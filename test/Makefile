CXX=g++ -o
CXXFLAGS=-Wall -pedantic -ansi -std=c++0x

LD=g++ -o
LDFLAGS=-static

INCLUDES=-I./../include
LIBS=-L./../bin -lPathIndipendent

OUTPUT_EXE=test_path_indipendent

#macro con la lista dei files sorgente
CPP_FILES = main.cpp
#genera lista dei file object a partire dai cpp
OBJS = ${CPP_FILES:.cpp=.o}

##################### SECTION COMPILE con suffixes rules   #######################################
#azzera regole esistenti
.SUFFIXES:                                   
# lista su quali file applicare la regola di suffisso
.SUFFIXES: .o .cpp
#definisce una regola (il modo) per costruire object files da cpp
.cpp.o:
	@echo "============= COMPILE FILE ================"
	@echo "Compiling . . . $<"
	$(CXX) $@ $(INCLUDES) $(CXXFLAGS) -c $<


####################### SECTION LINKING ###########################################################
#regola per generare eseguile dai file oggetto
$(OUTPUT_EXE): $(OBJS)
	@echo "============= GENERATE OUTPUT ================"
	$(LD) $@ $^ $(LIBS) $(LDFLAGS)

all: $(OUTPUT_EXE) clean

######################## SECTION OTHER TARGETS ############################################################

clean:
	/bin/rm -rf ./*.o

#in caso di target non previsto
.DEFAULT:
	@$(MAKE) help

help:
	@echo "================================================"
	@echo "do Use 'make' or make ALL"
	@echo "================================================"
