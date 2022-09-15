#include <iostream>
#include <fstream>
#include <string>
#include "pcsa.h"
#include "hyperLogLog.h"


using namespace std;

double* merge(double* s1, double* s2,int tamano){
    for(int i=0;i<pow(2,tamano);i++){
        s1[i]=max(s1[i],s2[i]);
        
  }
  return s1;
}

double jaccard(double es1,double es2, double es3){
    return (((es1 + es2) - es3) / es3);
}

int main ()
{
    int k=31;
      
    string filename1("GCF_000001405.39_GRCh38.p13_genomic.fna");
    string filename2("GCF_000308155.1_EptFus1.0_genomic.fna");
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
                            hll->update(kmer);
                            kmer.clear();
                        }
                        b++;
                    }
                    else{
                        b=0;
                        //pcsa->updatePCSA(kmer);
                        hll->update(kmer);
                        kmer.clear();
                    }
           
                }
            }  
        }
   
    }
    
    //cout<<hll->estimacion()<<endl;
    //cout<<hll->correccion()<<endl;
    double es1 = hll->estimacion();
    double* s1= hll->getsketch();
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
                            //pcsa->updatePCSA(kmer);
                            hll->update(kmer);
                            kmer.clear();
                        }
                        b++;
                    }
                    else{
                        b=0;
                        //pcsa->updatePCSA(kmer);
                        hll->update(kmer);
                        kmer.clear();
                    }
           
                }
            }  
        }
   
    }
    input_file1.close();
    double* s2= hll->getsketch();
    double es2 = hll->estimacion();
    double* s3 = merge(s1,s2,tamano);
    cout<<"la cardinalidad del merge es:"<<hll->estimacionj(s3)<<endl;
    double esunion = hll->estimacionj(s3);

    cout<<"el JACCCCARD ES:"<<jaccard(es1,es2,esunion)<<endl;
      
    

    //cout<<pcsa->estimacion()<<endl;
    return 0;
}