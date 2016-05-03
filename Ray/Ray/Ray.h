#pragma once

#include "Vector3.h"
class Ray
{
public:
	Ray();
	Ray(Vector3 origin, Vector3 direction);
	virtual ~Ray();

	const Vector3 &Origin(void) const;
	const Vector3 &Direction(void) const;

	void Origin(Vector3 &origin);
	void Direction(Vector3 &direction);

protected:
	Vector3 origin;
	Vector3 direction;
};

