#include<stdio.h>
#include<string.h>

/*
 * the purpose of this code is to implement the caesar cipher
 ***********************************************************
 * Author       Dept            Date            Notes
 ***********************************************************
 * Kuba N       Management      Feb 20 2020     Initial version
*/


int main(int argc, char* argv[]){
	

	//check if proper amount of arguments have been passed
	if( argc != 2 ){					//assuming that even if a character is passed it wil
								//be interpreted as an int since chars are ints
	printf("Error: usage is caesarcipher <offset>\n");
	return 1;
	}	
 	
	char msg[1000];	
	//get user input
	
	char cipherMsg[1000];		//make a place to store the rotated string
	int i;
	sscanf (argv[1],"%d",&i);	//initiate amount that we will cipher by
	int j;
	int test;
	
	while(fgets(msg, sizeof(msg), stdin)){
		test = strlen(msg);
		if(msg[0] != '\n'){		
	//initiate the counter that will go through the msg
	for(j = 0; j<test; j++){		//loop through the msg
		if((msg[j]>='a') && (msg[j]<='z')){
			if(i<0){
				cipherMsg[j] = (((msg[j]-97)+(26+i))%26+97);
			}
			else{
				cipherMsg[j] = (((msg[j]-97)+i)%26+97);
			}
		}
		else{
			cipherMsg[j] = msg[j];
		}
		printf("%c",cipherMsg[j]);
	}
//      int msgLength = strlen(msg);

//      printf("%.*s\n",msgLength-1,cipherMsg);
	
		}

}
}
