<img width="367" height="137" alt="image" src="..." />

# Hospital Simulado - Gerenciamento de Pacientes

Implemetação desenvolvida em C para simular o fluxo hospitalar utilizando estruturas de dados lineares.

## Regras
- **Emergência (Pilha):** Atendimento prioritário para gravidade 4 e 5.
- **Consultas (Fila):** Ordem de chegada para atendimentos agendados.
- **Exames (Fila Circular):** Capacidade máxima de 8 pacientes (remove o antigo se encher).

## Como Compilar e Rodar
1. Tenha um compilador C (como GCC) instalado.
2. No terminal, use:
   ```bash
   gcc main.c -o hospital
   ./hospital

### TRABALHO DE IMPLEMENTAÇÃO - ESTRUTURA DE DADOS - 3ºPERIODO - ESW - 2026
*ALUNOS: ANA BEATRIZ ABRANTES DA SILVA , NAYARA EMELLY PEREIRA MENDONÇA.*

ACESSO : [ACESSE AQUI](https://www.onlinegdb.com/fork/kydX4Jp4K) >> ESTARÁ O LINK DO COMPILADOR ONLINE PRONTO PARA O TESTE DEMONSTRATIVO


&#x09;Durante o desenvolvimento do sistema, realizamos pesquisas para entender melhor o funcionamento das estruturas de dados, como pilha, fila e fila circular. Ao longo do processo surgiram algumas dificuldades e dúvidas relacionadas à lógica e implementação em linguagem C, porém conseguimos resolver os problemas gradualmente e finalizar um sistema funcional e executável conforme os requisitos da atividade.


#### DESENVOLVIMENTO

FORAM CRIADOS 3 ARQUIVOS: **hospital.h , hospital.c e main.c**;


* **hospital.h** : Sendo o arquivo "cabeçalho", ele é o nosso arquivo header, que serviria para guardar o **Struct Paciente,** as constantes (MAX) e os protótipos das funções (void) . Sendo importante para conectar os arquivos do projeto;

* **hospital.c** : Onde realmente funciona com toda a lógica do sistema, ele contem: Pilha(emergencia) , Fila(consulta), Fila circular(exames), Cadastro, Atendimento, relatórios;

* **main.c** : Sendo o arquivo que chamará todos para serem rodados, ou seja, o "start", contendo o menu, opções e chamadas das funções do **hospital.c,** é onde controla as interações do usuário;


**Obs: os demais arquivos não se incluem no sistema que será compilado, sendo apenas anotações, códigos de exemplo e entre outros.**
