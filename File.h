#include <iostream>
#include <fstream>
#include <cstdlib>
#ifndef FILE_H
#define FILE_H
using namespace std;

//This is an abstract class that helps in dealing with files (opening and closing files)
class File{
    protected:
        ofstream _outFile;
        ifstream _inFile;
        virtual void read()=0;
        virtual void write()=0;
};

#endif