#ifndef TYPES_C
#define TYPES_C
#include <stdbool.h>

typedef enum TypeVector{VString, VInt, VDouble, VFloat}TypeVector;
typedef union _Vector{
    TypeVector type;
    struct{
        int size;
        String *data;
    }VString, *PtrVString;
    struct{
        int size;
        int *data;
    }VInt, *PtrVInt;
    struct{
        int size;
        double *data;
    }VDouble, *PtrVDouble;

    struct {
        int size;
        float *data;
    }VFloat, *PtrVFloat;
} Vector, *PtrVector;
Vector createVector(int size, TypeVector type);
void Remove(Vector *vector);
void Add(Vector *vector, void *data);
void InsertAt(Vector *vector, int index, void *data);
void RemoveAt(Vector *vector, int index);

void FreeVector(Vector *vector);

typedef enum _Function{cons ,func, dfunc, ddfunc}Function;
typedef enum _Operation{add ,moins, mult, div}Operation;

typedef struct _VectorFunctions{
    int size;
    Function* data;
}VectorFunctions, *PtrVectorFunctions;
VectorFunctions* createVectorFunctions(int size);

typedef struct _Expression{
    VectorFunctions vars;    
    Vector varsCompValue;
}Expression, *PtrExpression;
Expression* createExpression(VectorFunctions vars, Vector varsCompValue);
typedef struct {
    float x,y,z;
} Vector3D, *PtrVector3D;

typedef struct String{
    int length;
    char *data;
}String, *PtrString;

typedef struct {
    Vector3D position ;
    Vector3D velocity ;
    float masse;
    bool is__fixed ; // corps fixe=1 move=0
}cordonnes3D;

#endif