#include "file.h"
#include "textfile.h"
#include "imagefile.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
using namespace std;
typedef vector<File*> filevector;

void DisplayVectorFiles(filevector);
filevector* VectorOfType(filevector,string ext);// extention must include the preceding '.', and creates new memory.

void DisplayVectorFiles(filevector vec) {
	if(vec.size() < 1){
		return;
	}
	File* myfile = vec.back();
	vec.pop_back();
	DisplayVectorFiles(vec);
	myfile->displayProperties();
}

filevector* VectorOfType(filevector vec,string ext) {
	if(vec.size() < 1){
		return new filevector;
	}
	File* myfile = vec.back();
	vec.pop_back();
	filevector* retval = VectorOfType(vec, ext);
	if (myfile->getExt().compare(ext) == 0){
		retval->push_back(myfile);
	}
	return retval;
}


int main(){
	std::srand(std::time(NULL));
	filevector files;
	for(int i = 0; i < 15; i++){
		if (rand() % 10 < 4){
			// add new image file 40%
			File* add = new ImageFile("file" + to_string(i), rand() % 900 + 100,rand()% 10 + 90, 1 + rand() % 32);
			files.push_back(add);
		} else {
			// add new text file 60%
			File* add = new TextFile("file" + to_string(i), 1000 + rand() % 5000);
			files.push_back(add);
		}
	}
	cout << "DisplayVectorFiles funciton" << endl;
	DisplayVectorFiles(files);
	cout << endl;

	filevector* store;
	cout << "VectorOfType txt funciton" << endl;
	store = VectorOfType(files,".txt");
	DisplayVectorFiles(*store);
	cout << endl;
	cout << "VectorOfType gif funciton" << endl;
	delete store;
	store = VectorOfType(files,".gif");
	DisplayVectorFiles(*store);
	cout << endl;
	delete store;
	return 0;
}

