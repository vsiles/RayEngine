#include "Vector3.h"


Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}


// Addition of Vector3 field by field
Vector3 Vector3::operator+(Vector3 & other)
{
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

// 'Simple function to 'cout' a Vector3
std::ostream &operator<<(std::ostream &os, Vector3 const &m) {
	return os << "V3[x=" << m.X() << ",y=" << m.Y() << ",z=" << m.Z() << "]";
}

// Accessor
double Vector3::X(void) const
{
	return this->x;
}

double Vector3::Y(void) const
{
	return this->y;
}

double Vector3::Z(void) const
{
	return this->z;
}