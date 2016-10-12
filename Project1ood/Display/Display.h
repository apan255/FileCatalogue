#ifndef DISPLAY_H
#define DISPLAY_H
/////////////////////////////////////////////////////////////////////
//  Dispaly.h - display analysis facility of a build catalogue.    //
//					                							   //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2013                                 //
//  Platform:      Dell, Windows 8.1                               //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Author:		   Ankur Pandey                                    //
/////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
This module defines a class that provides services necessary to display analysis facility of a build catalogue.

Public Interface:
=================
Display ds;                                                         // Create Display Instance
Display ds(filesCatDisplay, duplicatedisplay,DulicateFilesAndDir);  // Initialise Display instance with analysed scopes
based on isDuplicateSearch,isSearchtext,isDisplayNumofFileAndDirect
which will be analysed to display in printOutput()
ds.printOutput(isDuplicateSearch,isSearchtext,isDisplayNumofFileAndDirec); // Display based on analysed boolean values
ds.userInput(std:: string userInputString);                         // Print User Command line Input
ds.printPathStore(printPathStore);                                  // Print Path Store
ds.printFileStore(printFileStore);                                  // Print File Store

Build Process:
==============
Required files
- Display.h, Display.cpp , ElementDisplay.h
Build commands
- devenv Display.vcxproj

Maintenance History:
====================
ver 1.0 : 8 Feb 2015
- first release
*/

#include<vector>
#include "../DataStore/ElementDisplay.h"

class Display{

public:

	using filesCatDisplay = std::vector < ElementDisplay > ;
	using duplicatedisplay = std::vector < ElementDisplay > ;
	using DulicateFilesAndDir = std::vector < ElementDisplay > ;
	using VectorElementDisplay = std::vector < ElementDisplay > ;

	Display::Display(filesCatDisplay filesCatDisplay, duplicatedisplay dupDispalyVec, DulicateFilesAndDir numberOfFilesAndDir);
	void printOutput(bool isDuplicateSearch, bool isSearchtext, bool isDisplayNumofFileAndDirect);
	void userInput(std::string userInputString);
	void printPathStore(VectorElementDisplay printPathStore);
	void printFileStore(VectorElementDisplay printFileStore);
	Display();
private:

	filesCatDisplay filesCatDisplayVec_;
	duplicatedisplay duplicatedisplayVec_;
	DulicateFilesAndDir numberOfFilesAndDirVec_;
	void printPathsFoundOutput(ElementDisplay fileDisplay);
	void printHeader(std::string header);
	void printFileAndPaths(ElementDisplay dubDisplay);
	void printDisplayNumofFileAndDirectOutput(ElementDisplay ndDisplay);
	void printFilesFoundOutput(ElementDisplay fileDisplay);
};
#endif
