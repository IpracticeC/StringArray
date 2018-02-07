#pragma once
#include <errno.h>
typedef struct stringArray_t *StringArray;
typedef int errno_t;
StringArray NewStringArray(void);
void DeleteStringArray(StringArray);
errno_t AddStringArrayItem(StringArray, const char*);
char * GetStringArrayItem(StringArray, const unsigned int);
unsigned int GetStringArraySize(StringArray);
unsigned int GetStringArrayMemSpaceSize(StringArray);
errno_t RemoveStringArrayItem(StringArray, const unsigned int);
