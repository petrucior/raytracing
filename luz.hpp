/**
 * \file luz.hpp
 *
 * \brief Este arquivo e um pacote que contem as definicoes que deverao ser apresentados na integra no arquivo luz.cpp, sendo este responsavel pelas 
 * definicoes de posicao e outras caracteristicas ligadas a luz da cena. Foi utilizado o texto [introducao ao ray tracing] como base para a 
 * implementacao do arquivo.
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
 
#ifndef _LUZ_HPP
#define _LUZ_HPP

#include "vetor.hpp"	//rayTracing::Vetor

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
   * \class Luz
   * 
   * \brief Define as caracteristicas como posicao e vetores para as luzes do ambiente.
   */
  class Luz{
    //------------------------------
    //	Atributos privados
    //------------------------------
  private:
    Vetor* pos_luz;	///< Vetor da posicao da luz
		
    //Coordenadas dos vetores de interseccao com a esfera, centro da esfera e posicao da camera.
    double int_esf_x;	///< Coordenada x do vetor de interseccao com a esfera
    double int_esf_y;	///< Coordenada y do vetor de interseccao com a esfera
    double int_esf_z;	///< Coordenada z do vetor de interseccao com a esfera
    double c_esf_x;		///< Coordenada x do vetor do centro da esfera
    double c_esf_y;		///< Coordenada y do vetor do centro da esfera
    double c_esf_z;		///< Coordenada z do vetor do centro da esfera
    double lkf_x;		///< Coordenada x do vetor da posicao da camera
    double lkf_y;		///< Coordenada y do vetor da posicao da camera
    double lkf_z;		///< Coordenada z do vetor da posicao da camera
		
    //Vetores para o calculo da lei de phong
    Vetor* n;	///< Vetor da normal
    Vetor* l; ///< Vetor do ponto de luz
    Vetor* o; ///< Vetor do observador
    Vetor* r; ///< Vetor da reflexao da luz
		
    //Constantes para o calculo da lei de phong
    double ka; ///< Constante ambiente
    double ks; ///< Constante especular
    double kd; ///< Constante difusa
		
    double Ia; ///< Intensidade do ambiente
    double Ilight_red; ///< Intensidade vermelha da luz
    double Ilight_green; ///< Intensidade verde da luz
    double Ilight_blue; ///< Intensidade azul da luz
		
    double fat; ///< Fator de atenuacao
    double nshin; ///< Espalhamento da luz no objeto
		
    //------------------------------
    //	Metodos publicos
    //------------------------------
  public:
    /**
     * \fn Luz();
     *
     * \brief Construtor da classe.
     */
    Luz();
		
    /**
     * \fn void posicao_luz(double pos_luz_x, double pos_luz_y, double pos_luz_z);
     *
     * \brief Atualiza os valores dos vetores de posicao da luz.
     *
     * \param pos_luz_x - posicao x da luz
     * \param pos_luz_y - posicao y da luz
     * \param pos_luz_z - posicao z da luz
     */
    void posicao_luz(double pos_luz_x, double pos_luz_y, double pos_luz_z);
		
    /**
     * \fn void atualizar_vetores_auxiliares(Vetor* interseccao_esfera, Vetor* centro_esfera, Vetor* lookfrom);
     *
     * \brief Pega todos os vetores necessarios para quantificacao da luz em um determinado ponto.
     *
     * \param interseccao_esfera - ponteiro para o vetor de interseccao da esfera
     * \param centro_esfera - ponteiro para o vetor de centro da esfera
     * \param lookfrom - ponteiro para o vetor de posicao da camera
     */
    void atualizar_vetores_auxiliares(Vetor* interseccao_esfera, Vetor* centro_esfera, Vetor* lookfrom);
		
    /**
     * \fn void vetor_normal();
     *
     * \brief Encontra o vetor normal do ponto da interseccao.
     */
    void vetor_normal();
		
    /**
     * \fn void vetor_luz();
     *
     * \brief Encontra o vetor da luz partindo do ponto de interseccao.
     */
    void vetor_luz();
		
    /**
     * \fn void vetor_observador();
     *
     * \brief Encontra o vetor do ponto de interseccao da esfera ate o observador
     */
    void vetor_observador();
		
    /**
     * \fn void vetor_reflexao();
     *
     * \brief Encontra o vetor de reflexao.
     */
    void vetor_reflexao();
		
    /**
     * \fn void atualizar_constantes_phong(double _ka, double _ks, double _kd, double _Ia, double _Ilight_red, double _Ilight_green, double _Ilight_blue, double _fat, double _nshin);
     *
     * \brief Atualiza as variaveis referentes as constantes de phong
     * 
     * \param _ka - constante ambiente
     * \param _ks - constante especular
     * \param _kd - constante difusa
     * \param _Ia - intensidade do ambiente
     * \param _Ilight_red - intensidade vermelha da luz
     * \param _Ilight_green - intensidade verde da luz
     * \param _Ilight_blue - intensidade azul da luz
     * \param _fat - fator de atenuacao
     * \param _nshin - espalhamento da luz (Utilize 2.0)
     */
    void atualizar_constantes_phong(double _ka, double _ks, double _kd, 
				    double _Ia, double _Ilight_red, double _Ilight_green, double _Ilight_blue,
				    double _fat, double _nshin);
		
    /**
     * \fn double calcula_luz_red();
     *
     * \brief Calcula o valor da luz de intensidade vermelha para o ponto de interseccao.
     * 
     * \return O valor da luz no ponto de interseccao.
     */
    double calcula_luz_red();

    /**
     * \fn double calcula_luz_green();
     *
     * \brief Calcula o valor da luz de intensidade verde para o ponto de interseccao.
     * 
     * \return O valor da luz no ponto de interseccao.
     */
    double calcula_luz_green();
		
    /**
     * \fn double calcula_luz_blue();
     *
     * \brief Calcula o valor da luz de intensidade azul para o ponto de interseccao.
     * 
     * \return O valor da luz no ponto de interseccao.
     */
    double calcula_luz_blue();
				
  };

} ////Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class

#endif
