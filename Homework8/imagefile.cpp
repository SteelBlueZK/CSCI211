#include "imagefile.h"
#include <iostream>
#include <math.h>
using namespace std;

ImageFile::ImageFile() : File(), xpx(0), ypx(0), clrdpth(0)
{
	setExt(".gif");
}

ImageFile::ImageFile(std::string filename, int sizex, int sizey, int colordepth) : File(filename), xpx(sizex), ypx(sizey), clrdpth(colordepth)
{
	setExt(".gif");
}

int ImageFile::getSize() {
	return xpx*ypx*ceil(double(clrdpth)/8);
}

void ImageFile::displayProperties() {
	File::displayProperties();
	cout << "Image Dimentions: " << xpx << "x" << ypx << endl
		<< "Color Depth: " << clrdpth << "(" << ceil(double(clrdpth)/8) << "bytes per pixel)" << endl;
}

int ImageFile::getXpx() {
	return xpx;
}

int ImageFile::getYpx() {
	return ypx;
}

int ImageFile::getColorDepth() {
	return clrdpth;
}

