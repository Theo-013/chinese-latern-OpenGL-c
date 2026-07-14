#include <GL/freeglut.h>
#include <math.h>

float angle = 0.0f;
float direction = 1.0f;

void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // Swinging rotation
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(sinf(angle) * 10, 0, 0, 1);

    // Draw lantern base
    glColor3f(1.0f, 0.3f, 0.0f); // Orange
    drawCircle(0.0f, 0.0f, 0.3f, 100);

    // Glow effect
    glColor4f(1.0f, 0.5f, 0.0f, 0.2f);
    for (float r = 0.35f; r < 0.5f; r += 0.02f) {
        drawCircle(0.0f, 0.0f, r, 100);
    }

    // Lantern tail
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -0.5f);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void update(int value) {
    angle += 0.05f;
    if (angle > 2 * 3.1415f) angle = 0;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Chinese Lantern - FreeGLUT");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
