#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

// Window dimensions
const int WIDTH = 1000;
const int HEIGHT = 700;

// Animation variables
float moveX = 0.0f;
float rotationAngle = 0.0f;
bool animationRunning = true;

const float PI = 3.14159265358979323846f;

// =====================================
// 1. DRAW POINT
// =====================================

void drawPoint()
{
    glPointSize(8.0f);

    glBegin(GL_POINTS);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(100, 600);

    glEnd();
}

// =====================================
// 2. DRAW A LINE
// =====================================

void drawLine()
{
    glLineWidth(4.0f);

    glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(150, 600);
        glVertex2f(300, 600);

    glEnd();
}

// =====================================
// 3. DRAW A TRIANGLE
// =====================================

void drawTriangle()
{
    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(100, 450);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(200, 550);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(300, 450);

    glEnd();
}

// =====================================
// 4. DRAW A RECTANGLE
// =====================================

void drawRectangle()
{
    glColor3f(0.0f, 0.8f, 0.5f);

    glBegin(GL_QUADS);

        glVertex2f(350, 450);
        glVertex2f(550, 450);
        glVertex2f(550, 550);
        glVertex2f(350, 550);

    glEnd();
}

// =====================================
// 5. DRAW A SQUARE
// =====================================

void drawSquare()
{
    glColor3f(1.0f, 0.5f, 0.0f);

    glBegin(GL_QUADS);

        glVertex2f(600, 450);
        glVertex2f(700, 450);
        glVertex2f(700, 550);
        glVertex2f(600, 550);

    glEnd();
}

// =====================================
// 6. DRAW A CIRCLE
// =====================================

void drawCircle(float cx, float cy, float radius)
{
    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(cx, cy);

        for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * PI * i / 100;

            float x = cx + radius * cos(angle);
            float y = cy + radius * sin(angle);

            glVertex2f(x, y);
        }

    glEnd();
}

// =====================================
// 7. DRAW AN ELLIPSE
// =====================================

void drawEllipse(float cx, float cy, float rx, float ry)
{
    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(cx, cy);

        for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * PI * i / 100;

            float x = cx + rx * cos(angle);
            float y = cy + ry * sin(angle);

            glVertex2f(x, y);
        }

    glEnd();
}

// =====================================
// 8. DRAW A POLYGON
// =====================================

void drawPolygon()
{
    glColor3f(0.7f, 0.2f, 0.8f);

    glBegin(GL_POLYGON);

        glVertex2f(100, 200);
        glVertex2f(150, 250);
        glVertex2f(200, 230);
        glVertex2f(230, 180);
        glVertex2f(180, 130);
        glVertex2f(120, 140);

    glEnd();
}

// =====================================
// 9. DRAW CONNECTED LINES
// =====================================

void drawLineStrip()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_STRIP);

        glVertex2f(300, 200);
        glVertex2f(350, 250);
        glVertex2f(400, 200);
        glVertex2f(450, 250);
        glVertex2f(500, 200);

    glEnd();
}

// =====================================
// 10. DRAW CLOSED LINES
// =====================================

void drawLineLoop()
{
    glColor3f(1.0f, 0.0f, 0.5f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_LOOP);

        glVertex2f(550, 150);
        glVertex2f(650, 150);
        glVertex2f(700, 250);
        glVertex2f(600, 280);

    glEnd();
}

// =====================================
// 11. DRAW TEXT
// =====================================

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);

    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

// =====================================
// 12. TRANSLATION
// =====================================

void drawMovingObject()
{
    glPushMatrix();

        glTranslatef(moveX, 0.0f, 0.0f);

        glColor3f(1.0f, 0.0f, 0.0f);

        drawCircle(100, 80, 30);

    glPopMatrix();
}

// =====================================
// 13. ROTATION
// =====================================

void drawRotatingObject()
{
    glPushMatrix();

        glTranslatef(850, 200, 0.0f);

        glRotatef(rotationAngle, 0, 0, 1);

        glColor3f(0.0f, 0.5f, 1.0f);

        glBegin(GL_QUADS);

            glVertex2f(-40, -40);
            glVertex2f(40, -40);
            glVertex2f(40, 40);
            glVertex2f(-40, 40);

        glEnd();

    glPopMatrix();
}

// =====================================
// 14. DISPLAY FUNCTION
// =====================================

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Point
    drawPoint();

    // Line
    drawLine();

    // Triangle
    drawTriangle();

    // Rectangle
    drawRectangle();

    // Square
    drawSquare();

    // Circle
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(800, 500, 50);

    // Ellipse
    glColor3f(0.0f, 0.5f, 1.0f);
    drawEllipse(900, 600, 70, 35);

    // Polygon
    drawPolygon();

    // Connected Lines
    drawLineStrip();

    // Closed Lines
    drawLineLoop();

    // Moving Object
    drawMovingObject();

    // Rotating Object
    drawRotatingObject();

    // Text
    glColor3f(0.0f, 0.0f, 0.0f);

    drawText(300, 650, "OpenGL GLUT 2D Basics");

    drawText(300, 30, "Press SPACE to Pause / Resume");

    glutSwapBuffers();
}

// =====================================
// 15. ANIMATION / TIMER
// =====================================

void update(int value)
{
    if (animationRunning)
    {
        moveX += 2.0f;

        if (moveX > WIDTH)
        {
            moveX = -150.0f;
        }

        rotationAngle += 2.0f;

        if (rotationAngle >= 360.0f)
        {
            rotationAngle -= 360.0f;
        }
    }

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}

// =====================================
// 16. KEYBOARD INPUT
// =====================================

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case ' ':
            animationRunning = !animationRunning;
            break;

        case 'r':
        case 'R':
            moveX = 0;
            rotationAngle = 0;
            break;

        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

// =====================================
// 17. MOUSE INPUT
// =====================================

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON &&
        state == GLUT_DOWN)
    {
        animationRunning = !animationRunning;
    }

    glutPostRedisplay();
}

// =====================================
// 18. WINDOW RESIZE
// =====================================

void reshape(int w, int h)
{
    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, WIDTH, 0, HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// =====================================
// 19. INITIALIZATION
// =====================================

void init()
{
    glClearColor(0.95f, 0.95f, 0.95f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, WIDTH, 0, HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// =====================================
// 20. MAIN FUNCTION
// =====================================

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(WIDTH, HEIGHT);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("OpenGL GLUT 2D Basics");

    init();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouse);

    glutTimerFunc(16, update, 0);

    glutMainLoop();

    return 0;
}
