#include "pcsa.h"

PCSA::PCSA(){
    k=31;
    phi=0.77351;
    M=4;
    media = 0;
    shift = 0;
    x=0;
    long long* sketch = new long long[M];
}

long long PCSA::compute(unsigned long long x){
        return ~x & (x+1);
}

void PCSA::updatePCSA(string linea){ 
    x = h1(linea);
    shift = (x >> 64-M);
    sketch[shift]=sketch[shift] | compute(x);
}

long long PCSA::estimacion(int k){
    sum=0;
    for(int i=0;i<k;i++){
        sum+= compute(sketch[shift]);   
    }
    media=(1.0*sum/M);
    return (M*pow(2,(media/phi)));
}