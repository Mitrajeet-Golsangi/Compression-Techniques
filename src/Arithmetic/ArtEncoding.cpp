#include <iostream>
#include <cstring>

#include "../../include/arithmetic.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc == 4)
	{

		if (strcmp(argv[1], "-c") == 0)
		{
			Encode obj;
			obj.encode(argv[2], argv[3]);
		}
		else if (strcmp(argv[1], "-d") == 0)
		{
			Decode obj;
			obj.decode(argv[2], argv[3]);
		}
		return 0;
	}
	else
	{
		cout << "Usage:\n\t Arithmetic -c inputfile outputfile : For Compression\n\t Arithmetic -d inputfile outputfile : For Decompression" << endl;
		exit(1);
	}
}
