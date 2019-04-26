/**
 * \file objeto.hpp
 *
 * \brief Este arquivo e um pacote que contem as definicoes que deverao ser apresentados na integra no arquivo objetos.cpp, sendo este responsavel pelas 
 * definicoes de posicao e outras caracteristicas ligadas ao objeto da cena. Foi utilizado o texto [introducao ao ray tracing] como base para a 
 * implementacao do arquivo.
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
 
#ifndef _OBJETO_HPP
#define _OBJETO_HPP

#include "vetor.hpp"	//rayTracing::Vetor
#include "textura.hpp"	//rayTracing::Textura  

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
	 * \class Objeto
	 * 
	 * \brief Define as caracteristicas dos objetos.
	 */
	class Objeto{
		//------------------------------
		//	Atributos privados
		//------------------------------
		private:
			//Criando uma estrutura Esfera
			struct Esfera{
				//posicao da esfera
				double pos_x;	///< coordenada x
				double pos_y;	///< coordenada y
				double pos_z;	///< coordenada z

				//raio da esfera
				double raio;	///< raio
				
				//Material da esfera
				double kd;		///< constante difusa
				double ks;		///< constante especular

				//cor da esfera
				double cor_r;	///< contribuicao red da cor
				double cor_g;	///< contribuicao green da cor
				double cor_b;	///< contribuicao blue da cor
			}esfera;
			
			//Criando uma estrutura Plano
			struct Plano{
				//posicao do plano
				double pos_x;	///< coordenada x
				double pos_y;	///< coordenada y
				double pos_z;	///< coordenada z
				
				//Constantes
				double kd;		///< constante difusa
				double ks;		///< constante especular

				//cor do plano
				double cor_r;	///< contribuicao red da cor
				double cor_g;	///< contribuicao green da cor
				double cor_b;	///< contribuicao blue da cor
			}plano;
			
			///Estruturas a adicionar: Cubo, Cilindro e Toroide alem da Textura dos objetos
		//------------------------------
		//	Metodos publicos
		//------------------------------
		public:
		//Esfera
		/**
		 * \fn void atualizar_esfera(Vetor* pos_esfera, double _raio, double _kd, double _ks, Vetor* cor);
		 *
		 * \brief Atualiza os valores da esfera
		 *
		 * \param pos_esfera - posicao da esfera
		 * \param _raio - raio da esfera
		 * \param _kd - constante difusa
		 * \param _ks - constante especular
		 * \param cor - Vetor com contribuicao r, g e b da cor.
		 */
		void atualizar_esfera(Vetor* pos_esfera, double _raio, double _kd, double _ks, Textura* cor);
		
		/**
		 * \fn void	Objeto::modificar_cor_pixel(Textura* cor);
		 *
		 * \brief Pinta pixels de cores definida pelo range da textura
		 *
		 * \param cor - Vetor com contribuicao r, g e b da cor.
		 */
		void modificar_cor_pixel(Textura* cor);
		
		/**
		 * \fn Vetor* posicao_esfera();
		 *
		 * \brief Retorna a posicao central da esfera.
		 */
		Vetor* posicao_esfera();
		
		/**
		 * \fn double raio();
		 *
		 * \brief Retorna o raio.
		 */
		double raio();
		
		/**
		 * \fn double kd_esfera();
		 *
		 * \brief Retorna a constante difusa do material
		 */
		double kd_esfera();
		
		/**
		 * \fn double posicao_esfera();
		 *
		 * \brief Retorna a constante especular do material
		 */
		double ks_esfera();
		
		/**
		 * \fn Vetor* cor_esfera();
		 *
		 * \brief Retorna a cor da esfera.
		 */
		Vetor* cor_esfera();
		
		//Plano
		/**
		 * \fn void atualizar_plano(Vetor* pos_plano, double _kd, double _ks, Vetor* cor);
		 *
		 * \brief Atualiza os valores do plano
		 *
		 *\param pos_plano - posicao do plano
		 * \param _kd - constante difusa
		 * \param _ks - constante especular
		 * \param cor - Vetor com contribuicao r, g e b da cor.
		 */
		void atualizar_plano(Vetor* pos_plano, double _kd, double _ks, Vetor* cor);
		
		/**
		 * \fn Vetor* posicao_plano();
		 *
		 * \brief Retorna a posicao central do plano.
		 */
		Vetor* posicao_plano();
		
		/**
		 * \fn double kd_plano();
		 *
		 * \brief Retorna a constante difusa do material
		 */
		double kd_plano();
		
		/**
		 * \fn double posicao_plano();
		 *
		 * \brief Retorna a constante especular do material
		 */
		double ks_plano();
		
		/**
		 * \fn Vetor* cor_plano();
		 *
		 * \brief Retorna a cor do plano.
		 */
		Vetor* cor_plano();
	};

} ////Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class

#endif

