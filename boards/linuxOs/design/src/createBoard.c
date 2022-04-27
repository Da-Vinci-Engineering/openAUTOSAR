/********************************************************************
* (C) DaVinci Engineering GmbH 2022
********************************************************************/

#include "stdio.h"
#include "createBoard.h"

#include <libxml/xmlreader.h>

configFileData cfgFile;

void
processConfigFileName(xmlTextReaderPtr reader) 
{
    const xmlChar *name, *value;
    int ret;

    name = xmlTextReaderConstName(reader);
    if (strcmp(name,"boarddescriptionfile") == 0)
    {
        ret = xmlTextReaderRead(reader);
        if (ret == 1)
        {
            value = xmlTextReaderConstValue(reader);
            cfgFile.name = (char *)malloc(strlen(value)+1);
            strcpy(cfgFile.name, value);
            printf("%s - %s\n", name, cfgFile.name);
        }
    }
}

int
streamConfigFile(const char *filename) 
{
    xmlTextReaderPtr reader;
    int readSuccess = 0;
    int parseSuccess = -1;

    reader = xmlReaderForFile(filename, NULL, 0);
    if (reader != NULL) 
    {
        readSuccess = xmlTextReaderRead(reader);
        if (readSuccess == 1) 
        {
            processConfigFileName(reader);
            xmlFreeTextReader(reader);
            parseSuccess = 0;
        }
        else 
        {
            parseSuccess = -1;
        }
        xmlCleanupParser();
        xmlMemoryDump();
    } 
    else 
    {
        parseSuccess = -1;
    }
    return(parseSuccess);
}

void
processNode(xmlTextReaderPtr reader) {
    const xmlChar *name, *value;

    name = xmlTextReaderConstName(reader);
    if (name == NULL)
	name = BAD_CAST "--";

    value = xmlTextReaderConstValue(reader);

    printf("%d %d %s %d %d", 
	    xmlTextReaderDepth(reader),
	    xmlTextReaderNodeType(reader),
	    name,
	    xmlTextReaderIsEmptyElement(reader),
	    xmlTextReaderHasValue(reader));
    if (value == NULL)
	printf("\n");
    else {
        if (xmlStrlen(value) > 40)
            printf(" %.40s...\n", value);
        else
	    printf(" %s\n", value);
    }
}

void
streamFile(const char *filename) 
{
    xmlTextReaderPtr reader;
    int ret;

    reader = xmlReaderForFile(filename, NULL, 0);
    if (reader != NULL) 
    {
        ret = xmlTextReaderRead(reader);
        while (ret == 1) 
        {
            processNode(reader);
            ret = xmlTextReaderRead(reader);
        }
        xmlFreeTextReader(reader);
        if (ret != 0) 
        {
            fprintf(stderr, "%s : failed to parse\n", filename);
        }
        xmlCleanupParser();
    } 
    else 
    {
        fprintf(stderr, "Unable to open %s\n", filename);
    }
}

