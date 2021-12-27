#include<stdio.h>
#include<string.h>

/*
 * the purpose of this code is to implement the caesar cipher
 ***********************************************************
 * Author       Dept            Date            Notes
 ***********************************************************
 * Kuba N       Management      Feb 14 2020     Initial version
 * Kuba N	Management 	Feb 20 2020	Final touches
*/


int main(int argc, char* argv[]){

if(argc != 4){						//check if the user input correct amount of arguments
printf("Error: usage is simplecalc <x> <op> <y>\n");
return 1;
}
int x, y;		//initiate integer variables
char op;		//initiate character variables


sscanf (argv[1],"%d",&x);		//assign and type the variables 
sscanf (argv[2],"%c",&op);
sscanf (argv[3],"%d",&y);
switch(op)				//start switch statement which will check if the op is =.-.*./
{
	case '+':
		printf("%d\n",(x+y));
		return 0;
		break;
	case '-':
		printf("%d\n",(x-y));
		return 0;
		break;
	case '*':
		printf("%d\n",(x*y));
		return 0;
		break;
	case '/':
		printf("%d\n",(x/y));
		return 0;
		break;
	default:					//if it is not the correct op return an error msg
		printf("%c not a valid operator\n",op);		
		return 2;
}

}
