#ifndef CATALOGER_H
#define CATALOGER_H
/////////////////////////////////////////////////////////////////////
//  Cataloger.h - Makes call to the FileManager which then         //
//               calls to DataStore classes                        //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2013                                 //
//  Platform:      Dell, Windows 8.1                               //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Author:		   Ankur Pandey                                    //
/////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
This module defines a class that provides services necessary to search text, files and Directories on a build catalogue DataStore by FileMgr.

Public Interface:
=================
Cataloger cat(FileMgr);                                          // Cataloger constructor with filMgr Ref
std::vector< ElementDisplay> vec = cat.searchUserText(vectorStore& patterns_,std::string searchText);
// Searching user text along with specifc patterns provided
if not then defaut *.* and Returning as vector of display element
std::vector< ElementDisplay> vec = cat.displayDuplicateFilesAndDirectories();
// Searching Duplicate files and Returning as vector of display element
std::vector< ElementDisplay> vec = cat.displayNumofFileAndDirectories
// Searching Number Of Files Found And Directories
std::vector< ElementDisplay> vec = cat.printPathStore();        // Iterating PathStore and Storing it as vector of display element and returning it
std::vector< ElementDisplay> vec = cat.printFileStore();        // Iterating FileStore and Storing it as vector of display element and returning it

Build Process:
==============
Required files
- FileSystem.h, FileSystem.cpp , FileMgr.h, FileMgr.cpp, ElementDisplay.h
Build commands
- devenv Cataloger.vcxproj

Maintenance History:
====================
ver 1.0 : 8 Feb 2015
- first release
*/

#include "../FileSystem/FileSystem.h"
#include "../FileMgr/FileMgr.h"
#include "../DataStore/ElementDisplay.h"
#include <iostream>
#include <vector>

class Cataloger
{
public:

	using file = std::string;
	using path = std::string;
	using setPathStore = std::set < path > ;
	using pathIterator = std::set<path>::iterator;
	using pathRef = std::list < pathIterator > ;
	using pathRefIterator = std::list<pathIterator>::iterator;
	using mapDataStore = std::map < file, pathRef > ;
	using mapDataStoreIterator = std::map<file, pathRef>::iterator;
	using patterns = std::vector < std::string > ;
	using filesFound = std::map < std::string, std::string > ;
	using filesFoundIterator = std::vector<std::string>::iterator;
	using vectorStore = std::vector < std::string > ;
	using vectorEle = std::vector < ElementDisplay > ;

	Cataloger(FileMgr& fm);
	vectorEle searchUserText(vectorStore& patterns_, std::string searchText);
	vectorEle displayDuplicateFilesAndDirectories();
	vectorEle printPathStore();
	vectorEle printFileStore();
	vectorEle displayNumofFileAndDirectories();

private:
	filesFound filesFound_;
	FileMgr& fileMgr_;

	bool Cataloger::checkFileFound(std::string filename, std::string pattern);
	bool Cataloger::issearchAllFiles(vectorStore& patterns_);
	bool textSearch(const std::string searchtext, const std::string& filePath, const std::string& filename);
};
#endif
