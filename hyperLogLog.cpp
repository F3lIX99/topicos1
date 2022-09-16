 #include "hyperLogLog.h"

hyperLogLog::hyperLogLog(int b){
  a=b;
  alfa16 = 0.673;
  alfa32 = 0.697;
  alfa64 = 0.709;
  E=0;
  x = 0;            //se inician las variables 
  j = 0;
  m = pow(2,b);
  alfam = 0.7213 / (1.0 + 1.079/m);
  registros = new double[m];    //se crea el arreglo de registros(sketch)
  for(int i=0;i<m;i++) registros[i]=0; //se inicializa con ceros
}

double hyperLogLog::estimacion(){
  double valor=0;
  for(int j=0;j<m-1;j++){
    valor += pow(2,-registros[j]);    //se estima la cardinalidad 
  }
  valor=1/valor;

  E = (alfam * pow(m,2) * valor);
  return E;
}
double hyperLogLog::correccion(){
  
  int V = 0;
  if (E <= 5/2 * m && V != 0) {
    return m*log(static_cast<double>(m)/V);   //se realiza la correcion de la cardinalidad encontrada
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
  j = (x >> (64-a));          //en update se procesa el kmer entregado y se actualiza(si es que es mayor) en el arreglo de registro 
  int pos = 0;
  x = (x << a);
  pos = __builtin_clzll(x) + 1;
  registros[j]= max(registros[j],(double)pos);
  }

  double* hyperLogLog::getsketch(){
    return registros;       // se retorna el arreglo de sketch
  }



