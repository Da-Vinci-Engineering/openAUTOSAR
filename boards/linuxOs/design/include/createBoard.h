/********************************************************************
* (C) DaVinci Engineering GmbH 2022
********************************************************************/
#ifndef CREATEBOARD_H_
#define CREATEBOARD_H_

#include "Port.h"

enum buttonStatus
{
    BTN_OFF,
    BTN_ON
};

enum ledStatus
{
    LED_OFF,
    LED_ON
};

/**
 * @brief Structure containing the file name for the definition of the board
 */
typedef struct _configFileData
{
    char * name;
} configFileData;

/**
 * @brief Structure containing board data
 */
typedef struct _board
{
    char * name;
    int hsize;
    int vsize;
} board;

/**
 * @brief Structure containing button data
 */
typedef struct _button
{
    char * name;
    int hsize;
    int vsize;
    char * label;
    enum buttonStatus btnStatus;
} button;

/**
 * @brief Structure containing button data
 */
typedef struct _led
{
    char * name;
    int hsize;
    int vsize;
    enum ledStatus ledStatus;
} led;


/**
 * @brief Structure containing the whole definition of the board
 */
typedef struct _boardDefinition
{
    board container;
    button btn;
    led ld;
    uint32_t nPorts;
    Port_ConfigType *portCfgs;
} boardDefinition;

/**
 * @brief Changes the status of a button
 */
void toggleButtonStatus(button * btn);

/**
 * @brief Changes the status of an LED
 */
void toggleLedStatus(led * led);


/**
 * @brief Reads the config file and fills the structure with the file name
 * @param filename configuration fie name
 * @param cfg pointer to the structure to be filled with data
 * @return 0 = success -1 = failure
 */
int getBoardDescriptionFileName(char * fileName, configFileData * cfg);

/**
 * @brief Reads the the file name from the XML config file
 * @param node containing the name
 * @param cfg pointer to the structure filled with data
 */
void getFileNameFromDescriptionFile(xmlNode *a_node, configFileData *cfg);

/**
 * @brief Reads the board definition file ile and fills the structure
 * @param cfg pointer to the structure filled with data
 * @return 0 = success -1 = failure
 */
int getBoardDefinition(char * descriptionFileName, boardDefinition * bcfg);

/**
 * @brief Reads the the components from the definition file
 * @param node containing the board name
 * @param bcfg pointer to the structure to be filled with data
 */
void getBoardComponents(xmlNode *a_node, boardDefinition *bcfg);

/**
 * @brief Reads the the board main data from the definition file
 * @param root_node pointer to node with the board name
 * @param board_node pointer to current node for the board
 * @param bcfg pointer to the structure to be filled with data
 */
void getBoardContainerData(xmlNode *root_node, xmlNode *board_node, boardDefinition *bcfg);

/**
 * @brief Reads the the board main data from the definition file
 * @param root_node pointer to node with the board name
 * @param board_node pointer to current node for the board
 * @param bcfg pointer to the structure to be filled with data
 */
void getButtonData(xmlNode *root_node, xmlNode *board_node, boardDefinition *bcfg);

/**
 * @brief Reads the the board main data from the definition file
 * @param root_node pointer to node with the board name
 * @param board_node pointer to current node for the board
 * @param bcfg pointer to the structure to be filled with data
 */
void getLedData(xmlNode *root_node, xmlNode *board_node, boardDefinition *bcfg);

/**
 * @brief Reads the the gpio ports data from the definition file
 * @param root_node pointer to node with the board name
 * @param connections_node pointer to current node for the board
 * @param bcfg pointer to the structure to be filled with data
 */
void getNPorts(xmlNode *root_node, xmlNode *connections_node, boardDefinition *bcfg);

void getGPIO(xmlNode *root_node, xmlNode *gpio_node, boardDefinition *bcfg, uint32_t *gpios_configured);

/**
 * @brief creates a grphical rendering of the board
 * @param bcfg pointer to the structure to be rendered
 */
void renderBoard(boardDefinition *bcfg);

WINDOW *create_newwin(int height, int width, int starty, int startx);
WINDOW *create_newsubwin(WINDOW *parent, int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);



#endif // CREATEBOARD_H_