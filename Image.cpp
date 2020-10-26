#include "Image.h"

Image::Image(std::string filename, int w, int h, int c) {
	// Open the file
	std::ofstream f;
	f.open(filename, std::ios::out | std::ios::trunc);
	if (f.is_open()) {
		// Set PPM file header
		this->width = w;
		this->height = h;
		this->colors = c;
		this->filename = filename;

		std::stringstream headerString;
		//headerString << "#Beginning of PPM image " << this->filename << std::endl;
		headerString << "P3 " << this->width << " " << this->height << std::endl;
		headerString << this->colors << std::endl;

		f << headerString.str();
		f.close();

		// init the buffer reserving memory
		this->buffer.resize(this->height);
		for (int i = 0; i < this->height; i++) {
			this->buffer[i].resize(this->width);
		}
	} else {
		std::cout << "[ERROR] Cannot open " << filename << " to write PPM file headers." << std::endl;
		exit(1);
	}
}

void Image::setPixel(int x, int y, const Color& c) {
	this->buffer[y][x] = c;
}

void Image::fill() const {
	// Open the file and write it with pixels
	std::ofstream f;
	f.open(this->filename, std::ios::out | std::ios::app);
	if (f.is_open()) {
		// Write the image data from the Color matrix
		std::stringstream line;
		for (int i = 0; i < this->height; i++) {
			for (int x = 0; x < this->width; x++) {
				line << this->buffer[i][x].str();
			}
			line << std::endl;
		}

		f << line.str();
		f.close();
	} else {
		std::cout << "[ERROR] Cannot open " << filename << " to write PPM image data." << std::endl;
		exit(1);
	}
}

std::string Image::getFilename() const {
	return this->filename;
}

int Image::getWidth() const {
	return this->width;
}

int Image::getHeight() const {
	return this->height;
}

int Image::getColorSetting() const {
	return this->colors;
}

std::ostream& operator<<(std::ostream& out, const Image& i) {
	out << "Image filename: " << i.getFilename() << std::endl;
	out << "W: " << i.getWidth() << "\tH: " << i.getHeight() << std::endl;
	out << "Color setting: " << i.getColorSetting() << std::endl;
	return out;
}
