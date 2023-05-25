/// week03-1_translate
#include <GL/glut.h>
void display()
{
    glPushMatrix();///備份矩陣
    glTranslatef(0.5, 0.5, 0);
	glutSolidTeapot( 0.3 ); ///這一行可以畫出實心的茶壼
	glPopMatrix();///還原矩陣

	glutSwapBuffers(); ///交換顯示出來
}
int main(int argc, char *argv[])
{
    	glutInit(&argc, argv);
    	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///設定 GLUT 的顯示模式
	glutCreateWindow("GLUT Shapes"); ///建一個窗字,叫 "GLUT Shapes"
	glutDisplayFunc(display); ///顯示的函式 display()
	glutMainLoop(); ///最後要有 glutMainLoop(); 主要迴圈卡最後面
}
