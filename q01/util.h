#define _XOPEN_SOURCE 700
#define _BSD_SOURCE
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>

// int main(int argc, char *argv[])
// {
//   int b=1;
//   char backup[100];
//   char *source=getenv(argv[1]);
//   char *destination=getenv("BackupDestination");
//   char *btime=getenv("BackupTime");

//   time_t getTime;
//   struct tm *actualTime;

//    while(b)
//     {
//        //in each loop you get the time so it can be compared with the env variable
//        time(&getTime);
//        actualTime=localtime(&getTime);
//        strftime(backup, 100, "%H:%M", actualTime);

//        //no need for a while loop in a while loop
//        if(strcmp(backup,btime)==0)
//        {
//            system("cp -r $BackupSource $BackupDestination");
//        }
//        sleep(60);
//     }

// return 0;
// }