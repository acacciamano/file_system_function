Struttura del fyle system:

(*) include: cartella che deve contenere gli header files (.h)
(*) library: cartella che deve contenere eventuali librerie esterne utilizzate dal programma
(*) sources: cartella contenente il file sorgente (.cpp)
(*) bin: cartella contenente il risultato della compilazione (eseguibile o libreria)
(*) objects: contenente i file oggetto

Makefile costruisce i seguenti targets:
(*) all: costruisce un eseguibile di test
(*) dynamic: costruisce una libreria shared
(*) static: costruisce una libreria statica
(*) clean: elimina file oggetto
(*) help: print come utilizzare make
(*) 

