#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128

char prompt[] = "> ";
char delimiters[] = " \t\r\n";
extern char **environ;



int main() {
    // Stores the string typed into the command line.
    char command_line[MAX_COMMAND_LINE_LEN];
    char cmd_bak[MAX_COMMAND_LINE_LEN];
  
    // Stores the tokenized command line input.
    char *arguments[MAX_COMMAND_LINE_ARGS];
    	
    while (true) {
      
        do{ 
            // Print the shell prompt.
            printf("%s", prompt);
            fflush(stdout);

            // Read input from stdin and store it in command_line. If there's an
            // error, exit immediately. (If you want to learn more about this line,
            // you can Google "man fgets")
        
            if ((fgets(command_line, MAX_COMMAND_LINE_LEN, stdin) == NULL) && ferror(stdin)) {
                fprintf(stderr, "fgets error");
                exit(0);
            }
 
        }while(command_line[0] == 0x0A);  // while just ENTER pressed

      
        // If the user input was EOF (ctrl+d), exit the shell.
        if (feof(stdin)) {
            printf("\n");
            fflush(stdout);
            fflush(stderr);
            return 0;
        }

        // TODO:
        // 
        
			  // 0. Modify the prompt to print the current working directory
			  void print_prompt() {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
          printf("[%s]$ ", cwd);
          fflush(stdout);
        } else {
          perror("getcwd() error");
          exit(EXIT_FAILURE);
        }
    }
        // 1. Tokenize the command line input (split it on whitespace)
      char *token = strtok(command_line, delimiters);
      int token_counter = 0;

        while (token != NULL && token_counter < MAX_COMMAND_LINE_ARGS - 1) {
          arguments[token_count] = token;
          token = strtok(NULL, delimiters);
          token_counter++;
        }
        arguments[token_counter] = NULL;
      
        // 2. Implement Built-In Commands
         if (strcmp(arguments[0], "exit") == 0) {
            return 0; 
        }
    
        // 3. Create a child process which will execute the command line input
      pid_t  pid = fork()
  
        // 4. The parent process should wait for the child to complete unless its a background process
       if (pid < 0) {
            perror("Error creating process!");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execvp(arguments[0], arguments);
            perror("execvp error");
            exit(1);
        } else {
            // Parent process
            int status;
            if (arguments[token_count - 1][0] != '&') {
                waitpid(pid, &status, 0); // Wait for child if not a background process
            }
        }
    }
