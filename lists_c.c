#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists_c.h"

/*==============================================
this program read an unkown amount of text from a given text file
and prints it in a fine presentation to the screen
the main function gets the file name from the terminal
===============================================*/
int main(int argc, char* argv[])
{
	char * file_name;
	list new_list;
	
	if((command_check(argc)) == FAILURE)
		exit(0);
	
	file_name = argv[1];
	
	if((read_file(&new_list,file_name)) == FAILURE)
		exit(0);
	
	print_list(&new_list);
	terminate(&new_list);

	return 0;
}

int command_check(int argc)
{
	if(argc == 1)
	{
		printf("missing file name\n");
		return FAILURE;
	}
	else if(argc != 2)
	{
		printf("enter one file name only\n");
		return FAILURE;
	}
	else
		return SUCCESS;
}

/*==============================================
this function copy the text from the the text file in to an array
it gets a pointer to the file, and an array to fill
===============================================*/
void get_string(FILE* fd, char data[])
{
	int i;
	memset(data,'\0',ARRAY_SIZE);
	for(i = 0; i < ARRAY_SIZE; i++)
	{
		if(feof(fd))
			break;
		fscanf(fd,"%c",&data[i]);
	}
}

int read_file(list* main_list, char* file_name)
{
	FILE* fd;
	char data[ARRAY_SIZE];
	
	if(!(fd = fopen(file_name,"r+")))
	{
		fprintf(stderr,"cannot open file\n");
		return FAILURE;
	}
	
	init(main_list);
	
	while(!feof(fd))
	{
		get_string(fd, data);
		add_node(main_list, data);
	}
	
	fclose(fd);
	return SUCCESS;

}
