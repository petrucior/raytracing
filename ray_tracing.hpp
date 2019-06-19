/**
 * \file ray_tracing.hpp
 *
 * \brief Este arquivo e um pacote que contem as definicoes que deverao ser apresentados na integra no arquivo ray_tracing.cpp, sendo este 
 * responsavel por todo processo logico e de implementacao do ray tracing. Foi utilizado o texto [introducao ao ray tracing] como base para a 
 * implementacao do arquivo.
 * [Texto de introducao ao ray tracing]: www.visgraf.impa.br/Data/RefBib/PS_PDF/silva94/rt.pdf "introducao ao ray tracing"
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal do Rio Grande do Norte \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 *
 * \version 0.3
 * \date Outubro 2013
 */
 
#ifndef _RAY_TRACING_HPP
#define _RAY_TRACING_HPP

#include "vetor.hpp"		//rayTracing::Vetor
#include "raio.hpp"			//rayTracing::Raio
#include "luz.hpp"			//rayTracing::Luz
#include "objeto.hpp"		//rayTracing::Objeto
#include "cena.hpp"			//rayTracing::Cena

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

/** 
 * \defgroup RayTracingNameSpace Namespace rayTracing.
 * @{
 */

/**
 * \namespace rayTracing
 *
 * \brief O espaco de nomes rayTracing contem todas os arquivos que sao utilizados para sua implementacao.
 */
namespace rayTracing{
  /**
   * \class Ray_tracing
   * 
   * \brief Define a logica e descreve os metodos responsaveis pelo funcionamento do ray tracing.
   */
  class Ray_tracing{
    //------------------------------
    //	Atributos privados
    //------------------------------
  private:
    /**
     * \fn void calculo_posicao_mundo(GLdouble winX, GLdouble winY, GLdouble winZ,
     * GLdouble model[16], GLdouble proj[16], GLint view[4],
     * GLdouble* objX, GLdouble* objY, GLdouble* objZ);
     *
     * \brief Metodo que calcula as posicoes de mundo atraves da funcao gluUnProject
     *
     * \param winX, winY, winZ - coordenadas da janela
     * \param model, proj, view - matrizes modelview, projection e viewport.
     * \param objX, objY, objZ - coordenadas do objeto
     */
    void calculo_posicao_mundo(GLdouble winX, GLdouble winY, GLdouble winZ,
			       const GLdouble model[16], const GLdouble proj[16], const GLint view[4],
			       GLdouble* objX, GLdouble* objY, GLdouble* objZ);
									   
    //GLubyte imagem[300][300][3];
    //------------------------------
    //	Metodos publicos
    //------------------------------
  public:
    /**
     * \fn GLubyte print_imagem(Cena* cena, Luz* luz, Vetor* lookfrom, Vetor* lookat, 
     * GLdouble model[16], GLdouble proj[16], GLint view[4], GLubyte imagem[300][300][3]);
     *
     * \brief Metodo para a pintura pixel a pixel da imagem
     *
     * \param cena - Cena que sera aplicado o ray tracing
     * \param luz - Luz no objeto
     * \param lookfrom - posicao da camera
     * \param lookat - posicao para onde esta apontada a camera
     * \param model, proj, view - matrizes modelview, projection e viewport
     * \param imagem - Imagem analisada
     */
    //Metodo para a pintura pixel a pixel da imagem
    const GLvoid print_imagem(Cena* cena, Luz* luz, Vetor* lookfrom, Vetor* lookat,
			      GLdouble model[16], GLdouble proj[16], GLint view[4], GLubyte imagem[300][300][3]);
    /* GLubyte print_imagem(Cena* cena, Luz* luz, Vetor* lookfrom, Vetor* lookat,
       GLdouble model[16], GLdouble proj[16], GLint view[4]); */
    /* GLvoid* print_imagem(Cena* cena, Luz* luz, Vetor* lookfrom, Vetor* lookat,
       GLdouble model[16], GLdouble proj[16], GLint view[4]); */

  };

} ////Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class

#endif
	
