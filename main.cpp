#include "Vector3.h"
#include "Color.h"
#include "Image.h"
#include "Scene.h"
#include "Ray.h"
#include <memory>

#define ASPECT_RATIO	16.0 / 9.0
#define IMG_WIDTH		3
#define IMG_HEIGHT		IMG_WIDTH / ASPECT_RATIO

int main(int argc, char** argv) {

	Image img("out.ppm", IMG_WIDTH, IMG_HEIGHT, 255);

	Vector3 camera(0, 0, 0);
	// Sphere sphere1(Vector3(0, 0, 0), 1, Color(255, 0, 0));
	// Sphere sphere2(Vector3(0, 0, 0), 1.5, Color(0, 0, 255));
	
	Scene scene1(camera);
	// scene1.addObject(sphere1);
	
	Scene scene2(camera);
	scene2.setSkyboxType(skybox::solid);
	scene2.setSkyboxColors(Color(170, 170, 170));
	// scene2.addObject(sphere2);

	// img.render(scene1);

	return 0;
}