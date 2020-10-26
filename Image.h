#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Color.h"

class Image {
	int width;
	int height;
	int colors;
	std::string filename;
	std::vector<std::vector<Color>> buffer;

public:
	Image(std::string filename, int w, int h, int c);
	void fill() const;
	void setPixel(int x, int y, const Color& c);
	std::string getFilename() const;
	int getWidth() const;
	int getHeight() const;
	int getColorSetting() const;

	// print operator
	friend std::ostream& operator<<(std::ostream& out, const Image& i);

	virtual ~Image() = default;
};

#endif // !IMAGE_H

