#include <stdio.h>
#include <hospital.h>
#include "hospital.h"

// A emergencia > que é PILHA
Paciente emergencia[MAX];
int topo = -1;

// O paciente está para consulta na FILA

Paciente consuta[MAX];
int frenteConsuta = 0;
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
    scanf(" %[^
]", p.nome);

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

        if (trasConsulta == MAX - 1) {
            printf("\nFila de consulta cheia!\n");
            return;
        }

        trasConsulta++;
        consulta[trasConsulta] = p;

        printf("\nPaciente enviado para CONSULTA!\n");
    }

    else if (p.tipo == 3) {

        // Se estiver cheia remove automaticamente o Exame mais antigo : isso ajuda em memoria desnecessaria ocupando nos dados..
        if ((trasExame + 1) % MAX_CIRCULAR == frenteExame) {

            printf("\nFila de exames cheia!\n");
            printf("Paciente mais antigo removido automaticamente.\n");

            frenteExame = (frenteExame + 1) % MAX_CIRCULAR;
        }

        if (frenteExame == -1)
            frenteExame = 0;

        trasExame = (trasExame + 1) % MAX_CIRCULAR;
        exames[trasExame] = p;

        printf("\nPaciente enviado para EXAMES!\n");
    }
}

void atender_emergencia() {

    if (frenteExame == trasExame) {
        frenteExame = -1;
        trasExame = -1;
    }
    else {
        frenteExame = (frenteExame + 1) % MAX_CIRCULAR;
    }

    totalAtendidos++;

    printf("\nPaciente atendido no exame:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Gravidade: %d\n", p.gravidade);
}

// aqui vai mostrar os setores

void mostrar_setores() {

    int i;

    printf("\n===== EMERGENCIA =====\n");

    if (topo == -1) {
        printf("Vazio\n");
    }
    else {
        for (i = topo; i >= 0; i--) {
            printf("%s\n", emergencia[i].nome);
        }
    }

    printf("\n===== CONSULTAS =====\n");

    if (frenteConsulta > trasConsulta) {
        printf("Vazio\n");
    }
    else {
        for (i = frenteConsulta; i <= trasConsulta; i++) {
            printf("%s\n", consulta[i].nome);
        }
    }

    printf("\n===== EXAMES =====\n");

    if (frenteExame == -1) {
        printf("Vazio\n");
    }
    else {

        i = frenteExame;

        while (i != trasExame) {
            printf("%s\n", exames[i].nome);
            i = (i + 1) % MAX_CIRCULAR;
        }

        printf("%s\n", exames[trasExame].nome);
    }
}


void relatorios() {

    printf("\n===== RELATORIOS =====\n");
    printf("Total de pacientes cadastrados: %d\n", totalPacientes);
    printf("Total de pacientes atendidos: %d\n", totalAtendidos);
}

