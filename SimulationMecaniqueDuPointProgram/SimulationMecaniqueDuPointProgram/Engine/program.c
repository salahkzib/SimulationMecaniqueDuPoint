#include <stdio.h>
#include "program.h"

void Initializing(int TypeExperienceArg, Plan planArg, Force ForcesExercees[], Component ComponentsArg[], DataCUS DataCUSArg[]){
   t = 0;
   
}

String TrajectoireType(Vector Trajectoire){

}



double EnergieMecaniqueCalcul(Expression expression){

}
double EnergiePotentielleCalcul(Expression expression){

}
double EnergieCinetiqueCalcul(Expression expression){

}
double vitesseCalcul(Expression expression){

}
double accelerationCalcul(Expression expression){

}
double vitesseXCalcul(Expression expression){

}
double vitesseYCalcul(Expression expression){

}
double vitesseZCalcul(Expression expression){

}
double MomentCinetiqueCalcul(Expression expression){

}
double VitesseEntrainementCalcul(Expression expression){

}
double AccelerationEntrainementCalcul(Expression expression){

}
double AccelerationCoriolisCalcul(Expression expression){

}
double AccelerationPrimeCalcul(Expression expression){

}



Expression MouvementEquationDeterminant(Point point){

}
Expression VitesseEquationeterminant(Point point){

}
Expression VitesseXEquationeterminant(Point point){

}
Expression VitesseYEquationeterminant(Point point){

}
Expression VitesseZEquationeterminant(Point point){

}
Expression VitesseEntrainementEquationeterminant(Point point){

}
Expression AccelerationEquationeterminant(Point point){

}
Expression AccelerationCoriolisEquationeterminant(Point point){

}
Expression AccelerationPrimeEquationeterminant(Point point){

}
Expression AccelerationEntrainementEquationeterminant(Point point){

}

void solve_first_order(double a, double y0){
   if (a == 0 ){
      printf(" erreur ");
      return;
   }
   int lea = -1*a;
   int ley0 = y0;
   printf("%d", lea);
   printf("%d", ley0);
   printf(" y(t) = %f*epx( %f*t )\n",ley0,lea);
}

void solve_second_order(double a, double b, double c , double var0 , double dvar0){
     if(a == 0){
        solve_first_order (b,c,var0,dvar0);
        return;
     }
     double delta = b * b - 4 * a *c ;
     if(delta > 0){
        double r1 = (-b + sqrt(delta))/ (2 * a) ;
        double r2 = (-b - sqrt(delta))/ (2 * a) ;
        double C2 = (dvar0 - r1 * var0)/ ( r2 - r1 );
        double C1 = var0 - C2 ;
        printf("y(t) = %.2f * exp(%.2f * t) + %.2f * exp(%.2f *t)", C1 , r1 , C2 , r2);
     }else if (delta == 0 ){
        double r = -b / (2 * a) ;
        double C1 = var0 ;
        double C2 = dvar0 - r * var0 ;
        printf(" y(t) = (%.2f + %.2f * t)* exp(%.2f * t)", C1 , C2, r);
     } else {
        double alpha = -b / a ;
        double  beta = (sqrt(-delta ))/ (2 * a) ;
        double C1 = var0;
        double C2 = (dvar0 - alpha)/ beta ;
        printf(" y(t) = exp(%.2f*t)*(%.2f*cos(%.2f*t) + %.2f*sin(%.2f*t))",alpha , C1, beta , C2 , beta );
     }
}
void DetEquationMov(){
   int ax, bx, cx, x0, dx0;
   int ay, by, cy, y0, dy0;
   int az, bz, cz, z0, dz0;
   switch(plan.dimentions){
      case 1:
         solve_second_order(ax, bx, cx, x0, dx0);
         break;
      case 2:
         solve_second_order(ax, bx, cx, x0, dx0);
         solve_second_order(ay, by, cy, y0, dy0);
         break;
      case 3:
         solve_second_order(ax, bx, cx, x0, dx0);
         solve_second_order(ay, by, cy, y0, dy0);
         solve_second_order(az, bz, cz, z0, dz0);
         break;
   }
}
