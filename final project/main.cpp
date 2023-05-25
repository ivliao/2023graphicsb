#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4]={1,1,1,1};///用show[i]決定要不要顯示
int ID=3;///0:頭 1:身體 2:上手臂 3:下手臂
float angle[20]={};
void keyboard (unsigned char key, int x, int y){
    if (key=='0') ID = 0;
    if (key=='1') ID = 1;
    if (key=='2') ID = 2;
    if (key=='3') ID = 3;

    glutPostRedisplay();
}
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0, teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2, 0.2, 0.2);///week13-02-2
        if(body==NULL){
            head=glmReadOBJ("model/head.obj");
            body=glmReadOBJ("model/body.obj");
            uparmR=glmReadOBJ("model/uparmR.obj");
            lowarmR=glmReadOBJ("model/lowarmR.obj");

            ///glmUnitize(body);///week13-02-1這行之後會改
        }
        if(ID==0) glColor3f(1,0,0);///設紅色
        else glColor3f(1,1,1);
        if (show[0]) glmDraw(head, GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);///設紅色
        else glColor3f(1,1,1);
        if (show[1]) glmDraw(body, GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(-1.200000, +0.453333, 0);
            glRotatef(angle[2], 0, 0, 1);
            ///glTranslatef(teapotX, teapotY, 0);
            glTranslatef(1.200000, -0.453333, 0);

            if(ID==2) glColor3f(1,0,0);///設紅色
            else glColor3f(1,1,1);
            if (show[2]) glmDraw(uparmR, GLM_MATERIAL);
            glPushMatrix();
            glTranslatef(-1.946666, +0.180001, 0);
            //glTranslatef(teapotX, teapotY, 0);
            glRotatef(angle[3], 0, 0, 1);
            glTranslatef(1.946666, -0.180001, 0);
            if(ID==3) glColor3f(1,0,0);///設紅色
            else glColor3f(1,1,1);
            if (show[3]) glmDraw(lowarmR, GLM_MATERIAL);
        glPopMatrix();
        glPopMatrix();


    glPopMatrix();
    glColor3f(0,1,0);///放小茶壺在中心點當參考
    glutSolidTeapot(0.02);///放小茶壺在中心點當參考
    glutSwapBuffers();
}
int oldX=0, oldY=0;///week13-03-2
void motion(int x, int y){
    teapotX += (x -oldX)/150.0;
    teapotY -= (y -oldY)/150.0;
    printf("glTranslatef(%f, %f, 0);\n",teapotX,teapotY);
    angle[ID] += x-oldX;
    oldX=x;
    oldY=y;

    glutPostRedisplay();

}

void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;///teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;///teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file4.txt", "w");
        fprintf(fout, "%f %f\n", teapotX, teapotY);
    }
    display();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard); ///step02-2 keyboard

    glutMainLoop();
}

