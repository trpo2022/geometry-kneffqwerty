#include "libgeo/lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float x_krug,y_krug,radiuss,x1_treugol,y1_treugol,x2_treugol,y2_treugol,x3_treugol,y3_treugol;
struct Point {
    float x, y;
};
void initInput(char array[32])
{
       scanf("%[^\n]", array);
}

int main()
{	printf("Vvedite po ocheride koordinati kruga i treugolnika v lubom poradke, ispolzuya grammatiku EBNF\n");
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
        radiuss=radius;
        x_krug=p.x;
        y_krug=p.y;
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
            return 0;
        }
        int xx,yy,xx1,yy1,xx2,yy2;
        xx=points[0].x;
        x1_treugol=xx;
        xx1=points[1].x;
        x2_treugol=xx1;
        xx2=points[2].x;
        x3_treugol=xx2;
        yy=points[0].y;
        y1_treugol=yy;
        yy1=points[1].y;
        y2_treugol=yy1;
        yy2=points[2].y;
        y3_treugol=yy2;
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
        return 0;
    }
    char* qqq = malloc(sizeof(char) * 32);
    fgets(qqq, 32, stdin);
	initInput(qqq);
    
   	char del[] = "( ,)";
    char* tok = strtok(qqq, del);
    if (strcmp(tok, "circle") == 0) 
	{
        struct Point p;
        p.x = atof(strtok(NULL, del));
        p.y = atof(strtok(NULL, del));
        float radius = atof(strtok(NULL, del));
        radiuss=radius;
        x_krug=p.x;
        y_krug=p.y;
        per_krug(p.x, p.y,radius);
        plosh_kruga(p.x, p.y,radius);
    } 
	else 
	if (strcmp(tok, "triangle") == 0) 
	{
        struct Point points[4];
        for (int i = 0; i < 4; i++) 
		{
            points[i].x = atof(strtok(NULL, del));
            points[i].y = atof(strtok(NULL, del));
            
        }
        if (points[3].x != points[0].x || points[3].y != points[0].y) 
		{
            printf("Oshibka obrabotki\n");
            return 0;
        }
        int xx,yy,xx1,yy1,xx2,yy2;
        xx=points[0].x;
        x1_treugol=xx;
        xx1=points[1].x;
        x2_treugol=xx1;
        xx2=points[2].x;
        x3_treugol=xx2;
        yy=points[0].y;
        y1_treugol=yy;
        yy1=points[1].y;
        y2_treugol=yy1;
        yy2=points[2].y;
        y3_treugol=yy2;
        per_treug(xx,yy,xx1,yy1,xx2,yy2);
        plosh_treug(xx,yy,xx1,yy1,xx2,yy2);
    } 
	else 
	if (strcmp(tok, "q") == 0) 
	{
        return 0;
    } 
	else 
	{
        printf("Nepravelniy vvod dannih.\n");
        return 0;
    }
    check(x_krug,y_krug,radiuss,x1_treugol,y1_treugol,x2_treugol,y2_treugol,x3_treugol,y3_treugol);
    
  return 0;
}