#pragma once
#pragma once

#include<iostream>
using namespace std;

template<class Type>
class vec;

template<typename Type>
vec<Type> operator*(Type scalar, vec<Type>& v);

template<class Type>
class vec {
public:
	Type x;
	Type y;
	Type z;

public:

	vec();
	vec(Type x1, Type y1, Type z1);
	float magnitude();
	vec operator +(const vec& v);
	vec operator -(const vec& v);
	vec(const vec& v);
	vec operator *(Type scalar);
	vec operator *(const vec& v);
	vec normalize();
	vec crossproduct(vec& v1, vec& v2);
	Type dotproduct(const vec& v1, const vec& v2);
	float sinearc(vec& v1, vec& v2);
	float coarc(vec& v1, vec& v2);
	float distance(const vec& v1, const vec& v2);
	void print();
	friend vec operator* (Type scalar, vec<Type>& v) {
		v.x = scalar * v.x;
		v.y = scalar * v.y;
		v.z = scalar * v.z;
		return v;
	}
};