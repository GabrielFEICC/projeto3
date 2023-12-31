

#ifndef PROJETO_PROJ_H
#define PROJETO_PROJ_H


//para criar um nome para cada funcao que usaremos na proj.c
typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
    int estado;
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;

//funcoes de cadastrar, deletar e listar tarefas, alterar, filtrar por prioridade, estado, categoria, estado e categoria, exportar por categoria, prioridade, categoria e prioridade
int cadastrarTarefa(ListaDeTarefas *lt);
int deletarTarefas(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas lt);
int alterarTarefa(ListaDeTarefas *lt);
int filtrarPorPrioridade(ListaDeTarefas lt, int prioridade);
int filtrarPorEstado(ListaDeTarefas lt, int estado);
int filtrarPorCategoria(ListaDeTarefas lt, const char *categoria);
int filtrarPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char *categoria);
int exportarPorPrioridade(ListaDeTarefas lt, int prioridade, const char *arquivo);
int exportarPorCategoria(ListaDeTarefas lt, const char *categoria, const char *arquivo);
int exportarPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char *categoria, const char *arquivo);


//funcao para mostrar o menu para o usuario
void printMenu();
//para salvar as tarefas no arquivo
int salvarTarefas(ListaDeTarefas *lt, char *arquivo);
//para carregar as tarefas no arquivos
int carregarTarefas(ListaDeTarefas *lt, char *arquivo);
#endif //PROJETO_PROJ_H
