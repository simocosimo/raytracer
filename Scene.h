#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Color.h"
#include "Vector3.h"

namespace skybox {
	const int solid		=	1 << 0;
	const int gradient	=	1 << 1;
	const int black		=	1 << 2;
}

class Scene {
	// TODO: Add objects list in scene
	// std::vector<Object> objects;
	Vector3 camera;
	int skyboxType;
	Color primary;
	Color secondary;

public:
	Scene(const Vector3& cam, const int skyType = skybox::gradient);
	// std::vector<Object> getObjects() const;
	void setSkyboxType(const int type);
	void setSkyboxColors(const Color& first, const Color& second = NULL);
	// void addObject(const Object& obj);
	// void addObject(const std::vector<Object> objs);

};

#endif // !SCENE_H

