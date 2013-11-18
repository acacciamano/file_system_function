# MACRO
# $@ indica il target
# $? indica i dependent name con estensioni
# $< il nome del file che causa l'azione VALE SOLO in suffixes rules
# $* 
# $$
#
#
#seleziona il compilatore
CXX = g++
#seleziona il linker
LD = g++ -o
#flags per la compilazione
CXXFLAGS = -Wall -std=c++0x -pedantic -ansi
#flags del linker
LD_FLAGS=-shared
#flags per la compilazione ottimizzata
OPTIMIZE_FLAGS=
#flags per il debug                             
DEBUG_FLAGS= -g
#directory con i files sorgente
SOURCES_PATH = ./source/
#macro con la lista dei files sorgente
CPP_FILES = $(wildcard ./sources/*.cpp)
#directory in cui posizionare l'output
OUTPUT_PATH = ./bin

# Header files
INCS_PATH = -I./include
# Library
LIBS= -L/library
#macro di inclusione header
INCLUDES= $(INCS_PATH)

#nome eseguibile
OUTPUT_EXE = main
#nome libreria statica
OUTPUT_LIB_STATIC=libPathIndipendent.a
#nome libreria dinamica
OUTPUT_LIB_DYNAMIC=libPathIndipendent.so

#genera lista dei file object a partire dai cpp
#OBJS = ${CPP_FILES:.cpp=.o}
OBJS := $(addprefix objects/,$(notdir $(CPP_FILES:.cpp=.o)))

#SRCS = path.cpp main.cpp
#CPP_FILES := $(wildcard ./sources/*.cpp)


#macro predefinita: non echo the command to stdout
#.SILENT :

##################### SECTION COMPILE con suffixes rules   #######################################
#azzera regole esistenti
.SUFFIXES:                                   
# lista su quali file applicare la regola di suffisso
.SUFFIXES: .o .cpp
#definisce una regola (il modo) per costruire object files da cpp
objects/%.o: sources/%.cpp
#.cpp.o:
	@echo "============= COMPILE FILE ================"
	@echo "Compiling . . . $<"
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c -o $@ $< 


####################### SECTION LINKING ###########################################################
#regola per generare eseguile dai file oggetto
./bin/$(OUTPUT_EXE): $(OBJS)
	@echo "============= GENERATE OUTPUT ================"	
	$(LD) $@ $^

all : $(OUTPUT_EXE) clean

######################## SECTION STATIC AND DYNAMIC LIBRARY TARGETS ############################################################

static_lib: ./objects/path.o
	@echo "============= GENERATE STATIC LIB ================"
	ar rcs $(OUTPUT_LIB_STATIC) $^
	/bin/mv $(OUTPUT_LIB_STATIC) ./bin

dynamic_lib: ./objects/path.o
	@echo "============= GENERATE DYNAMIC LIB ================"
	@echo $^
	$(LD) $(OUTPUT_LIB_DYNAMIC) $(LD_FLAGS) $^
	/bin/mv $(OUTPUT_LIB_DYNAMIC) ./bin


#dipendenze per generazione librerie
./objects/path.o:./sources/path.cpp
	@echo "Compiling source file"
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@


dynamic:
	/usr/bin/make $(MFLAGS) CXXFLAGS='-Wall -std=c++0x -pedantic -ansi -fPIC' LD_FLAGS=-shared dynamic_lib


static:
	$(MAKE) $(MFLAGS) CXXFLAGS='-Wall -std=c++0x -pedantic -ansi' static_lib clean

######################## SECTION OTHER TARGETS ############################################################

clean:
	/bin/rm ./objects/*.o



#in caso di target non previsto
.DEFAULT:
	@$(MAKE) help

help:
	@echo "================================================"
	@echo "do Use 'make' to generate test program for library"
	@echo "do Use 'make static' to generate static library"
	@echo "do Use 'make dynamic' to generate dynamic library"
	@echo "================================================"













