// Made by RODRIGO CARDENAS DOMINGUEZ.
// March 6th, 2018.
// UNIVERSIDAD IBEROAMERICANA, ENGINEERING PHYSICS.

// RUNGE-KUTTA FOR A DIFFERENTIAL EQUATION USING POINTERS.

#include<math.h>
#include<stdio.h>
#include<float.h>
#include<stdlib.h>

void ED(float y, float *dy);
void RKO4(float dy, float dx, float *y);

int main(){
    
    float x = 0, xf = 1;
    float h = 0.1, v, dv, v1;
    
    v = 0.0;
    
    printf("\tv \tk1 \tk2 \tk3 \tk4 \tv1\n");
    do{
        ED(v, &dv);
        RKO4(dv, h, &v);
        x = x + h;
    }
    while( x < xf + h);
}

void ED(float y, float *dy){
    
    float g = 9.81, k = 12.5, m = 25;
    
    *dy = k/m*y + g;
    printf("\n\t dy = %0.2f", *dy);
    
}

void RKO4(float dy, float dx, float *y){
    
    float k1 =  dy;
    float k2 =  dy + (k1 * dx/2);
    float k3 =  dy + (k2 * dx/2);
    float k4 =  dy + (k3 * dx);
    float RK4 = *y + 1/6*(k1 + 2*k2 + 2*k3 + k4);
    
    *y = RK4;s
    
    printf("\t%.2f \t%.2f \t%.2f \t%.2f \t%.2f \t%.2f\n", *y, k1, k2, k3, k4, RK4);
}

