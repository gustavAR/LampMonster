#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <algorithm>
#include <string>
#include "file_manager.h"

#define VERSION_NUMBER 0.0
#define DEFAULT_TRAIN_SIZE 10


using namespace std;
using namespace boost::program_options;
using namespace boost::filesystem;

/*Creates an option_description with describes 
 *all the commands that can only be invoked 
 *throug the command line. (includes help and others) 
 */
options_description GetCmdOnlyOptions()
{
	options_description cmdonly_desc("General options");
	cmdonly_desc.add_options()
		("help,h", "produce help text")
		("-info,i", "print information about what the program does"
						"as it is run.")
		("version,v", "prints version string");

	return cmdonly_desc;
}
/* Creates an option_descripton witch describes
  * general configuration options. Any of these
  * options can be specified through the command
  * line or written in the configuration file.
  */
options_description GetConfigOptions() 
{
	typedef vector<string> vec;
	options_description config_desc("Config options");
	config_desc.add_options()
		("algorithm,a", value<vec>(), 
		 "specify algorithms to be used: NA, PER or APER")
		("train,t", value<vec>(), 
		 "categories that will be used when training.")
		("output,o", value<vec>(), "files to be classified.")
		("trainsize", value<int>()->default_value(DEFAULT_TRAIN_SIZE), 
		 "number of files that will be used in each training"
		 "set to train the algorithms.")
	   ("outputsize", value<int>()->default_value(-1),
		 "number of files that will be evaluated. (-1) = all files")
		("random,r", value<bool>()->default_value(false),
		 "if true the training set will be selected at random."
		 "otherwize the first -ts will be selected for training.")
		 ("rootpath", value<string>(), "root to the amazon files.");
	return config_desc;	
}

/*
 * Takes care of all the cases that would cause the program to do an early return.
 * This gives users a chanse to see (some errors) in input data and provide other
 * services such as help and version information.
 */
int handleEarlyReturn(const variables_map& vm, const options_description& cmdline_desc) 
{
	if (vm.count("help")) {
		cout << cmdline_desc << endl;
		return 1;
	} else if(vm.count("version")) {
		cout << "Version: " << VERSION_NUMBER << endl; 
	}	else if (!vm.count("algorithm")) {
		cout << "Please specify atleast one algorithm to use. " << endl;	
		return 2;
	} else if (!vm.count("train")) {
		cout << "Please specify atleast one category to train on. " << endl;	
		return 3;
	} else if (!vm.count("output")) {
		cout << "Please specify atleast one output category. " << endl;	
		return 4;
	} else if(vm["trainsize"].as<int>()  <= 0) {
		cout << "trainsize must be greater then 0!" << endl;
		return 5;
	}	


}

int main(int argc, char *argv[])
{	

	auto cmdonly_desc = GetCmdOnlyOptions();
	auto config_desc = GetConfigOptions();
	
	options_description cmdline_desc;
	cmdline_desc.add(config_desc).add(cmdonly_desc);

	variables_map vm;
	store(parse_command_line(argc,argv,cmdline_desc), vm);
	try {
		store(parse_config_file<char>("config.cfg", config_desc), vm);
	} catch(...) {
	    cout << "no config found\n";
	}
	notify(vm);

	if(!handleEarlyReturn(vm, cmdline_desc))
		return 1;

	fileManagerTests();

	//Read input from the command line and the config file.
	auto trainingSize   = vm["trainsize"].as<int>();
	auto outputSize		= vm["outputsize"].as<int>();
	auto trainingSet    = vm["train"].as<vector<string>>();
	auto outputSet		= vm["output"].as<vector<string>>();
	auto randomize		= vm["random"].as<bool>();
	bool printInfo		= vm.count("info"); 
	path rootPath(vm["rootpath"].as<string>());

	auto posTrainPaths = GetTrainingPaths(rootPath, trainingSet, "pos", trainingSize);
	auto negTrainPaths = GetTrainingPaths(rootPath, trainingSet, "neg", trainingSize);

	auto posProcessingPaths = GetProcessingPaths(rootPath, outputSet, "pos", trainingSize, outputSize);
	auto negProcessingPaths = GetProcessingPaths(rootPath, outputSet, "neg", trainingSize, outputSize);

	//auto posBagOfWords = BuildBagOfWords(posTrainPaths);
	//auto negBagOfWords = BuildBagOfWords(negTrainPaths);
	
	//for(int i = 0; i < outputSize; i++) {
	//	auto words = ReadWordsFromFile(posProcessingPaths[i]);
	//	double posResult = ProcessNaiveBayes(0.5, words, posBagOfWords);
	//	double negResult = ProcessNaiveBayes(0.5, words, negBagOfWords);
	//  if(posResult < negResult)
	//		cout << "Naive Bayes was correct on file: " << posProcessingPaths[i] << '\n';
	//	else
	//		cout << "Naive Bayes was inncorrect on file: " << posProcessingPaths[i] << '\n';
	//}

/*
	cout << "Trainsize: " << trainingSize 
		  << " OuputSize: " << outputSize 
		  << "\nRandomize: " << randomize 
		  << " Print info: " << printInfo
		  << "\nTrainingSet: ";
	copy(begin(trainingSet), end(trainingSet), ostream_iterator<string>(cout, " "));

   cout  << "\nOutputSet: "; 
	copy(begin(outputSet), end(outputSet), ostream_iterator<string>(cout, " "));
*/
	

	return 0;
}

