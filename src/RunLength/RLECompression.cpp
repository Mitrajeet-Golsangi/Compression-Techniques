#include <iostream>
#include <fstream>
#include "../../include/rle.h"
#include "../../include/file_handler.h"

int main(int argc, char *argv[])
{

	ifstream inFile;
	ofstream outFile;
	RLECompression cmp;

	if (argc == 4)
	{

		char *option = argv[1];
		inFile.open(argv[2]);
		outFile.open(argv[3]);

		if (strcmp(option, "-c") == 0)
		{
			cmp.compress(inFile, outFile);
			get_compression_ratio(argv[3], argv[2]);
		}
		else if (strcmp(option, "-d") == 0)
		{
			cmp.decompress(inFile, outFile);
		}

		inFile.close();
		outFile.close();
	}

	else
	{
		cout << "Usage:\n\t RLECompression -c inputfile outputfile : For Compression\n\t RLECompression -d inputfile outputfile : For Decompression" << endl;
		exit(1);
	}
	return 0;
}
