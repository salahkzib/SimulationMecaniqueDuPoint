#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//cote math 
typedef struct {
    float x,y,z;
} Vector3D;
// addition 
Vector3D vec_add( Vector3D a, Vector3D b){
    return (Vector3D){ a.x + b.x, a.y + b.y, a.z +b.z };
}
//multuplication bach n3rfo position li raykon fiha le corps selon v et t=q
Vector3D vec_scal( Vector3D v, float q){
    return(Vector3D){ v.x*q, v.y*q, v.z*q};
}
// norme du vecteur 
float vec_norm(Vector3D v){
return sqrtf(v.x*v.x+v.y*v.y+v.z*v.z);
}
// vecteur unitaire 
Vector3D vec_uni(Vector3D v){
float lenth = vec_norm(v);
if lenth = 0.0f return(Vector3D){0.0f ,0.0f ,0.0f};
return (Vector3D){v.x/lenth , v.y/lenth ,v.z/lenth };
}
// fin cote math 
//cote physique 
typedef struct {
    Vector3D position ;
    Vector3D velocity ;
    float masse;
    bool is__fixed ; // corps fixe=1 move=0
}cordonnes3D;
Vector3D force_gravity(cordonnes3D c , Vector3D g){ 
    return vec_scal( g, c.masse);
}
Vector3D force_friction(cordonnes3D c, float k ){
    return vec_scal(c.velocity, k);
}
Vector3D acceleration(Vector3D position, Vector3D velocity , float masse , Vector3D g ,float k){
    cordonnes3D temp_c = {position, velocity , masse ,0};
    Vector3D force_g = force_gravity(temp_c , g);
    Vector3D force_f = force_friction(temp_c , k);
    Vector3D totale_force = vec_add(force_g , force_f);
    return vec_scal(totale_force,1.0f/masse);// a=(somme de forces )*1/masse
}
void rk4(cordonnes3D *c,float dt , Vector3D g , float k ){
    if (c-> is__fixed) return ;
    Vector3D x0 = c->position;
    Vector3D v0 = c-> velocity;
    //point K1
    Vector3D a1 = acceleration(x0 , v0 , (*p).masse , g , k);
    Vector3D kv1 = v0 ;
    Vector3D ka1 = a1;
    // point k2 
    Vector3D x2 = vec_add(x0 , vec_scal(kv1, 0.5f * dt));
    Vector3D v2 = vec_add(v0 , vec_scal(ka1, 0.5f * dt));
     Vector3D a2 = acceleration(x2 , v2 , (*p).masse , g , k);
     Vector3D kv2 = v2 ;
    Vector3D ka2 = a2 ;
    // point k3 
    Vector3D x3 = vec_add(x0 , vec_scal(kv2, 0.5f * dt));
    Vector3D v3 = vec_add(v0 , vec_scal(ka2, 0.5f * dt));
     Vector3D a3 = acceleration(x3, v3 , (*p).masse , g , k);
     Vector3D kv3 = v3 ;
    Vector3D ka3 = a3 ;
    // point k4 
    Vector3D x4 = vec_add(x0 , vec_scal(kv3,  dt));
    Vector3D v4 = vec_add(v0 , vec_scal(ka3, dt));
     Vector3D a4 = acceleration(x4 , v4 , (*p).masse , g , k);
     Vector3D kv4 = v4 ;
    Vector3D ka4 = a4 ;
    Vector3D sum_v = vec_add(vec_add(kv1,vec_scal(kv2 , 2.0f)),vec_add(vec_scal(kv3, 2.0f), kv4));
    c->position = vec_add(x0 , vec_scal(sum_v, dt/6.0f));
    Vector3D sum_a = vec_add(vec_add(ka1,vec_scal(ka2 , 2.0f)),vec_add(vec_scal(ka3, 2.0f), ka4));
    c->velocity= vec_add(v0 , vec_scal(sum_a, dt/6.0f));
}