#pragma once
#include <iostream>
using namespace std;


//Callum Simpson -- b6030326

#ifndef CUBIC_H
#define CUBIC_H


class Cubic {

	/*
	A cubic polynomial is a polynomial of degree 3.
	A univariate cubic polynomial has the form .
	An equation involving a cubic polynomial is called a cubic equation.
	A closed-form solution known as the cubic formula exists for the solutions of an arbitrary cubic equation.
	*/

public:


	Cubic();	//Defualt constructor 
	Cubic(double[]); 	//constructor takes in a array of doubles 
	Cubic(const Cubic& aCube);//copy const 


	// get the coifficents of a degree in a cubic
	double getX3()const;
	double getX2()const;
	double getX1()const;
	double getConstant()const;

	//comput the total of the cubic based on x
	double  computeCubic(double input);

	//overload sub and add
	Cubic operator+(const Cubic& rhs)const;
	Cubic operator-(const Cubic& rhs)const;

	//overload times for int and double
	Cubic operator*(int rhs);
	Cubic operator*(double rhs);

	//overload bool
	bool operator==(const Cubic& rhs)const;
	bool operator!=(const Cubic& rhs)const;

	//overload += and -=
	Cubic& operator+=(const Cubic& rhs);
	Cubic& operator-=(const Cubic& rhs);

	//overload for input / output
	friend istream& operator>>(istream& instream, Cubic& cubic);
	friend ostream& operator<<(ostream& instream, const Cubic& cubic);

private:

	//Cubic can only be of size 4 x0 ,x1, x2 ,x3
	double coifficents[4];
};

#endif 