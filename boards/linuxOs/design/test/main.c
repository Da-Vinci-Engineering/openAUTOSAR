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
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    xmlDoc *doc2 = NULL;
    xmlNode *root_element2 = NULL;

    if (argc != 3)
        return(1);

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    /*parse the file and get the DOM */
    doc = xmlReadFile(argv[1], NULL, 0);

    if (doc == NULL) {
        printf("error: could not parse file %s\n", argv[1]);
    }

    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);

    print_element_names(root_element);

    /*free the document */
    xmlFreeDoc(doc);

    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    //xmlCleanupParser();

    /*parse the file and get the DOM */
    doc2 = xmlReadFile(argv[2], NULL, 0);

    if (doc2 == NULL) {
        printf("error: could not parse file %s\n", argv[2]);
    }
        printf("Parsed file %s\n", argv[2]);

    /*Get the root element node */
    root_element2 = xmlDocGetRootElement(doc2);

    print_element_names(root_element2);

    /*free the document */
    xmlFreeDoc(doc2);

    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    xmlCleanupParser();


    return 0;
}
