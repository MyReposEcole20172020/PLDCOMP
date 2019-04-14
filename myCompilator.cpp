#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, const char ** argv) 
{
	int status = 0;
	if (argc == 2 )
	{
		string docName = argv[1];
		string fileName = "";

		int index = docName.find_last_of('/');
		if (index != string::npos)
		{
			fileName = docName.substr(index+1,docName.size()-1);
			for (int i = 0; i < fileName.size()+1 ; i++)
			{
	 			docName.pop_back();

			}
		}
		else
		{
			fileName=docName;
		}
		

		fileName.pop_back();
		fileName.pop_back();
	
		string command;
		if (index != string::npos)
		{
			command = "make build folderC="+ docName + " file=" + fileName;
		}
		else
		{
			command = "make build folderC=. file=" + fileName;
		}	

		status = system(command.c_str());
	}
	return status;
}
