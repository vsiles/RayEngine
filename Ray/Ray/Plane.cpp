#include "Plane.h"

Plane::Plane(double a, double b, double c, double d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

Plane::Plane(const Vector3 &n, double d)
{
	Vector3 norm = n;
	norm.normalize();

	a = norm.X();
	b = norm.Y();
	c = norm.Z();
	this->d = d;
}

Plane::~Plane()
{
}

double Plane::A(void) const
{
	return a;
}

double Plane::B(void) const
{
	return b;
}

double Plane::C(void) const
{
	return c;
}

double Plane::D(void) const
{
	return d;
}

Vector3 Plane::N(void) const
{
	return Vector3(a, b, c);
}

void Plane::A(double a)
{
	this->a = a;
}

void Plane::B(double b)
{
	this->b = b;
}

void Plane::C(double c)
{
	this->c = c;
}

void Plane::D(double d)
{
	this->d = d;
}

void Plane::N(const Vector3 &n)
{
	a = n.X();
	b = n.Y();
	c = n.Z();
}