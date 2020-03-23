
#ifndef ALARMS_H
#define ALARMS_H

#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace chrono;

enum Repetitions {None, EveryMinute, EveryHour};
enum AlarmTypes {Light, Noise, Both};

struct AlarmInformation{
    AlarmInformation(time_point<high_resolution_clock, milliseconds> timepoint){
        this->timepoint = timepoint;
        this->name = "Test Alarm";
        this->repetition = Repetitions::EveryMinute;
        this->alerType = AlarmTypes::Both;
        this->triggered = false;
        this->active = true;
    }
    time_point<high_resolution_clock, milliseconds> timepoint;
    string name;
    Repetitions repetition;
    AlarmTypes alerType;
    bool triggered; 
    bool active; 
};

class AlarmController {
public:
    AlarmController();
    AlarmController(AlarmController const& other) = delete;
    AlarmController& operator=(AlarmController const& other) = delete;
    AlarmController(AlarmController&& other) = delete;
    AlarmController& operator=(AlarmController&& other) = delete;
    ~AlarmController() = default;
    
    void addAlarm(AlarmInformation alarm);
    void deleteAlarm(AlarmInformation alarm);
    bool checkForAlarm(const time_point<high_resolution_clock, milliseconds> timePoint);
    AlarmInformation getNextAlarm();
private:
    bool checkAlarmTimePoint(const time_point<high_resolution_clock, milliseconds> timePoint, const AlarmInformation alarm);
    vector<AlarmInformation> alarms;
};

#endif /* ALARMS_H */

