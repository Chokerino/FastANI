/**
 * @file    core_genome_identity.cpp
 * @ingroup src
 * @author  Chirag Jain <cjain7@gatech.edu>
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include <functional>
#include <omp.h>

//Own includes

int main()
{
  /*
   * Make sure env variable MALLOC_ARENA_MAX is unset 
   * for efficient multi-threaded execution
   */
  //std::cout<<"dsadasdasda"<<std::endl;
  //float x = system("./fastANI -q data/Escherichia_coli_str_K12_MG1655.fna -r data/Shigella_flexneri_2a_01.fna");
  //std::cout << x << std::endl;

  FILE * stream;
  std::string cmd = "./fastANI -q data/Escherichia_coli_str_K12_MG1655.fna -r data/Shigella_flexneri_2a_01.fna";
  cmd.append(" 2>error");
  const int max_buffer = 256;
  char buffer[max_buffer];
  stream = popen(cmd.c_str(), "r");
  std::string data;
  if (stream) {
    while (!feof(stream))
      if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
  }

  //std::cout << ::atof(data.c_str()) << std::endl;
  std::cout << std::stod(data) << std::endl;
}

//float getDistance(std::string query, std::string distance)
//{
//  
//}