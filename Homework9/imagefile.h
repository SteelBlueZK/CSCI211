#ifndef IMAGEFILE_H
#define IMAGEFILE_H

#include "file.h"
#include <iostream>

class ImageFile : public File {
	private:
		int xpx;
		int ypx;
		int clrdpth;
	public:
		ImageFile();
		ImageFile(std::string filename, int sizex, int sizey, int colordepth);
		virtual int getSize();
		virtual void displayProperties();
		int getXpx();
		int getYpx();
		int getColorDepth();
};

#endif//IMAGEFILE_H
