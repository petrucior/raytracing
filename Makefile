#
#	Makefile do projeto Ray Tracing
#

#
# A variável CC indica que compilador será utilizado
#
CC=g++

#
# A variável CFLAGS indica que opções de compilação queremos
#
CFLAGS=	-Wall -pedantic -ansi -g -c

#
# A variável LFLAGS indica que opções de compilação queremos
#
LFLAGS=	-Wall -g

#
# A variável INCS indica o caminho dos arquivos de cabeçalho
#
INCS=

#
# A variável LIBS indica o caminho das bibliotecas e as bibliotecas usadas na ligação
#
LIBS= -lm -lGL -lglut -lGLU
#LIBS= -lopengl32 -lglut32 -lglu32

#
# A variável OBJS indica os arquivos objetos
#
OBJS= vetor.o raio.o luz.o objeto.o cena.o textura.o ray_tracing.o main.o

#
# Regra de compilação e ligação do executável
# 
main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main $(LIBS)

#
# Regra de compilação do arquivo objeto vetor.o
# 
vetor.o: vetor.cpp vetor.hpp
	$(CC) $(CFLAGS) vetor.cpp -o vetor.o

#
# Regra de compilação do arquivo objeto raio.o
# 
raio.o: raio.cpp raio.hpp
	$(CC) $(CFLAGS) raio.cpp -o raio.o
#
# Regra de compilação do arquivo objeto luz.o
# 
luz.o: luz.cpp luz.hpp
	$(CC) $(CFLAGS) luz.cpp -o luz.o

#
# Regra de compilação do arquivo objeto raio.o
# 
objeto.o: objeto.cpp objeto.hpp textura.cpp textura.hpp
	$(CC) $(CFLAGS) objeto.cpp -o objeto.o

#
# Regra de compilação do arquivo objeto cena.o
# 
cena.o: cena.cpp cena.hpp
	$(CC) $(CFLAGS) cena.cpp -o cena.o

#
# Regra de compilação do arquivo objeto cena.o
# 
textura.o: textura.cpp textura.hpp
	$(CC) $(CFLAGS) textura.cpp -o textura.o

#
# Regra de compilação do arquivo objeto raytracing.o
# 
ray_tracing.o: ray_tracing.cpp ray_tracing.hpp vetor.cpp vetor.hpp raio.cpp raio.hpp luz.cpp luz.hpp objeto.cpp objeto.hpp cena.cpp cena.hpp textura.cpp textura.hpp
	$(CC) $(CFLAGS) ray_tracing.cpp -o ray_tracing.o $(LIBS)

#
# Regra de compilação do arquivo objeto main.o
# 
main.o: main.cpp vetor.cpp vetor.hpp raio.cpp raio.hpp luz.cpp luz.hpp objeto.cpp objeto.hpp cena.cpp cena.hpp textura.cpp textura.hpp ray_tracing.cpp ray_tracing.hpp
	$(CC) $(CFLAGS) main.cpp -o main.o

#
# Regra que elimina arquivos intermediários
# 
clean:
	rm -f *.o *.~

#
# Regra que elimina arquivos intermediários e executável
# 
realclean:
	rm -f *.o *.~ main

#
# Regra para executar - Abre processo mais nao exclui
# 
exec:
	./main
