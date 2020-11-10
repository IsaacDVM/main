#include <stdio.h>
int main(){
	int n, checkinput;
	double x;
	checkinput = scanf("%d %lf",&n,&x);
	if (checkinput < 2){
		printf("Error durante la toma de datos");
	}
	printf("%e %c\n",x/n);
	return 0;
}
