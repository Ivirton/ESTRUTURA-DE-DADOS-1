#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<strings.h>
float preco_Brasil_Argentiva = 3121;
float preco_Argentina_Brasil = 2869;

typedef struct pass{
    int localizador;
    int dia,mes,ano;
    char destino[20];
    float preco;
    pass *esquerda, *direita;
}Passagem;
typedef struct anos{
    int ano;
    pass *passagem;
    anos *esquerda,*direita;
}Anos;
Passagem *raizArgentina;
Passagem *raizBrasil;
Anos *anosAnteriores;
pass *terceira;
int anoAtual = 2022;

void  imprimir(pass *raiz, int tab = 0) {
    if (raiz == NULL) return;
    imprimir(raiz->direita, tab + 1);
    for (int i = 0; i < tab; i++) printf("\t");
   
    printf("[%d R$:%1.2f %s %d/%d/%d]\n", raiz->localizador,raiz->preco,raiz->destino,raiz->dia,raiz->mes,raiz->ano);
    imprimir(raiz->esquerda, tab + 1);
}
void  imprimirReduzido(pass *raiz){
if (raiz == NULL) return;
    imprimirReduzido(raiz->direita);
    printf("[%d R$:%1.2f %s %d/%d/%d]\n", raiz->localizador,raiz->preco,raiz->destino,raiz->dia,raiz->mes,raiz->ano);
    imprimirReduzido(raiz->esquerda);         
}
void  limparTerminal(){
    system("cls");
    //system("cleaner");
}
int   menu(){
    printf("\n1 - Vender Passagem");
    printf("\n2 - Buscar por Brasil");
    printf("\n3 - Buscar por Argentina");
    printf("\n4 - Relatorio de voos e valor arrecadado");
    printf("\n5 - Combinar Arvores");
    printf("\n6 - Anos Anteriores:");
    printf("\n0 - Sair");
    printf("\n>");
    int op = 0;
    scanf("%d",&op);
    return op;
}
float precoTotal(pass *raiz) {
    if(raiz == NULL)return 0;    
    else return raiz->preco + precoTotal(raiz->esquerda) + precoTotal(raiz->direita);
}
int   tamanho(pass *raiz) {
    if(raiz == NULL) return 0; 
    else return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}
void  relatorio(pass *raiz ,char nome[]){
    printf("\n%s :Total de Voos:%d, valor arrecadado %1.2f\n",nome,tamanho(raiz),precoTotal(raiz));
}
pass *buscar_no(pass *node, int num) {
    if (node == NULL) return NULL;
    if (node->localizador == num)return node;
    if (node->localizador < num) return buscar_no(node->direita, num);
    else return buscar_no(node->esquerda, num);
}
anos *buscarAnos(anos *node, int num) {
        if (node == NULL) return NULL;
        if (node->ano == num)return node;
        if (node->ano < num) return buscarAnos(node->direita, num);
        else return buscarAnos(node->esquerda, num);
    }
int  gerarNumero(){
    int numero = rand()%100;
    if(buscar_no(raizBrasil,numero) == NULL && buscar_no(raizArgentina,numero) == NULL) return numero;  
    else gerarNumero();
}
int  inputDia(){
    int op = 0;
    printf("Dia:");
    scanf("%d",&op);
    return op;
}
int  inputMes(){
    int op = 0;
    printf("MES:");
    scanf("%d",&op);
    return op;
}
void destino(){
    printf("Destino:");
}

pass*inserir(pass *raiz,int localizador,char pais[],int ano = anoAtual,int mes = inputMes(),int dia = inputDia()){
    if(raiz == NULL) {
        pass *novo = (pass*) malloc(sizeof(pass));
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->localizador = localizador;
        novo->dia = dia;
        novo->mes = mes;
        novo->ano = anoAtual;
        strcpy(novo->destino,pais);
        if(strcmp(pais,"Brasil") == 0) novo->preco = preco_Argentina_Brasil;
        else novo->preco = preco_Brasil_Argentiva;
        return novo;
    }
    else{
        if(localizador < raiz->localizador) raiz->esquerda = inserir(raiz->esquerda,localizador,pais,ano,mes,dia);
        if(localizador > raiz->localizador) raiz->direita = inserir(raiz->direita,localizador,pais,ano,mes,dia);
    return raiz;
    }
}
anos*inserirAnos(anos *raiz,int ano,pass *nova){
    if(raiz == NULL) {
        anos *novo = (anos*) malloc(sizeof(anos));
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->ano = ano;
        novo->passagem = nova;
        anoAtual++;
        return novo;
    }
    else{
        if(ano < raiz->ano) raiz->esquerda = inserirAnos(raiz->esquerda,ano,nova);
        if(ano > raiz->ano) raiz->direita = inserirAnos(raiz->direita,ano,nova);
    return raiz;
    }
}
void vender(){
    int op = 0;
        do{
        printf("Digite o destino");
        printf("\n1 - Brasil");
        printf("\n2 - Argentina");
        printf("\n0 - Sair\n>");
        scanf("%d",&op);
        switch (op){
            case 1:
                raizBrasil = inserir(raizBrasil,gerarNumero(),"Brasil");
                op = 0;
            break;
            case 2:
                raizArgentina = inserir(raizArgentina,gerarNumero(),"Argentina");
                op = 0;
            break;
        }
        }while(op!=0);
}
pass*remover(pass *raiz, int chave) {
    if(raiz == NULL) return NULL;
     else { // procura o nó a remover
        if(raiz->localizador == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
               terceira= inserir(terceira,raiz->localizador,raiz->destino,raiz->ano,raiz->mes,raiz->dia);
                free(raiz);
               // printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    pass *aux = raiz->esquerda;
                    while(aux->direita != NULL) aux = aux->direita;
                    raiz->localizador = aux->localizador;
                    terceira= inserir(terceira,raiz->localizador,raiz->destino,raiz->ano,raiz->mes,raiz->dia);
                    aux->localizador = chave;
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
                else{
                    pass *aux;
                    if(raiz->esquerda != NULL) aux = raiz->esquerda;
                    else aux = raiz->direita;
                    terceira= inserir(terceira,raiz->localizador,raiz->destino,raiz->ano,raiz->mes,raiz->dia);
                    free(raiz);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->localizador)  raiz->esquerda = remover(raiz->esquerda, chave);
            else raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}
void combinarArvores(){
        while(raizBrasil != NULL) raizBrasil = remover(raizBrasil,raizBrasil->localizador);
        while(raizArgentina != NULL) raizArgentina = remover(raizArgentina,raizArgentina->localizador);
        anosAnteriores = inserirAnos(anosAnteriores,anoAtual,terceira);
       terceira = NULL;
       //imprimirReduzido(terceira);
        
}
void pesquisar(){
        int pesq = 0;
        printf("\nDigite o ano:");
        scanf("%d",&pesq);
        anos *temp = buscarAnos(anosAnteriores,pesq);
        if(temp != NULL){
            relatorio(temp->passagem,"");
            imprimirReduzido(temp->passagem);
        }else{
            printf("\nNao encontrado.\n");
        }
       
    }
int main(){
    srand(time(NULL));
    int op = 0;
    do{       
    op = menu();
        switch(op){
            case 1:
                limparTerminal();
                vender();
                break;
            case 2:
                limparTerminal();
                imprimirReduzido(raizBrasil);
                break;
            case 3:
                limparTerminal();
                imprimirReduzido(raizArgentina);
                break;
             case 4:
                limparTerminal();
                relatorio(raizBrasil,"Brasil");
                relatorio(raizArgentina,"Argentina");
                break;
             case 5:
                limparTerminal();
                combinarArvores();
                break;
             case 6:
                limparTerminal();
                pesquisar();
                break;  
            case 0:
                limparTerminal();
                printf("Sistema Encerrado!");
                break;
        }

    }while (op != 0);
    return 0;
}
