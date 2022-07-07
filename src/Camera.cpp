#include <iostream>
#include "FrameBuffer.h"
#include "Camera.hpp"
#include <SDL2/SDL.h>
#include <cmath>



Camera::Camera() :
    posCam   {0, 0, 5.f},
    rotCam   {0, 0, 0},
    scaleCam {1, 1, 1}
{
    inverseCamMatrix = Matrix4<float>::identity();
}

Camera::~Camera()
{

}


void Camera::manage_cam_translation(const float& deltaTime)
{
    double forward = 0, strafe = 0, fly = 0, speed = deltaTime * CAM_SPEED;

    // input
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_W])
        forward   = -0.025 * speed;
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_S])
        forward   = 0.025  * speed;
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_A])
        strafe    = -0.025 * speed;
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_D])
        strafe    = 0.025  * speed;
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_SPACE])
        fly       = 0.025  * speed;
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LCTRL])
        fly       = -0.025  * speed; 


    // change pos of camera
    double angle = rotCam.y * (M_PI / 180);

    posCam.x += forward * sin(angle);
    posCam.z += forward * cos(angle);
    posCam.x += strafe  * cos(angle);
    posCam.z += strafe  * -sin(angle);
    posCam.y += fly;
}

void Camera::manage_cam_rotation(const float& deltaTime)
{
    float speed = deltaTime * CAM_SPEED;

    // input
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_UP])
        rotCam.x += 2 * speed;
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_DOWN])
        rotCam.x -= 2 * speed;
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT])
        rotCam.y += 2 * speed;
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT])
        rotCam.y -= 2 * speed;

    // limit vertical rotation
    if (rotCam.x > 89)
        rotCam.x = 89;
    else if (rotCam.x < -89)
        rotCam.x = -89;
}


void Camera::manage_cam(Rasterizer& rast, const float& deltaTime)
{
    manage_cam_rotation(deltaTime);
    manage_cam_translation(deltaTime);

    // Change the camera's transformation matrix
    inverseCamMatrix = (Matrix4<float>::CreateTRSMatrix(scaleCam, rotCam, posCam));
	inverseCamMatrix = inverseCamMatrix.getInverseMatrix();
}
