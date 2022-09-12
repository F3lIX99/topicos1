 #include "hyperLogLog.h"

hyperLogLog::hyperLogLog(int b){
  alfa16 = 0.673;
  alfa32 = 0.697;
  alfa64 = 0.709;
  alfam = 0.7213 / (1.0 + 1.079/m);
  E=0;
  x = 0;
  j = 0;
  m = pow(2,b);
  registros = new double[m];
  for(int i=0;i<m;i++) registros[i]=0;
}

double hyperLogLog::estimacion(){
  double valor=0;
  for(int j=0;j<m-1;j++){
    valor += pow(2,-registros[j]);
  }
  valor=1/valor;

  E = (alfam * pow(m,2) * valor);
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

void hyperLogLog::merge(unsigned int s1[],unsigned int s2[]){
  int a = s1.size();

  for(int i=0;i<a;i++){
    s1[i]=max(s1[i],s2[i]);
  }
}

void hyperLogLog::jaccard(){

}

void hyperLogLog::update(string linea){
  x = h2(linea);
  j = 1 + (x >> (64-b));
  w = 



}