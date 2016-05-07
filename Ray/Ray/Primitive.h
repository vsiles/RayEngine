#pragma once

#include <string>
#include "Material.h"
#include "Ray.h"
#include "Vector3.h"
#include "constants.h"

class Primitive
{
public:
	Primitive();
	virtual ~Primitive();

	/*
	enum
	{
		SPHERE = 1,
		PLANE
	};
	*/
	const Material& getMaterial(void) const;
	void setMaterial(const Material& mat);

	//virtual int GetType() = 0;

	virtual hitStatus Intersect(const Ray &ray, double &dist) = 0;
	virtual Vector3 getNormal(Vector3 &pos) const = 0;
	virtual Color getColor(void) const;
	virtual void setLight(bool light);
	bool isLight(void) const;
	void setName(const std::string &name);
	const std::string &getName(void) const;

protected:
	Material material;
	std::string name;
	bool light;
};

