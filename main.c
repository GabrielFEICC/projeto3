#include <stdio.h>
#include "biblioteca.h"
#include <stdlib.h>


//a main funciona para fazer rodar o programa no terminal e mostrar os resultados
//fizemos todas as funcoes no proj.c, na main apenas estamos chamando as funcoes para rodar perfeitamente no terminal no arquivo
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
            cadastrarTarefa(&lt);
        }else if(opcao==2){
            deletarTarefas(&lt);
        }else if(opcao==3){
            listarTarefas(lt);
        }else if (opcao == 4) {
            alterarTarefa(&lt);
        }else if (opcao == 5){
            int prioridade;
            printf("Digite a prioridade para filtrar: ");
            scanf("%d", &prioridade);
            filtrarPorPrioridade(lt, prioridade);
        }else if (opcao == 6) {
            int estado;
            printf("Digite o estado para filtrar (0 - Nao iniciado, 1 - Em andamento, 2 - Completo): ");
            scanf("%d", &estado);
            filtrarPorEstado(lt, estado);
        }else if (opcao == 7) {
            char categoria[100];
            printf("Digite a categoria para filtrar: ");
            scanf("%s", categoria);
            filtrarPorCategoria(lt, categoria);
        }else if (opcao == 8) {
            int prioridade;
            char categoria[100];
            printf("Digite a prioridade para filtrar: ");
            scanf("%d", &prioridade);
            printf("Digite a categoria para filtrar: ");
            scanf("%s", categoria);
            filtrarPorPrioridadeECategoria(lt, prioridade, categoria);
        }else if (opcao == 9) {
            int prioridade;
            char exportFile[100];
            printf("Digite a prioridade para exportar: ");
            scanf("%d", &prioridade);
            printf("Digite o nome do arquivo de exportação: ");
            scanf("%s", exportFile);
            exportarPorPrioridade(lt, prioridade, exportFile);
        }else{
            printf("opcao invalida\n");
        }
        printf("%d\n", opcao);
    } while (opcao != 0);

    cod = salvarTarefas(&lt, arquivo);
    if (cod != 0){
        printf("problema ao salvar arquivo\n");
    }

    printf("fim\n");
    return 0;
}
