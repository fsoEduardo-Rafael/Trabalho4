#define _BSD_SOURCE
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


struct Infos{
	char *name_file;
	char ano[5];
	char mes[3];
	char dia[3];
	char hora[3];
	char minuto[3];
};

struct Infos infos;

void set_infos(char * name, char * data){
	int i;
	//printf("chegou aqui\n");

	infos.name_file = name;
	//printf("chegou aqui\n");
	for(i=0 ; i<4 ; i++){
		infos.ano[i] = data[i];
	}
	printf("chegou aqui\n");
	infos.ano[4] = '\0';

	for(i=4 ; i<6 ; i++){
		infos.mes[i-4] = data[i];
	}	
	infos.mes[6-4] = '\0';
	for(i=6 ; i<8 ; i++){
		infos.dia[i-6] = data[i];
	}
	infos.dia[8-6] = '\0';

	for(i=8 ; i<10 ; i++){
		infos.hora[i-8] = data[i];
	}
	infos.hora[10-8] = '\0';

	for(i=10 ; i<12 ; i++){
		infos.minuto[i-10] = data[i];
	}
	infos.minuto[12-10] = '\0';
}

void print_infos(const struct stat *sb){
	printf("Data de criacao: %s\n", ctime(&sb->st_ctime));
	printf("Ultimo acesso: %s\n", ctime(&sb->st_atime));
	printf("Ultima modificacao: %s\n", ctime(&sb->st_mtime));
}

int main(int argc, char *argv[]){
	char *name_file = (char*)argv[1];
	char *data = (char*)argv[2];
	struct stat sb;
	int i;

	if((strlen(data) != 12) || argc != 3){//Conferindo entradas..
		printf("Entrada invalida!");
	}

	set_infos(name_file, data);

	printf("Nome: %s\n", infos.name_file);
	printf("Data: %s\n", data);
	printf("Ano: %s\n", infos.ano);
	printf("Mes: %s\n", infos.mes);
	printf("Dia: %s\n", infos.dia);
	printf("Hora: %s\n", infos.hora);
	printf("Minuto: %s\n", infos.minuto);
	
	printf("Testando:\n");
	lstat(infos.name_file, &sb);
	printf("opa..\n");
	print_infos(&sb);

	return 0;
}