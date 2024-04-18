#include <iostream>
#include <string>
#include "Date.h"
#include "Person.h"
#ifndef Witness_H
#define Witness_H

class Witness:public Person{
    //Witnesses connot be less than 2 and no need for more than 2
    private:
        static unsigned int _witnessesCount;
    public:
        Witness(){
            _witnessesCount++;
        }
        Witness(string name){
            _witnessesCount++;
            this->_name=name;
        }
        ~Witness(){
            _witnessesCount--;
        }
        static unsigned int count_witnesses() {
            return _witnessesCount;
        }
};
unsigned int Witness::_witnessesCount=0;
#endif