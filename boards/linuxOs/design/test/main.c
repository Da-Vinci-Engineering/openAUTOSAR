/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/
#include <stdio.h>
#include <form.h>
#include <ncurses.h>

#include "Port.h"

typedef struct _win_border_struct {
	chtype 	ls, rs, ts, bs, 
	 	tl, tr, bl, br;
}WIN_BORDER;

typedef struct _WIN_struct {

	int startx, starty;
	int height, width;
	WIN_BORDER border;
}WIN;

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
	int ch;

    if (argc != 2)
        return(1);

    int ret = getBoardDescriptionFileName(argv[1], &cfg);

    if (ret == 0)
    {
        ret = getBoardDefinition(cfg.name, &bcfg);
        printf("Node: %s - hsize: %d - vsize: %d\n", bcfg.container.name, bcfg.container.hsize, bcfg.container.vsize);
        printf("Node: %s - hsize: %d - vsize: %d - start_status: %d\n", bcfg.btn.name, bcfg.btn.hsize, bcfg.btn.vsize, bcfg.btn.btnStatus);
        printf("Node: %s - hsize: %d - vsize: %d - start_status: %d\n", bcfg.ld.name, bcfg.ld.hsize, bcfg.ld.vsize, bcfg.ld.ledStatus);
        printf("GPIO Connections: %d\n", bcfg.nPorts);
        printf("GPIO: 0 - pintype: %d, pinModeType: %d, pinDirectionType: %d\n",
                             bcfg.portCfgs[0].pinType, 
                             bcfg.portCfgs[0].pinModeType, 
                             bcfg.portCfgs[0].pinDirectionType 
                             );
        printf("GPIO: 1 - pintype: %d, pinModeType: %d, pinDirectionType: %d\n",
                             bcfg.portCfgs[1].pinType, 
                             bcfg.portCfgs[1].pinModeType, 
                             bcfg.portCfgs[1].pinDirectionType 
                             );
    }  

    renderBoard(&bcfg);

	while((ch = getch()) != KEY_F(12))
	{	
        toggleButtonStatus(&(bcfg.btn));
        toggleLedStatus(&(bcfg.ld));
        renderBoard(&bcfg);
	}
		
	endwin();			/* End curses mode		  */

    return 0;
}
