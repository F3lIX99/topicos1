#include "pcsa.h"

PCSA::PCSA(int k){
    k=k;
    phi=0.77351;  //se inician las variables con sus respectivos valores
    errStd=0.05;
    M = ceil(phi/errStd);
    lo = log2(M);
    shift = 0;
    sketch = new long long[M];      //se crea el arreglo de sketch
    for(int i=0;i<M;i++) sketch[i]=0; // se inicializa con ceros
}

long long PCSA::compute(unsigned long long x){
        return ~x & (x+1);              
}

void PCSA::updatePCSA(string linea){ 
    unsigned long long aux;
    aux = h1(linea);    
    shift = (aux >> (64-lo));          //se realiza hashing al kmer entregado y luego se actualiza el arreglo sketch
    sketch[shift]=sketch[shift] | compute(aux);
}

long long PCSA::estimacion(){
    long long sum=0;                //se realiza la estimacion de cardinalidad
    for(int i=0;i<M;i++){
        sum+= log2 (compute(sketch[i]));   
    }
    double media=(1.0*sum/M);
    return (M*pow(2,(media)))/phi;
}