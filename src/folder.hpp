#pragma once
#include <string>
#include <chrono>


class Folder {
public:
  Folder(std::string folderName, std::chrono::seconds duration);
  Folder(std::string folderName, std::chrono::minutes duration);
  Folder(std::string folderName, std::chrono::hours duration);
  Folder(std::string folderName);
  ~Folder(){}

  void openNewFolder();
  void notifyOfNewFile();
  void notifyDeletedFile();
  void deleteFolder();
  void addMoreTime();

  std::chrono::system_clock getTimeLeft();
  
  

private:
  std::string _folderName;
  std::chrono::system_clock startTimeInEpoch;
  std::chrono::system_clock endTimeInEpoch;

};
