#include <iostream>
#include <fstream>
#include <string>
#include "pcsa.h"
#include "hyperLogLog.h"
#include "chrono"

using namespace std;

double merge(double* s1, double* s2,int tamano){
    int nuevotam=pow(2,tamano);
    float alfam = 0.7213 / (1.0 + 1.079/nuevotam);
    double* respuesta = new double [nuevotam];
    for(int i=0;i<nuevotam;i++){
        respuesta[i]=max(s1[i],s2[i]);    
    }
    double valor=0;
    for(int j=0;j<nuevotam-1;j++){
        valor += pow(2,-respuesta[j]);
    }
    valor=1/valor;
  
    double E = (alfam * pow(nuevotam,2) * valor);
    cout<<E<<endl;
    return E;
}

double jaccard(double es1,double es2, double es3){
    return (((es1 + es2) - es3) / es3);
}

int main ()
{
    
    std::chrono::time_point<std::chrono::high_resolution_clock> _init, _end; 
    std::chrono::duration<double> delta;
    int k=31;
      
    string filename1("genoma_preprocesado.fna"); //el que pesa mas se preprocesa asi grep -v ">" genoma_original-fna > genoma_preprocesado.fna y grep -v "N" genoma_original-fna > genoma_preprocesado.fna
    string filename2("geno_preprocesado.fna"); //el que pesa menos
    string linea;
    string kmer;
    ifstream input_file(filename1);
    if(!input_file.is_open()){
        cout<<"error al abrir el archivo"<<endl;
        return EXIT_FAILURE;                       
         //retorna el error
    }

    PCSA *pcsa = new PCSA(k);
    int tamano=4;
    hyperLogLog *hll = new hyperLogLog(tamano);
    int j;       
    int b=0;
    _init = std::chrono::high_resolution_clock::now();
    while(!input_file.eof()){   
        input_file >> linea;
        if(linea.length()>=k){
            for(int i=0;i<=linea.length()-k;i++){
                for(int j=0;j<k;j++){
                    kmer+=linea[i+j];
                }
                pcsa->updatePCSA(kmer);
                hll->update(kmer);
                kmer.clear();
            }
        }else{
            pcsa->updatePCSA(linea);
            hll->update(linea);
        }
    } 
    double* s1= hll->getsketch();
    double es1 = hll->estimacion();
    input_file.close();
    //lectura del otro archivo
    ifstream input_file1(filename2);
    hyperLogLog *hll2 = new hyperLogLog(tamano);
    PCSA *pcsa2 = new PCSA(k);
    if(!input_file1.is_open()){
        cout<<"error al abrir el archivo"<<endl;
        return EXIT_FAILURE;                        
        //retorna el error
    }
    int contador=0;
    while(!input_file1.eof()){   
        input_file1 >> linea;
        if(linea.length()>=k){
            for(int i=0;i<=linea.length()-k;i++){
                for(int j=0;j<k;j++){
                    kmer+=linea[i+j];
                }
                pcsa2->updatePCSA(kmer);
                hll2->update(kmer);
                kmer.clear();
            }
        }else{
            pcsa2->updatePCSA(linea);
            hll2->update(linea);
        }
    }
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
    double_t timeInsert = delta.count(); 
    input_file1.close();
    double* s2= hll2->getsketch();
    double es2 = hll2->estimacion();
    cout<<"La estimacion hll es: "<<es1<<" y la estimacion hll2 es: "<< es2<<endl;
    double s3 = merge(s1,s2,tamano);
    cout<<"el JACCCCARD ES: "<<jaccard(es1,es2,s3)<<endl;
    cout<<"la estimacion PCSA del primer archivo es: "<<pcsa->estimacion()<<endl;
    cout<<"la estimacion PCSA del segundo archivo es: "<<pcsa2->estimacion()<<endl;
    cout<<timeInsert<<endl;
    return 0;
}