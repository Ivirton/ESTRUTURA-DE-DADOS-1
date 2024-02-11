#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum nivelPrioridade {emergencia,urgencia,eletivo};
int temp = 0;
typedef struct pessoa{
    char nome[30];
    char cpf[11];
    nivelPrioridade prioridade;
}Pessoa;
typedef struct fila{
    Pessoa pessoa;
    fila *proximo;
}Fila;
Fila *filaUrgencia = NULL, *filaEmergencia = NULL, *filaEletiva = NULL,*filaAtendidos = NULL;
int tamEmergencia = 0;int tamUrgencia = 0;int tamEletivo = 0;
void limparTerminal(){
		system("clear");
   // system("cls");
    
}
void mostraQuantidade(){
    
    printf("EMERGENCIA:%d",tamEmergencia);
    printf(" URGENCIA:%d",tamUrgencia);
    printf(" ELETIVO:%d\n",tamEletivo);
    printf("---------------------------------\n");
}
void mostraDadosPessoa(Fila *fila){
    printf("Nome: %s",fila->pessoa.nome);
    printf("\tCPF: %s\n",fila->pessoa.cpf);
}
void imprimirFila(Fila *fila){
    if(fila == NULL){
        printf("Fila vazia!");
        return;
    }
    while (fila){
        mostraDadosPessoa(fila);
        fila = fila->proximo;
    }
}
void imprimirFilas(){
    
    printf("\n-------------EMERGENCIA----------\n");
    imprimirFila(filaEmergencia);
    printf("\n-------------URGENCIA------------\n");
    imprimirFila(filaUrgencia);
    printf("\n-------------ELETIVA-------------\n");
    imprimirFila(filaEletiva);
    printf("\n-------------ATENDIDOS-----------\n");
    
    imprimirFila(filaAtendidos);
		printf("\n");
    printf("\n---------------------------------\n");
	mostraQuantidade();
}
Fila *ultimoDaFila(Fila *fila){
    while(fila && fila->proximo) fila = fila->proximo;
    return fila;
}
void adicionarPessoaFila(Fila **fila,Fila *elemento){
     elemento->proximo = NULL;
    if(*fila == NULL){
        *fila = elemento;
    }else ultimoDaFila(*fila)->proximo = elemento;
}
fila *enfileirar(char nome[],char cpf[],nivelPrioridade prioridade){
    Fila *novo = (Fila*) malloc(sizeof(fila));
    strcpy(novo->pessoa.nome,nome);
    strcpy(novo->pessoa.cpf,cpf);
    novo->pessoa.prioridade = prioridade;
    if(prioridade == emergencia){
        adicionarPessoaFila(&filaEmergencia,novo);
    }else if(prioridade == urgencia){
        adicionarPessoaFila(&filaUrgencia,novo);
    }else{
         adicionarPessoaFila(&filaEletiva,novo);
    }
    return novo;
}
void cadastrarPessoa(){
    
    char nome[30],cpf[11];
    printf("\nDigite Nome:");
    scanf("%s",nome);
    printf("Digite O CPF:");
    scanf(" %s",cpf);
    int op = 0;
		printf("\nNivel de prioridade\n");
    printf("\n[0] - Voltar \n[1] - Emergencia \n[2] - Urgencia \n[3] - Eletivo \n > ");
    scanf(" %d",&op);
    switch(op){
        case 1:
            enfileirar(nome,cpf,emergencia);
        break;
        case 2:
            enfileirar(nome,cpf,urgencia);
        break;
        case 3:
            enfileirar(nome,cpf,eletivo);
        break;
    }
    
}
Fila *desenfileirar(Fila **fila){
    Fila* remover = NULL;
    if(*fila != NULL){
        remover = *fila;
        *fila = remover->proximo;
    }
    remover->proximo = NULL;
    return remover;   
}
void next(){
    Fila *atendido = NULL;
    if(filaEmergencia != NULL){
        atendido = desenfileirar(&filaEmergencia);
        adicionarPessoaFila(&filaAtendidos,atendido);
        tamEmergencia++;
        return;
    }
    if(filaUrgencia != NULL && temp != 3){
        atendido = desenfileirar(&filaUrgencia);
        adicionarPessoaFila(&filaAtendidos,atendido);
        tamUrgencia++;
        temp++;
        return;
    }if(filaEletiva != NULL){
        atendido = desenfileirar(&filaEletiva);
        adicionarPessoaFila(&filaAtendidos,atendido);
        tamEletivo++;
        temp = 0;
    }else{
        printf("\n fila vazia\n");
    }
}
int buscarCpf(char cpf[]){
	int cont = -1;
	int temp1 = 0;
	Fila *auxEmergencia = filaEmergencia;
	Fila *auxUrgencia = filaUrgencia;
	Fila *auxEletiva = filaEletiva;
	while(auxEmergencia != NULL ){
		cont++;
		if(strcmp(auxEmergencia->pessoa.cpf, cpf) == 0){
			return cont; 
		}
		auxEmergencia = auxEmergencia->proximo;
	} 
	
	while(auxUrgencia != NULL  && temp1 != 3){
		cont++;
		if(strcmp(auxUrgencia->pessoa.cpf, cpf) == 0){
			
			return cont; 
		}
		temp1++;
		auxUrgencia = auxUrgencia->proximo;
	}

	while(auxEletiva != NULL ){
		cont++;
		temp1 = 0;
		if(strcmp(auxEletiva->pessoa.cpf, cpf) == 0){
			return cont; 
		}
		
		auxUrgencia = auxUrgencia->proximo;
	}
	return -1;
}
void menu(){
  int op = 0;
	limparTerminal();
	imprimirFilas();
  do{
    
    
    printf("\n0 - Sair\n");
    printf("1 - Cadastrar Paciente\n");
    printf("2 - Imprimir Filas\n");
    printf("3 - proximo(Next)\n");
    printf("4 - Buscar por CPF quantos na frente\n");
    printf("Aguardando > ");
    scanf("%d",&op);
    switch(op){
        case 0:
           	limparTerminal();
            printf("Sistema encerrado!");
            system("pause");
            break;
        case 1:
            
            cadastrarPessoa();
            break;
        case 2:
           limparTerminal();
           imprimirFilas();
            break;
        case 3:
            next();
						limparTerminal();
						imprimirFilas();
            break;
			case 4:
						limparTerminal();
           	printf("\nInforme o CPF: ");
           	char cpf[11];
						scanf("%s",cpf);
						printf("%d pessoas na frente \n",buscarCpf(cpf));
						imprimirFilas();
            break;
        default:{
            printf("Digite outra opção!\n");
        }
    }
    }while(op != 0);
}
int  main(){
    enfileirar("IVIRTON","01",emergencia);
    enfileirar("NEYMAR","02",emergencia);
    enfileirar("LULA","03",emergencia);
    enfileirar("ELDA","04",emergencia);
    enfileirar("VICTOR","05",urgencia);
    enfileirar("DOUGLAS","06",urgencia);
    enfileirar("FELIPE","07",urgencia);
    enfileirar("JORGE","08",urgencia);
    enfileirar("CIRO","09",urgencia);
    enfileirar("PEDRO","10",eletivo);
    enfileirar("WILLIAN","11",eletivo);
    enfileirar("MARIA","12",eletivo);
    enfileirar("HERRY","13",eletivo);
    enfileirar("CARLOS","14",urgencia);
    limparTerminal();
    menu();
    return 0; 
}