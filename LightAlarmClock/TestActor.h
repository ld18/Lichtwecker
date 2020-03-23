
#ifndef TESTACTOR_H
#define TESTACTOR_H

#include <string>
#include <iostream>

using namespace std;


class TestActor {
public:
   TestActor() =default;
   
   static void entry_Normal(void){
       cout << "entry_Normal" << endl;
   }
   static void exit_Normal(void){
       cout << "exit_Normal" << endl;
   }
   
   static void entry_Alarm(void){
       cout << "entry_Alarm" << endl;
   }
   static void exit_Alarm(void){
       cout << "exit_Alarm" << endl;
   }
   
   static void entry_Error(void){
       cout << "entry_Error" << endl;
   }
   static void exit_Error(void){
       cout << "exit_Error" << endl;
   }
   
   static void entry_Bootup(void){
       cout << "entry_Bootup" << endl;
   }
   static void exit_Bootup(void){
       cout << "exit_Bootup" << endl;
   }
};


#endif /* TESTACTOR_H */

