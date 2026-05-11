//adicionei o arquivo de menu e etc para rodar tudo aqui 
#include <stdio.h>
#include "hospital.h"

int main() {

    int menu;

    do {

        printf("\n-----------HOSPITAL SIMULADO-----------\n");

        printf("1 - Cadastrar paciente\n");
        printf("2 - Atender emergencia\n");
        printf("3 - Atender consulta\n");
        printf("4 - Atender exame\n");
        printf("5 - Mostrar setores\n");
        printf("6 - Transferir paciente\n");
        printf("7 - Relatorios\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &menu); 

        switch(menu) {

            case 1:
                cadastrar_paciente();
                break;

            case 2:
                atender_emergencia(); // detalhe: se a gravidade for 4 >= 5 o sisteminha evita que escolha outro que não seja emergencia, 
                //levando obrigatoriamente para a parte de emergencia  
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
                transferir_paciente();
                break;

            case 7:
                relatorios();
                break;

            case 0:
                printf("\nSistema encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(menu != 0);

    return 0;
}
