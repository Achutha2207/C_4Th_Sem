#include <GL/glut.h>
#include <cmath>
#include <vector>

#define CAR_LENGTH 2.0
#define CAR_WIDTH 1.0
#define HOUSE_SIZE 3.0

GLfloat cameraPosX = 0.0, cameraPosY = 0.0, cameraPosZ = 10.0;
GLfloat cameraYaw = 0.0;

struct Position {
    GLfloat x, z;
};

std::vector<Position> carPositions = {
    { -10.0, -15.0 },
    { 5.0, -20.0 },
    { 8.0, -10.0 },
    { -5.0, -5.0 },
    { 15.0, 0.0 }
};

std::vector<Position> housePositions = {
    { -15.0, 10.0 },
    { 10.0, 15.0 },
    { -5.0, 20.0 },
    { 20.0, -15.0 },
    { -20.0, -20.0 }
};

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawCar(GLfloat x, GLfloat z) {
    glPushMatrix();
    glTranslatef(x, 0.0, z);
    glBegin(GL_QUADS);
    glVertex3f(-CAR_WIDTH / 2, 0.0, -CAR_LENGTH / 2);
    glVertex3f(CAR_WIDTH / 2, 0.0, -CAR_LENGTH / 2);
    glVertex3f(CAR_WIDTH / 2, 0.0, CAR_LENGTH / 2);
    glVertex3f(-CAR_WIDTH / 2, 0.0, CAR_LENGTH / 2);
    glVertex3f(-CAR_WIDTH / 2, CAR_WIDTH / 2, -CAR_LENGTH / 2);
    glVertex3f(CAR_WIDTH / 2, CAR_WIDTH / 2, -CAR_LENGTH / 2);
    glVertex3f(CAR_WIDTH / 2, CAR_WIDTH / 2, CAR_LENGTH / 2);
    glVertex3f(-CAR_WIDTH / 2, CAR_WIDTH / 2, CAR_LENGTH / 2);
    glEnd();
    glPopMatrix();
}

void drawHouse(GLfloat x, GLfloat z) {
    glPushMatrix();
    glTranslatef(x, 0.0, z);
    glBegin(GL_QUADS);
    glVertex3f(-HOUSE_SIZE / 2, 0.0, -HOUSE_SIZE / 2);
    glVertex3f(HOUSE_SIZE / 2, 0.0, -HOUSE_SIZE / 2);
    glVertex3f(HOUSE_SIZE / 2, 0.0, HOUSE_SIZE / 2);
    glVertex3f(-HOUSE_SIZE / 2, 0.0, HOUSE_SIZE / 2);
    glVertex3f(-HOUSE_SIZE / 2, HOUSE_SIZE / 2, -HOUSE_SIZE / 2);
    glVertex3f(HOUSE_SIZE / 2, HOUSE_SIZE / 2, -HOUSE_SIZE / 2);
    glVertex3f(HOUSE_SIZE / 2, HOUSE_SIZE / 2, HOUSE_SIZE / 2);
    glVertex3f(-HOUSE_SIZE / 2, HOUSE_SIZE / 2, HOUSE_SIZE / 2);
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(cameraPosX, cameraPosY, cameraPosZ,
              cameraPosX + cos(cameraYaw), cameraPosY, cameraPosZ - sin(cameraYaw),
              0.0, 1.0, 0.0);
    
    // Draw cars
    for (const auto& pos : carPositions) {
        drawCar(pos.x, pos.z);
    }
    
    // Draw houses
    for (const auto& pos : housePositions) {
        drawHouse(pos.x, pos.z);
    }
    
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            cameraPosX += 0.1 * cos(cameraYaw);
            cameraPosZ -= 0.1 * sin(cameraYaw);
            break;
        case 's':
            cameraPosX -= 0.1 * cos(cameraYaw);
            cameraPosZ += 0.1 * sin(cameraYaw);
            break;
        case 'a':
            cameraYaw += 0.1;
            break;
        case 'd':
            cameraYaw -= 0.1;
            break;
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Virtual Car Park");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(display);
    init();
    glutMainLoop();
    return 0;
}
