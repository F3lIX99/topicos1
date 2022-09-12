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
        
        //unsigned int s1[],s2[];
    public:
        hyperLogLog(int b);
        double estimacion();
        double correccion();
        void update(string linea);
        void merge(unsigned int s1[], unsigned int s2[]);
        void jaccard();
};