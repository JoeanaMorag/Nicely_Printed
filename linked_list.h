#define ARRAY_SIZE 50

/*==============================================
define the node structure of the linked list
===============================================*/
typedef struct _node
{
	char data[ARRAY_SIZE];
	struct _node* next;
} node;

/*===============================================
define the linked list structure
===============================================*/
typedef struct _list
{
	node* head;
	node* tail;
} list;

/*==============================================
this function initiate the list head and tail to null
it gets a pointer to the list which needs to be initiate
===============================================*/
void init(list* main_list);

/*==============================================
this function add a new node to the linked list
it gets a pointer to the list to which it needs to add a node, and a data array which needs to fill the data field in the node
===============================================*/
void add_node(list* main_list, char data[]);

/*==============================================
this function prints the whole data fields linked list
it gets a pointer to the list it needs to print
===============================================*/
void print_list(list* main_list);

/*==============================================
this function delete the linked list and free the memory allocation
it gets a pinter to the list it needs to delete
===============================================*/
void terminate(list* main_list);
