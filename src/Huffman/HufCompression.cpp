#include <iostream>
#include <cstring>
#include "../../include/huffman.h"
#include "../../include/file_handler.h"

using namespace std;

int main(int argc, char *argv[])
{
    char *option = argv[1];
    if (argc == 4)
    {
        if (strcmp(option, "-c") == 0)
        {
            Huffman h(argv[2], argv[3]);
            h.create_pq();
            h.create_huffman_tree();
            h.calculate_huffman_codes();
            h.coding_save();
            cout << endl;
            
            get_compression_ratio(argv[2], argv[3]);

            exit(1);
        }
        else if (strcmp(option, "-d") == 0)
        {
            Huffman h(argv[2], argv[3]);
            h.recreate_huffman_tree();
            h.decoding_save();
            cout << endl;
            exit(1);
        }
    }
    else
    {
        cout << "Usage:\n\t HufCompression -c inputfile outputfile : For Compression\n\t HufCompression -d inputfile outputfile : For Decompression" << endl;
        exit(1);
    }
    return 0;
}