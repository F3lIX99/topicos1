#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class PCSA{
    private:
        int M;
        float errStd;
        float phi;
        int k;
        unsigned long long x;
        int sum;
        double media;
        int shift;
        long long* sketch;
        string linea;
        hash<string> h1;
        long long unsigned lo;
    
    
    public:
        PCSA();
        ~PCSA();
        long long compute(unsigned long long x);
        void updatePCSA(string linea);
        long long estimacion();
};