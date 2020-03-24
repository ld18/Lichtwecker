
#include <cstdlib>
#include <iostream>
#include <string>
#include "AlarmClock.h"

using namespace std;

int main(int argc, char** argv) {
    
    AlarmClock ac;
    ac.testFrequenzy();
    
    while(true){
        ac.tick();
    }
    return 0;
}

