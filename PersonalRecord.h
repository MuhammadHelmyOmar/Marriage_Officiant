#include <iostream>
#include <sstream>
#include <string>
#include "Person.h"
#include "File.h"
#include <map>
#include <vector>
#ifndef PERSONALRECORD_H
#define PERSONALRECORD_H
using namespace std;

class PersonalRecord:private File{
    private:
        //Attributes 
        map<unsigned long long int, vector<string>> _info;//To store the records

        //Methods to Deal with Files
        void write() override{
            this->_outFile.open("Personal_Status_Record.txt",ios::app);
            if(this->_outFile.fail()){
                cout<<"Opening File Failed\n";
                exit(1);
            }
        }
        void read()override{
            this->_inFile.open("Personal_Status_Record.txt");
            if(this->_inFile.fail()){
                cout<<"Opening File Failed\n";
                exit(1);
            }
        }   
        
    public:
        void setInfo(Person *p){
            this->write();

            cout<<"ID Number: ";
            cin>>p->_ID_Number;
            this->_outFile<<endl<<p->_ID_Number<<',';

            cout<<"Name: ";
            cin.ignore();
            getline(cin,p->_name);
            this->_outFile<<p->_name<<',';
            
            cout<<"Gender: ";
            cin>>p->_gender;
            this->_outFile<<p->_gender<<',';
            
            cout<<"Birthdate: ";
            cin>>p->_birthdate;
            this->_outFile<<p->_birthdate<<',';

            cout<<"Religion: ";
            cin>>p->_religion;
            this->_outFile<<p->_religion<<',';

            cout<<"Status: ";
            cin>>p->_status;
            this->_outFile<<p->_status<<',';

            cout<<"Address: ";
            cin.ignore();
            getline(cin,p->_address);
            this->_outFile<<p->_address<<',';

            cout<<"Job: ";
            getline(cin,p->_job);
            this->_outFile<<p->_job;

            this->_outFile.close();
        }
        map<unsigned long long int,vector<string>> getInfo(){
            this->read();

            string Line;//This is to help read the file line by line
            unsigned int i=0;//This is to skip first line (header)
            while(getline(this->_inFile,Line)){
                if(i==0){//This is to skip first line (header)
                    i++;
                    continue;
                }
                else{
                    string word;//To help split the file lines into words
                    stringstream ss(Line);//This is to help split the line by the ',' char
                    vector<string> *currInfo=new vector<string>;//Splitting line into a vector of strings
                    unsigned int j=0;//This is to help store the id as the key of the info map
                    unsigned long long int ID = 0;//This is the temp ID
                    while (getline(ss,word,','))
                    {
                        if(j==0){
                            //This is for casting the id string to an int
                            stringstream id(word);
                            id >> ID;
                            //.
                            j++;
                            continue;
                        }
                        else{
                            currInfo->push_back(word);
                        }
                    }
                    this->_info.emplace(ID,*currInfo);
                    delete currInfo;
                }
            }

            this->_inFile.close();
            return _info;
        }
};
#endif