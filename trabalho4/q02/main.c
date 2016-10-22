#include "util.h"

int main(int argc, char * argv[]){
	char *caminho;
	char *string_part;
	int num_lines;

	if(argc != 4){
		printf("Modo de uso: <caminho> <string> <numero_de_saidas>");
		exit(1);
	}

	caminho = malloc(sizeof(char*));
	string_part = malloc(sizeof(char*));

	caminho = argv[1];
	string_part = argv[2];
	num_lines = atoi(argv[3]);
	string_global = argv[2];
	printf("Caminho: %s\n", caminho);
	printf("String: %s\n", string_part);
	printf("Num: %d\n", num_lines);
	//print_directory_files(caminho, string_part);
	if (nftw(caminho, print_directory_files, num_lines, FTW_DEPTH)
            == -1) {
        perror("nftw");
        exit(EXIT_FAILURE);
    }
	return 0;
}