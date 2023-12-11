#include "TempFolder.hpp"
#include <chrono>
#include <ctime>
#include <filesystem>
#include <iostream>

TempFolder::TempFolder(const std::string& folderName, const std::chrono::seconds& duration): _folderName(folderName), _durInSec(duration){
  
}

TempFolder::TempFolder(const std::string& folderName, const std::chrono::minutes& duration): _folderName(folderName),_durInMin(duration){
  
}

TempFolder::TempFolder(const std::string& folderName, const std::chrono::hours& duration): _folderName(folderName), _durInHours(duration){}

TempFolder::TempFolder(const std::string& folderName): _folderName(folderName){}


void TempFolder::openNewTempFolder(){
  namespace fs = std::filesystem;
  fs::path newFolderPath = _folderName;
  
  if(fs::exists(newFolderPath)){
    system("notify-send TempFolder \"Folder already exist, choose another folder name.\"");
    throw "Error: folder already exists.";
  }
    fs::create_directory(_folderName);
  
  _startTime = std::chrono::system_clock::now();
  //sets end time to be start time + the desired duration in seconds(epoch time).
  setEndTime();

  std::time_t tt;
  tt = std::chrono::system_clock::to_time_t(_endTime);
  
  std::string sucess_created = "notify-send TempFolder \"Created sucssesfuly temporary directory.\nend time: ";
  std::string qm = "\"";
  sucess_created.append(ctime(&tt)+qm);


  //system("notify-send TempFolder \"Created sucssesfuly temporary directory.\"" + str.c_str());
  system(sucess_created.c_str());
}

void TempFolder::setEndTime(){
  namespace chrono =  std::chrono;
  _startTime  = chrono::system_clock::now();
  _endTime = _startTime + 
    chrono::seconds(_durInSec.has_value() ? _durInSec.value().count() : 0) +
    chrono::minutes(_durInMin.has_value() ? _durInMin.value().count() : 0) +
    chrono::hours(_durInHours.has_value() ? _durInHours.value().count() : 0);
  
}

