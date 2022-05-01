/********************************************************************
* (C) DaVinci Engineering GmbH 2022
********************************************************************/
#ifndef CREATEBOARD_H_
#define CREATEBOARD_H_

/**
 * @brief Structure containing the file name for the definition of the board
 */
typedef struct _configFileData
{
    char * name;
} configFileData;

/**
 * @brief Structure containing the name of the board
 */
typedef struct _board
{
    char * name;
    int hsize;
    int vsize;
} board;

/**
 * @brief Structure containing the whole definition of the board
 */
typedef struct _boardDefinition
{
    board * container;
} boardDefinition;

/**
 * @brief Reads the config file and fills the structure with the file name
 * @param filename configuration fie name
 * @param cfg pointer to the structure to be filled with data
 * @return 0 = success -1 = failure
 */
int getBoardDescriptionFileName(char * fileName, configFileData * cfg);

/**
 * @brief Reads the the file name from the XML config file
 * @param node contatining the name
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
 * @param node contatining the board name
 * @param bcfg pointer to the structure to be filled with data
 */
void getBoardComponents(xmlNode *a_node, boardDefinition *bcfg);

#endif // CREATEBOARD_H_