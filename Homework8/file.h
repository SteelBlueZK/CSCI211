#ifndef FILE_H
#define FILE_H

#include <string>

class File {
	private:
		std::string name;
		std::string ext;
	protected:
		void setName(std::string replace);
		void setExt(std::string replace);
	public:
		File();
		std::string getName();
		std::string getExt();
		virtual int getSize();
		virtual void displayProperties();
};

#endif//FILE_H
