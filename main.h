#ifndef _PRINTF
#define _PRINTF

#include <unistd.h>
#include <stdlib.h>

typedef unsigned int u_int;

/* Define functions prototypes */
int _printf(const char *format, ...);
char *_strcat(char *dest, char *src);
u_int _strlen(char *str);
char *_itoa(int num);
char *_strrev(char *str);
#endif /* _PRINTF */
