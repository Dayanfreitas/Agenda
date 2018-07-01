#include "interface.h"
#include "adicionar.h"

int main(){
	apontador();
	
}
void verificaFuncao(char x,int linha){
	Registro alunos[40];
	int escolha = 0;
	int id=0;
	int i;
	FILE *arquivo;
	char *nome_arquivo = "dados.bin";      
	int tamanho = 0;
	arquivo = fopen(nome_arquivo, "rb");
	
	if (arquivo != NULL) {
		fread(&tamanho, sizeof(int), 1, arquivo);
		fread(alunos, sizeof(Registro), 40, arquivo);
		fclose(arquivo);
	}else{
		puts("Sem arquivo!");
	  }
	if (x == 13)/*enter*/
	{
		if(linha == 3)
		{
			/*opção 1*/
			gotoxy(40,3);
			printf("_-_-CADASTRA_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
			gotoxy(40,6);
			printf ("Informe seu iD: ");
            scanf ("%d", &id); 
			registerContact(alunos, id);
		}else if(linha == 5)
		{
			char op;
			/*opção 2*/
			gotoxy(40,3);
			printf("_-_-PESQUISA_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
			gotoxy(40,6);
			printf("[1]-   ID");
			gotoxy(40,7);
			printf("[2]- NOME");
			gotoxy(40,9);
			printf("Pesquisar como:");
			op = getch();
			switch(op){
				case '1':
					gotoxy(40,11);
					/*chama a funçõa*/
					printf ("Informe seu iD: ");
          			scanf ("%d", &id); 
					searchById(alunos, id);
					getch();
					break;
				case '2':
					gotoxy(40,11);
					/*chama a funçõa*/
					searchByName(alunos);
					getch();
					break;
				default:
					gotoxy(40,11);
					printf("Invalido!!");
					getch();
					break;
			}
		}else if(linha == 7)
		{
			/*opção 3*/
			gotoxy(40,3);
			printf("_-_-EXCLUIR_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
			gotoxy(40,6);
			printf ("Informe seu iD: ");
            scanf ("%d", &id); 
   		   	deleteContact(alunos,id);
   		    tamanho--;
		}else if(linha == 9)
		{
			/*opção 4*/
			gotoxy(40,3);
			printf("_-_-EDITAR_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
			gotoxy(40,6);
			printf ("Informe seu iD: ");
            scanf ("%d", &id);
			editContact(alunos, id);
		}else if (linha == 11)
		{
			/*opção 5*/
			gotoxy(40,3);
			printf("_-_-LISTAR TODOS_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
			showAll(alunos);
	
		}else if(linha == 13)
		{
			gotoxy(40,3);
			printf("_-_-SAIR_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");	
			exit(1);
		}
		arquivo = fopen(nome_arquivo, "wb");
	    fwrite(&tamanho, sizeof(int), 1, arquivo);
		fwrite(alunos, sizeof(Registro), 40, arquivo);
		fclose(arquivo);
	}
} 

