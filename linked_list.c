#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"

void init(list* main_list)
{
	main_list->head = NULL;
	main_list->tail = NULL;
}

void add_node(list* main_list, char data[])
{
	node* ptr;
	
	/*create node*/
	ptr = (node*)malloc(sizeof(node));
	if(!ptr)
	{
		printf("memory allocation failed");
		return;
	}
	
	memcpy(ptr->data,data,ARRAY_SIZE);
	ptr->next = NULL;
	
	/*place node*/
	if(main_list->head == NULL)
	{
		main_list->head = ptr;
		main_list->tail = ptr;	
	}
	else
	{
		main_list->tail->next = ptr;
		main_list->tail = ptr;
	}
}

void print_list(list* main_list)
{
	node* ptr;
	ptr = main_list->head;
	while(ptr != NULL)
	{
		if(ptr == main_list->tail)
			printf("%s", ptr->data);
		else
			printf("%.*s", ARRAY_SIZE, ptr->data);
			
		ptr = ptr->next;
	}
}

void terminate(list* main_list)
{
	node* ptr;
	node* head_ptr;
	head_ptr = main_list->head;
	
	while(head_ptr)
	{
		ptr = head_ptr;
		head_ptr = head_ptr->next;
		free(ptr);
	}
	
}
