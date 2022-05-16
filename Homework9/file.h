#ifndef FILE_H
#define FILE_H

#include <string>

class File {
	private:
		std::string name;
		std::string ext;
	protected:
		void setExt(std::string replace);
		void propertiesHeader();
	public:
		File();
		File(std::string name);
		virtual ~File();
		std::string getName();// returns name without extention
		std::string getExt();// Also works as get type
		void setName(std::string replace);
		virtual int getSize() = 0;
		virtual void displayProperties() = 0;
};

#endif//FILE_H
