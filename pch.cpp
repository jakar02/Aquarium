#include "pch.h"

void drawGroundWithGradient(float radius, float centerX, float centerZ) {
    int segments = 100;
    int circles = 100;

    for (int i=circles; i > 0; i--) {

        //glColor3f(1.0f/circles * i, 1.0f/circles * i, 1.0); //niebieski 
        glColor3f(1.0f / circles *0.5* i + 0.5, 1.0, 1.0f / circles * 0.5 *i + 0.5);

        glBegin(GL_TRIANGLE_FAN);  // U�ywamy TRIANGLE_FAN do rysowania ko�a
        glVertex3f(centerX, -4.0f, centerZ);  // �rodek ko�a

        // Rysowanie wierzcho�k�w ko�a (segmenty)
        for (int j = 0; j <= segments; ++j) {
            float angle = j * 2 * 3.14159f / segments;  // Obliczanie k�ta dla ka�dego segmentu
            float x = centerX + cos(angle) * (radius*i/circles);   // Wsp�rz�dna X punktu na obwodzie
            float z = centerZ + sin(angle) * (radius*i/circles);   // Wsp�rz�dna Z punktu na obwodzie
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
    // Rysowanie blatu sto�u
    glColor3f(0.7f, 0.7f, 0.7f); // kolor blatu
    glPushMatrix();

    glBegin(GL_QUADS); // Rysowanie prostok�ta (blat)
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


    //��czniki blatu
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
    glBegin(GL_QUADS); // Rysowanie prostok�ta (blat)
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
    // G��wna �odyga wodorostu (zakrzywiona, grubsza)
    glColor3f(0.0f, 0.6f, 0.0f); // Kolor �odygi

    glBegin(GL_QUAD_STRIP);
    // Definicja sekcji �odygi jako po��czonych prostok�t�w
    glVertex3f(baseX - thickness, -1.0f, baseZ);      // Podstawa (lewo)
    glVertex3f(baseX + thickness, -1.0f, baseZ);      // Podstawa (prawo)

    glVertex3f(baseX - thickness + 0.05f, -0.8f, baseZ + 0.05f); // �rodek (lewo)
    glVertex3f(baseX + thickness + 0.05f, -0.8f, baseZ + 0.05f); // �rodek (prawo)

    glVertex3f(baseX - thickness - 0.05f, -0.6f, baseZ);         // Wierzcho�ek (lewo)
    glVertex3f(baseX + thickness - 0.05f, -0.6f, baseZ);         // Wierzcho�ek (prawo)
    glEnd();

    // Li�cie wodorostu (kilka tr�jk�t�w po bokach �odygi)
    glColor3f(0.0f, 0.8f, 0.0f); // Kolor li�ci

    glBegin(GL_TRIANGLES);
    // Li�� 1 (dolny)
    glVertex3f(baseX, -0.9f, baseZ);          // Punkt na �odydze
    glVertex3f(baseX - 0.15f, -0.85f, baseZ); // Punkt w lewo
    glVertex3f(baseX, -0.8f, baseZ + 0.05f);  // Punkt wy�ej

    // Li�� 2 (�rodkowy)
    glVertex3f(baseX + 0.05f, -0.75f, baseZ + 0.05f); // Punkt na �odydze
    glVertex3f(baseX + 0.2f, -0.7f, baseZ);          // Punkt w prawo
    glVertex3f(baseX + 0.05f, -0.65f, baseZ + 0.05f); // Punkt wy�ej

    // Li�� 3 (g�rny)
    glVertex3f(baseX - 0.05f, -0.65f, baseZ);         // Punkt na �odydze
    glVertex3f(baseX - 0.2f, -0.6f, baseZ + 0.05f);   // Punkt w lewo
    glVertex3f(baseX - 0.05f, -0.55f, baseZ);         // Punkt wy�ej
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



//Te rybki s� z https://github.com/ping543f/Computer-Graphics--OpenGL-GLUT/blob/master/fish-aquriam.cpp
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
    glColor3f(0.5f, 0.25f, 0.1f);  // Br�zowy kolor dla dna

    glBegin(GL_QUADS);

    glVertex3f(-2.0f, -1.0f, -1.0f);  // lewy dolny r�g
    glVertex3f(2.0f, -1.0f, -1.0f);    // prawy dolny r�g
    glVertex3f(2.0f, -1.0f, 1.0f);     // prawy g�rny r�g
    glVertex3f(-2.0f, -1.0f, 1.0f);   // lewy g�rny r�g

    glEnd();
}

void drawWater()
{
    // Kolor wody (przezroczysty)
    glColor4f(0.5f, 0.8f, 1.0f, 0.1f); // Kolor wody z przezroczysto�ci�

    // Rysowanie przezroczystych �cian akwarium (6 �cian, sze�cian)
    glBegin(GL_QUADS);

    // Front (woda)
    glVertex3f(-2.0f, -1.0f, 1.0f);  // lewy dolny r�g
    glVertex3f(2.0f, -1.0f, 1.0f);    // prawy dolny r�g
    glVertex3f(2.0f, 1.0f, 1.0f);     // prawy g�rny r�g
    glVertex3f(-2.0f, 1.0f, 1.0f);    // lewy g�rny r�g

    // Back (woda)
    glVertex3f(-2.0f, -1.0f, -1.0f);  // lewy dolny r�g
    glVertex3f(-2.0f, 1.0f, -1.0f);   // lewy g�rny r�g
    glVertex3f(2.0f, 1.0f, -1.0f);    // prawy g�rny r�g
    glVertex3f(2.0f, -1.0f, -1.0f);   // prawy dolny r�g

    // Left (woda)
    glVertex3f(-2.0f, -1.0f, -1.0f);  // lewy dolny r�g
    glVertex3f(-2.0f, -1.0f, 1.0f);   // lewy g�rny r�g
    glVertex3f(-2.0f, 1.0f, 1.0f);    // prawy g�rny r�g
    glVertex3f(-2.0f, 1.0f, -1.0f);   // prawy dolny r�g

    // Right (woda)
    glVertex3f(2.0f, -1.0f, -1.0f);   // lewy dolny r�g
    glVertex3f(2.0f, 1.0f, -1.0f);    // lewy g�rny r�g
    glVertex3f(2.0f, 1.0f, 1.0f);     // prawy g�rny r�g
    glVertex3f(2.0f, -1.0f, 1.0f);    // prawy dolny r�g

    // Top (woda)
    glVertex3f(-2.0f, 1.0f, -1.0f);   // lewy dolny r�g
    glVertex3f(2.0f, 1.0f, -1.0f);    // prawy dolny r�g
    glVertex3f(2.0f, 1.0f, 1.0f);     // prawy g�rny r�g
    glVertex3f(-2.0f, 1.0f, 1.0f);    // lewy g�rny r�g

    // Bottom (woda)
    glVertex3f(-2.0f, -1.0f, -1.0f);  // lewy dolny r�g
    glVertex3f(-2.0f, -1.0f, 1.0f);   // lewy g�rny r�g
    glVertex3f(2.0f, -1.0f, 1.0f);    // prawy g�rny r�g
    glVertex3f(2.0f, -1.0f, -1.0f);   // prawy dolny r�g

    glEnd();
}


void drawAquarium() {
    glEnable(GL_BLEND); // W��czanie blendowania (przezroczysto�ci)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Ustawienie funkcji blendowania

    drawWater();

    // Teraz rysowanie ramy akwarium - grubsze �ciany na zewn�trz
    glColor4f(0.6f, 0.6f, 0.6f, 0.2f); // Kolor ramy akwarium, szary (albo jaki� inny)

    glBegin(GL_QUADS);

    // Front rama
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy dolny r�g
    glVertex3f(2.01f, -1.01f, 1.01f);   // prawy dolny r�g
    glVertex3f(2.01f, 1.1f, 1.01f);    // prawy g�rny r�g (zmienione z 1.05f na 1.1f)
    glVertex3f(-2.01f, 1.1f, 1.01f);    // lewy g�rny r�g (zmienione z 1.05f na 1.1f)

    // Back rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny r�g
    glVertex3f(-2.01f, 1.1f, -1.01f);   // lewy g�rny r�g (zmienione z 1.05f na 1.1f)
    glVertex3f(2.01f, 1.1f, -1.01f);   // prawy g�rny r�g (zmienione z 1.05f na 1.1f)
    glVertex3f(2.01f, -1.01f, -1.01f); // prawy dolny r�g

    // Left rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny r�g
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy g�rny r�g
    glVertex3f(-2.01f, 1.1f, 1.01f);    // prawy g�rny r�g (zmienione z 1.05f na 1.1f)
    glVertex3f(-2.01f, 1.1f, -1.01f);   // prawy dolny r�g (zmienione z 1.05f na 1.1f)

    // Right rama
    glVertex3f(2.01f, -1.01f, -1.01f);  // lewy dolny r�g
    glVertex3f(2.01f, 1.1f, -1.01f);    // lewy g�rny r�g (zmienione z 1.05f na 1.1f)
    glVertex3f(2.01f, 1.1f, 1.01f);     // prawy g�rny r�g (zmienione z 1.05f na 1.1f)
    glVertex3f(2.01f, -1.01f, 1.01f);   // prawy dolny r�g

    // Bottom rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny r�g
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy g�rny r�g
    glVertex3f(2.01f, -1.01f, 1.01f);  // prawy g�rny r�g
    glVertex3f(2.01f, -1.01f, -1.01f); // prawy dolny r�g


    glEnd();


    // Rysowanie zewn�trznej ramy (grube, ciemniejsze �ciany)
    glBegin(GL_QUADS);

    // Front rama
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy dolny r�g
    glVertex3f(2.01f, -1.01f, 1.01f);   // prawy dolny r�g
    glVertex3f(2.01f, 1.01f, 1.01f);    // prawy g�rny r�g
    glVertex3f(-2.01f, 1.01f, 1.01f);    // lewy g�rny r�g

    // Back rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny r�g
    glVertex3f(-2.01f, 1.10f, -1.01f);   // lewy g�rny r�g
    glVertex3f(2.01f, 1.10f, -1.01f);   // prawy g�rny r�g
    glVertex3f(2.01f, -1.01f, -1.01f); // prawy dolny r�g

    // Left rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny r�g
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy g�rny r�g
    glVertex3f(-2.01f, 1.10f, 1.01f);    // prawy g�rny r�g
    glVertex3f(-2.01f, 1.10f, -1.01f);   // prawy dolny r�g

    // Right rama
    glVertex3f(2.01f, -1.01f, -1.01f);  // lewy dolny r�g
    glVertex3f(2.01f, 1.1f, -1.01f);    // lewy g�rny r�g
    glVertex3f(2.01f, 1.1f, 1.01f);     // prawy g�rny r�g
    glVertex3f(2.01f, -1.01f, 1.01f);   // prawy dolny r�g

    // Bottom rama
    glVertex3f(-2.01f, -1.01f, -1.01f); // lewy dolny r�g
    glVertex3f(-2.01f, -1.01f, 1.01f);  // lewy g�rny r�g
    glVertex3f(2.01f, -1.01f, 1.01f);  // prawy g�rny r�g
    glVertex3f(2.01f, -1.01f, -1.01f); // prawy dolny r�g

    glEnd();

    // Rysowanie cienkich kraw�dzi ramy wok� akwarium
    glColor4f(0.4f, 0.4f, 0.4f, 0.5f);


    // Front (g�rna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, 1.01f);
    glVertex3f(2.01f, -1.01f, 1.01f);
    glEnd();

    // Front (dolna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, 1.01f);
    glVertex3f(2.01f, -1.01f, 1.01f);
    glEnd();

    // Back (g�rna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, 1.1f, -1.01f);
    glVertex3f(2.01f, 1.1f, -1.01f);
    glEnd();

    // Back (dolna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, 1.1f, -1.01f);
    glVertex3f(2.01f, 1.1f, -1.01f);
    glEnd();

    // Left (g�rna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, -1.01f);
    glVertex3f(-2.01f, 1.1f, -1.01f);
    glEnd();

    // Left (dolna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, 1.01f);
    glVertex3f(-2.01f, 1.1f, 1.01f);
    glEnd();

    // Right (g�rna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(2.01f, -1.01f, -1.01f);
    glVertex3f(2.01f, 1.1f, -1.01f);
    glEnd();

    // Right (dolna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(2.01f, -1.01f, 1.01f);
    glVertex3f(2.01f, 1.1f, 1.01f);
    glEnd();

    // Top (g�rna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, 1.1f, 1.01f);
    glVertex3f(2.01f, 1.1f, 1.01f);
    glEnd();

    // Bottom (dolna kraw�d�)
    glBegin(GL_LINES);
    glVertex3f(-2.01f, -1.01f, -1.01f);
    glVertex3f(2.01f, -1.01f, -1.01f);
    glEnd();



    // Bottom (dolna kraw�d�)
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

