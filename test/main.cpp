#include <iostream>
#include <cstdlib>
#include <chrono>
#include <string>

#include "path.h"

int main(int argc,char** argv)
{
//test path_directory(); ==> FUNCTION 1
  auto start = std::chrono::steady_clock::now();
  myPath::path_directory temp;
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout << std::endl << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION path_directory();" << std::endl;
  std::cout << "Default path object value: " << temp << std::endl;
  std::cout << "Construct default path object in: " << std::chrono::duration<double,std::milli>(diff).count() << " ms" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;
  
//test function static std::string executable_path(); ==> FUNCTION 2
  start = std::chrono::steady_clock::now();
  std::string path =  myPath::path_directory::executable_path();
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION static std::string executable_path();" << std::endl;
  std::cout << "Executable path obtained in: " << std::chrono::duration<double,std::milli>(diff).count() << " ms" << std::endl;
  std::cout << "Executable path is: " << path << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;

//test path_directory(const std::string& ); ==> FUNCTION 3
  start = std::chrono::steady_clock::now();
  myPath::path_directory temp1("/home/gta");
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION path_directoryconst std::string&();" << std::endl;
  std::cout << "Default path object value: " << temp1 << std::endl;
  std::cout << "Construct path object in: " << std::chrono::duration<double,std::milli>(diff).count() << " ms" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;

//test path_directory(const std::string& ); ==> FUNCTION 3
  start = std::chrono::steady_clock::now();
  myPath::path_directory temp2("/home\\/gta");
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION path_directoryconst std::string&();" << std::endl;
  std::cout << "Default path object value: " << temp2 << std::endl;
  std::cout << "Construct path object in: " << std::chrono::duration<double,std::milli>(diff).count() << " ms" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;


//test path_directory(const std::string& ); ==> FUNCTION 3
  start = std::chrono::steady_clock::now();
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION path_directoryconst std::string&();" << std::endl;
  try
  {
    myPath::path_directory temp3("/home/gta/provolo");
    std::cout << "Default path object value: " << temp3 << std::endl;
    std::cout << "Construct path object in: ";
  }
  catch(const myPath::path_directory::invalid_path& ex)
  {
    std::cout << ex.what() << "! Failed path object in: ";
  }
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout << std::chrono::duration<double,std::milli>(diff).count() << " ms" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;


//test function static std::string running_path(); ==> FUNCTION 4
  start = std::chrono::steady_clock::now();
  std::string path1 =  myPath::path_directory::running_path();
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION static std::string running_path();" << std::endl;
  std::cout << "Running path obtained in: " << std::chrono::duration<double,std::milli>(diff).count() << " ms" << std::endl;
  std::cout << "Running path is: " << path1 << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;


//test function static std::string running_path(); ==> FUNCTION 5
  std::string path2 =  "/home/gta";
  start = std::chrono::steady_clock::now();
  bool ret = myPath::path_directory::directory_exist(path2);
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION bool directory_exist(const std::string& dir_name);" << std::endl;
  if(ret)
    std::cout << "Directory " << path2 << " exist (elapsed " << std::chrono::duration<double,std::milli>(diff).count() << " ms)" << std::endl;
  else
    std::cout << "Directory " << path2 << " NOT exist (elapsed " << std::chrono::duration<double,std::milli>(diff).count() << " ms)" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;


//test function static std::string running_path(); ==> FUNCTION 6
  ret = true;
  std::string path3 =  "/home/gta/new_dir";
  std::cout << "============================================================" << std::endl;
  std::cout << "TEST FUNCTION bool directory_exist(const std::string& dir_name);" << std::endl;
  start = std::chrono::steady_clock::now();
  try
  {
    myPath::path_directory::create_directory(path3);
  }
  catch(const myPath::path_directory::invalid_path& ex)
  {
    ret = false;
    std::cout << ex.what() << " ";
  }
  end = std::chrono::steady_clock::now();
  diff = end - start;
  if(ret)
    ret = myPath::path_directory::directory_exist(path3);

  if(ret)
    std::cout << "Directory " << path3 << " create (elapsed " << std::chrono::duration<double,std::milli>(diff).count() << " ms)" << std::endl;
  else
    std::cout << "Directory " << path3 << " NOT create (elapsed " << std::chrono::duration<double,std::milli>(diff).count() << " ms)" << std::endl;
  std::cout << "============================================================" << std::endl;
  std::cout << std::endl;








  return EXIT_SUCCESS;
}
