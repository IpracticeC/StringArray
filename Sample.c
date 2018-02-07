]#include <stdio.h>
#include <errno.h>
#include "stringArray.h"


int main(void){
	unsigned int i;
	StringArray array;
	char buff[4];
	array=NewStringArray();
	if(array==NULL)
		return 0;
	for(i=0;i<200;i++){
		sprintf(buff,"%d",i);
		AddStringArrayItem(array,buff);
	}
	for(i=0;i<GetStringArraySize(array);i++){
		printf("%s\n",GetStringArrayItem(array,i));
	}
	DeleteStringArray(array);
	return 0;
}
