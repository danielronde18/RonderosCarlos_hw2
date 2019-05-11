#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

double dt = 0.01;
double g = 0.0;
double k = 2000.0;
double m = 1000.0;

double eq1( double );
double eq2( double );
double eq3( double );
double eq4( double, double, double, double, double );
double eq5( double, double, double, double );
double eq6( double, double, double );
void resolver( double, double, double&, double&, double&, double&, double&, double& );
void condiciones_iniciales( double&, double&, double&, double&, double&, double& );

int main(){
    
	double w = sqrt(k/m);
	double u1, u2, u3, v1, v2, v3;
	condiciones_iniciales( u1, u2, u3, v1, v2, v3);
    
    
    
    
 return 0;   
}

void condiciones_iniciales(double& u1, double& u2, double& u3, double& v1, double& v2, double& v3){
	u1 = 0.0;
	u2 = 0.0;
	u3 = 0.0;
	v1 = 0.0;
	v2 = 0.0;
	v3 = 0.0;
}



double eq4( double t, double u1, double u2, double v1, double w ){
	return 1/m*(-g*v1 + k*(u2 - 2*u1) + sin( w*t));
}

double eq5( double u1, double u2, double u3, double v2 ){
	return 1/m*(-g*v2 + k*(u1 - 2*u2 + u3) );
}

double eq6( double u2, double u3, double v3 ){
	return 1/m*(-g*v3 + k*(u2 - u3));
}


double eq1( double v1 ){
	return v1;
}

double eq2( double v2 ){
	return v2;
}

double eq3( double v3 ){
	return v3;
}

void resolver( double w, double t, double &u1, double &u2, double &u3, double &v1, double &v2, double &v3){
	double iter00, iter01, iter02, iter03, iter04, iter05;
	iter00 = dt*eq1( v1 );
	iter01 = dt*eq2( v2 );
	iter02 = dt*eq3( v3 );
	iter03 = dt*eq4( t, u1, u2, v1, w );
	iter04 = dt*eq5( u1, u2, u3, v2 );
	iter05 = dt*eq6( u2, u3, v3 );

	double iter10, iter11, iter12, iter13, iter14, iter15;
	iter10 = dt*eq1( v1+1/2.0*iter03 );
	iter11 = dt*eq2( v2+1/2.0*iter04 );
	iter12 = dt*eq3( v3+1/2.0*iter05 );
	iter13 = dt*eq4( t+1/2.0*dt, u1+1/2.0*iter00, u2+1/2.0*iter01, v1+1/2.0*iter03, w );
	iter14 = dt*eq5( u1+1/2.0*iter00, u2+1/2.0*iter01, u3+1/2.0*iter02, v2+1/2.0*iter04 );
	iter15 = dt*eq6( u2+1/2.0*iter01, u3+1/2.0*iter02, v3+1/2.0*iter05 );

	double iter20, iter21, iter22, iter23, iter24, iter25;
	iter20 = dt*eq1( v1+1/2.0*iter13 );
	iter21 = dt*eq2( v2+1/2.0*iter14 );
	iter22 = dt*eq3( v3+1/2.0*iter15 );
	iter23 = dt*eq4( t+1/2.0*dt, u1+1/2.0*iter10, u2+1/2.0*iter11, v1+1/2.0*iter13, w );
	iter24 = dt*eq5( u1+1/2.0*iter10, u2+1/2.0*iter11, u3+1/2.0*iter12, v2+1/2.0*iter14 );
	iter25 = dt*eq6( u2+1/2.0*iter11, u3+1/2.0*iter12, v3+1/2.0*iter15 );

	double iter30, iter31, iter32, iter33, iter34, iter35;
	iter30 = dt*eq1( v1+iter23 );
	iter31 = dt*eq2( v2+iter24 );
	iter32 = dt*eq3( v3+iter25 );
	iter33 = dt*eq4( t+dt, u1+iter20, u2+iter21, v1+iter23, w );
	iter34 = dt*eq5( u1+iter20, u2+iter21, u3+iter22, v2+iter24 );
	iter35 = dt*eq6( u2+iter21, u3+iter22, v3+iter25 );

	u1 += iter00/6.0 + 1/3.0*(iter10 + iter20) + iter30/6.0;
	u2 += iter01/6.0 + 1/3.0*(iter11 + iter21) + iter31/6.0;
	u3 += iter02/6.0 + 1/3.0*(iter12 + iter22) + iter32/6.0;
	v1 += iter03/6.0 + 1/3.0*(iter13 + iter23) + iter33/6.0;
	v2 += iter04/6.0 + 1/3.0*(iter14 + iter24) + iter34/6.0;
	v3 += iter05/6.0 + 1/3.0*(iter15 + iter25) + iter35/6.0;
}
