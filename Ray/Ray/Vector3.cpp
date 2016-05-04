#include <cmath>
#include "Vector3.h"
#include "constants.h"


Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3 &ref)
{
	this->x = ref.x;
	this->y = ref.y;
	this->z = ref.z;
}


Vector3::~Vector3()
{
}


// Addition of Vector3 field by field
Vector3 Vector3::operator+(const Vector3 & other) const
{
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

// Subtraction of Vector3 field by field
Vector3 Vector3::operator-(const Vector3 &other) const
{
	return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

// Scalar product
double Vector3::operator*(const Vector3 &other) const
{
	return (this->x * other.x, this->y * other.y, this->z * other.z);
}

// Multiplication by a scalar
void Vector3::scale(double scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
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

void Vector3::X(double x)
{
	this->x = x;
}

void Vector3::Y(double y)
{
	this->y = y;
}

void Vector3::Z(double z)
{
	this->z = z;
}

double Vector3::length(void) const
{
	double length = x*x + y*y + z*z;
	return std::sqrt(length);
}

double Vector3::length_squared(void) const
{
	return x*x + y*y + z*z;
}

void Vector3::normalize(void)
{
	double length = x*x + y*y + z*z;
	if (length <= epsilon)
		return;

	length = std::sqrt(length);

	x /= length;
	y /= length;
	z /= length;
}