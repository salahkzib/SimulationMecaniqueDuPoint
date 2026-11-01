
#include "raylib.h"
#include "raymath.h"
#include "plantesting.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 600

// 3D camera
Camera3D camera = { 0 };

// Camera rotation speed
#define ROTATION_SPEED 0.03f

// Initialize the 3D environment
void init_plan(void)
{
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

// Reset camera to its original position
void reset_camera(void)
{
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
}

// Manual camera controls
void control_camera(void)
{
    float rotation_speed = ROTATION_SPEED;

    // Position relative to camera target
    Vector3 offset = Vector3Subtract(camera.position, camera.target);

    // Zoom using the mouse wheel
float zoom_speed = 1.0f;

float wheel = GetMouseWheelMove();

if (wheel != 0)
{
    float distance = Vector3Length(offset);

    distance -= wheel * zoom_speed;

    // Prevent the camera from getting too close
    if (distance < 2.0f) distance = 2.0f;

    // Prevent excessive zoom out
    if (distance > 50.0f) distance = 50.0f;

    offset = Vector3Scale(
        Vector3Normalize(offset),
        distance
    );
}

    // Left and right rotation
    if (IsKeyDown(KEY_LEFT))
    {
        offset = Vector3RotateByAxisAngle(
            offset,
            (Vector3){ 0.0f, 1.0f, 0.0f },
            rotation_speed
        );
    }

    if (IsKeyDown(KEY_RIGHT))
    {
        offset = Vector3RotateByAxisAngle(
            offset,
            (Vector3){ 0.0f, 1.0f, 0.0f },
            -rotation_speed
        );
    }

    // Up and down rotation
    Vector3 right = Vector3Normalize(
        Vector3CrossProduct(
            (Vector3){ 0.0f, 1.0f, 0.0f },
            offset
        )
    );

    if (IsKeyDown(KEY_UP))
    {
        offset = Vector3RotateByAxisAngle(
            offset, right, rotation_speed
        );
    }

    if (IsKeyDown(KEY_DOWN))
    {
        offset = Vector3RotateByAxisAngle(
            offset, right, -rotation_speed
        );
    }

    // Prevent camera from flipping upside down
    float horizontalDistance = sqrtf(
        offset.x * offset.x + offset.z * offset.z
    );

    float angle = atan2f(offset.y, horizontalDistance);

    if (angle > 1.4f || angle < -1.4f)
    {
        offset.y = tanf(1.4f) * horizontalDistance *
                   (offset.y > 0 ? 1.0f : -1.0f);
    }

    camera.position = Vector3Add(camera.target, offset);
}

// Calculate the 3D world position under the mouse
bool GetMouseWorldPosition(Vector3 *worldPosition)
{
    Ray ray = GetMouseRay(GetMousePosition(), camera);

    // Ground plane: Y = 0
    if (fabsf(ray.direction.y) < 0.0001f)
        return false;

    float distance = -ray.position.y / ray.direction.y;

    if (distance < 0.0f)
        return false;

    *worldPosition = Vector3Add(
        ray.position,
        Vector3Scale(ray.direction, distance)
    );

    return true;
}

// Draw the 3D environment
void draw_plan(void)
{
    // Reset camera
    if (IsKeyPressed(KEY_R))
    {
        reset_camera();
    }

    // Manual camera control
    control_camera();

    Vector3 mouseWorld = { 0 };
bool mouseOnGround = GetMouseWorldPosition(&mouseWorld);

    // 3D drawing begins
    BeginMode3D(camera);

        // Ground grid
        DrawGrid(20, 1.0f);

        // Coordinate axes
        DrawLine3D(
            (Vector3){ -10.0f, 0.0f, 0.0f },
            (Vector3){  10.0f, 0.0f, 0.0f },
            RED
        );

        DrawLine3D(
            (Vector3){ 0.0f, -10.0f, 0.0f },
            (Vector3){ 0.0f,  10.0f, 0.0f },
            GREEN
        );

        DrawLine3D(
            (Vector3){ 0.0f, 0.0f, -10.0f },
            (Vector3){ 0.0f, 0.0f,  10.0f },
            BLUE
        );

        // Origin point
        DrawSphere(
            (Vector3){ 0.0f, 0.0f, 0.0f },
            0.15f,
            WHITE
        );

        // Test cube
        DrawCube(
            (Vector3){ 0.0f, 1.0f, 0.0f },
            2.0f, 2.0f, 2.0f,
            PURPLE
        );

        // Cube outline
        DrawCubeWires(
            (Vector3){ 0.0f, 1.0f, 0.0f },
            2.0f, 2.0f, 2.0f,
            WHITE
        );

        // Mouse position indicator
if (mouseOnGround)
{
    DrawSphere(
        mouseWorld,
        0.12f,
        RED
    );
}

    // 3D drawing ends
    EndMode3D();

// Mouse world coordinates
if (mouseOnGround)
{
    DrawText(
        TextFormat(
            "Mouse World: X: %.2f | Y: 0.00 | Z: %.2f",
            mouseWorld.x,
            mouseWorld.z
        ),
        10, HEIGHT - 75, 18, WHITE
    );
}
else
{
    DrawText(
        "Mouse World: Outside ground plane",
        10, HEIGHT - 75, 18, GRAY
    );
}

// Camera position
DrawText(
    TextFormat(
        "Camera: X: %.2f | Y: %.2f | Z: %.2f",
        camera.position.x,
        camera.position.y,
        camera.position.z
    ),
    10, HEIGHT - 50, 18, WHITE
);

    // 2D UI
    DrawText(
        "R: Reset Camera",
        WIDTH - 190, 10, 18, WHITE
    );

    DrawText(
        "Arrow Keys: Rotate Camera",
        WIDTH - 280, 35, 18, LIGHTGRAY
    );

    DrawText(
        "X: Red  |  Y: Green  |  Z: Blue",
        10, HEIGHT - 25, 18, LIGHTGRAY
    );
}

// Main window
int main(void)
{
    InitWindow(WIDTH, HEIGHT, "3D Mechanical Planner");

    SetTargetFPS(60);

    init_plan();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        draw_plan();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
