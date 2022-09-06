#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class PCSA{
    private:
        int M;
        float phi;
        int k;
        unsigned long long x;
        hash<string> h1;
        int sum;
        double media;
        int shift;
        long long* sketch;
        string linea;
    
    
    public:
        PCSA();
        ~PCSA();
        long long compute(unsigned long long x);
        void updatePCSA(string linea);
        long long estimacion(int k);
};