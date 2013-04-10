#include "FileParser.h"
#include <algorithm>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file.hpp>

namespace fs = boost::filesystem;
namespace io = boost::iostreams;
using namespace std;

FileParser::FileParser(const string& delims) 
	: delimiters(delims)
{  }

void FileParser::Parse(const fs::path& path, vector<string>& words) const
{
	using namespace boost::algorithm;
	io::stream<io::file_source> file(canonical(path).string());
	string line;
	vector<string> tmp;
	while (getline(file, line)) {
		split(tmp, line, is_any_of(delimiters), token_compress_on);
		copy(tmp.begin(), tmp.end(), back_inserter(words));
		tmp.clear();
	}
	file.close();
}

void ChangeToUpper(vector<string>& words) 
{
	for(auto& word : words) {
		std::transform(word.begin(), word.end(), word.begin(), toupper);
	}
}


vector<string> FileParser::ParseFile(const fs::path& filepath) const
{
	vector<string> words;
	Parse(filepath, words);
	ChangeToUpper(words);
	return words;
}

vector<string> FileParser::ParseFiles(const vector<fs::path>& filepaths) const
{
	vector<string> words;
	for(auto& filepath : filepaths)
		Parse(filepath, words);
	ChangeToUpper(words);
	return words;	
}

void testFileParser() {
	using namespace fs;
	path filepath1("..\\Documents\\amazon-balanced-6cats\\books\\neg\\1.txt");//Create a bunch of paths
	path filepath2("..\\Documents\\amazon-balanced-6cats\\books\\neg\\2.txt");
	path filepath3("..\\Documents\\amazon-balanced-6cats\\books\\neg\\3.txt");
	vector<path> v;
	
	v.push_back(filepath1);
	v.push_back(filepath2);
	v.push_back(filepath3);
	
	FileParser parser(".,()[]{}\/>< :;\"`'*&^%$#@");

	auto words = parser.ParseFiles(v);
	copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
}