#include <stdio.h>
#include <math.h>

void solve_first_order(double a, double y0){
   int lea = -1*a;
   int ley0 = y0; 
   printf("%d", lea);
   printf("%d", ley0);
   printf(" y(t) = %f*epx( %f*t )\n",ley0,lea);
}

void solve_second_order( double a, double b, double c , double y0 , double dy0){
     if(a == 0){
        printf("erreur \n");
        return;
     }
     double delta = b * b - 4 * a *c ; 
     if(delta > 0){
        double r1 = (-b + sqrt(delta))/ 2 * a ;
        double r2 = (-b - sqrt(delta))/ 2 * a ;
        double C2 = (dy0 - r1 * y0)/ ( r2 - r1 );
        double C1 = y0 - C2 ;
        printf("y(t) = %.2f * exp(%.2f * t) + %.2f * exp(%.2f *t)", C1 , r1 , C2 , r2);
     }else if (delta == 0 ){ 
        double r = -b / 2 * a ;
        double C1 = y0 ;
        double C2 = dy0 - r * y0 ;
        printf(" y(t) = (%.2f + %.2f * t)* exp(%.2f * t)", C1 , C2, r);
     } else {
        double alpha = -b / a ;
        double  beta = (sqrt(-delta ))/ 2 * a ;
        double C1 = y0 ;
        double C2 = (dy0 - alpha)/ beta ;
        printf(" y(t) = exp(%.2f*t)*(%.2f*cos(%.2f*t) + %.2f*sin(%.2f*t))",alpha , C1, beta , C2 , beta );
     }
}

int main(){
    int choix;
    printf("choisiser votre type d'eqt \n");
    printf(" 1: eqt 1ere ordre(y' + a * y = 0)\n ");
    printf("2: eqt 2ere ordre(a *y'' + b * y' + c * y = 0)\n ");
    printf("entrer votre choix ");
    scanf("%d", &choix);
    if(choix == 1 ){
        double a , y0;
        printf("entrer le coefficient a :");
        scanf("%lf",&a);
        printf("entrer la condition initial y0 : ");
        scanf("%lf",&y0);
        solve_first_order( a, y0);
    }else {
        double a, b, c, y0 , dy0 ;
        printf("entrer les coefficients a, b et c  :");
        scanf("%lf%lf%lf ",&a , &b, &c);
        printf("entrer les conditions initial y0 , dy0");
        scanf("%lf%lf",&y0,&dy0);
        solve_second_order( a,  b,  c ,  y0 ,  dy0);
    }
    return 0;
}