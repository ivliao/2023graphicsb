#include <stdio.h>
#include <GL/glut.h>
FILE*fout=NULL;///一開始檔案沒開,所以是NULL
FILE*fin=NULL;///要讀檔用的指標,一開始也是NULL
float teapotX=0, teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX=(x-150)/150.0;
        teapotY=(150-y)/150.0;
        if(fout==NULL) fout=fopen("file4.txt","w");
            fprintf(fout,"%f %f\n",teapotX,teapotY);
    }
    display();
}
void keyboard(unsigned char key,int x,int y)
{
    if(fin==NULL){///如果檔案還沒fopen(),就打開它
        fclose(fout);///前面mouse會開fout指標,所以要關掉
        fin=fopen("file4.txt","r");///沒開檔案就開它
    }
    fscanf(fin,"%f %f",&teapotX,&teapotY);///真的讀檔
    display();///重畫畫面
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);///keyboard開檔讀檔

    glutMainLoop();
}
