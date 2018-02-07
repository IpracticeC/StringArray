#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "stringArray.h"

struct stringArray_t {
	unsigned int size;
	unsigned int memSpaceSize;
	char **str;
};
StringArray NewStringArray(void) {
	StringArray array = (StringArray)malloc(sizeof(struct stringArray_t));//important
	if (array == NULL)
		return NULL;
	array->str = (char **)malloc(sizeof(char *));
	if (array->str == NULL) {
		free(array);
		return NULL;
	}
	array->size = 0;
	array->memSpaceSize = 1;
	return array;
}

void DeleteStringArray(StringArray array) {
	unsigned int i = 0;
	for (i = 0; i < array->size; i++) {
		free(array->str[i]);
	}
	free(array->str);
	free(array);
}

int AddStringArrayItem(StringArray array, const char *str) {
	unsigned int memSpaceSize;
	int length;
	char *newStr;
	if (array->memSpaceSize > array->size)
		memSpaceSize = 0;
	else if (array->memSpaceSize < UINT_MAX / 2)
		memSpaceSize = array->memSpaceSize + array->memSpaceSize;
	else if (array->memSpaceSize < UINT_MAX)
		memSpaceSize = UINT_MAX;
	else
		return EINVAL;
	if (memSpaceSize > 0) {
		char **temp;
		temp = (char **)realloc(array->str, sizeof(char *)*memSpaceSize);
		if (temp == NULL)
			return ENOMEM;
		array->str = temp;
		array->memSpaceSize = memSpaceSize;
	}

	length = strlen(str);
	newStr = (char *)calloc(length+1,sizeof(char));
	if (newStr == NULL)
		return ENOMEM;
	memcpy(newStr, str, length + 1);
	array->str[array->size] = newStr;
	array->size++;
	return 0;
}

char * GetStringArrayItem(StringArray array, const unsigned int index) {
	if (index >= array->size)
		return NULL;
	else
		return array->str[index];
}

unsigned int GetStringArraySize(StringArray array) {
	return array->size;
}

unsigned int GetStringArrayMemSpaceSize(StringArray array) {
	return array->memSpaceSize;
}
int RemoveStringArrayItem(StringArray array, const unsigned int index) {
	if (index >= array->size)
		return EINVAL;
	free(array->str[index]);
	memmove(array->str+index, array->str+index+1, sizeof(char *)*(array->size -index));
	array->size--;
	return 0;
}



