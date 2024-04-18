#include <iostream>
#include <string>
#include "Date.h"
#include "Person.h"
#ifndef Guardian_H
#define Guardian_H

//Guardian of the bride
class Guardian:public Person{
    private:
        //Relation of the guardian is important, father, grandfather, uncle, brother,... etc
        string _relation;
        friend class MarriageOfficiant;
    public:
        Guardian(){}
        Guardian(string relation){
            this->_relation=relation;
        }
        Guardian(string name,string relation){
            this->_name=name;
            this->_relation=relation;
        }
};

#endif