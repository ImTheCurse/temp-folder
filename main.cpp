#include "src/TempFolder.hpp"
#include <chrono>
int main(){

  TempFolder tf("temp",std::chrono::minutes(5));

  tf.openNewTempFolder();

  return 0;
}
