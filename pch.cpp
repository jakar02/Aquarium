#include "pch.h"

void drawGroundWithGradient(float radius, float centerX, float centerZ) {
    int segments = 100;
    int circles = 100;

    for (int i=circles; i > 0; i--) {

        //glColor3f(1.0f/circles * i, 1.0f/circles * i, 1.0); //niebieski 
        glColor3f(1.0f / circles *0.5* i + 0.5, 1.0, 1.0f / circles * 0.5 *i + 0.5);

        glBegin(GL_TRIANGLE_FAN);  // U¿ywamy TRIANGLE_FAN do rysowania ko³a
        glVertex3f(centerX, -4.0f, centerZ);  // Œrodek ko³a

        // Rysowanie wierzcho³ków ko³a (segmenty)
        for (int j = 0; j <= segments; ++j) {
            float angle = j * 2 * 3.14159f / segments;  // Obliczanie k¹ta dla ka¿dego segmentu
            float x = centerX + cos(angle) * (radius*i/circles);   // Wspó³rzêdna X punktu na obwodzie
            float z = centerZ + sin(angle) * (radius*i/circles);   // Wspó³rzêdna Z punktu na obwodzie
            glVertex3f(x, -4.0f, z);                    // Rysowanie punktu
        }
        glEnd();
    }


}






void drawLegs() 
{
    glColor3f(0.7f, 0.7f, 0.7f); // kolor blatu
    glPushMatrix();

    glBegin(GL_QUADS); 
        glVertex3f(4.0f, -1.2f, -2.0f);
        glVertex3f(3.8f, -1.2f, -2.0f);
        glVertex3f(3.8f, -4.0f, -2.0f);
        glVertex3f(4.0f, -4.0f, -2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.0f, -1.2f, -2.0f);
        glVertex3f(-3.8f, -1.2f, -2.0f);
        glVertex3f(-3.8f, -4.0f, -2.0f);
        glVertex3f(-4.0f, -4.0f, -2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(4.0f, -1.2f, 2.0f);
        glVertex3f(3.8f, -1.2f, 2.0f);
        glVertex3f(3.8f, -4.0f, 2.0f);
        glVertex3f(4.0f, -4.0f, 2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.0f, -1.2f, 2.0f);
        glVertex3f(-3.8f, -1.2f, 2.0f);
        glVertex3f(-3.8f, -4.0f, 2.0f);
        glVertex3f(-4.0f, -4.0f, 2.0f);
    glEnd();

    //polowa

    glBegin(GL_QUADS);
        glVertex3f(4.0f, -1.2f, 2.0f);
        glVertex3f(4.0f, -1.2f, 1.8f);
        glVertex3f(4.0f, -4.0f, 1.8f);
        glVertex3f(4.0f, -4.0f, 2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(4.0f, -1.2f, -2.0f);
        glVertex3f(4.0f, -1.2f, -1.8f);
        glVertex3f(4.0f, -4.0f, -1.8f);
        glVertex3f(4.0f, -4.0f, -2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.0f, -1.2f, -2.0f);
        glVertex3f(-4.0f, -1.2f, -1.8f);
        glVertex3f(-4.0f, -4.0f, -1.8f);
        glVertex3f(-4.0f, -4.0f, -2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.0f, -1.2f, 2.0f);
        glVertex3f(-4.0f, -1.2f, 1.8f);
        glVertex3f(-4.0f, -4.0f, 1.8f);
        glVertex3f(-4.0f, -4.0f, 2.0f);
    glEnd();






    glPopMatrix();
}

void drawTable() {

    drawLegs();
    // Rysowanie blatu sto³u
    glColor3f(0.7f, 0.7f, 0.7f); // kolor blatu
    glPushMatrix();

    glBegin(GL_QUADS); // Rysowanie prostok¹ta (blat)
        glVertex3f(4.0f, -1.2f, -2.0f);
        glVertex3f(4.0f, -1.2f, 2.0f);
        glVertex3f(-4.0f, -1.2f, 2.0f);
        glVertex3f(-4.0f, -1.2f, -2.0f);
    glEnd();

    glColor4f(0.4f, 0.4f, 0.4f, 0.5f);


     //dolne
    glBegin(GL_LINES);
        glVertex3f(4.0f, -1.2f, -2.0f);
        glVertex3f(-4.0f, -1.2f, -2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(4.0f, -1.2f, 2.0f);
        glVertex3f(4.0f, -1.2f, -2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(4.0f, -1.2f, 2.0f);
        glVertex3f(-4.0f, -1.2f, 2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-4.0f, -1.2f, 2.0f);
        glVertex3f(-4.0f, -1.2f, -2.0f);
    glEnd();


    //³¹czniki blatu
    glColor3f(0.7f, 0.7f, 0.7f); // kolor blatu

    glBegin(GL_QUADS);
        glVertex3f(-4.0f, -1.01f, -2.0f);
        glVertex3f(-4.0f, -1.2f, -2.0f);
        glVertex3f(4.0f, -1.2f, -2.0f);
        glVertex3f(4.0f, -1.01f, -2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.0f, -1.01f, 2.0f);
        glVertex3f(-4.0f, -1.2f, 2.0f);
        glVertex3f(4.0f, -1.2f, 2.0f);
        glVertex3f(4.0f, -1.01f, 2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.0f, -1.01f, 2.0f);
        glVertex3f(-4.0f, -1.2f, 2.0f);
        glVertex3f(-4.0f, -1.2f, -2.0f);
        glVertex3f(-4.0f, -1.01f, -2.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(4.0f, -1.01f, 2.0f);
        glVertex3f(4.0f, -1.2f, 2.0f);
        glVertex3f(4.0f, -1.2f, -2.0f);
        glVertex3f(4.0f, -1.01f, -2.0f);
    glEnd();



    glColor4f(0.4f, 0.4f, 0.4f, 0.5f);
    //posrodku linie
    glBegin(GL_LINES);
        glVertex3f(4.0f, -1.01f, -2.0f);
        glVertex3f(4.0f, -1.2f, -2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(4.0f, -1.01f, 2.0f);
        glVertex3f(4.0f, -1.2f, 2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-4.0f, -1.01f, 2.0f);
        glVertex3f(-4.0f, -1.2f, 2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-4.0f, -1.01f, -2.0f);
        glVertex3f(-4.0f, -1.2f, -2.0f);
    glEnd();

    //blat 1
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS); // Rysowanie prostok¹ta (blat)
        glVertex3f(4.0f, -1.01f, -2.0f);
        glVertex3f(4.0f, -1.01f, 2.0f);
        glVertex3f(-4.0f, -1.01f, 2.0f);
        glVertex3f(-4.0f, -1.01f, -2.0f);
    glEnd();

    glColor4f(0.4f, 0.4f, 0.4f, 0.5f);

    //gorne
    glBegin(GL_LINES);
        glVertex3f(4.0f, -1.01f, -2.0f);
        glVertex3f(-4.0f, -1.01f, -2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(4.0f, -1.01f, 2.0f);
        glVertex3f(4.0f, -1.01f, -2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(4.0f, -1.01f, 2.0f);
        glVertex3f(-4.0f, -1.01f, 2.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-4.0f, -1.01f, 2.0f);
        glVertex3f(-4.0f, -1.01f, -2.0f);
    glEnd();


    glBegin(GL_LINES);

    glEnd();
    
    glPopMatrix();

}





void drawSeaweed(float baseX, float baseZ, float thickness) {
    // G³ówna ³odyga wodorostu (zakrzywiona, grubsza)
    glColor3f(0.0f, 0.6f, 0.0f); // Kolor ³odygi

    glBegin(GL_QUAD_STRIP);
    // Definicja sekcji ³odygi jako po³¹czonych prostok¹tów
    glVertex3f(baseX - thickness, -1.0f, baseZ);      // Podstawa (lewo)
    glVertex3f(baseX + thickness, -1.0f, baseZ);      // Podstawa (prawo)

    glVertex3f(baseX - thickness + 0.05f, -0.8f, baseZ + 0.05f); // Œrodek (lewo)
    glVertex3f(baseX + thickness + 0.05f, -0.8f, baseZ + 0.05f); // Œrodek (prawo)

    glVertex3f(baseX - thickness - 0.05f, -0.6f, baseZ);         // Wierzcho³ek (lewo)
    glVertex3f(baseX + thickness - 0.05f, -0.6f, baseZ);         // Wierzcho³ek (prawo)
    glEnd();

    // Liœcie wodorostu (kilka trójk¹tów po bokach ³odygi)
    glColor3f(0.0f, 0.8f, 0.0f); // Kolor liœci

    glBegin(GL_TRIANGLES);
    // Liœæ 1 (dolny)
    glVertex3f(baseX, -0.9f, baseZ);          // Punkt na ³odydze
    glVertex3f(baseX - 0.15f, -0.85f, baseZ); // Punkt w lewo
    glVertex3f(baseX, -0.8f, baseZ + 0.05f);  // Punkt wy¿ej

    // Liœæ 2 (œrodkowy)
    glVertex3f(baseX + 0.05f, -0.75f, baseZ + 0.05f); // Punkt na ³odydze
    glVertex3f(baseX + 0.2f, -0.7f, baseZ);          // Punkt w prawo
    glVertex3f(baseX + 0.05f, -0.65f, baseZ + 0.05f); // Punkt wy¿ej

    // Liœæ 3 (górny)
    glVertex3f(baseX - 0.05f, -0.65f, baseZ);         // Punkt na ³odydze
    glVertex3f(baseX - 0.2f, -0.6f, baseZ + 0.05f);   // Punkt w lewo
    glVertex3f(baseX - 0.05f, -0.55f, baseZ);         // Punkt wy¿ej
    glEnd();
}



void drawAllSeaweed() {
    drawSeaweed(-1.5f, 0.5f, 0.01); 
    drawSeaweed(0.0f, -0.5f, 0.01);
    drawSeaweed(0.7f, 0.0f, 0.01);
    drawSeaweed(-0.3f, 0.6f, 0.01);
    drawSeaweed(-0.59f, 0.2f, 0.01);
    drawSeaweed(-0.2f, -0.2f, 0.01);
    drawSeaweed(0.5f, 0.7f, 0.01);
    drawSeaweed(-0.0f, 0.9f, 0.01);
    drawSeaweed(1.5f, 0.9f, 0.01);
    drawSeaweed(1.7f, 0.8f, 0.01);
    drawSeaweed(1.65f, 0.2f, 0.01);
    drawSeaweed(-1.8f, -0.8f, 0.01);
    drawSeaweed(1.84f, -0.8f, 0.01);
}



//Te rybki s¹ z https://github.com/ping543f/Computer-Graphics--OpenGL-GLUT/blob/master/fish-aquriam.cpp
void fish1()
{
    glColor3f(0.8, 0.5, 0.4); 
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.05);
    glVertex2f(0.05, 0.1);
    glVertex2f(0.15, 0.05);
    glVertex2f(0.05, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.13, 0.05);
    glVertex2f(0.2, 0.09);
    glVertex2f(0.2, 0.01);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.095);
    glVertex2f(0.09, 0.125);
    glVertex2f(0.07, 0.07);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.007);
    glVertex2f(0.095, -0.035);
    glVertex2f(0.07, 0.02);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2f(0.02, 0.065); // Oko
    glEnd();
}

void fish2()
{
    glColor3f(0.1, 0.2, 0.8); // Czerwony kolor ryby
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.05);
    glVertex2f(0.05, 0.1);
    glVertex2f(0.15, 0.05);
    glVertex2f(0.05, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.13, 0.05);
    glVertex2f(0.2, 0.09);
    glVertex2f(0.2, 0.01);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.095);
    glVertex2f(0.09, 0.125);
    glVertex2f(0.07, 0.07);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.007);
    glVertex2f(0.095, -0.035);
    glVertex2f(0.07, 0.02);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2f(0.02, 0.065); // Oko
    glEnd();
}

void fish3()
{
    glColor3f(0.8, 0.2, 0.2); // Czerwony kolor ryby
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.05);
    glVertex2f(0.05, 0.1);
    glVertex2f(0.15, 0.05);
    glVertex2f(0.05, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.13, 0.05);
    glVertex2f(0.2, 0.09);
    glVertex2f(0.2, 0.01);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.095);
    glVertex2f(0.09, 0.125);
    glVertex2f(0.07, 0.07);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.007);
    glVertex2f(0.095, -0.035);
    glVertex2f(0.07, 0.02);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2f(0.02, 0.065); // Oko
    glEnd();
}

void drawTheBottomOfTheAquarium() {
    // Rysowanie dna akwarium
    glColor3f(0.5f, 0.25f, 0.1f);  // Br¹zowy kolor dla dna

    glBegin(GL_QUADS);

    glVertex3f(-2.0f, -1.0f, -1.0f);  // lewy dolny róg
    glVertex3f(2.0f, -1.0f, -1.0f);    // prawy dolny róg
    glVertex3f(2.0f, -1.0f, 1.0f);     // prawy górny róg
    glVertex3f(-2.0f, -1.0f, 1.0f);   // lewy górny róg

    glEnd();
}

void drawWater()
{
    // Kolor wody (przezroczysty)
    glColor4f(0.5f, 0.8f, 1.0f, 0.1f); // Kolor wody z przezroczystoœci¹

    // Rysowanie przezroczystych œcian akwarium (6 œcian, szeœcian)
    glBegin(GL_QUADS);

    // Front (woda)
    glVertex3f(-2.0f, -1.0f, 1.0f);  // lewy dolny róg
    glVertex3f(2.0f, -1.0f, 1.0f);    // prawy dolny róg
    glVertex3f(2.0f, 1.0f, 1.0f);     // prawy górny róg
    glVertex3f(-2.0f, 1.0f, 1.0f);    // lewy górny róg

    // Back (woda)
    glVertex3f(-2.0f, -1.0f, -1.0f);  // lewy dolny róg
    glVertex3f(-2.0f, 1.0f, -1.0f);   // lewy górny róg
    glVertex3f(2.0f, 1.0f, -1.0f);    // prawy górny róg
    glVertex3f(2.0f, -1.0f, -1.0f);   // prawy dolny róg

    // Left (woda)
    glVertex3f(-2.0f, -1.0f, -1.0f);  // lewy dolny róg
    glVertex3f(-2.0f, -1.0f, 1.0f);   // lewy górny róg
    glVertex3f(-2.0f, 1.0f, 1.0f);    // prawy górny róg
    glVertex3f(-2.0f, 1.0f, -1.0f);   // prawy dolny róg

    // Right (woda)
    glVertex3f(2.0f, -1.0f, -1.0f);   // lewy dolny róg
    glVertex3f(2.0f, 1.0f, -1.0f);    // lewy górny róg
    glVertex3f(2.0f, 1.0f, 1.0f);     // prawy górny róg
    glVertex3f(2.0f, -1.0f, 1.0f);    // prawy dolny róg

    // Top (woda)
    glVertex3f(-2.0f, 1.0f, -1.0f);   // lewy dolny róg
    glVertex3f(2.0f, 1.0f, -1.0f);    // prawy dolny róg
    glVertex3f(2.0f, 1.0f, 1.0f);     // prawy górny róg
    glVertex3f(-2.0f, 1.0f, 1.0f);    // lewy górny róg

    // Bottom (woda)
    glVertex3f(-2.0f, -1.0f, -1.0f);  // lewy dolny róg
    glVertex3f(-2.0f, -1.0f, 1.0f);   // lewy górny róg
    glVertex3f(2.0f, -1.0f, 1.0f);    // prawy górny róg
    glVertex3f(2.0f, -1.0f, -1.0f);   // prawy dolny róg

    glEnd();
}


void drawAquarium() {
    glEnable(GL_BLEND); // W³¹czanie blendowania (przezroczystoœci)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Ustawienie funkcji blendowania

    drawWater();

    // Teraz rysowanie ramy akwarium - grubsze œciany na zewn¹trz
    glColor4f(0.6f, 0.6f, 0.6f, 0.2f); // Kolor ramy akwarium, szary (albo jakiœ inny)

    glBegin(GL_QUADS);

    // Front rama
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy dolny róg
    glVertex3f(2.01f, -1.01f, 1.01f);   // prawy dolny róg
    glVertex3f(2.01f, 1.1f, 1.01f);    // prawy górny róg (zmienione z 1.05f na 1.1f)
    glVertex3f(-2.01f, 1.1f, 1.01f);    // lewy górny róg (zmienione z 1.05f na 1.1f)

    // Back rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny róg
    glVertex3f(-2.01f, 1.1f, -1.01f);   // lewy górny róg (zmienione z 1.05f na 1.1f)
    glVertex3f(2.01f, 1.1f, -1.01f);   // prawy górny róg (zmienione z 1.05f na 1.1f)
    glVertex3f(2.01f, -1.01f, -1.01f); // prawy dolny róg

    // Left rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny róg
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy górny róg
    glVertex3f(-2.01f, 1.1f, 1.01f);    // prawy górny róg (zmienione z 1.05f na 1.1f)
    glVertex3f(-2.01f, 1.1f, -1.01f);   // prawy dolny róg (zmienione z 1.05f na 1.1f)

    // Right rama
    glVertex3f(2.01f, -1.01f, -1.01f);  // lewy dolny róg
    glVertex3f(2.01f, 1.1f, -1.01f);    // lewy górny róg (zmienione z 1.05f na 1.1f)
    glVertex3f(2.01f, 1.1f, 1.01f);     // prawy górny róg (zmienione z 1.05f na 1.1f)
    glVertex3f(2.01f, -1.01f, 1.01f);   // prawy dolny róg

    // Bottom rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny róg
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy górny róg
    glVertex3f(2.01f, -1.01f, 1.01f);  // prawy górny róg
    glVertex3f(2.01f, -1.01f, -1.01f); // prawy dolny róg


    glEnd();


    // Rysowanie zewnêtrznej ramy (grube, ciemniejsze œciany)
    glBegin(GL_QUADS);

    // Front rama
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy dolny róg
    glVertex3f(2.01f, -1.01f, 1.01f);   // prawy dolny róg
    glVertex3f(2.01f, 1.01f, 1.01f);    // prawy górny róg
    glVertex3f(-2.01f, 1.01f, 1.01f);    // lewy górny róg

    // Back rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny róg
    glVertex3f(-2.01f, 1.10f, -1.01f);   // lewy górny róg
    glVertex3f(2.01f, 1.10f, -1.01f);   // prawy górny róg
    glVertex3f(2.01f, -1.01f, -1.01f); // prawy dolny róg

    // Left rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny róg
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy górny róg
    glVertex3f(-2.01f, 1.10f, 1.01f);    // prawy górny róg
    glVertex3f(-2.01f, 1.10f, -1.01f);   // prawy dolny róg

    // Right rama
    glVertex3f(2.01f, -1.01f, -1.01f);  // lewy dolny róg
    glVertex3f(2.01f, 1.1f, -1.01f);    // lewy górny róg
    glVertex3f(2.01f, 1.1f, 1.01f);     // prawy górny róg
    glVertex3f(2.01f, -1.01f, 1.01f);   // prawy dolny róg

    // Bottom rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny róg
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy górny róg
    glVertex3f(2.01f, -1.01f, 1.01f);  // prawy górny róg
    glVertex3f(2.01f, -1.01f, -1.01f); // prawy dolny róg

    glEnd();

    // Rysowanie cienkich krawêdzi ramy wokó³ akwarium
    glColor4f(0.4f, 0.4f, 0.4f, 0.5f);


    // Front (górna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, 1.01f);
    glVertex3f(2.01f, -1.01f, 1.01f);
    glEnd();

    // Front (dolna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, 1.01f);
    glVertex3f(2.01f, -1.01f, 1.01f);
    glEnd();

    // Back (górna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, 1.1f, -1.01f);
    glVertex3f(2.01f, 1.1f, -1.01f);
    glEnd();

    // Back (dolna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, 1.1f, -1.01f);
    glVertex3f(2.01f, 1.1f, -1.01f);
    glEnd();

    // Left (górna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, -1.01f);
    glVertex3f(-2.01f, 1.1f, -1.01f);
    glEnd();

    // Left (dolna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, 1.01f);
    glVertex3f(-2.01f, 1.1f, 1.01f);
    glEnd();

    // Right (górna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(2.01f, -1.01f, -1.01f);
    glVertex3f(2.01f, 1.1f, -1.01f);
    glEnd();

    // Right (dolna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(2.01f, -1.01f, 1.01f);
    glVertex3f(2.01f, 1.1f, 1.01f);
    glEnd();

    // Top (górna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, 1.1f, 1.01f);
    glVertex3f(2.01f, 1.1f, 1.01f);
    glEnd();

    // Bottom (dolna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, -1.01f);
    glVertex3f(2.01f, -1.01f, -1.01f);
    glEnd();



    // Bottom (dolna krawêdŸ)
    glBegin(GL_LINES);
    glVertex3f(2.01f, -1.01f, -1.01f);
    glVertex3f(2.01f, -1.01f, 1.01f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(2.01f, 1.1f, -1.01f);
    glVertex3f(2.01f, 1.1f, 1.01f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, -1.01f);
    glVertex3f(-2.01f, -1.01f, 1.01f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-2.01f, 1.1f, -1.01f);
    glVertex3f(-2.01f, 1.1f, 1.01f);
    glEnd();


}

