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


const Vector3& Ray::getOrigin(void) const
{
	return origin;
}

const Vector3& Ray::getDirection(void) const
{
	return direction;
}

void Ray::setOrigin(Vector3 &origin)
{
	this->origin = origin;
}

void Ray::setDirection(Vector3 &direction)
{
	this->direction = direction;
}