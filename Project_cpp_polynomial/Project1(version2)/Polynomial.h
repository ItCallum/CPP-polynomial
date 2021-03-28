#pragma once
#include <iostream>
using namespace std;


//Callum Simpson -- b6030326

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {

	
	//Polynomial(const Polynomial&);
public:

	//default const 
	Polynomial();

	Polynomial(double y[],int x);

	//copy const 
	Polynomial(const Polynomial& aPoly);
	
	//deconstutor  
	~Polynomial();

	//getters
	int getDegree()const;
	double getCoefficient(int i)const;

	//comput a polly based on an input
	double  computePolynomial(double input);

	Polynomial& operator=(const Polynomial& rhs);//

	//opertations overload
	Polynomial operator+(const Polynomial& rhs)const; //
	Polynomial operator-(const Polynomial& rhs)const; //

	//opertations overload on times, int and double 
	Polynomial& operator*(int rhs) ; //
	Polynomial& operator*(double rhs) ; //

	//opertations overload on times, another polly 
	Polynomial operator*(const Polynomial& rhs); //
	Polynomial operator*=(const Polynomial& rhs);//

	//overload bool comparisons 
	bool operator==(const Polynomial& rhs)const ;//
	bool operator!=(const Polynomial& rhs)const;//


	Polynomial& operator+=(const Polynomial& rhs);//
	Polynomial& operator-=(const Polynomial& rhs);//

	//overload input and output	
	friend istream& operator>>(istream& input, Polynomial& cubic);
	friend ostream& operator<<(ostream& output,const Polynomial cubic); //

private:

	//int for degrees
	int degree;

	//pointer to a double where I will store an array
	double* coefficients;

};



#endif 
