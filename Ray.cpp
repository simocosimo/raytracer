#include "Ray.h"

Ray::Ray(const Vector3& origin, const Vector3& direction) : 
	origin(origin), direction(direction) {
}

Vector3 Ray::getOrigin() const {
	return this->origin;
}

Vector3 Ray::getDirection() const {
	return this->direction;
}

Point3 Ray::at(double t) const {
	return this->origin + (t * this->direction);
}

std::ostream& operator<<(std::ostream& out, const Ray& v) {
	out << "Ray[origin: " << v.getOrigin() << ", direction: " << v.getDirection() << "]";
	return out;
}
