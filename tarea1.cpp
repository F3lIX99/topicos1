#include <iostream>
#include <fstream>
#include <string>
#include "pcsa.h"


using namespace std;


int main ()
{
    string filename("GCF_000001405.39_GRCh38.p13_genomic.fna");
    string linea;                               //para leer linea por linea
    ifstream input_file(filename);
    if(!input_file.is_open()){
        cout<<"error al abrir el archivo"<<endl;
        return EXIT_FAILURE;                        //retorna el error
    }

    srand(time(NULL));
    clock_t start;
    double t=0;
    PCSA *pcsa = new PCSA();
    start=clock();
    while( (input_file >> linea)){
        pcsa->updatePCSA(linea);
        for(int i=0;i<linea.length()-1;i++){
            if(linea[i]=='A'||linea[i]=='C'||linea[i]=='G'||linea[i]=='T'||linea[i]=='a'||linea[i]=='c'||linea[i]=='g'||linea[i]=='t'){
            
        }
        cout<<pcsa->estimacion()<<endl;
        
    }   
    }
    
    return 0;
}