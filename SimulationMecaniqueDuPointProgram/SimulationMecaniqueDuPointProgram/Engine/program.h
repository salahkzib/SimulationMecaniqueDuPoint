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
    String MouvementEquation;
    String VitesseEquation;
    String VitesseXEquation;
    String VitesseYEquation;
    String VitesseZEquation;
    String VitesseEntrainementEquation;
    String AccelerationEquation;
    String AccelerationCoriolisEquation;
    String AccelerationPrimeEquation;
    String AccelerationEntrainementEquation;
    int NumberForceExercee;
    Force ForceExercee[];
}Point, PtrPoint;

typedef struct _Component{
    int position[2];
    double masse;
    char type;
}Component, PtrComponent;

typedef struct _Force{
    String TravailExpression;
    double Travail;
}Force, PtrForce;
#endif