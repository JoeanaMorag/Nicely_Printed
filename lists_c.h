#include "linked_list.h"
#define FAILURE 1
#define SUCCESS 0

/*==============================================
this function check the command line from the terminal
it gets the number of arguments that was in the command line
return SUCCESS if the command line contains the program name and one file name
returns FAILURE for any other command line (with more or less file names)
===============================================*/
int command_check(int argc);

/*==============================================
this function read the text from the file given in the command line
gets a list type in which to store the text, and the file name
return FAILURE if the file fail to oppen, and SUCCESS otherways
===============================================*/
int read_file(list* main_list, char* file_name);
