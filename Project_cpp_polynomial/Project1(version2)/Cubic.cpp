#pragma once
#include "Cubic.h"
#include <iostream>
#include <string>
#include<cmath>


//Callum Simpson -- b6030326

using namespace std;

Cubic::Cubic()
{
	for (int i = 0; i < 4; i++) {
		coifficents[i] = 0;
	}
}

Cubic::Cubic(double y[])
{

		if (y[3] == 0)
		{
			cout << "The coefficient of the cube cannont be 0";
			y[3] = 1;
		}
		
		for (int i = 3; i >=  0; i--) {
			coifficents[i] = y[i];
		}
	
}

Cubic::Cubic(const Cubic& aCube) {

	if (aCube.coifficents) {

		for (int i = 0; i <= 3; i++)
		{
			coifficents[i] = aCube.coifficents[i];
		}

	}
}

//functions to get the coffients at a give degree.
double Cubic::getX3()const
{
	return coifficents[3];
}

double Cubic::getX2()const
{
	return coifficents[2];
}

double Cubic::getX1()const
{
	return coifficents[1];
}

double Cubic::getConstant()const
{
	return coifficents[0];
}

//compute cubic based on input
double Cubic::computeCubic(double input)
{
	//using pow from the maths libary.
	return (coifficents[3] * pow(input, 3)) + (coifficents[2] * pow(input, 2)) + (coifficents[1] * pow(input, 1)) + coifficents[0];
}

//overload opperators for arthimatic operators 
// each one creates a dummy array to store the results of running the operator that im overloading. Then it makes a new cubic with the results.
Cubic Cubic::operator+(const Cubic& rhs)const
{
	double dummy[4];

	dummy[3] = (coifficents[3] + rhs.getX3());
	dummy[2] = (coifficents[2] + rhs.getX2());
	dummy[1] = (coifficents[1] + rhs.getX1());
	dummy[0] = (coifficents[0] + rhs.getConstant());
	Cubic add(dummy);
	return add;
}

Cubic Cubic::operator-(const Cubic& rhs)const {

	double dummy[4];

	dummy[3] = (coifficents[3] - rhs.getX3());
	dummy[2] = (coifficents[2] - rhs.getX2());
	dummy[1] = (coifficents[1] - rhs.getX1());
	dummy[0] = (coifficents[0] - rhs.getConstant());

	Cubic sub(dummy);
	return sub;
}

Cubic Cubic::operator*(int rhs)
{
	double dummy[4];

	dummy[3] = (coifficents[3] * rhs);
	dummy[2] = (coifficents[2] * rhs);
	dummy[1] = (coifficents[1] * rhs);
	dummy[0] = (coifficents[0] * rhs);
	Cubic multInt(dummy);
	return multInt;
}

Cubic Cubic::operator*(double rhs)
{
	double dummy[4];

	dummy[3] = (coifficents[3] * rhs);
	dummy[2] = (coifficents[2] * rhs);
	dummy[1] = (coifficents[1] * rhs);
	dummy[0] = (coifficents[0] * rhs);
	Cubic multDouble(dummy);
	return multDouble;
}

//overloads of boolean operators 
bool Cubic::operator==(const Cubic& rhs)const
{
	return (coifficents[3] == rhs.coifficents[3] && coifficents[2] == rhs.coifficents[2] && coifficents[1] == rhs.coifficents[1] && coifficents[0] == rhs.coifficents[0]);
}

bool Cubic::operator!=(const Cubic& rhs)const
{
	return (coifficents[3] != rhs.coifficents[3] && coifficents[2] != rhs.coifficents[2] && coifficents[1] != rhs.coifficents[1] && coifficents[0] != rhs.coifficents[0]);
}

//overload of += , returns *this
Cubic& Cubic::operator+=(const Cubic& rhs)
{
	coifficents[3] += rhs.coifficents[3];
	coifficents[2] += rhs.coifficents[2];
	coifficents[1] += rhs.coifficents[1];
	coifficents[0] += rhs.coifficents[0];

	return *this;
}

//overload of -= , returns *this
Cubic& Cubic::operator-=(const Cubic& rhs)
{
	coifficents[3] -= rhs.coifficents[3];
	coifficents[2] -= rhs.coifficents[2];
	coifficents[1] -= rhs.coifficents[1];
	coifficents[0] -= rhs.coifficents[0];

	return *this;
}


istream& operator>>(istream& input, Cubic& cubic)
{
	//for each degree ask for a coefficient
	cout << "enter the coefficients of x^3 ";
	input >> cubic.coifficents[3];
	
	
	cout << "enter the coefficients of x^2 ";
	input >> cubic.coifficents[2];


	cout << "enter the coefficients of x^1 ";
	input >> cubic.coifficents[1];

	
	cout << "enter the coefficients of constant ";
	input >> cubic.coifficents[0];

	
	return input;
}

ostream& operator<<(ostream& output, const Cubic& cubic)
{
	//return each degree with its coifficent
	output << cubic.coifficents[3] << "x^3 + " << cubic.coifficents[2] << "x^2 + " << cubic.coifficents[1] <<  "x^1 + " << cubic.coifficents[0];
	return output;
}
