#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

typedef boost::filesystem::path file_path;

const std::vector<file_path> GetTrainingPaths(const file_path& root,
									 const std::vector<std::string>& categories,
									 const std::string& classification,
								   	 const int trainSize);

const std::vector<file_path> GetProcessingPaths(const file_path& root,
										  const std::vector<std::string>& categories,
										  const std::string& classification,
										  const int trainSize,
									      const int processCount);

std::vector<std::string> GetWords(file_path path);

void fileManagerTests();

#endif