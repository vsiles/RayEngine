#include "Primitive.h"

Primitive::Primitive() : material(), name()
{
	light = false;
}


Primitive::~Primitive()
{
}

const Material& Primitive::getMaterial(void) const
{
	return material;
}

void Primitive::setMaterial(const Material& mat)
{
	material = mat;
}

Color Primitive::getColor(void) const
{
	return material.getColor();
}

void Primitive::setLight(bool light)
{
	this->light = light;
}

bool Primitive::isLight(void) const
{
	return light;
}

void Primitive::setName(const std::string &name)
{
	this->name.clear();
	this->name = name;
}

const std::string &Primitive::getName(void) const
{
	return name;
}
