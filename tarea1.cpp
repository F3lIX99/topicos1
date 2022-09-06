#include <iostream>
#include <fstream>
#include <string>

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
    start=clock();

    while( (input_file >> linea)){
        
        cout << linea << endl;

    }
    
    
}