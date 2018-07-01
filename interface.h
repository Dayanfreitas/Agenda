#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
void aviso();
void gotoxy(int x, int y);
void fundo();
void opcoes();
void verificaFuncao(char x,int linha);
void apontador();
void apontador(){
	char op;
	int xDoApontador=12;
	int yDoApontador=3;
	aviso();
	do{
		system("cls");
		fundo();
		opcoes();
		gotoxy(xDoApontador,yDoApontador);
		printf(">");
		op=getch();

	
		if ((op == 's'|| op == 'S')  && (yDoApontador <=12)){
			yDoApontador = yDoApontador+2;
		}else if((op == 'w' || op == 'W') && (yDoApontador >3)){
			yDoApontador = yDoApontador-2;
		}
		verificaFuncao(op,yDoApontador);
	}while(1);
}

void fundo(){
	printf("\n");
	printf("\t");
	
	for (int COLUNA = 0;COLUNA<20;COLUNA++){
		for(int LINHA= 0; LINHA<90;LINHA++){
			printf("%c",176);
		}
		printf("\n");
		printf("\t");
	}

}
void opcoes(){
	int xDasOpcoes=14;
	int yDasOpcoes=3;
	gotoxy(xDasOpcoes,yDasOpcoes);
	printf("Criar Contato");
	gotoxy(xDasOpcoes,yDasOpcoes+2);
	printf("Procurar Contato");
	gotoxy(xDasOpcoes,yDasOpcoes+4);
	printf("Excluir Contato");
	gotoxy(xDasOpcoes,yDasOpcoes+6);
	printf("Editar Contato");
	gotoxy(xDasOpcoes,yDasOpcoes+8);
	printf("Listar Todos");
	gotoxy(xDasOpcoes,yDasOpcoes+10);
	printf("Sair e Salvar");
}
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void aviso(){
	printf("\t  /*AVISOS*/\n");
	printf("\t/*IMPORTANTES*/\n");
	printf("Para navegar no menu use:\n\n");
	printf("[w]-Para ir para       cima\n");
	printf("[s]-Para ir para      baixo\n");
	printf("[enter]-Para entra na opção\n");
	printf("\n");
	printf("Para salvar e sair,deve sair pela opção do programa!\n\n");
	printf("\t\t/*Desenvolvido por Rafael Matsumoto e Dayan Freitas\n\t\tAlunos da primeira fase de Engenharia de Software pela PUC*/");
	getch();
}
