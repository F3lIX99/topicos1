 #include "hyperLogLog.h"

hyperLogLog::hyperLogLog(int b){
  alfa16 = 0.673;
  alfa32 = 0.697;
  alfa64 = 0.709;
  alfam = 0.7213 / (1.0 + 1.079/m);
  E=0;
  m = pow(2,b);
  for(int i=0;i<m;i++) M[i]=0;
}

double hyperLogLog::estimacion(){
  double valor=0;
  for(int j=0;j<m-1;j++){
    valor += pow(2,-M[j]);
  }
  valor=1/valor;

  E = (alfam * pow(m,2) * valor)
  return E;
}
double hyperLogLog::correccion(){
  E = 0;
  int V = 0;
  if (E <= 5/2 * m && V != 0) {
    return m*log(static_cast<double>(m)/V);
  }
  else if (E <= 1/30* pow(2,32)) {
    return E;
  }
  else {
    return (-pow(2,32) * log(1-E/pow(2,32)));
  }
}

void hyperLogLog::merge(long long* s1,long long* s2){
  for(i=0;i<s1.lenght;i++){
    s1[i]=max(s1[i],s2[i]);
  }
}

void hyperLogLog::jaccard(){
  
}