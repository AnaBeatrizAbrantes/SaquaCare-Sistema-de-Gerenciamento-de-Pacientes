#include <stdio.h>
#include <hospital.h>
#include "hospital.h"

// A emergencia > que é PILHA
Paciente emergencia[MAX];
int topo = -1;

// O paciente está para consulta na FILA

Paciente consulta[MAX];
int frenteConsulta = 0;
int atrasConsulta = -1;

// o paciente vai fazer exames FILA CIRCULAR

Paciente exames[MAX_CIRCULAR];
int frenteExames = -1;
int atrasExames = -1;

// terá os relatórios do total de pacientes e pacientes atendidos

int totalPacientes = 0;
int totalAtendidos = 0;

// O CADASTRO DO PACIENTE NO SISTEMA DO HOSPITAL

void cadastrar_paciente(){
    Paciente p;

     printf("\nNome: ");
    scanf(" %[^]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    printf("Gravidade (1-5): ");
    scanf("%d", &p.gravidade);

    printf("Tipo (1-Emergencia, 2-Consulta, 3-Exame): ");
    scanf("%d", &p.tipo);

    totalPacientes++;

    // qual a gravidade do paciente?

    if (p.gravidade >= 4 ){
        if (topo == MAX - 1){
            printf("\nEMERGENCIA LOTADA :(");
            return ;
        }

        topo++;
        emergencia[topo] = p;
        printf("\nPaciente em destino: !EMERGENCIA!");
    }

    // o paciente é consultado 
    if (p.tipo == 2) {

        if (atrasConsulta == MAX - 1) {
            printf("\nFila de consulta cheia!\n");
            return;
        }

        atrasConsulta++;
        consulta[atrasConsulta] = p;

        printf("\nPaciente enviado para CONSULTA!\n");
    }

    else if (p.tipo == 3) {

        // Se estiver cheia remove automaticamente o Exame mais antigo : isso ajuda em memoria desnecessaria ocupando nos dados..
        if ((atrasExames + 1) % MAX_CIRCULAR == frenteExames) {

            printf("\nFila de exames cheia!\n");
            printf("Paciente mais antigo removido automaticamente.\n");

            frenteExames = (frenteExames + 1) % MAX_CIRCULAR;
        }

        if (frenteExames == -1)
            frenteExames = 0;

        atrasExames = (atrasExames + 1) % MAX_CIRCULAR;
        exames[atrasExames] = p;

        printf("\nPaciente enviado para EXAMES!\n");
    }
}

void atender_emergencia() {

    if (topo == -1) {
        printf("\nEmergencia vazia!\n");
        return;
    }

    Paciente p = emergencia[topo];
    topo--;

    totalAtendidos++;

    printf("\nPaciente atendido na emergencia:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Gravidade: %d\n", p.gravidade);
}

// aqui vai mostrar os setores

void mostrar_setores() {

    int i;

    printf("\nEMERGENCIA \n");

    if (topo == -1) {
        printf("Vazio\n");
    }
    else {
        for (i = topo; i >= 0; i--) {
            printf("%s\n", emergencia[i].nome);
        }
    }

    printf("\nCONSULTAS\n");

    if (frenteConsulta > atrasConsulta) {
        printf("Vazio\n");
    }
    else {
        for (i = frenteConsulta; i <= atrasConsulta; i++) {
            printf("%s\n", consulta[i].nome);
        }
    }

    printf("\n===== EXAMES =====\n");

    if (frenteExames == -1) {
        printf("Vazio\n");
    }
    else {

        i = frenteExames;

        while (i != atrasExames) {
            printf("%s\n", exames[i].nome);
            i = (i + 1) % MAX_CIRCULAR;
        }

        printf("%s\n", exames[atrasExames].nome);
    }
}


void relatorios() {

    printf("\nRELATORIOS\n");
    printf("Total de pacientes cadastrados: %d\n", totalPacientes);
    printf("Total de pacientes atendidos: %d\n", totalAtendidos);
}

