
#include "AlarmClock.h"

AlarmClock::AlarmClock(): stateMachine(),  timekeeper(),  alarmController(){
    timekeeper.printTime();
    stateMachine.input("done");
    cout<<"\tAlarmClock initialised"<<endl;
}

void AlarmClock::tick() {
    timekeeper.updateTime();
    if(alarmController.checkForAlarm(timekeeper.getTime())){
        stateMachine.input("alarm");
        timekeeper.printTime();
        cout<<" arlarm is on"<<endl;
        if(Dummy_Input::checkFor_deactivateButton()){
            stateMachine.input("noAlarm");
            timekeeper.printTime();
            cout<<" arlarm is off"<<endl;
        }
    }
}

void AlarmClock::testFrequenzy() {
    AlarmInformation al(timekeeper.addToTime());
    alarmController.addAlarm(al);
    cout<<"\tAlarm added"<<endl;
}
