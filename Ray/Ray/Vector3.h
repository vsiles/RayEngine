#pragma once

#include <ostream>

class Vector3
{
public:
	Vector3(double x=0.0, double y=0.0, double z=0.0);
	virtual ~Vector3();

	// Addition of Vector3 field by field
	Vector3 operator+(Vector3 & other);

	// Accessor
	double X(void) const;
	double Y(void) const;
	double Z(void) const;

	// Mutator
	void X(double x);
	void Y(double y);
	void Z(double z);

	// norm stuff
	double length(void) const;
	double length_squared(void) const;
	void normalize(void);


protected:
	double x;
	double y;
	double z;
};

// 'Simple function to 'cout' a Vector3
std::ostream &operator<<(std::ostream &os, Vector3 const &m);
