#include "pch.h"
//#include <GL/freeglut.h>
#include <vector>
#include <cmath>

typedef sf::Event sfe;
typedef sf::Keyboard sfk;
typedef sf::Keyboard sfk;

float R = 1.5;
float cameraAngle = 45.0f; 
const int N = 500;

float fishPosX[N] = {};
float fishPosY[N] = {};
float fishPosZ[N] = {};
float fishPosXAmplitude[N] = {};
float fishPosZAmplitude[N] = {};
float fishSpeed = 0.001f; 
float fishAngle[N] = {}; 
int fishType[N] = {};
void (*fishFunctions[])() = { fish1, fish2, fish3 };



typedef sf::Event sfe;
typedef sf::Keyboard sfk;

void initOpenGL(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}


void reshapeScreen(sf::Vector2u size)
{
    glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)size.x / (GLdouble)size.y, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}




void initializeFishes() {
    for (int i = 0; i < N; i++) {
        fishPosX[i] = 0.0f;
        fishPosZ[i] = 0.0f;  
        fishPosY[i] = 1.0f * ((float)rand() / RAND_MAX) - 0.5f; 
        fishAngle[i] = 360.0f * ((float)rand() / RAND_MAX); 
        fishType[i] = (int)(3.0f * ((float)rand() / RAND_MAX));
        fishPosZAmplitude[i] = 0.4f * ((float)rand() / RAND_MAX) - 0.2;
    }
}


void drawFish(float x, float y, float z, float angle, int it) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    fishFunctions[fishType[it]]();

    glPopMatrix();
}


void updateFish(int it) {
    float a = 1.7f; // Pó³osie elipsy w X
    float b = 0.7f; // Pó³osie elipsy w Z

    fishAngle[it] += fishSpeed * 360.0f; // Aktualizacja k¹ta
    if (fishAngle[it] >= 360.0f) fishAngle[it] -= 360.0f;

    // Nowa pozycja ryby
    fishPosX[it] = a * cos(fishAngle[it] * 3.14159f / 180.0f);
    fishPosZ[it] = b * sin(fishAngle[it] * 3.14159f / 180.0f);
}


void drawScene(sf::RenderWindow& window) {
    glLoadIdentity();

    float cameraX = 3.0f * R * cos(cameraAngle * 3.14159f / 180.0f);
    float cameraZ = 3.0f * R * sin(cameraAngle * 3.14159f / 180.0f);
    float cameraY = 3.0f * R;
    gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawGroundWithGradient(8.0f, 0.0f, 0.0f);
    drawTable(); 
    drawTheBottomOfTheAquarium();
    drawAllSeaweed();

    for (int i = 0; i < N; i++) {
        float fishDirectionAngle = 90 - fishAngle[i];
        drawFish(fishPosX[i], fishPosY[i], fishPosZ[i] + fishPosZAmplitude[i], fishDirectionAngle, i);
    }


    drawAquarium();
}









int main(int argc, char** argv)
{


    // Initialize SFML
    sf::ContextSettings settings;
    settings.depthBits = 24;
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Akwarium", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    ImGui::SFML::Init(window);
    initOpenGL();

    reshapeScreen(window.getSize());

    bool running = true;

    sf::Clock deltaClock;
    initializeFishes();

    while (running)
    {
        sfe event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sfe::Closed || (event.type == sfe::KeyPressed && event.key.code == sfk::Escape))
                running = false;
            if (event.type == sfe::Resized)
                reshapeScreen(window.getSize());
        }

        // Aktualizacja pozycji ryb
        for (int i = 0; i < N; i++) {
            updateFish(i);
        }
        drawScene(window);

        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::Begin("Akwarium");
        ImGui::SliderFloat("Fishes speed", &fishSpeed, 0.00001f, 0.01f);
        ImGui::SliderFloat("Camera angle", &cameraAngle, 0.0f, 360.0f);
        ImGui::SliderFloat("R", &R, 0.5f, 10.0f);

        ImGui::End();

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
