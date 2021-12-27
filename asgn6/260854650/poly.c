#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"utils.h"
/*
 * the purpose of this code is to create simple polynomial expression from
 * certain predetermined values
 ***********************************************************
 * Author       Dept            Date            Notes
 ***********************************************************
 * Kuba N       Management      Arpil 3, 2020     Initial version
 * Kuba N	Management	April 5, 2020	  Adding all functions
*/


struct PolyTerm{
	int coeff;	//initalize attributes
	int expo;
	struct PolyTerm *next;
};

struct PolyTerm *head = NULL;	//global head pointer


//add polyterm into linked list
int addPolyTerm(int c, int e){
//	printf("i am in addpolyTerm\n");

	struct PolyTerm *term, *tempTerm, *before;	//declare PolyTerm objects for later use
	term = (struct PolyTerm*)malloc(sizeof(struct PolyTerm));	//create the first erm
	if(term == NULL){
		return -1;
	}
	term->coeff =c;
	term->expo =e;
	term->next = NULL;

	//if the head has not been created
	if(head == NULL){
		head = term;
	}
	//if the new term is less than the head
	else if(term->expo < head->expo){
		term->next = head;
		head = term;
	}
	//if it is greater or equal
	else{
		before=head;
		tempTerm=head->next;

		while(tempTerm!=NULL && term->expo > tempTerm->expo){
			before=tempTerm;
			tempTerm=tempTerm->next;

		}
		if(tempTerm == NULL){
			before->next=term;
		}
		else{
			term->next=tempTerm;
			before->next=term;
		}
	}
	return 0;
}	


//display the polynomial
void displayPolynomial(){

	struct PolyTerm *temp, *next;
	int counter = 0;
	temp = head;
	//loop through the linked list and print contents while next != NULL
	while(temp != NULL){
		if(temp->next == NULL){}

		else if(temp->expo == temp->next->expo){
			temp->coeff = temp->coeff+temp->next->coeff;
			next=temp->next->next;
			free(temp->next);
			temp->next=next;
		}
		//if it is the first element
		if(counter==0){
			printf("%dx%d",temp->coeff,temp->expo);
		}
		else{
			printf("%+dx%d",temp->coeff,temp->expo);
		}
		temp=temp->next;
		counter++;
	}
	printf("\n");
}

//accepts a value for x and evaluates the polynomial at that value
int evaluatePolynomial(int x){
//	printf("we are in evaluate poly\n");
	int result = 0;
	struct PolyTerm *temp;
	temp = head;
	int interm = 0;
	int valB;
	while(temp != NULL){
		valB = temp->coeff;
		interm = powi(x,temp->expo);
		result = result + (valB*interm);
		temp = temp->next;
	}
	
	return result;
}










