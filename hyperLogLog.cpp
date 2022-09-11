 #include "hyperLogLog.h"

hyperLogLog::hyperLogLog(){
  alfa16 = 0.673;
  alfa32 = 0.697;
  alfa64 = 0.709;
  alfam = 0.7213 / (1.0 + 1.079/m);
  E=0;
  m = pow(2,b);
  for(int i=0;i<m;i++) M[i]=0;
}

double hyperLogLog::estimacion(){
  double valor;
  for(int j=0;j<m-1;j++){
    valor = 
  }

  E = (alfam * pow(m,2) * for(j=0;j<m-1;j++) {pow(2,-M[j])}
}
double hyperLogLog::correccion(){
  E = 0;
  int V = 0;
  if (E <= 5 / 2 * m && V != 0) {
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