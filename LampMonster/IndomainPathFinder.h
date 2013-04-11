#pragma once
#include "PathFinderBase.h"

namespace bfs = boost::filesystem;
using namespace std;

class IndomainPathFinder :
	public PathFinderBase
{
public:
	IndomainPathFinder(const boost::filesystem::path& root,
					   const int numTrainingFiles,
					   const int numProcessingFiles)
    : PathFinderBase(root, numTrainingFiles, numProcessingFiles) { }
	
	virtual  std::vector<boost::filesystem::path> 
				GetTrainingPaths(const std::string& category);

	virtual std::vector<boost::filesystem::path> 
				GetProcessingPaths(const std::string& category);
private:
	vector<bfs::path> GetPaths(const bfs::path& dir, const int start,
							   const int count);
};


vector<bfs::path> IndomainPathFinder::GetPaths(const bfs::path& dir, const int start, const int count) 
{
	vector<bfs::path> paths(count);
	for (int i = start; i < start + count; i++)
		paths[i - start] = (dir / (to_string(i + 1) + ".txt"));
	
	return paths;
}

vector<bfs::path> IndomainPathFinder::GetTrainingPaths(const string& category) 
{
	return GetPaths(root / category, 1, numTrainingFiles);
}

vector<bfs::path> IndomainPathFinder::GetProcessingPaths(const string& category)
{
	return GetPaths(root / category, numTrainingFiles, numProcessingFiles);
}
