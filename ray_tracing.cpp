/**
 * \file ray_tracing.cpp
 *
 * \brief Este arquivo contem a implementacao que foi definida no arquivo ray_tracing.hpp. Este arquivo corresponde a juncao de todas as classes
 * que foram implementadas para o projeto e resolver o problema. Para tanto, se fez uso do texto [Texto de introducao ao ray tracing] como
 * referencial tecnico alem do site de [Tabela de cores] para delimitar o rgb.
 * [Texto de introducao ao ray tracing]: www.visgraf.impa.br/Data/RefBib/PS_PDF/silva94/rt.pdf "introducao ao ray tracing"
 * [Tabela de cores]: http://www.mxstudio.com.br/Conteudos/Dreamweaver/Cores.htm "tabela de cores em rgb"
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal do Rio Grande do Norte \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 *
 * \version 0.4
 * \date Outubro 2013
 */
#include <iostream>			//std::endl, std::cin e std::cout
#include "ray_tracing.hpp"	//rayTracing::Ray_tracing
#include "vetor.hpp"		//rayTracing::Vetor
#include "raio.hpp"			//rayTracing::Raio
#include "luz.hpp"			//rayTracing::Luz
#include "objeto.hpp"		//rayTracing::Objeto
#include "cena.hpp"			//rayTracing::Cena

#ifdef __unix__   // Unix
#include <GL/gl.h>		//GLdouble, Glint, glDrawPixels
#include <GL/glu.h>
#include <GL/glut.h>		//gluUnProject
#else  // Windows
#include <w32api/GL/gl.h>	//GLdouble, Glint, glDrawPixels
#include <w32api/GL/glu.h>
#include <w32api/GL/glut.h>	//gluUnProject
#endif

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
  //------------------------------
  //	Metodos privados
  //------------------------------
  /**
   * \fn void Ray_tracing::calculo_posicao_mundo(GLdouble winX, GLdouble winY, GLdouble winZ,
   GLdouble model[16], GLdouble proj[16], GLint view[4],
   GLdouble* objX, GLdouble* objY, GLdouble* objZ);
   *
   * \brief Metodo que calcula as posicoes de mundo atraves da funcao gluUnProject
   *
   * \param winX, winY, winZ - coordenadas da janela
   * \param model, proj, view - matrizes modelview, projection e viewport.
   * \param objX, objY, objZ - coordenadas do objeto
   */
  void 
  Ray_tracing::calculo_posicao_mundo(GLdouble winX, GLdouble winY, GLdouble winZ,
				     const GLdouble model[16], const GLdouble proj[16],const GLint view[4],
				     GLdouble* objX, GLdouble* objY, GLdouble* objZ){
    gluUnProject(winX, winY, winZ, model, proj, view, objX, objY, objZ);
    return;
  }
	
  //------------------------------
  //	Metodos publicos
  //------------------------------
  /**
   * \fn GLubyte Ray_tracing::print_imagem(Cena* cena, Luz* luz, Vetor* lookfrom, Vetor* lookat, 
   GLdouble model[16], GLdouble proj[16], GLint view[4], GLubyte imagem[300][300][3]);
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
  //GLubyte
  const GLvoid
  Ray_tracing::print_imagem(Cena* cena, Luz* luz, Vetor* lookfrom, Vetor* lookat,
			    GLdouble model[16], GLdouble proj[16], GLint view[4], GLubyte imagem[300][300][3]){
    Cena* cena_auxiliar = new Cena();				//Objetivo de nao perder os objetos da cena
    Objeto* objeto_salvo = new Objeto();				//Objeto que sera pintado
    double t_aux;							//t calculado para o objeto pintado
    for (int i = 0; i < cena->lado(); i++){				//lado
      for (int j = 0; j < cena->altura(); j++){			//Altura
	//Colocando valor absurdo para o t para primeiro valor
	t_aux = -1.0;
	//Encontrando lookat's
	GLdouble x, y, z;
	GLint realy = view[3] - (GLint)j - 1;
	calculo_posicao_mundo((GLdouble) i, (GLdouble) realy, 1.0, model, proj, view, &x, &y, &z);
	Vetor* lookat = new Vetor();
	lookat->valores_vetor((double)x, (double)y, (double)z);
		    
	//Definicao do Raio
	Raio* r = new Raio();
		    
	//Tenho que fazer com que o conteudo permaneca inalterado.
	int tamanho = cena->size_objetos_pilha();
		    
	for (int k = 0; k < tamanho; k++){	//Varrendo objetos da cena
	  //Retirando o objeto da cena
	  Objeto* obj = cena->excluir_objetos_pilha();
			    
	  r->atualizar_vetores(lookfrom, lookat, obj);
			    
	  double t = r -> calcula_t();
			    
	  if (t > 0.0){		//Verificar se o t encontrado e maior que zero
	    if (t_aux == -1.0){	//Nao tem nenhum valor maior que 0 que seja menor que -1
	      t_aux = t;
	      objeto_salvo = obj;
	    }
	    else{
	      if (t < t_aux){		//Verificar se e menor que os t's encontrados
		t_aux = t;
		objeto_salvo = obj;
	      }
	    }
	  }
	  cena_auxiliar->incluir_objetos_pilha(obj);
	}
			
	Cena* tmp = cena;
	cena = cena_auxiliar;
	cena_auxiliar = tmp;
	//cena = cena_auxiliar;
		    
	if (t_aux > 0.0){	//esfera nao foi interceptada
	  //atualizando o raio
	  r->atualizar_vetores(lookfrom, lookat, objeto_salvo);
			  
	  //Interseccao com a esfera
	  Vetor* int_esfera = new Vetor();
	  int_esfera = r->interseccao_esfera(t_aux);
		      
	  //Atualiza a luz
	  luz->atualizar_vetores_auxiliares(int_esfera, objeto_salvo->posicao_esfera(), lookfrom);
			  
	  //Pegando o valor da contribuicao red, blue e green do objeto
	  Vetor* cores_objeto = new Vetor();
			  
	  //
	  //	Textura fixa - definido no main
	  //
	  cores_objeto = objeto_salvo->cor_esfera();	//Determina uma cor fixa para toda a esfera
			  
	  //
	  //	Textura variavel com o pixel - Aplicando textura em cada pixel da esfera
	  //
	  //Limites da cor do objeto
	  //Vetor* range_areia_superior = new Vetor();	//Vetor de limite superior da cor
	  //range_areia_superior->valores_vetor(223.0, 246.0, 143.0);
	  //Vetor* range_areia_inferior = new Vetor();	//Vetor de limite inferior da cor
	  //range_areia_inferior->valores_vetor(139.0, 129.0, 76.0);
	  //Textura* cor_areia = new Textura(range_areia_superior, range_areia_inferior);
	  //Aplicando a textura ao objeto
	  //objeto_salvo->modificar_cor_pixel(cor_areia);
	  //cores_objeto = objeto_salvo->cor_esfera();
			  
			  
	  //Calculando as contribuicoes de luz red, blue e green para o determinado pixel
	  Vetor* cor_luz = new Vetor();
	  double valor_luz_vermelha = luz->calcula_luz_red();
	  double valor_luz_verde = luz->calcula_luz_green();
	  double valor_luz_azul = luz->calcula_luz_blue();
	  cor_luz->valores_vetor(valor_luz_vermelha, valor_luz_verde, valor_luz_azul);
			  
	  //criando o dado			  
	  imagem[i][j][0] = (GLubyte)(cor_luz->vx() * (cores_objeto->vx()/cores_objeto->norma()));
	  imagem[i][j][1] = (GLubyte)(cor_luz->vy() * (cores_objeto->vy()/cores_objeto->norma()));
	  imagem[i][j][2] = (GLubyte)(cor_luz->vz() * (cores_objeto->vz()/cores_objeto->norma()));
	}
	else{
	  //pinta de background
	  imagem[i][j][0] = (GLubyte)cena->cor_background_r();
	  imagem[i][j][1] = (GLubyte)cena->cor_background_g();
	  imagem[i][j][2] = (GLubyte)cena->cor_background_b();
	}
      }
    }
    //return imagem;
    return;
  }
	
} //Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class
