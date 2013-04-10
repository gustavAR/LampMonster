#ifndef CLASSIFIERFACTORY_H
#define CLASSIFIERFACTORY_H

#include "Classifier.h"
#include <boost/program_options/variables_map.hpp>

class ClassifierFactory
{
public:
	static Classifier Create(boost::program_options::variables_map vm);
};

#endif
