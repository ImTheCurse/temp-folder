#include "src/TempFolder.hpp"
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <variant>
#include <string>
#include <type_traits>
#include <iostream>

class InputParser{
    public:
        InputParser (int &argc, char **argv){
            for (int i=1; i < argc; ++i)
                this->tokens.push_back(std::string(argv[i]));
        }
        /// @author iain
        const std::string& getCmdOption(const std::string &option) const{
            std::vector<std::string>::const_iterator itr;
            itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
            if (itr != this->tokens.end() && ++itr != this->tokens.end()){
                return *itr;
            }
            static const std::string empty_string("");
            return empty_string;
        }
        /// @author iain
        bool cmdOptionExists(const std::string &option) const{
            return std::find(this->tokens.begin(), this->tokens.end(), option)
                   != this->tokens.end();
        }
    private:
        std::vector <std::string> tokens;
};


int main(int argc, char**argv) {
  bool gotTimeFormat = false;  
  int time = 0;
  int v_index = -1;
  std::string filePath;
  std::variant<std::chrono::seconds,std::chrono::minutes,std::chrono::hours>newTime; 

  InputParser input(argc,argv);

  if(input.cmdOptionExists("-n")){
    filePath = input.getCmdOption("-n");
    
  }
  
  if(input.cmdOptionExists("-t")){
    std::string s = input.getCmdOption("-t");
    time = std::atoi(s.c_str());
  }

  if(input.cmdOptionExists("-f")){
    if(input.getCmdOption("-f") == "s"){
      newTime = std::chrono::seconds(time);
    }
    if(input.getCmdOption("-f") == "m"){
      newTime = std::chrono::minutes(time); 
    }
    if(input.getCmdOption("-f") == "h"){
      newTime = std::chrono::hours(time);

    }
  }


    TempFolder tf(filePath, std::holds_alternative<std::chrono::seconds>(newTime) ? std::get<0>(newTime) : 
                  std::holds_alternative<std::chrono::minutes>(newTime) ? std::get<1>(newTime) :
                  std::get<2>(newTime)
                  );
  
  tf.openNewTempFolder();
  while (tf.getTimeLeft() > 0) {

    if (tf.wasFileAdded()) {
      tf.notifyOfNewFile();
    }
    if (tf.wasFileRemoved()) {
      tf.notifyDeletedFile();
    }

    std::this_thread::sleep_for(std::chrono::seconds(30));
  }
  tf.deleteTempFolder();

  return 0;
}
