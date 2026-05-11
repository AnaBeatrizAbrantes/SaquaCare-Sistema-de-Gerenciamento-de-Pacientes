#include <stdio.h>
#include <string.h>
#include "hospital.h"

Paciente emergencia[MAX]; // ultimo a chegar é o primeiro a ser atendido 
int topo = -1;

Paciente consulta[MAX]; // o primeiro a chegar é atendido primeiro 
int frenteConsulta = 0;
int atrasConsulta = -1;

Paciente exames[MAX_CIRCULAR]; // é remover o mais antigo 
int frenteExames = -1;
int atrasExames = -1;

int totalPacientes = 0;
int totalAtendidos = 0;

void cadastrar_paciente() {

    Paciente p;

    printf("\nNome: ");
    scanf(" %[^\n]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    printf("Gravidade (1-5): ");
    scanf("%d", &p.gravidade);

    printf("Tipo (1-Emergencia, 2-Consulta, 3-Exame): ");
    scanf("%d", &p.tipo);

    totalPacientes++;

    if (p.gravidade >= 4) {

        if (topo == MAX - 1) {
            printf("\nEMERGENCIA LOTADA!\n");
            return;
        }

        topo++;
        emergencia[topo] = p;

        printf("\nPaciente enviado para EMERGENCIA!\n");
        return;
    }

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

        if ((atrasExames + 1) % MAX_CIRCULAR == frenteExames) {

            printf("\nFila de exames cheia!\n");
            printf("Paciente mais antigo removido .\n");

            frenteExames = (frenteExames + 1) % MAX_CIRCULAR;
        }

        if (frenteExames == -1) {
            frenteExames = 0;
        }

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

void atender_consulta() {

    if (frenteConsulta > atrasConsulta) {
        printf("\nFila de consulta vazia!\n");
        return;
    }

    Paciente p = consulta[frenteConsulta];

    frenteConsulta++;

    totalAtendidos++;

    printf("\nPaciente atendido na consulta:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Gravidade: %d\n", p.gravidade);
}

void atender_exame() {

    if (frenteExames == -1) {
        printf("\nFila de exames vazia!\n");
        return;
    }

    Paciente p = exames[frenteExames];

    if (frenteExames == atrasExames) {

        frenteExames = -1;
        atrasExames = -1;

    } else {

        frenteExames = (frenteExames + 1) % MAX_CIRCULAR;
    }

    totalAtendidos++;

    printf("\nPaciente atendido no exame:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Gravidade: %d\n", p.gravidade);
}

void mostrar_setores() {

    int i;

    printf("\n EMERGENCIA\n");

    if (topo == -1) {

        printf("Vazio\n");

    } else {

        for (i = topo; i >= 0; i--) {
            printf("%s\n", emergencia[i].nome);
        }
    }

    printf("\n CONSULTAS\n");

    if (frenteConsulta > atrasConsulta) {

        printf("Vazio\n");

    } else {

        for (i = frenteConsulta; i <= atrasConsulta; i++) {
            printf("%s\n", consulta[i].nome);
        }
    }

    printf("\n EXAMES\n");

    if (frenteExames == -1) {

        printf("Vazio\n");

    } else {

        i = frenteExames;

        while (i != atrasExames) {

            printf("%s\n", exames[i].nome);

            i = (i + 1) % MAX_CIRCULAR;
        }

        printf("%s\n", exames[atrasExames].nome);
    }
}

void transferir_paciente(){
     
    int destino;

    if (frenteConsulta > atrasConsuta){
        printf("\nnão há pacientes na consulta!\n")
        return;
    }

    Paciente p = consulta[frenteConsulta];
    frenteConsulta++;

    printf("\nTransferir para:\n");
    printf("\n1 > Emergencia\n");
    printf("\n2 > Exames\n");

    scanf("%d", &destino);

    if (destino == 1){
        if(topo == MAX -1){
            printf("\nEmergencia cheia!\n");
            return;
        }

        topo++;
        emergencia[topo] = p;
        printf("\nPaciente tranferido para EMERGENCIA\n");
    }

     else if (destino == 2) {

        if ((atrasExames + 1) % MAX_CIRCULAR == frenteExames) {

            frenteExames = (frenteExames + 1) % MAX_CIRCULAR;
        }

        if (frenteExames == -1) {
            frenteExames = 0;
        }

        atrasExames = (atrasExames + 1) % MAX_CIRCULAR;

        exames[atrasExames] = p;

        printf("\nPaciente transferido para EXAMES!\n");
    }

    else {

        printf("\nDestino invalido!\n");
    }
}

 

void relatorios() {

    printf("\nRegistros\n");

    printf("Total de pacientes cadastrados: %d\n", totalPacientes);

    printf("Total de pacientes atendidos: %d\n", totalAtendidos);
}
