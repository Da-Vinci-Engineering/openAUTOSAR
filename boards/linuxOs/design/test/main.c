/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/
#include <stdio.h>
#include <libxml/xmlreader.h>

#include "createBoard.h"

extern void processDoc(xmlTextReaderPtr readerPtr);
extern configFileData cfg;

int main(int argc, char **argv)
{
    xmlTextReaderPtr readerPtr;
    int ret = -1;

    if (argc < 1)
    {
        return (1);
    }

    readerPtr = openConfigFile(argv[1]);
    if (NULL == readerPtr)
    {
        fprintf(stderr, "%s: failed to create reader\n", argv[1]);
        return (1);
    }

    ret = processConfigDoc(readerPtr);
    if (ret == 0)
    {
        fprintf(stderr, "New File:%s\n", cfg.name);
        xmlReaderNewFile(readerPtr, cfg.name, NULL, 0);
        if (NULL == readerPtr)
        {
            fprintf(stderr, "Failed to create reader: %s\n", cfg.name);
            return (1);
        }
        processConfigDoc(readerPtr);

        /*
         * Clean up the reader.
         */
        xmlFreeTextReader(readerPtr);

        /*
         * Cleanup function for the XML library.
         */
        xmlCleanupParser();

        free(cfg.name);

        /*
         * this is to debug memory for regression tests
         */
        xmlMemoryDump();
    }
    return (0);
}
