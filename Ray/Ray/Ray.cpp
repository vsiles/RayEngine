#include "Ray.h"



Ray::Ray() : origin(), direction()
{
}

Ray::Ray(Vector3 origin, Vector3 direction)
{
	this->origin = origin;
	this->direction = direction;
}


Ray::~Ray()
{
}


const Vector3& Ray::Origin(void) const
{
	return origin;
}

const Vector3& Ray::Direction(void) const
{
	return direction;
}

void Ray::Origin(Vector3 &origin)
{
	this->origin = origin;
}

void Ray::Direction(Vector3 &direction)
{
	this->direction = direction;
}