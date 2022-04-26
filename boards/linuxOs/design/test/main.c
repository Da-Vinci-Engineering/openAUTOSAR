#include "createBoard.h"

extern void streamFile(const char *filename);

int main(int argc, char **argv) 
{
    if (argc != 2)
        return(1);

    streamFile(argv[1]);

    /*
     * Cleanup function for the XML library.
     */
    xmlCleanupParser();
    /*
     * this is to debug memory for regression tests
     */
    xmlMemoryDump();
    return(0);
}
