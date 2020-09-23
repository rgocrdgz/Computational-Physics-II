// Made by RODRIGO CARDENAS DOMINGUEZ.
// March 6th, 2018.
// UNIVERSIDAD IBEROAMERICANA, ENGINEERING PHYSICS.

// RUNGE-KUTTA FOR A DIFFERENTIAL EQUATION USING ARRAYS.

#include<math.h>
#include<stdio.h>
#include<float.h>
#include<stdlib.h>

float ED(float y[11], int c, float dy[11]);
void RKO4(float dy[11], int c, float dx, float y[11]);

int main(){
    
    int i = 0;
    float x = 0, xf = 1;
    float h = 0.1, v[11], dv[11];
    
    v[0] = 0.0;
    
    printf("\tv[%d] \tk1 \tk2 \tk3 \tk4 \tv[%d]\n", i+1, i+2);
    do{
        RKO4(dv, i, h, v);
        x = x + h;
        i = i + 1;
    }
    while( x < xf + h);
}

void RKO4(float dy[11], int c, float dx, float y[11]){
    
    float k1 =  ED(y, c, dy);
    float k2 =  ED(y, c, dy) + (k1 * dx/2);
    float k3 =  ED(y, c, dy) + (k2 * dx/2);
    float k4 =  ED(y, c, dy) + (k3 * dx);
    
    y[c+1] = ED(y, c, dy) + 1/6*(k1 + 2*k2 + 2*k3 + k4);
    
    printf("\t%.2f \t%.2f \t%.2f \t%.2f \t%.2f \t%.2f\n", y[c], k1, k2, k3, k4, y[c+1]);
}

float ED(float y[11], int c, float dy[11]){
    
    float g = 9.81, k = 12.5, m = 25;
    
    dy[c] = k/m*y[c] + g;
    
    return dy[c];

}
