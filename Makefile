#
#	Makefile do projeto Ray Tracing
#

#
# A vari�vel CC indica que compilador ser� utilizado
#
CC=g++

#
# A vari�vel CFLAGS indica que op��es de compila��o queremos
#
CFLAGS=	-Wall -pedantic -ansi -g -c

#
# A vari�vel LFLAGS indica que op��es de compila��o queremos
#
LFLAGS=	-Wall -g

#
# A vari�vel INCS indica o caminho dos arquivos de cabe�alho
#
INCS=

#
# A vari�vel LIBS indica o caminho das bibliotecas e as bibliotecas usadas na liga��o
#
#LIBS= -lm -lGL -lglut -lGLU
LIBS= -lopengl32 -lglut32 -lglu32
#
# A vari�vel OBJS indica os arquivos objetos
#
OBJS= vetor.o raio.o luz.o objeto.o cena.o textura.o ray_tracing.o main.o

#
# Regra de compila��o e liga��o do execut�vel
# 
main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main $(LIBS)

#
# Regra de compila��o do arquivo objeto vetor.o
# 
vetor.o: vetor.cpp vetor.hpp
	$(CC) $(CFLAGS) vetor.cpp -o vetor.o

#
# Regra de compila��o do arquivo objeto raio.o
# 
raio.o: raio.cpp raio.hpp
	$(CC) $(CFLAGS) raio.cpp -o raio.o
#
# Regra de compila��o do arquivo objeto luz.o
# 
luz.o: luz.cpp luz.hpp
	$(CC) $(CFLAGS) luz.cpp -o luz.o

#
# Regra de compila��o do arquivo objeto raio.o
# 
objeto.o: objeto.cpp objeto.hpp textura.cpp textura.hpp
	$(CC) $(CFLAGS) objeto.cpp -o objeto.o

#
# Regra de compila��o do arquivo objeto cena.o
# 
cena.o: cena.cpp cena.hpp
	$(CC) $(CFLAGS) cena.cpp -o cena.o
	
#
# Regra de compila��o do arquivo objeto cena.o
# 
textura.o: textura.cpp textura.hpp
	$(CC) $(CFLAGS) textura.cpp -o textura.o
	
#
# Regra de compila��o do arquivo objeto raytracing.o
# 
ray_tracing.o: ray_tracing.cpp ray_tracing.hpp vetor.cpp vetor.hpp raio.cpp raio.hpp luz.cpp luz.hpp objeto.cpp objeto.hpp cena.cpp cena.hpp textura.cpp textura.hpp
	$(CC) $(CFLAGS) ray_tracing.cpp -o ray_tracing.o $(LIBS)

#
# Regra de compila��o do arquivo objeto main.o
# 
main.o: main.cpp vetor.cpp vetor.hpp raio.cpp raio.hpp luz.cpp luz.hpp objeto.cpp objeto.hpp cena.cpp cena.hpp textura.cpp textura.hpp ray_tracing.cpp ray_tracing.hpp
	$(CC) $(CFLAGS) main.cpp -o main.o
	
#
# Regra que elimina arquivos intermedi�rios
# 
clean:
	rm -f *.o *.~

#
# Regra que elimina arquivos intermedi�rios e execut�vel
# 
realclean:
	rm -f *.o *.~ main

#
# Regra para executar - Abre processo mais nao exclui
# 
exec:
	./main
