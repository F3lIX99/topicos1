#include "pcsa.h"

PCSA::PCSA(int k){
    k=k;
    phi=0.77351;
    errStd=0.05;
    M = ceil(phi/errStd);
    lo = log2(M);
<<<<<<< HEAD
=======
    media = 0;
>>>>>>> 86931c32ba28cb50693bc1d296c441635c9855b8
    shift = 0;
    sketch = new long long[M];
    for(int i=0;i<M;i++) sketch[i]=0;
}

long long PCSA::compute(unsigned long long x){
        return ~x & (x+1);
}

void PCSA::updatePCSA(string linea){ 
    unsigned long long aux;
    aux = h1(linea);
    shift = (aux >> (64-lo));
    sketch[shift]=sketch[shift] | compute(aux);
}

long long PCSA::estimacion(){
    long long sum=0;
    for(int i=0;i<M;i++){
        sum+= log2 (compute(sketch[i]));   
    }
    double media=(1.0*sum/M);
    return (M*pow(2,(media)))/phi;
}