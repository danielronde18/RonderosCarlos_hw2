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
