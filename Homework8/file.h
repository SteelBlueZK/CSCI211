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
		void propertiesHeader();
	public:
		File();
		File(std::string name);
		virtual ~File();
		std::string getName();
		std::string getExt();
		virtual int getSize() = 0;
		virtual void displayProperties() = 0;
};

#endif//FILE_H
