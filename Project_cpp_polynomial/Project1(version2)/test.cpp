#pragma once
#include "Cubic.h"
#include "Polynomial.h"
#include <iostream>


//Callum Simpson -- b6030326

int main() {

	Cubic c3;

	//1, 2, 3, 4
	double val[4] = { 1,2,3,4 };
	double val2[4] = { 5,6,7,8 };

	Cubic c1(val);
	Cubic c2(val2);

	Cubic c4(c1);

	cout << "Test of the Cubic istream overload" << endl;
	cin >> c3;
	cout << "The cubic that you have created:" << c3 << endl;


	cout << endl << "First Cubic c1 : " << c1 << endl;
	cout << "Second Cubic c2 : " << c2 << endl;

	cout << endl << "Test of the copy constructor c4(c1) : " << c4 << endl;


	cout << endl << "Test of the Cubic get methods using c1"<< endl;
	cout << "getX3() - Expect 4 actually got " << c1.getX3() << endl;
	cout << "getX2() - Expect 3 actually got " << c1.getX2() << endl;
	cout << "getX1() - Expect 2 actually got " << c1.getX1() << endl;
	cout << "getX0() - Expect 1 actually got " << c1.getConstant() << endl;

	cout << endl << "Test of the Cubic compute cubic based on x : c1.computeCubic(2)" << endl;
	cout << c1.computeCubic(2) << endl;

	cout << endl << "Print out C1 " << c1 << endl;

	cout << endl << "Print out C2 " << c2 << endl;

	cout << endl << "A Test for overloading +" << endl;
	cout << "c1 + c2  = " << c1 + c2 << endl;
	cout << "c1.operator+(c2) = " <<  c1.operator+(c2) << endl;

	cout << endl << "A Test for overloading -" << endl;
	cout << "c1 - c2  = " << c1 - c2 << endl;
	cout << "c1.operator-(c2) = " << c1.operator-(c2) << endl;


	cout << endl << "A test for timesing a cubic by a int " << c1 * 5 << endl;
	cout << "A test for timesing a cubic by a double " << c1 * 4.5 << endl;

	cout << endl << "A test for overloading == : c1 == c2 should return false " << c1.operator==(c2) << endl;
	cout << "A test for overloading == : c1 == c4 should return true "  << c1.operator==(c4) << endl;
	cout << "A test for overloading == : c1 =! c2 should return true " << c1.operator!=(c2) << endl;

	Cubic c8(c1);
	Cubic c6(c1);
	Cubic c7(c1);

	cout << endl << " c6 and c7 are copies of c1 " << endl;
	cout << "A test for overloading += : c6.operator+=(c2)" << endl;
	cout << "Test 1 : " << c6.operator+=(c2) << endl;
	cout << "Test 2 : " << c6.operator+=(c2) << endl;
	cout << "Test 3 : " << c6.operator+=(c2) << endl;

	cout << "A test for overloading -= : c7.operator-=(c2)" << endl;
	cout << "Test 1 : " << c7.operator-=(c2) << endl;
	cout << "Test 2 : " << c7.operator-=(c2) << endl;
	cout << "Test 3 : " << c7.operator-=(c2) << endl;

	cout << endl << "-----------------------------------------------------------------------------------" << endl;

	cout << endl << "These are the tests for the Polynomial class" << c1.operator==(c2) << endl;

	//in my code the array value equals x degree
	double val3[3] = { 1,2,3};
	double val4[5] = { 4,5,6,7,8};

	Polynomial p1(val3,2);
	Polynomial p2(val4,4);

	Polynomial ptest = p2;

	cout << endl << "A test of the input overload in the Polynomial class" << endl;

	Polynomial p3;

	cin >> p3;

	cout << "Heres is the polynomial that you have created:"  << endl << p3 << endl;

	Polynomial p4(p1);
	Polynomial p5(p1);
	Polynomial p6(p1);
	Polynomial p7(p1);
	Polynomial p8(p1);

	cout << " I have created 2 extra First Polynomial" << endl;
	cout << "First Polynomial : " << p1 << endl;
	cout << "Second Polynomial : " << p2 << endl;

	cout << "A test of a copy function : p4(p1)"<< endl;
	cout << "P4 Polynomial :" << p4 << endl;

	cout << "Heres is a test of overload= : ptest = p2 :  " << endl << ptest << endl;

	cout << "A test of getDegree on p1 : "<< p1.getDegree() << endl;

	cout << "A test of getCoefficient on p1 : degree 1 should be 2 :" << p1.getCoefficient(1) << endl;
	cout << "A test of getCoefficient on p1 : degree 2 should be 3 :" << p1.getCoefficient(2) << endl;
	cout << "A test of getCoefficient on p1 : degree 5 should be 0 : " << p1.getCoefficient(5) << endl;

	cout << endl << "Test of Compute Polynomial based on x : p1.computePolynomial(2)" << endl;
	cout << p1.computePolynomial(2) << endl;

	cout << endl << "Test of Compute Polynomial based on x : p2.computePolynomial(3)" << endl;
	cout << p2.computePolynomial(3) << endl;

	cout << endl << "Test of p2 + p1 : " << p2 + p1 << endl;
	cout << "Test of p2.operator+(p1) : " << p2.operator+(p1) << endl;

	cout << endl << "Test of -" << endl;
	cout << "Test of p2.operator-(p1) : " << p2.operator-(p1) << endl;
	cout << "Test of p1.operator-(p2) : " << p1.operator-(p2) << endl;

	cout << endl << "A test for timesing a cubic by a int p4.operator*(5) " << endl;
	cout << p4.operator*(5) << endl;

	cout << "A test for timesing a poly by a double p5.operator*(2.5) " << endl;
	cout << p5.operator*(2.5) << endl;

	cout << "A test for timesing a poly by a poly  p1.operator*(p2) " << endl;
	cout << p1.operator*(p2) << endl;

	cout << endl << "A test for overloading == : p1 == p2 should return false " << p1.operator==(p2) << endl;
	cout << "A test for overloading == : p1 == p6 (p6 made by p6(p1)) should return true " << p1.operator==(p6) << endl;
	cout << "A test for overloading == : p1 =! p2 should return true " << p1.operator!=(p2) << endl;
	cout << "A test for overloading == : p1 =! p6 should return false " << p1.operator!=(p6) << endl;


	cout << endl << " p6 , p7 and p8 are copies of p1 " << endl;
	cout << "A test for overloading += : p6.operator+=(p2)" << endl;
	cout << "Test 1 : " << p6.operator+=(p2) << endl;
	cout << "Test 2 : " << p6.operator+=(p2) << endl;
	cout << "Test 3 : " << p6.operator+=(p2) << endl;

	cout << "A test for overloading -= : p7.operator-=(p2)" << endl;
	cout << "Test 1 : " << p7.operator-=(p2) << endl;
	cout << "Test 2 : " << p7.operator-=(p2) << endl;
	cout << "Test 3 : " << p7.operator-=(p2) << endl;

	cout << "A test for overloading *= : p8.operator+=(p2)" << endl;
	cout << "Test 1 : " << p8.operator*=(p2) << endl;
	cout << "Test 2 : " << p8.operator*=(p2) << endl;
	cout << "Test 3 : " << p8.operator*=(p2) << endl;

	//cin << 

	return 0;
}