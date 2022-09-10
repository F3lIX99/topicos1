#include <iostream>
#include <string>
#include <math.h>

class hyperLogLog{
    private:
        int m;
        hash<string>h2;
        float alfa16,alfa32,alfa64,alfam;

        
    public:
        hyperLogLog();
        void update();
        void estimacion();
};