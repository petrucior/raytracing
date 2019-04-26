/**
 * \file cena.cpp
 *
 * \brief Este arquivo contem os calculos que foram definidos no arquivo objeto.hpp, sendo este responsavel pela definicoes da cena. Foi utilizado 
 * o texto [introducao ao ray tracing] como base para a implementacao do arquivo.
 * [Texto de introducao ao ray tracing]: www.visgraf.impa.br/Data/RefBib/PS_PDF/silva94/rt.pdf "introducao ao ray tracing"
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal do Rio Grande do Norte \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 *
 * \version 0.1
 * \date Outubro 2013
 */
 
#include "cena.hpp"		//rayTracing::Cena
#include <iostream>	//std
#include <list>		//list

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
  //	Metodos publicos
  //------------------------------
  /**
   * \fn Cena::Cena();
   *
   * \brief Construtor da classe.
   */
  Cena::Cena(){
    //Atualizando valores de background
    background_r = 0.0;
    background_g = 0.0;
    background_b = 0.0;
		
    //Atualizando tamanho
    n = 300;
    m = 300;
  }
	
  /**
   * \fn void Cena::atualizar_cor_background(double r, double g, double b);
   *
   * \brief Atualiza as cores de background.
   *
   * \param r - contribuicao red para o background
   * \param g - contribuicao green para o background
   * \param b - contribuicao blue para o background
   */
  void 
  Cena::atualizar_cor_background(double r, double g, double b){
    background_r = r;
    background_g = g;
    background_b = b;
    /* for (int i = 0; i < n; i++){
       for (int j = 0; j < m; m++){
       background->DrawPixel(i,j, (unsigned char) r, (unsigned char) g, (unsigned char) b);
       }
       } */
  }
	
  /**
   * \fn double Cena::cor_background_r();
   *
   * \brief Retorna a contribuicao red para a cor de background.
   */
  double 
  Cena::cor_background_r(){
    return background_r;
  }
	
  /**
   * \fn double Cena::cor_background_g();
   *
   * \brief Retorna a contribuicao green para a cor de background.
   */
  double 
  Cena::cor_background_g(){
    return background_g;
  }
	
  /**
   * \fn double Cena::cor_background_b();
   *
   * \brief Retorna a contribuicao blue para a cor de background.
   */
  double 
  Cena::cor_background_b(){
    return background_b;
  }
	
  /**
   * \fn void Cena::incluir_objetos_pilha(Objeto* o);
   *
   * \brief Inclue um objeto na pilha.
   *
   * \param o - ponteiro para o objeto que devera ser colocado na pilha
   */
  void 
  Cena::incluir_objetos_pilha(Objeto* o){
    obj.push_front(o);
  }
	
  /**
   * \fn Objeto* Cena::excluir_objetos_pilha();
   *
   * \brief Exclue um objeto na pilha.
   */
  Objeto* 
  Cena::excluir_objetos_pilha(){
    if (obj.size() != 0){
      Objeto* aux = obj.front();
      obj.pop_front();
      return aux;
    }
    else return NULL;
  }
	
  /**
   * \fn int Cena::size_objetos_pilha();
   *
   * \brief calcula quantos objetos tem na pilha e que constitue minha cena.
   *
   * \return A quantidade objetos na pilha
   */
  int 
  Cena::size_objetos_pilha(){
    return obj.size();
  }
	
  /**
   * \fn void Cena::atualizar_ka(double _ka);
   *
   * \brief Atualizando o valor de ka.
   *
   * \param _ka - constante do ambiente
   */
  void 
  Cena::atualizar_ka(double _ka){
    ka = _ka;
  }
	
  /**
   * \fn double Cena::ka_ambiente();
   *
   * \brief Retornando o valor da constante do ambiente
   */
  double 
  Cena::ka_ambiente(){
    return ka;
  }
	
  /**
   * \fn void Cena::dimensao_imagem(int lado, int altura);
   *
   * \brief Atualizando as dimensoes da imagem
   *
   * \param lado - dimensao do lado da imagem
   * \param altura - dimensao da altura da imagem
   */
  void 
  Cena::dimensao_imagem(int lado, int altura){
    n = lado;
    m = altura;
  }
	
  /**
   * \fn int Cena::lado();
   *
   * \brief Retornando o valor do lado da imagem.
   */
  int 
  Cena::lado(){
    return n;
  }
	
  /**
   * \fn int Cena::altura();
   *
   * \brief Retornando o valor da altura da imagem.
   */
  int Cena::altura(){
    return m;
  }

} //Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class
