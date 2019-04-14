#pragma once
#include <string>
using namespace std;

/*Node which represents a Include of file*/

class Include{
    public:
        Include(string oneDirect) : direct(oneDirect){}
        virtual ~Include(){}

    protected:
	    string direct;
};
