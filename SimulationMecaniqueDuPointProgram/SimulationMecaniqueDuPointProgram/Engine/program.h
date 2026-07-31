#ifndef PROGRAM_C
#define PROGRAM_C
#define EXPORT _declspec(dllexport)
#include <stdbool.h>
#include "types.h"

typedef struct _Point{
    int x;
    int y;
    double EnergieMecanique;
    double EnergiePotentielle;
    double EnergieCinetique;
    double vitesse;
    double acceleration;
    double vitesseX;
    double vitesseY;
    double vitesseZ;
    double MomentCinetique;
    double VitesseEntrainement;
    double AccelerationEntrainement;
    double AccelerationCoriolis;
    double AccelerationPrime;
    double masse;
    VectorInt Trajectoire;
    Expression MouvementEquation;
    Expression VitesseEquation;
    Expression VitesseXEquation;
    Expression VitesseYEquation;
    Expression VitesseZEquation;
    Expression VitesseEntrainementEquation;
    Expression AccelerationEquation;
    Expression AccelerationCoriolisEquation;
    Expression AccelerationPrimeEquation;
    Expression AccelerationEntrainementEquation;
    int NumberForceExercee;
    Force ForceExercee[];
}Point, *PtrPoint;

typedef struct _Component{
    int position[2];
    double masse;
    char type;
}Component, *PtrComponent;

typedef struct _Force{
    String TravailExpression;
    double Travail;
}Force, *PtrForce;
extern Force Gravity, Archimede, PlanReaction;

String TrajectoireType(VectorInt Trajectoire);

double EnergieMecaniqueCalcul(Expression expression);
double EnergiePotentielleCalcul(Expression expression);
double EnergieCinetiqueCalcul(Expression expression);
double vitesseCalcul(Expression expression);
double accelerationCalcul(Expression expression);
double vitesseXCalcul(Expression expression);
double vitesseYCalcul(Expression expression);
double vitesseZCalcul(Expression expression);
double MomentCinetiqueCalcul(Expression expression);
double VitesseEntrainementCalcul(Expression expression);
double AccelerationEntrainementCalcul(Expression expression);
double AccelerationCoriolisCalcul(Expression expression);
double AccelerationPrimeCalcul(Expression expression);

Expression MouvementEquationDeterminant(Point point);
Expression VitesseEquationeterminant(Point point);
Expression VitesseXEquationeterminant(Point point);
Expression VitesseYEquationeterminant(Point point);
Expression VitesseZEquationeterminant(Point point);
Expression VitesseEntrainementEquationeterminant(Point point);
Expression AccelerationEquationeterminant(Point point);
Expression AccelerationCoriolisEquationeterminant(Point point);
Expression AccelerationPrimeEquationeterminant(Point point);
Expression AccelerationEntrainementEquationeterminant(Point point);

#endif