#include <iostream>
#include <cstring>
using namespace std;


struct livro{
string nome;
string autor;
int edicao;
string genero; 
int localizacao;
};

class acervo{
int* quant;
livro livros[quant];
public:
acervo();
void encontrar_livro_nome(string nome);
void encontrar_livro_autor(string autor);
void encontrar_genero(string genero);
void ler_arquivo(string arquivo);
void adicionar_livro(livro l);
void remover_livro(livro l);
};

void acervo::acervo(string arquivo){}







int main(){
   
}

