#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <iostream>

using namespace std;
using namespace boost::program_options;

int main(int argc, char *argv[])
{
	options_description cmdonly_desc("General options");
	cmdonly_desc.add_options()
		("help,h", "produce help text")
		("-info,i", "print information about what the program does"
						"as it is run.")
		("version,v", "prints version string");


	typedef vector<string> vec;
	options_description config_desc("Config options");
	config_desc.add_options()
		("algorithm,a", value<vec>(), 
		 "specify algorithms to be used: NA, PER or APER")
		("train,t", value<vec>(), 
		 "categories that will be used when training.")
		("output,o", value<vec>(), "files to be classified.")
		("trainsize", value<int>()->default_value(10),
		 "number of files that will be used in each training"
		 "set to train the algorithms.")
	   ("outputsize", value<int>()->default_value(-1),
		 "number of files that will be evaluated. (-1) = all files")
		("random,r", value<bool>()->default_value(false),
		 "if true the training set will be selected at random."
		 "otherwize the first -ts will be selected for training.");
		

	options_description cmdline_desc;
	cmdline_desc.add(config_desc).add(cmdonly_desc);

	variables_map vm;
	store(parse_command_line(argc,argv,cmdline_desc), vm);
	store(parse_config_file<char>("config.cfg", config_desc), vm);
	notify(vm);	


	if (vm.count("help")) {
		cout << cmdline_desc << endl;
		return 1;
	}

	

	return 0;
}

