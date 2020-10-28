#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include "Vector3.h"
#include "Color.h"

class Object {
	Vector3 pos;
	Color color;

public:
	Object(const Vector3& position, const Color& color);

};


#endif // !OBJECT_H
