/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>



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
            cfg->name = (char *)malloc((strlen((char *)value)) + 1);
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
                getBoardContainerData(a_node, cur_node, bcfg);
            }
            if (strcmp((char *)cur_node->name, "button") == 0)
            {
                getButtonData(a_node, cur_node, bcfg);
            }
            if (strcmp((char *)cur_node->name, "led") == 0)
            {
                getLedData(a_node, cur_node, bcfg);
            }
        }
        getBoardComponents(cur_node->children, bcfg);
    }
}

void getBoardContainerData(xmlNode *root_node, xmlNode *board_node, boardDefinition *bcfg)
{

    xmlAttr *attribute = board_node->properties;
    // Attribute: name
    xmlChar *name = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->container.name = (char *)malloc((strlen((char *)name)) + 1);
    strcpy(bcfg->container.name, (char *)name);
    xmlFree(name);
    attribute = attribute->next;
    // Attribute: hsize
    xmlChar *hsize = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->container.hsize = atoi((char *)hsize);
    xmlFree(hsize);
    attribute = attribute->next;
    // Attribute: vsize
    xmlChar *vsize = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->container.vsize = atoi((char *)vsize);
    xmlFree(vsize);
}

void getButtonData(xmlNode *root_node, xmlNode *button_node, boardDefinition *bcfg)
{

    xmlAttr *attribute = button_node->properties;
    // Attribute: name
    xmlChar *name = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->btn.name = (char *)malloc((strlen((char *)name)) + 1);
    strcpy(bcfg->btn.name, (char *)name);
    xmlFree(name);
    attribute = attribute->next;
    // Attribute: hsize
    xmlChar *hsize = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->btn.hsize = atoi((char *)hsize);
    xmlFree(hsize);
    attribute = attribute->next;
    // Attribute: vsize
    xmlChar *vsize = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->btn.vsize = atoi((char *)vsize);
    xmlFree(vsize);
    attribute = attribute->next;
    // Attribute: start_status
    xmlChar *startStatus = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    if (strcmp((char *) startStatus, "on") == 0)
    {
        bcfg->btn.btnStatus = BTN_ON;
    }
    else
    {
        bcfg->btn.btnStatus = BTN_OFF;
    }
    xmlFree(startStatus);
}

void getLedData(xmlNode *root_node, xmlNode *led_node, boardDefinition *bcfg)
{

    xmlAttr *attribute = led_node->properties;
    // Attribute: name
    xmlChar *name = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->ld.name = (char *)malloc((strlen((char *)name)) + 1);
    strcpy(bcfg->ld.name, (char *)name);
    xmlFree(name);
    attribute = attribute->next;
    // Attribute: hsize
    xmlChar *hsize = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->ld.hsize = atoi((char *)hsize);
    xmlFree(hsize);
    attribute = attribute->next;
    // Attribute: vsize
    xmlChar *vsize = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    bcfg->ld.vsize = atoi((char *)vsize);
    xmlFree(vsize);
    attribute = attribute->next;
    // Attribute: start_status
    xmlChar *startStatus = xmlNodeListGetString(root_node->doc, attribute->children, 1);
    if (strcmp((char *) startStatus, "on") == 0)
    {
        bcfg->ld.ledStatus = LED_ON;
    }
    else
    {
        bcfg->ld.ledStatus = LED_OFF;
    }
    xmlFree(startStatus);
}

void renderBoard(boardDefinition *bcfg)
{

    WINDOW *my_win;
	int board_width, board_height;
	int ch;

	initscr();			/* Start curses mode 		*/
	cbreak();	 		/* Line buffering disabled, Pass on
				  	     * everty thing to me 		*/
	noecho();
    keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

	board_height = bcfg->container.vsize;
	board_width = bcfg->container.hsize;
	refresh();
	my_win = create_newwin(board_height, board_width, 0, 0);
	mvwprintw(my_win, 1, 1,"Press F12 to exit");
    WINDOW * button_win = create_newsubwin(my_win, bcfg->btn.vsize, bcfg->btn.hsize, 10, 1);
    mvwprintw(button_win, 1, 1, "Button 1");
    mvwprintw(button_win, 2, 1, "%d", bcfg->btn.btnStatus);
    WINDOW * led_win = create_newsubwin(my_win, bcfg->ld.vsize, bcfg->ld.hsize, 10, 1 + bcfg->btn.hsize);
    mvwprintw(led_win, 1, 1, "LED 1");
    mvwprintw(led_win, 2, 1, "%d", bcfg->ld.ledStatus);
    wrefresh(button_win);
    wrefresh(led_win);
    wrefresh(my_win);
	while((ch = getch()) != KEY_F(12))
	{	
	}
		
	endwin();			/* End curses mode		  */

}


WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

WINDOW *create_newsubwin(WINDOW * parent, int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = subwin(parent, height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}