#include "Material.h"



Material::Material() : color()
{
	refl = 0.0;
	diff = 0.0;
}


Material::~Material()
{
}

void Material::setColor(Color& color)
{
	this->color = color;
}

Color Material::getColor(void) const
{
	return color;
}

void Material::setDiffuse(double diffuse)
{
	this->diff = diffuse;
}

double Material::getDiffuse(void) const
{
	return diff;
}

void Material::setReflection(double refl)
{
	this->refl = refl;
}

double Material::GetReflection(void) const
{
	return refl;
}

double Material::getSpecular(void) const
{
	return 1 - diff;
}