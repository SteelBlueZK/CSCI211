#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "file.h"

class TextFile : public File {
	private:
		int charCount;
	public:
		TextFile();
		TextFile(std::string name, int numofchar);
		virtual int getSize();
		virtual void displayProperties();
		int getCharacterCount();
};

#endif//TEXTFILE_H
