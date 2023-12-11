#pragma once
#include <optional>
#include <string>
#include <chrono>


class TempFolder {
public:
  TempFolder(const std::string& folderName, const std::chrono::seconds& duration);
  TempFolder(const std::string& folderName, const std::chrono::minutes& duration);
  TempFolder(const std::string& folderName, const std::chrono::hours& duration);
  TempFolder(const std::string& folderName);
  ~TempFolder(){}

  void openNewTempFolder();
  void notifyOfNewFile() const;
  void notifyDeletedFile() const;
  void deleteTempFolder();
  void addMoreTime();

  std::chrono::system_clock getTimeLeft() const;
  
  

private:
  std::string _folderName;
  std::optional<std::chrono::seconds> _durInSec;
  std::optional<std::chrono::minutes> _durInMin;
  std::optional<std::chrono::hours> _durInHours;

  void setEndTime();
  std::chrono::time_point<std::chrono::system_clock> _startTime, _endTime;

};
