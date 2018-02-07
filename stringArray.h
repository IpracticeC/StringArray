#pragma once
#include <errno.h>
typedef struct stringArray_t *StringArray;
StringArray NewStringArray(void);
void DeleteStringArray(StringArray);
int AddStringArrayItem(StringArray, const char*);
char * GetStringArrayItem(StringArray, const unsigned int);
unsigned int GetStringArraySize(StringArray);
unsigned int GetStringArrayMemSpaceSize(StringArray);
int RemoveStringArrayItem(StringArray, const unsigned int);
