#include <iostream>
#include <string>
#include "Date.h"
#include "Person.h"
#include "File.h"
#include "Guardian.h"
#include "Witness.h"
#include "MarriageContract.h"
#include <set>
#ifndef MARRIAGEOFFICIANT_H
#define MARRIAGEOFFICIANT_H
using namespace std;

class MarriageOfficiant:public Person{
    private:
        //This set contains the only guardians who can give the bride permission to marry
        set <string> validGuardians={"Father","Grandfather","Uncle","Brother"};
        MarriageContract *newContract=new MarriageContract;
    public:
        MarriageOfficiant(string name){
            this->_name=name;
            cout<<"Date of Marriage: ";
            cin>>newContract->_MarriageDate;
        }
        ~MarriageOfficiant(){
            delete newContract;
        }
        void checkGroom(Person *groom){
            cout<<"Groom's Name: ";
            cin.ignore();
            getline(cin,groom->_name);

            cout<<"Groom's Religion: ";
            cin>>groom->_religion;

            cout<<"Groom's Birthdate: ";
            cin>>groom->_birthdate;
            unsigned int groomAge=newContract->_MarriageDate._year - groom->_birthdate._year;
            if(groomAge<18){
                cout<<"Unfortunately, the groom is too young to get married.\nGood Luck Next Time.";
                exit(0);
            }
            else{
                cout<<"Groom Checked.\n";
            }
        }
        void checkGuardian(Guardian *guardian){
            cout<<"Guardian's Relation: ";
            cin>>guardian->_relation;
            //Check Guardian's Relation
            if(!validGuardians.count(guardian->_relation)){
                cout<<"This person cannot give the bride permission to marry.\n";
                exit(0);
            }

            cout<<"Guardian's Name: ";
            cin.ignore();
            getline(cin,guardian->_name);

            cout<<"Guardian's Religion: ";
            cin>>guardian->_religion;

            cout<<"Guardian's ID Number: ";
            cin>>guardian->_ID_Number;

            cout<<"Gaurdian Checked.\n";
        }
        void checkBride(Person *bride){
            cout<<"Bride's Name: ";
            cin.ignore();
            getline(cin,bride->_name);

            cout<<"Bride's Religion: ";
            cin>>bride->_religion;

            cout<<"Bride's Birthdate: ";
            cin>>bride->_birthdate;
            unsigned int brideAge=newContract->_MarriageDate._year - bride->_birthdate._year;
            if(brideAge< 18){
                cout<<"Unfortunately, the bride is too young to get married.\nGood Luck Next Time.";
                exit(0);
            }
            else{
                cout<<"Bride Checked.\n";
            }
        }
        void checkWitnesses(Witness *witness1,Witness *witness2){
            if(Witness::count_witnesses()<2 || witness1==witness2){
                cout<<"There is no enough witnesses for this marriage...\nThis marriage connot be proceeded.";
                exit(0);
            }
            else{
                //First Witness
                cout<<"First Witness Name: ";
                cin.ignore();
                getline(cin,witness1->_name);

                cout<<"First witness ID Number: ";
                cin>>witness1->_ID_Number;

                cout<<"First Witness Checked.\n";
            
                //Second Witness
                cout<<"Second Witness Name: ";
                cin.ignore();
                getline(cin,witness2->_name);

                cout<<"Second witness ID Number: ";
                cin>>witness2->_ID_Number;

                cout<<"Second Witness Checked.\n";
            }
        }
        void MarriageValidity(Person *groom,Person *bride){
            // Check Religious Compatibility
            if(bride->_religion=="Muslim" && groom->_religion != "Muslim"){
                cout<<"This marriage is not valid as long as the groom is not Muslim.\n";
                exit(0);
            }
            else{
                cout<<"Religion Checked.\n";
            }
        }
        void DocMarriage(Person *groom,Person *bride){
            cout<<"Mahr: ";
            cin>>newContract->_mahr;

            cout<<"House Owner: ";
            cin.ignore();
            cin>>newContract->_propertyOwner;
            if(newContract->_propertyOwner._name==groom->_name){
                newContract->_propertyOwner=*groom;
            }
            else if(newContract->_propertyOwner._name==bride->_name){
                newContract->_propertyOwner=*bride;
            }
            else{
                cout<<"What the heck?!\n";
            }
            cout<<"Fixed Salary in Case of Divorce: ";
            cin>>newContract->_salaryIfDivorce;
        }
};

#endif