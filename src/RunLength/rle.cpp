#include <iostream>
#include <fstream>
#include <cstring>
#include "../../include/rle.h"

using namespace std;

void RLECompression::compress(ifstream& inFile, ofstream& outFile)
{
	nextByte = inFile.get();
	previousByte = nextByte;
	
	while(nextByte != EOF)
	{
		runLength = 1;
		
		previousByte = nextByte;
		
		while((nextByte = inFile.get()) != EOF && nextByte == previousByte)
			runLength++;
			
		outFile.put(runLength);
		outFile.put(previousByte);
	}
}

void RLECompression::decompress(ifstream& inFile, ofstream& outFile)
{
	while((runLength = inFile.get()) != EOF)
	{	
		nextByte = inFile.get();
		
		for(int i = 0; i < runLength; i++)
			outFile.put(nextByte);
	}
}
