#include "file.h"
#include <string>
#include <iostream>

using namespace std;

File::File() : name("NULL"), ext("NULL") 
{
}

File::File(string x) : name(x), ext("") 
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
	cout << name << ext << endl;
	cout << "Filesize is: " << getSize() << " bytes" << endl;
}
