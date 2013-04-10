#include "BuildBagOfWords.h"
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file.hpp>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "FileParser.h"

using namespace std;
namespace fs = boost::filesystem;
namespace io = boost::iostreams;

const map<string, int> BuildBagOfWords(const vector<fs::path>& files)
{	
	using namespace boost::algorithm;
	map<string, int> bag;
	FileParser parser(".,()[]{}\/>< :;\"`'*&^%$#@");
	for(auto& word : parser.ParseFiles(files))
		bag[word]++;

	
	return bag;
}

void BuildBagTest(void){
	fs::path filepath1("..\\Documents\\amazon-balanced-6cats\\books\\neg\\1.txt");//Create a bunch of paths
	fs::path filepath2("..\\Documents\\amazon-balanced-6cats\\books\\neg\\2.txt");
	fs::path filepath3("..\\Documents\\amazon-balanced-6cats\\books\\neg\\3.txt");

	vector<fs::path> paths;
	paths.push_back(filepath1);
	paths.push_back(filepath2);
	paths.push_back(filepath3);

	auto bag = BuildBagOfWords(paths);

	for (auto itr = bag.begin(), end = bag.end(); itr != end; ++itr) {
		cout << itr->first << ", " << itr->second << endl;
	}
	int i = 1;
	cin>>i;
}