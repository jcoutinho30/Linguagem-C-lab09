#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
    int custo;
}No;

typedef struct{
    No *v_heap;
    int qtd;
    int tamanho;
}Heap;

//encontra o pai do no
int pai(int i){
    int pai = ((i-1)/2);
    return pai;
}

//encontra o filho esq do no
int filho_esq(int i){
    int f_esq = (2*i)+1;
    return f_esq;
}

//encontra o filho direito do no
int filho_dir(int i){
    int f_dir = (2*i)+2;
    return f_dir;
}

//criando o heap com tamanho tam
Heap* inicializa_heap(Heap *heap, int tam){
    heap = malloc(sizeof(Heap));
    heap->tamanho = tam;
    heap->qtd = 0;
    heap->v_heap = malloc(tam * sizeof(No));
    return heap;
}

//criando vetor indice -> achar elementos com facilidade
int *cria_indice(Heap *heap){
    int *indice = malloc(heap->tamanho * sizeof(int));
    for(int i = 0; i < heap->tamanho; i++)
        indice[i] = -1;
    return indice;
}

//subir no heap dps de adicionar na ultima posicao -> reorganiza o heap
void subir_heap(Heap *heap, int position, int *index){
    if(position > 0 && heap->v_heap[pai(position)].custo > heap->v_heap[position].custo){

        index[heap->v_heap[position].chave] = pai(position);
        index[heap->v_heap[pai(position)].chave] = position;

        int temp1 = heap->v_heap[pai(position)].chave;
        int temp2 = heap->v_heap[pai(position)].custo;

        heap->v_heap[pai(position)].chave = heap->v_heap[position].chave;
        heap->v_heap[pai(position)].custo = heap->v_heap[position].custo;

        heap->v_heap[position].chave = temp1;
        heap->v_heap[position].custo = temp2;

        subir_heap(heap, pai(position), index);
    }
    else
        index[heap->v_heap[position].chave] = position;
}

//inserindo noh no heap
void inserir_heap(Heap *heap, int chave_i, int custo, int *index){
    if(index[chave_i] == -1 && chave_i < heap->tamanho){
        heap->v_heap[heap->qtd].chave = chave_i;
        heap->v_heap[heap->qtd].custo = custo;
        subir_heap(heap, heap->qtd, index);
        heap->qtd++;
    }
}

//descendo no heap -> reorganiza o heap quando retiramos o minimo
void descer_heap(Heap *heap, int posit, int *index){
    int low_son;
    if(filho_esq(posit) < heap->qtd){
        low_son = filho_esq(posit);
    if(filho_dir(posit) < heap->qtd && heap->v_heap[filho_dir(posit)].custo < heap->v_heap[filho_esq(posit)].custo)
        low_son = filho_dir(posit);
    if(heap->v_heap[low_son].custo < heap->v_heap[posit].custo){
        index[heap->v_heap[posit].chave] = low_son;
        index[heap->v_heap[low_son].chave] = posit;

        int temp_chave = heap->v_heap[posit].chave;
        int temp_custo = heap->v_heap[posit].custo;

        heap->v_heap[posit].chave = heap->v_heap[low_son].chave;
        heap->v_heap[posit].custo = heap->v_heap[low_son].custo;
        heap->v_heap[low_son].chave = temp_chave;
        heap->v_heap[low_son].custo = temp_custo;

        descer_heap(heap, low_son, index);
    }
    }
    else
       index[heap->v_heap[posit].chave] = posit;
}

//retirando valor minimo do heap
void min_heap(Heap *heap, int *index){
    if(heap->qtd == 0){
        index[heap->v_heap[0].chave] = -1;
        printf("heap vazio\n");
    }
    else{
        int minimo_custo = heap->v_heap[0].custo;
        int minimo_chave = heap->v_heap[0].chave;
        index[minimo_chave] = -1;

        printf("minimo {%d,%d}\n", minimo_chave, minimo_custo);

        heap->v_heap[0].custo = heap->v_heap[heap->qtd-1].custo;
        heap->v_heap[0].chave = heap->v_heap[heap->qtd-1].chave;

        heap->v_heap[heap->qtd-1].custo = minimo_custo;
        heap->v_heap[heap->qtd-1].chave = minimo_chave;

        heap->qtd--;

        descer_heap(heap, 0, index);
    }
}

//buscando chave igual para trocar custo
void troca_custo(Heap *heap, int chave_t, int custo_t, int *index){
    heap->v_heap[index[chave_t]].custo = custo_t;
    subir_heap(heap, index[chave_t], index);
}

int main (void){
    int tamanho;
    char comando;

    scanf("%d", &tamanho);

    int *v_index = NULL;
    Heap *heap = NULL;

    heap = inicializa_heap(heap, tamanho);
    v_index = cria_indice(heap);


    while(scanf(" %c", &comando) != 'z'){
        
        if(comando == 'i'){
            int chave_i;
            int custo_i;
            scanf(" %d", &chave_i);
            scanf(" %d", &custo_i);
            inserir_heap(heap, chave_i, custo_i, v_index);
        }

        if(comando == 'm'){
            min_heap(heap, v_index);
        }

        if(comando == 'd'){
            int chave_d;
            int custo_d;
            scanf(" %d", &chave_d);
            scanf(" %d", &custo_d);
            troca_custo(heap, chave_d, custo_d, v_index);
        }

        if(comando == 't'){
            free(heap->v_heap);
            free(heap);
            free(v_index);
            break;
        }
    }
}