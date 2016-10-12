#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void print_directory_files(char *caminho, char *string){
	DIR *d;
	struct dirent *dir;
	d = opendir(caminho);
	if (d){
		while ((dir = readdir(d)) != NULL) {
		  if(strstr(dir->d_name, string)!=NULL){
		  	printf("%s\n", dir->d_name);
		  }
		}
		closedir(d);
	}
}