/********************************************************************
* (C) DaVinci Engineering GmbH 2022
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/xmlreader.h>

#include "createBoard.h"

configFileData cfg;

xmlTextReaderPtr openConfigFile(char * fileName)
{

    xmlTextReaderPtr readerPtr;
    readerPtr = xmlReaderForFile(fileName, NULL, 0);
    if (NULL == readerPtr) 
    {
      fprintf(stderr, "%s: failed to create reader\n", fileName);      
    }
    return(readerPtr);
}

int processConfigDoc(xmlTextReaderPtr readerPtr)
{
    int ret = -1;
    int parsed = -1;
    const xmlChar *name = NULL; 
    const xmlChar *value = NULL;
 

    ret = xmlTextReaderRead(readerPtr);
    if (ret == 1) 
    {
        name = xmlTextReaderConstName(readerPtr);
        xmlTextReaderRead(readerPtr);
        value = xmlTextReaderConstValue(readerPtr);
        cfg.name = (char *)malloc(strlen((char *) value)+1);
        strcpy(cfg.name, (char * ) value);
        printf("%s-%s\n-%d\n", name, cfg.name, strlen((char *) value)+1);
        parsed = 0;
    }
    else
    {
        parsed = -1;
    }
    return(parsed);
}

