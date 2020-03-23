
#include "Timekeeper.h"

Timekeeper::Timekeeper() {
    this->updateTime();
}

void Timekeeper::updateTime() {
    latestTimepoint = time_point_cast<milliseconds>(high_resolution_clock::now());
}

time_point<high_resolution_clock, milliseconds> Timekeeper::getTime() {
    this->updateTime();
    return this->latestTimepoint;
}

time_point<high_resolution_clock, milliseconds> Timekeeper::addToTime() {
    this->updateTime();
    time_point<high_resolution_clock, milliseconds> timePoint = time_point<high_resolution_clock, milliseconds>(this->latestTimepoint + seconds(10));
    return timePoint;
}

void Timekeeper::printTime() {
    this->updateTime();
    time_t timePoint = high_resolution_clock::to_time_t(this->latestTimepoint);
    cout << put_time(localtime(&timePoint), "%d.%m.%Y %T");
}
