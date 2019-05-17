//defines used to determine the OS this is getting compiled on --used in sysinfo and other OS-specific commands
#if defined(_WIN32) || defined(WIN32)
#define OS 0
#endif

#ifdef __unix__
#define OS 1
#endif

#include <stdio.h>
#include <stdlib.h>

#define DIM 1000
#define CDIM 100

int main(){
  char curDir[DIM+1];                                                                        //declare current directory string
  char shInput[CDIM+1];                                                                       //declare input command string
  while(1) {                                                                                 //endless cycle that asks for and executes commands
    fscanf(popen("pwd", "r"), "%s", curDir);                                                 //uses pwd output in pipe to be put in curDir
    printf("%s $ ", curDir);                                                                 //prints shell prompt
    scanf("%s", shInput);                                                                    //asks for commands --Here's where the fun stuff happens
    if (!strcmp(shInput, "sysinfo") && OS) system("uname -a");                               //sysinfo command linux ver --Tells info about the system
    else if (!strcmp(shInput, "sysinfo") && !OS) system("ver");                              //sysinfo command windows ver --Same as above but for Window$
    else if (!strcmp(shInput, "ls")) printf("Aresu\tLai\tCauli\tComputer\n");                //fake ls that tells about the people behind this
    else if (!strcmp(shInput, "help")) printf("ITIS Scano's unofficial fake shell!\n");      //fake help command that tells about this program's clandestine status!
    else if (!strcmp(shInput, "exit")) {                                                     //exit command --terminates program
      printf("Logging out...\n");
      exit(-1);                                                                              //termination
    }
    else printf("Illegal command\n");                                                        //this gets printed if the command doesn't exist --this is quite ironic
  }
  return 0;
}
