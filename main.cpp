#include <Gl\glew.h>
#include <GL\freeglut.h>
 
#include <math.h>
#define PI 3.14159
int circle_points = 100;
 
void draw_circle(GLfloat centerx , GLfloat centery , GLfloat radius)
{
    GLdouble theta;
    GLint i;
   
    glBegin(GL_POLYGON);
   
    for (i = 0 ; i < circle_points ; ++i)
    {
        theta = 2 * PI * i / circle_points ;
        glVertex2f(centerx + radius * cos(theta), centery + radius * sin(theta));
    }
    glEnd();
}
 
void drawHeart(double magnifier)
{
    if(magnifier < 0.5)
        glColor3f(0.5 * 2, 0.0, magnifier * 2 );
    else
        glColor3f(0.5 , 0.0, magnifier );
   
   
   
   
    glBegin(GL_POINTS);
    {
       
        for (double theta = 0 ; theta <  2  * 3.14159; theta += 0.001)
        {
            double r = ( 2 - 2 * sin(theta) + sin(theta) * ( sqrt(fabs(cos(theta))) / (sin(theta) +1.4)));
            r *= 1.2;
            double x = cos(theta) * r  * magnifier ;
            double y = sin(theta) * r * magnifier ;
            glVertex2f(x ,  y  );
        }
    }
   
    glEnd();
   
}
 
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
   
    //Head
    glColor3f(1.0, 0.0, 1.0);
   
 
    glBegin(GL_POINTS);
    {
       
        for (double theta = 1 ; theta >  0 ; theta -= 0.001)
        {
            drawHeart(theta);
           
        }
    }
   
    glEnd();
   
    glColor3f(0.0, 0.0, 0.0);
   
   
    glBegin(GL_POINTS);
    {
       
        for (double theta = -5.0 ; theta <  5.0; theta += 0.00001)
        {
            glVertex2f(0,theta );
            glVertex2f(theta, 0);
        }
    }
   
    glEnd();
   
   
    for (int i = - 5 ; i <= 5 ; i++)
    {
        draw_circle(i, 0, .025);
        draw_circle(0, i, .025);
    }
   
   
    glFlush();
}
 
 
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
   
    glViewport(0, 0, 320, 240);
   
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
   
   
}
 
 
int main(int argc, char* argv[])
{
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("character window");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}