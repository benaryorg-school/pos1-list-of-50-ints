#ifndef HEADER_H
#define HEADER_H

#include "config.h"

#define error(format, ...) fprintf(stderr, (format), ##__VA_ARGS__)

#if HAS_LOGGING
#define log(format,...) fprintf(stderr, (format), ##__VA_ARGS__)
#else
#define log(...) 0
#endif // HAS_LOGGING

// logging //
#define FSTART log("start function(%s())\n",__func__)
#define FEND log("end function(%s())\n",__func__)

// menu options //
typedef enum menu
{
    INVALID=-1,
    ADD_VALUE,
    DEL_ALL,
    PRINT_ORIGINAL,
    PRINT_ASCENDING,
    PRINT_MODAL,
    PRINT_MEDIAN,
    PRINT_MEAN,
    PRINT_SPAN,
    PRINT_HELP,
    EXIT,
} menu_t;

// list manipulation //

// count a lists elements //
int list_count(int **);
// sort the list //
void list_sort(int **);
// copies the list //
int **list_copy(int **);
// add element to list //
int list_add(int **,int);

// read a value from stdin //
int read_value(int *);
// read a menu value from stdin //
menu_t menu(void);
// print the help menu to stdout //
void print_help(void);


#endif // HEADER_H
