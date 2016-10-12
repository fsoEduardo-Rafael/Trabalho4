#include "util.h"

int main(int argc, char *argv[]){
	char *name_file = (char*)argv[1];
	char *data = (char*)argv[2];
	struct stat sb;
	char new_name[24];
	int i;

	if((strlen(data) != 12) || argc != 3){//Conferindo entradas..
		printf("Entrada invalida!");
	}

	set_infos(name_file, data);
	
	strcpy(new_name, generate_bkp(name_file));

	stat(infos.name_file, &sb);
	printf("Informacoes anteriores:\n");
	print_infos(sb);

	printf("---------------------------\n\n");

	printf("Alterando inforamcoes..\n\n");
	changing_infos(infos.name_file);

	printf("\n--------------------------------\nInformacoes bkp:\n");

	changing_infos_bkp(new_name, sb);
	printf("Voltou disso");

	return 0;
}