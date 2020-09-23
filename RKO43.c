// Made by RODRIGO CARDENAS DOMINGUEZ.
// March 6th, 2018.
// UNIVERSIDAD IBEROAMERICANA, ENGINEERING PHYSICS.

// RUNGE-KUTTA FOR LORENZ ATTRACTOR.

#include<stdio.h>
#include<float.h>
#include<stdlib.h>

void DE(double y[3], double dy[3]);
void RKO4(double dy[3], double dx, int k, double y[3]);

int main(){
    
    double x = 0, xf = .01;
    double h = 0.001, v[3], dv[3];
    int i;
    
    v[0] = 1.0;
    v[1] = 0.0;
    v[2] = 1.0;
    
    do{
        DE(v, dv);
        for(i=0 ; i<3 ; i++)
            RKO4(dv, h, i, v);
        printf("\t%0.4f \t%0.4f \t%0.4f\n", v[0], v[1], v[2]);
        x = x + h;
    }
    while( x < xf);
}

void DE(double y[3], double dy[3]){
    
    double sigma = 10.0, ro = 2.67, beta = 28.0;
    
    dy[0] = sigma*(y[1] - y[0]);
    dy[1] = y[0]*(ro - y[2]) - y[1];
    dy[2] = y[0]*y[1] - beta*y[2];

}

void RKO4(double dy[3], double dx, int k, double y[3]){
    
    double k1 =  dy[k];
    double k2 =  dy[k] + (k1 * dx/2);
    double k3 =  dy[k] + (k2 * dx/2);
    double k4 =  dy[k] + (k3 * dx);
    double RK4 = y[k] + dx*(k1 + 2*k2 + 2*k3 + k4)/6;
    
    y[k] = RK4;
 
}

