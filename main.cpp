#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

//Coloque aqui as variáveis globais

// Função callback de redesenho da janela de visualização
void Desenha(void)
{

    // Limpa a janela de visualização com a cor
    // de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT);

    //Gerando a matriz modelo
    glMatrixMode(GL_MODELVIEW);
    //Carregando a matriz identidade
    glLoadIdentity();


    //Coloque aqui as funções para transformações geométricas

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


	//Para colorir uma determinada primitiva, use a função de cor.
	/*glColor3f(0.0f, 0.0f, 1.0f); //Essa função irá colorir uma primitiva com a cor AZUL
	glBegin(GL_LINES);
    glVertex2f(0.0, 0.0f);
    glVertex2f(0.0f,50.0f);
    glEnd(); */

	//Crie aqui as primitivas necessárias para criar as linhas que irão representar um eixo cartesiano

    //Executa os comandos OpenGL
    glFlush();
}

// Função callback chamada quando o tamanho da janela é alterado
// Essa função permite que com alterações no tamanho da janela o desenho permaneça sempre proporcional a mesma
void RedimensionaJanela(GLsizei w, GLsizei h)
{
    GLsizei largura, altura;

    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Atualiza as variáveis
    largura = w;
    altura = h;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, largura, altura);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (esquerda, direita, inferior,
    // superior) mantendo a proporção com a janela de visualização
    if (largura <= altura)
        gluOrtho2D (-40.0f, 40.0f, -40.0f*altura/largura, 40.0f*altura/largura);
    else
        gluOrtho2D (-40.0f*largura/altura, 40.0f*largura/altura, -40.0f, 40.0f);




}
// Função responsável por inicializar parâmetros e variáveis
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização aqui
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Branco

    //Faça aqui a inicialização de variaveis
}

//Coloque aqui a função TeclasEspeciais e faça o tratamento adequado das variáveis
//que manipulam as funções de transformação geométricas
void TeclasEspeciais (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}


// Programa Principal
int main(void)
{
    // Define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Especifica a posição inicial da janela GLUT no monitor
    glutInitWindowPosition(1,0);    //define a posição em que a janela é inicializada

    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(840,840);    //

    // Cria a janela passando como argumento o título da mesma
    glutCreateWindow("Nessa casinha moram: Danilo, Milena e Reynold");

    // Registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(Desenha);

    // Registra a função callback de redimensionamento da janela de visualização
    glutReshapeFunc(RedimensionaJanela);

    //Para interagir com o programa sem que seja necessário compilar o código novamente

    //Chama a função responsável para tratar os eventos de teclado através das teclas especiais
    glutKeyboardFunc(TeclasEspeciais);

    // Chama a função responsável por fazer as inicializações
    Inicializa();

    // Inicia o processamento e aguarda interações do usuário
    glutMainLoop();

    return 0;
}
