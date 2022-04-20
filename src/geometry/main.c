#include "libgeo/lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    float x, y;
};

void initInput(char array[32])
{
   	scanf("%[^\n]", array);
}

int main()
{
  char* input = malloc(sizeof(char) * 32);
    initInput(input);
    char delims[] = "( ,)";
    char* token = strtok(input, delims);
    if (strcmp(token, "circle") == 0) 
	{
        struct Point p;
        p.x = atof(strtok(NULL, delims));
        p.y = atof(strtok(NULL, delims));
        float radius = atof(strtok(NULL, delims));
        per_krug(p.x, p.y,radius);
        plosh_kruga(p.x, p.y,radius);
    } 
	else 
	if (strcmp(token, "triangle") == 0) 
	{
        struct Point points[4];
        for (int i = 0; i < 4; i++) 
		{
            points[i].x = atof(strtok(NULL, delims));
            points[i].y = atof(strtok(NULL, delims));
            
        }
        if (points[3].x != points[0].x || points[3].y != points[0].y) 
		{
            printf("Oshibka obrabotki\n");
        }
        int xx,yy,xx1,yy1,xx2,yy2;
        xx=points[0].x;
        xx1=points[1].x;
        xx2=points[2].x;
        yy=points[0].y;
        yy1=points[1].y;
        yy2=points[2].y;
        per_treug(xx,yy,xx1,yy1,xx2,yy2);
        plosh_treug(xx,yy,xx1,yy1,xx2,yy2);
    } 
	else 
	if (strcmp(token, "q") == 0) 
	{
        return 0;
    } 
	else 
	{
        printf("Nepravelniy vvod dannih.\n");
    }
    free(input);
  return 0;
}
