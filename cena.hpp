/**
 * \file cena.hpp
 *
 * \brief Este arquivo e um pacote que contem as definicoes que deverao ser apresentados na íntegra no arquivo cena.cpp, sendo este responsavel pelas 
 * definicoes da cena. Foi utilizado o texto [introducao ao ray tracing] como base para a implementacao do arquivo. Link [http://www.cplusplus.com/reference/list/list/size/]
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
 
#ifndef _CENA_HPP
#define _CENA_HPP

#include "objeto.hpp"	//rayTracing::Objeto
#include <iostream>	//std
#include <list>		//list
//#include "ImageClass.h"

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
	 * \class Cena
	 * 
	 * \brief Define as características dos objetos.
	 */
	class Cena{
		//------------------------------
		//	Atributos privados
		//------------------------------
		private:
			std::list<Objeto*> obj;	///< Pilha de objetos
			
			//Definindo cor do background
			double background_r; ///< cor r do background
			double background_g; ///< cor g do background
			double background_b; ///< cor b do background
			
			//Constante ambiente
			double ka;	///< constante do ambiente
			
			//Tamanho da imagem
			int n;	///< Numero de linhas da imagem
			int m;	///< Numero de colunas da imagem
			
			//Criando uma imagem para background
			//ImageClass* background = new ImageClass(n, m);
			
		//------------------------------
		//	Metodos publicos
		//------------------------------
		public:
		/**
		 * \fn Cena();
		 *
		 * \brief Construtor da classe.
		 */
		Cena();
		
		/**
		 * \fn void atualizar_cor_background(double r, double g, double b);
		 *
		 * \brief Atualiza as cores de background.
		 *
		 * \param r - contribuicao red para o background
		 * \param g - contribuicao green para o background
		 * \param b - contribuicao blue para o background
		 */
		void atualizar_cor_background(double r, double g, double b);
		
		/**
		 * \fn double cor_background_r();
		 *
		 * \brief Retorna a contribuicao red para a cor de background.
		 */
		double cor_background_r();
		
		/**
		 * \fn double cor_background_g();
		 *
		 * \brief Retorna a contribuicao green para a cor de background.
		 */
		double cor_background_g();
		
		/**
		 * \fn double cor_background_b();
		 *
		 * \brief Retorna a contribuicao blue para a cor de background.
		 */
		double cor_background_b();
		
		/**
		 * \fn void incluir_objetos_pilha(Objeto* o);
		 *
		 * \brief Inclue um objeto na pilha.
		 *
		 * \param o - ponteiro para o objeto que devera ser colocado na pilha
		 */
		void incluir_objetos_pilha(Objeto* o);
		
		/**
		 * \fn Objeto* excluir_objetos_pilha();
		 *
		 * \brief Exclue um objeto na pilha.
		 */
		Objeto* excluir_objetos_pilha();
		
		/**
		 * \fn int size_objetos_pilha();
		 *
		 * \brief calcula quantos objetos tem na pilha e que constitue minha cena.
		 *
		 * \return A quantidade objetos na pilha
		 */
		int size_objetos_pilha();
		
		
		/**
		 * \fn void atualizar_ka(double _ka);
		 *
		 * \brief Atualizando o valor de _ka.
		 *
		 * \param _ka - constante do ambiente
		 */
		void atualizar_ka(double _ka);
		
		/**
		 * \fn double ka_ambiente();
		 *
		 * \brief Retornando o valor da constante do ambiente
		 */
		double ka_ambiente();
		
		/**
		 * \fn void dimensao_imagem(int lado, int altura);
		 *
		 * \brief Atualizando as dimensoes da imagem
		 *
		 * \param lado - dimensao do lado da imagem
		 * \param altura - dimensao da altura da imagem
		 */
		void dimensao_imagem(int lado, int altura);
		
		/**
		 * \fn int lado();
		 *
		 * \brief Retornando o valor do lado da imagem.
		 */
		int lado();
		
		/**
		 * \fn int altura();
		 *
		 * \brief Retornando o valor da altura da imagem.
		 */
		int altura();
		
	};

} ////Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class

#endif
	