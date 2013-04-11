#pragma once
#include "PathFinderBase.h"

namespace bfs = boost::filesystem;
using namespace std;

class CategoryPathFinder :
	public PathFinderBase
{
public:
	CategoryPathFinder(const bfs::path& root,
					   const int numTrainingFiles,
					   const int numProcessingFiles)
    : PathFinderBase(root, numTrainingFiles, numProcessingFiles) { }
	
	virtual  std::vector<bfs::path> 
				GetTrainingPaths(const std::string& category);

	virtual std::vector<bfs::path> 
				GetProcessingPaths(const std::string& category);
private:
	vector<bfs::path> GetPaths(const bfs::path& dir, const int start,
							   const int count);
};


vector<bfs::path> CategoryPathFinder::GetPaths(const bfs::path& dir, const int start, const int count) 
{
	vector<bfs::path> paths(count);
	bfs::path posDir = dir / "pos";
	bfs::path negDir = dir / "neg";

	for (int i = start, j = 0; i < start + count / 2; i++, j++) {
		paths[j*2] = (posDir / (to_string(i) + ".txt"));
		paths[j*2 + 1] = (negDir / (to_string(i) + ".txt"));
	}
	
	return paths;
}

vector<bfs::path> CategoryPathFinder::GetTrainingPaths(const string& category) 
{
	return GetPaths(root / category, 1, numTrainingFiles);
}

vector<bfs::path> CategoryPathFinder::GetProcessingPaths(const string& category)
{
	return GetPaths(root / category, numTrainingFiles / 2 + 1, numProcessingFiles);
}

