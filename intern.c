/*
 * intern.c
 * Zeynep Ferah Akkurt
 * Technical Questionnaire - SW Development Intern
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int N = 0;

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int isPrime(int n){
	int isprime = 0;
	// 0 and 1 are not prime numbers
	  if (n == 0 || n == 1)
		isprime = 1;

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      isprime = 1;
      break;
    }
  }
  
  return isprime;
	}

int maxPathSum(int tri[][N], int m, int n)
{
     // loop for bottom-up calculation
     for (int i=m-1; i>=0; i--)
     {
        for (int j=0; j<=i; j++)
        {
            if (tri[i+1][j] > tri[i+1][j+1] && !(isPrime(tri[i+1][j])))
                tri[i][j] += tri[i+1][j];
            else
                tri[i][j] += tri[i+1][j+1];
        }
     }
     return tri[0][0];
}

int countRow(char *fileName){
	FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Error: could not open file %s", fileName);
        exit(-1);
    }

	char ch;
    int ne = 1;
    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch == '\n'){
			ne++;
		}
	}
	fclose(fp);
	return ne;
}

int readTriange(char *fileName,int tri[N][N]){
	
	FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Error: could not open file %s", fileName);
        exit(-1);
    }
	const char s[1] = " ";
	int i = 0;
    int j = 0;
	char str[1000];
	while (fgets(str, 1000, fp)){
		char *token;
		/* get the first token */
		token = strtok(str, s);
		/* walk through other tokens */
	   while( token != NULL ) {
	      tri[i][j] = atoi(token);
	      j++;
		  token = strtok(NULL, s);
	   }
	   i++;
	   j = 0;
		
	}
        
    fclose(fp);
    return 1;
}
 
 
int main()
{

   N = countRow("input.txt");
   int tri[N][N];
   
   readTriange("input.txt",tri) ;
   printf("Path no is: \n%d",maxPathSum(tri, N-1, N-1));
   return 0;
}


