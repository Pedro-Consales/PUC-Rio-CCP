#include <stdio.h>
#include <math.h>

float foo1 (float a, float b);

int main() {
	float a = 3.14159265358979323846f/2.0f;
	float b = 3.5;
	printf("%f\n", foo1(a,b));
	return 0;
}