#include <bits/stdc++.h>

using namespace std;

#include "GL\glut.h"
#define PI acos(-1)

int s_ID;
bool f=1,pause=0;
double fade, speech, trans_x, trans_y, f1,f2,f3,f4,f5, star_fade, p=.5;
int a[50],b[50];

// Function to Print Text
void print(char *str,double r,double g,double b,double a,int x,int y,double w,double h,double strokeSize)
{
    glPushMatrix();

    glColor4f(r, g, b, a);
    glTranslatef(x, y, 0);
    glScalef(w, h, 0);

    glPointSize(strokeSize);
    glLineWidth(strokeSize);

    while (*str)
    {
        // each character
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *str++);
    }
    glPopMatrix();
}

// Function to Draw Circle
void circleDrawing(double x,double y,double r,double g,double b,double sx,double sy,double radius, double st_ang, double en_ang)
{
    glPushMatrix();

    glTranslatef(x, y, 0);
    glScalef(sx, sy, 0);

    // rsin(theta)  rcos(theta)
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    for (double i = st_ang; i < en_ang; i += 5)
        glVertex2f(radius * sin(i * PI / 180.0), radius * cos(i * PI / 180.0));
    glEnd();

    glPopMatrix();
}


// Function to Draw a Woman
void madam(double tx, double ty, double sx, double sy)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    // Neck
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.9, 0.7, 0.4);
    glVertex2f(507, 380);
    glVertex2f(507, 360);
    glVertex2f(513, 380);
    glVertex2f(513, 360);
    glEnd();
    glLineWidth(1);

    // Face
    circleDrawing(510, 397, 0.98, 0.85, 0.5, 1, 1, 30, 0 , 360);

    // Hair
    circleDrawing(510, 410, 0.2, 0.2, 0.2, 1, .6, 35, -90 , 90);

    // blackish fonytaill
    circleDrawing(535, 390, 0.2, 0.2, 0.2,.4, 1, 35, 0 , 180);

    // Left Eye
    circleDrawing(490, 400, 1, 1, 1, 1, 1, 5, 0 , 360);
    circleDrawing(490, 400, 0.05, 0.05, 0.05, 1, 1, 2.5, 0, 360);

    // Right Eye
    circleDrawing(515, 400, 1, 1, 1, 1, 1, 5 ,0, 360);

    circleDrawing(515, 400, 0.05, 0.05, 0.05, 1, 1, 2.5,  0, 360);

    //mouth
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(500, 380);
    glVertex2f(510, 380);
    glEnd();

    // Nose
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(502, 400);
    glVertex2f(498, 393);
    glVertex2f(498, 393);
    glVertex2f(502, 390);
    glEnd();
    glLineWidth(1);

    // Arms
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.95, 0.8, 0.45); // Lighter Skin
    glVertex2f(470, 340);
    glVertex2f(470, 240);
    glVertex2f(475, 340);
    glVertex2f(475, 240);
    glVertex2f(480, 340);
    glVertex2f(480, 240);

    glVertex2f(540, 340);
    glVertex2f(540, 240);
    glVertex2f(545, 340);
    glVertex2f(545, 240);
    glVertex2f(550, 340);
    glVertex2f(550, 240);
    glEnd();
    glLineWidth(1);

    // Top
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex2f(470, 360);
    glVertex2f(550, 360);
    glVertex2f(540, 300);
    glVertex2f(480, 300);
    glEnd();



    // Skirt
    glBegin(GL_POLYGON);
    glColor3f(.3, .3, .3);
    glVertex2f(480, 300);
    glVertex2f(540, 300);
    glVertex2f(560, 180);
    glVertex2f(460, 180);
    glEnd();


    // Ribbon
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2f(480, 300);
    glVertex2f(540, 300);
    glEnd();
    glLineWidth(1);

    // Legs
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.95, 0.8, 0.45); // Lighter Skin
    glVertex2f(490, 180);
    glVertex2f(490, 150);
    glVertex2f(495, 180);
    glVertex2f(495, 150);

    glVertex2f(525, 180);
    glVertex2f(525, 150);
    glVertex2f(530, 180);
    glVertex2f(530, 150);
    glEnd();
    glLineWidth(1);


    glPopMatrix();
}

void boyDress(double tx,double ty,double sx,double sy,double r,double g,double b)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    // Bottom Shirt
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(0, 20);
    glVertex2f(100, 20);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glEnd();

    // Top Shirt
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(135, 105);
    glVertex2f(120, 175);
    glVertex2f(100, 200);
    glVertex2f(50, 180);
    glVertex2f(0, 200);
    glVertex2f(-20, 175);
    glVertex2f(-35, 105);
    glVertex2f(0, 100);
    glEnd();

    // Left Trouser
    glColor3ub(37, 107, 202);
    glBegin(GL_POLYGON);
    glVertex2f(0, 25);
    glVertex2f(0, -100);
    glVertex2f(35, -100);
    glVertex2f(65, 25);
    glEnd();

    // Right Trouser
    glBegin(GL_POLYGON);
    glVertex2f(35, 25);
    glVertex2f(65, -100);
    glVertex2f(100, -100);
    glVertex2f(100, 25);
    glEnd();

    glPopMatrix();
}

void boy(double tx,double ty,double sx,double sy,double r,double g,double b)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    // Neck
    circleDrawing(-1, -35, .95, .7, .35,.6, 1, 20, -90, 90);

    // Face
    circleDrawing(0, 0, .95, .8, .45, 1, 1, 24,  0, 360);

    // Left Eye
    circleDrawing(-8, 0, 1, 1, 1, 1, 1, 4,  0, 360);
    circleDrawing(-6, 0, 0.05, 0.05, 0.05, 1, 1, 2,  0, 360);

    // Right Eye
    circleDrawing(8, 0, 1, 1, 1, 1, 1, 4,0,360);
    circleDrawing(10, 0, 0.05, 0.05, 0.05, 1, 1, 2, 0, 360);

    //hair

    circleDrawing(0, 5,.1, 0.1, 0.1, 1, 1, 26,  -90, 90);

    // mouth
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(.1,.1,.1);
    glVertex2f(-5, -15);
    glVertex2f(2, -15);
    glEnd();


    // Hands
    circleDrawing(-42, -82, .95, .8, .45, 1, 1, 10,  0, 360);
    circleDrawing(38, -82, .95, .8, .45, 1, 1, 10,  0, 360);

    // dress
    boyDress(-32, -125, .6, .5,r, g, b);

    // Left Shoe
    circleDrawing(-21, -178, .1, .1, .1,1.2, 1,10, -90, 90);

    // Right Shoe
    circleDrawing(18, -178, .1, .1, .1, 1.2, 1,10, -90, 90);

    glPopMatrix();
}


void kg_room()
{
    // top ceiling
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.58, 0.49);
    glVertex2f(0, 800);
    glColor3f(1, .99, .95);
    glVertex2f(200, 700);
    glColor3f(1, .99, .95);
    glVertex2f(1400, 700);
    glColor3f(0.65, 0.58, 0.49);
    glVertex2f(1400, 800);
    glEnd();

    // Border for Ceiling
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0); // Black
    glVertex2f(0, 800);
    glVertex2f(200, 700);
    glVertex2f(1400, 700);
    glVertex2f(1400, 800);
    glEnd();


    // left wall

    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.58, 0.49);
    glVertex2f(0, 800);
    glColor3f(1, .99, .95);
    glVertex2f(200, 700);
    glColor3f(1, .99, .95);
    glVertex2f(200, 175);
    glColor3f(0.65, 0.58, 0.49);
    glVertex2f(0, 0);
    glEnd();

    // Border for left Wall
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(0, 800);
    glVertex2f(200, 700);
    glVertex2f(200, 175);
    glVertex2f(0, 0);
    glEnd();

    // middle Wall
    glBegin(GL_POLYGON);
    glColor3f(1, .99, .95);
    glVertex2f(200, 700);
    glColor3f(1, .99, .95);
    glVertex2f(1400, 700);
    glColor3f(0.65, 0.58, 0.49);
    glVertex2f(1400, 175);
    glColor3f(0.65, 0.58, 0.49);
    glVertex2f(200, 175);
    glEnd();

    // Border for Center Wall
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(200, 700);
    glVertex2f(1400, 700);
    glVertex2f(1400, 175);
    glVertex2f(200, 175);
    glEnd();

    // Floor
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.58, 0.49);
    glVertex2f(200, 175);
    glVertex2f(1400, 175);
    glVertex2f(1400, 0);
    glVertex2f(0, 0);
    glEnd();

    // Blackboard
    glBegin(GL_POLYGON);
    glColor3f(0.05, 0.05, 0.05);
    glVertex2f(450, 540);
    glVertex2f(1100, 540);
    glVertex2f(1100, 300);
    glVertex2f(450, 300);
    glEnd();

    // Blackboard Border
    glLineWidth(10);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.25, 0.15, 0.1);
    glVertex2f(450, 540);
    glVertex2f(1100, 540);
    glVertex2f(1100, 300);
    glVertex2f(450, 300);
    glEnd();
}

// Function to Draw Teacher's Desk
void Desk()
{
    // Teacher's Desk
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.2);

    glVertex2f(900, 300);
    glVertex2f(870, 240);
    glVertex2f(1030, 240);
    glVertex2f(1000, 300);
    glEnd();

    // Teacher's Desk Edge
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.2);
    glVertex2f(870, 240);
    glVertex2f(870, 230);
    glVertex2f(1030, 230);
    glVertex2f(1030, 240);
    glEnd();

    //Leg
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.2);
    glVertex2f(900, 230);
    glVertex2f(900, 140);
    glVertex2f(1000, 140);
    glVertex2f(1000, 230);
    glEnd();
}


// S_ID =0 ,Introduction

void intro()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Title
    if(fade<=1)
    {
        print("The True picture of Education",1,1,1,fade,300,580,.27,.27, 3);
        print("in our society",1,1,1,fade,500,500,.27,.27,3);
    }
    else if(fade<2)
        print("A short story",1, 1, 1, fade-1, 500, 520, .3, .3, 3);
    else if(fade<3)
    {
        print("By",1, 1, 1, fade-2, 650, 580, .3, .3, 3);
        print("Md. Abul Kalam",1, 1, 1, fade-2, 450, 480, .3, .3, 2);
        print("Roll: 133032",1, 1, 1, fade-2, 450, 420, .3, .3, 2);
        print("Department of CSE",1, 1, 1, fade-2, 450, 360, .3, .3, 2);
        print("For Project CSE-4202",1, 1, 1, fade-2, 390, 300, .3, .3, 2);
    }
}


// S_ID =  1, kg Title

void kgTitle()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    print("kindergarten",1,1,1,fade,300+trans_x,400,.3,.3,2);
}

// S_ID =  2 - kg speech

void kg_speech()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    print("As children",1, 1, 1, fade, 150, 660, .25, .25, 3);
    print("-> we are taught to follow, not to lead",1, 1, 1, fade-1, 150, 590, .25, .25, 3);
    print("-> We are taught to learn, not to explore.",1, 1, 1, fade-2, 150,530, .25, .25,3);
    print("-> We are taught to by heart, not to understand.",1,1,1,fade-3,150,470,.25,.25,3);
}

// S_ID =  3 - kg room

void kg()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    kg_room();
    madam(440, 0, 1, 1);
    Desk();
    // board text
    print("2 + 2 = ",1,1,1,fade,580,440,.2,.2,3);
    print("4",1,1,1,fade-0.5,740,440,.2,.2,3);
    print("6 - 4 = ",1,1,1,fade-1,580,380,.2,.2,3);
    print("2",1,1,1,fade-1.5,740,380,.2,.2,3);
    print("-> This is where our educational journey begins...",
          0, 0, 0, fade-2, 350, 600, .15, .15, 2);
}


// S_ID =  4 - Primary Title

void psTitle()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    print("Primary School",1,1,1,fade,300+trans_x,400,.3,.3,2);
}

// S_ID = 5 - primary speech

void ps_speech()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    print("-> We cannot go outside to play",1,1,1,fade,150,590,.25,.25,3);
    print("-> As Playing is considered just waste of time",
          1,1,1,fade-1,150,530,.25,.25,3);
    print("-> But it is good for our health",1,1,1,fade-2,150,470,.25,.25,3);
}


// house drawing function
void house()
{
    // Ceiling
    glBegin(GL_POLYGON);
    glColor3f(.12, .4, .5); // Aqua
    glVertex2f(0, 800);
    glVertex2f(0, 700);
    glVertex2f(100, 650);
    glVertex2f(1400, 650);
    glVertex2f(1400, 800);
    glEnd();

    // Border for Ceiling
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(0, 800);
    glVertex2f(0, 700);
    glVertex2f(100, 650);
    glVertex2f(1400, 650);
    glVertex2f(1400, 800);
    glEnd();

    // left wall

    glBegin(GL_POLYGON);
    glColor3f(.7, .8, .85);
    glVertex2f(0, 750);
    glVertex2f(100, 650);
    glVertex2f(100, 200);
    glVertex2f(0, 0);
    glEnd();

    // Border for left Wall
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(0, 750);
    glVertex2f(100, 650);
    glVertex2f(100, 200);
    glVertex2f(0, 0);
    glEnd();

    // middle Wall
    glBegin(GL_POLYGON);
    glColor3f(.45, .6, .7);
    glVertex2f(100, 650);
    glVertex2f(1400, 650);
    glColor3f(.65, .75, .8);
    glVertex2f(1400, 200);
    glVertex2f(100, 200);
    glEnd();

    // Border for middle Wall
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(100, 650);
    glVertex2f(1400, 650);
    glVertex2f(1400, 200);
    glVertex2f(100, 200);
    glEnd();

    // Floor
    glBegin(GL_POLYGON);
    glColor3f(.45, .6, .7);
    glVertex2f(100, 200);
    glVertex2f(1400, 200);
    glVertex2f(1400, 0);
    glVertex2f(0, 0);
    glEnd();

    // Border for Floor
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(100, 200);
    glVertex2f(1400, 200);
    glVertex2f(1400, 0);
    glVertex2f(0, 0);
    glEnd();

    // Door
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2f(300, 500);
    glVertex2f(500, 500);
    glVertex2f(500, 200);
    glVertex2f(300, 200);
    glEnd();

    // Border
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(.5, .3, .1);
    glVertex2f(300, 200);
    glVertex2f(300, 500);
    glVertex2f(300, 500);
    glVertex2f(500, 500);
    glVertex2f(500, 500);
    glVertex2f(500, 200);
    glEnd();
    glLineWidth(1);

    // play

    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.67, 0.91); // Sky Blue
    glVertex2f(300, 500);
    glVertex2f(500, 500);
    glColor3f(.32, 0.64, 0.16); // Green Grass
    glVertex2f(500, 275);
    glVertex2f(300, 275);
    glEnd();

    // road

    glBegin(GL_POLYGON);
    glColor3f(.15, .16, .16);
    glVertex2f(300, 275);
    glVertex2f(500, 275);
    glVertex2f(500, 200);
    glVertex2f(300, 200);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(300, 235);
    glVertex2f(380, 235);
    glVertex2f(420, 235);
    glVertex2f(500, 235);
    glEnd();
    glLineWidth(1);
}

void ps_dialogue()
{
    if(fade>=.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(.0, 0, 0); // black
        glVertex2f(140, 630);
        glVertex2f(140, 585);
        glVertex2f(950, 585);
        glVertex2f(950, 630);
        glEnd();
    }
    if(fade>=.5 && fade<=2)
    {
        glBegin(GL_POLYGON);
        glColor3f(.0, 0, 0); // black
        glVertex2f(150, 585);
        glVertex2f(250, 370);
        glVertex2f(200, 585);
        glEnd();
        print("KID: Mom, can I go out and play football?",
              1, 1, 1, 1, 300, 600, .14, .14, 1);
    }
    else if(fade>2)
    {
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2f(800, 585);
        glVertex2f(935, 395);
        glVertex2f(850, 585);
        glEnd();
        print("MOM: No, you have to complete your homework first",
              1, 1, 1, 1, 180, 600, .14, .14, 1);
    }
}

// S_ID = 6 - Primary School

void ps()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    house();
    // Mother
    madam(440, 0, 1, 1);
    // main kid
    boy(250, 370,1, 1,.5, .5, .5);

    // moving kid
    boy(360 + trans_x, 380,-.3, .3,1, 1, 0);
    // Left Kid
    boy(350 , 350,.3, .3,1, 1, 1);
    // Right Kid
    boy(430, 350,-.3, .3,1, 1, 0);
    // football
    circleDrawing(380 + trans_x,305,.9, .9, .9,1, 1, 6, 0, 360);
    ps_dialogue();
}


double sunMove, hsBoyX = 1150, hsBoyY = 5220,
                trans_x1 = 850, trans_x2 = -1000, trans_y1 = 40, trans_y2 = 1040;

double sky_r = 0.05, sky_g = 0.67, sky_b = 0.91,
       grass_r = 0.32, grass_g =  0.7, grass_b = 0.165,
       sun_r = 0.98, sun_g = 1, sun_b = 0.64;

bool noon, sunSet, tuition_done, graduation;

// S_ID = 7 - High School title


void hsTitile()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    print("High School",1,1,1,fade,300 + trans_x,400,.3,.3,2);
}

// S_ID = 8 - High School speech

void hs_speech()
{
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    print("At High school",1,1,1,fade,150,660,.25,.25,3);
    print("-> we only allowed to go to school",1,1,1,fade-1,150,590,.25,.25,3);
    print("-> And to the tuitions",1,1,1,fade-2,150,530,.25,.25,3);
    print("-> They become our life",1,1,1,fade-3,150,470,.25,.25,3);
}

// High School window create

void window()
{
    // School Windows
    for (int i = 0; i <= 450; i+=110)
    {
        glBegin(GL_POLYGON);
        glColor3f(.2, .38, .5);
        glVertex2f(425 + i, 450);
        glVertex2f(520 + i, 450);
        glVertex2f(520 + i, 360);
        glColor3f(.38, .5, .6);
        glVertex2f(425 + i, 360);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(.1, .1, .1);
        glVertex2f(425 + i, 450);
        glVertex2f(520 + i, 450);
        glVertex2f(520 + i, 360);
        glVertex2f(425 + i, 360);
        glEnd();
    }
}

// High school scene draw

void highSchool()
{
    // Background
    glBegin(GL_POLYGON);
    glColor3f(sky_r, sky_g, sky_b); // Sky Blue
    glVertex2f(0, 800);  // 0 - 1400 , 400 - 800
    glVertex2f(1400, 800);
    glVertex2f(1400, 400);
    glVertex2f(0, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(sky_r, sky_g, sky_b); // Sky Blue
    glVertex2f(0, 400);
    glVertex2f(1400, 400);
    glColor3f(grass_r, grass_g, grass_b); // Green Grass
    glVertex2f(1400, 175);
    glVertex2f(0, 175);
    glEnd();

    // sun
    circleDrawing(100 + sunMove, 700,sun_r, sun_g, sun_b,
                  1, 1, 50, 0, 360);


    // lower grass
    glBegin(GL_POLYGON);
    glColor3f(grass_r, grass_g, grass_b);
    glVertex2f(0, 75);
    glVertex2f(1400, 75);
    glVertex2f(1400, 0);
    glVertex2f(0, 0);
    glEnd();

    // Road
    glBegin(GL_POLYGON);
    glColor3f(.15, .15, .15);
    glVertex2f(0, 175);
    glVertex2f(1400, 175);
    glVertex2f(1400, 75);
    glVertex2f(0, 75);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(0, 125);
    glVertex2f(200, 125);

    glVertex2f(300, 125);
    glVertex2f(500, 125);

    glVertex2f(600, 125);
    glVertex2f(800, 125);

    glVertex2f(900, 125);
    glVertex2f(1100, 125);

    glVertex2f(1200, 125);
    glVertex2f(1400, 125);

    glVertex2f(0, 172);
    glVertex2f(1400, 172);

    glVertex2f(0, 78);
    glVertex2f(1400, 78);

    glEnd();
    glLineWidth(1);

    // Home Bottom
    glBegin(GL_POLYGON);
    glColor3f(0.66, 0.46, 0.35);
    glVertex2f(1375, 190);
    glColor3f(.75, .55, .45);
    glVertex2f(1375, 300);
    glColor3f(.75, .55, .45);
    glVertex2f(1100, 300);
    glColor3f(.65, .5, .35);
    glVertex2f(1100, 190);
    glEnd();

    // Home Bottom Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(1375, 190);
    glVertex2f(1375, 300);
    glVertex2f(1100, 300);
    glVertex2f(1100, 190);
    glEnd();


    // Triangle Rooftop
    glBegin(GL_TRIANGLES);
    glColor3f(.25, .15, .1);
    glVertex2f(1090, 300);
    glVertex2f(1237, 400);
    glVertex2f(1385, 300);
    glEnd();

    // Triangle Rooftop Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(1090, 300);
    glVertex2f(1237, 400);
    glVertex2f(1385, 300);
    glEnd();


    // Door
    glBegin(GL_POLYGON);
    glColor3f(.1, .18, .2);
    glVertex2f(1130, 190);
    glVertex2f(1130, 280);
    glVertex2f(1190, 280);
    glVertex2f(1190, 190);
    glEnd();

    // Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(1130, 190);
    glVertex2f(1130, 280);
    glVertex2f(1190, 280);
    glVertex2f(1190, 190);
    glEnd();


    // Rectangular Window
    glBegin(GL_POLYGON);
    glColor3f(.21, .35, .5);
    glVertex2f(1240, 280);
    glVertex2f(1240, 240);
    glVertex2f(1355, 240);
    glColor3f(.35, .44, .6);
    glVertex2f(1355, 280);
    glEnd();

    // Rectangular Window Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(1240, 280);
    glVertex2f(1240, 240);
    glVertex2f(1355, 240);
    glVertex2f(1355, 280);
    glEnd();




    // School Building
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4 ,0.4);
    glVertex2f(400, 190);
    glVertex2f(1000, 190);
    glVertex2f(1000, 500);
    glColor3f(.6, .6, .6);
    glVertex2f(400, 500);
    glEnd();

    // School Building Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(400, 190);
    glVertex2f(1000, 190);
    glVertex2f(1000, 500);
    glVertex2f(400, 500);
    glEnd();

    // Triangle Rooftop
    glBegin(GL_TRIANGLES);
    glColor3f(.25, .15, .1);
    glVertex2f(380, 500);
    glVertex2f(700, 600);
    glVertex2f(1020, 500);
    glEnd();

    // Triangle Rooftop Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(380, 500);
    glVertex2f(700, 600);
    glVertex2f(1020, 500);
    glEnd();


    // School Door
    glBegin(GL_POLYGON);
    glColor3f(.7, .75, .75);
    glVertex2f(600, 190);
    glVertex2f(600, 280);
    glVertex2f(800, 280);
    glVertex2f(800, 190);
    glEnd();

    // School Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(600, 190);
    glVertex2f(600, 280);
    glVertex2f(800, 280);
    glVertex2f(800, 190);
    glEnd();

    // School Door Divider
    glBegin(GL_LINES);
    glColor3f(.1, .1, .1);
    glVertex2f(700, 280);
    glVertex2f(700, 190);
    glEnd();

    glLineWidth(2);

    glBegin(GL_LINES);
    glColor3f(.1,.1,.1);

    glVertex2f(690, 240);
    glVertex2f(690, 220);

    glVertex2f(710, 240);
    glVertex2f(710, 220);
    glEnd();

    glLineWidth(1);

    window();

    // School Board
    glBegin(GL_POLYGON);
    glColor3f(.75, .75, .75);
    glVertex2f(570, 530);
    glVertex2f(830, 530);
    glVertex2f(830, 470);
    glVertex2f(570, 470);
    glEnd();

    // School Board Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(570, 530);
    glVertex2f(830, 530);
    glVertex2f(830, 470);
    glVertex2f(570, 470);
    glEnd();

    print("HIGH SCHOOL", 0, 0, 0, 1, 590, 485, .2, .2, 1.5);


    // Tuition building
    glBegin(GL_POLYGON);
    glColor3f(.6, .75, .82);
    glVertex2f(25, 190);
    glVertex2f(300, 190);
    glColor3f(.5, .76, .8);
    glVertex2f(300, 360);
    glVertex2f(25, 360);
    glEnd();

    // Tuition Building Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(25, 190);
    glVertex2f(300, 190);
    glVertex2f(300, 360);
    glVertex2f(25, 360);
    glEnd();


    // Triangle Rooftop
    glBegin(GL_TRIANGLES);
    glColor3f(.25, .15, .1);
    glVertex2f(25, 360);
    glVertex2f(163, 450);
    glVertex2f(300, 360);
    glEnd();

    // Triangle Rooftop Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(25, 360);
    glVertex2f(163, 450);
    glVertex2f(300, 360);
    glEnd();

    // Tuition Board
    glBegin(GL_POLYGON);
    glColor3f(1, .9, .6);
    glVertex2f(50, 380);
    glVertex2f(180, 380);
    glVertex2f(180, 330);
    glVertex2f(50, 330);
    glEnd();

    // Tuition Board Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(50, 380);
    glVertex2f(180, 380);
    glVertex2f(180, 330);
    glVertex2f(50, 330);
    glEnd();

    print("TUITION", 0, 0, 0, 1, 58, 350, .15, .15, 1.3);

    // Tuition Door
    glBegin(GL_POLYGON);
    glColor3f(.28, .16, .1);
    glVertex2f(130, 190);
    glVertex2f(130, 295);
    glVertex2f(190, 295);
    glVertex2f(190, 190);
    glEnd();

    // Tuition Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(130, 190);
    glVertex2f(130, 295);
    glVertex2f(190, 295);
    glVertex2f(190, 190);
    glEnd();

    // Tuition Rectangular Right Window
    glBegin(GL_POLYGON);
    glColor3f(.22, .38, .5);
    glVertex2f(210, 280);
    glVertex2f(210, 240);
    glVertex2f(270, 240);
    glColor3ub(97, 131, 159);
    glVertex2f(270, 280);
    glEnd();

    // Tuition Rectangular Right Window Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(210, 280);
    glVertex2f(210, 240);
    glVertex2f(270, 240);
    glVertex2f(270, 280);
    glEnd();

    // Tuition Rectangular left Window
    glBegin(GL_POLYGON);
    glColor3f(.22, .38, .5);
    glVertex2f(50, 280);
    glVertex2f(50, 240);
    glVertex2f(110, 240);
    glColor3f(.4, .5, .6);
    glVertex2f(110, 280);
    glEnd();

    // Tuition Rectangular Right Window Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(50, 280);
    glVertex2f(50, 240);
    glVertex2f(110, 240);
    glVertex2f(110, 280);
    glEnd();


}


void stars()
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor4f(1, 1, 1, star_fade); // white
    for (int i = 0, j = 0; i < 50; i++)
        glVertex2f(a[i],b[i]);
    glEnd();
    glPointSize(1);
}

void student(double tx, double ty,double sx, double sy, double sr, double sg, double sb)
{
    glPushMatrix();
    glScalef(sx, sy, 0);
    glTranslatef(tx, ty, 0);
    // Shoes
    circleDrawing(1160, 120,1, 1, 1,1, 1,10,-90, 91);
    // ankle
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2f(1160, 120);
    glVertex2f(1170, 120);
    glVertex2f(1170, 135);
    glVertex2f(1160, 135);
    glEnd();

    // Pants
    glBegin(GL_POLYGON);
    glColor3f(.4, .4, 1);
    glVertex2f(1158, 135);
    glVertex2f(1172, 135);
    glVertex2f(1170, 190);
    glVertex2f(1160, 190);
    glEnd();

    // Shirt
    glBegin(GL_POLYGON);
    glColor3f(sr, sg, sb);
    glVertex2f(1155, 190);
    glVertex2f(1170, 190);
    glVertex2f(1170, 260);
    glVertex2f(1160, 260);
    glEnd();

    // shirt border
    glBegin(GL_LINE_LOOP);
    glColor3f(sr, sg, sb);
    glVertex2f(1155, 190);
    glVertex2f(1170, 190);
    glVertex2f(1170, 260);
    glVertex2f(1160, 260);
    glEnd();

    // Bag
    glBegin(GL_POLYGON);
    glColor3f(.2, .2, .2);
    glVertex2f(1170, 250);
    glVertex2f(1180, 245);
    glVertex2f(1185, 200);
    glVertex2f(1170, 195);
    glEnd();


    // Bag border
    glBegin(GL_LINE_LOOP);
    glColor3f(.2, .2, .2);
    glVertex2f(1170, 250);
    glVertex2f(1180, 245);
    glVertex2f(1185, 200);
    glVertex2f(1170, 195);
    glEnd();

    // Head
    circleDrawing(1164,273,0.9,0.7,0.4,1,1.4,12,0,360);

    // Hair
    circleDrawing(1167, 277,0, 0, 0,1, 1,14, -80, 180);

    // Eye
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    glVertex2f(1156, 270);
    glEnd();
    glPointSize(1);

    glPopMatrix();
}


// S_ID = 9 - High School

void hs()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    highSchool();
    stars();
    student(hsBoyX, hsBoyY, p,.5,1, 1, 1);
    print("Home to School to Tuition to Home",
          .1, .1, .1, fade, 220, 610, .3, .3, 1);
}

// S_ID = 10 - College Title
void CollegeTitle()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //Title
    print("College",1,1,1,fade,400-trans_x,450-trans_x,.3,.3,2);
}

// S_ID = 11 - College Speech

void clg_speech()
{

// Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    print("-> In college",1,1,1,fade,150,590,.25,.25,3);
    print("-> We are given two options to pursuit ",
          1, 1, 1, fade-1, 150, 530, .25, .25, 3);
    print("-> Engineering and Medical",
          1, 1, 1, fade-2, 150, 470, .25, .25, 3);
    print("-> Most students aren't able to keep pace",
          1, 1, 1, fade-3, 150, 410, .25, .25, 3);
    print("-> Thus fail to move on",
          1, 1, 1, fade-4, 150, 350, .25, .25, 3);

}

// section board draw

void clg_sec_board(double x, double y, double z, double sx, double sy, double sz, char *str)
{
    glPushMatrix();

    glScalef(sx, sy, sz);
    glTranslatef(x, y, z);

    // board
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2f(160, 500);
    glVertex2f(160, 470);
    glVertex2f(270, 470);
    glVertex2f(270, 500);
    glEnd();

    // board border

    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(160, 500);
    glVertex2f(160, 470);
    glVertex2f(270, 470);
    glVertex2f(270, 500);
    glEnd();

    print(str,0, 0, 0, 1, 170, 480, .1, .1, 2);

    glPopMatrix();
}

// Draw college environment
void clg_corridor()
{
    // Floor
    glBegin(GL_POLYGON);
    glColor3f(0.88,0.85,0.78);
    glVertex2f(-365,0);
    glVertex2f(1765,0);
    glColor3f(0.8,0.7,0.68);
    glVertex2f(775,200);
    glVertex2f(625,200);
    glEnd();


    glPointSize(1);
    // middle Wall
    glBegin(GL_POLYGON);
    glColor3f(.9,.9,.9);
    glVertex2f(625,200);
    glVertex2f(775,200);
    glVertex2f(775,450);
    glVertex2f(625,450);
    glEnd();

    // Middle Wall Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1,.1,.1);
    glVertex2f(625,200);
    glVertex2f(775,200);
    glVertex2f(775,450);
    glVertex2f(625,450);
    glEnd();



    //top
    glBegin(GL_POLYGON);
    glColor3f(.9,.9,.9);
    glVertex2f(625,450);
    glVertex2f(775,450);
    glColor3f(.95,.95,.95);
    glVertex2f(1400,800);
    glVertex2f(0,800);
    glEnd();

    // top Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(625, 450);
    glVertex2f(775, 450);
    glVertex2f(1400, 800);
    glVertex2f(0, 800);
    glEnd();


    // Left Wall
    glBegin(GL_POLYGON);
    glColor3f(.95, .95, .95);
    glVertex2f(0, 75);
    glVertex2f(625, 200);
    glVertex2f(625, 450);
    glVertex2f(0, 800);
    glEnd();

    // Left Wall Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(0, 75);
    glVertex2f(625, 200);
    glVertex2f(625, 450);
    glVertex2f(0, 800);
    glEnd();

    // Right Wall
    glBegin(GL_POLYGON);
    glColor3f(.9, .9, .9);
    glVertex2f(775, 200);
    glVertex2f(1400, 75);
    glVertex2f(1400, 800);
    glVertex2f(775, 450);
    glEnd();

    // Right Wall Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(775, 200);
    glVertex2f(1400, 75);
    glVertex2f(1400, 800);
    glVertex2f(775, 450);
    glEnd();

    ///////////////////////

    // First Door
    glBegin(GL_POLYGON);
    glColor3f(.84, .84, .84);
    glVertex2f(150, 104);
    glVertex2f(350, 144);
    glVertex2f(350, 481);
    glVertex2f(150, 548);
    glEnd();

    // First Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(150, 104);
    glVertex2f(350, 144);
    glVertex2f(350, 481);
    glVertex2f(150, 548);
    glEnd();

    // First Wooden Door
    glBegin(GL_POLYGON);
    glColor3f(.22, .14, .1);
    glVertex2f(150, 104);
    glVertex2f(335, 158);
    glVertex2f(335, 472);
    glVertex2f(150, 548);
    glEnd();

    // First Wooden Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(150, 104);
    glVertex2f(335, 158);
    glVertex2f(335, 472);
    glVertex2f(150, 548);
    glEnd();

    // Door Knob
    circleDrawing(320, 320,.95,.75,.1,1, 1,5, 0, 360);

    // draw section board
    clg_sec_board(-20, 20, 0,1, 1, 1,"Science-A");

    // Second Door
    glBegin(GL_POLYGON);
    glColor3f(.85, .85, .85);
    glVertex2f(450, 164);
    glVertex2f(550, 184);
    glVertex2f(550, 413);
    glVertex2f(450, 447);
    glEnd();

    // Second Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(450, 164);
    glVertex2f(550, 184);
    glVertex2f(550, 413);
    glVertex2f(450, 447);
    glEnd();

    // Second Wooden Door
    glBegin(GL_POLYGON);
    glColor3f(.22, .14, .1);
    glVertex2f(450, 164);
    glVertex2f(540, 194);
    glVertex2f(540, 403);
    glVertex2f(450, 447);
    glEnd();

    // Second Wooden Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(450, 164);
    glVertex2f(540, 194);
    glVertex2f(540, 403);
    glVertex2f(450, 447);
    glEnd();

    circleDrawing(530, 320,.95,.75,.1,1, 1,5, 0, 360);

    // science B

    clg_sec_board(350, 50, 0,.8, .8, 1,"Science-B");


    // right side

    // First Door
    glBegin(GL_POLYGON);
    glColor3f(.85, .85, .85);
    glVertex2f(1049, 144);
    glVertex2f(1250, 104);
    glVertex2f(1250, 548);
    glVertex2f(1049, 481);
    glEnd();

    // First Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(1049, 144);
    glVertex2f(1250, 104);
    glVertex2f(1250, 548);
    glVertex2f(1049, 481);
    glEnd();

    // First Wooden Door
    glBegin(GL_POLYGON);
    glColor3f(.22, .13, .1);
    glVertex2f(1250, 104);
    glVertex2f(1065, 158);
    glVertex2f(1065, 472);
    glVertex2f(1250, 548);
    glEnd();

    // First Wooden Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(1250, 104);
    glVertex2f(1065, 158);
    glVertex2f(1065, 472);
    glVertex2f(1250, 548);
    glEnd();

    clg_sec_board(1000, 10, 0,1, 1, 1,"Arts");

    // Door Knob
    circleDrawing(1080,320,.95,.75,.1,1, 1,5,0,360);

    // Second Door
    glBegin(GL_POLYGON);
    glColor3f(.85, .85, .85);
    glVertex2f(850, 184);
    glVertex2f(950, 164);
    glVertex2f(950, 447);
    glVertex2f(850, 413);
    glEnd();

    // Second Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(850, 184);
    glVertex2f(950, 164);
    glVertex2f(950, 447);
    glVertex2f(850, 413);
    glEnd();

    // Second Wooden Door
    glBegin(GL_POLYGON);
    glColor3f(.22, .13, .1);
    glVertex2f(950, 164);
    glVertex2f(860, 194);
    glVertex2f(860, 403);
    glVertex2f(950, 447);
    glEnd();

    // Second Wooden Door Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(950, 164);
    glVertex2f(860, 194);
    glVertex2f(860, 403);
    glVertex2f(950, 447);
    glEnd();

    // commerce
    clg_sec_board(950,50,0,.8,.8,1,"Commerce");


    // Door Knob
    circleDrawing(870,300,.95,.75,.1,1, 1,3,0,360);


    // Board Hanging Line
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(600, 800);
    glVertex2f(600, 750);
    glVertex2f(800, 800);
    glVertex2f(800, 750);
    glEnd();
    glLineWidth(1);

    // Board Border
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(498, 750);
    glVertex2f(498, 600);
    glVertex2f(902, 600);
    glVertex2f(902, 750);
    glEnd();

    // Board
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 1);
    glVertex2f(500, 748);
    glColor3f(0, 0.4, 0.9);
    glVertex2f(500, 602);
    glVertex2f(900, 602);
    glColor3ub(0, 0.5, 1);
    glVertex2f(900, 748);
    glEnd();

    print("College",1,1,1,1,590,670,.3,.3,4);
}


// S_ID = 12 - College Scene
void college()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    clg_corridor();
    // Boy
    student(trans_x, trans_y,1.4, 1.4,.3, .3, .3);
}

// S_ID = 13 -  varsity Title Scene
void varTitle()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    print("Engineering varsity",1,1,1,fade,400-trans_x,400,.3,.3,2);
}


// S_ID = 14 - varsity first speech

void var_speech1()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    print("Many chase their dreams to",1,1,1,fade,400,450,.25,.25,3);

    print("Engineering varsity",1,1,1,fade-1.3,470,400,.25,.25,3);
}

// S_ID = 15 - varsity second speech
void var_speech2()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    print("Then after 4 years of struggle",1,1,1,fade,350,450,.25,.25,3);
    print("we graduate",1,1,1,fade,550,400,.25,.25,3);
}

// Graduate student draw function
void Graduated(double tx, double ty,double sx, double sy)
{
    glPushMatrix();

    glScalef(sx,sy,0);
    glTranslatef(tx,ty,0);

    // Shoes
    circleDrawing(1160,120,0,0,0,1,1,10,-90,91);

    // Shoe Extension
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(1160, 120);
    glVertex2f(1170, 120);
    glVertex2f(1170, 135);
    glVertex2f(1160, 135);
    glEnd();

    // Pants
    glBegin(GL_POLYGON);
    glColor3f(.3, .3, .3);
    glVertex2f(1158, 135);
    glVertex2f(1172, 135);
    glVertex2f(1170, 190);
    glVertex2f(1160, 190);
    glEnd();

    // Shirt
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(1155, 190);
    glVertex2f(1170, 190);
    glVertex2f(1170, 260);
    glVertex2f(1160, 260);
    glEnd();

    // Bag
    glBegin(GL_POLYGON);
    glColor3ub(156, 86, 47);
    glVertex2f(1170, 250);
    glVertex2f(1180, 245);
    glVertex2f(1185, 200);
    glVertex2f(1170, 195);
    glEnd();

    // Head
    circleDrawing(1164,273,0.95,.8,.45,1,1.4,12,0,360);
    // Hair
    circleDrawing(1167,277,0,0,0,1,1,14,-80,180);

    // Graduation Cap
    glBegin(GL_POLYGON);
    glColor3f(.2, .2, .2); // Barely Black
    glVertex2f(1144, 282);
    glVertex2f(1190, 268);
    glVertex2f(1189, 285);
    glVertex2f(1165, 297);
    glEnd();

    // Graduation Cap Thread
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glColor3f(.95, .95, .18);
    glVertex2f(1173, 281);
    glVertex2f(1186, 272);
    glVertex2f(1190, 258);
    glEnd();
    glLineWidth(1);
    circleDrawing(1190,258,.92,0.92,.2,1,1.2,3,0,360);

    // Eye
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    glVertex2f(1156, 270);
    glEnd();
    glPointSize(1);

    glPopMatrix();
}

// Function to build varsity environment
void var_build()
{
    // Background
    glBegin(GL_POLYGON);
    glColor3f(.46, .67, .9); // Sky Blue
    glVertex2f(0, 800);
    glVertex2f(1400, 800);
    glColor3f(.32, .64, .18); // Green Grass
    glVertex2f(1400, 125);
    glVertex2f(0, 125);
    glEnd();

    // Road

    glBegin(GL_POLYGON);
    glColor3f(.2, .2, .2);
    glVertex2f(0, 0);
    glVertex2f(1400, 0);
    glVertex2f(1400, 0);
    glVertex2f(0, 0);
    glEnd();

    // lines road

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);

    glVertex2f(0, 120);
    glVertex2f(1400, 120);

    glVertex2f(0, 5);
    glVertex2f(1400, 5);

    glVertex2f(0, 60);
    glVertex2f(100, 60);

    glVertex2f(120, 60);
    glVertex2f(220, 60);

    glVertex2f(240, 60);
    glVertex2f(340, 60);

    glVertex2f(360, 60);
    glVertex2f(460, 60);

    glVertex2f(480, 60);
    glVertex2f(580, 60);

    glVertex2f(600, 60);
    glVertex2f(700, 60);

    glVertex2f(720, 60);
    glVertex2f(820, 60);

    glVertex2f(840, 60);
    glVertex2f(940, 60);

    glVertex2f(960, 60);
    glVertex2f(1060, 60);

    glVertex2f(1080, 60);
    glVertex2f(1180, 60);

    glVertex2f(1200, 60);
    glVertex2f(1300, 60);

    glVertex2f(1320, 60);
    glVertex2f(1420, 60);
    glEnd();
    glLineWidth(1);


    //  building

    // Building
    glBegin(GL_POLYGON);
    glColor3f(.7, .7, .7);
    glVertex2f(300, 125);
    glColor3f(.7, .7, .7);
    glVertex2f(1100, 125);
    glColor3f(.6, .6, .6);
    glVertex2f(1100, 600);
    glColor3f(.5, .5, .5);
    glVertex2f(300, 600);
    glEnd();


    // Triangle Rooftop
    glBegin(GL_TRIANGLES);
    glColor3f(.5, .5, .5);
    glVertex2f(290, 600);
    glColor3f(.6, .6, .6);
    glVertex2f(700, 790);
    glColor3f(.5, .5, .5);
    glVertex2f(1110, 600);
    glEnd();

    // Triangle Rooftop Border
    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(290, 600);
    glVertex2f(700, 790);
    glVertex2f(1110, 600);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0, .1, .2);

    // Vertical

    glVertex2f(300, 600);
    glVertex2f(300, 125);

    glVertex2f(375, 600);
    glVertex2f(375, 125);

    glVertex2f(460, 600);
    glVertex2f(460, 125);

    glVertex2f(550, 600);
    glVertex2f(550, 125);

    glVertex2f(625, 600);
    glVertex2f(625, 125);

    glVertex2f(700, 600);
    glVertex2f(700, 125);

    glVertex2f(775, 600);
    glVertex2f(775, 125);

    glVertex2f(850, 600);
    glVertex2f(850, 125);

    glVertex2f(930, 600);
    glVertex2f(930, 125);

    glVertex2f(1010, 600);
    glVertex2f(1010, 125);

    glVertex2f(1100, 600);
    glVertex2f(1100, 125);

    // Horizontal
    glVertex2f(300, 125);
    glVertex2f(1100, 125);

    glVertex2f(300, 177.5);
    glVertex2f(1100, 177.5);

    glVertex2f(300, 230);
    glVertex2f(1100, 230);

    glVertex2f(300, 282.5);
    glVertex2f(1100, 282.5);

    glVertex2f(300, 335);
    glVertex2f(1100, 335);

    glVertex2f(300, 387.5);
    glVertex2f(1100, 387.5);

    glVertex2f(300, 440);
    glVertex2f(1100, 440);

    glVertex2f(300, 492.5);
    glVertex2f(1100, 492.5);

    glVertex2f(300, 545);
    glVertex2f(1100, 545);
    glEnd();

    // Door
    glBegin(GL_POLYGON);
    glColor3f(.2, .5, .5);
    glVertex2f(626, 125);
    glColor3f(.3, .4, .4);
    glVertex2f(774, 125);
    glColor3f(.4, .4, .5);
    glVertex2f(774, 282);
    glColor3f(.4, .4, .5);
    glVertex2f(626, 282);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, .11, .23);
    glVertex2f(700, 282);
    glVertex2f(700, 125);
    glEnd();

    glLineWidth(2);

    glBegin(GL_LINES);
    glColor3f(1,1,1);

    glVertex2f(690, 210);
    glVertex2f(690, 190);

    glVertex2f(710, 210);
    glVertex2f(710, 190);
    glEnd();

    glLineWidth(1);

    //// board

    glBegin(GL_POLYGON);
    glColor3f(.2, .4, .5);
    glVertex2f(520, 610);
    glVertex2f(880, 610);
    glColor3f(.4, .5, .6);
    glVertex2f(880, 700);
    glVertex2f(520, 700);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(625, 600);
    glVertex2f(625, 620);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(775, 600);
    glVertex2f(775, 620);
    glEnd();
    glLineWidth(1);

    print("Engineering University",1,1, 1,1,530,650,.15,.15,2);

    // Red Boy
    student(trans_x1, trans_y1,.75,.75,1,0,0);
    // Green Boy
    student(trans_x2, trans_y1,-.75, .75,0, 1, 0);
    // Red Graduate
    Graduated(trans_x2, trans_y2,.75, .75);
    // Green Graduate
    Graduated(trans_x2-110,trans_y2,.75,.75);
}


// S_ID = 16 - varsity scene
void varsity()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    var_build();
}

// S_ID = 17 - Office Title Scene
void officeTitle()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Story Title
    print("Office",1, 1, 1,fade,400-trans_x,500,.3,.3,2);
}

double r1, r2, r3, r4;

// Function to draw office
void OF()
{
    // floor
    glBegin(GL_POLYGON);
    glColor3f(.3, .3, .3);
    glVertex2f(-500, 0);
    glVertex2f(1400, 0);
    glVertex2f(1400, 150);
    glVertex2f(50, 150);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(-500, 0);
    glVertex2f(1400, 0);
    glVertex2f(1400, 150);
    glVertex2f(50, 150);
    glEnd();

    // left wall

    glBegin(GL_POLYGON);
    glColor3f(.7, .7, .7);
    glVertex2f(0, 75);
    glVertex2f(50, 150);
    glVertex2f(50, 800);
    glVertex2f(0, 800);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(0, 75);
    glVertex2f(50, 150);
    glVertex2f(50, 800);
    glVertex2f(0, 800);
    glEnd();

    // middle wall

    glBegin(GL_POLYGON);
    glColor3f(.8, .8, .8);
    glVertex2f(50, 150);
    glVertex2f(1400, 150);
    glVertex2f(1400, 800);
    glVertex2f(50, 800);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(.1, .1, .1);
    glVertex2f(50, 150);
    glVertex2f(1400, 150);
    glVertex2f(1400, 800);
    glVertex2f(50, 800);
    glEnd();


    // board of software company

    glBegin(GL_POLYGON);
    glColor3f(.2, .4, .4);
    glVertex2f(100, 700);
    glVertex2f(420, 700);
    glColor3f(.4, .6, .6);
    glVertex2f(420, 600);
    glVertex2f(100, 600);
    glEnd();

    print("Software Company",1,1,1,1,110,650,.18,.18,2);

    // AC

    // body
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2f(600, 675);
    glVertex2f(1000, 675);
    glVertex2f(1000, 750);
    glVertex2f(600, 750);
    glEnd();

    //side
    glBegin(GL_POLYGON);
    glColor3f(.95, .95, .95);
    glVertex2f(600, 675);
    glVertex2f(610, 660);
    glVertex2f(1010, 660);
    glVertex2f(1000, 675);
    glEnd();

    // low

    glBegin(GL_POLYGON);
    glColor3f(.9, .9, .9);
    glVertex2f(1000, 750);
    glVertex2f(1010, 720);
    glVertex2f(1010, 660);
    glVertex2f(1000, 675);
    glEnd();

    // low panel
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(.6, .6, .6);
    glVertex2f(620, 666);
    glVertex2f(980, 666);
    glEnd();
    glLineWidth(1);


    // bubble leads
    circleDrawing(865, 410, .95, .95, .95, 1, 1, r1, 0, 360);
    circleDrawing(900, 430, .95, .95, .95, 1, 1, r2, 0, 360);
    circleDrawing(935, 450, .95, .95, .95, 1, 1, r3, 0, 360);

    // bubble
    circleDrawing(1000, 480, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1040, 500, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1080, 500, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1120, 500, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1160, 500, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1200, 480, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1040, 460, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1080, 460, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1120, 460, .95, .95, .95, 1, 1, r4, 0, 360);
    circleDrawing(1160, 460, .95, .95, .95, 1, 1, r4, 0, 360);

    print("I may be able to do",0, 0, 0, fade, 1000, 480, .09, .09, 1);
    print("better as a journalist",0, 0, 0, fade, 1000, 460, .09, .09, 1);
}

// Function to draw worker
void worker(double x, double y, double r, double g, double b)
{

    glPushMatrix();

    glTranslatef(x,y,0);
    // mouth
    circleDrawing(300, 380,0.8, 0.6, 0.4, 1,1.2,30, 0, 360);

    // hair
    circleDrawing(300, 400,.1, .1, .1, 1, .6, 32, -90, 90);
    circleDrawing(320, 390, .1, .1, .1,.6, .6,35, 0, 180);

    // Left Eye
    circleDrawing(298, 383,1, 1, 1,1, 1,5, 0, 360);
    circleDrawing(297, 382,.1, .1, .1,1, 1,2, 0, 360);

    // Right Eye
    circleDrawing(278, 383,1, 1, 1,1, 1,5, 0, 360);
    circleDrawing(277, 382,.1, .1, .1,1, 1,2, 0, 360);

    // Body
    circleDrawing(300, 275,r, g, b,.6, .8,80, 0, 360);

    // table

    // front
    glBegin(GL_POLYGON);
    glColor3f(.38, .19, .08);
    glVertex2f(100, 100);
    glVertex2f(500, 100);
    glVertex2f(500, 250);
    glVertex2f(100, 250);
    glEnd();

    // top
    glBegin(GL_POLYGON);
    glColor3f(.3, .18, .04);
    glVertex2f(100, 250);
    glVertex2f(500, 250);
    glVertex2f(525, 275);
    glVertex2f(125, 275);
    glEnd();

    // right
    glBegin(GL_POLYGON);
    glColor3f(.22, .1, .04);
    glVertex2f(500, 100);
    glVertex2f(525, 150);
    glVertex2f(525, 275);
    glVertex2f(500, 250);
    glEnd();

    // Monitor
    glBegin(GL_POLYGON);
    glColor3f(.3, .3, .3);
    glVertex2f(210, 280);
    glVertex2f(400, 280);
    glVertex2f(400, 380);
    glVertex2f(210, 380);
    glEnd();

    // Logo
    circleDrawing(300, 325,.2, .2, .2,1, 1,10, 0, 360);

    // Monitor Stand
    glBegin(GL_POLYGON);
    glColor3f(.1, .1, .1);
    glVertex2f(290, 280);
    glVertex2f(280, 260);
    glVertex2f(320, 260);
    glVertex2f(310, 280);
    glEnd();

    // Mouse
    circleDrawing(240, 262,.6, .6, .6,1, 1,10, -90, 90);

    glPopMatrix();
}


// S_ID = 17 - Office Scene
void office()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    OF();
    worker(0,0,.8,.2,.2);
    worker(500,0,0,.7,.5);
    worker(1000,0,.2,.4,.7);
}

// Tell morals of the story
void morals()
{
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Summary Title

    if(fade<=2)
        print("The moral of the story is...",
              1, 1, 1, fade, 400, 500, .2, .2, 1.5);

    else if(fade<=3)
        print("A child can choose to be either",
              1, 1, 1, fade-2, 350, 500, .2, .2, 1.5);

    else if(fade<=4)
        print("An engineer",
              1, 1, 1, fade-3, 580, 500, .2, .2, 1.5);

    else if(fade<=5)
        print("A pilot",
              1, 1, 1, fade-4, 600, 500, .2, .2, 1.5);

    else if(fade<=6)
        print("A scientist",
              1, 1, 1, fade-5, 580, 500, .2, .2, 1.5);

    else if(fade<=7)
        print("An artist",
              1, 1, 1, fade-6, 600, 500, .2, .2, 1.5);

    else if(fade<=8)
        print("He/she could be a superhero if they wished to be",
              1, 1, 1, fade-7, 200, 500, .2, .2, 1.5);

    else if(fade<=9)
        print("It will go a long way into their future in shaping them as",
              1, 1, 1, fade-8, 100, 500, .2, .2, 1.5);

    else if(fade<=10)
        print("better human beings.",
              1, 1, 1, fade-9, 510, 500, .2, .2, 1.5);

    else if(fade<=11)
        print("If we tell a fish to swim, ",
              1, 1, 1, fade-10, 400, 500, .2, .2, 1.5);

    else if(fade<=12)
        print("it spends its life thinking it is stupid",
              1, 1, 1, fade-11, 330, 500, .2, .2, 1.5);

    else if(fade<=13)
        print("So, Let people explore",
              1, 1, 1, fade-12, 480, 500, .2, .2, 1.5);

    else if(fade<=14)
        print("Let them ask questions",
              1, 1, 1, fade-13, 480, 500, .2, .2, 1.5);

    else if(fade<=15)
        print("Let them be better humans",
              1, 1, 1, fade-14, 480, 500, .2, .2, 1.5);

    else
        print("The End !!!",
              1, 1, 1, fade-15, 540, 500, .2, .2, 1.5);

}

// Function to Render Scene
void curScreen()
{
    // Select which scene is playing
    switch (s_ID)
    {
    case 0:
        intro();
        break;
    case 1:
        kgTitle();
        break;
    case 2:
        kg_speech();
        break;
    case 3:
        kg();
        break;
    case 4:
        psTitle();
        break;
    case 5:
        ps_speech();
        break;
    case 6:
        ps();
        break;
    case 7:
        hsTitile();
        break;
    case 8:
        hs_speech();
        break;
    case 9:
        hs();
        break;
    case 10:
        CollegeTitle();
        break;
    case 11:
        clg_speech();
        break;
    case 12:
        college();
        break;
    case 13:
        varTitle();
        break;
    case 14:
        var_speech1();
        break;
    case 15:
        varsity();
        break;
    case 16:
        var_speech2();
        break;
    case 17:
        officeTitle();
        break;
    case 18:
        office();
        break;
    case 19:
        morals();
        break;
    default:
        exit(0);
    }

    // glFush sends it to the Display Buffer
    glFlush();
}

// Animator Updation Function
void update(int)
{
    // for pause check
    if(pause)
    {
        glutPostRedisplay();
    }
    else
    {
        // Introduction
        if (s_ID == 0)
        {
            if (fade < 3)
                fade += .01;
            else
            {
                fade=0;
                s_ID++;
            }
        }


        // kg Title Screen
        if (s_ID == 1)
        {
            if (trans_x < 100)
                trans_x += 1;
            if (fade < 2.5)
                fade += .03;
            else
            {
                trans_x = 0;
                fade=0;
                s_ID++; //update scene
            }

        }
        // kg_speech
        if (s_ID == 2)
        {
            if (fade <= 4)
                fade += .01;
            else
            {
                fade=0;
                s_ID++;
            }
        }

        // kg
        if (s_ID == 3)
        {
            if (fade <= 3.2)
                fade += .007;
            else
            {
                fade=0;
                s_ID++;
            }
        }


        // Primary School Title Screen
        if (s_ID == 4)
        {
            if (trans_x < 100)
                trans_x += 1;
            if (fade < 2)
                fade += .025;
            else
            {
                trans_x = 0;
                fade=0;
                s_ID++; //update scene
            }
        }

        // pr_speech
        if (s_ID == 5)
        {
            if (fade <= 3.2)
                fade += .01;
            else
            {
                fade=0;
                s_ID++;
            }
        }

        // Primary School
        if (s_ID == 6)
        {
            // background boy and football move
            if (trans_x < 40 && f)
                trans_x += .4;
            else if(trans_x>=0)
            {
                f=0;
                trans_x -=.4;
            }
            else
            {
                f=1;
            }

            // for text appear
            if(fade<5)
            {
                fade+=0.01;
            }
            else
            {
                trans_x = 0;
                fade=0;
                s_ID++; //update scene
            }

        }

        // High School Title Screen
        if (s_ID == 7)
        {
            if (trans_x < 100)
                trans_x += 1;
            if (fade < 2.2)
                fade += .025;
            else
            {
                trans_x = 0;
                fade=0;
                s_ID++; //update scene
            }
        }

        // hs_speech
        if (s_ID == 8)
        {
            if (fade <= 4.2)
                fade += .01;
            else
            {
                fade=0;
                f1=f2=f3=0;
                s_ID++;
            }
        }

        // High School
        if (s_ID == 9)
        {
            if (!f1)
            {
                hsBoyY -= 5000;  // back in the picture from out of window
                f1=1;
            }

            // home to school

            if (f1 && !f2)
            {
                if (hsBoyX >= 300)
                {
                    hsBoyX -= 6;
                }
                else
                {
                    hsBoyY += 5000; // out of the picture
                    f2=1;
                }
            }

            // sun move, light change
            if (f1 && f2 && !f3 && !sunSet)
            {
                if (sun_r <= 1)
                    sun_r += .0004;
                if (sun_g <= 1)
                    sun_g += .0004;
                if (sun_b <= 1)
                    sun_b += .0004;

                if (grass_r <= 1)
                    grass_r += .0003;
                if (grass_g <= 1)
                    grass_g += .0003;
                if (grass_b >= 1)
                    grass_b += .0003;

                if (sky_r <= 0)
                    sky_r += .0004;
                if (sky_g >= 0)
                    sky_g -= .0004;
                if (sky_b >= 0)
                    sky_b -= .0004;

                if (sunMove < 1100) // until sun set
                    sunMove += 2;
                else
                    sunSet = true;

                if (sunMove > 500) // noon condition
                    noon = true;
            }

            // school to tuition // if noon
            if (noon && !f4)
            {
                if (hsBoyY != 220)
                    hsBoyY -= 5000;

                if (hsBoyX >= -850)
                    hsBoyX -= 6;
                else
                {
                    hsBoyY += 5000;
                    f4 = true;
                }
            }


            // when tuition // out of picture
            if (f4)
            {
                if (hsBoyY != 5220 && !tuition_done)
                {
                    hsBoyY += 5000;
                    tuition_done = true;
                    p*=-1;
                    hsBoyX = -1500;
                }
            }

            // sunset , then reappear student
            if (sunSet)
            {
                if (star_fade <= 2)
                    star_fade += 0.005;

                if (hsBoyY != 220)
                {
                    hsBoyY -= 5000;
                    p*=-1;
                }
                f5 = true;
            }

            if (f5)
            {
                //tuition to home
                if (hsBoyX > -3500)
                    hsBoyX -= 6;
                else
                {
                    if (hsBoyY != 5220)
                        hsBoyY += 5000;
                }

                if (fade < 2)
                {
                    fade+= .005;
                }
                else
                {
                    fade=0;
                    s_ID++;
                }
            }
        }

        // College Title Screen
        if (s_ID == 10)
        {
            if (trans_x < 100)
                trans_x += .8;
            else
            {
                trans_x = 0;
                fade=0;
                s_ID++;
            }

            if (fade < 1)
                fade += .01;

        }

        // clg_speech
        if (s_ID == 11)
        {
            if (fade <= 6)
                fade += .01;
            else
            {
                fade=0;
                trans_x= -550;
                trans_y= -50;
                s_ID++;
            }
        }

        // College
        if (s_ID == 12)
        {
            if (trans_x >= -930)
                trans_x -= .7;
            else
            {
                trans_x = 0;
                trans_y = 0;
                s_ID++;
            }
            if (trans_y <= -20)
                trans_y += .07;
        }

        // varsity Title Screen
        if (s_ID == 13)
        {
            if (trans_x < 100)
                trans_x += .7;
            else
            {
                fade=0;
                trans_x=0;
                s_ID++;
            }

            if (fade < 1)
                fade += .025;
        }

        // var_speech
        if (s_ID == 14)
        {
            if (fade <= 3)
                fade += .02;
            else
            {
                fade=0;
                s_ID++;
            }
        }
        // varsity student walk
        if (s_ID == 15)
        {
            // if graduation complete got to left side together
            // other wise came from two different side to varsity
            if (graduation)
            {
                if (trans_y2 != 40)
                {
                    trans_y2 -= 1000;
                }
                if (trans_x2 >= -1200)
                    trans_x2 -= 2;
                else
                {
                    s_ID+=2;
                }
            }
            else
            {
                if (trans_x1 >= -180)
                    trans_x1 -= 2;
                if (trans_x2 >= -2050)
                    trans_x2 -= 2;
                // out of window
                if (trans_x1 <= -180 && trans_x2 <= -2050 && !graduation)
                {
                    trans_y1 += 1000;
                    graduation = true;
                    trans_x2 = -180;
                    s_ID++;

                }
            }
        }
        // varsity speech 2
        if(s_ID == 16)
        {
            if (fade <= 2)
                fade += .01;
            else
            {
                fade=0;
                s_ID--;
            }
        }

        // office title
        if (s_ID == 17)
        {
            if (trans_x < 100)
                trans_x += .7;
            else
            {
                trans_x = 0;
                fade=0;
                f1=f2=f3=f4=0;
                s_ID++;
            }

            if (fade < 1)
                fade += .01;
        }

        // radius for bubble

        if (s_ID == 18)
        {
            if (!f1)
            {
                if (r1 <= 10)
                    r1 += .25;
                else
                    f1 = true;
            }

            if (f1 && !f2)
            {
                if (r2 <= 12)
                    r2 += .25;
                else
                    f2 = true;
            }

            if (f1 && f2 && !f3)
            {
                if (r3 <= 14)
                    r3 += .25;
                else
                    f3 = true;
            }

            if (f1 && f2 && f3 && !f4)
            {
                if (r4 <= 30)
                    r4 += .5;
                else
                    f4 = true;
            }

            if (f1 && f2 && f3 && f4)
            {
                if (fade <= 1)
                    fade += .005;
                else
                {
                    f1=f2=f3=f4=0;
                    s_ID++;
                    fade=.2;
                }
            }
        }

        // Morals
        if (s_ID == 19)
        {
            if (fade < 18)
                fade += .007;
            else
                s_ID++;
        }

        // Recalls the Display Function
        glutPostRedisplay();

        // Creates a Timer of 25ms
        glutTimerFunc(25, update, 0);

    }

}


// Function to Initialize Screen
void initializeScreen()
{
    //  model view matrix mode
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //2D orthographic projection matrix
    gluOrtho2D(0, 1400, 0, 800);
}

// star create

void star_gen()
{
    //40 starts
    for(int i = 0; i < 40; i++)
    {
        a[i] = rand()%(int)(1400 - 0);
        b[i] = 600 +(rand()%(int)(800-600));
    }
}

void handleKeypress(unsigned char key,int x, int y )
{
    switch (key)
    {
        case 27: //Escape key
            exit(0); //Exit the program
            break;
        case 'p':
        {
            pause = !pause;
            break;
        }
    }

    glutPostRedisplay(); // current window redisplay
    // Creates a Timer of 25ms
    glutTimerFunc(25, update, 0);
}

// Main Function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    // buffer and color
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    // window position
    glutInitWindowPosition(0, 0);
    //window size
    glutInitWindowSize(1400, 800);
    // creating window
    glutCreateWindow("The True picture of Education in our society");

    // generating stars for future use
    star_gen();

    //Enables Transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    // Enable Smoothening
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Display Function
    glutDisplayFunc(curScreen);
    // every 20 milliseconds, update function is called
    glutTimerFunc(20, update, 0);

    glutKeyboardFunc(handleKeypress);

    initializeScreen();

    glutMainLoop();


    return 0;
}
