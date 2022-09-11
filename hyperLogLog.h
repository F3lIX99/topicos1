#include <iostream>
#include <string>
#include <math.h>

class hyperLogLog{
    private:
        int m;
        hash<string>h2;
        float alfa16,alfa32,alfa64,alfam;
        double E,M[m];
        int m;
        
    public:
        hyperLogLog();
        double estimacion();
        double correccion();
        void merge(long long* s1, long long*s2);
};