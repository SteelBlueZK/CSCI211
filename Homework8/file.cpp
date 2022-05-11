#include "file.h"
#include <string>
#include <iostream>

using namespace std;

File::File() : name("NULL"), ext("NULL") 
{
}

void File::setName(string replace){
	name = replace;
}

void File::setExt(string replace){
	ext = replace;
}

int File::getSize(){
	return 0;
}

string File::getName(){
	return name;
}

string File::getExt(){
	return ext;
}

void File::displayProperties(){
	cout << "NULL" << endl;
}
