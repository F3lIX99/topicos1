 #include "hyperLogLog.h"

hyperLogLog::hyperLogLog{
    alfa16 = 0.673;
    alfa32 = 0.697;
    alfa64 = 0.709;
    alfam = 0.7213 / (1.0 + 1.079/m);
    
}

hyperLogLog::estimacion(){

}
hyperLogLog::correccion(){
    double E = 0;
    int V = 0;
    if (E <= 5 / 2 * m && V != 0) {
        return m*log(static_cast<double>(m)/V);
      }
      else if (E <= /30) {
        return E;
      }
      else {
        return -(1ll << 32) * log(1-E/(1ll << 32));
      }
}