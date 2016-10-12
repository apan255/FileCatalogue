#ifndef FILEMGR_H
#define FILEMGR_H
/////////////////////////////////////////////////////////////////////
//  FileMgr.h -    Makes call to the FileSystem and DataStore      //
//			    	classes			        					   //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2013                                 //
//  Platform:      Dell, Windows 8.1                               //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Author:		   Ankur Pandey                                    //
/////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
This module defines a class that provides services necessary to search and transfer files and path found to store in dataStore package.

Public Interface:
=================

FileMgr fm;                                                             // Get FileMgr Instance
fm.search(const std::string& path, patterns patterns_, bool isSearchRecursively); // Searching File and Path recursively and transfering to Data Store to save it
std::vector<ElementDisplay> dataStoreVec = fm.printDataStoreMap();      // Return vector for Displaying Map Store
int Value = fm.dataStoreSize();                                         // Return Data Store Size
DataStore& dataStore_ = fm.getDataStoreReference();                     // Return Data Store Reference

Build Process:
==============
Required files
- FileSystem.h, DataStore.h , ElementDisplay.h ,FileSystem.cpp, DataStore.cpp

Build commands
- devenv FileMgr.vcxproj

Maintenance History:
====================
ver 1.0 : 8 Feb 2015
- first release
*/

#include "../DataStore/ElementDisplay.h"
#include "../FileSystem/FileSystem.h"
#include "../DataStore/DataStore.h"
#include <iostream>
#include <vector>

class FileMgr
{
public:
	using vectorStore = std::vector < std::string > ;
	using vectorEle = std::vector < ElementDisplay > ;
	using patterns = std::vector < std::string > ;

	void search(const std::string& path, patterns patterns_, bool isSearchRecursively);
	vectorEle printDataStoreMap();
	DataStore&  getDataStoreReference();
	int dataStoreSize();
	FileMgr();

private:
	void searchFiles(std::string path, std::string pattern, bool listRecursively);
	DataStore Datastore_;
};
#endif
