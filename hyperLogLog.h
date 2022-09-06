#include <iostream>
#include <string>

class hyperLogLog{
    private:
        int m;
        
    public:
        hyperLogLog();
        void update();
        void estimacion();
};