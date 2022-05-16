#include "file.h"
#include "textfile.h"
#include "imagefile.h"
#include "menu/menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
using namespace std;
typedef vector<File*> filevector;

//globals
string FILENAME = "file.txt";

//header section
void DisplayVectorFiles(filevector);
filevector* VectorOfType(filevector,string ext);// extention must include the preceding '.', and creates new memory.

// funct definitions
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

// main header
void PrintMenu();
void ReadFile(filevector& f);
void DeleteFile(filevector& f, string fullname);

// main function
int main(){
	std::srand(std::time(NULL));
	filevector files, *tempfiles;
	//read from file and add them to files vector
	//menu
	bool exit = false;
	string inst = "";
	do {
		PrintMenu();
		inst = Menu::SolicitInst("Enter menu option");
		if (Menu::CharCompare(inst, 'q')){
			ReadFile(files);
			cout << "new files found\n";
		}
		if (Menu::CharCompare(inst, 'w')){
			string name(Menu::SolicitInst("Enter file name")),
				sizex(Menu::SolicitInst("Enter image width")),
				sizey(Menu::SolicitInst("Enter image height")),
				colord(Menu::SolicitInst("Enter image colordepth"));
			files.push_back(new ImageFile(name, stoi(sizex), stoi(sizey), stoi(colord)));
			cout << "file added\n";
		}
		if (Menu::CharCompare(inst, 'e')){
			string name(Menu::SolicitInst("Enter file name")),
				charc(Menu::SolicitInst("Enter number of characters"));
			files.push_back(new TextFile(name, stoi(charc)));
			cout << "file added\n";
		}
		if (Menu::CharCompare(inst, 'r')){
			DisplayVectorFiles(files);
		}
		if (Menu::CharCompare(inst, 'a')){
			tempfiles = VectorOfType(files,".gif");
			DisplayVectorFiles(*tempfiles);
			delete tempfiles;
		}
		if (Menu::CharCompare(inst, 's')){
			tempfiles = VectorOfType(files,".txt");
			DisplayVectorFiles(*tempfiles);
			delete tempfiles;
		}
		if (Menu::CharCompare(inst, 'd')){
			inst = Menu::SolicitInst("Enter file name(ex. sample.txt)");
			DeleteFile(files, inst);
		}
		if (Menu::CharCompare(inst, 'z')){
			exit = !exit;
		}
	} while (!exit);
	cout << "Goodbye world!" << endl;
	return 0;
}

// mainheader funcitons implimentation

void PrintMenu(){
	cout
		<< "↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓" << endl
		<< "          Project 2\n"
		<< "  q: read from file\n"
		<< "  w: create image file\n"
		<< "  e: create text file\n"
		<< "  r: print all files\n"
		<< "  a: print all image files\n"
		<< "  s: print all text files\n"
		<< "  d: delete file by name\n"
		<< "  z: quit\n"
		<< "↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑" << endl;
}

void ReadFile(filevector& f) {
	ifstream read(FILENAME);
	int streamsize = 100;
	char stream[streamsize];
	string input;

	while (!read.eof()) {
		read.getline(stream, streamsize);
		input = stream;
		if (input.compare("txt") == 0) {
			string name, stringnum;
			read.getline(stream, streamsize);
			name = stream;
			read.getline(stream, streamsize);
			stringnum = stream;
			f.push_back(new TextFile(name,stoi(stringnum)));
		} else 
		if (input.compare("gif") == 0) {
			string name, sizex, sizey, colord;
			read.getline(stream, streamsize);
			name = stream;
			read.getline(stream, streamsize, ' ');
			sizex = stream;
			read.getline(stream, streamsize, ' ');
			read.getline(stream, streamsize);
			sizey = stream;
			read.getline(stream, streamsize);
			colord = stream;
			f.push_back(new ImageFile(name, stoi(sizex), stoi(sizey), stoi(colord)));
		}
	}
	read.close();
}

void DeleteFile(filevector& f, string fullname) {
	for (int i = 0; i < f.size(); ++i) {
		if (fullname.compare(f[i]->getName() + f[i]->getExt()) == 0) {
			delete f[i];
			f.erase(f.begin() + i);
			cout << "file deleted\n";
			return;
		}
	}
	cout << "file not found\n";
}

