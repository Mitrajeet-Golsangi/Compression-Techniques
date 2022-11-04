#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class RLECompression
{
	int runLength;	
	int nextByte;
	int previousByte;
	
	public:
		// RLECompression(char* option, ifstream& inFile, ofstream& outFile);
		void compress(ifstream& inFile, ofstream& outFile);
		void decompress(ifstream& inFile, ofstream& outFile);
};