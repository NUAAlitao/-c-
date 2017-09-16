#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n - i; j++){
			printf(" ");
		}
		for (int k = 1; k <= i; k++){
			printf("*");
		}
		printf("\n");
	}
	system("pause");
}