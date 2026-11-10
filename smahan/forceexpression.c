#include "program.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ExtractEquationCoefficient(double masse, double *a_out , double *b_out , double *c_out , double *F_ext_x , double *F_ext_y , double *F_ext_z){
     *a_out = (masse > 0 ) ? masse : 1.0;
     double b_visqueux = 0.0 ;
     if (frottementfluidelineaire.coefficient > 0){
        b_visqueux = frottementfluidelineaire.coefficient;
     }else {
        b_visqueux = frottementfluidelineaire.fx ;
     }
     *b_out = b_visqueux ;
     double c_rappel = 0.0;
    if (rappel.coefficient > 0) {
        c_rappel = rappel.coefficient;
    } else {
        c_rappel = rappel.fx;
    }
    *c_out = c_rappel;
    *F_ext_x = poids.fx + gravitationuniverselle.fx + reactionnormal.fx + frottementsloide.fx + inertie.fx;
    *F_ext_y = poids.fy + gravitationuniverselle.fy + reactionnormal.fy + frottementsloide.fy + inertie.fy;
    *F_ext_z = poids.fz + gravitationuniverselle.fz + reactionnormal.fz + frottementsloide.fz + inertie.fz;
    if (ForceExternes != NULL) {
        *F_ext_x += ForceExternes[0].fx;
        *F_ext_y += ForceExternes[0].fy;
        *F_ext_z += ForceExternes[0].fz;
void ResolverEtGenererTrajectoire(double t_max, double dt) {
    double masse = (Donnes.data != NULL && Donnes.data[0] > 0) ? Donnes.data[0] : 1.0;
    double a = 0.0, b = 0.0, c = 0.0;
    double F_ext_x = 0.0, F_ext_y = 0.0, F_ext_z = 0.0;
    ExtractEquationCoefficients(masse, &a, &b, &c, &F_ext_x, &F_ext_y, &F_ext_z);
    if (plan.dimentions == 1) {
        point.Vector.D1.ax = a;
        point.Vector.D1.bx = b;
        point.Vector.D1.cx = c;
    } 
    else if (plan.dimentions == 2) {
        point.Vector.D2.ax = a; point.Vector.D2.ay = a;
        point.Vector.D2.bx = b; point.Vector.D2.by = b;
        point.Vector.D2.cx = c; point.Vector.D2.cy = c;
    } 
    else if (plan.dimentions == 3) {
        point.Vector.D3.ax = a; point.Vector.D3.ay = a; point.Vector.D3.az = a;
        point.Vector.D3.bx = b; point.Vector.D3.by = b; point.Vector.D3.bz = b;
        point.Vector.D3.cx = c; point.Vector.D3.cy = c; point.Vector.D3.cz = c;
    }
    double x0 = (plan.dimentions == 3) ? point.Vector.D3.x0 : point.Vector.D1.x;
    double dx0 = (plan.dimentions == 3) ? point.Vector.D3.dx0 : 0.0;
    
    solve_second_order(a_out, b_out, c_out, x0, dx0);
    double x_curr = x0;
    double v_curr = dx0;
    double accel_curr = 0.0;
    double t_max;
    for (double time = 0.0; time <= t_max; time += dt) {
        // PFD : a(t) = (F_ext - b*v - c*x) / m
        accel_curr = (F_ext_x - (b_out * v_curr) - (c_out  * x_curr)) / a;
        if (plan.dimentions == 3) {
            point.Vector.D3.ax = accel_curr;
            point.Vector.D3.x  = x_curr;
        } else if (plan.dimentions == 1) {
            point.Vector.D1.ax = accel_curr;
            point.Vector.D1.x  = x_curr;
        }
        printf("%.2f \t %.4f \t %.4f \t %.4f\n", time, x_curr, v_curr, accel_curr);
        v_curr += accel_curr * dt;
        x_curr += v_curr * dt;
    }
}
}