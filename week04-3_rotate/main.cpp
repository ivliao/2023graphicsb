#include <GL/glut.h>
float angle = 0;///全域變數
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef(0.5, 0, 0);///移到右邊的
        glRotated(angle, 0, 1, 0);///旋轉中的
        glColor3f(0, 0, 1);///藍色的
        glutSolidTeapot( 0.3 );///茶壺
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣
        glRotated(angle, 0, 1, 0);///旋轉中的
        glTranslatef(0.5, 0, 0);///移到右邊的
        glColor3f(1, 1, 0);///黃色的
        glTranslatef(0, 0.5, 0);
        glutSolidTeapot( 0.3 );///茶壺
    glPopMatrix();///還原矩陣

    glutSwapBuffers();
	angle++; ///角度++
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///設定 GLUT 的顯示模式
	glutCreateWindow("week04");

	glutDisplayFunc(display); ///顯示的函式 display()
	glutIdleFunc(display);
	glutMainLoop(); ///最後要有 glutMainLoop(); 主要迴圈卡最後面
}
