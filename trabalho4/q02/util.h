#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ftw.h>

char *string_global;

int print_directory_files(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbufs){
	if(tflag == FTW_F){
		char * name;
		char * path;
		path = (char*)fpath;
		if(strstr(fpath, string_global)!=NULL){
			printf("%s\n", fpath);
		}
	}
	return 0;
}