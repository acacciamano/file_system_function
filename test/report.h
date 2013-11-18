
#include <iostream>
#include <sstream>


//funzione template per la generazione dei report



#ifndef REPORT_H
#define REPORT_H

namespace more_test
{

  void print_report_ctr_object(std::ostream& os,const std::string& name_function,const std::string& str,double time,int err);

  void print_report_exist_dir(std::ostream& os,const std::string& name_function,const std::string& str,bool ret);

  void print_report_create_dir(std::ostream& os,const std::string& name_function,const std::string& str,bool ret);
}



#endif





#endif
