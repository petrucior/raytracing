/**
 * \file main.cpp
 *
 * \brief Arquivo principal do projeto.
 * Obs.: Para gerar a documentacao em doxygen apenas e necessario fazer o seguinte comando: doxygen Doxygen
 * 
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal do Rio Grande do Norte \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 *
 * \version 1.4
 * \date Outubro 2013
 */

// Compila��o: g++ -o t main.cpp -lopengl32 -lglu32 -lglut32 -lm cena.hpp cena.cpp objeto.hpp objeto.cpp vetor.hpp vetor.cpp raio.hpp raio.cpp luz.hpp luz.cpp ray_tracing.hpp ray_tracing.cpp
 
#ifdef __unix__  // Unix
#include <GL/gl.h>  //GLdouble, Glint, glDrawPixels                             
#include <GL/glu.h>
#include <GL/glut.h> //gluUnProject
#else // Apple
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
/*#else  // Windows                                                               
#include <w32api/GL/gl.h> //GLdouble, Glint, glDrawPixels                       
#include <w32api/GL/glu.h>
#include <w32api/GL/glut.h> //gluUnProject                                      
#endif*/

#include <iostream> //std::endl, std::cin e std::cout
#include <ctime> //clock		
#include "cena.hpp" //rayTracing::Cena
#include "objeto.hpp" //rayTracing::Objeto
#include "vetor.hpp" //rayTracing::Vetor
#include "raio.hpp" //rayTracing::Raio
#include "luz.hpp" //rayTracing::Luz
#include "textura.hpp" //rayTracing::Textura
#include "ray_tracing.hpp" //rayTracing::Ray_tracing

using rayTracing::Vetor;
using rayTracing::Raio;
using rayTracing::Luz;
using rayTracing::Cena;
using rayTracing::Objeto;
using rayTracing::Textura;
using rayTracing::Ray_tracing;

GLubyte imagem[300][300][3];
/**
 * \fn void print_pixel(int x, int y, double red, double green, double blue);
 *
 * \brief Pinta um determinado pixel x, y da imagem com a cor que foi passado.
 *
 * \param x, y - coordenadas de pixel que deverao ser pintadas.
 * \param red, green, blue - valor do rgb de 0 - 255.
 */
void print_pixel(int x, int y, double red, double green, double blue){
  /* 	imagem[x][y][0] = (GLubyte) red;
	imagem[x][y][1] = (GLubyte) green;
	imagem[x][y][2] = (GLubyte) blue;
  */
}

/**
 * \fn void init(void);
 *
 * \brief Inicia a tela de background.
 */
void init(void){
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

/**
 * \fn void display(void);
 *
 * \brief Pinta toda a tela.
 */
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glRasterPos2i(0, 0);

  double start_clock = clock();
  //Primeira esfera
  Vetor* c_esfera1 = new Vetor();
  c_esfera1->valores_vetor(150.0, 150.0, 0.0);
  //Limites da cor do objeto
  Vetor* range1 = new Vetor();	//Vetor de limite superior da cor
  range1->valores_vetor(0.0, 0.0, 255.0);
  Vetor* range2 = new Vetor();	//Vetor de limite inferior da cor
  range2->valores_vetor(0.0, 0.0, 254.0);
  Textura* cores1 = new Textura(range1, range2);
  Objeto* esfera1 = new Objeto();
  esfera1->atualizar_esfera(c_esfera1, 40.0, 0.3, 0.3, cores1);
	
  //segunda esfera
  Vetor* c_esfera2 = new Vetor();
  c_esfera2->valores_vetor(150.0, 100.0, 0.0);
  //Limites da cor do objeto
  Vetor* range3 = new Vetor();	//Vetor de limite superior da cor
  range3->valores_vetor(0.0, 255.0, 0.0);
  Vetor* range4 = new Vetor();	//Vetor de limite inferior da cor
  range4->valores_vetor(0.0, 254.0, 0.0);
  Textura* cores2 = new Textura(range3, range4);
  Objeto* esfera2 = new Objeto();
  esfera2->atualizar_esfera(c_esfera2, 60.0, 0.3, 0.3, cores2);
	
  //terceira esfera
  Vetor* c_esfera3 = new Vetor();
  c_esfera3->valores_vetor(150.0, 200.0, 0.0);
  //Limites da cor do objeto
  Vetor* range5 = new Vetor();	//Vetor de limite superior da cor
  range5->valores_vetor(255.0, 0.0, 0.0);
  Vetor* range6 = new Vetor();	//Vetor de limite inferior da cor
  range6->valores_vetor(254.0, 0.0, 0.0);
  Textura* cores3 = new Textura(range5, range6);
  Objeto* esfera3 = new Objeto();
  esfera3->atualizar_esfera(c_esfera3, 60.0, 0.3, 0.3, cores3);

  //quarta esfera
  Vetor* c_esfera4 = new Vetor();
  c_esfera4->valores_vetor(100.0, 150.0, 0.0);
  //Limites da cor do objeto
  Vetor* range7 = new Vetor();	//Vetor de limite superior da cor
  range7->valores_vetor(255.0, 254.0, 0.0);
  Vetor* range8 = new Vetor();	//Vetor de limite inferior da cor
  range8->valores_vetor(254.0, 254.0, 0.0);
  Textura* cores4 = new Textura(range7, range8);
  Objeto* esfera4 = new Objeto();
  esfera4->atualizar_esfera(c_esfera4, 60.0, 0.3, 0.3, cores4);
	
  //Criando a cena
  Cena* cena = new Cena();
  cena->atualizar_cor_background(0.0, 0.0, 0.0);
  cena->atualizar_ka(1.2);
  //incluindo primeira esfera
  cena->incluir_objetos_pilha(esfera1);
  //incluindo segunda esfera
  cena->incluir_objetos_pilha(esfera2);
  //incluindo terceira esfera
  cena->incluir_objetos_pilha(esfera3);
  //incluindo terceira esfera
  //cena->incluir_objetos_pilha(esfera4);
	
  //std::cout << ("cena: ")<< cena->size_objetos_pilha() << std::endl;
	
	
  //Lookfrom
  Vetor* lookfrom = new Vetor();
  lookfrom->valores_vetor(155.0, 150.0, -150.0);
  //Lookat
  Vetor* lookat = new Vetor();
  lookat->valores_vetor(2.0, 1.0, 0.0);
	
  //Luz
  Luz* luz = new Luz();
  luz->posicao_luz(3.0, 3.0, 3.0);
  //O valor de _nshin (espalhamento da luz) estabelecido como 2.0
  luz->atualizar_constantes_phong(0.4, esfera1->ks_esfera(), esfera1->kd_esfera(), 200.0, 192.0, 192.0, 192.0 , 1.0, 2.0);
	
  //Matrizes de visualizacao
  GLint viewport[4];
  GLdouble modelview[16], projection[16];

  //Parte do c�digo que provoca um erro segmentation fault talvez por eu nao ter especificado a viewport
  //------------------------------------------------------------------------------------------------------
  glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
  glGetDoublev( GL_PROJECTION_MATRIX, projection );
  glGetIntegerv( GL_VIEWPORT, viewport );
  //------------------------------------------------------------------------------------------------------
	
  //Aplicacao do ray tracing
  Ray_tracing* obj_ray_tracing = new Ray_tracing();
  //imagem = obj_ray_tracing -> print_imagem(cena, luz, lookfrom, lookat, modelview, projection, viewport);
  obj_ray_tracing -> print_imagem(cena, luz, lookfrom, lookat, modelview, projection, viewport, *&imagem);
	
  std::cout << "passei pela pintura da imagem" << std::endl;
  /* //pintando a imagem
     for (int i = 0; i < 300; i++){
     for (int j = 0; j < 300; j++){
     print_pixel(i, j, 255.0, 255.0, 0.0);
     }
     } */
	
  unsigned int n = 300;
  unsigned int m = 300;
  glDrawPixels(n, m, GL_RGB, GL_UNSIGNED_BYTE, imagem);
   
  double stop_clock = clock();
  std::cout << "time: " << (stop_clock-start_clock)/(CLOCKS_PER_SEC) << " segundos" << std::endl;
  glFlush();
}

/**
 * \fn void reshape(int lado, int altura);
 *
 * \brief Redimensiona a janela quando o usuario a altera.
 * 
 * \param lado - coordenada x da imagem
 * \param altura - coordenada y da imagem
 */
void reshape(int w, int h){
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho (0.0, (GLfloat) w, 0.0, (GLfloat) h, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  init();
  glutReshapeFunc(reshape);
  //pintando a imagem
  /* for (int i = 0; i < n; i++){
     for (int j = 0; j < m; j++){
     print_pixel(i, j, 255.0, 255.0, 0.0);
     }
     }  */
  /* 
  //Primeira esfera
  Vetor* c_esfera = new Vetor();
  c_esfera->valores_vetor(2.0,2.0,1.0);
  Vetor* cores = new Vetor();
  cores->valores_vetor(1.0, 0.0, 0.0);
  Objeto* esfera = new Objeto();
  esfera->atualizar_esfera(c_esfera, 1.0, 0.0, 1.0, cores);
	
  //Criando a cena
  Cena* cena = new Cena();
  cena->atualizar_cor_background(0.0, 0.0, 0.0);
  cena->atualizar_ka(1.2);
  cena->incluir_objetos_pilha(esfera);
	
  //Lookfrom
  Vetor* lookfrom = new Vetor();
  lookfrom->valores_vetor(2.0, 3.0, 2.0);
  //Lookat
  Vetor* lookat = new Vetor();
  lookat->valores_vetor(2.0, 1.0, 0.0);
	
  //Luz
  Luz* luz = new Luz();
  luz->posicao_luz(3.0, 3.0, 3.0);
  luz->atualizar_constantes_phong(0.4, 0.3, 0.3, 200.0, 250.0, 0.0, 0.0 , 1.0, 1.0);
	
  Ray_tracing* obj_ray_tracing = new Ray_tracing();
  imagem = obj_ray_tracing -> print_imagem(cena, luz, lookfrom, lookat, GL_MODELVIEW, GL_PROJECTION, GL_VIEWPORT);
  */
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
