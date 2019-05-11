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
	
	
		ofstream info1;
	info1.open("uiVSw.txt");
	for( double t = 0.0; t < 150; t = t + dt ){
		resolver( w, t, u1, u2, u3, v1, v2, v3 );
		info1 << t << "\t" << u1 << "\t" << u2 << "\t" << u3 << "\t" << v1 << "\t" << v2 << "\t" << v3 << endl;
	}
	info1.close();

	w = 0.63;
	condiciones_iniciales( u1, u2, u3, v1, v2, v3);
	ofstream info2;
	info2.open("datos1.txt");
	for( double t = 0.0; t < 150; t = t + dt ){
		resolver( w, t, u1, u2, u3, v1, v2, v3 );
		info2 << t << "\t" << u1 << "\t" << u2 << "\t" << u3 << "\t" << v1 << "\t" << v2 << "\t" << v3 << endl;
	}
	info2.close();

	w = 1.30;
	condiciones_iniciales( u1, u2, u3, v1, v2, v3);
	ofstream info3;
	info3.open("datos2.txt");
	for( double t = 0.0; t < 150; t = t + dt ){
		resolver( w, t, u1, u2, u3, v1, v2, v3 );
		info3 << t << "\t" << u1 << "\t" << u2 << "\t" << u3 << "\t" << v1 << "\t" << v2 << "\t" << v3 << endl;
	}
	info3.close();

	w = 2.50;
	condiciones_iniciales( u1, u2, u3, v1, v2, v3);
	ofstream info4;
	info4.open("datos3.txt");
	for( double t = 0.0; t < 150; t = t + dt ){
		resolver( w, t, u1, u2, u3, v1, v2, v3 );
		info4 << t << "\t" << u1 << "\t" << u2 << "\t" << u3 << "\t" << v1 << "\t" << v2 << "\t" << v3 << endl;
	}
	info4.close();

	w = 4.0;
	condiciones_iniciales( u1, u2, u3, v1, v2, v3);
	ofstream info5;
	info5.open("datos4.txt");
	for( double t = 0.0; t < 150; t = t + dt ){
		resolver( w, t, u1, u2, u3, v1, v2, v3 );
		info5 << t << "\t" << u1 << "\t" << u2 << "\t" << u3 << "\t" << v1 << "\t" << v2 << "\t" << v3 << endl;
	}
	info5.close();

	int N = 100;
	double tf = 150.0;
	int arrtam = int(tf/dt);
	double w0 = 0.2*sqrt(k/m);
	double w1 = 3.0*sqrt(k/m);
	double dw = ( w1 - w0 )/(N-1);
	double W[N], T[arrtam];
	
	ofstream info6;
	info6.open("ui_maximo.txt");

	for( int i = 0; i<N; i++ ){
		W[i] = w0 + dw*i;
	}

	for( int i = 0; i<arrtam; i++ ){
		T[i] = i*dt;
	}
	
	for( int i=0; i < N; i++){
		condiciones_iniciales( u1, u2, u3, v1, v2, v3);
		vector<double> u1_t(arrtam), u2_t(arrtam), u3_t(arrtam);

		for( int j=0; j < arrtam; j++ ){
			resolver( W[i], T[j], u1, u2, u3, v1, v2, v3 );
			u1_t[j] = u1;
			u2_t[j] = u2;
			u3_t[j] = u3;
		}

		sort( u1_t.begin(), u1_t.end() );
		sort( u2_t.begin(), u2_t.end() );
		sort( u3_t.begin(), u3_t.end() );

		double u1_max = u1_t[arrtam-1];
		double u2_max = u2_t[arrtam-1];
		double u3_max = u3_t[arrtam-1];
		info6 << W[i] << "\t" << u1_max << "\t" << u2_max << "\t" << u3_max << endl;
	}
	
	info6.close();

    
    
    
    
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





double eq1( double v1 ){
	return v1;
}

double eq2( double v2 ){
	return v2;
}

double eq3( double v3 ){
	return v3;
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
