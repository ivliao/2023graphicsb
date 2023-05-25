///week03-2_translate_mouse
#include <GL/glut.h>
float X=0, Y=0, Z=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();///備份矩陣
        glTranslatef( X, Y, Z );
        glutSolidTeapot( 0.3 ); ///這一行可以畫出實心的茶壼
	glPopMatrix();///還原矩陣

	glutSwapBuffers(); ///交換顯示出來
}
void mouse( int button, int state, int x, int y )
{
    X = (x-150)/150.0;
    Y = -(y-150)/150.0;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///設定 GLUT 的顯示模式
	glutCreateWindow("week03"); ///建一個窗字,叫 "week03"

	glutMouseFunc(mouse);
	glutDisplayFunc(display); ///顯示的函式 display()
	glutMainLoop(); ///最後要有 glutMainLoop(); 主要迴圈卡最後面
}
