#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Point {
    float x, y;
};

void initInput(char array[32])
{
   	scanf("%[^\n]", array);
}

void CircleInfo(float x, float y, float radius)
{
    printf("\tcenter = (%.3f %.3f)\n\tradius = %.3f\n",x,y,radius);
}

int main()
{
    char* input = malloc(sizeof(char) * 32);
    initInput(input);
    char delims[] = "( ,)";
    char* token = strtok(input, delims);
    if (strcmp(token, "circle") == 0) 
    {
        printf("\n%s:\n", token);
        struct Point p;

        p.x = atof(strtok(NULL, delims));
        p.y = atof(strtok(NULL, delims));
        float radius = atof(strtok(NULL, delims));
       
        CircleInfo(p.x, p.y,radius);

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