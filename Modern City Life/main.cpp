 /*
Farhan Sadik Ferdous  ID : 20-42072-1
Tapu Biswas           ID : 20-42073-1
*/
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <cstdio>
#include <MMSystem.h>


bool rain=false;


GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.1f;
GLfloat speed2 = 0.15f;
GLfloat speed3 = 0.02f;


//Moving Right
void update(int value)
{
    if(position > 2)

    position = -2.0f;
    position += speed;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);

}


//Moving Left
void update2(int value)
{
    if(position2 < -2.0)

    position2 = 2.0f;
    position2 -= speed2;

	glutPostRedisplay();
	glutTimerFunc(100, update2, 0);
}


//Moving Down(Rain)
void update3 (int value) {

if(position3 < -1.0)
        position3 = 1.0f;

    position3 -= speed3;


	glutPostRedisplay();


	glutTimerFunc(100, update3, 0);
}

//MouseHandle
void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			speed2 += 0.1f;
		}

	}

	else if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			speed -= 0.1f;
			speed2 -= 0.1f;
		}

	}

	glutPostRedisplay();
}


//Rain
void rainf()
{
    int i=0,j=0;
    float x,y;
    x=-1.0f;
    y=2.0f;

    while(j<=100)
    {
        x = -1.0f;
        while(i<=100)
        {
            glBegin(GL_LINES);
            glColor3f(0.313, 0.560, 0.713);
            glVertex2f(x,y);
            glVertex2f(x-0.01f,y-0.01f);
            glEnd();

            x=x+0.02f;
            i++;
        }
        y = y-0.05f;
        j++;
        i=0;
    }
}

//Timer Function
void Timer(int i)
{
    glutPostRedisplay();
    glutTimerFunc(26, Timer, 0);
}


//Day
void day()
{
    glClearColor(0.0f, 0.8f, 1.0f,1.0f);
    glutPostRedisplay();
}


//Night
void night()
{
    glClearColor(0.1f, 0.1f, 0.1f,1.0f);
    glutPostRedisplay();
}


//Cloud
void cloud()
{

    GLfloat x = -0.85f ;
    GLfloat y = 0.9f;
    GLfloat rad = 0.03f;
    int tri = 40;
    GLfloat cal = 2.0f * 3.1416f;

    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255,250,250);
        glVertex2f(x,y);
        for (int i=0;i<=tri;i++) {
        glVertex2f(
        x + (rad* cos(i*cal / tri)),
        y + (rad* sin(i*cal / tri))
        );
        }

    glEnd();


    GLfloat x2 = -0.75f ;
    GLfloat y2 = 0.9f;
    int tri2 = 40;
    GLfloat cal2 = 2.0f * 3.1416f;

    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255,250,250);
        glVertex2f(x2,y2);
        for (int i=0;i<=tri2;i++) {
        glVertex2f(
        x2 + (rad* cos(i*cal2 / tri2)),
        y2 + (rad* sin(i*cal2 / tri2))
        );
        }

    glEnd();


    GLfloat x3 = -0.8f ;
    GLfloat y3 = 0.9f;
    GLfloat radi = 0.04f;
    int tri3 = 40;

    GLfloat cal3 = 2.0f * 3.1416f;

    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255,250,250);
        glVertex2f(x3,y3);
        for (int i=0;i<=tri3;i++) {
        glVertex2f(
        x3 + (radi* cos(i*cal3 / tri3)),
        y3 + (radi* sin(i*cal3 / tri3))
        );
        }

    glEnd();
}

//Car1
void car1 ()
{
    //CarBody
    glBegin(GL_POLYGON);
        glColor3ub(96, 123, 139);
        glVertex2f(-0.6f, -0.0f);
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(0.4f,  0.4f);
        glVertex2f(0.6f,  0.2f);
        glVertex2f(0.6f,  0.0f);

    glEnd();

    //Car glass
    glBegin(GL_POLYGON);
        glColor3ub(211, 211, 211);
        glVertex2f( -0.04f,  0.2f);
        glVertex2f( -0.04f, 0.35f);
        glVertex2f(-0.37f, 0.35f);
        glVertex2f(-0.52f,  0.2f);

    glEnd();

    glBegin(GL_POLYGON);
      glColor3ub(211, 211, 211);
      glVertex2f( 0.04f,  0.2f);
      glVertex2f( 0.04f, 0.35f);
      glVertex2f(0.37f, 0.35f);
      glVertex2f(0.52f,  0.2f);

    glEnd();

    //Car line
    glBegin(GL_POLYGON);
      glColor3ub(211, 211, 211);
      glVertex2f( -0.6f,  0.18f);
      glVertex2f( -0.6f,  0.16f);
      glVertex2f( 0.6f,  0.16f);
      glVertex2f( 0.6f,  0.18f);

    glEnd();

    //Car wheel1
    GLfloat x = -0.4f ;
    GLfloat y = 0.0f;
    GLfloat rad = 0.1f;
    int tri = 40;

    GLfloat cal = 2.0f * 3.1416f;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(x,y);
        for (int i=0;i<=tri;i++) {
        glVertex2f(
        x + (rad* cos(i*cal / tri)),
        y + (rad* sin(i*cal / tri))
        );
        }

    glEnd();

    //Car wheel2
    GLfloat x2 = 0.4f ;
    GLfloat y2 = 0.0f;
    GLfloat radi2 = 0.1f;
    int tri2 = 40;

    GLfloat cal2 = 2.0f * 3.1416f;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(x2,y2);
        for (int i=0;i<=tri;i++) {
        glVertex2f(
        x2 + (radi2* cos(i*cal2 / tri2)),
        y2 + (radi2* sin(i*cal2 / tri2))
        );
        }

    glEnd();
}


//Car2
void car2 ()
{
    //Car Body
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.3f, -0.1f);
        glVertex2f(-0.3f, -0.1f);

    glEnd();

    //Car Window
    glBegin(GL_QUADS);
        glColor3ub(70,70,70);
        glVertex2f(-0.18f, 0.08f);
        glVertex2f(-0.01f, 0.08f);
        glVertex2f(-0.01f, -0.12f);
        glVertex2f(-0.27f, -0.12f);

    glEnd();

    //CarWindow
    glBegin(GL_QUADS);
        glColor3ub(70,70,70);
        glVertex2f(0.18f, 0.08f);
        glVertex2f(0.01f, 0.08f);
        glVertex2f(0.01f, -0.12f);
        glVertex2f(0.27f, -0.12f);

    glEnd();

    //Bottom Part
    glBegin(GL_QUADS);
    glColor3ub(92,46,46);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(-0.5f, -0.3f);
    glEnd();

	GLfloat x=-0.3f , y=-0.3f, radius =.13f;
	int triangleAmount = 50;
	GLfloat twicePi = 2.0f * 3.1416f;

	glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);

            glVertex2f(x,y);
            for (int i=0;i<=triangleAmount;i++) {
                glVertex2f(
                    x + (radius* cos(i*twicePi / triangleAmount)),
                    y + (radius* sin(i*twicePi / triangleAmount))
                );
            }
    glEnd();


    GLfloat x2=0.3f , y2=-0.3f, radius2 =.13f;
	int triangleAmount2 = 50;
	GLfloat twicePi2 = 2.0f * 3.1416f;

	glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);

            glVertex2f(x2,y2);
            for (int i=0;i<=triangleAmount2;i++) {
                glVertex2f(
                    x2 + (radius2* cos(i*twicePi2 / triangleAmount2)),
                    y2 + (radius2* sin(i*twicePi2 / triangleAmount2))
                );
            }
    glEnd();
}


//Boat1
void boat1()
{
    //Boat
    glBegin(GL_POLYGON);
          glColor3ub(139, 69, 19);
          glVertex2f(-0.3f, -0.8f);
          glVertex2f(-0.5f, -0.7f);
          glVertex2f(0.5f, -0.7f);
          glVertex2f(0.3f, -0.8f);

    glEnd();

    //Boat triangle
    glBegin(GL_TRIANGLES);
          glColor3f(1.0f, 1.0f, 1.0f);
          glVertex2f(-0.01f, -0.68f);
          glVertex2f(-0.01f, -0.4f);
          glVertex2f(-0.3f, -0.68f);

    glEnd();

    //Boat triangle2
    glBegin(GL_TRIANGLES);
          glColor3f(1.0f, 1.0f, 1.0f);
          glVertex2f( 0.01f, -0.68f);
          glVertex2f( 0.01f, -0.32f);
          glVertex2f( 0.3f, -0.68f);

    glEnd();

}


//Boat2
void boat2 ()
{
    //Boat
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.4f,-0.6f);
        glVertex2f(-0.3f,-0.75f);
        glVertex2f(0.3f,-0.75f);
        glVertex2f(0.4f,-0.6f);

    glEnd();

    //Boat box1
    glBegin(GL_POLYGON);
        glColor3ub(244,233,0);
        glVertex2f(-0.3f,-0.6f);
        glVertex2f(-0.3f,-0.5f);
        glVertex2f(0.3f,-0.5f);
        glVertex2f(0.3f,-0.6f);

    glEnd();

    //Boat box2
    glBegin(GL_POLYGON);
        glColor3ub(255,255,255);
        glVertex2f(-0.25f,-0.5f);
        glVertex2f(-0.25f,-0.45f);
        glVertex2f(0.25f,-0.45f);
        glVertex2f(0.25f,-0.5f);

    glEnd();

    //Boat window1
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.25f,-0.53f);
        glVertex2f(-0.25f,-0.57f);
        glVertex2f(-0.20f,-0.57f);
        glVertex2f(-0.20f,-0.53);

    glEnd();

    //Boat window2
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.15f,-0.53f);
        glVertex2f(-0.15f,-0.57f);
        glVertex2f(-0.10f,-0.57f);
        glVertex2f(-0.10f,-0.53);

    glEnd();

    //Boat window3
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.05f,-0.53f);
        glVertex2f(-0.05f,-0.57f);
        glVertex2f(0.0f,-0.57f);
        glVertex2f(0.0f,-0.53);

    glEnd();

    //Boat window4
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(0.1f,-0.53f);
        glVertex2f(0.1f,-0.57f);
        glVertex2f(0.05f,-0.57f);
        glVertex2f(0.05f,-0.53);

    glEnd();

    //Boat window5
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(0.15f,-0.53f);
        glVertex2f(0.15f,-0.57f);
        glVertex2f(0.2f,-0.57f);
        glVertex2f(0.2f,-0.53);

    glEnd();

    //Boat window5
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(0.25f,-0.53f);
        glVertex2f(0.25f,-0.57f);
        glVertex2f(0.28f,-0.57f);
        glVertex2f(0.28f,-0.53);

    glEnd();
}


//Plane
void plane()
{
    //PlaneBody
    glBegin(GL_POLYGON);
        glColor3ub(255,250,250);
        glVertex2f(-0.05f,0.95f);
        glVertex2f(0.11f,0.935f);
        glVertex2f(0.15f,0.92f);
        glVertex2f(0.23f,0.9f);
        glVertex2f(0.15f,0.87f);
        glVertex2f(0.07f,0.85f);
        glVertex2f(0.0f,0.85f);
        glVertex2f(-0.07f,0.85f);
        glVertex2f(-0.1f,0.865f);
        glVertex2f(-0.18f,0.89f);

    glEnd();

    //PlaneTail
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(0.22f,0.9f);
        glVertex2f(0.16f,0.92f);
        glVertex2f(0.19f,0.98f);
        glVertex2f(0.25f,0.96f);

    glEnd();

    //PlaneWing
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(0.0f,0.9f);
        glVertex2f(0.08f,0.88f);
        glVertex2f(0.12f,0.812f);
        glVertex2f(0.087f,0.81f);

    glEnd();

    //window1
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.05f,0.94f);
        glVertex2f(-0.05f,0.91f);
        glVertex2f(-0.09f,0.923f);

    glEnd();

    //window2
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.03f,0.94f);
        glVertex2f(0.00f,0.94f);
        glVertex2f(0.00f,0.91f);
        glVertex2f(-0.03f,0.91f);

    glEnd();

    //window3
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(0.05f,0.936f);
        glVertex2f(0.02f,0.94f);
        glVertex2f(0.02f,0.91f);
        glVertex2f(0.05f,0.91f);

    glEnd();

    //window4
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(0.1f,0.93f);
        glVertex2f(0.07f,0.93f);
        glVertex2f(0.07f,0.91f);
        glVertex2f(0.1f,0.91f);

    glEnd();

    //window5
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(0.12f,0.925f);
        glVertex2f(0.14f,0.92f);
        glVertex2f(0.14f,0.91f);
        glVertex2f(0.12f,0.91f);

    glEnd();
}


//Train
void train()
{
    //Train Engine
    glBegin(GL_POLYGON);
        glColor3ub(255,250,250);
        glVertex2f(-0.205f,0.12f);
        glVertex2f(-0.205f,0.22f);
        glVertex2f(-0.58f,0.22f);
        glVertex2f(-0.6f,0.2f);
        glVertex2f(-0.6f,0.12f);

    glEnd();

    //First Door
    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.535f,0.12f);
        glVertex2f(-0.535f,0.21f);
        glVertex2f(-0.57f,0.21f);
        glVertex2f(-0.57f,0.12f);

    glEnd();

    //2Window+1Door
    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.213f,0.17f);
        glVertex2f(-0.213f,0.21f);
        glVertex2f(-0.243f,0.21f);
        glVertex2f(-0.243f,0.17f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.253f,0.17f);
        glVertex2f(-0.253f,0.21f);
        glVertex2f(-0.283f,0.21f);
        glVertex2f(-0.283f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.293f,0.12f);
        glVertex2f(-0.293f,0.21f);
        glVertex2f(-0.363f,0.21f);
        glVertex2f(-0.363f,0.12f);

    glEnd();

    //2Window+1Door
    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.373f,0.17f);
        glVertex2f(-0.373f,0.21f);
        glVertex2f(-0.403f,0.21f);
        glVertex2f(-0.403f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.413f,0.17f);
        glVertex2f(-0.413f,0.21f);
        glVertex2f(-0.443f,0.21f);
        glVertex2f(-0.443f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.453f,0.12f);
        glVertex2f(-0.453f,0.21f);
        glVertex2f(-0.523f,0.21f);
        glVertex2f(-0.523f,0.12f);

    glEnd();

    //MiddleCompartment
    glBegin(GL_POLYGON);
        glColor3ub(255,250,250);
        glVertex2f(0.128f,0.12f);
        glVertex2f(0.128f,0.22f);
        glVertex2f(-0.2f,0.22f);
        glVertex2f(-0.2f,0.12f);

    glEnd();

    //2Window+1Door
    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.12f,0.17f);
        glVertex2f(0.12f,0.21f);
        glVertex2f(0.09f,0.21f);
        glVertex2f(0.09f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.08f,0.17f);
        glVertex2f(0.08f,0.21f);
        glVertex2f(0.05f,0.21f);
        glVertex2f(0.05f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.04f,0.12f);
        glVertex2f(0.04f,0.21f);
        glVertex2f(-0.03f,0.21f);
        glVertex2f(-0.03f,0.12f);

    glEnd();

    //2Window+1Door
    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.04f,0.17f);
        glVertex2f(-0.04f,0.21f);
        glVertex2f(-0.07f,0.21f);
        glVertex2f(-0.07f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.08f,0.17f);
        glVertex2f(-0.08f,0.21f);
        glVertex2f(-0.11f,0.21f);
        glVertex2f(-0.11f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(-0.12f,0.12f);
        glVertex2f(-0.12f,0.21f);
        glVertex2f(-0.19f,0.21f);
        glVertex2f(-0.19f,0.12f);

    glEnd();

    //LastCompartment
    glBegin(GL_POLYGON);
        glColor3ub(255,250,250);
        glVertex2f(0.133f,0.12f);
        glVertex2f(0.133f,0.22f);
        glVertex2f(0.46f,0.22f);
        glVertex2f(0.46f,0.12f);

    glEnd();

    //2Window+1Door
    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.422f,0.17f);
        glVertex2f(0.422f,0.21f);
        glVertex2f(0.452f,0.21f);
        glVertex2f(0.452f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.412f,0.17f);
        glVertex2f(0.412f,0.21f);
        glVertex2f(0.382f,0.21f);
        glVertex2f(0.382f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.372f,0.12f);
        glVertex2f(0.372f,0.21f);
        glVertex2f(0.302f,0.21f);
        glVertex2f(0.302f,0.12f);

    glEnd();

    //2Window+1Door
    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.292f,0.17f);
        glVertex2f(0.292f,0.21f);
        glVertex2f(0.262f,0.21f);
        glVertex2f(0.262f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.252f,0.17f);
        glVertex2f(0.252f,0.21f);
        glVertex2f(0.222f,0.21f);
        glVertex2f(0.222f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(70,70,70);
        glVertex2f(0.212f,0.12f);
        glVertex2f(0.212f,0.21f);
        glVertex2f(0.142f,0.21f);
        glVertex2f(0.142f,0.12f);

    glEnd();
}


//Tree
void tree ()
{
    //Tree triangle
    glBegin(GL_TRIANGLES);
        glColor3ub(84, 139, 84);
        glVertex2f(0.06f, 0.35f);
        glVertex2f(0.19f, 0.55f);
        glVertex2f(0.3f, 0.35f);

    glEnd();

    //Tree triangle2
    glBegin(GL_TRIANGLES);
        glColor3ub(84, 139, 84);
        glVertex2f(0.06f, 0.45f);
        glVertex2f(0.19f, 0.65f);
        glVertex2f(0.3f, 0.45f);

    glEnd();

    //Stand
    glBegin(GL_POLYGON);
        glColor3ub(139,69, 19);
        glVertex2f(0.18f, 0.2f);
        glVertex2f(0.18f, 0.35f);
        glVertex2f(0.2f, 0.35f);
        glVertex2f(0.2f, 0.2f);

    glEnd();
}


//River
void river()
{
    glBegin(GL_POLYGON);
        glColor3ub(135,206,250);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(-1.0f, -0.8f);
        glVertex2f(1.0f, -0.8f);

	glEnd();

}


//Between River And Road
void divider()
{
    glBegin(GL_POLYGON);
        glColor3ub(112,128,144);
        glVertex2f(1.0f, -0.8f);
        glVertex2f(-1.0f, -0.8f);
        glVertex2f(-1.0f, -0.75f);
        glVertex2f(1.0f, -0.75f);

	glEnd();

}


//RoadLine
void roadLine()
{
	glBegin(GL_POLYGON);
        glColor3ub(255,255,255);
        glVertex2f(1.0f, -0.64f);
        glVertex2f(-1.0f, -0.64f);
        glVertex2f(-1.0f, -0.65f);
        glVertex2f(1.0f, -0.65f);

	glEnd();
}


//GuardrailStand
void guardrailStand()
{
	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.95f, -0.7f);
        glVertex2f(-0.95f, -0.75f);
        glVertex2f(-0.96f, -0.75f);
        glVertex2f(-0.96f, -0.7f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.9f, -0.7f);
        glVertex2f(-0.9f, -0.75f);
        glVertex2f(-0.91f, -0.75f);
        glVertex2f(-0.91f, -0.7f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.85f, -0.7f);
        glVertex2f(-0.85f, -0.75f);
        glVertex2f(-0.86f, -0.75f);
        glVertex2f(-0.86f, -0.7f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-0.8f, -0.7f);
        glVertex2f(-0.8f, -0.75f);
        glVertex2f(-0.81f, -0.75f);
        glVertex2f(-0.81f, -0.7f);

	glEnd();
}


//Guardrail
void guardrail()
{
	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(1.0f, -0.7f);
        glVertex2f(-1.0f, -0.7f);
        glVertex2f(-1.0f, -0.69f);
        glVertex2f(1.0f, -0.69f);

	glEnd();

	guardrailStand();

	glTranslatef(0.2,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(0.4,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(0.6,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(0.8,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.0,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.2,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.4,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.6,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.8,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.0,0.0,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.0,0.0,0);
	guardrailStand();
    glLoadIdentity();
}


//Road
void road()
{
    glBegin(GL_POLYGON);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex2f(1.0f, -0.75f);
        glVertex2f(-1.0f, -0.75f);
        glVertex2f(-1.0f, -0.55f);
        glVertex2f(1.0f, -0.55f);

	glEnd();

}


//Road Divider
void roadDivider()
{
    glBegin(GL_POLYGON);
        glColor3ub(112,128,144);
        glVertex2f(1.0f, -0.55f);
        glVertex2f(-1.0f, -0.55f);
        glVertex2f(-1.0f, -0.5f);
        glVertex2f(1.0f, -0.5f);

	glEnd();

}


//Grass
void grass()
{
    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.4f, 0.0f);
        glVertex2f(1.0f, -0.3f);
        glVertex2f(-1.0f, -0.3f);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f(1.0f, -0.2f);

	glEnd();

}


//Train Line Pillar
void pillar()
{
    glBegin(GL_POLYGON);
        glColor3ub(112,128,144);
        glVertex2f(-0.9f, 0.1f);
        glVertex2f(-0.7f, 0.1f);
        glVertex2f(-0.75f, 0.0f);
        glVertex2f(-0.85f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(112,128,144);
        glVertex2f(-0.83f, 0.0f);
        glVertex2f(-0.77f, 0.0f);
        glVertex2f(-0.77f, -0.2f);
        glVertex2f(-0.83f, -0.2f);

	glEnd();

}


//Metro Rail Road
void pillarRoad()
{
    glBegin(GL_POLYGON);
        glColor3ub(105,105,105);
        glVertex2f(-1.0f, 0.15f);
        glVertex2f(1.0f, 0.15f);
        glVertex2f(1.0f, 0.1f);
        glVertex2f(-1.0f, 0.1f);

	glEnd();

}


//Building1Window
void building1Window()
{
    glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.83f, 0.010f);
        glVertex2f(0.88f, 0.010f);
        glVertex2f(0.88f, -0.08f);
        glVertex2f(0.83f, -0.08f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.83f, -0.09f);
        glVertex2f(0.88f, -0.09f);
        glVertex2f(0.88f, -0.18f);
        glVertex2f(0.83f, -0.18f);

	glEnd();

}


//Building1
void building1()
{
    glBegin(GL_POLYGON);
        glColor3ub(169,169,169);
        glVertex2f(0.4f, 0.03f);
        glVertex2f(0.9f, 0.03f);
        glVertex2f(0.9f, -0.2f);
        glVertex2f(0.4f, -0.2f);

	glEnd();

	//Shawdow
	glBegin(GL_POLYGON);
        glColor3ub(192,192,192);
        glVertex2f(0.4f, 0.03f);
        glVertex2f(0.52f, 0.03f);
        glVertex2f(0.52f, -0.2f);
        glVertex2f(0.4f, -0.2f);

	glEnd();

	//Windows
	building1Window();

	glTranslatef(-0.06,0.0,0);
	building1Window();
    glLoadIdentity();

    glTranslatef(-0.12,0.0,0);
	building1Window();
    glLoadIdentity();

    glTranslatef(-0.18,0.0,0);
	building1Window();
    glLoadIdentity();

    glTranslatef(-0.24,0.0,0);
	building1Window();
    glLoadIdentity();

    glTranslatef(-0.30,0.0,0);
	building1Window();
    glLoadIdentity();


}

//building2Window
void building2Window()
{
    glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.05f, 0.04f);
        glVertex2f(0.28f, 0.04f);
        glVertex2f(0.28f, 0.0f);
        glVertex2f(0.05f, 0.0f);
	glEnd();

}

//building2
void building2()
{
    glBegin(GL_POLYGON);
        glColor3ub(211,211,211);
        glVertex2f(-0.1f, 0.06f);
        glVertex2f(0.3f, 0.06f);
        glVertex2f(0.3f, -0.2f);
        glVertex2f(-0.1f, -0.2f);
	glEnd();

	//Shadow
	glBegin(GL_POLYGON);
        glColor3ub(192,192,192);
        glVertex2f(-0.1f, 0.06f);
        glVertex2f(0.03f, 0.06f);
        glVertex2f(0.03f, -0.2f);
        glVertex2f(-0.1f, -0.2f);
	glEnd();

	//Windows
	building2Window();

	glTranslatef(0.0,-0.06,0);
	building2Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.12,0);
	building2Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.18,0);
	building2Window();
    glLoadIdentity();
}


//Building3Window
void building3Window()
{
    glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.21f, -0.18f);
        glVertex2f(-0.25f, -0.18f);
        glVertex2f(-0.25f, -0.1f);
        glVertex2f(-0.21f, -0.1f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.21f, -0.08f);
        glVertex2f(-0.25f, -0.08f);
        glVertex2f(-0.25f, -0.00f);
        glVertex2f(-0.21f, -0.00f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.21f, 0.02f);
        glVertex2f(-0.25f, 0.02f);
        glVertex2f(-0.25f, 0.1f);
        glVertex2f(-0.21f, 0.1f);

	glEnd();
}


//Building3
void building3()
{
    glBegin(GL_POLYGON);
        glColor3ub(169,169,169);
        glColor3ub(169,169,169);
        glVertex2f(-0.4f, 0.12f);
        glVertex2f(-0.2f, 0.12f);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(-0.4f, -0.2f);

	glEnd();

	//Shawdow
	glBegin(GL_POLYGON);
        glColor3ub(192,192,192);
        glVertex2f(-0.4f, 0.12f);
        glVertex2f(-0.36f, 0.12f);
        glVertex2f(-0.36, -0.2f);
        glVertex2f(-0.4f, -0.2f);

	glEnd();

	//Windows
	building3Window();

	glTranslatef(-0.05,0.0,0);
	building3Window();
    glLoadIdentity();

    glTranslatef(-0.1,0.0,0);
	building3Window();
    glLoadIdentity();
}


//Building4Window
void building4Window()
{
    glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.52f, -0.18f);
        glVertex2f(-0.56f, -0.18f);
        glVertex2f(-0.56f, -0.1f);
        glVertex2f(-0.52f, -0.1f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.52f, -0.08f);
        glVertex2f(-0.56f, -0.08f);
        glVertex2f(-0.56f, -0.00f);
        glVertex2f(-0.52f, -0.00f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.52f, 0.02f);
        glVertex2f(-0.56f, 0.02f);
        glVertex2f(-0.56f, 0.1f);
        glVertex2f(-0.52f, 0.1f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.52f, 0.12f);
        glVertex2f(-0.56f, 0.12f);
        glVertex2f(-0.56f, 0.2f);
        glVertex2f(-0.52f, 0.2f);

	glEnd();

}


//Building4
void building4()
{
    glBegin(GL_POLYGON);
        glColor3ub(211,211,211);
        glVertex2f(-0.8f, 0.25f);
        glVertex2f(-0.5f, 0.25f);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.8f, -0.2f);

	glEnd();

	//Shadow
    glBegin(GL_POLYGON);
    glColor3ub(220,220,220);
        glVertex2f(-0.8f, 0.25f);
        glVertex2f(-0.72f, 0.25f);
        glVertex2f(-0.72f, -0.2f);
        glVertex2f(-0.8f, -0.2f);
	glEnd();

	//Windows
	building4Window();

	glTranslatef(-0.05,0.0,0);
	building4Window();
    glLoadIdentity();

    glTranslatef(-0.1,0.0,0);
	building4Window();
    glLoadIdentity();

    glTranslatef(-0.15,0.0,0);
	building4Window();
    glLoadIdentity();
}


//Building5Window
void building5Window()
{
    glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.64f, 0.48f);
        glVertex2f(-0.61f, 0.48f);
        glVertex2f(-0.61f, -0.18f);
        glVertex2f(-0.64, -0.18f);

	glEnd();

}


//Building5
void building5()
{
    glBegin(GL_POLYGON);
        glColor3ub(192,192,192);
        glVertex2f(-0.9f, 0.5f);
        glVertex2f(-0.6f, 0.5f);
        glVertex2f(-0.6f, -0.2f);
        glVertex2f(-0.9f, -0.2f);

	glEnd();

	//Shadow
	glBegin(GL_POLYGON);
        glColor3ub(211,211,211);
        glVertex2f(-0.9f, 0.5f);
        glVertex2f(-0.81f, 0.5f);
        glVertex2f(-0.81f, -0.2f);
        glVertex2f(-0.9f, -0.2f);

	glEnd();

    //Windows
    building5Window();

    glTranslatef(-0.04,0.0,0);
    building5Window();
    glLoadIdentity();

    glTranslatef(-0.08,0.0,0);
    building5Window();
    glLoadIdentity();

    glTranslatef(-0.12,0.0,0);
    building5Window();
    glLoadIdentity();

    glTranslatef(-0.16,0.0,0);
    building5Window();
    glLoadIdentity();

    glTranslatef(-0.21,0.0,0);
    building5Window();
    glLoadIdentity();

    glTranslatef(-0.25,0.0,0);
    building5Window();
    glLoadIdentity();
}


//Building6Window
void building6Window()
{
    glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.13f,0.55f);
        glVertex2f(-0.13f,0.68f);
        glVertex2f(-0.10f, 0.68f);
        glVertex2f(-0.10f, 0.55f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.09f,0.55f);
        glVertex2f(-0.09f,0.68f);
        glVertex2f(-0.06f, 0.68f);
        glVertex2f(-0.06f, 0.55f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.05f,0.55f);
        glVertex2f(-0.05f,0.68f);
        glVertex2f(-0.02f, 0.68f);
        glVertex2f(-0.02f, 0.55f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.05f,0.55f);
        glVertex2f(-0.05f,0.68f);
        glVertex2f(-0.02f, 0.68f);
        glVertex2f(-0.02f, 0.55f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(-0.01f,0.55f);
        glVertex2f(-0.01f,0.68f);
        glVertex2f(0.02f, 0.68f);
        glVertex2f(0.02f, 0.55f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.03f,0.55f);
        glVertex2f(0.03f,0.68f);
        glVertex2f(0.06f, 0.68f);
        glVertex2f(0.06f, 0.55f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.07f,0.55f);
        glVertex2f(0.07f,0.68f);
        glVertex2f(0.10f, 0.68f);
        glVertex2f(0.10f, 0.55f);

	glEnd();

}


//Building6
void building6()
{
    glBegin(GL_POLYGON);
        glColor3ub(220,220,220);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(-0.3f, 0.7f);
        glVertex2f(-0.15f,0.8f);
        glVertex2f(0.11f, 0.7f);
        glVertex2f(0.11f, -0.2f);

	glEnd();

	//Shawdpw
	glBegin(GL_POLYGON);
        glColor3ub(211,211,211);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(-0.3f, 0.7f);
        glVertex2f(-0.15f,0.8f);
        glVertex2f(-0.15f, -0.2f);

	glEnd();

	//Windows
	building6Window();

	glTranslatef(0.0,-0.15,0);
	building6Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.3,0);
	building6Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.45,0);
	building6Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.60,0);
	building6Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.74,0);
	building6Window();
    glLoadIdentity();
}


//Building7Window
void building7Window()
{
    glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.45f, 0.55f);
        glVertex2f(0.48f, 0.55f);
        glVertex2f(0.48f, -0.15f);
        glVertex2f(0.45f, -0.15f);

	glEnd();

}


//Building7
void building7()
{
    glBegin(GL_POLYGON);
        glColor3ub(220,220,220);
        glVertex2f(0.2f, 0.6f);
        glVertex2f(0.5f, 0.6f);
        glVertex2f(0.5f, -0.2f);
        glVertex2f(0.2f, -0.2f);

	glEnd();

	//Shadow
	glBegin(GL_POLYGON);
        glColor3ub(192,192,192);
        glVertex2f(0.2f, 0.6f);
        glVertex2f(0.28f, 0.6f);
        glVertex2f(0.28f, -0.2f);
        glVertex2f(0.2f, -0.2f);

	glEnd();

	//Windows
	building7Window();

	glTranslatef(-0.05,0.0,0);
	building7Window();
    glLoadIdentity();

    glTranslatef(-0.10,0.0,0);
	building7Window();
    glLoadIdentity();

    glTranslatef(-0.15,0.0,0);
	building7Window();
    glLoadIdentity();

    glTranslatef(-0.22,0.0,0);
	building7Window();
    glLoadIdentity();
}


//Building8Window
void building8Window()
{
	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.76f, 0.38f);
        glVertex2f(0.8f, 0.38f);
        glVertex2f(0.8f, 0.32f);
        glVertex2f(0.76f, 0.32f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.81f, 0.38f);
        glVertex2f(0.85f, 0.38f);
        glVertex2f(0.85f, 0.32f);
        glVertex2f(0.81f, 0.32f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.86f, 0.38f);
        glVertex2f(0.9f, 0.38f);
        glVertex2f(0.9f, 0.32f);
        glVertex2f(0.86f, 0.32f);

	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(240,255,255);
        glVertex2f(0.91f, 0.38f);
        glVertex2f(0.95f, 0.38f);
        glVertex2f(0.95f, 0.32f);
        glVertex2f(0.91f, 0.32f);

	glEnd();

}


//Building8
void building8()
{
    glBegin(GL_POLYGON);
        glColor3ub(220,220,220);
        glVertex2f(0.7f, 0.4f);
        glVertex2f(0.96f, 0.4f);
        glVertex2f(0.96f, -0.2f);
        glVertex2f(0.7f, -0.2f);;

	glEnd();

	//Shadow
	glBegin(GL_POLYGON);
        glColor3ub(192,192,192);
        glVertex2f(0.7f, 0.4f);
        glVertex2f(0.75f, 0.4f);
        glVertex2f(0.75f, -0.2f);
        glVertex2f(0.7f, -0.2f);;

	glEnd();

	//Windows
	building8Window();

	glTranslatef(0.0,-0.085,0);
	building8Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.164,0);
	building8Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.246,0);
	building8Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.328,0);
	building8Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.41,0);
	building8Window();
    glLoadIdentity();

    glTranslatef(0.0,-0.492,0);
	building8Window();
    glLoadIdentity();
}


//First Display
void display()
{
    glClearColor(0.0f, 0.8f, 1.0f,0.1f);

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(1,1);
    glColor3ub(0,0,0);
    glVertex2f(-1,1);
    glColor3ub(25,25,112);
    glVertex2f(-1,-1);
    glColor3ub(25,25,112);
    glVertex2f(1,-1);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    char *C="COMPUTER GRAPHICS [H]";
    glRasterPos2f( -0.23 , 0.7 );
    for(int i = 0; C[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, C[i]);

    glColor3f(1.0 , 1.0, 1.0);
    char *F="Farhan Sadik Ferdous(20-42072-1)";
    glRasterPos2f( -0.23 , 0.1 );
    for(int i = 0; F[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, F[i]);

    glColor3f(1.0 , 1.0, 1.0);
    char *T="Tapu Biswas (20-42073-1)";
    glRasterPos2f( -0.23 , 0.0 );
    for(int i = 0; T[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, T[i]);

    glColor3f(1.0, 1.0, 1.0);
    char *S="Press (S) for start";
    glRasterPos2f( -0.8, -0.7 );
    for(int i = 0; S[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, S[i]);

    glColor3f(1.0, 1.0, 1.0);
    char *E="Press (E) for Exit";
    glRasterPos2f( 0.55, -0.7 );
    for(int i = 0; E[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, E[i]);

    glColor3f(1.0, 1.0, 1.0);
    char *D="Press (D) for Day";
    glRasterPos2f( -0.1 , -0.6 );
    for(int i = 0; D[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, D[i]);

    glColor3f(1.0, 1.0, 1.0);
    char *N="Press (N) for Night";
    glRasterPos2f( -0.1 , -0.7 );
    for(int i = 0; N[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, N[i]);

    glFlush();
}


//SecondDisplay
void secondDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	river();
	divider();
	roadDivider();


	road();

	glTranslatef(0.0,0.25,0);
	road();
    glLoadIdentity();


    grass();


    //Secondguardrail
    glTranslatef(0.0,0.2,0);
	guardrail();
    glLoadIdentity();

    glTranslatef(0.4,0.2,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(0.6,0.2,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(0.8,0.2,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.0,0.2,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.2,0.2,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.4,0.2,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.6,0.2,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.8,0.2,0);
	guardrailStand();
    glLoadIdentity();


    glTranslatef(-0.94,-0.33,0);
    glScalef(-0.2,0.3,0);
    tree();
    glLoadIdentity();


    //Thirdguardrail
    glTranslatef(0.0,0.45,0);
	guardrail();
    glLoadIdentity();

    glTranslatef(0.4,0.45,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(0.6,0.45,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(0.8,0.45,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.0,0.45,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.2,0.45,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.4,0.45,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.6,0.45,0);
	guardrailStand();
    glLoadIdentity();

    glTranslatef(1.8,0.45,0);
	guardrailStand();
    glLoadIdentity();


    building5();
    building6();
    building7();
    building8();
    building1();
    building2();
    building3();
    building4();


    pillar();

	glTranslatef(0.4,0.0,0);
	pillar();
    glLoadIdentity();

    glTranslatef(0.8,0.0,0);
	pillar();
    glLoadIdentity();

    glTranslatef(1.2,0.0,0);
	pillar();
    glLoadIdentity();

    glTranslatef(1.6,0.0,0);
	pillar();
    glLoadIdentity();


    roadLine();

    glTranslatef(0.0,0.25,0);
    roadLine();
    glLoadIdentity();


    //MovingRight
    glPushMatrix();

    glTranslatef(position,0.0f, 0.0f);
    glTranslatef(0.0,-0.53,0);
    glScalef(-0.15,0.25,0);
    car2();
    glLoadIdentity();


    glTranslatef(position,0.0f, 0.0f);
    glTranslatef(0.5,-0.635,0);
    glScalef(-0.15,0.25,0);
    car2();
    glLoadIdentity();


    glTranslatef(position,0.0f, 0.0f);
    glTranslatef(0.9,-0.61,0);
    glScalef(-0.2,0.3,0);
    car1();
    glLoadIdentity();


    glTranslatef(position,0.0f, 0.0f);
    glTranslatef(-0.5,-0.71,0);
    glScalef(-0.2,0.3,0);
    car1();
    glLoadIdentity();


    glTranslatef(position,0.0f, 0.0f);
    glTranslatef(-0.5,-0.65,0);
    glScalef(-0.25,0.35,0);
    boat1();
    glLoadIdentity();


    glTranslatef(position,0.0f, 0.0f);
    glTranslatef(0.2,0.3,0);
    glScalef(-0.55,0.65,0);
    plane();
    glLoadIdentity();

    glPopMatrix();
    //MovingEnd


    //MovingLeft
    glPushMatrix();


    glTranslatef(position2,0.0f, 0.0f);
    train();
    glLoadIdentity();

    glTranslatef(position2,0.0f, 0.0f);
    glTranslatef(0.0,-0.28,0);
    glScalef(-0.15,0.25,0);
    car2();
    glLoadIdentity();


    glTranslatef(position2,0.0f, 0.0f);
    glTranslatef(0.5,-0.38,0);
    glScalef(-0.15,0.25,0);
    car2();
    glLoadIdentity();


    glTranslatef(position2,0.0f, 0.0f);
    glTranslatef(0.9,-0.36,0);
    glScalef(-0.2,0.3,0);
    car1();
    glLoadIdentity();


    glTranslatef(position2,0.0f, 0.0f);
    glTranslatef(-0.5,-0.456,0);
    glScalef(-0.2,0.3,0);
    car1();
    glLoadIdentity();


    glTranslatef(position2,0.0f, 0.0f);
    glTranslatef(0.2,-0.5,0);
    glScalef(-0.55,0.65,0);
    boat2();
    glLoadIdentity();

    glPopMatrix();
    //MovingEnd


    guardrail();

    pillarRoad();


    glTranslatef(1.0,-0.26,0);
    glScalef(-0.2,0.3,0);
    tree();
    glLoadIdentity();


    glTranslatef(-0.43,-0.26,0);
    glScalef(-0.2,0.3,0);
    tree();
    glLoadIdentity();


    glTranslatef(-0.9,-0.26,0);
    glScalef(-0.2,0.3,0);
    tree();
    glLoadIdentity();


    glTranslatef(-0.04,-0.28,0);
    glScalef(-0.2,0.3,0);
    tree();
    glLoadIdentity();


    glTranslatef(0.34,-0.3,0);
    glScalef(-0.2,0.3,0);
    tree();
    glLoadIdentity();


    glTranslatef(0.74,-0.27,0);
    glScalef(-0.2,0.3,0);
    tree();
    glLoadIdentity();



    cloud();

    glTranslatef(1.6,-0.05,0);
    cloud();
    glLoadIdentity();



    glPushMatrix();

    glTranslatef(0.0f,position3, 0.0f);
    if(rain)
        {
            rainf();
        }
        glPopMatrix();

    glFlush();
}


//Keyboard Handling
void keys(unsigned char key,int x,int y)
{

    if(key=='s'||key=='S'){
        glutDisplayFunc(secondDisplay);
    }
    else if(key=='r'||key=='R')
    {
        rain=true;
        PlaySound(TEXT("rain.wav"), NULL,  SND_ASYNC|SND_FILENAME);
    }
    else if(key=='f'||key=='F')
    {
        rain=false;
        PlaySound(NULL, NULL,  SND_ASYNC|SND_FILENAME);
    }
    else if(key=='d'||key=='D')
    {
        day();
    }
    else if(key=='n'||key=='N')
    {
        night();
    }
    else if(key=='p'||key=='P')
    {
        speed = 0.0f;
        speed2 = 0.0f;
        PlaySound(NULL, NULL,  SND_ASYNC|SND_FILENAME);
    }
    else if(key=='m'||key=='M')
    {
        speed = 0.1f;
        speed2 = 0.15f;
    }
    else if(key=='t'||key=='T')
    {
        PlaySound(TEXT("train.wav"), NULL,  SND_ASYNC|SND_FILENAME);
    }
    else if(key=='c'||key=='C')
    {
        PlaySound(TEXT("traffic.wav"), NULL,  SND_ASYNC|SND_FILENAME);
    }
    else if(key=='a'||key=='A')
    {
        PlaySound(TEXT("plane.wav"), NULL,  SND_ASYNC|SND_FILENAME);
    }
	else if(key=='e'||key=='E')
        exit(0);
}


//Main Function
int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitWindowSize(1280, 960);
	glutCreateWindow("Modern City Life");
	glutDisplayFunc(display);

    glutKeyboardFunc(keys);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);
    Timer(1);

	glutMainLoop();
	return 0;
}

