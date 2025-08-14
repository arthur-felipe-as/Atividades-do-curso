#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct livro{
string nome;
string autor;
string genero; 
string localizacao;
int prateleira;
livro(){
    autor = "";
    genero = "";
    localizacao = "";
    nome = "";
    prateleira = 0;
};
};

class acervo{
int quant;
livro* livros;
public:
int retornar_quant();
string retornar_nome();
acervo();
void encontrar_livro(string nome);
void busca_autor(string autor);
void busca_genero(string genero);
void ler_arquivo(string arquivo);
void adicionar_livro(livro l);
void remover_livro(livro l);
void livros_em_local(string local);
void livros_em_prateleira(string local, int prat);
};

int acervo::retornar_quant(){
    return quant;
}

string acervo::retornar_nome(){
    return livros[0].nome;
}


acervo::acervo(){
    livro vazio;
    quant = 1;
    livros = new livro[quant]; 
}


void acervo::encontrar_livro(string nome){
    int encontrado = 0;
    for(int i = 0; i < nome.size(); i++){
        nome[i] = toupper(nome[i]);
    }
    for(int i = 0; i < quant; i++){
        if(livros[i].nome == nome){
            encontrado++;
            if(encontrado == 1){
                std::cout << "Livro encontrado em " << livros[i].localizacao << " na prateleira " << livros[i].prateleira << endl;
            }
            else{
                std::cout << "Outra edicao encontrada em " << livros[i].localizacao << " na prateleira " << livros[i].prateleira << endl;
            } 
        } 
    }
    if(encontrado == 0){
        std::cout << "Esse livro nao foi encontrado" << endl;
    }
}

void acervo::busca_autor(string nome){
    int encontrado = 0;
    for(int i = 0; i < nome.size(); i++){
        nome[i] = toupper(nome[i]);
    }
    for(int i = 0; i < quant; i++){
        if(livros[i].autor == nome){
            encontrado++;
            std::cout << livros[i].nome << " encontrado em " << livros[i].localizacao << " na prateleira " << livros[i].prateleira << endl;
        } 
    }
    if(encontrado == 0){
        std::cout << "Nao foram encontrados livros desse autor" << endl;
    }
}

void ler_arquivo(string arquivo){

}

void adicionar_livro(livro l){
    cout << "Digite o nome" << endl;
    cin.ignore();
    getline(cin, l.nome);
    for(int i = 0; i < l.nome.size(); i++){
        l.nome[i] = toupper(l.nome[i]);
    }
    std::cout << "Digite o nome do autor" << endl;
    std::cin.ignore();
    getline(std::cin, l.autor);
    for(int j = 0; j < l.autor.size(); j++){
        l.autor[j] = toupper(l.autor[j]);
    }
    cout << "Digite o genero do livro" << endl;
    cin.ignore();
    getline(cin, l.genero);
    cout << "Digite a localizacao" << endl;
    cin.ignore();
    getline(cin, l.localizacao);
    cout << "Digite a prateleira" << endl;
    cin >> l.prateleira;
    
}


int main(){
   acervo novo_acervo;
   int escolha = 0;

   cout << "O que deseja fazer?" << endl << "1: Adicionar Livro" << endl << "2: Remover Livro" << endl << "3: Encontrar Livros" << endl;
   cin >> escolha;
   if(escolha == 1){
    livro novo_livro;
    novo_acervo.adicionar_livro(novo_livro);

   }
   if(escolha == 3){
    cout << "Como deseja encontrar?" << endl;
    cout << "1: Nome" << endl << "2: Autor" << endl << "3: Genero" << endl;
    cin >> escolha;
    string nome;
    if(escolha == 1){
        cout << "Digite o nome do livro" << endl;
    cin.ignore();
    getline(cin, nome);
    novo_acervo.encontrar_livro(nome);
    }
    if(escolha == 2){
        cout << "Digite o nome do autor" << endl;
    } 
   }


   return 0;
}

