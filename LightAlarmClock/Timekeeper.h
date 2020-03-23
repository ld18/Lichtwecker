
#ifndef TIME_H
#define TIME_H

#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using namespace chrono;

class Timekeeper {
public:
    Timekeeper();
    Timekeeper(Timekeeper const& other) = delete;
    Timekeeper& operator=(Timekeeper const& other) = delete;
    Timekeeper(Timekeeper&& other) = delete;
    Timekeeper& operator=(Timekeeper&& other) = delete;
    ~Timekeeper() = default;
    
    void updateTime();
    time_point<high_resolution_clock, milliseconds> getTime();
    time_point<high_resolution_clock, milliseconds> addToTime();    
    void printTime();
private:
    time_point<high_resolution_clock, milliseconds> latestTimepoint;
};

#endif /* TIME_H */

