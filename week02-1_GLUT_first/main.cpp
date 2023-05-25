#include <GL/glut.h>  //step01-1 使用 GL/glut.h
void display()
{
    glColor3f(1,1,0); ///step01-2 色彩 黃色
	glutSolidTeapot( 0.5 ); /// 畫出實心的茶壼

    glColor3f(0,1,0); ///step01-2 色彩 綠色
	glutSolidTeapot( 0.3 ); /// 畫出實心的茶壼
	glutSwapBuffers(); ///交換顯示出來
}
int main(int argc, char *argv[])
{ ///這個 main() 是比較厲害的 main()
    glutInit(&argc, argv);  /// 要開始 GLUT 的功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///要設定 GLUT 的顯示模式 ...
    glutCreateWindow("week02"); ///要建一個窗字,叫 "..."
    glutDisplayFunc(display); /// 要顯示的函式 display()
	glutMainLoop(); ///最後要有 glutMainLoop(); 主要迴圈卡最後面
}
