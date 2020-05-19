#include <stdlib.h>
#include <stdio.h>

float deposit(float fBalance){
	float fAdd;
	
	printf("How much do you want to deposit?\n");
	scanf("%f", &fAdd);
	
	if (fAdd<0){
		printf("Invalid Deposit Input");
		return 0;
	}
	else {
		printf("Your Balance with deposit is Now %f", fBalance + fAdd );
		return fBalance + fAdd;
	}			
	
}

float withdraw(float fBalance){
	float fSub;
	
	printf("How much do you want to withdraw?\n");
	scanf("%f", &fSub);
	
	if (fSub<0){
		printf("Invalid Withdraw Input");
		return 0;
	}
	else if (fSub > fBalance){
		printf("Invalid Withdraw Input");
		return 0;
	}
	else {
		printf("Your current Balance is Now %f", fBalance - fSub);
		return fBalance - fSub;
	}
			
}

float transaction (float fBalance){
	int iChoice;
	char cTransact;
	
	printf("\nWould you like to have another transaction? y or n\n");
	fflush(stdin);
	scanf("%c", &cTransact);
	
	if (cTransact == 'n' ){
		printf("Thank you, Come again.");
		return 0;
		} 

	printf("\nWhat would you like to do?\n 1 for Deposit\n 2 for Withdraw\n 3 for Check balance\n");
	scanf("%i", &iChoice);
			
	do{
		switch (iChoice){
		case 1://deposit//
			fBalance =  deposit(fBalance);
			transaction(fBalance);
			break;
		case 2://withdraw//
			fBalance = withdraw(fBalance);
			transaction(fBalance);
			break;
		case 3://check//
			printf("Your current Balance is %f", fBalance);
			transaction(fBalance);
			break;	
		default:
			printf("Invalid");
			transaction(fBalance);
		}
	}
	while (cTransact == 'y');	
	
}
	

int main (){
	
	float fBalance = 10000;
	int iChoice;
	
	printf("\nWhat would you like to do?\n 1 for Deposit\n 2 for Withdraw\n 3 for Check balance\n 4 for Exit\n");
	scanf("%i", &iChoice);
	
	switch (iChoice){
		case 1://deposit//
			fBalance =  deposit(fBalance);
			break;
		case 2://withdraw//
			fBalance = withdraw(fBalance);
			break;
		case 3://check//
			printf("Your current Balance is %f", fBalance);
			break;
		case 4:
			printf("Thank you for using Us");
			return 0;
			break;
		default:
			printf("Invalid Input");
			break;
	}

	transaction(fBalance);		
	return 0;

}
