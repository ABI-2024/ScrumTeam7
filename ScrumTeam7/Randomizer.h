#pragma once

#include <windows.h>

class Randomizer
{
	// Systemzeit f�r Random Zahlen
	static SYSTEMTIME st;
	static bool active;

	static void activate();
public:
	static int randomize( int range);
	static int randomize( int range , int begin);

};

