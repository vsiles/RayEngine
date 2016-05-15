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


void Vector3::operator+=(const Vector3 &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

void Vector3::operator-=(const Vector3 &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}


// Scalar product
double Vector3::dot(const Vector3 &other) const
{
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

// Cross product
void Vector3::operator^=(const Vector3 &other)
{
	x = this->y * other.z - this->z * other.y;
	y = this->z * other.x - this->x * other.z;
	z = this->x * other.y - this->y * other.x;
}


// Multiplication by a scalar
Vector3 operator*(const Vector3 &v, double scalar)
{
	return Vector3(v.x * scalar, v.y *scalar, v.z*scalar);
}

void Vector3::operator*=(const Vector3 &v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

Vector3 operator*(double scalar, const Vector3 &v)
{
	return Vector3(v.x * scalar, v.y *scalar, v.z*scalar);
}

Vector3 operator*(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

void Vector3::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
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

double Vector3::R(void) const
{
	return this->x;
}

double Vector3::G(void) const
{
	return this->y;
}

double Vector3::B(void) const
{
	return this->z;
}

void Vector3::R(double x)
{
	this->x = x;
}

void Vector3::G(double y)
{
	this->y = y;
}

void Vector3::B(double z)
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