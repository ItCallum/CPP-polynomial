#pragma once
#include "Polynomial.h"
#include<cmath>

//Callum Simpson -- b6030326

//deconstruct
Polynomial::~Polynomial()
{
	//if coefficients has a value deconstruct it
	if (coefficients)
	{
		delete[] coefficients;
		coefficients = nullptr;
	}
}

//default const 
Polynomial::Polynomial()
{
	//make a poly with no values
	degree = 0;
	coefficients = new double[degree + 1];
	coefficients[0] = 0;
}

//create a poly using an array and a int
Polynomial::Polynomial(double y[],int x)
{
	//set the degree to be equal the int
	degree = x;

	coefficients = new double[degree + 1];

	//as c cant find the size of an array we are going to assume that a user is going to check 

	//for (int i = 0; i <= degree; i++) {
	//	coefficients[i] = 0;
	//}

	for (int i = 0; i <= degree; i++) {
		coefficients[i] = y[i];
	}
}

//copy constructor 
Polynomial::Polynomial(const Polynomial& Poly)
{
	coefficients = new double[Poly.degree + 1];
	
	//as c cant find the size of an array we are going to assume that a user is going to pass in the correct value 

	//for (int i = 0; i <= degree; i++) {
	//	coefficients[i] = 0;
	//}

	for(int i = 0; i <= (int)Poly.degree; i++)
	{
		coefficients[i] = Poly.coefficients[i];
	}

	degree = Poly.degree;
}

//get the highest degree
int Polynomial::getDegree()const {
	return degree;
}

//get the Coefficient of a given degree, if it dosnt exist then return 0
double Polynomial::getCoefficient(int i)const {

	//if the degree exists in the poly return the relateded poly 
	if (i <= degree && i >= 0) {
		return coefficients[i];
	}
	//else return zero
	else {
		return 0;
	}
}


//given a value of x calucate a polynomial
double Polynomial::computePolynomial(double input)
{
	double totalsum = 0;

	for (int i = 0; i <= degree; i++) {

		//if i isnt x^0 then do input the power * coefficient  		
		if (i != 0) {
			totalsum = totalsum + (coefficients[i] * pow(input, i));
		}	
		// else just add the x^0 coeff to the total sum 
		else {
			totalsum = totalsum + coefficients[i];
		}
	}

	return totalsum;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs)
{

	//delet current coeff
	if (coefficients)
	{
		delete[] coefficients;
		coefficients = nullptr;
	}

	//create a new coeff
	coefficients = new double[rhs.degree + 1];

	//copy all values from right had side to coeff 
	for (int i = 0; i <= (int)rhs.degree; i++)
	{
		coefficients[i] = rhs.coefficients[i];
	}

	//set the degree to be equal rhs
	degree = rhs.degree;

	return *this;
}

//overload +
Polynomial Polynomial::operator+(const Polynomial& rhs)const
{
	int largestSize = (degree > rhs.degree) ? degree : rhs.degree;
	
	//create a new array to store the result of adding the 2 polys together 
	int arraysize = largestSize + 1;
	double* tempcoefficients = new double[arraysize];

	// set every value of the array to zero
	for (int i = 0; i <= largestSize; i++) {
		tempcoefficients[i] = 0;
	}

	//std::memset(tempcoefficients, 0, largestSize + 1);

	//add everything on the lhs to the tempcoefficient
	for (int i = 0; i <= degree; i++) {
		tempcoefficients[i] += coefficients[i];
	}

	//add everything on the rhs to the tempcoefficient
	for (int i = 0; i <= rhs.degree;  i++) {
		tempcoefficients[i] += rhs.coefficients[i];
	}

	//create a new poly
	Polynomial sum(tempcoefficients, largestSize);

	//deconstruct tempcoefficients
	if(tempcoefficients)
	{
		delete[] tempcoefficients;
		tempcoefficients = nullptr;
	}

	return sum;
}

//overload -
Polynomial Polynomial::operator-(const Polynomial& rhs)const
{
	int largestSize = (degree > rhs.degree) ? degree : rhs.degree;

	int arraysize = largestSize + 1;
	double* tempcoefficients = new double[arraysize];

	for (int i = 0; i <= largestSize; i++) {
		tempcoefficients[i] = 0;
	}

	//std::memset(tempcoefficients, 0, largestSize + 1);

	for (int i = 0; i <= degree; i++) {
		tempcoefficients[i] += coefficients[i];
	}

	for (int i = 0; i <= rhs.degree; i++) {
		tempcoefficients[i] -= rhs.coefficients[i];
	}

	//create a new poly
	Polynomial minus(tempcoefficients, largestSize);


	//deconstruct tempcoefficients
	if (tempcoefficients)
	{
		delete[] tempcoefficients;
		tempcoefficients = nullptr;
	}

	return minus;
}

//times by an int
Polynomial& Polynomial::operator*(int rhs)
{
	for (int i = 0; i <= degree; i++) {
		coefficients[i] = coefficients[i] * rhs;
	}

	return *this;
}

//times by an double
Polynomial& Polynomial::operator*(double rhs)
{
	for (int i = 0; i <= degree; i++) {
		coefficients[i] = coefficients[i] * rhs;
	}

	return *this;
}

//times by and a poly
Polynomial Polynomial::operator*(const Polynomial& rhs)
{

	int tempdegree = degree + rhs.degree;

	int arraysize = tempdegree + 1;
	double* tempcoefficients = new double[arraysize];

	for (int i = 0; i <= tempdegree; i++) {
		tempcoefficients[i] = 0;
	}

	//std::memset(tempcoefficients, 0, tempdegree + 1);


	//add the degrees togther to find what postion of the array I should be modifying 
	// set that value to be coefficients[i] * rhs.coefficients[j]
	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j <= rhs.degree; j++) {
			tempcoefficients[i + j] += (coefficients[i] * rhs.coefficients[j]);
		}
	}
	 
	Polynomial mult(tempcoefficients, tempdegree);

	if (tempcoefficients)
	{
		delete[] tempcoefficients;
		tempcoefficients = nullptr;
	}

	return mult;
}

//overload ==
bool Polynomial::operator==(const Polynomial& rhs)const
{
	bool result = true;

	if (degree != rhs.degree) {
		result = false;
	}

	else {
		int i = 0;
		
		//go through each value in the array and if its not equal remove it
		while (result == true && i <= degree) {

			if (coefficients[i] != rhs.coefficients[i]) {
				result = false;

			}
			i++;
		}
	
	}
	return result;
}

//overload !=
bool Polynomial::operator!=(const Polynomial& rhs)const
{
	return !operator==(rhs);
}


//operator+=
Polynomial& Polynomial::operator+=(const Polynomial& rhs)
{	

	//set the tempdegree to be the largest degree of the two
	int tempdegree = (degree < rhs.degree) ? rhs.degree : degree;

	int arraysize = tempdegree + 1;
	double* tempcoefficients = new double[arraysize];

	for (int i = 0; i <= tempdegree; i++)
	{
		tempcoefficients[i] = 0;
	}

	//std::memset(tempcoefficients, 0, tempdegree + 1);

	for (int i = 0; i <= degree; i++) {
		tempcoefficients[i] += coefficients[i];
	}

	for (int i = 0; i <= rhs.degree; i++) {
		tempcoefficients[i] += rhs.coefficients[i];
	}

	if (coefficients)
	{
		delete[] coefficients;
		coefficients = nullptr;
	}

	degree = tempdegree;
	coefficients = tempcoefficients;
	return *this;
}

//operator-=
Polynomial& Polynomial::operator-=(const Polynomial& rhs)
{

	//set the tempdegree to be the largest degree of the two
	int tempdegree = (degree < rhs.degree) ? rhs.degree : degree;

	double* tempcoefficients = new double[tempdegree + 1];

	for (int i = 0; i <= tempdegree; i++)
	{
		tempcoefficients[i] = 0;
	}

	//std::memset(tempcoefficients, 0, tempdegree + 1);

	//minus rhs from lhs and store results in tempcoefficients

	for (int i = 0; i <= degree; i++) {
		tempcoefficients[i] = tempcoefficients[i] + coefficients[i] ;
	}

	for (int i = 0; i <= rhs.degree; i++) {
		tempcoefficients[i] = tempcoefficients[i] - rhs.coefficients[i];
	}

	if (coefficients)
	{
		delete[] coefficients;
		coefficients = nullptr;
	}

	degree = tempdegree;
	coefficients = tempcoefficients;

	return *this;
}

//operator*=
Polynomial Polynomial::operator*=(const Polynomial& rhs)
{
	
	//the biggest degree gotten when multi is degree + rhs.degree
	int tempdegree = degree + rhs.degree;

	//create a new array of size tempdegree to store all of the multi 
	double* tempcoefficients = new double[tempdegree + 1];

	std::memset(tempcoefficients, 0, tempdegree + 1);

	//add the degrees togther to find what postion of the array I should be modifying 
	// set that value to be coefficients[i] * rhs.coefficients[j]
	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j <= rhs.degree; j++) {
			tempcoefficients[i + j] = (coefficients[i] * rhs.coefficients[j]);
		}
	}

	//deconstruct 
	if (coefficients)
	{
		delete[] coefficients;
		coefficients = nullptr;
	}

	degree = tempdegree;

	coefficients = tempcoefficients;

	return *this;
}

/*
istream& operator>>(istream& input, Polynomial& poly)
{
	char spec = '|';
	char x = 'x';
	char powerof = '^';
	//int power;
	//char op;

	int temp;
	input >> temp;

	poly.degree = temp;
	delete[] poly.coefficients;

	double * temparray = new double[temp + 1];

	for (int i = temp; i >= 0; i--) {
		input >> spec >> temparray[i];
		//if (op == '-')
			//poly.coefficients[i] = -poly.coefficients[i];
	}

	Polynomial inputpoly(temparray, temp);

	poly = inputpoly;

	delete[] temparray;

	return input;
}
*/


istream& operator>>(istream& input, Polynomial& poly)
{
	cout << "Please enter a degree" << endl;
	int temp;
	input >> temp;

	//delete the current coifficent
	if (poly.coefficients)
	{
		delete[] poly.coefficients;
		poly.coefficients = nullptr;
	}

	poly.degree = temp;

	poly.coefficients = new double[poly.degree + 1];

	for (int i = 0; i <= poly.degree; i++) {
		cout << "Please enter the number for coificcent x^" << i << endl;
		input >> poly.coefficients[i];
	}
	return input;
}


ostream& operator<<(ostream& output, const Polynomial poly)
{
	for (int i = poly.degree; i >= 0; i--) {

		if (i == 0) {
			output << poly.coefficients[0] << endl;
		}
		else {
			output << poly.coefficients[i] << "x^" << i << " + ";
		}
	}
	return output;
}
