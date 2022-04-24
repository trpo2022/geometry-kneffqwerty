#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int plosh_kruga(float x_krug, float y_krug, float radius)
{
	float Pi,S;
	Pi=3.14;
	S=radius*radius*Pi;
	printf("\narea = %f",S);
	return S;
}