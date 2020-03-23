
#include "Alarms.h"

AlarmController::AlarmController() {
}

void AlarmController::addAlarm(AlarmInformation alarm) {
    this->alarms.push_back(alarm);
}

bool AlarmController::checkForAlarm(const time_point<high_resolution_clock, milliseconds> timePoint) {
    for(auto& alarm : this->alarms){
        if(this->checkAlarmTimePoint(timePoint, alarm)){
            if(alarm.active){
                if(alarm.triggered == false){
                    alarm.triggered = true;
                    return true;
                }else{
                    continue;
                }
            }
        }
        alarm.triggered = false;
    }
    return false;
}

bool AlarmController::checkAlarmTimePoint(const time_point<high_resolution_clock, milliseconds> timePoint, const AlarmInformation alarm) {
    milliseconds timeDifference = timePoint - alarm.timepoint;
    if(alarm.repetition != Repetitions::None){
        switch(alarm.repetition){
            case EveryMinute:
                timeDifference = timeDifference % minutes(1);
                break;
            case EveryHour:
                timeDifference = timeDifference % hours(1);
                break;
        }
    }
    if(milliseconds(0) < timeDifference && milliseconds(2000) > timeDifference){
        return true;
    }
    return false;
}