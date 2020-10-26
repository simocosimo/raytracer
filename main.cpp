#include "Vector3.h"
#include "Color.h"
#include "Image.h"
#include <memory>

#define IMG_WIDTH	3
#define IMG_HEIGHT	2

int main(int argc, char** argv) {

	Color white(255, 255, 255);
	Color black(0, 0, 0);
	Color red(255, 0, 0);
	Color green(0, 255, 0);
	Color blue(0, 0, 255);

	Image avgImage("avg-test.ppm", IMG_WIDTH, IMG_HEIGHT, 255);
	Image addImage("add-test.ppm", IMG_WIDTH, IMG_HEIGHT, 255);

	// ADD mode
	Color::setAddMode(mode::ADD);
	Color yellow = red + green;
	std::cout << "red + green = " << yellow << std::endl;
	addImage.setPixel(0, 0, red);
	addImage.setPixel(1, 0, green);
	addImage.setPixel(2, 0, blue);
	addImage.setPixel(0, 1, yellow);
	addImage.setPixel(1, 1, white);
	addImage.setPixel(2, 1, black);
	addImage.fill();

	// AVG mode
	Color::setAddMode(mode::AVG);
	Color mixed = red + green;
	std::cout << "red + green = " << mixed << std::endl;
	Color grey = white + black;
	std::cout << "white + black = " << grey << std::endl;
	avgImage.setPixel(0, 0, red);
	avgImage.setPixel(1, 0, green);
	avgImage.setPixel(2, 0, blue);
	avgImage.setPixel(0, 1, mixed);
	avgImage.setPixel(1, 1, grey);
	avgImage.setPixel(2, 1, black);
	avgImage.fill();

	return 0;
}