/**
 * \file objeto.cpp
 *
 * \brief Este arquivo contem os calculos que foram definidos no arquivo objeto.hpp, sendo este responsavel pela definicoes de caracteristicas de todos
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
 * \date Outubro 2013
 */
 
#include "objeto.hpp"		//rayTracing::Objeto

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
  //Esfera
  /**
   * \fn void Objeto::atualizar_esfera(Vetor* pos_esfera, double _raio, double _kd, double _ks, Vetor* cor);
   *
   * \brief Atualiza os valores da esfera
   *
   * \param pos_esfera - posicao da esfera
   * \param _raio - raio da esfera
   * \param _kd - constante difusa
   * \param _ks - constante especular
   * \param cor - Vetor com contribuicao r, g e b da cor.
   */
  void
  Objeto::atualizar_esfera(Vetor* pos_esfera, double _raio, double _kd, double _ks, Textura* cor){
    //Posicao da esfera
    esfera.pos_x = pos_esfera->vx();
    esfera.pos_y = pos_esfera->vy();
    esfera.pos_z = pos_esfera->vz();

    //Raio da esfera
    esfera.raio = _raio;
		
    //Material da esfera
    esfera.kd = _kd;
    esfera.ks = _ks;
		
    Vetor* contribuicoes_rgb = new Vetor();
    contribuicoes_rgb = cor->map_textura_solida();
		
    //Cor da esfera
    esfera.cor_r = contribuicoes_rgb->vx();
    esfera.cor_g = contribuicoes_rgb->vy();
    esfera.cor_b = contribuicoes_rgb->vz();
  }
	
  /**
   * \fn void	Objeto::modificar_cor_pixel(Textura* cor);
   *
   * \brief Pinta pixels de cores definida pelo range da textura
   *
   * \param cor - Vetor com contribuicao r, g e b da cor.
   */
  void
  Objeto::modificar_cor_pixel(Textura* cor){
    Vetor* contribuicoes_rgb = new Vetor();
    contribuicoes_rgb = cor->map_textura_solida();
		
    //Cor da esfera
    esfera.cor_r = contribuicoes_rgb->vx();
    esfera.cor_g = contribuicoes_rgb->vy();
    esfera.cor_b = contribuicoes_rgb->vz();
  }
	
  /**
   * \fn Vetor* Objeto::posicao_esfera();
   *
   * \brief Retorna a posicao central da esfera.
   */
  Vetor* 
  Objeto::posicao_esfera(){
    Vetor* aux = new Vetor();
    aux->valores_vetor(esfera.pos_x, esfera.pos_y, esfera.pos_z);
    return aux;
  }
	
  /**
   * \fn double Objeto::raio();
   *
   * \brief Retorna o raio.
   */
  double
  Objeto::raio(){
    return esfera.raio;
  }
	
  /**
   * \fn double Objeto::kd_esfera();
   *
   * \brief Retorna a constante difusa do material
   */
  double 
  Objeto::kd_esfera(){
    return esfera.kd;
  }
	
  /**
   * \fn double Objeto::posicao_esfera();
   *
   * \brief Retorna a constante especular do material
   */
  double 
  Objeto::ks_esfera(){
    return esfera.ks;
  }
	
  /**
   * \fn Vetor* Objeto::cor_esfera();
   *
   * \brief Retorna a cor da esfera.
   */
  Vetor* 
  Objeto::cor_esfera(){
    Vetor* aux = new Vetor();
    aux->valores_vetor(esfera.cor_r, esfera.cor_g, esfera.cor_b);
    return aux;
  }	

  //Plano
  /**
   * \fn void Objeto::atualizar_plano(Vetor* pos_plano, double _kd, double _ks, Vetor* cor);
   *
   * \brief Atualiza os valores do plano
   *
   *\param pos_plano - posicao do plano
   * \param _kd - constante difusa
   * \param _ks - constante especular
   * \param cor - Vetor com contribuicao r, g e b da cor.
   */
  void 
  Objeto::atualizar_plano(Vetor* pos_plano, double _kd, double _ks, Vetor* cor){
    //Posicao do plano
    plano.pos_x = pos_plano->vx();
    plano.pos_y = pos_plano->vy();
    plano.pos_z = pos_plano->vz();
		
    //Material da plano
    plano.kd = _kd;
    plano.ks = _ks;
		
    //Cor do plano
    plano.cor_r = cor->vx();
    plano.cor_g = cor->vy();
    plano.cor_b = cor->vz();
  }
	
  /**
   * \fn Vetor* Objeto::posicao_plano();
   *
   * \brief Retorna a posicao central do plano.
   */
  Vetor* 
  Objeto::posicao_plano(){
    Vetor* aux = new Vetor();
    aux->valores_vetor(plano.pos_x, plano.pos_y, plano.pos_z);
    return aux;
  }
	
  /**
   * \fn double Objeto::kd_plano();
   *
   * \brief Retorna a constante difusa do material
   */
  double 
  Objeto::kd_plano(){
    return plano.kd;
  }
	
  /**
   * \fn double Objeto::posicao_plano();
   *
   * \brief Retorna a constante especular do material
   */
  double 
  Objeto::ks_plano(){
    return plano.ks;
  }
	
  /**
   * \fn Vetor* Objeto::cor_plano();
   *
   * \brief Retorna a cor do plano.
   */
  Vetor* 
  Objeto::cor_plano(){
    Vetor* aux = new Vetor();
    aux->valores_vetor(plano.cor_r, plano.cor_g, plano.cor_b);
    return aux;
  }

} //Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class
