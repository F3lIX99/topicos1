#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class hyperLogLog{
    private:
        int m;
        hash<string>h2;
        float alfa16,alfa32,alfa64,alfam;
        double E;
        double* registros;
        unsigned long long x;
        int j;
        int a;
        
    public:
        hyperLogLog(int b);
        double estimacion();
         double estimacionj(double* s1);
        double correccion();
        void update(string linea);
        double* getsketch();
};