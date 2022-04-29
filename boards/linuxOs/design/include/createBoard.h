/********************************************************************
* (C) DaVinci Engineering GmbH 2022
********************************************************************/
#ifndef CREATEBOARD_H_
#define CREATEBOARD_H_

xmlTextReaderPtr openConfigFile(char * fileName);
int processConfigDoc(xmlTextReaderPtr readerPtr);

typedef struct _configFileData
{
    char * name;
} configFileData;

#endif // CREATEBOARD_H_