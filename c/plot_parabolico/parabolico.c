#include <math.h>
#include <stdio.h>

//defino la grav del planeta
const double g = -9.81;

typedef struct{
	double x, y, z;
} vec;

typedef struct{
	vec pos;
	vec speed;
} particle;

particle pelota = {
	{0.0,0.0,10.0},
	{10.0,10.0,70.0},
};

int main(){
	FILE *fp = NULL;
	fp = fopen("parabolico.dat","w");
	double deltaT = 0.08, t = 0.0;
	int inout = 1;
	while (inout == 1){
		if (pelota.pos.z < 0.0){
			inout = 0;
		}
		fprintf(fp,"%10.2e %10.2e %10.2e %10.2e %10.2e %10.2e %10.2e\n",t,pelota.pos.x,pelota.pos.y,pelota.pos.z,pelota.speed.x,pelota.speed.y,pelota.speed.z);
		t += deltaT;
		pelota.pos.x += pelota.speed.x * deltaT;
		pelota.pos.y += pelota.speed.y * deltaT;
		pelota.pos.z += (pelota.speed.z + 0.5 * g * deltaT) * deltaT;
		pelota.speed.z += g * deltaT;
		
		
	}
	fclose(fp);
	return 0;
}
