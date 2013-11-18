#include <iostream>
#include <sstream>


//funzione template per la generazione dei report



#ifndef REPORT_H
#define REPORT_H


void print_report_ctr_object(std::ostream& os,const std::string& name_function,const std::string& str,double time,int err)
{  
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION " << name_function << std::endl;
  std::cout << "Used path: " << str << std::endl;
  if(err)
    std::cout << "Construct in: " << time << " ms" << std::endl;
  else
    std::cout << "Failed in: " << time << " ms" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;
}

void print_report_exist_dir(std::ostream& os,const std::string& name_function,const std::string& str,bool ret)
{
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION " << name_function << std::endl;
  std::cout << "Used path: " << str << std::endl;
  if(ret)
    std::cout << "Directory exist (elapsed: " << time << " ms)" << std::endl;
  else
    std::cout << "Directory not exist (elapsed: " << time << " ms)" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;
}

void print_report_create_dir(std::ostream& os,const std::string& name_function,const std::string& str,bool ret)
{
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION " << name_function << std::endl;
  std::cout << "Used path: " << str << std::endl;
  if(ret)
    std::cout << "Directory exist (elapsed: " << time << " ms)" << std::endl;
  else
    std::cout << "Directory not exist (elapsed: " << time << " ms)" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;
}




#endif
