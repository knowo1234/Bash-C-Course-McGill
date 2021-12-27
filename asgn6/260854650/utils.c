#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * the purpose of this code is to create simple polynomial expression from
 * certain predetermined values
 ***********************************************************
 * Author       Dept            Date            Notes
 ***********************************************************
 * Kuba N       Management      Arpil 3, 2020     Initial version
 * Kuba N	Management	April 5, 2020	  Correcting bugs after compiling
*/

//code that parses the line
void parse(char *s,int *base,int *exponent){
	sscanf(s,"%d %d",base,exponent);
}

//code that raises a number to a power
int powi(int x,int exponent){
	int result = 1;
	while(exponent != 0) {
		result *= x;
		--exponent;
	}
	return (result);	
}
