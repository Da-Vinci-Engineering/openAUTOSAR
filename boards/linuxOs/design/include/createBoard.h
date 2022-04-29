/********************************************************************
* (C) DaVinci Engineering GmbH 2022
********************************************************************/
#ifndef CREATEBOARD_H_
#define CREATEBOARD_H_

void
print_element_names(xmlNode * a_node);

typedef struct _configFileData
{
    char * name;
} configFileData;

#endif // CREATEBOARD_H_