/**
 * \file raio.hpp
 *
 * \brief Este arquivo e um pacote que contem as definicoes de calculos que deverao ser apresentados na integra no arquivo raio.cpp, sendo este 
 * responsavel pela definicoes de funcoes de interseccoes com os objetos. Foram utilizados os textos [introducao ao ray tracing] e [RAY TRACING]
 * como base para a implementacao do arquivo.
 * [Texto de introducao ao ray tracing]: www.visgraf.impa.br/Data/RefBib/PS_PDF/silva94/rt.pdf "introducao ao ray tracing"
 * [Texto de apoio para a disciplina - RAY TRACING]: http://disciplinas.ist.utl.pt/leic-cg/textos/livro/Ray%20Tracing.pdf "RAY TRACING"
 *
 * \author 
 * Petrúcio Ricardo Tavares de Medeiros \n
 * Universidade Federal do Rio Grande do Norte \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 *
 * \version 0.4
 * \date Outubro 2013
 */ 
 
#ifndef _RAIO_HPP
#define _RAIO_HPP

#include "vetor.hpp"	//rayTracing::Vetor
#include "objeto.hpp"	//rayTracing::Objeto

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
	 * \class Raio
	 * 
	 * \brief Define os atributos e funcoes que sao atribuidas ao raio.
	 */
	class Raio{
		//------------------------------
		//	Atributos privados
		//------------------------------
		private:
			Vetor* lkf; ///< Lookfrom
			Vetor* lkt; ///< Lookat
			Vetor* c_esf; ///< Centro da esfera
			Vetor* drt; ///< Vetor Diretor
    
			//Coordenadas globais
			double lkfx, lkfy, lkfz;
			double lktx, lkty, lktz;
			double c_esfx, c_esfy, c_esfz;
			double drtx, drty, drtz;
			
			double r;	//raio da esfera
		//------------------------------
		//	Atributos publicos
		//------------------------------
		public:
		/**
		 * \fn Raio();
		 *
		 * \brief Construtor da classe.
		 */
		Raio();
		
		/**
		 * \fn void atualizar_vetores(Vetor* _lkf, Vetor* _lkt, Objeto* esfera)
		 *
		 * \brief Atualiza os valores dos vetores de posicao da camera (lookfrom), posicao do centro da esfera e do lookat
		 *
		 * \param _lkf - vetor de posicao da camera
		 * \param _lkt - vetor de posicao do lookat
		 * \param esfera - objeto esfera
		 */
		void atualizar_vetores( Vetor* _lkf, Vetor* _lkt, Objeto* esfera);
	
		/**
		 * \fn void vetor_diretor()
		 *
		 * \brief Calcula a diferenca entre o vetor lookat e o vetor lookfrom.
		 */
		void vetor_diretor();
	
		/**
		 * \fn double delta(double a, double b, double c)
		 *
		 * \brief calcula o delta para ser utilizado no metodo de interseccao com a esfera
		 *
		 * \param a - o valor do a da equacao do segundo grau
		 * \param b - o valor do b da equacao do segundo grau
		 * \param c - o valor do c da equacao do segundo grau
		 *
		 * \return o valor de delta
		 */
		double delta(double a, double b, double c);
	
		/**
		 * \fn double calcula_t() 
		 *
		 * \brief Atraves de uma manipulacao algebrica apresentada a seguir foi encontrada uma equacao que facilita a descoberta dos valores de t' e t''.
		 * Pode ser encontrado o vetor diretor atraves do metodo acima que me retornara uma equacao de valores da forma: \f$ (D_x) = (lkt_x - lkf_x) \f$,
		 * \f$(D_y) = (lkt_y - lkf_y) \f$ e \f$ (D_z) = (lkt_z - lkf_z) \f$. Encontramos a equacao parametrizada: \f$ x = (lkf_x) + t(D_x) \f$, \f$ y = (lkf_y) + t(D_y) \f$ e
		 * \f$ z = (lkf_z) + t(D_z) \f$. Aplicando na equacao da esfera: \f$ (x - x_0)^2 + (y - y_0)^2 + (z - z_0)^2 = r^2 \f$ o que resultou em:
		 * \f$ x^2 - 2x(x_0) + (x_0)^2 + y^2 - 2y(y_0) + (y_0)^2 + z^2 - 2z(z_0) + (z_0)^2 - r^2 = 0 \f$
		 * \f$ ((lkf_x) + t(D_x))^2 - 2((lkf_x) + t(D_x))(x_0) + (x_0)^2 + ((lkf_y) + t(D_y))^2 - 2((lkf_y) + t(D_y))(y_0) + (y_0)^2 + ((lkf_z) + t(D_z))^2 - 2((lkf_z) + t(D_z))(z_0) + (z_0)^2 - r^2 = 0 \f$
		 * \f$ t^2*((D_x)^2 + (D_y)^2 + (D_z)^2) + t*(2*(lkf_x)*(D_x) + 2*(lkf_y)*(D_y) + 2*(lkf_z)*(D_z) - 2*(c_esf_x)(D_x) - 2*(c_esf_y)(D_y) - 2*(c_esf_z)(D_z)) +(lkf_x)^2 +(lkf_y)^2 +(lkf_z)^2 +(c_esf_x)^2 +(c_esf_y)^2 + +(c_esf_z)^2 - r^2 - 2*(c_esf_x)*(lkf_x) - 2*(c_esf_y)*(lkf_y) - 2*(c_esf_z)*(lkf_z) = 0
		 * desta forma para encontrar t' e t'' podemos utilizar a formula de baskara.
		 * A partir da equacao acima encontramos a, b e c para ser aplicado a formula de baskara, mas sabemos da fórmula de baskara que necessitamos 
		 * calcular primeiro o \f$ delta = b^2 - 4ac \f$ e tomar conclusoes se intercepta o objeto ou nao e se sim calcular a posicao de interceccao.
		 * Nas equacoes D e o vetor diretor, lkf(lookfrom), lkt(lookat) c_esf(centro da esfera).
		 *
		 * \return o menor valor entre t' e t'' ou um valor 0 que implica dizer que nao foi interceptado nenhuma esfera. e necessario saber que se o menor
		 * valor e negativo e porque a câmera esta dentro do objeto.
		 */
		double calcula_t();
	 
		/**
		 * \fn vetor interseccao_esfera(double t)
		 *
		 * \brief Atraves do valor de t pode ser encontrado a posicao de interseccao do raio com a esfera aplicando a equacao parametrizada. Sabemos que
		 * o vetor diretor esta na forma \f$(D_x) = (lkt_x - lkf_x) \f$, \f$(D_y) = (lkt_y - lkf_y) \f$ e \f$ (D_z) = (lkt_z - lkf_z) \f$ aplicando a equacao parametrizada a qual
		 * conhecemos \f$ x = (lkf_x) + t(D_x) \f$, \f$ y = (lkf_y) + t(D_y) \f$ e \f$ z = (lkf_z) + t(D_z) \f$.
		 *
		 * \param t - valor do t da equacao parametrizada
		 *
		 * \return a posicao de interseccao entre o raio e a esfera
		 */
		Vetor* interseccao_esfera(double t);
	
	};

} ////Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class

#endif

