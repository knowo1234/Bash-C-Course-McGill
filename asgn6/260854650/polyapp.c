#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"utils.h"
#include"poly.h"

/*
 * the purpose of this code is to create simple polynomial expression from
 * certain predetermined values
 ***********************************************************
 * Author       Dept            Date            Notes
 ***********************************************************
 * Kuba N       Management      Arpil 3, 2020     Initial version
*/

int main(int argc, char* argv[]){
	//are we supposed to have a main
	if(argc != 2){
		fprintf(stderr,"Error: pass right amount of arguments");
		return 1;
	}
	//if you are here then the right amount of arguments were passeed in
	//open file and then go through it
	FILE *file = fopen(argv[1],"rt");
	//display the contents of the first line
	if(file){
		char str[1000];
		int *base, *exponent;
		int initB, initE;
		initB = 0;
		initE = 0;
		base = &initB;
		exponent = &initE;
		//go throught the file and make polyterms
		while(fgets(str,sizeof(file),file) != NULL){
			 //store the line from the file in *line
			parse(str,base,exponent);	
//			printf("\n%d, %s\n",base,exponent);
			addPolyTerm(*base,*exponent);
		}
	
		//close the file
//		printf("i am about to close the file\n");
			
		displayPolynomial();

		printf("for x=-2, y=%d\n",evaluatePolynomial(-2));
		printf("for x=-1, y=%d\n",evaluatePolynomial(-1));
		printf("for x=0, y=%d\n",evaluatePolynomial(0));
		printf("for x=1, y=%d\n",evaluatePolynomial(1));
		printf("for x=2, y=%d\n",evaluatePolynomial(2));
	
		fclose(file); //close the file

	}
}


