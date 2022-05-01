/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/
#include <stdio.h>
#include <libxml/xmlreader.h>

#include "createBoard.h"

/**
 * Simple example to parse a file called "file.xml", 
 * walk down the DOM, and print the name of the 
 * xml elements nodes.
 */
int
main(int argc, char **argv)
{
    configFileData cfg;
    boardDefinition bcfg;

    if (argc != 2)
        return(1);

    int ret = getBoardDescriptionFileName(argv[1], &cfg);

    if (ret == 0)
    {
        ret = getBoardDefinition(cfg.name, &bcfg);
    }

    return 0;
}
