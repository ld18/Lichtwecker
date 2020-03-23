
#include <cstdlib>
#include <iostream>
#include <string>
#include "StateMachine.h"
#include "Timekeeper.h"
#include "Alarms.h"

using namespace std;

int main(int argc, char** argv) {
    StateMachine sm;
    
    Timekeeper tk;
    tk.printTime();
    cout<<endl;
    
    AlarmController a;
    AlarmInformation al(tk.addToTime());
    a.addAlarm(al);
    
    sm.input("done");
    
    while(true){
        tk.updateTime();
        if(a.checkForAlarm(tk.getTime())){
            sm.input("alarm");
            tk.printTime();
            cout<<" arlarm is on"<<endl;
        }
        
    }
    return 0;
}

