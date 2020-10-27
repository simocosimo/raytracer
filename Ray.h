#pragma once
#ifndef RAY_H
#define RAY_H

#include <iostream>
#include "Vector3.h"

class Ray {
	Vector3 origin;
	Vector3 direction;

public:
	Ray(const Vector3& origin, const Vector3& direction);
	Vector3 getOrigin() const;
	Vector3 getDirection() const;
	Point3 at(double t = 1) const;

	// << print operator
	friend std::ostream& operator<<(std::ostream& out, const Ray& v);

};

#endif // !RAY_H

