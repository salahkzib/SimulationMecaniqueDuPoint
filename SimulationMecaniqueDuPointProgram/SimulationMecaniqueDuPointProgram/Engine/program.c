#include <stdio.h>
#include "program.h"

void Initializing(String TypeExperienceParam, Plan planParam, Component *ComposantsParam, Force *ForcesExerceesParam, Force *ForceExternesParam, VectorDouble SensParam, VectorDouble PositionsInitialParam, int VitesseInitialParam, int masseParam, VectorDouble DonnesParam, VectorString QuestionsParam){
    t = 0;
    point.masse = masseParam;
    if(planParam.dimentions == 1){
        point.Vector.D1.x = PositionsInitialParam.data[0];
    }else if(planParam.dimentions == 2){
        point.Vector.D2.x = PositionsInitialParam.data[0];
        point.Vector.D2.y = PositionsInitialParam.data[1];
    }else if(planParam.dimentions == 3){
        point.Vector.D3.x = PositionsInitialParam.data[0];
        point.Vector.D3.y = PositionsInitialParam.data[1];
        point.Vector.D3.z = PositionsInitialParam.data[2];
    }
    point.EnergieCinetique = 0;
    TypeExperience = TypeExperienceParam;
    plan = planParam;
    Components = ComposantsParam;
    ForcesExercees = ForcesExerceesParam;
    ForceExternes = ForceExternesParam;
    ConditionsInitiales = SensParam;
    Donnes = DonnesParam;
    Questions = QuestionsParam;

}

String TrajectoireType(VectorInt Trajectoire){

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