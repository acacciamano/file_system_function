#include "path.h"

namespace myPath
{

      path_directory::path_directory() :
        _path(path_directory::executable_path())
      {
      }

      path_directory::path_directory(const std::string& str):_path(str)
      {
        init();
      }

      std::ostream& path_directory::print_path_directory(std::ostream& os) const
      {
        return os << _path;
      }

      std::ostream& operator<<(std::ostream& os,const myPath::path_directory& rpd)      
      {        
        return rpd.print_path_directory(os);
      }

      //ritorna il path assoluto al programma in esecuzione PLATFORM INDIPENDENT
      std::string path_directory::running_path()
      {
        char current_path[100];
        if( ! GET_CURRENT_DIR(current_path,sizeof(current_path)) )
        {
          throw invalid_path("Error: unable to find running directory");            
        }
#if defined _WIN32 ||defined WIN32 || defined __NT__ || defined __WIN32__ || defined _WIN64
        int TO_DO_SECTION = 0_DO_SECTION = 0;;
#endif       
        return std::string(current_path);
      }

      //ritorna il path assoluto a dove si trova il file eseguibile PLATFORM INDEPENDENT
      std::string path_directory::executable_path()
      {
        char executable_path[100];
#if defined linux || defined __linux__ || defined __linux
        int ret = readlink("/proc/self/exe",executable_path,100);
        if( ret == -1)
          throw invalid_path("Error: unable to find executable directory");
        executable_path[ret] = '\0';
#endif        
#if defined _WIN32 ||defined WIN32 || defined __NT__ || defined __WIN32__ || defined _WIN64
        HMODULE h_module = GetModuleHandle(NULL);
        if ( !h_module)
          throw invalid_path("Error: unable to find executable directory");
        GetModuleFileName(h_module,executable_path,100);
#endif       
        return std::string(executable_path);
      }

      //verifca se una directory e' esistente
      bool path_directory::directory_exist(const std::string& dir_name)
      {
#if defined linux || defined __linux__ || defined __linux
        DIR* dir = opendir(dir_name.c_str());
        if(dir)
        {
          closedir(dir);
          return true;
        }
        else if(ENOENT == errno)
          throw invalid_path("Error: directory does not exist");
#endif        
#if defined _WIN32 ||defined WIN32 || defined __NT__ || defined __WIN32__ || defined _WIN64
        DWORD ftyp = GetFileAttributesA(dir_name.c_str());
        if( ftyp == INVALID_FILE_ATTRIBUTES )
          throw invalid_path("Error: something is wrong in path");
        if( ftyp & FILE_ATTRIBUTE_DIRECTORY )
          return true;
#endif        
        return false;          
      }

      //crea una directory
      void path_directory::create_directory(const std::string& dir_name)
      {
#if defined linux || defined __linux__ || defined __linux
        int stat = mkdir(dir_name.c_str(),0777);
        if(stat)
          throw invalid_path("Error: unable to create directory");                   
#endif        
#if defined _WIN32 ||defined WIN32 || defined __NT__ || defined __WIN32__ || defined _WIN64
        if( ! CreateDirectory(dir_name.c_str() )
          if( ERROR_ALREADY_EXIST != GetLastError() )
            throw invalid_path("Error: unable to create directory");                   
#endif        
      }





      void path_directory::init()
      {
        parse_separator_symbol(_path);
        parse_adjacent_symbol(_path);
        parse_terminal_symbol(_path);
        if(!test_exist_path(_path))
          throw invalid_path();
      }

      bool path_directory::comp_sep_symb::operator()(char c1,char c2)
      {
        return ( (c1 == SYSTEM_SEP) && (c2 == SYSTEM_SEP) );
      }

      
      //elimina i doppi slash consecutivi
      void path_directory::parse_adjacent_symbol(std::string& str)
      {
        std::string::iterator it = str.begin();
        while( it != str.end() )
        {
          it = std::adjacent_find(it,str.end(),comp_sep_symb());
          if( it != str.end() )
          {
            str.erase(it);
            it = str.begin(); //erase could be invalid iterator !!
          }
        }
      }

      //escaping degli spazi bianchi nel percorso
      void path_directory::parse_empty_space(std::string& str)
      {
        std::vector<size_t> pos_empty_space;
        std::string::size_type pos = str.find(' ',0);
        while(pos != std::string::npos)
        {
          pos_empty_space.push_back(pos);
          pos = str.find(' ',++pos);          
        }
        for(std::vector<size_t>::size_type i = 0 ; i < pos_empty_space.size() ; ++i)
        {
          str.insert(pos_empty_space[i] + i, system_escape );
        }
      }

      //verifica (e nel caso corregge) che i separatori di dirctory siano corretti per la piattaforma
      void path_directory::parse_separator_symbol(std::string& str)
      {
        std::string::size_type pos = 0;
        while( (pos = str.find('\\',pos)) != std::string::npos )
        {
          str[pos]  = SYSTEM_SEP;
          pos++;
        }
      }

      //inserisce un separatore finale se non e' gia' presente
      void path_directory::parse_terminal_symbol(std::string& str)
      {
        std::string::size_type pos = str.find_last_of(SYSTEM_SEP);
        if(pos != (str.size()-1) )
          str.push_back(SYSTEM_SEP);
      }

      //testa se il path esiste altrimenti lancia eccezione
      bool path_directory::test_exist_path(const std::string& str)
      {
        bool ret = false;
        #if defined linux || defined __linux__ || defined __linux
          struct stat status;
          if(!stat(str.c_str(),&status))
            ret = S_ISDIR(status.st_mode);
        #endif
        #ifdef _WIN32
            
        #endif 
         return ret;
      }

        path_directory::invalid_path::invalid_path() : _message("Path is not valid") 
        {}
        path_directory::invalid_path::invalid_path(const std::string& str) : _message(str) 
        {}
        path_directory::invalid_path::~invalid_path() throw()
        {}
        const char* path_directory::invalid_path::what() const throw()
        {
          return _message.c_str();
        }


}


