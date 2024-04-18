#include <iostream>
#include <string>
#include "Date.h"
#include "Person.h"
#ifndef MARRIAGECONTRACT_H
#define MARRIAGECONTRACT_H
using namespace std;

class MarriageContract{
    private:
        //Attributes
        static unsigned int countContracts;
        unsigned int _mahr;
        Date _MarriageDate;
        Person _propertyOwner;
        unsigned int _salaryIfDivorce;
        friend class MarriageOfficiant;
    public:
        //Methods
        MarriageContract(){
            countContracts++;
        }
        ~MarriageContract(){
            countContracts--;
        }
        static unsigned int getCountContracts(){
            return countContracts;
        }
};

unsigned int MarriageContract::countContracts=0;
#endif