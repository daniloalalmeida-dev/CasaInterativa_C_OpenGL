# CasaInterativa_C_OpenGL
Demonstração de funções do OpenGL em C

Reproduzido uma casa no OpenGL, criando as primitivas com seus respectivos pontos e cores dentro da função desenha().
 
No código existe a função main, onde a comunicação com a OpenGL é estabelecida e são disparadas as inicializações necessárias (inclusive a chamada da função desenha que irá exibir as primitivas criadas na tela), que inclui a definição das funções callback;

• Função que contém as inicializações relativas à exibição (Inicializa);
// Inicializa parâmetros de rendering
void Inicializa (void)
{
// Define a cor de fundo da janela de visualização como preta
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

• Função callback (Desenha) responsável pelo desenho;
Para interagir com o programa sem que seja necessário compilar o código cada vez que o objeto, por exemplo, é rotacionado com um ângulo diferente:
Utilize uma função callback acrescentando a seguinte linha de código na função main, antes da
chamada para a função Inicializa():

glutSpecialFunc(TeclasEspeciais);

Para fazer o tratamento dos eventos, existe a função call-back TeclasEspeciais descrita abaixo. O código desta função permite:
• rotacionar o objeto para esquerda cada vez o usuário pressiona a tecla PageUp
• rotacionar o objeto para direita cada vez o usuário pressiona a tecla PageDn
• aumentar o tamanho do objeto cada vez que o usuário pressiona a tecla Home
• diminuir o tamanho do objeto cada vez que o usuário pressiona a tecla End
• transladar o objeto para cima, para baixo, para a esquerda e para a direita sempre que o usuário pressionar cada uma das teclas de setas.

void TeclasEspeciais(int key, int x, int y)
{
switch (key)
{
case GLUT_KEY_PAGE_UP:
break;
case GLUT_KEY_PAGE_DOWN:
break;
case GLUT_KEY_HOME:
break;
case GLUT_KEY_END:
break;
case GLUT_KEY_UP:
break;
case GLUT_KEY_DOWN:
break;
case GLUT_KEY_LEFT:
break;
case GLUT_KEY_RIGHT:
break;
}
glutPostRedisplay();
}
