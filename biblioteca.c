
//incluimos para as funcoes rodarem
#include <stdio.h>
#include "biblioteca.h"
#include <stdlib.h>

//funcao de cadastrar as tarefas
int cadastrarTarefa(ListaDeTarefas *lt){
    if (lt-> qtd < 100) {
        Tarefa novaTarefa;
        
        //para escolher a prioridade da tarefa
        printf("Digite a prioridade da tarefa entre 0 e 10: ");
        scanf("%d", &novaTarefa.prioridade);

        //para caso escolha uma opcao menor que 0 ou maior que 10, dar erro
        if (novaTarefa.prioridade < 0 || novaTarefa.prioridade > 10) {
            printf("Prioridade invalida. A prioridade deve estar entre 0 e 10.\n");
            return 0;
        }

        //para digitar a categoria da tarefa
        printf("Digite a categoria da tarefa: ");
        scanf("%s", novaTarefa.categoria);

        //para digitar a descrição da tarefa
        printf("Digite a descricao da tarefa: ");
        scanf("%s", novaTarefa.descricao);

        lt->tarefas[lt->qtd] = novaTarefa;
        lt->qtd++;

        //mostra se a tarefa foi ou não cadastrada com sucesso
        printf("Tarefa cadastrada com sucesso!\n");

    } else {
        printf("A lista de tarefas está cheia.\n");

    }
}

//funcao de deletar as tarefas
int deletarTarefas(ListaDeTarefas *lt){
    int num;

    //para excluir o numero da tarefa que estava criada
    printf("Digite o numero da tarefa que deseja deletar: ");
    scanf("%d", &num);

    if (num >= 1 && num <= lt->qtd) {
        for (int i = num - 1; i < lt->qtd - 1; i++) {
            lt->tarefas[i] = lt->tarefas[i + 1];
        }
        lt->qtd--;

        //para mostrar se a tarefa foi deletada ou não com sucesso
        printf("Tarefa com o numero foi deletada com sucesso\n", num);
        return 1;
    } else {
        printf("nao existe essa tarefa\n");
        return 0;
    }
}

//funcao de listar as tarefas criadas
int listarTarefas(ListaDeTarefas lt){
    if (lt.qtd == 0) {
        //caso nenhuma tarefa tenha sido cadastrada, ira mostrar.
        printf("Nenhuma tarefa cadastrada.\n");
        return 0;
    }

    printf("Lista de Tarefas:\n");
    for (int i = 0; i < lt.qtd; i++) {
        //mostra o numero da tarefa, prioridade, categoria e descrição
        printf("tarefa: %d\n", i + 1);
        printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
        printf("Categoria: %s\n", lt.tarefas[i].categoria);
        printf("Descricao: %s\n", lt.tarefas[i].descricao);

    }

    return 1;
}

//funcao de mostrar o menu para o usuario escolher oq ele quer fazer
void printMenu(){
    printf("Menu\n");
    printf("1. Cadastrar Tarefa\n");
    printf("2. Deletar Tarefas\n");
    printf("3. Listar Tarefas\n");

}

//funcao de salvar as tarefas em arquivo
int salvarTarefas(ListaDeTarefas *lt, char *arquivo){
    FILE *arq;
    //caso o arquivo esteja vazio, nao ira abrir
    arq = fopen(arquivo, "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        return 0;
    }

    fwrite(lt, sizeof(ListaDeTarefas), 1, arq);

    fclose(arq);
    //para salvar todas as tarefas que digitou no arquivo
    printf("Tarefas salvas com sucesso no arquivo %s.\n", arquivo);
    return 1;

}

//funcao de carregas as tarefas no arquivo
int carregarTarefas(ListaDeTarefas *lt, char *arquivo){
    FILE *arq;

    arq = fopen(arquivo, "rb");
    if (arq == NULL) {
        //caso nao tenha nenhuma tarefa no arquivo, ira mostrar isso
        printf("Arquivo %s não encontrado. Iniciando com lista vazia.\n", arquivo);
        return 0;
    }

    fread(lt, sizeof(ListaDeTarefas), 1, arq);

    fclose(arq);
    //ira mostrar todas as tarefas digitas no arquivo
    printf("Tarefas carregadas com sucesso do arquivo %s.\n", arquivo);
    return 1;

}

int alterarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd == 0) {
        printf("Nenhuma tarefa cadastrada para alterar.\n");
        return 0;
    }

    int numeroTarefa;
    printf("Digite o número da tarefa que deseja alterar: ");
    scanf("%d", &numeroTarefa);

    if (numeroTarefa < 1 || numeroTarefa > lt->qtd) {
        printf("Número de tarefa inválido.\n");
        return 0;
    }

    Tarefa *tarefa = &lt->tarefas[numeroTarefa - 1];

    printf("Escolha o campo a ser alterado:\n");
    printf("1. Prioridade\n");
    printf("2. Categoria\n");
    printf("3. Descrição\n");
    printf("4. Estado\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a nova prioridade da tarefa: ");
            scanf("%d", &tarefa->prioridade);
            break;
        case 2:
            printf("Digite a nova categoria da tarefa: ");
            scanf("%s", tarefa->categoria);
            break;
        case 3:
            printf("Digite a nova descrição da tarefa: ");
            scanf("%s", tarefa->descricao);
            break;
        case 4:
            printf("Escolha o novo estado da tarefa (0 - Não Iniciado, 1 - Em Andamento, 2 - Completo): ");
            int estado;
            scanf("%d", &estado);

            if (estado < 0 || estado > 2) {
                printf("Estado inválido.\n");
                return 0;
            }

            tarefa->estado = estado;
            break;
        default:
            printf("Opção inválida.\n");
    }

    printf("Tarefa alterada com sucesso!\n");
    return 1;
}


