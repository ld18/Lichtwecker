
#ifndef DUMMY_INPUT_H
#define DUMMY_INPUT_H

#include <string>
#include <iostream>

using namespace std;

class Dummy_Input {
public:
   Dummy_Input() =default;
   
   static bool checkFor_deactivateButton(void){
       cout << "deactivateButton pressed" << endl;
       return true;
   }

};


#endif /* DUMMY_INPUT_H */

