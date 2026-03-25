#include <stdio.h>

float foo (double a, float b);

int main() {
	double a = 2.5;
	float b = 3.5;
	printf("%f\n", foo(a,b));
	return 0;
}