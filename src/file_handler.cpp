#include <iostream>
#include <fstream>
#include "../include/file_handler.h"

using namespace std;

int calculate_size(string filename)
{
    ifstream file(filename, ios::binary);

    file.seekg(0, ios::end);
    int file_size = file.tellg();
    
    return file_size;
}

void get_compression_ratio(string original, string compressed)
{
    float og_size = calculate_size(original);
    float cp_size = calculate_size(compressed);

    float cmp = (cp_size / og_size) * 100;

    cout << "File compression was : " << cmp << " %";
}