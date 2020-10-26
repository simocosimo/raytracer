#include "Color.h"

// default adding method
int Color::addMode = mode::ADD;

Color::Color(int r, int g, int b) {
	try {
		if (r >= 0 && r <= 255 &&
			g >= 0 && g <= 255 &&
			b >= 0 && b <= 255) {
			this->r = r;
			this->g = g;
			this->b = b;
		} else {
			throw "[ERROR] Invalid color values. Please use 8bit color values (from 0 to 255).";
		}
	} catch (const std::string e) {
		std::cout << e << std::endl;
		exit(2);
	}
}

int Color::getR() const {
	return this->r;
}

int Color::getG() const {
	return this->g;
}

int Color::getB() const {
	return this->b;
}

std::string Color::str() const {
	std::stringstream colorString;
	colorString << this->r << " " << this->g << " " << this->b << " ";
	return colorString.str();
}

// TODO: refactor this after doing a logger
void Color::setAddMode(const int& m) {
	switch (m)
	{
	case mode::ADD:
		std::cout << "[DEBUG] Setting ADD as color add method." << std::endl;
		Color::addMode = mode::ADD;
		break;

	case mode::AVG:
		std::cout << "[DEBUG] Setting AVG as color add method." << std::endl;
		Color::addMode = mode::AVG;
		break;

	default:
		std::cout << "[WARNING] Invalid color add method. Setting ADD as default." << std::endl;
		Color::addMode = mode::ADD;
		break;
	}
}

Color Color::operator+(const Color& c) const {
	int _r = 0;
	int _g = 0;
	int _b = 0;

	// TODO: Check if this mode has a logic or it's dumb
	if (Color::addMode & mode::ADD) {
		_r = this->r + c.r;
		_g = this->g + c.g;
		_b = this->b + c.b;

		// Normalize values between 0 and 255
		if (_r < 0) _r = 0;
		else if (_r > 255) _r = 255;

		if (_g < 0) _g = 0;
		else if (_g > 255) _g = 255;

		if (_b < 0) _b = 0;
		else if (_b > 255) _b = 255;
	} 

	if (Color::addMode & mode::AVG) {
		// alredy normalized
		_r = sqrt((pow(this->r, 2) + pow(c.r, 2)) / 2);
		_g = sqrt((pow(this->g, 2) + pow(c.g, 2)) / 2);
		_b = sqrt((pow(this->b, 2) + pow(c.b, 2)) / 2);
	}
	
	Color res(_r, _g, _b);
	return res;
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
	out << "(r: " << c.getR() << ", g: " << c.getG() << ", b: " << c.getB() << ")";
	return out;
}