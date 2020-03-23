
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <map>
#include <string>
#include <stdexcept>
#include "TestActor.h"

using namespace std;

enum State{Bootup, Normal, Alarm, Error};

class StateMachine {
public:
   StateMachine();
   StateMachine(StateMachine const& other) = delete;
   StateMachine& operator=(StateMachine const& other) = delete;
   StateMachine(StateMachine&& other) = delete;
   StateMachine& operator=(StateMachine&& other) = delete;
   ~StateMachine() = default;
   
   void input(string signal);
   string getState();
   string getLastState();
private:
    State state;
    map<State, map<string, State>> stateTransferfunrctions;
    map<State, void (*)(void)> stateEntryfunrctions;
    map<State, void (*)(void)> stateExitFunctions;
};

#endif /* STATEMACHINE_H */

