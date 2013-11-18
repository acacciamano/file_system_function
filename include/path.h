/*************************************** Header Section *******************************************
-- Name                   : Andrea Cacciamano
-- Date                   : 5-Oct-2013
-- Filename               : path_indipendent.h
-- Language               : C++11
-- Description            : Class to manage path despite the platform (Windows or Linux)
-- Version                : 1.0
-- Tested on              :

Revision History
-- Date
-- Name
-- Description
-- Version

Revision History
-- Date
-- Name
-- Description
-- Version

Revision History
-- Date
-- Name
-- Description
-- Version

*************************************** End Header Section ***************************************/



#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
#include <vector>
#include <cerrno>
#include <fstream>


#if defined linux || defined __linux__ || defined __linux
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <unistd.h>
  #include <dirent.h>
#endif

#if defined _WIN32 ||defined WIN32 || defined __NT__ || defined __WIN32__ || defined _WIN64
  #include <direct.h> //to _getcwd
  #include <windows.h> // to getmodulehandle & getmodulefile
#endif

//scelgo il separatore di directory
#if defined linux || defined __linux__ || defined __linux
  #define SYSTEM_SEP '/'
#elif defined _WIN32 ||defined WIN32 || defined __NT__ || defined __WIN32__ || defined _WIN64
  #define SYSTEM_SEP '\\'
#endif

//scelgo il simbolo di escape
#if defined linux || defined __linux__ || defined __linux
  #define system_escape "\\"
#elif defined _WIN32 ||defined WIN32 || defined __NT__ || defined __WIN32__ || defined _WIN64
  #define system_escape ""
#endif

//scelgo la funzione per il recupero della directory in cui run application
#if defined linux || defined __linux__ || defined __linux
  #define GET_CURRENT_DIR getcwd
#elif defined _WIN32 ||defined WIN32 || defined __NT__ || defined __WIN32__ || defined _WIN64
  #define GET_CURRENT_DIR _getcwd
#endif

  
  
namespace myPath
{

class path_directory
{
  public:
    //costruttore di default ==> costruisce un path dove gira l'applicazione
      path_directory();
      explicit path_directory(const std::string& str);
      std::ostream& print_path_directory(std::ostream&) const;


      static std::string running_path();
      static std::string executable_path();
      static bool directory_exist(const std::string& dir_name);
      static void create_directory(const std::string& dir_name);


     class invalid_path : public std::exception
     {
      public:
        invalid_path();
        invalid_path(const std::string& str);
        virtual ~invalid_path() throw();
        virtual const char* what() const throw();

      private:
        std::string _message;
    };
  private:
      void init();
      struct comp_sep_symb
      {
        bool operator()(char c1,char c2);
      };
      
      //elimina i doppi slash consecutivi
      void parse_adjacent_symbol(std::string& str);

      //escaping degli spazi bianchi nel percorso
      void parse_empty_space(std::string& str);

      //verifica (e nel caso corregge) che i separatori di dirctory siano corretti per la piattaforma
      void parse_separator_symbol(std::string& str);

      //inserisce un separatore finale se non e' gia' presente
      void parse_terminal_symbol(std::string& str);

      //testa se il path esiste altrimenti lancia eccezione
      bool test_exist_path(const std::string& str);
/*
     class invalid_path : public std::exception
     {
      public:
        invalid_path();
        invalid_path(const std::string& str);
        virtual ~invalid_path() throw();
        virtual const char* what() const throw();

      private:
        std::string _message;
    };
    */
    std::string _path;
};

  std::ostream& operator<<(std::ostream& os,const path_directory& rpd);
}


#endif
