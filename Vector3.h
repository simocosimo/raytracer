#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

class Vector3 {
	double x;
	double y;
	double z;
	//double magnitude;

public:
	Vector3(double a = 0, double b = 0, double c = 0);
	double magnitude() const;
	Vector3 normalize() const;
	double dot(const Vector3& v);

	// Getters
	double getX() const;
	double getY() const;
	double getZ() const;

	// Add(+) operators
	Vector3 operator+(const Vector3& v) const;
	Vector3& operator+=(const Vector3& v);

	// Sub(-) operators
	Vector3 operator-(const Vector3& v) const;
	Vector3& operator-=(const Vector3& v);

	// Div(/) operators
	Vector3 operator/(const double v) const;
	Vector3& operator/=(const double v);

	// Mul(*) operators
	Vector3 operator*(const double v) const;
	Vector3& operator*=(const double v);

	// << print operator
	friend std::ostream& operator<<(std::ostream& out, const Vector3& v);

	virtual ~Vector3() = default;

};

using Point3 = Vector3;

#endif // !VECTOR3_H

