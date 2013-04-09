#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <iostream>
#include <algorithm>
#include <string>

#define VERSION_NUMBER 0.0
#define DEFAULT_TRAIN_SIZE 10


using namespace std;
using namespace boost::program_options;

static double NBC(double probOfClass, map<string,int> vocabulary, vector<string> words)
{
	double product = 1;
	int totNumWordsInVoc = 0;
	
	for(auto i = vocabulary.cbegin(); i != vocabulary.cend(); i++) //Get the sum of all words in the vocabulary map
		totNumWordsInVoc += i->second;

	for (string word : words) //calculate probalility for each word to belong to classification with the vocabulary
	{
		product *= (vocabulary.at(word)+1)/(totNumWordsInVoc + vocabulary.size());
	}
	return product*probOfClass;
}
void main(void)
{
	map<string,int> m;
	m["Buuuh"] = 2;
	m["Aaah"] = 1;
	m["Ooooh"] = 5;
	m["Oooiihihih"] = 2;
	m["Hehehaha"] = 3;
	m["Hahahahohohhuehue"] = 1;

	vector<string> s;
	s.assign("Buuuh");
	s.assign("Ooooh");
	s.assign("Hehehaha");
	s.assign("Buuuh");
	s.assign("Ooooh");
	s.assign("Hehehaha");
}