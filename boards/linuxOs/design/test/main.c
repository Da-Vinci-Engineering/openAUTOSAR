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

    streamFile("/home/marco/Projects/classic-platform/boards/linuxOs/design/test/linuxBoard.xml");
    streamFile(cfgFile.name);

    return(0);
}
