#include <stdio.h>
#include <stdlib.h>


int m = 262139;

#define hash(v, m) (v % m) 

// Com um número aleatório
// Transforma o v em unsigned int
// Essa macro é utlizada se m não for primo
#define hosh(v, m) (618033*(unsigned)v) % m)

typedef struct Item
{
    int chave;
    // endereço 1 e endereço 2
    long e1, e2;
    long elemento;
} Item;

// Como em um dos números proibidos existe 0, então tive
// que colocar -1 como a menor variável
Item NULLItem = {-1, 0, 0, 0}; 

#define Key(x) (x.chave)
#define less(a, b) (Key(a) < Key(b))

// pergunta se o elemento é null ou não
#define null(A) (Key(ht[A]) == Key(NULLItem))

// M: tamanho da tabela hash
static int N, M;

// ht: hashTable
// Item *ht: ponteiro de hashTable
static Item *ht; 

// Inicializa a tabela hash
// @param max: número máximo de elementos que vai entrar na tabela hash
void HTInit(int max) {
    int i;
    // M: quantidade de elementos
    N = 0, M = 2*max;
    ht = malloc(sizeof(Item)*M);
    for(i = 0; i < M; i++) {
        ht[i] = NULLItem;
    }
};

int HTcount() { return N;};

// Inserir o elemento na tabela hash
// Nessa função foi utilizado 'linear probing' de um em um
// @param item: Uma cópia do tipo item
void HTinsert(Item item) {
    int value = Key(item);
    
    // Sempre calcular a hash a partir da chave
    // Se fosse uma string, teria que utilizar a hash universal
    int i = hash(value, m);
    
    // Como está sendo colocado várias vezes elementos aqui
    // vai acabar causando uma colisão.
    //
    // ` ht[i] = item;`  <-- Essa forma não é o suficiente
    //
    // Pode ser necessário colocar outra condição invés desse null
    // denpendendo da questão.
    //
    // Esse loop serve para encontrar uma posição da direita
    // que esteja vazio. Esse loop também faz a volta no vetor,
    // quando passa do limite utiliza o módulo de M.
    while(Key(ht[i]) >= 0) {
        // Coloca a hash em uma posição do lado
        // Esse M serve para dar a volta no vetor
        i = (i + 1)%M;
    }
    
    // Insere o elemento na tabela hash
    ht[i] = item;
    // Quantidade de elementos na estrutura
    N++;
}

// Realiza uma busca na tabela hash
// Pesquisa se uma chave específica está na tabela hash,
// se estiver retorna o item equivalente
Item HTsearch(int value) {
    int i = hash(value, m);
    while(Key(ht[i]) >= 0) {
        if(value == Key(ht[i])) {
            return ht[i];
        }
        else {
            i = (i + 1)%M;
        }
    }
}

int main(void) {
    HTInit(262139);
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        Item item = { t, 0 , 0, 0};
        HTinsert(item);
    }
    int c;
    while(scanf("%d", &c) == 1) {
        Item value_in_hash = HTsearch(c);
        //printf("Key(HTsearch(c)): %d\n", Key(value_in_hash) );
        if(Key(value_in_hash) == c) {
            printf("sim\n");
        }
        else if(Key(value_in_hash) == 0) {
            printf("nao\n");
        }
        else if(Key(value_in_hash) != c) {
            printf("nao\n");
        }
    }
    return 0;
}

