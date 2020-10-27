#include "Vector3.h"

Vector3::Vector3(double a, double b, double c) {
	this->x = a;
	this->y = b;
	this->z = c;
}

double Vector3::magnitude() const {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3 Vector3::normalize() const {
	return (*this) / this->magnitude();
}

double Vector3::dot(const Vector3& v) {
	return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
}

// Getters
double Vector3::getX() const {
	return this->x;
}

double Vector3::getY() const {
	return this->y;
}

double Vector3::getZ() const {
	return this->z;
}

// Operators
Vector3 Vector3::operator/(const double v) const {
	double _x = this->x / v;
	double _y = this->y / v;
	double _z = this->z / v;

	Vector3 res(_x, _y, _z);
	
	return res;
}

Vector3& Vector3::operator/=(const double v) {
	this->x /= v;
	this->y /= v;
	this->z /= v;

	return (*this);
}

Vector3 Vector3::operator+(const Vector3& v) const {
	double _x = this->x + v.x;
	double _y = this->y + v.y;
	double _z = this->z + v.z;

	Vector3 res(_x, _y, _z);

	return res;
}

Vector3& Vector3::operator+=(const Vector3& v) {
	this->x += v.x;
	this->x += v.y;
	this->x += v.z;

	return (*this);
}

Vector3 Vector3::operator-(const Vector3& v) const {
	double _x = this->x - v.x;
	double _y = this->y - v.y;
	double _z = this->z - v.z;

	Vector3 res(_x, _y, _z);

	return res;
}

Vector3& Vector3::operator-=(const Vector3& v) {
	this->x -= v.x;
	this->x -= v.y;
	this->x -= v.z;

	return (*this);
}

Vector3 Vector3::operator*(const double v) const {
	double _x = this->x * v;
	double _y = this->y * v;
	double _z = this->z * v;

	Vector3 res(_x, _y, _z);

	return res;
}

Vector3& Vector3::operator*=(const double v) {
	this->x *= v;
	this->y *= v;
	this->z *= v;

	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Vector3& v) {
	out << "(x: " << v.getX() << ", y: " << v.getY() << ", z: " << v.getZ() << ")";
	return out;
}