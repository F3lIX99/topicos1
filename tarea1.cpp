#include <iostream>
#include <fstream>
#include <string>
#include "pcsa.h"


using namespace std;


int main ()
{
    int k=31;  
    string filename("GCF_000308155.1_EptFus1.0_genomic.fna");
    string linea;
    //vector <string> lineas;
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
    start=clock();

    while(!input_file.eof()){    
        input_file >> linea; 
        if(linea[0]=='>'|| linea[0] == 'N') continue;

        /*else if(linea[0]=='N'|| linea[0] == 'n')
            for(int j=0;j<linea.length;j++)
                if(linea[j]=='N')
                    continue;
                else   
                    cout<<linea<<endl;*/

        else if(linea[0]=='a'|| linea[0]=='A'||linea[0]=='T'|| linea[0]=='t'||linea[0]=='c'|| linea[0]=='C'||linea[0]=='G'|| linea[0]=='g'){
           int b=0;
           for(int a=0;a<linea.length() ;a++){
                
                if(b<=k){
                    kmer+=linea[a];
                    if(a==linea.length()-1){
                        pcsa->updatePCSA(kmer);
                    }
                    b++;
                }
                else{
                    b=0;
                    pcsa->updatePCSA(kmer);
                    kmer.clear();
                }
           
           }
           
        }
        
        else
            continue;    
    }
    cout<<pcsa->estimacion()<<endl;
    
    return 0;
}