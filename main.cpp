#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

//Coloque aqui as vari�veis globais

// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void)
{

    // Limpa a janela de visualiza��o com a cor
    // de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT);

    //Gerando a matriz modelo
    glMatrixMode(GL_MODELVIEW);
    //Carregando a matriz identidade
    glLoadIdentity();


    //Coloque aqui as fun��es para transforma��es geom�tricas

    // Altera a cor do desenho para azul
	glColor3f(0.0f, 0.0f, 1.0f);
    // Desenha a casa
	glBegin(GL_QUADS);
		glVertex2f(-15.0f,-15.0f);
		glVertex2f(-15.0f,  5.0f);
		glVertex2f( 15.0f,  5.0f);
		glVertex2f( 15.0f,-15.0f);
	glEnd();

	// Altera a cor do desenho para branco
	glColor3f(1.0f, 1.0f, 1.0f);
	// Desenha a porta e a janela
	glBegin(GL_QUADS);
	//porta
		glVertex2f(-4.0f,-14.5f);
		glVertex2f(-4.0f,  0.0f);
		glVertex2f( 4.0f,  0.0f);
		glVertex2f( 4.0f,-14.5f);
    //janela
		glVertex2f( 7.0f,-5.0f);
		glVertex2f( 7.0f,-1.0f);
		glVertex2f(13.0f,-1.0f);
		glVertex2f(13.0f,-5.0f);
	glEnd();

	// Altera a cor do desenho para azul
	glColor3f(0.0f, 0.0f, 1.0f);
	// Desenha as "linhas" da janela
	glBegin(GL_LINES);
		glVertex2f( 7.0f,-3.0f);
		glVertex2f(13.0f,-3.0f);
		glVertex2f(10.0f,-1.0f);
		glVertex2f(10.0f,-5.0f);
	glEnd();

	// Altera a cor do desenho para vermelho
	glColor3f(1.0f, 0.0f, 0.0f);
	// Desenha o telhado
	glBegin(GL_TRIANGLES);
		glVertex2f(-15.0f, 5.0f);
		glVertex2f(  0.0f,17.0f);
		glVertex2f( 15.0f, 5.0f);
	glEnd();

	//Crie aqui as primitivas para desenho da CASA


	//Para colorir uma determinada primitiva, use a fun��o de cor.
	/*glColor3f(0.0f, 0.0f, 1.0f); //Essa fun��o ir� colorir uma primitiva com a cor AZUL
	glBegin(GL_LINES);
    glVertex2f(0.0, 0.0f);
    glVertex2f(0.0f,50.0f);
    glEnd(); */

	//Crie aqui as primitivas necess�rias para criar as linhas que ir�o representar um eixo cartesiano

    //Executa os comandos OpenGL
    glFlush();
}

// Fun��o callback chamada quando o tamanho da janela � alterado
// Essa fun��o permite que com altera��es no tamanho da janela o desenho permane�a sempre proporcional a mesma
void RedimensionaJanela(GLsizei w, GLsizei h)
{
    GLsizei largura, altura;

    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Atualiza as vari�veis
    largura = w;
    altura = h;

    // Especifica as dimens�es da Viewport
    glViewport(0, 0, largura, altura);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de sele��o (esquerda, direita, inferior,
    // superior) mantendo a propor��o com a janela de visualiza��o
    if (largura <= altura)
        gluOrtho2D (-40.0f, 40.0f, -40.0f*altura/largura, 40.0f*altura/largura);
    else
        gluOrtho2D (-40.0f*largura/altura, 40.0f*largura/altura, -40.0f, 40.0f);




}
// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualiza��o aqui
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Branco

    //Fa�a aqui a inicializa��o de variaveis
}

//Coloque aqui a fun��o TeclasEspeciais e fa�a o tratamento adequado das vari�veis
//que manipulam as fun��es de transforma��o geom�tricas
void TeclasEspeciais (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}


// Programa Principal
int main(void)
{
    // Define do modo de opera��o da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Especifica a posi��o inicial da janela GLUT no monitor
    glutInitWindowPosition(1,0);    //define a posi��o em que a janela � inicializada

    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(840,840);    //

    // Cria a janela passando como argumento o t�tulo da mesma
    glutCreateWindow("Nessa casinha moram: Danilo, Milena e Reynold");

    // Registra a fun��o callback de redesenho da janela de visualiza��o
    glutDisplayFunc(Desenha);

    // Registra a fun��o callback de redimensionamento da janela de visualiza��o
    glutReshapeFunc(RedimensionaJanela);

    //Para interagir com o programa sem que seja necess�rio compilar o c�digo novamente

    //Chama a fun��o respons�vel para tratar os eventos de teclado atrav�s das teclas especiais
    glutKeyboardFunc(TeclasEspeciais);

    // Chama a fun��o respons�vel por fazer as inicializa��es
    Inicializa();

    // Inicia o processamento e aguarda intera��es do usu�rio
    glutMainLoop();

    return 0;
}
