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
OUTPUTTEST = doc/exemplos/dense.out
OUTPUTFILE = output.txt

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean:
	rm -f $(APPNAME) $(OUTPUTFILE)

run:
	make
	clear
	./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

test:
	make run
	diff $(OUTPUTFILE) $(OUTPUTTEST)

time:
	make
	time ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

analysis:
	make
	$(VALGRIND) ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)
