/**
 * \file textura.hpp
 *
 * \brief Este arquivo e um pacote que contem as definicoes que deverao ser apresentados na integra no arquivo textura.cpp, sendo este responsavel pelas 
 * definicoes de criacao da textura e outras caracteristicas ligadas ao objeto da cena. Foi utilizado o texto [introducao ao ray tracing] como base para a 
 * implementacao do arquivo.
 * [Texto de introducao ao ray tracing]: www.visgraf.impa.br/Data/RefBib/PS_PDF/silva94/rt.pdf "introducao ao ray tracing"
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal do Rio Grande do Norte \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 *
 * \version 0.0
 * \date Novembro 2013
 */
 
#ifndef _TEXTURA_HPP
#define _TEXTURA_HPP

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
	 * \class Textura
	 * 
	 * \brief Define metodos para a criacao da textura.
	 */
	class Textura{
		//------------------------------
		//	Atributos privados
		//------------------------------
		private:
			//Inicio do range
			Vetor* inicio_range;
			//Fim do range
			Vetor* final_range;
		
		//------------------------------
		//	Metodos privados
		//------------------------------	
		/**
		 * \fn int rand_red();
		 *
		 * \brief Escolhe a parte red randomicamente.
		 *
		 * \return Valor randomico para a contribuicao vermelha.
		 */
		int rand_red();

		/**
		 * \fn int rand_green();
		 *
		 * \brief Escolhe a parte green randomicamente.
		 *
		 * \return Valor randomico para a contribuicao verde.
		 */
		int rand_green();
		
		/**
		 * \fn int rand_blue();
		 *
		 * \brief Escolhe a parte blue randomicamente.
		 *
		 * \return Valor randomico para a contribuicao azul.
		 */
		int rand_blue();

		//------------------------------
		//	Metodos publicos
		//------------------------------
		public:
		/**
		 * \fn Textura(Vetor* _inicio_range, Vetor* _final_range);
		 *
		 * \brief Construtor da classe textura.
		 *
		 * \param _inicio_range - inicio dos limites
		 * \param _final_range - final dos limites
		 */
		Textura(Vetor* _inicio_range, Vetor* _final_range);

		
		/**
		 * \fn Vetor* map_textura_solida();
		 *
		 * \brief Metodo que mapeia a textura solida.
		 *
		 * \return Vetor com contribuicao r, g e b.
		 */
		Vetor* map_textura_solida();
	};

} //Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class

#endif
