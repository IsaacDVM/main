#include <stdio.h>
#include <math.h>

// Physical constants.

const double bigG = 6.6726E-11; // Nm^2/kg^2

// Useful typedefs, i.e., our own data types for the problem at hand.

// A 3-D vector.

typedef struct {
    double x, y, z;
} vector;

// All the information that we need to know about a test particle.

typedef struct {
  double mass;      // The mass of the particle, in kg.
  double epoch;     // The time in seconds at which the following 
                    //     two items are specified.
  vector pos;       // The particle's position.
  vector vel;       // The particle's velocity.
  vector force;     // The force acting on the particle.
  double potential; // The gravitational potential that the particle is in.
  double ke;        // The particle's kinetic energy.
  double pe;        // The particle's potential energy.
  vector I;         // The particle's angular momentum.
} particle;

// Now we define some functions that we will need.

void gravity(particle *p1, particle *p2) {

    // Calculates the force and potential acting on particle p1 due to 
    // particle p2.

    double forceMagnitude;
    double distance;
    vector d;

    // Calculate the position offset between the two particles.

    d.x = p1->pos.x - p2->pos.x;
    d.y = p1->pos.y - p2->pos.y;
    d.z = p1->pos.z - p2->pos.z;

    // The magnitude of the position offset vector is the distance between
    // the particles.

    distance = sqrt(d.x*d.x + d.y*d.y + d.z*d.z);

    // Now calculate the magnitude of the force acting on p1 due to p2.

    forceMagnitude = bigG * p1->mass * p2->mass / (distance * distance);

    // And orient it correctly in 3 dimensions by multiplying by a unit
    // vector from p2 to p1.

    p1->force.x = - forceMagnitude * d.x / distance;
    p1->force.y = - forceMagnitude * d.y / distance;
    p1->force.z = - forceMagnitude * d.z / distance;

    // Finally, calculate the potential at p1 due to p2.

    p1->potential = - bigG * p2->mass / distance;
}

void update(particle *p, double deltaT) {

    // Updates the properties of particle p after a time interval
    // deltaT [seconds].

    vector acc;

    // Calculate the acceleration due to the force acting on the particle.
   
    acc.x = p->force.x / p->mass;
    acc.y = p->force.y / p->mass;
    acc.z = p->force.z / p->mass;

    // Update the position vector, assuming a constant acceleration
    // over the time interval.

    p->pos.x += (p->vel.x + 0.5 * acc.x * deltaT) * deltaT;
    p->pos.y += (p->vel.y + 0.5 * acc.y * deltaT) * deltaT;
    p->pos.z += (p->vel.z + 0.5 * acc.z * deltaT) * deltaT;

    // Update the velocity vector.

    p->vel.x += acc.x * deltaT;
    p->vel.y += acc.y * deltaT;
    p->vel.z += acc.z * deltaT;

    // Update the epoch.

    p->epoch += deltaT;

    // Update the kinetic energy.

    p->ke = 0.5 * p->mass * (p->vel.x * p->vel.x +
			     p->vel.y * p->vel.y +
			     p->vel.z * p->vel.z);

    // Update the potential energy.

    p->pe = p->mass * p->potential;

    // Update the angular momentum.

    p->I.x = p->mass * (p->pos.y * p->vel.z - p->pos.z * p->vel.y);
    p->I.y = p->mass * (p->pos.z * p->vel.x - p->pos.x * p->vel.z);
    p->I.z = p->mass * (p->pos.x * p->vel.y - p->pos.y * p->vel.x);
}

// Here are two representative particles:

particle sun =   {1.989E30,              // Mass in kg
		  0.0, 
		  {0.0, 0.0, 0.0},       // The initial position
		  {0.0, 0.0, 0.0}};      // The initial velocity

particle earth = {5.976E24,              // Mass in kg
		  0.0, 
		  {149.6E9, 0.0, 0.0},   // The initial position 
		  {0.0, 12000.0, 0.0}}; // The initial velocity 27.786E3,

const double deltaT = 1800.0; // The time interval in seconds

int main (void) {
	FILE *fp = NULL;
	fp = fopen("gravity.txt","w");
	fprintf(fp,"x (10.2e,10.2e,10.2e) v (10.2e,10.2e,10.2e) E (%10.2e =%10.2e +%10.2e) I (%10.2e,%10.2e, %10.2e) \n");
    double time;
    // Choose the position of the Sun to put the centre of mass at (0,0,0).
    sun.pos.x = - earth.pos.x * earth.mass/sun.mass;
    sun.pos.y = - earth.pos.y * earth.mass/sun.mass;
    sun.pos.z = - earth.pos.z * earth.mass/sun.mass;
    // Choose the velocity of the Sun to keep the centre of mass
    // at a constant position.
    sun.vel.x = 0.0;
    sun.vel.y = earth.vel.y * sun.pos.x / earth.pos.x;
    sun.vel.z = 0.0;
    // Now follow the motion for one year...

    for (time = 0.0; time < 365.2422 * 24 * 3600; time += deltaT) {
        gravity(&sun, &earth);
        gravity(&earth, &sun);

		update(&sun,   deltaT);
		update(&earth, deltaT);

	//		displayParticle(&sun);
	//      printf("\n");
		#if 0
			fprintf(fp,"x (%10.2e,%10.2e,%10.2e); v (%10.2e,%10.2e,%10.2e)",sun.pos.x, sun.pos.y, sun.pos.z, sun.vel.x, sun.vel.y, sun.vel.z); 
			fprintf(fp," E (%10.2e =%10.2e +%10.2e)", sun.ke + sun.pe, sun.ke, sun.pe);
			fprintf(fp," I (%10.2e,%10.2e, %10.2e)", sun.I.x, sun.I.y, sun.I.z);
			vector cm;
			cm.x = (earth.mass * earth.pos.x  + sun.mass * sun.pos.x)/(earth.mass + sun.mass);
			cm.y = (earth.mass * earth.pos.y  + sun.mass * sun.pos.y)/(earth.mass + sun.mass);
			cm.z = (earth.mass * earth.pos.z  + sun.mass * sun.pos.z)/(earth.mass + sun.mass);
			fprintf(fp," cm (%10.2e,%10.2e, %10.2e)", cm.x, cm.y, cm.z);
			fprintf(fp,"\n");
		#endif
			fprintf(fp,"%10.2e ",time);
			fprintf(fp,"%10.2e %10.2e %10.2e %10.2e %10.2e %10.2e",earth.pos.x, earth.pos.y, earth.pos.z, earth.vel.x, earth.vel.y, earth.vel.z);
			fprintf(fp,"%10.2e %10.2e %10.2e %10.2e %10.2e %10.2e",sun.pos.x, sun.pos.y, sun.pos.z, sun.vel.x, sun.vel.y, sun.vel.z); 
			fprintf(fp," %10.2e %10.2e %10.2e", earth.ke + earth.pe, earth.ke, earth.pe);
			fprintf(fp," %10.2e %10.2e %10.2e", earth.I.x, earth.I.y, earth.I.z);
			fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;
}
