#include <math.h>
#include <stdio.h>
#define deltaT 0.001   //intervalo para Runge Kutta 
#define finalTime 14.0 // intsante final simulación
typedef struct{
	double x, y, z;
} vec;

typedef struct{
	const double mass; //masa de la partícula
	double t;		//instante en el que se encuentra la partícula
	vec r,v,a;   // pos y veloc de la partícula en un momento determinado y aceleración que experimenta en un instante determ
} particle;

//función para calcular una aceleración concreta dado un r,v,t y m quí se mete la expresión algebraica

vec showvaluea(vec r, vec v, double t){
	vec atoshow;
	float norm = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
	if (t < 6.0){
		
		atoshow.x = -r.x;
		atoshow.y = -r.y;
		atoshow.z = -r.z - 9.81;
	}
	else {
		atoshow.x = 0.0;
		atoshow.y = 0.0;
		atoshow.z = - 9.81;
	}
	return atoshow;
}

vec makevec (double value,int x,int y, int z){
	vec s;
	s.x = value * (float)x;
	s.y = value * (float)y;
	s.z = value * (float)z;
	return s;	
}

void newa(particle *p){
	vec k1r,k1v,k2r,k2v,k3r,k3v,k4r,k4v;
	k1v.x = p->a.x*deltaT;
	k1v.y = p->a.y*deltaT;
	k1v.z = p->a.z*deltaT;
	k1r.x = p->v.x*deltaT;
	k1r.y = p->v.y*deltaT;
	k1r.z = p->v.z*deltaT;
	k2v.x = showvaluea(makevec(p->r.x + k1r.x/2.0,1,0,0),makevec(p->v.x + k1v.x/2.0,1,0,0),p->t + deltaT/2.0).x*deltaT;
	k2v.y = showvaluea(makevec(p->r.y + k1r.y/2.0,0,1,0),makevec(p->v.y + k1v.y/2.0,0,1,0),p->t + deltaT/2.0).y*deltaT;	
	k2v.z = showvaluea(makevec(p->r.z + k1r.z/2.0,0,0,1),makevec(p->v.z + k1v.z/2.0,0,0,1),p->t + deltaT/2.0).z*deltaT;		
	k2r.x = (p->v.x + k1v.x/2.0)*deltaT;
	k2r.y = (p->v.y + k1v.y/2.0)*deltaT;
	k2r.z = (p->v.z + k1v.z/2.0)*deltaT;
	k3v.x = showvaluea(makevec(p->r.x + k2r.x/2.0,1,0,0),makevec(p->v.x + k2v.x/2.0,1,0,0),p->t + deltaT/2.0).x*deltaT;	
	k3v.y = showvaluea(makevec(p->r.y + k2r.y/2.0,0,1,0),makevec(p->v.y + k2v.y/2.0,0,1,0),p->t + deltaT/2.0).y*deltaT;	
	k3v.z = showvaluea(makevec(p->r.z + k2r.z/2.0,0,0,1),makevec(p->v.z + k2v.z/2.0,0,0,1),p->t + deltaT/2.0).z*deltaT;	
	k3r.x = (p->v.x + k2v.x/2.0)*deltaT;
	k3r.y = (p->v.y + k2v.y/2.0)*deltaT;
	k3r.z = (p->v.z + k2v.z/2.0)*deltaT;
	k4v.x = showvaluea(makevec(p->r.x + k3r.x,1,0,0),makevec(p->v.x + k3v.x,1,0,0),p->t + deltaT).x*deltaT;
	k4v.y = showvaluea(makevec(p->r.y + k3r.y,0,1,0),makevec(p->v.y + k3v.y,0,1,0),p->t + deltaT).y*deltaT;
	k4v.z = showvaluea(makevec(p->r.z + k3r.z,0,0,1),makevec(p->v.z + k3v.z,0,0,1),p->t + deltaT).z*deltaT;
	k4r.x = (p->v.x + k3v.x)*deltaT;
	k4r.y = (p->v.y + k3v.y)*deltaT;
	k4r.z = (p->v.z + k3v.z)*deltaT;
	p->r.x = p->r.x + (k1r.x+2.0*k2r.x+2.0*k3r.x+k4r.x)/6.0;
	p->v.x = p->v.x + (k1v.x+2.0*k2v.x+2.0*k3v.x+k4v.x)/6.0;
	p->r.y = p->r.y+ (k1r.y+2.0*k2r.y+2.0*k3r.y+k4r.y)/6.0;
	p->v.y = p->v.y + (k1v.y+2.0*k2v.y+2.0*k3v.y+k4v.y)/6.0;
	p->r.z = p->r.z + (k1r.z+2.0*k2r.z+2.0*k3r.z+k4r.z)/6.0;
	p->v.z = p->v.z + (k1v.z+2.0*k2v.z+2.0*k3v.z+k4v.z)/6.0;
}

particle p = {
	2.5,
	0.0,
	{0.0,7.0,0.0},
	{0.0,12.0,6.0},
	{0.0,0.0,0.0}
};
	
int main(){
	FILE *fp = NULL;
	fp = fopen("data.dat","w");
	p.a = showvaluea(p.r,p.v,p.t);
	int inout = 1;
	while (inout == 1){
		if (p.t > finalTime){
			inout = 0;
		}
		fprintf(fp,"%10.2e %10.2e %10.2e %10.2e %10.2e %10.2e %10.2e\n",p.t,p.r.x,p.r.y,p.r.z,p.v.x,p.v.y,p.v.z);
		p.t += deltaT;
		newa(&p);	
	}
	fclose(fp);
	return 0;	
}		
	
	
	
	
	
	
