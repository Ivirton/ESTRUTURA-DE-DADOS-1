#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct vei{
    char nome[20];
    int anoFacricacao;
    float precoCompra;
    float precoVenda;
    vei *anterior;
    vei *proximo;
}Veiculo;
 //Listas de veiculos
 Veiculo *veiculos_Venda = NULL,*veiculos_Vendidos = NULL;
//Adicionar dados aos campos
void setConteudo(vei **head){
    vei *novo = *head;
    printf("\n\n");
    printf("*******\t\tCadastro de veiculo\t********\n");
    printf("Nome do Carro:");
    scanf("%s",novo->nome);
    printf("Ano de fabricacao:");
    scanf("%d",&novo->anoFacricacao);
    printf("Preco de compra:");
    scanf("%f",&novo->precoCompra);
    novo->precoVenda = (novo->precoCompra * 0.2) + novo->precoCompra;
    system("cls");
    //comando usando para limpar o terminal do windows! pode ser que não funcione em outro sistema operacional
}
//aloca uma novo veiculo a lista
Veiculo *alocarCelula(){
    vei *nova = (vei*) malloc(sizeof(vei));
    setConteudo(&nova);
    return nova;
}
//adiciona um veiculo a lista de vendas por ordem alfabética
void adicionarOrdenado(vei **head,vei *nova){
     if (*head == NULL) {
    nova->proximo = *head;
    *head = nova;
  } else {
    vei *aux = *head;
    Veiculo *ant = NULL;
    while (aux != NULL) {
      if (strcmp(nova->nome, aux->nome) < 0) {
        if (ant != NULL) {
          ant->proximo = nova;
        } else {
          *head = nova;
        }
        nova->proximo = aux;
        return;
      }
      ant = aux;
      aux = aux->proximo;
    }
    ant->proximo = nova;
    nova->proximo = aux;
  }
}
//adicionarVendidos

//Imprimi todos veiculos
void imprimirVeiculos(vei *head){
    printf("\t*******\t\tVEICULOS A VENDA\t********\n");
    printf("\n");
    int cont = 1;
    while(head){
        printf("%d \tnome:%s\t",cont,head->nome);
        printf("\tAno:%d\t",head->anoFacricacao);
        printf("\tValor:%3.2f\t",head->precoVenda);
        printf("\n");
        head = head->proximo;
         cont++;  
    }
}
//buscar por valor
void buscarValor(vei *head){
  printf("*******\t\tBuscar por Valor\t********\n");
  printf("\tValo:");
  float valor = 0;
   int cont = 1;
  scanf("%f",&valor);
  while(head){
    if(head->precoVenda <= valor){
     printf("%d \tnome:%s\t",cont,head->nome);
      printf("\tAno:%d\t",head->anoFacricacao);
      printf("\tValor:%3.2f\t",head->precoVenda);
      printf("\n");
       cont++;  
    }     
    head = head->proximo;

  }
}
//buscar por ano
void buscarAno(vei *head){
  printf("*******\t\tBuscar por Ano\t********\n");
  printf("\tAno:");
  int valor = 0;
  scanf("%d",&valor);
   int cont = 1;
  while(head){
    if(head->anoFacricacao == valor){
      printf("%d \tnome:%s\t",cont,head->nome);
      printf("\tAno:%d\t",head->anoFacricacao);
      printf("\tValor:%3.2f\t",head->precoVenda);
      printf("\n");
       cont++;  
    }   
     
    head = head->proximo;
  }
}

//realiza a compra dos veiculos
vei* comprar(vei *head){
  printf("*******\t\tComprar Veiculo\t********\n");
  printf("\tDigite o nome do veiculo:");
  char nome[20];
  scanf(" %s",nome);
  Veiculo *aux, *remover = NULL;

   if(strcmp(head->nome,nome)){
      adicionarOrdenado(&veiculos_Vendidos,head);
      
    }else{
      aux = head;
      
            while(aux->proximo && strcmp(head->nome,nome)){
              if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
              aux = aux->proximo;
            }
    }
 
  return remover;
}
//menu
int menu(){
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Registrar Veiculo\t*\n");
  printf("*\t2 - Veiculos a Venda\t*\n");
  printf("*\t3 - Buscar por valor\t*\n");
  printf("*\t4 - Buscar por Ano\t*\n");
  printf("*\t5 - Comprar veiculo\t*\n");
  printf("*\t0 - Sair\t\t*\n >");
  int valor = 0;
  scanf("%d",&valor);
  system("cls");
  return valor;
}
void opcoes(){
    int op = 0;
    do{
      op = menu();
        switch(op){
            case 1:
              adicionarOrdenado(&veiculos_Venda,alocarCelula());
              break;
            case 2:
              imprimirVeiculos(veiculos_Venda);
              break;
            case 3:
              buscarValor(veiculos_Venda);
              break;
            case 4:
              buscarAno(veiculos_Venda);
              break;
            case 5:
             free(comprar(veiculos_Venda));
              break;
        }
    }while (op != 0);
}
int main(){
  opcoes();
  printf("Sitema finalizado!\n");
  system("pause");
  return 0;
}