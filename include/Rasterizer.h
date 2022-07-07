#ifndef _RASTERIZER_H_
#define _RASTERIZER_H_


#include <SDL2/SDL.h>
#include "Scene.h"
#include "FrameBuffer.h"
#include "vector.hpp"
#include "Camera.hpp"

class Rasterizer
{
    private:
        void 			    init_SDL		();
        SDL_Window* 	    create_window	();
        SDL_Renderer* 	    create_renderer	();
        
        void 			    draw_triangle 	(const Vertex triangleVertices[3], FrameBuffer* tex, const std::vector<Light>& light, const Texture* texMesh)const;
        void 			    draw_entity		(const Entity& entity, FrameBuffer* tex, std::vector<Light>& light, const Camera& cam);

    public:
        Rasterizer();
        ~Rasterizer();


		Matrix4<float>	    projMatrix = Matrix<float,4,4>::identity();
        SDL_Renderer* 	    renderer;
        SDL_Window*   	    window;

        void                RenderScene(Scene* pScene, FrameBuffer* pTarget, const Camera& cam);

       	Matrix4<float>      CreateOrthoMatrix(	const float& right, const float&  left, 
												const float&  top, const float&  bottom, 
												const float&  far, const float&  near) const;

		Matrix4<float>      CreatePerspectiveMatrix	(const int&  width, const int& height, 
													const float& near, const float& far, const float& fov) const;
};

#endif
