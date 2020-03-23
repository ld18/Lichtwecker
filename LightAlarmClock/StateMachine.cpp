
#include "StateMachine.h"

StateMachine::StateMachine()
{
    this->state = State::Bootup;
    try {
        this->stateEntryfunrctions.at(this->state)();
    } catch (...) {
    }
    
    this->stateTransferfunrctions[State::Bootup] = {
            {"done", State::Normal}
        };
    this->stateTransferfunrctions[State::Normal] = {
            {"error", State::Error},
            {"alarm", State::Alarm}
        };
    this->stateTransferfunrctions[State::Alarm] = {
            {"error", State::Error},
            {"noAalarm", State::Normal}
        };
    this->stateTransferfunrctions[State::Error] = {
            {"error", State::Error}
        };
    
    this->stateEntryfunrctions[State::Bootup] = TestActor::entry_Bootup;
    this->stateEntryfunrctions[State::Normal] = TestActor::entry_Normal;
    this->stateEntryfunrctions[State::Alarm] = TestActor::entry_Alarm;
    this->stateEntryfunrctions[State::Error] = TestActor::entry_Error;
    
    this->stateExitFunctions[State::Bootup] = TestActor::exit_Bootup;
    this->stateExitFunctions[State::Normal] = TestActor::exit_Normal;
    this->stateExitFunctions[State::Alarm] = TestActor::exit_Alarm;
    this->stateExitFunctions[State::Error] = TestActor::exit_Bootup;
}

void StateMachine::input(string signal) {
    try {
        State newState = this->stateTransferfunrctions.at(this->state).at(signal);
        this->stateExitFunctions.at(this->state)();
        this->state = newState;
        this->stateEntryfunrctions.at(this->state)();
    } catch (...) {
    }
}

string StateMachine::getState() {
    switch(this->state){
        case State::Bootup:
            return "Bootup";
        case State::Normal:
            return "Normal";
        case State::Alarm:
            return "Alarm";
        case State::Error:
            return "Error";
        default:
             throw exception();
    }
    return "unknwon state";
}
