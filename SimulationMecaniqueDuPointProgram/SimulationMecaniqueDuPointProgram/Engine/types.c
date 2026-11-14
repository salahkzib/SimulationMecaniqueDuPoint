#include "types.h"

VectorFunctions* createVectorFunctions(int size){
    VectorFunctions* vector = (VectorFunctions*)malloc(sizeof(VectorFunctions));
    vector->size = size;
    vector->data = (Function*)calloc(size, sizeof(Function));
    return vector;
}

Expression* createExpression(VectorFunctions vars, Vector varsCompValue){
    Expression* expr = (Expression*)calloc(1, sizeof(Expression));
    expr->vars = vars;
    expr->varsCompValue = varsCompValue;
    return expr;
}

Vector createVector(int size, TypeVector type){
    Vector vector;
    vector.type = type;
    switch(type){
        case VString:
            vector.VString.size = size;
            vector.VString.data = (String*)calloc(size, sizeof(String));
            break;
        case VInt:
            vector.VInt.size = size;
            vector.VInt.data = (int*)calloc(size, sizeof(int));
            break;
        case VDouble:
            vector.VDouble.size = size;
            vector.VDouble.data = (double*)calloc(size, sizeof(double));
            break;
        case VFloat:
            vector.VFloat.size = size;
            vector.VFloat.data = (float*)calloc(size, sizeof(float));
            break;
    }
    return vector;
}

void Remove(Vector *vector){

}

void Add(Vector *vector, void *data){

}

void InsertAt(Vector *vector, int index, void *data){

}

void RemoveAt(Vector *vector, int index){

}