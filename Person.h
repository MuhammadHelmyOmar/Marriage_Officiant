#include <iostream>
#include "Date.h"
#include <string>
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class Person{
   protected:
      Date _birthdate;
      unsigned long long int _ID_Number;//If there is no national id marriage cannot be proceeded
      string _religion;//Religion is either Muslim, Christian, or Jewish
      string _status;//Status is either single, married, divorced, widow/widower
      string _address;
      string _job;
      friend class PersonalRecord;
      friend class MarriageOfficiant;
   public:
      //Attributes
      string _name;
      char _gender;//Gender could be either M or F
      
      //Methods
      Person(){}
      Person(string name){
         this->_name=name;
      }
      Person(unsigned long long int id_number){
         this->_ID_Number=id_number;
      }
      virtual ~Person(){};
      friend istream &operator >> (istream &input,Person &p){
            getline(input,p._name);
            return input;
        }
};
#endif