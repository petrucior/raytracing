/**
 * \file textura.cpp
 *
 * \brief Este arquivo contem as resolucoes que foram definidas no arquivo objeto.hpp, sendo este responsavel pela definicoes de criacao da textura e outras caracteristicas de todos
 * os objetos da cena que serao renderizados. Foi utilizado o texto [introducao ao ray tracing] como base para a implementacao do arquivo.
 * [Texto de introducao ao ray tracing]: www.visgraf.impa.br/Data/RefBib/PS_PDF/silva94/rt.pdf "introducao ao ray tracing"
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal do Rio Grande do Norte \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 *
 * \version 0.2
 * \date Novembro 2013
 */
 
#include "textura.hpp"		//rayTracing::Textura
#include <iostream>
#include <stdlib.h>			//rand
#include <cmath>			//ceil

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
   * \fn int Textura::rand_red();
   *
   * \brief Escolhe a parte red randomicamente.
   *
   * \return Valor randomico para a contribuicao vermelha.
   */
  int 
  Textura::rand_red(){
    int r;
    int x = ceil(inicio_range->vx());
    int y = ceil(final_range->vx());
    if (x != y){	//Para evitar uma excessao de provocada no rand
      r = (rand() % x + y);
    }
    else r = 0;
    return r;
  }

  /**
   * \fn int Textura::rand_green();
   *
   * \brief Escolhe a parte red randomicamente.
   *
   * \return Valor randomico para a contribuicao verde.
   */
  int 
  Textura::rand_green(){
    int g;
    int x = ceil(inicio_range->vy());
    int y = ceil(final_range->vy());
    if (x != y){	//Para evitar uma excessao de provocada no rand
      g = (rand() % x + y);
    }
    else g = 0;
    return g;
  }

  /**
   * \fn int Textura::rand_blue();
   *
   * \brief Escolhe a parte red randomicamente.
   *
   * \return Valor randomico para a contribuicao azul.
   */
  int 
  Textura::rand_blue(){
    int b;
    int x = ceil(inicio_range->vz());
    int y = ceil(final_range->vz());
    if (x != y){ 	//Para evitar uma excessao de provocada no rand
      b = (rand() % x + y);
    }
    else b = 0;
    return b;
  }

  //------------------------------
  //	Metodos privados
  //------------------------------
  /**
   * \fn Textura::Textura(Vetor* _inicio_range, Vetor* _final_range);
   *
   * \brief Construtor da classe textura.
   *
   * \param _inicio_range - inicio dos limites
   * \param _final_range - final dos limites
   */
  Textura::Textura(Vetor* _inicio_range, Vetor* _final_range){
    inicio_range = new Vetor();
    final_range = new Vetor();
    inicio_range = _inicio_range;
    final_range = _final_range;
  }
		
  /**
   * \fn Vetor* Textura::map_textura_solida();
   *
   * \brief Metodo que mapeia a textura solida.
   *
   * \return Vetor com contribuicao r, g e b.
   */
  Vetor*
  Textura::map_textura_solida(){
    //Calculando randomicamente a contribuicao do r, g e b
    double r = rand_red();
    double g = rand_green();
    double b = rand_blue();
		
    //criando um vetor que armazenara as contribuicoes do r, g e b
    Vetor* textura = new Vetor();
    textura->valores_vetor(r, g, b);

    //retornando o vetor de textura
    return textura;
  }
	
} //Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class
