#include "types.h"
#include <stdlib.h>
#include <stdio.h>

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


String creatString(String str){

}
void AddCharacter(){

}
void AddCharacterAt(){
    
}
void RemoveCharacter(){

}
void RemoveCharacterAt(){

}

Vector createVector(int size, TypeVector type){
    Vector vector;
    vector.getDataAt = getDataAt;
    vector.type = type;
    vector.size = size;
    switch(type){
        case VString:
            vector.VString.data = (String*)calloc(size, sizeof(String));
            break;
        case VInt:
            vector.VInt.data = (int*)calloc(size, sizeof(int));
            break;
        case VDouble:
            vector.VDouble.data = (double*)calloc(size, sizeof(double));
            break;
        case VFloat:
            vector.VFloat.data = (float*)calloc(size, sizeof(float));
            break;
        default:
            return;
    }
    return vector;
}

void Remove(Vector *vector){
    switch(vector->type){
        case VString:
            vector->VString.data = realloc(vector, (vector->size - 1) * sizeof(String));
            break;
        case VInt:
            vector->VInt.data = realloc(vector, (vector->size - 1) * sizeof(int));
            break;
        case VDouble:
            vector->VDouble.data = realloc(vector, (vector->size - 1) * sizeof(double));
            break;
        case VFloat:
            vector->VFloat.data = realloc(vector, (vector->size - 1) * sizeof(float));
            break;
        default:
            return;
    }
    vector->size--;
}

void Add(Vector *vector, void* data){
    switch(vector->type){
        case VString:
            vector->VString.data = realloc(vector, (vector->size + 1) * sizeof(String));
            vector->VString.data[vector->size] = (String)data;
            break;
        case VInt:
            vector->VInt.data = realloc(vector, (vector->size + 1) * sizeof(int));
            vector->VInt.data[vector->size] = (int)data;
            break;
        case VDouble:
            vector->VDouble.data = realloc(vector, (vector->size + 1) * sizeof(double));
            vector->VDouble.data[vector->size] = (double)data;
            break;
        case VFloat:
            vector->VFloat.data = realloc(vector, (vector->size + 1) * sizeof(float));
            vector->VFloat.data[vector->size] = (float)data;
            break;
        default:
            return;
    }
    vector->size++;
}

void InsertAt(Vector *vector, int index, void *data){
    switch(vector->type){
        case VString:
            vector->VString.data = realloc(vector, (vector->size + 1) * sizeof(String));
            for(int i = vector->size; i > index; i++){
                vector->VString.data[index] = vector->VString.data[index-1];
            }
            vector->VInt.data[index] = (String)data;
            break;
        case VInt:
            vector->VInt.data = realloc(vector, (vector->size + 1) * sizeof(int));
            for(int i = vector->size; i > index; i++){
                vector->VInt.data[index] = vector->VInt.data[index-1];
            }
            vector->VInt.data[index] = (int)data;
            break;
        case VDouble:
            vector->VDouble.data = realloc(vector, (vector->size + 1) * sizeof(double));
            for(int i = vector->size; i > index; i++){
                vector->VDouble.data[index] = vector->VDouble.data[index-1];
            }
            vector->VDouble.data[index] = (double)data;
            break;
        case VFloat:
            vector->VFloat.data = realloc(vector, (vector->size + 1) * sizeof(float));
            for(int i = vector->size; i > index; i++){
                vector->VFloat.data[index] = vector->VFloat.data[index-1];
            }
            vector->VFloat.data[index] = (float)data;
            break;
        default:
            return;
    }
    vector->size++;
}

void RemoveAt(Vector *vector, int index){
    switch(vector->type){
        case VString:
            for(; index < vector->size - 1; index++){
                vector->VString.data[index] = vector->VString.data[index+1];
            }
            vector->VString.data = realloc(vector, (vector->size - 1) * sizeof(String));
            break;
        case VInt:
            for(; index < vector->size - 1; index++){
                vector->VInt.data[index] = vector->VInt.data[index+1];
            }
            vector->VInt.data = realloc(vector, (vector->size - 1) * sizeof(int));
            break;
        case VDouble:
            for(; index < vector->size - 1; index++){
                vector->VDouble.data[index] = vector->VDouble.data[index+1];
            }
            vector->VDouble.data = realloc(vector, (vector->size - 1) * sizeof(double));
            break;
        case VFloat:
            for(; index < vector->size - 1; index++){
                vector->VFloat.data[index] = vector->VFloat.data[index+1];
            }
            vector->VFloat.data = realloc(vector, (vector->size - 1) * sizeof(float));
            break;
        default:
            return;
    }
    vector->size--;
}

