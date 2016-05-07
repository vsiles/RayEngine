#pragma once

#include "Vector3.h"
class Ray
{
public:
	Ray();
	Ray(Vector3 origin, Vector3 direction);
	virtual ~Ray();

	const Vector3 &getOrigin(void) const;
	const Vector3 &getDirection(void) const;

	void setOrigin(Vector3 &origin);
	void setDirection(Vector3 &direction);

protected:
	Vector3 origin;
	Vector3 direction;
};

