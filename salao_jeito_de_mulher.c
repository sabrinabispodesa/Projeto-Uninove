#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

struct produto {
    char nome[50];
    float preco;
    int estoque;
};

struct cliente {
    char nome[50];
    char telefone[11];
    char cpf[11];
};

struct profissional {
    // não tenho certeza desse struct ainda
    char nome[50];
    char telefone[11];
    char cpf[11];
};

struct servico {
    char nome[50];
    float valor;
    int num_de_profissionais;
    char nome_do_profissional[50][50];
    // struct profissional pro;
}; 

// escolher qual profissional -> em serviço (função?)
// escolher os produtos cadastrados
struct agendamento {
    struct cliente cli;
    struct servico serv;
    struct produto pro[10];
};

int cadastrar_produto(struct produto pro[]);
void escolher_produto(struct produto pro[], int tamanho);
void cadastrar_cliente();
bool validaCPF(int num[]);
void cadastrar_servico();


int main(){
    int escolha;
    int tamanho;
    struct produto produto[100];

    printf("\n----------------------- SALÃO DE BELEZA JEITO DE MULHER -----------------------\n");
    printf("\n 1 - CADASTRAR CLIENTE");
    printf("\n 2 - CADASTRAR PRODUTO");
    printf("\n 3 - CADASTRAR SERVIÇO");
   // printf("\n 4 - COMPRAR PRODUTO");

    printf("\n\nQual operação deseja executar: ");
    scanf("%d", &escolha);

    if (escolha == 1){
    cadastrar_cliente();
    } 
    else if (escolha == 2){
    cadastrar_produto(produto); 
    }
    else if (escolha == 3){
    cadastrar_servico();
    }
    else if(escolha == 4){
    tamanho =  cadastrar_produto(produto); 
    escolher_produto(produto, tamanho);
    }
   return 0;
}

bool validaCPF(int num[]){
        int i;
        int j;
        int soma = 0;
        int resto;
        int dev1;
        int dev2;

        for (int i = 1; i < 11; i++) {
        if (num[i] != num[0]) {
        break;
    }
        if (i == 10) {
        return false;
    }
}

        // Digito verificador 1 do CPF
        j = 10;
        for (i = 0; i < 9; i++){
            soma = soma + num[i] * j;
            j = j - 1 ;
        }
        resto = soma % 11;

        if (resto < 2){
            dev1 = 0;
        } else {
            dev1 = 11 - resto;
        }
    
        // Digito verificador 2 do CPF
        j = 11;
        soma = 0;
        for (int i = 0; i < 10; i++){
        soma = soma + num[i] * j;
            j = j - 1;
        }
        resto = soma % 11;

        if(resto < 2){
            dev2 = 0;
        } else{
            dev2 = 11 - resto;
        } 
        if ((num[9] == dev1) && (num[10] == dev2)){
            return  true;
        } else {
            return false;
        }
    }

void cadastrar_cliente(){
    int tamanho_da_array;
    int digito1;
    int digito2;
    int cpf_digitos[11];
    bool resultado;
    printf("\n=========================== Cadastro de Cliente ===========================\n");

    printf("\nQuantos clientes deseja cadastrar? ");
    scanf("%d", &tamanho_da_array);

    struct cliente clie[tamanho_da_array];

    for (int i = 0; i < tamanho_da_array; i++){
        getchar();
        printf("\nDigite nome do cliente: ");
        fgets(clie[i].nome, sizeof(clie[i].nome),stdin);
        clie[i].nome[strcspn(clie[i].nome, "\n")] = '\0';

        printf("\nDigite o número de telefone:  ");
        scanf("%s", clie[i].telefone);

  do {
        printf("\nDigite o CPF: ");
        scanf("%s", clie[i].cpf);

        for (int j = 0; j < 11; j++){
        cpf_digitos[j] = clie[i].cpf[j] - '0';

        }
        resultado = validaCPF(cpf_digitos);
    }
    while (resultado != true);
    
    }

    printf("\n---------------------- Clientes Cadastrados -------------------------\n");
    for (int i = 0; i < tamanho_da_array; i++){
        printf("\nCliente %d", i+1);
        printf("\nNome: %s", clie[i].nome);
        printf("\nTelefone: (%c%c) %c%c%c%c%c-%c%c%c%c", clie[i].telefone[0], clie[i].telefone[1]
                                                     , clie[i].telefone[2], clie[i].telefone[3], clie[i].telefone[4], clie[i].telefone[5], clie[i].telefone[6]
                                                     , clie[i].telefone[7], clie[i].telefone[8], clie[i].telefone[9], clie[i].telefone[10]);
        printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n", clie[i].cpf[0], clie[i].cpf[1], clie[i].cpf[2]
                                                 , clie[i].cpf[3], clie[i].cpf[4], clie[i].cpf[5]
                                                 , clie[i].cpf[6], clie[i].cpf[7], clie[i].cpf[8]
                                                 , clie[i].cpf[9], clie[i].cpf[10]);
    }
}

int cadastrar_produto(struct produto pro[]){
int tamanho;
    printf("\n=========================== Cadastro de Produto ===========================\n");
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &tamanho);

    for (int i = 0; i < tamanho; i++){
    getchar();
    printf("\nDigite o nome do produto %d: ", i + 1);
    fgets(pro[i].nome, sizeof(pro[i].nome), stdin);
    pro[i].nome[strcspn(pro[i].nome, "\n")] = '\0';


    printf("\nDigite o valor do produto %d: R$ ", i + 1);
    scanf("%f", &pro[i].preco);

    printf("\nDigite a quantida do estoque: ");
    scanf("%d", &pro[i].estoque);
    }

    printf("\n---------------------- Produtos Cadastrados -------------------------\n");
    for(int i = 0; i < tamanho; i++){
    printf("\nProduto %d\n", i + 1);
    printf("Nome: %s\n", pro[i].nome);
    printf("Preço: R$%.2f\n", pro[i].preco);
    printf("Quantidade de %s no estoque: %d\n", pro[i].nome, pro[i].estoque);
}
    return tamanho;
}

void escolher_produto(struct produto pro[], int tamanho){
    int escolher_produto;
    int quantidade_de_produto;
    float valor_total = 0;
    int quer_adicionar_outro_produto;

    int produtos_escolhidos[100];
    int quantidade_de_produtos_escolhidos[100];
    int total_escolhidos = 0;


    printf("\n======================== Lista de Produtos ========================\n");
    
    for (int i = 0; i < tamanho; i ++){
        printf("\n%d - Nome do produto: %s", i + 1, pro[i].nome);
        printf("\n          Valor do produto: R$%.2f", pro[i].preco);
        printf("\n          Quantidade de %s no estoque: %d\n", pro[i].nome, pro[i].estoque);
    }

    printf("\n=================== Adicionar Produtos Para Compra ===================\n");
    
       
    do {
        printf("\nDigite o número do produto que deseja comprar: ");
        scanf ("%d", &escolher_produto);

        printf("\nQual a quantidade de %s você quer comprar? ", pro[escolher_produto - 1].nome);
        scanf("%d", &quantidade_de_produto);

        if(quantidade_de_produto > pro[escolher_produto - 1].estoque){
            printf("\nQuantidade Indisponível!");
            printf("\nDigite uma quantidade válida: ");
            scanf("%d", &quantidade_de_produto);
        } else if (quantidade_de_produto == 0){
            printf("\nQuantidade Indisponível!");
            printf("\nDigite uma quantidade válida: ");
            scanf("%d", &quantidade_de_produto);
        }

        produtos_escolhidos[total_escolhidos] = escolher_produto - 1;
        quantidade_de_produtos_escolhidos[total_escolhidos] = quantidade_de_produto;
        total_escolhidos++;
        
        valor_total = valor_total + pro[escolher_produto - 1].preco * quantidade_de_produto;
        
        printf("\nDeseja adicionar outro produto? ");
        printf("\n1 - SIM");
        printf("\n2 - NÃO");
        printf("\n----> ");
        scanf("%d",&quer_adicionar_outro_produto);
    }

    while (quer_adicionar_outro_produto == 1);
   
    printf("\n=================== Resumo da Compra ===================\n");
    for (int i = 0; i < tamanho; i++){
        printf("\n %d - Produto: %s", i + 1, pro[produtos_escolhidos[i]].nome);
        printf("\n     Valor por unidade: %.2f", pro[produtos_escolhidos[i]].preco);
        printf("\n     Quantidade: %d\n", quantidade_de_produtos_escolhidos[i]);
    }
     printf("\nValor total da compra: %.2f", valor_total);

}

void cadastrar_servico(){
    int quantidade_de_servico;
    printf("\n=========================== Cadastro de Serviço ===========================\n");
    printf("\nQuantos serviços deseja cadastrar? ");
    scanf("%d", &quantidade_de_servico);
    struct servico ser[quantidade_de_servico];

    getchar();
    for (int i = 0; i < quantidade_de_servico; i++){
        printf("\nDigite o nome do serviço %d: ", i + 1);
        fgets(ser[i].nome, sizeof(ser[i].nome), stdin);
        ser[i].nome[strcspn(ser[i].nome, "\n")] = '\0';

        printf("\nDigite o valor do serviço %d: R$ ", i + 1);
        scanf("%f", &ser[i].valor);
        

        printf("\nQuantos profissionais você deseja cadastrar para esse serviço? ");
        scanf("%d", &ser[i].num_de_profissionais);

    if (ser[i].num_de_profissionais == 0){
        printf("\nOpção inválida!");
        printf("\nDigite um número válido: ");
        scanf("%d", &ser[i].num_de_profissionais);
    }
    getchar();   

    for (int j = 0; j < ser[i].num_de_profissionais; j++){
        printf("\nDigite o nome do(a) profissional %d: ", j + 1);
        fgets(ser[i].nome_do_profissional[j], sizeof(ser[i].nome_do_profissional[j]), stdin);
    }
}

    printf("\n------------------------ Serviços e Profissionais Cadastrados ------------------------ \n");    
    for (int i = 0; i < quantidade_de_servico; i++){
        printf("\n\nNome do Serviço %d: %s", i + 1, ser[i].nome);
        printf("\nValor do Serviço %d: R$%.2f\n", i + 1, ser[i].valor);

            for (int j = 0; j < ser[i].num_de_profissionais; j++){
            printf("Profissional %d: %s", j + 1, ser[i].nome_do_profissional[j]);
        }
    }
}

 

// cadastrar o produtor, um produto é adicionado ao "carrinho" do cliente e a funçao estoque decide se está disponível ou não.
// agenda disponivel de cada profissional....
