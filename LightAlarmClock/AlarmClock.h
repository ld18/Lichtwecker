
#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "StateMachine.h"
#include "Timekeeper.h"
#include "Alarms.h"
#include "Dummy_Input.h"

class AlarmClock {
public:
    AlarmClock();
    AlarmClock(AlarmClock const& other) = delete;
    AlarmClock& operator=(AlarmClock const& other) = delete;
    AlarmClock(AlarmClock&& other) = delete;
    AlarmClock& operator=(AlarmClock&& other) = delete;
    ~AlarmClock() = default;
    
    void testFrequenzy();
    void tick();
private:
    Timekeeper timekeeper;
    StateMachine stateMachine;
    AlarmController alarmController;
};

#endif /* ALARMCLOCK_H */

