#include "src/TempFolder.hpp"
#include <chrono>
#include <iostream>
#include <filesystem>
int main(){

  TempFolder tf("temp",std::chrono::minutes(5));

  tf.openNewTempFolder();
  std::cout<<tf.getTimeLeft()<<std::endl;
  /*
  while(tf.getTimeLeft() > 0){

  }
*/

  return 0;
}
