#include <iostream>
#include <fstream>
#include <string>
#include "pcsa.h"
#include "hyperLogLog.h"


using namespace std;


int main ()
{
    int k=31;
      
    string filename("GCF_000308155.1_EptFus1.0_genomic.fna");
    string linea;
    string kmer;
                                //para leer linea por linea
    ifstream input_file(filename);
    if(!input_file.is_open()){
        cout<<"error al abrir el archivo"<<endl;
        return EXIT_FAILURE;                        //retorna el error
    }
    srand(time(NULL));
    clock_t start;
    double t=0;
    PCSA *pcsa = new PCSA(k);
    hyperLogLog *hll = new hyperLogLog(4);
    start=clock();
    int j;
    int b=0;

    
    while(!input_file.eof()){   
        //getline(input_file,linea); 
        input_file >> linea;
        if(linea[0]=='>') continue;
        else{
            for(int i=0;i<linea.length();i++){
                if(linea[i]=='N') continue;
                else{
                    if(b<=k){
                        kmer+=linea[i];
                        if(i==linea.length()-1){
                            //cout<<kmer<<endl;
                            //pcsa->updatePCSA(kmer);
                            hll->update(kmer);
                            kmer.clear();
                        }
                        b++;
                    }
                    else{
                        b=0;
                        //pcsa->updatePCSA(kmer);
                        //cout<<kmer<<endl;
                        hll->update(kmer);
                        kmer.clear();
                    }
           
                }
            }  
        }
   
    }
    cout<<hll->estimacion()<<endl;
    cout<<hll->correccion()<<endl;
    //cout<<pcsa->estimacion()<<endl;
    return 0;
}