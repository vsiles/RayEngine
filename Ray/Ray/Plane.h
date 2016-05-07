#pragma once

#include "Vector3.h"

class Plane
{
public:
	Plane(double a = 0.0, double b = 0.0, double c = 0.0, double d = 0.0);
	Plane(const Vector3 &n, double d);
	virtual ~Plane();

	double A(void) const;
	double B(void) const;
	double C(void) const;
	double D(void) const;
	Vector3 N(void) const;

	void A(double a);
	void B(double b);
	void C(double c);
	void D(double d);
	void N(const Vector3 &n);)

protected:
	double a;
	double b;
	double c;
	double d;
};

