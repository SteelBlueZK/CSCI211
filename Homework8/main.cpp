#include "file.h"
#include "textfile.h"
#include "imagefile.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
	array<File*,5> myFiles;
	myFiles[0] = new ImageFile();
	myFiles[1] = new ImageFile();
	myFiles[2] = new TextFile();
	myFiles[3] = new TextFile();
	myFiles[4] = new ImageFile();
	for (File* i : myFiles){
		cout << i->getName() << endl;
		delete i;
	}
	return 0;
}

