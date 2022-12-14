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
        int shift;
        long long* sketch;
        string linea;
        hash<string> h1;
        long long unsigned lo;
    
    
    public:
        PCSA(int k);
        ~PCSA();
        long long compute(unsigned long long x);
        void updatePCSA(string linea);
        long long estimacion();
};