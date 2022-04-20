#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int per_krug(float x_krug, float y_krug, float radius)
{
	float p,Pi;
	Pi=3.14;
	p=2*radius*Pi;
	printf("\nperimetr = %f",p);
	return p;
}