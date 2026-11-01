#ifndef PLANTESTING_H
#define PLANTESTING_H
#include "raylib.h"

void init_plan(void);
void draw_plan(void);
void control_camera(void);
Vector2 WorldToScreen(Vector2 world);//convert world coordinates to screen coordinates
Vector2 ScreenToWorld(Vector2 screen);//convert screen coordinates to world coordinates

#endif //PLANTESTING_H