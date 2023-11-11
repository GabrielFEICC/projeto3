#include <stdio.h>
#include "biblioteca.h"
#include <stdlib.h>


//a main funciona para fazer rodar o programa no terminal e mostrar os resultados
//fizemos todas as funcoes na biblioteca.c, na main apenas estamos chamando as funcoes para rodar perfeitamente no terminal no arquivo
int main() {
    int cod;
    char arquivo[100] = "tarefas";
    ListaDeTarefas lt;

    cod = carregarTarefas(&lt, arquivo);
    lt.qtd = 0;

    int opcao;
    do{
        printMenu();
        scanf("%d", &opcao);

        if (opcao==0){

        }else if(opcao==1){
            //para mostrar o cadastrar tarefa
            cadastrarTarefa(&lt);
        }else if(opcao==2){
            //para mostrar o deletar tarefa
            deletarTarefas(&lt);
        }else if(opcao==3){
            //para mostrar o listar tarefa
            listarTarefas(lt);
        }else if (opcao == 4) {
            //para mostrar o alterar tarefa
            alterarTarefa(&lt);
        }else if (opcao == 5){
            //para mostrar a prioridade da tarefa
            int prioridade;
            printf("Digite a prioridade para filtrar: ");
            scanf("%d", &prioridade);
            filtrarPorPrioridade(lt, prioridade);
        }else if (opcao == 6) {
            //para mostrar o estado da tarefa
            int estado;
            printf("Digite o estado para filtrar (0 - Nao iniciado, 1 - Em andamento, 2 - Completo): ");
            scanf("%d", &estado);
            filtrarPorEstado(lt, estado);
        }else if (opcao == 7) {
            //para mostrar a categoria da tarefa filtrar
            char categoria[100];
            printf("Digite a categoria para filtrar: ");
            scanf("%s", categoria);
            filtrarPorCategoria(lt, categoria);
        }else if (opcao == 8) {
            //para mostrar a prioridade e categoria da tarefa para filtrar
            int prioridade;
            char categoria[100];
            printf("Digite a prioridade para filtrar: ");
            scanf("%d", &prioridade);
            printf("Digite a categoria para filtrar: ");
            scanf("%s", categoria);
            filtrarPorPrioridadeECategoria(lt, prioridade, categoria);
        }else if (opcao == 9) {
            //para exportar por prioridade
            int prioridade;
            char exportFile[100];
            printf("Digite a prioridade para exportar: ");
            scanf("%d", &prioridade);
            printf("Digite o nome do arquivo de exportacao: ");
            scanf("%s", exportFile);
            exportarPorPrioridade(lt, prioridade, exportFile);
        }else if (opcao == 10) {
            //para exportar por categoria
            char categoria[100];
            char exportFile[100];
            printf("Digite a categoria para exportar: ");
            scanf("%s", categoria);
            printf("Digite o nome do arquivo de exportacao: ");
            scanf("%s", exportFile);
            exportarPorCategoria(lt, categoria, exportFile);
        }else if (opcao == 11){
            //para exportar por prioridade e categoria
            int prioridade;
            char categoria[100];
            char exportFile[100];
            printf("Digite a prioridade para exportar: ");
            scanf("%d", &prioridade);
            printf("Digite a categoria para exportar: ");
            scanf("%s", categoria);
            printf("Digite o nome do arquivo de exportacao: ");
            scanf("%s", exportFile);
            exportarPorPrioridadeECategoria(lt, prioridade, categoria, exportFile);
        }else{
            //caso digite uma opcao errada
            printf("opcao invalida\n");
        }
        printf("%d\n", opcao);
    } while (opcao != 0);

    cod = salvarTarefas(&lt, arquivo);
    if (cod != 0){
        //caso de erro ao salvar o arquivo
        printf("problema ao salvar arquivo\n");
    }
    //para dar fim ao programa
    printf("fim\n");
    return 0;
}
