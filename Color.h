#pragma once
#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

namespace mode {
	const int ADD = 1 << 0;
	const int AVG = 1 << 1;
}

class Color {
	int r;
	int g;
	int b;
	static int addMode;

public:
	Color(int r = 0, int g = 0, int b = 0);
	int getR() const;
	int getG() const;
	int getB() const;
	std::string str() const;
	static void setAddMode(const int& m);

	// Add(+) operators
	Color operator+(const Color& c) const;

	// print operator
	friend std::ostream& operator<<(std::ostream& out, const Color& c);

	virtual ~Color() = default;
};
#endif // !COLOR_H

