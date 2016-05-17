#pragma once

#include <ostream>

class Vector3
{
public:
	Vector3(double x=0.0, double y=0.0, double z=0.0);
	Vector3(const Vector3 &ref);
	virtual ~Vector3();

	// Addition of Vector3 field by field
	friend Vector3 operator+(const Vector3 v1, const Vector3 &v2) {
		return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}
	void operator+=(const Vector3 &other);

	// Subtraction of Vector3 field by field
	friend Vector3 operator-(const Vector3 v1, const Vector3 &v2) {
		return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}
	void operator-=(const Vector3 &other);

	// Scalar product
	double dot(const Vector3 &other) const;

	// Cross product
	friend Vector3 operator^(const Vector3 &v1, const Vector3 &v2) {
		return Vector3(
                        v1.y * v2.z - v1.z * v2.y,
                        v1.z * v2.x - v1.x * v2.z,
                        v1.x * v2.y - v1.y * v2.x);
	}
	void operator^=(const Vector3 &other);

	// Multiplication by a scalar
	friend Vector3 operator*(const Vector3 &v, double scalar);
	friend Vector3 operator*(double scalar, const Vector3 &v);
	void operator*=(const Vector3 &v);
	friend Vector3 operator*(const Vector3 &v1, const Vector3 &v2);
	void operator*=(double scalar);

	// unary opp
	Vector3 operator- () const;

	// Accessor
	double X(void) const;
	double Y(void) const;
	double Z(void) const;

	double R(void) const;
	double G(void) const;
	double B(void) const;

	// Mutator
	void X(double x);
	void Y(double y);
	void Z(double z);

	void R(double r);
	void G(double g);
	void B(double b);

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

