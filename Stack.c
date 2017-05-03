#include <stdio.h>
#include <stdlib.h>

typedef struct Graph graph;
typedef struct Node node;
typedef struct Stack stack;


struct Stack {
  node* top;
  int quant_no;
};

struct Node {
  int dado;
  node* next;
};

// Funções~

graph* create_graph(int quant_vertice);
node* create_node(int value_vertice);
void add_vertice(graph* G, int vertice1, int vertice2);
void dfs(graph* G, int vertice, stack* sta);
void push(stack* sta, int value);
int pop(stack* sta);
void topSort(graph* G, stack* sta, int quant_vertice);
void createDepend(graph* G, int dependencias);

//---------------------------------------------------

node* create_node(int value){
  // Alocando um nó que vai ser o futuro vertice.
  node* n = (node*) calloc(1, sizeof(node));
  // setando os valores da struct no.
  n->dado = value;
  n->next = NULL;

  return n;
}


stack* create_stack(){
  //Alocando a stack.
  stack* sta = (stack*) calloc(1, sizeof(stack));
  sta->top = NULL;
  sta->quant_no = 0;
  return sta;
}

void push(stack* sta, int value){
  node* no = create_node(value);
  if (!sta->quant_no){
    sta->top = no;
  } else {
    no->next = sta->top;
    sta->top = no;
  }
  sta->quant_no ++;
}

int pop(stack* sta){

  int vertice = sta->top->dado;

  node* n = sta->top;
  sta->top = sta->top->next;

  free(n);

  return vertice;

}

int main(){

    int array[15], i, j=0;

    for (i=14; i>=0; i--)
    {
        array[i] = j;
        j++;
    }

    stack *s = create_stack();

    for(i=0; i<15; i++)
        push(s, i);
    j=0;
    for (i=0; i<15; i++)
    {
       if(array[i] == pop(s))
       {
            printf("%d\n", j);
            j++;
       }
    }
    return 0;
}
