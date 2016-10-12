#ifndef FILEMGR_H
#define FILEMGR_H
#include "FileSystem.h"
#include "../DataStore/DataStore.h"
#include <iostream>
#include <vector>
class FileMgr
{
public:

	using iterator = DataStore::iterator;
	using patterns = std::vector<std::string>;
	FileMgr(const std::string& path, DataStore& ds);
	void addPattern(const std::string& patt);
	void search();
	void find(const std::string& path);
	void parseCmdLine(int argc, char* argv[]);

private:
	bool bShowFuncSizeComplexity;
	bool isSearchRecursively;
	void searchFiles(std::string path, std::string pattern, bool listRecursively);
	std::string path_;
	DataStore& store_;
	patterns patterns_;
};
#endif
