#include <GL/glut.h>
float angle = 0,newAngle = 0, oldAngle = 0;
float oldX = 0;
void timer(int t)
{
    if(t<100)glutTimerFunc(33, timer, t+1);
    float alpha = t/100.0;
    angle = alpha*newAngle + (1-alpha)*oldAngle;
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
	glutTimerFunc(0, timer, 0);
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN)oldAngle = angle;
    if(state==GLUT_UP)newAngle = angle;
    oldX = x;
    glutPostRedisplay();
}
void motion(int x, int y)
{
    angle += x-oldX;
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotated(angle, 0, 0, 1);
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣
	glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///設定 GLUT 的顯示模式
	glutCreateWindow("week14");

	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	///glutTimerFunc(3000, timer, 0);
	glutDisplayFunc(display); ///顯示的函式 display()

	glutMainLoop(); ///最後要有 glutMainLoop(); 主要迴圈卡最後面
}
