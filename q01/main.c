#include "util.h"

struct Infos{
	char *name_file;
	char ano[5];
	char mes[3];
	char dia[3];
	char tempo[6];
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

	for(i=8 ; i<12 ; i++){
		infos.tempo[i-8] = data[i];
	}
	infos.tempo[12-8] = '\0';
}

void print_infos(const struct stat sb){
	printf("Data de criacao: %s\n", ctime(&sb.st_ctime));
	printf("Ultimo acesso: %s\n", ctime(&sb.st_atime));
	printf("Ultima modificacao: %s\n", ctime(&sb.st_mtime));
}

void changing_infos(){
	struct utimbuf utb;
	const struct stat new;
	printf("Olha: %d", (int) infos.tempo);
	utb.actime = (int) infos.tempo;
	utb.modtime = (int) infos.tempo;

	if(utime(infos.name_file, &utb) == -1){
		printf("utime");
	}
	stat(infos.name_file, &new);
	print_infos(new);
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
	printf("Hora: %s\n", infos.tempo);
	
	printf("Testando:\n");
	stat(infos.name_file, &sb);
	printf("opa..\n");
	print_infos(sb);

	printf("---------------------------\n\n");

	printf("AGORA VAIII:\n\n");
	changing_infos();
	return 0;
}