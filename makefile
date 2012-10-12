# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc

#Objetos
OBJS =  src/tp1.c src/funcoes_grafo.c src/funcoes.c 

# Nome do aplicativo
APPNAME = tp1

#valgrind
VALGRIND = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

#arquivos
INPUTFILE = doc/exemplos/dense.in
OUTPUTFILE = output.txt

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean:
	rm -f $(APPNAME) $(OUTPUTFILE)

run:
	make
	./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

time:
	gcc $(GERAMATRIZES) -o geraMatrizes
	./geraMatrizes $(INPUTFILE) 10
	make
	time ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

analysis:
	make
	$(VALGRIND) ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)