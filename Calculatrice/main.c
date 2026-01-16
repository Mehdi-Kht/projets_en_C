#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Programme simple de calculatrice en ligne de commande.
 * Usage : ./programme nombre1 opérateur nombre2
 * Exemple : ./programme 5 + 3
 * 
 * Effectue l'opération arithmétique (+, -, *, /) entre deux nombres entiers.
 * Affiche le résultat ou un message d'erreur si les arguments sont incorrects.
 */

int main(int argc, char* argv[])
{
	if(argc != 4 && argc != 2){
		printf("error: Exactly one or tree arguments must be provided\n");
		return 1;
	}
	char op;
	int r=0,n1=0,n2=0;

	if (argc == 4)
	{
		op = argv[2][0];
			
		n1 = atoi(argv[1]);
		n2 = atoi(argv[3]);
		r = 0;
	}else {
		char *expr = argv[1];
		int i=0;
		int len = strlen(expr);

		while(i < len && (isdigit(expr[i]) || expr[i] == '-')) i++;

		if (i == 0 || i == len)
		{
			printf("Error: Invalid expression format\n");
			return 1;
		}
		char num1[20], num2[20];
		strncpy(num1, expr,i);
		num1[i] = '\0';
		op = expr[i];
		strcpy(num2, expr + i+1);

		n1 =atoi(num1);
		n2 = atoi(num2);
	}


	switch (op)
		{
			case '+':
				r = n1+n2;
				break;
			case '-':
				r = n1-n2;
				break;
			case '/':
				r= n1/n2;
				break;
			case '*':
				r = n1*n2;
				break;
			default:
				printf("Error: Unknown operator '%c' \n", op);
				return 1;
		}

	printf(" %d %c %d = %d\n", n1,op,n2,r);
	return 0;


}