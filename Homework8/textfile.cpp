#include "textfile.h"
#include <iostream>
using namespace std;

TextFile::TextFile() : File(), charCount(0)
{
	setExt(".txt");
}

TextFile::TextFile(std::string name, int numofchar) : File(name), charCount(numofchar)
{
	setExt(".txt");
}

int TextFile::getSize(){
	return charCount;
}

void TextFile::displayProperties(){
	File::displayProperties();
	cout << "Number of characters in document: " << charCount << endl;
}

int TextFile::getCharacterCount() {
	return charCount;
}

