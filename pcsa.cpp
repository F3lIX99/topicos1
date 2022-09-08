#include "pcsa.h"

PCSA::PCSA(int k){
    k=k;
    phi=0.77351;
    errStd=0.2;
    M = round(pow(phi/errStd,2));
    lo = log2(M); 
    media = 0;
    shift = 0;
    x=0;
    sketch = new long long[M];
}

long long PCSA::compute(unsigned long long x){
        return ~x & (x+1);
}

void PCSA::updatePCSA(string linea){ 
    x = h1(linea);
    shift = (x >> (64-lo));
    sketch[shift]=sketch[shift] | compute(x);
}

long long PCSA::estimacion(){
    sum=0;
    for(int i=0;i<shift;i++){
        sum+= log2 (compute(sketch[shift]));   
    }
    media=(1.0*sum/M);
    return (M*pow(2,(media/phi)));
}