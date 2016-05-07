#include <cmath>
#include "constants.h"
#include "Sphere.h"


Sphere::Sphere() : center()
{
	radius = 0.0;
	sqrRadius = 0.0;
	revRadius = 0.0;
}

Sphere::Sphere(const Vector3& center, double radius)
{
	radius = fabs(radius);
	this->center = center;
	this->radius = radius;
	sqrRadius = radius * radius;
	if (radius < epsilon)
		revRadius = 0.0;
	else
		revRadius = 1.0 / radius;
}

Sphere::~Sphere()
{
}

hitStatus Sphere::Intersect(const Ray &ray, double &dist)
{
	Vector3 v = ray.getOrigin() - center;
	double b = -(v * ray.getDirection());
	double det = (b * b) - (v * v) + sqrRadius;
	hitStatus retval = MISS;
	if (det > 0)
	{
		det = sqrt(det);
		double i1 = b - det;
		double i2 = b + det;
		if (i2 > 0)
		{
			if (i1 < 0)
			{
				if (i2 < dist)
				{
					dist = i2;
					retval = INPRIM;
				}
			}
			else
			{
				if (i1 < dist)
				{
					dist = i1;
					retval = HIT;
				}
			}
		}
	}
	return retval;
}

Vector3 Sphere::getNormal(const Vector3 &pos)
{
	return (pos - center) * revRadius;
}

const Vector3& Sphere::getCenter(void) const
{
	return center;
}

void Sphere::setCenter(const Vector3 &center)
{
	this->center = center;
}

double Sphere::getRadius(void) const
{
	return radius;
}

void Sphere::setRadius(double radius)
{
	radius = fabs(radius);
	this->radius = radius;
	sqrRadius = radius * radius;
	if (radius < epsilon)
		revRadius = 0.0;
	else
		revRadius = 1.0 / radius;
}

double Sphere::getSquaredRadius(void) const
{
	return sqrRadius;
}

double Sphere::getRevRadius(void) const
{
	return revRadius;
}