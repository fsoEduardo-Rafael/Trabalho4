#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int num, n=0;
char * vistos[100];

char * remove_substring(char *string, int length){
    int i, j, k;
    char * new_string;
    new_string = malloc(sizeof(string));

    printf("Eita que o: %s\n", string);
    
    printf("%d\n", length);
    for(i=0 ; i<length ; i++){
    	new_string[i] = string[i];
    }

	printf("Olha aqui: %s\n", new_string);
	return new_string;
}

char *  print_directory_files(char *caminho, char *string, int length){
	DIR *d;
	struct dirent *dir;
	int i, check=0, j=0;

	printf("opaaaaa\n");
	d = opendir(caminho);
	if(d == NULL){
		printf("Nao era um diretorio\n");
		strcpy(caminho,remove_substring(caminho, length));
		return caminho;
	}else{
		printf("Entrou..\n");
		n++;
		while ((dir = readdir(d)) != NULL) {
			vistos[j] = malloc(sizeof(char*));
			strcpy(vistos[n-1], dir->d_name);
			printf("Entrou no while: %s\n", dir->d_name);
			check =0;
			for(i=0 ; i<n ; i++){
				if(strcmp(dir->d_name, vistos[i])==0 && n>1 || strcmp(dir->d_name, "..") == 0){
					check = 1;
					printf("checkado\n");
				}
			}
			if(check == 0){
				printf("Entrou no novo\n");
				if(strstr(dir->d_name, string)!=NULL){
					printf("%s\n", dir->d_name);
				}
				length = strlen(caminho);
				strcat(caminho, "/");
				strcat(caminho, dir->d_name);
				printf("Caminho: %s\n", caminho);
				printf("----------------------------------------\n");
				strcpy(caminho, print_directory_files(caminho, string, length));
				return print_directory_files(caminho, string, length);
				printf("--------------------2----------------------\n");
			}
			j++;
		}
		closedir(d);
	}
}