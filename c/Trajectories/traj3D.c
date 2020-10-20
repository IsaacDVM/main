#include <stdio.h>
#include <math.h>
/*PRECISION define cómo de grande es el array y por lo tanto la cantidad de puntos a represenar*/


int main(){
	unsigned long PRECISION = 10000;
	FILE *fp = NULL;
	fp = fopen("traj3D.txt","w");
	double lim_tinf, lim_tsup, ancho;
	int i;
	printf("Introduce el tiempo inicial y final, como decimales, separados por un espacio: \n");
	scanf("%lf %lf", &lim_tinf, &lim_tsup);
	ancho = (lim_tsup - lim_tinf)/(float)PRECISION;
	/*ahora creamos los arrays*/
	double x[PRECISION],y[PRECISION],t[PRECISION],z[PRECISION];
	for (i = 0; i <= PRECISION; i++){
		t[i]=lim_tinf+(float)i*ancho;
		/*este es el punto en el que debes integrar la trayectoria*/
		x[i]=0.5*cos(0.022*t[i]);
		y[i]=0.5*sin(0.022*t[i]);
		z[i]=0.1*t[i];
		fprintf(fp,"%lf %lf %lf %lf\n",t[i],x[i],y[i],z[i]);
		/*este es el punto en el que debes integrar la función*/
	}
	printf("Este es el segundo valor de x %f",x[1]);
	printf("Este es el segundo valor de y %f",y[1]);
	fclose(fp);
    return 0;	
}
