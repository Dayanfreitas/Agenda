#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char telephone[14];
	char name[50];
	int age;
} Registro;

void registerContact(Registro student[], int position) {
     if (student[position].age == 0){         
        system("cls"); 
    
    	printf("Entre o nome do contato: ");
    	scanf("%s", student[position].name);
    	
        do {
        	printf("Entre a idade do contato: ");
        	scanf("%d", &student[position].age);
        } while (student[position].age == 0); 
    	
    	printf("Entre o telefone do contato: ");
    	scanf("%s", student[position].telephone);
     }
     else {
          system("cls"); 
          printf ("Aluno ja cadastrado\n");
          system("pause");
     }
	
	
}

void editContact(Registro student[], int position) {
    system("cls"); 

	printf("Entre o nome do contato: ");
	scanf("%s", student[position].name);
	
    do {
    	printf("Entre a idade do contato: ");
    	scanf("%d", &student[position].age);
    } while (student[position].age == 0); 
	
	printf("Entre o telefone do contato: ");
	scanf("%s", student[position].telephone);
	
	
}

void searchById(Registro student[], int position) {
    system("cls");
    if (student[position].age != 0){
        printf("Contatos %d\n", position);
    	printf("ID\tNome\tIdade\tTelefone\n");
    	printf("%d\t%s\t%d\t%s\n", position, student[position].name, student[position].age, student[position].telephone);
    	system("pause");
    }
    else {
         printf ("Aluno nao cadastrado\n");
         system("pause");
    }
}

void searchByName(Registro student[]){
     int i;
     char title[50];     
     printf ("Informe o nome: ");
     scanf ("%s", title);
     system("cls");
     for (i = 0; i <= 39; i++){
         if (strcmp(title, student[i].name) == 0){
            printf ("Contatos\n");
            printf("ID\tNome\tIdade\tTelefone\n");
    	    printf("%d\t%s\t%d\t%s\n", i, student[i].name, student[i].age, student[i].telephone);            
         }     
     } 
     system("pause");
}

void showAll(Registro student[]) {
    system("cls");
    int i;
	printf("Contatos\n");
	printf("ID\tNome\tIdade\tTelefone\n");
	for (i = 0; i < 40; i++){
        if (student[i].age != 0){
	       printf("%d\t%s\t%d\t%s\n", i, student[i].name, student[i].age, student[i].telephone);
        }
     }
	system("pause");
}

void deleteContact(Registro student[],int position){
    system("cls");
   
     student[position].age = 0;
     
     memset(&student[position].name, 0, sizeof(student[position].name));
     
     memset(&student[position].telephone, 0, sizeof(student[position].telephone));

}
