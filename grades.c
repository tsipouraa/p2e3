#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {

FILE *fp_students;
char studs[20];
int  temp;
double grd1, grd2, grd3, avg;
double avgMAX=0;

printf("Oi foitites me ton megalutero meso oro einai oi:\n");

fp_students = fopen("students.txt", "r");
       if(fp_students == NULL) {
        printf("Error \n");
        return 0;
    }
        while(1) {
        temp = fscanf(fp_students,"%s%lf%lf%lf", studs, &grd1, &grd2, &grd3);
        
		if(temp!=4) {
        break;
        }
        
		avg=(grd1+grd2+grd3)/3;

		if (avg>avgMAX)
        {
			avgMAX=avg;
	    }
	}
	    
	rewind(fp_students);
       
	   while(1)
	   { 
       temp = fscanf(fp_students,"%s%lf%lf%lf", studs, &grd1, &grd2, &grd3);
        
	    if(temp!=4) {
        break;
        }
        if((grd1+grd2+grd3)/3==avgMAX) {
        	printf("%s\n", studs);
		}
	}

fclose(fp_students);
return 0;
}

