#ifndef IPATH_FINDER_H
#define IPATH_FINDER_H
#include <boost/filesystem/path.hpp>
#include <boost/utility/base_from_member.hpp>
#include <string>
#include <vector>

class IPathFinder
{
public:
	virtual std::vector<boost::filesystem::path>
		GetTrainingPaths(const std::string& category) = 0;

	virtual std::vector<boost::filesystem::path>
				GetProcessingPaths(const std::string& category)  = 0;
};

#endif