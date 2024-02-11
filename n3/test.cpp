#pragma region objetos
    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    #include<strings.h>
     float preco_Brasil_Argentiva = 3121;
     float preco_Agerntiva_Brasil = 2869;
     enum Destino {Brasil,Agerntina};
    typedef struct {
        int dia, mes,ano;
    }Data;
    typedef struct pass{
        int localizador;
        Data data;
        char destino[20];
        float preco;
        pass *esquerda, *direita;
    }Passagem;
    typedef struct anos{
        int ano;
        pass *brasil;
        pass *argentina;
        anos *esquerda,*direita;
    }Anos;
    Passagem *raizArgentina;
    Passagem *raizBrasil;
    Passagem *terceira;
    Anos *anosAnteriores;
#pragma endregion
#pragma region métodos
    void limparTerminal(){
        system("cls");
        //system("clear");
    }
    pass *novo(int localizador,Destino dest){
    pass *novo = (pass*) malloc(sizeof(pass));
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->localizador = localizador;
   // novo->preco = preco;
   if(dest == Brasil) {
    novo->preco = preco_Agerntiva_Brasil;
    strcpy(novo->destino,"Brasil");
   }else{
    novo->preco = preco_Brasil_Argentiva;
    strcpy(novo->destino,"Argentina");
   }
   
    return novo;
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
    int tamanho(pass *raiz) {
        if(raiz == NULL) return 0; 
        else return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
    float precoTotal(pass *raiz) {
        if(raiz == NULL)return 0;    
        else return raiz->preco + precoTotal(raiz->esquerda) + precoTotal(raiz->direita);
    }
    void relatoio(){
        printf("\n %d Voos  para o Brasil, valor total arrecadado %1.2f",tamanho(raizBrasil),precoTotal(raizBrasil));
        printf("\n %d Voos  para o Argentina, valor total arrecadado %1.2f\n",tamanho(raizArgentina),precoTotal(raizArgentina));
    }
    pass *inserir(pass *raiz,int numero,Destino destino){
    if(raiz == NULL) return novo(numero,destino);
    else{
        if(numero < raiz->localizador) raiz->esquerda = inserir(raiz->esquerda,numero,destino);
        if(numero > raiz->localizador) raiz->direita = inserir(raiz->direita,numero,destino);
    return raiz;
    }
}
    int  gerarNumero(){
    int numero = rand()%100;
    if(buscar_no(raizBrasil,numero) == NULL && buscar_no(raizArgentina,numero) == NULL) return numero;
    //NÚMERO NÃO EXISTE  
    else gerarNumero();
}
    void vender(){
    int op = 0;
    do{
    limparTerminal();
    printf("Digite o destino");
    printf("\n1 - Brasil");
    printf("\n2 - Argentina");
    printf("\n0 - Sair\n >");
    scanf("%d",&op);
    switch (op){
        case 1:
           raizBrasil = inserir(raizBrasil,gerarNumero(),Brasil);
        op = 0;
        break;
        case 2:
           raizArgentina = inserir(raizArgentina,gerarNumero(),Agerntina);
        op = 0;
        break;
    }
    }while(op!=0);
}
    void imprimir(pass *node, int tab = 0) {
        if (node == NULL) return;
        imprimir(node->direita, tab + 1);
        for (int i = 0; i < tab; i++) printf("\t");
        printf("[%d R$:%1.2f %s]\n", node->localizador,node->preco,node->destino);
        imprimir(node->esquerda, tab + 1);
}
    void imprimirReduzido(pass *raiz){
        if (raiz == NULL) return;
        imprimirReduzido(raiz->direita);
         printf("[%d R$:%1.2f %s]\n", raiz->localizador,raiz->preco,raiz->destino);
         imprimirReduzido(raiz->esquerda);
    }
    int  menu(){
    printf("\n1 - Vender Passagem");
    printf("\n2 - Buscar por Brasil");
    printf("\n3 - Buscar por Argentina");
    printf("\n4 - Relatorio de voos valor arrecadado");
    printf("\n5 - Combina  duas Arvores");
    printf("\n6 - Pesquisa Ano:");
    printf("\n0 - Sair");
    printf("\n>");
    int op = 0;
    scanf("%d",&op);
    return op;
    }
    anos *combinarArvores(anos *raiz,int ano){
        if(raiz == NULL){
        Anos *novo  = (Anos*)malloc(sizeof(Anos));
        novo->brasil = raizBrasil;
        novo->argentina = raizArgentina;
        novo->ano = ano;
        novo->esquerda = NULL;
        novo->direita = NULL;
        raizArgentina = NULL;
        raizBrasil = NULL;
        }else{
            if(ano < raiz->ano) raiz->esquerda = combinarArvores(raiz->esquerda,ano);  
            if (ano > raiz->ano) raiz->direita = combinarArvores(raiz->direita,ano);
            return raiz;
        }
    }
    void pesquisar(){
        int pesq = 0;
        printf("\nDigite o ano:");
        scanf("%d",&pesq);
        anos *temp = buscarAnos(anosAnteriores,pesq);
        if(temp != NULL){
            imprimirReduzido(temp->brasil);
            imprimirReduzido(temp->argentina);
        }else{
            printf("\nNao Encontrado!\n");
        }
       
    }
    
    pass *remover(pass *raiz,int valor){
        pass *aux = raiz;
        if(raiz == NULL) return aux; //raiz vazia  
        else{
            if (raiz->localizador == valor){
                if(raiz->esquerda == NULL && raiz->direita == NULL){
                    
                    return NULL;
                }
            }else{
                if (valor < raiz->localizador)
                {
                 raiz->esquerda = remover(raiz->esquerda,valor);
                }else{
                  raiz->direita = remover(raiz->direita,valor);
                }
                return raiz;
            }
            


        }
    }

#pragma endregion
int main(){
   int op = 0, anoAtual = 2022;
    
   int valor  = 0;
    do{       
        op = menu();
        switch(op){
            case 1:
                vender();
                break;
            case 2:
                limparTerminal();
                imprimir(raizBrasil);
                //imprimirReduzido(raizBrasil);
                break;
            case 3:
                limparTerminal();
               // imprimirReduzido(raizArgentina);
                imprimir(raizArgentina);
                break;
             case 4:
                limparTerminal();
                relatoio();
                break;
             case 5:
                limparTerminal();
                if(raizBrasil != NULL || raizArgentina != NULL){
                    anosAnteriores = combinarArvores(anosAnteriores,anoAtual);
                    printf("Arvore Consolidada no ano de %d",anoAtual);
                    anoAtual++;
                }
              
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