#include "file_manager.h"
#include <boost/filesystem.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace boost::filesystem;

const std::string file_ext(".txt");

void validateDir(const path& directory) {
	if(!exists(directory))
		throw runtime_error(string("Classification directory "
							+ directory.string() + " does not exist."));

	if(!is_directory(directory))
		throw runtime_error(string("Classification directory"
						    + directory.string() + " is not a directory."));
}

const vector<path> GetPaths(const path& root,
						   const vector<string>& categories,
						   const string& classification, 
						   const int startIndex,
						   const int count) {
	vector<path> paths;
	validateDir(root);
	for(auto& clasification : categories) {
		path clsDir = root / clasification;
		validateDir(clsDir);

		path posDir = clsDir / classification;
		for (int i = startIndex; i < startIndex + count; ++i) {
			const string file = to_string(i) + file_ext;
			paths.push_back(posDir / file);
		}
	}

	return paths;
}


const vector<path> GetTrainingPaths(const path& root,
						   const vector<string>& categories,
						   const string& classification, 
						   const int trainSize) 
{
	//At the moment we igonre randomization of test data. Can always be added later.
	return GetPaths(root, categories, classification, 0, trainSize);
}

const vector<path> GetProcessingPaths(const path& root,
							    const vector<string>& categories,
							    const string& classification, 
							    const int trainSize,
								const int processCount)
{
	return GetPaths(root, categories, classification, trainSize, processCount);
}


// Below are temporary bad testing untill we get a proper unit framework!

void fileManagerTests() {
	boost::filesystem::path root("..\\Documents\\amazon-balanced-6cats\\");
	cout << boost::filesystem::exists(root) << " " << root;

	vector<string> categories;
	categories.push_back("camera");

	auto posTrainingPaths = GetTrainingPaths(root, categories, "pos", 10);
	auto negTrainingPaths = GetTrainingPaths(root, categories, "neg", 10);
	auto posProcessingPaths = GetProcessingPaths(root, categories, "pos", 10, 20);
	auto negProcessingPaths = GetProcessingPaths(root, categories, "neg", 10, 20);

	using namespace boost::filesystem;

	cout << "Posetive training paths -----------------------------------\n";
	copy(begin(posTrainingPaths), end(posTrainingPaths), ostream_iterator<path>(cout, "\n"));

	cout << "Negative training paths -----------------------------------\n";
	copy(begin(negTrainingPaths), end(negTrainingPaths), ostream_iterator<path>(cout, "\n"));

	cout << "Posetive processing paths -----------------------------------\n";
	copy(begin(posProcessingPaths), end(posProcessingPaths), ostream_iterator<path>(cout, "\n"));

	cout << "Negative processing paths -----------------------------------\n";
	copy(begin(negProcessingPaths), end(negProcessingPaths), ostream_iterator<path>(cout, "\n"));
}