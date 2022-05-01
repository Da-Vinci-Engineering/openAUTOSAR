/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "createBoard.h"

int getBoardDescriptionFileName(char *fileName, configFileData *cfg)
{
    int ret = -1;

    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    /*parse the file and get the DOM */
    doc = xmlReadFile(fileName, NULL, 0);

    if (doc != NULL)
    {
        /*Get the root element node */
        root_element = xmlDocGetRootElement(doc);

        getFileNameFromDescriptionFile(root_element, cfg);

        /*free the document */
        xmlFreeDoc(doc);

        /*
         *Free the global variables that may
         *have been allocated by the parser.
         */
        xmlCleanupParser();
        ret = 0;
    }
    else
    {
        ret = -1;
    }

    return (ret);
}

void getFileNameFromDescriptionFile(xmlNode *a_node, configFileData *cfg)
{

    if (a_node->type == XML_ELEMENT_NODE)
    {
        if (strcmp((char *)a_node->name, "boarddescriptionfile") == 0)
        {
            xmlAttr *attribute = a_node->properties;
            // Attribute: name
            xmlChar *value = xmlNodeListGetString(a_node->doc, attribute->children, 1);
            cfg->name = (char *)malloc((strlen(value)) + 1);
            strcpy(cfg->name, (char *)value);
            xmlFree(value);
        }
    }
    printf("File name:: %s \n", cfg->name);
}

int getBoardDefinition(char *descriptionFileName, boardDefinition *bcfg)
{
    int ret = -1;

    xmlDoc *doc2 = NULL;
    xmlNode *root_element2 = NULL;

    /*parse the file and get the DOM */
    doc2 = xmlReadFile(descriptionFileName, NULL, 0);

    if (doc2 != NULL)
    {

        /*Get the root element node */
        root_element2 = xmlDocGetRootElement(doc2);

        getBoardComponents(root_element2, bcfg);

        /*free the document */
        xmlFreeDoc(doc2);

        /*
         *Free the global variables that may
         *have been allocated by the parser.
         */
        xmlCleanupParser();
    }
    else
    {
        ret = -1;
    }
    return (ret);
}

void getBoardComponents(xmlNode *a_node, boardDefinition *bcfg)
{
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node != NULL; cur_node = cur_node->next)
    {
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            if (strcmp((char *)cur_node->name, "board") == 0)
            {
                xmlAttr *attribute = a_node->properties;
                // Attribute: name
                xmlChar *name = xmlNodeListGetString(a_node->doc, attribute->children, 1);
                bcfg->container->name = (char *)malloc((strlen(name)) + 1);
                strcpy(bcfg->container->name, (char *)name);
                xmlFree(name);
                attribute = attribute->next;
                // Attribute: hsize
                xmlChar *hsize = xmlNodeListGetString(a_node->doc, attribute->children, 1);
                bcfg->container->hsize = atoi((char *)hsize);
                xmlFree(hsize);
            printf("Node: %s - hsize: %d\n", bcfg->container->name, bcfg->container->hsize);
            }
        }
        getBoardComponents(cur_node->children, bcfg);
    }
}
