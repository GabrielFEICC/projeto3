
//incluimos para as funcoes rodarem
#include <stdio.h>
#include "biblioteca.h"
#include <stdlib.h>

//funcao para mostrar o menu, com as opcoes
void printMenu() {
    printf("Menu\n");
    printf("1 - Cadastrar Tarefas\n");
    printf("2 - Deletar Tarefas\n");
    printf("3 - Listar Tarefas\n");
    printf("4 - Alterar Tarefa\n");
    printf("5 - Filtrar Tarefas por Prioridade\n");
    printf("6 - Filtrar Tarefas por Estado\n");
    printf("7 - Filtrar Tarefas por Categoria\n");
    printf("8 - Filtrar Tarefas por Prioridade e Categoria\n");
    printf("9 - Exportar Tarefas por Prioridade\n");
    printf("10 - Exportar Tarefas por Categoria\n");
    printf("11 - Exportar Tarefas por Prioridade e Categoria\n");
    printf("0 - Sair\n");
}



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

//funcao para alterar a tarefa
int alterarTarefa(ListaDeTarefas *lt) {
    //quando nao tiver nenhuma tarefa cadastrada
    if (lt->qtd == 0) {
        printf("Nenhuma tarefa cadastrada para alterar.\n");
        return 0;
    }

    int numeroTarefa;
    //para digitar o numero da tarefa
    printf("Digite o numero da tarefa que deseja alterar: ");
    scanf("%d", &numeroTarefa);

    //para dar erro quando digitar um numero menor que 1 ou maior que a quantidade de tarefas que possui
    if (numeroTarefa < 1 || numeroTarefa > lt->qtd) {
        printf("Numero de tarefa invalido.\n");
        return 0;
    }

    Tarefa *tarefa = &lt->tarefas[numeroTarefa - 1];

    //para escolher se deseja alterar entrem prioridade, categoria, descricao e estado
    printf("Escolha o campo a ser alterado:\n");
    printf("1. Prioridade\n");
    printf("2. Categoria\n");
    printf("3. Descricao\n");
    printf("4. Estado\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
        //para trocar a prioridade
            printf("Digite a nova prioridade da tarefa: ");
            scanf("%d", &tarefa->prioridade);
            break;
        case 2:
        //para digitar a nova categoria
            printf("Digite a nova categoria da tarefa: ");
            scanf("%s", tarefa->categoria);
            break;
        case 3:
        //para a nova descricao
            printf("Digite a nova descricao da tarefa: ");
            scanf("%s", tarefa->descricao);
            break;
        case 4:
        //para o novo estado da tarefa
            printf("Escolha o novo estado da tarefa (0 - Não Iniciado, 1 - Em Andamento, 2 - Completo): ");
            int estado;
            scanf("%d", &estado);
            //caso digite entre menor ou maior que 0, dar erro
            if (estado < 0 || estado > 2) {
                printf("Estado invalido.\n");
                return 0;
            }

            tarefa->estado = estado;
            break;
        default:
            printf("Opcao invalida.\n");
    }

    printf("Tarefa alterada com sucesso\n");
    return 1;
}


//funcao de filtrar por prioridade
int filtrarPorPrioridade(ListaDeTarefas lt, int prioridade) {
    int tarefasEncontradas = 0;

    for (int i = 0; i < lt.qtd; i++) {
        //para mostrar as tarefas
        if (lt.tarefas[i].prioridade == prioridade) {
            printf("Tarefa: %d\n", i + 1);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            printf("\n");
            tarefasEncontradas = 1;
        }
    }

    if (!tarefasEncontradas) {
        //caso nao encontre nenhuma tarefa com prioridade
        printf("Nenhuma tarefa encontrada com prioridade %d\n", prioridade);
        return 0;
    }

    return 1;
}

//funcao para filtrar por estado
int filtrarPorEstado(ListaDeTarefas lt, int estado) {
    int tarefasEncontradas = 0;

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].estado == estado) {
            //para mostrar as tarefas
            printf("Tarefa: %d\n", i + 1);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descrição: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            printf("\n");
            tarefasEncontradas = 1;
        }
    }

    if (!tarefasEncontradas) {
        //caso nao tenha nenhuma tarefa com estado
        printf("Nenhuma tarefa encontrada com estado %d\n", estado);
        return 0;
    }

    return 1;
}

//funcao para filtrar por categoria
int filtrarPorCategoria(ListaDeTarefas lt, const char *categoria) {
    int tarefasEncontradas = 0;

    for (int i = 0; i < lt.qtd; i++) {
        //para mostrar a tarefa
        if (strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            printf("Tarefa: %d\n", i + 1);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            printf("\n");
            tarefasEncontradas = 1;
        }
    }

    if (!tarefasEncontradas) {
        //caso nao tenha nenhuma tarefa na categoria
        printf("Nenhuma tarefa encontrada na categoria %s\n", categoria);
        return 0;
    }

    return 1;
}

//funcao de filtrar por prioridade e categoria
int filtrarPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char *categoria) {
    int tarefasEncontradas = 0;

    for (int i = 0; i < lt.qtd; i++) {
        //para mostrar a tarefa
        if (lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            printf("Tarefa: %d\n", i + 1);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            printf("\n");
            tarefasEncontradas = 1;
        }
    }

    if (!tarefasEncontradas) {
        //caso nenhuma tarefa com a prioridade e categoria desejada
        printf("Nenhuma tarefa encontrada com prioridade %d e na categoria %s\n", prioridade, categoria);
        return 0;
    }

    return 1;
}

//funcao de exportar por prioridade
int exportarPorPrioridade(ListaDeTarefas lt, int prioridade, const char *arquivo) {
    
    FILE *exportFile = fopen(arquivo, "w");

    if (!exportFile) {
        //caso de erro para abrir o arquivo
        printf("Erro ao abrir o arquivo de exportacao.\n");
        return 0;
    }

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridade) {
            //para mostrar a tarefa
            fprintf(exportFile, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(exportFile, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(exportFile, "Estado: %d\n", lt.tarefas[i].estado);
            fprintf(exportFile, "Descricao: %s\n\n");
        }
    }

    fclose(exportFile);
    //para exportar a tarefa com tal prioridade para o arquivo
    printf("Tarefas com prioridade %d exportadas para o arquivo %s.\n", prioridade, arquivo);
    return 1;
}


//funcao de exportar por categoria
int exportarPorCategoria(ListaDeTarefas lt, const char *categoria, const char *arquivo) {
    FILE *exportFile = fopen(arquivo, "w");

    if (!exportFile) {
        //caso de erro ao abrir o arquivo
        printf("Erro ao abrir o arquivo de exportacao.\n");
        return 0;
    }

    for (int i = 0; i < lt.qtd; i++) {
        if (strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            //para mostrar a tarefa
            fprintf(exportFile, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(exportFile, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(exportFile, "Estado: %d\n", lt.tarefas[i].estado);
            fprintf(exportFile, "Descricao: %s\n\n");
        }
    }

    fclose(exportFile);
    //vai exportar a tarefa com categoria para o arquivo
    printf("Tarefas na categoria %s exportadas para o arquivo %s.\n", categoria, arquivo);
    return 1;
}


//para mostrar por prioridade e categoria
int exportarPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char *categoria, const char *arquivo) {
    FILE *exportFile = fopen(arquivo, "w");

    if (!exportFile) {
        //caso de erro ao abrir o arquivo
        printf("Erro ao abrir o arquivo de exportacao.\n");
        return 0;
    }

    for (int i = 0; i < lt.qtd; i++) {
        //para mostrar a tarefa
        if (lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            fprintf(exportFile, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(exportFile, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(exportFile, "Estado: %d\n", lt.tarefas[i].estado);
            fprintf(exportFile, "Descricao: %s\n\n");
        }
    }

    fclose(exportFile);
    //vai exportar a tarefa com prioridade e categoria para o arquivo
    printf("Tarefas com prioridade %d e na categoria %s exportadas para o arquivo %s.\n", prioridade, categoria, arquivo);
    return 1;
}
