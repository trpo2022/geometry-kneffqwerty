#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>

int check(float x_krug, float y_krug, float radius, float x1_treugol, float y1_treugol, float x2_treugol, float y2_treugol, float x3_treugol, float y3_treugol)
{
    float qsqrt_one, qsqrt_two, qsqrt_three;
    qsqrt_one = sqrt((x_krug - x1_treugol) * (x_krug - x1_treugol) + (y_krug - y1_treugol) * (y_krug - y1_treugol));
    qsqrt_two = sqrt((x_krug - x2_treugol) * (x_krug - x2_treugol) + (y_krug - y2_treugol) * (y_krug - y2_treugol));
    qsqrt_three = sqrt((x_krug - x3_treugol) * (x_krug - x3_treugol) + (y_krug - y3_treugol) * (y_krug - y3_treugol));
    if (((qsqrt_one > radius) && (qsqrt_two > radius) && (qsqrt_three > radius)) || ((qsqrt_one < radius) && (qsqrt_two < radius) && (qsqrt_three < radius))) 
    {
            printf("\nNe peresikayutsa\n");
            return 0;
    } 
    else 
    {
            printf("\nPeresikayutsa\n");
            return 1;
    }
}
