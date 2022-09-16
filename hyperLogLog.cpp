 #include "hyperLogLog.h"

hyperLogLog::hyperLogLog(int b){
  a=b;
  alfa16 = 0.673;
  alfa32 = 0.697;
  alfa64 = 0.709;
<<<<<<< HEAD
=======
  //alfam = 0.7213 / (1.0 + 1.079/m);
>>>>>>> 86931c32ba28cb50693bc1d296c441635c9855b8
  E=0;
  x = 0;
  j = 0;
  m = pow(2,b);
  alfam = 0.7213 / (1.0 + 1.079/m);
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


void hyperLogLog::update(string linea){
  x = h2(linea);
  j = (x >> (64-a));
  int pos = 0;
  x = (x << a);
<<<<<<< HEAD
  pos = __builtin_clzll(x) + 1;
  registros[j]= max(registros[j],(double)pos);
=======
  pos = __builtin_clzll(x);
  registros[j]= max(registros[j],(double)pos);

  
>>>>>>> 86931c32ba28cb50693bc1d296c441635c9855b8
  }

  double* hyperLogLog::getsketch(){
    return registros; 
  }
<<<<<<< HEAD
=======

  double hyperLogLog::estimacionj(double* s1){
  double valor=0;
  for(int j=0;j<m-1;j++){
    valor += pow(2,-registros[j]);
  }
  valor=1/valor;

  E = (alfam * pow(m,2) * valor);
  return E;
} 
>>>>>>> 86931c32ba28cb50693bc1d296c441635c9855b8



