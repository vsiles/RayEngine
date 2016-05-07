#pragma once

#include "Primitive.h"
#include "Vector3.h"
#include "Plane.h"
#include "Ray.h"

class PlanePrim :
	public Primitive
{
public:
	PlanePrim();
	PlanePrim(const Vector3 &normal, double d);
	PlanePrim(const Plane &plane);
	PlanePrim(const PlanePrim &plane);
	virtual ~PlanePrim();

	double getD(void) const;
	Vector3 getNormal(void) const;

	hitStatus Intersect(const Ray &ray, double &dist);

private:
	Plane rawPlane;
};

