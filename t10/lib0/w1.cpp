#include "stdafx.h"
#include "w1.h"
int factorial(int n) {
	if (n ==0)
		return 1;
	return n*factorial(n-1);

}
float FAC::convert(int a) {
	float d = (1.0*a/180)*3.1415926;
	return d;
}