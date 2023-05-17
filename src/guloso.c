#include "guloso.h"

int vida_harry (int* caminho, int indice_caminho) {

    int vida_inicial = 1;
    int vida = 1;

    for (int i = 0; i <= indice_caminho; i++) {
        vida = vida - caminho[i];
        if (vida <= 1) {
            while(vida == 1) {
                vida++;
                vida_inicial++;
            }
        }
    }

    return vida_inicial;
}


int guloso (Graph *graph, int nrows, int ncols) {

    int* caminho = (int*)malloc(graph->nvertices * sizeof(int));
    int indice_caminho = 0;
    int indice_vertices = 0; 
    int melhor_vertice;

    caminho[indice_caminho] = graph->vertices[0].value;
    indice_caminho++;

    while (indice_vertices < graph->nvertices) {
        int aux = 0;
        for(int i = 0; i < graph->nvertices; i++){
            if((graph->vertices[indice_vertices].col + 1  == graph->vertices[i].col && graph->vertices[indice_vertices].row  == graph->vertices[i].row ) || (graph->vertices[indice_vertices].row + 1  == graph->vertices[i].row && graph->vertices[indice_vertices].col == graph->vertices[i].col)){
                int maior_aresta, nova_aresta;
                if (aux == 0) {
                    maior_aresta = graph->adjMatrix[indice_vertices][i];
                    aux++;
                }
                else {
                    nova_aresta = graph->adjMatrix[indice_vertices][i];
                
                    if (nova_aresta > maior_aresta) {
                        maior_aresta = nova_aresta;
                        melhor_vertice = i;
                    }
                }
            }
        }

        caminho[indice_caminho] = graph->vertices[melhor_vertice].value;
        indice_caminho++;
        indice_vertices = melhor_vertice;
    }
    int vida = vida_harry(caminho, indice_caminho);
    free(caminho);
    return vida;
}
