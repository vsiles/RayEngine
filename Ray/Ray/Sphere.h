#pragma once
#include "Primitive.h"
class Sphere :
	public Primitive
{
public:
	Sphere();
	Sphere(const Vector3& center, double radius);
	virtual ~Sphere();

	hitStatus Intersect(const Ray &ray, double &dist);
	Vector3 getNormal(const Vector3 &pos);

	const Vector3& getCenter(void) const;
	void setCenter(const Vector3 &center);

	double getRadius(void) const;
	void setRadius(double radius);

	double getSquaredRadius(void) const;
	double getRevRadius(void) const;

protected:
	Vector3 center;
	double radius;
	double sqrRadius;
	double revRadius;
};

