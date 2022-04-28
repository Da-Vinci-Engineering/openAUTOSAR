#include <stdio.h>
#include "createBoard.h"

extern void streamConfigFile(const char *filename);
extern void streamFile(const char *filename);
extern configFileData cfgFile;

int main(int argc, char **argv) 
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: testncboard <config_file>\n");
        return(1);
    }

    streamConfigFile(argv[1]);
    streamFile((char *) cfgFile.name);

    return(0);
}
