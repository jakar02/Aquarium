#ifndef PCH_H
#define PCH_H

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <gl\GLU.h>
#include <iostream>
#include <algorithm>
#include <numbers>
#include <thread>

//#include <GL/freeglut.h>
#include "imgui.h" 
#include "imgui-SFML.h"
#include <cstdlib>  // dla rand()
#include <ctime>    // dla time()

void drawSeaweed(float baseX, float baseZ, float thickness);
void drawAllSeaweed();
void drawTheBottomOfTheAquarium();
void drawAquarium();
void fish1();
void fish2();
void fish3();
void drawTable();
void drawGroundWithGradient(float radius, float centerX, float centerZ);

#endif
