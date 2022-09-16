#include <iostream>
#include <fstream>
#include <string>
#include "pcsa.h"
#include "hyperLogLog.h"
<<<<<<< HEAD
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
=======


using namespace std;

double* merge(double* s1, double* s2,int tamano){
    for(int i=0;i<pow(2,tamano);i++){
        s1[i]=max(s1[i],s2[i]);
        
  }
  return s1;
>>>>>>> 86931c32ba28cb50693bc1d296c441635c9855b8
}

double jaccard(double es1,double es2, double es3){
    return (((es1 + es2) - es3) / es3);
}

int main ()
{
<<<<<<< HEAD
    
    std::chrono::time_point<std::chrono::high_resolution_clock> _init, _end; 
    std::chrono::duration<double> delta;
    int k=31;
      
    string filename1("genoma_preprocesado.fna"); //el que pesa mas se preprocesa asi grep -v ">" genoma_original-fna > genoma_preprocesado.fna y grep -v "N" genoma_original-fna > genoma_preprocesado.fna
    string filename2("geno_preprocesado.fna"); //el que pesa menos
=======
    int k=31;
      
    string filename1("GCF_000001405.39_GRCh38.p13_genomic.fna");
    string filename2("GCF_000308155.1_EptFus1.0_genomic.fna");
>>>>>>> 86931c32ba28cb50693bc1d296c441635c9855b8
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
<<<<<<< HEAD
    int j;       
    int b=0;
    _init = std::chrono::high_resolution_clock::now();
    while(!input_file.eof()){   
        input_file >> linea;
        if(linea.length()>=k){
            for(int i=0;i<=linea.length()-k;i++){
                for(int j=0;j<k;j++){
                    kmer+=linea[i+j];
=======
    int j;
    int b=0;
    int contador1=0;
    
    while(!input_file.eof()){   
        input_file >> linea;
        if(linea[0]=='>') continue;
        else{
            for(int i=0;i<linea.length();i++){
                if(linea[i]=='N') continue;
                else{
                    if(b<=k){
                        kmer+=linea[i];
                        if(i==linea.length()-1){
                            //pcsa->updatePCSA(kmer);
                            //hll->update(kmer);
                            kmer.clear();
                        }
                        b++;
                    }
                    else{
                        b=0;
                        //pcsa->updatePCSA(kmer);
                        //hll->update(kmer);
                        kmer.clear();
                    }
           
>>>>>>> 86931c32ba28cb50693bc1d296c441635c9855b8
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
<<<<<<< HEAD
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
=======
    
    //cout<<hll->estimacion()<<endl;
    //cout<<hll->correccion()<<endl;
    //double es1 = hll->estimacion();
    //double* s1= hll->getsketch();
    input_file.close();
    //lectura del otro archivo
    ifstream input_file1(filename2);
    if(!input_file1.is_open()){
        cout<<"error al abrir el archivo"<<endl;
        return EXIT_FAILURE;                        
        //retorna el error
    }

    b=0;
    while(!input_file1.eof()){   
        input_file1 >> linea;
        if(linea[0]=='>') continue;
        else{
            for(int i=0;i<linea.length();i++){
                if(linea[i]=='N') continue;
                else{
                    if(b<=k){
                        kmer+=linea[i];
                        if(i==linea.length()-1){
                            pcsa->updatePCSA(kmer);
                            hll->update(kmer);
                            kmer.clear();
                        }
                        b++;
                    }
                    else{
                        b=0;
                        pcsa->updatePCSA(kmer);
                        hll->update(kmer);
                        kmer.clear();
                    }
           
                }
            }  
        }
   
    }
    input_file1.close();
    //double* s2= hll->getsketch();
    //double es2 = hll->estimacion();
    //double* s3 = merge(s1,s2,tamano);
    //cout<<"la cardinalidad del merge es:"<<hll->estimacionj(s3)<<endl;
    //double esunion = hll->estimacionj(s3);

    //cout<<"el JACCCCARD ES:"<<jaccard(es1,es2,esunion)<<endl;
      
    

    cout<<pcsa->estimacion()<<endl;
>>>>>>> 86931c32ba28cb50693bc1d296c441635c9855b8
    return 0;
}