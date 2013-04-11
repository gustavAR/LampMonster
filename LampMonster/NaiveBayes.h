#ifndef NAIVEBAYES_H
#define NAIVEBAYES_H

#include <map>
#include <vector>
#include <string>
#include "Classifier.h"
#include <boost/filesystem.hpp>

typedef std::pair<std::string, std::map<std::string, int>> Category;
typedef std::map<std::string, std::vector<boost::filesystem::path>> CategoryPaths;

class NaiveBayes : public Classifier
{
public:
	NaiveBayes(CategoryPaths paths);
	virtual std::string Classify(std::vector<std::string>& words);
private:
	std::vector<Category> categories;
	int prior;
};


double NBC(double p, const std::map<std::string, int>& voc, const std::vector<std::string>& word, double prior);

#endif 