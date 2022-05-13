#include "file.h"
#include "textfile.h"
#include "imagefile.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
	array<File*,5> myFiles;
	myFiles[0] = new ImageFile("DancingCat", 100, 100, 8);
	myFiles[1] = new ImageFile("MulticolorMeme", 600, 800, 32);
	myFiles[2] = new TextFile("HomeworkLinks",3012);
	myFiles[3] = new TextFile("grocerylist",632);
	myFiles[4] = new ImageFile("Brother'sFail", 1800,4000,64);
	for (File* i : myFiles){
		i->displayProperties();
		cout << endl;
		delete i;
	}
	return 0;
}

