
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <C:\GLUT\include\GL\glut.h>
#include <stdlib.h>


static void display(void)
{
    float a=1.0;
    //glClearColor(1.0,1.0,0.0,1.0);//color de pantalla
    glClear(GL_COLOR_BUFFER_BIT);//limpia la pantalla
    glPointSize(10);//Grosor del punto
    //GLBegin se utiliza para encapsular o escribir toda primitiva
    //GL_QUADS permite que cada cuadrupla de vertices determine un cuadrado
    glBegin(GL_QUADS);

    for(double i=1.0;i>=0.1;i=i-0.1){
        glColor3f(0.0,a,1.0);//color azul marino/cian(RGB) para los elementos dibujados dentro del glBegin()
        glVertex2d(-i,-i);
        glVertex2d(-i,i);
        glVertex2d(i,i);
        glVertex2d(i,-i);
        if(a==1.0){
            a=a-1;
        }else{
            a=a+1;
        }

    }
        /*Cuadrado
        glVertex2d(-0.1,-0.1);
        glVertex2d(-0.1,0.1);
        glVertex2d(0.1,0.1);
        glVertex2d(0.1,-0.1);*/

    glEnd();//cierra glBegin()
    glFlush();//refuerzo de pintado

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);//recoger los parametros de la linea de comandos
    //le dice al motor grafico que hay que renderizar, refrescar
    //o no la pantalla, que buffer hay que activar o desactivar y
    //la modalidad de colores que queremos usar
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);//establece el tamaño de la pantalla donde se mostrará nuestro dibujo o animacion
    glutInitWindowPosition(0,0);//establecen las coordenadas del lugar de la pantalla donde se quiere que aparezca la ventana
    glutCreateWindow("Dibuja Cuadrado");//Titulo de la Ventana
    glutDisplayFunc(display);//manda llamar el metodo a ejecutar
    //Es entrar al bucle infinito que domina cualquier aplicacion
    //OpenGL y con la sig. funcion se le dice a la libreria que
    //espere eternamenta que se produzcan "eventos"
    glutMainLoop();

}
