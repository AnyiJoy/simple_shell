#ifndef SIMPLE-SHELL_H_
#define SIMPLE-SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

/*const*/
#define CMD_TYPE_EXTERNAL 1
#define CMD_TYPE_INTERNAL 2
#define CMD_TYPE_PATH 3
#define CMD_TYPE_INVALID -1

#define MIN(x, y) ((x) < (y) ? (x) : (y))

/**
 *struct map - This is a struct that maps a command name to a function 
 *
 *@cmd_name: This is the name of the command
 *@func: This is the function that executes the command
 */

  typedef struct {
    char *cmd_name;
    void (*func)(char **cmd);
} FunctionMap;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

void print(char *, int);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);

int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int);
void remove_comment(char *);

int parse_cmd(char *);
void execute_cmd(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

void env(char **);
void quit(char **);

extern void non_interactive(void);
extern void initializer(char **current_cmd, int type_cmd);

#endif /*SIMPLE-SHELL_H_*/
