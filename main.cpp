#include "src/TempFolder.hpp"
#include <chrono>
#include <filesystem>
#include <thread>

int main() {

  TempFolder tf("temp", std::chrono::minutes(5));
  const std::filesystem::path filePath = "temp";

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
