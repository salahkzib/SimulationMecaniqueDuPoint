#include <stdio.h>

#include "program.h"

String TrajectoireType(VectorInt Trajectoire){

}

double EnergieMecaniqueCalcul(Expression expression){
       return EnergieCinetiqueCalcul(expression) + EnergiePotentielleCalcul(expression);
}
double EnergiePotentielleCalcul(Expression expression){
      double g = 9.81;
      return point.masse * g * point.z ;
}
double EnergieCinetiqueCalcul(Expression expression){
      double v_squard = (point.vitesseX * point.vitesseX ) +(point.vitesseY * point.vitesseY) +  (point.vitesseZ * point.vitesseZ);
      return 0.5 * point.masse * v_squard ;
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

void AllExpretions(){

}
      
typedef struct {
      int dimensions;
      double ax , bx , cx ;
      double ay , by , cy ;
      double az , bz , cz ;
      double x0 , dx0 ;
      double y0 , dy0 ;
      double z0 , dz0 ;
} plan;
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

void solve_second_order( double a, double b, double c , double y0 , double dy0){
     if(a == 0){
        solve_first_order (b,c,y0);
        return;
     }
     double delta = b * b - 4 * a *c ; 
     if(delta > 0){
        double r1 = (-b + sqrt(delta))/ (2 * a) ;
        double r2 = (-b - sqrt(delta))/ (2 * a) ;
        double C2 = (dy0 - r1 * y0)/ ( r2 - r1 );
        double C1 = y0 - C2 ;
        printf("y(t) = %.2f * exp(%.2f * t) + %.2f * exp(%.2f *t)", C1 , r1 , C2 , r2);
     }else if (delta == 0 ){ 
        double r = -b / (2 * a) ;
        double C1 = y0 ;
        double C2 = dy0 - r * y0 ;
        printf(" y(t) = (%.2f + %.2f * t)* exp(%.2f * t)", C1 , C2, r);
     } else {
        double alpha = -b / a ;
        double  beta = (sqrt(-delta ))/ (2 * a) ;
        double C1 = y0 ;
        double C2 = (dy0 - alpha)/ beta ;
        printf(" y(t) = exp(%.2f*t)*(%.2f*cos(%.2f*t) + %.2f*sin(%.2f*t))",alpha , C1, beta , C2 , beta );
     }
}
void DetEquationMov(){
      if (plan.dimensions == 3){
            slove_second_order(plan.ax, plan.bx, plan.cx, plan.x0, plan.dx0);
            slove_second_order(plan.ay, plan.by, plan.cy, plan.y0, plan.dy0);
            slove_second_order(plan.az, plan.bz, plan.cz, plan.z0, plan.dz0);
      }
      else if (plan.dimensions == 2 ){
            slove_second_order(plan.ax, plan.bx, plan.cx, plan.x0, plan.dx0);
            slove_second_order(plan.ay, plan.by, plan.cy, plan.y0, plan.dy0);    
      }
      else if (plan.dimensions == 1){
            slove_second_order(plan.ax, plan.bx, plan.cx, plan.x0, plan.dx0);
      }
      }      

