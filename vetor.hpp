/**
 * \file vetor.hpp
 *
 * \brief Este arquivo e um pacote que contem as definicoes de calculos que deverao ser apresentados na integra no arquivo vetor.cpp, que e 
 * responsavel pela definicoes de funcoes da estrutura dos vetores.
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal do Rio Grande do Norte \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 *
 * \version 0.0
 * \date Outubro 2013
 */
 
#ifndef _VETOR_HPP
#define _VETOR_HPP

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
	 * \class Vetor
     *
     * \brief Esta classe contem a definicao de vetores que serao utilizados como estrutura para o projeto rayTracing.
     *
     */
	class Vetor{
		//------------------------------
		//	Atributos privados
		//------------------------------
		private:
			double x;	///< Coordenada x
			double y;	///< Coordenada y
			double z;	///< Coordenada z
			
			double pi;
		//------------------------------
		//	Metodos publicos
		//------------------------------
		public:
			/**
			 * \fn Vetor();
			 *
			 * \brief Construtor da classe vetor.
			 */
			Vetor();
			
			/**
			 * \fn void valores_vetor(double _x, double _y, double _z);
			 *
			 * \brief Atualiza os valores do vetor.
			 *
			 * \param _x - valor correspondente a coordenada x
			 * \param _y - valor correspondente a coordenada y
			 * \param _z - valor correspondente a coordenada z			 
			 */
			void valores_vetor(double _x, double _y, double _z);
			
			/**
			 * \fn double vx();
	         *
			 * \brief Encontra o valor da coordenada x.
			 *
			 * \return O valor da coordenada x do vetor.
			 */
			double vx();
			
			/**
			 * \fn double vy();
	         *
			 * \brief Encontra o valor da coordenada y.
			 *
			 * \return O valor da coordenada y do vetor.
			 */
			double vy();
			
			/**
			 * \fn double vz();
	         *
			 * \brief Encontra o valor da coordenada z.
			 *
			 * \return O valor da coordenada z do vetor.
			 */
			double vz();
			
			/**
			 * \fn void vetor_diretor(Vetor& v, Vetor& r);
	         *
			 * \brief Calcula o vetor diretor.
			 */
			void vetor_diretor(Vetor* v, Vetor* r);
			
			/**
			 * \fn double norma();
			 *
			 * \brief Calcula a norma ou modulo do vetor.
			 *
			 * \return A norma do vetor.
			 */
			double norma();
			
			/**
			 * \fn double produto_escalar(const Vetor& v);
			 *
			 * \brief Calcula o produto escalar entre os dois vetores.
			 *
			 * \param v - vetor que esta realizando o produto escalar.
			 * 
			 * \return O valor do produto escalar.
			 */
			double produto_escalar(Vetor* v);
			
			/**
			 * \fn double angulo(const Vetor& v);
			 *
			 * \brief Calcula o angulo entre vetores.
			 *
			 * \param v - vetor que se deseja encontrar o angulo. 
			 *
	         * \return O angulo entre os dois vetores em GRAUS.
			 */
			double angulo(Vetor* v);
			
	};
	
 } ////Fim do namespace rayTracing
 
/** @} */ //Fim do grupo class

#endif


