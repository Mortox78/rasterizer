//================	RASTERIZER	===================//

By: Quentin BLEUSE & Steeven NOVO
Released the : 19/12/2019

//=============	DESCRIPTION	=================//

This project consisted in making a rasterizer 
using the SDL to help us draw pixels on screen.
The rasterizer can draw 3D scenes and manage light.

//============	HOW TO BUILD ================//

First, make sure that no indiresable file are present by using 
the command "make clean", then use the command make to make the 
executable appear ( "rasterizer" )

//============	HOW TO RUN	=================//

After having built the project, make it run by using the command "./rasterizer".
if it doesn't run, try to rebuild it by using the commands "make clean"
and "make".

//===========	FEATURES	=================//

The Version 0 to 6 have been implemented. The backface-culling too.

//=============================TECHNIQUES USED================================

The SDL has been used to load textures, open a new window, and display the results of rasterization
by creating a SDL_Texture.

//=======================NOT ADDED FEATURES & BUGS==============================

Version 7, 8 and 10 not added or fully added.
Having no clipping in 3D space, the rasterizer make a segmentation fault when
the scene is behind the user.
