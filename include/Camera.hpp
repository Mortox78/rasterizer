#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector.hpp"

class Rasterizer;

#define MOUSE_SENSITIVITY 1.f
#define CAM_SPEED         50.0f

class Camera
{
    private:
        Vec3 posCam;
        Vec3 rotCam;
        Vec3 scaleCam;

        void manage_cam_translation(const float& deltaTime);
        void manage_cam_rotation(const float& deltaTime);

    public:
        Camera();
        ~Camera();

        Matrix4<float> inverseCamMatrix;

        void manage_cam(Rasterizer& rast, const float &deltaTime);

        inline Vec3 get_posCam()const {return posCam;}
};



#endif
