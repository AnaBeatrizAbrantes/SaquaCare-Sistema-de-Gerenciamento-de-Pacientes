//adicionei o arquivo de menu e etc para rodar tudo aqui 
#include <stdio.h>
#include <hospital.h>
#include "hospital.h"

int main(){
   int menu; 

   do {
        printf("\n.--------------------------------------------------------------------------------------------------------------------------------------.
|   ad88888ba         db         ,ad8888ba,    88        88        db         ,ad8888ba,         db         88888888ba   88888888888   |
|  d8"     "8b       d88b       d8"'    `"8b   88        88       d88b       d8"'    `"8b       d88b        88      "8b  88            |
|  Y8,              d8'`8b     d8'        `8b  88        88      d8'`8b     d8'                d8'`8b       88      ,8P  88            |
|  `Y8aaaaa,       d8'  `8b    88          88  88        88     d8'  `8b    88                d8'  `8b      88aaaaaa8P'  88aaaaa       |
|    `"""""8b,    d8YaaaaY8b   88          88  88        88    d8YaaaaY8b   88               d8YaaaaY8b     88""""88'    88"""""       |
|          `8b   d8""""""""8b  Y8,    "88,,8P  88        88   d8""""""""8b  Y8,             d8""""""""8b    88    `8b    88            |
|  Y8a     a8P  d8'        `8b  Y8a.    Y88P   Y8a.    .a8P  d8'        `8b  Y8a.    .a8P  d8'        `8b   88     `8b   88            |
|   "Y88888P"  d8'          `8b  `"Y8888Y"Y8a   `"Y8888Y"'  d8'          `8b  `"Y8888Y"'  d8'          `8b  88      `8b  88888888888   |
'--------------------------------------------------------------------------------------------------------------------------------------'\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Atender emergencia\n");
        printf("3 - Atender consulta\n");
        printf("4 - Atender exame\n");
        printf("5 - Mostrar setores\n");
        printf("6 - Relatorios\n");
        printf("0 - Sair\n");
        
        switch(opcao) {

            case 1:
                cadastrar_paciente();
                break;

            case 2:
                atender_emergencia();
                break;

            case 3:
                atender_consulta();
                break;

            case 4:
                atender_exame();
                break;

            case 5:
                mostrar_setores();
                break;

            case 6:
                relatorios();
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

   }while(opcao != 0);

  return 0;
} 
