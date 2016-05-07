#include "PlanePrim.h"

PlanePrim::PlanePrim() : rawPlane()
{
}

PlanePrim::PlanePrim(const Vector3 &normal, double d) : rawPlane(normal, d)
{
}

PlanePrim::PlanePrim(const Plane &plane) : rawPlane(plane)
{
}

PlanePrim::PlanePrim(const PlanePrim &plane) : rawPlane(plane.rawPlane)
{
}

PlanePrim::~PlanePrim()
{
}

double PlanePrim::getD(void) const
{
	return rawPlane.D();
}

Vector3 PlanePrim::getNormal(const Vector3 &pos) const
{
	(void)pos;
	return rawPlane.N();
}

hitStatus PlanePrim::Intersect(const Ray &ray, double &dist)
{
	double d = rawPlane.N() * ray.getDirection();
	if (abs(d) > epsilon)
	{
		double tempdist = -((rawPlane.N() * ray.getOrigin()) + rawPlane.D()) / d;
		if (tempdist > 0)
		{
			if (tempdist < dist)
			{
				dist = tempdist;
				return HIT;
			}
		}
	}
	return MISS;
}
