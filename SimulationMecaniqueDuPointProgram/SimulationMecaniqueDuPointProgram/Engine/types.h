#ifndef TYPES_C
#define TYPES_C
#include <stdbool.h>

typedef enum TypeVector{VString, VInt, VDouble, VFloat}TypeVector;
typedef union _Vector{
    TypeVector type;
    int size;
    struct{
        String *data;
    }VString, *PtrVString;
    struct{
        int *data;
    }VInt, *PtrVInt;
    struct{
        double *data;
    }VDouble, *PtrVDouble;
    struct {
        float *data;
    }VFloat, *PtrVFloat;
    void* (*getDataAt)(int index);
} Vector, *PtrVector;

Vector createVector(int size, TypeVector type);
void Remove(Vector *vector);
void Add(Vector *vector, void *data);
void InsertAt(Vector *vector, int index, void *data);
void RemoveAt(Vector *vector, int index);
void* getDataAt(int index);

void FreeVector(Vector *vector);

typedef enum _Function{cons ,func, dfunc, ddfunc}Function;
typedef enum _Operation{add ,minus, mult, div}Operation;

typedef struct _VectorFunctions{
    int size;
    Function* data;
}VectorFunctions, *PtrVectorFunctions;
VectorFunctions* createVectorFunctions(int size);

typedef struct _Expression{
    VectorFunctions vars;    
    Vector varsCompValue;
    Operation* operations;
}Expression, *PtrExpression;
Expression* createExpression(VectorFunctions vars, Vector varsCompValue);
typedef struct {
    float x,y,z;
} Vector3D, *PtrVector3D;

typedef struct String{
    int length;
    char *data;
}String, *PtrString;
String creatString(String str);
void AddCharacter();
void AddCharacterAt();
void RemoveCharacter();
void RemoveCharacterAt();

typedef struct {
    Vector3D position ;
    Vector3D velocity ;
    float masse;
    bool is__fixed ; // corps fixe=1 move=0
}cordonnes3D;

#endif