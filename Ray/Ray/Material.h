#pragma once

#include "Vector3.h"

typedef Vector3 Color;

class Material
{
public:
	Material();
	virtual ~Material();

	void setColor(const Color& color);
	Color getColor(void) const;
	void setDiffuse(double diffuse);
	double getDiffuse(void) const;

	void setReflection(double refl);
	double GetReflection(void) const;
	double getSpecular(void) const;

protected:
	Color color;
	double refl;
	double diff;
};

