#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

double function(double x)	//input function
{
	return x / (1.2 - sin(2 * x));		
}

double random_float(double min, double max) //a function that returns random float with parameters from min to max 
{
	return (static_cast<double>(rand()) / RAND_MAX) * (max - min) + min;	
}

double find_min(double a, double b) //implementation of the random method of find miniumum
{
	const double acc = 0.000001;   //accuracy
	int i =0;
	double x1 = random_float(a, b);
	double x2 = random_float(a, b);	//picking two first interior points
	if (x2 < x1) { swap(x1, x2); }	//swaping point if second point is smaller than first one
	cout << "Initial x1: " << x1 << endl << "Initial x2: " << x2 << endl << endl;

	while ((b - a) > acc) //loop loops as long as distance is greater than accuracy
	{
		i++;
		if (function(x1) < function(x2))
		{
			b = x2;
			cout << "Moving B:  " << b << endl;
			x2 = random_float(a, b);	 //picking new random interior point
			if (x1 > x2) { swap(x1, x2); } //swaping point if is greater than second one
			cout << "x1  " << x1 << endl;
			cout << "x2  " << x2 << endl << endl;
		}
		else
		{
			a = x1;
			cout << "Moving A:  " << a << endl;
			x1 = random_float(a, b);		//picking new random interior point
			if (x1 > x2) { swap(x1, x2); } //swaping point if is greater than second one
			cout << "x1  " << x1 << endl;
			cout << "x2  " << x2 << endl << endl;
		}
	}
	//cout << "ilosc" << i;
	return (a + b) / 2; //returning the miniumum value of the function
	
}

int main() {
	srand(time(nullptr));  //seed for random function
	double a = -1;	 //interval
	double b = 1;
	cout<<"Minimal value " << function(find_min(a, b))<<" on x="<< find_min(a, b)<<endl;
	return 0;
}














