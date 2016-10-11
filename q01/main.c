#include "util.h"

int main(int argc, char *argv[]){
	char *name_file = (char*)argv[1];
	char *data = (char*)argv[2];
	struct stat sb;
	int i;

	if((strlen(data) != 12) || argc != 3){//Conferindo entradas..
		printf("Entrada invalida!");
	}

	set_infos(name_file, data);
	
	stat(infos.name_file, &sb);
	printf("Informacoes anteriores:\n");
	print_infos(sb);

	printf("---------------------------\n\n");

	printf("Alterando inforamcoes..\n\n");
	changing_infos();
	return 0;
}