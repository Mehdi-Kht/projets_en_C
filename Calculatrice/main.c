#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc != 4){
		printf("error: Exactly tree arguments must be provided\n");
		return 1;
	}

	char op = argv[2][0];
	
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[3]);
	int r = 0;

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
				printf("Default case ");
		}

	printf(" %d %c %d = %d\n", n1,op,n2,r);
	return 0;


}