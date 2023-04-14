
#include <iostream>
#include <locale.h>
#include <locale.h>
#include <string>
using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;
public:
    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }
    Data() {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }
    void setDia(int dia) {
        this->dia = dia;
    }
    void setMes(int mes) {
        this->mes = mes;
    }
    void setAno(int ano) {
        this->ano = ano;
    }
    int getDia() {
        return this->dia;
    }
    int getMes() {
        return this->mes;
    }
    int getAno() {
        return this->ano;
    }
    string getData()
    {
        return to_string(this->dia) + "/" +
            to_string(this->mes) + "/" +
            to_string(this->ano);
    }
};

class Contato
{
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;
public:
    Contato(string email, string nome, string telefone, Data dtnasc) {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }
    Contato() {
        this->email = "";
        this->nome = "";
        this->telefone = "";
        this->dtnasc = Data();
    }
    void setEmail(string email) {
        this->email = email;
    }
    void setNome(string nome) {
        this->nome = nome;
    }
    void setTelefone(string telefone) {
        this->telefone = telefone;
    }
    void setDataNascimento(int dia, int mes, int ano) {
        this->dtnasc.setAno(ano);
        this->dtnasc.setMes(mes);
        this->dtnasc.setDia(dia);
    }
    string getEmail() {
        return this->email;
    }
    string getNome() {
        return this->nome;
    }
    string getTelefone() {
        return this->telefone;
    }
    Data getDataNascimento() {
        return this->dtnasc;
    }
    int idade() {
        // calcula a idade com base na data de nascimento
        // considerando que a data atual � 12/04/2023
        int idade = 2023 - this->dtnasc.getAno();
        if (this->dtnasc.getMes() > 4 || (this->dtnasc.getMes() == 4 && this->dtnasc.getDia() > 12)) {
            idade--;
        }
        return idade;
    }
    void exibeContato() {
        cout << "|Nome: " << this->nome << endl;
        cout << "|E-mail: " << this->email << endl;
        cout << "|Telefone: " << this->telefone << endl;
        cout << "|Data de Nascimento: " << this->dtnasc.getData() << endl;
        cout << "|---------------------------------" << endl;
        cout << "|Idade: " << this->idade() << " anos" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Contato contatos[5];

    for (int i = 0; i < 5; i++) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Digite o nome do contato " << i + 1 << ": ";
        getline(cin, nome);

        cout << "Digite o e-mail do contato " << i + 1 << ": ";
        getline(cin, email);

        cout << "Digite o telefone do contato " << i + 1 << ": ";
        getline(cin, telefone);

        cout << "Digite a data de nascimento do contato " << i + 1 << " (DD MM AAAA): ";
        cin >> dia >> mes >> ano;
        cin.ignore();

        contatos[i].setNome(nome);
        contatos[i].setEmail(email);
        contatos[i].setTelefone(telefone);
        contatos[i].setDataNascimento(dia, mes, ano);
    }

    cout << "Lista de Contatos:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "----------------------------------" << endl;
        contatos[i].exibeContato();
        cout << "----------------------------------" << endl;
    }

    return 0;
}


// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depura��o
// Depurar programa: F5 ou menu Depurar > Iniciar Depura��o

// Dicas para Come�ar: 
//   1. Use a janela do Gerenciador de Solu��es para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do c�digo-fonte
//   3. Use a janela de Sa�da para ver mensagens de sa�da do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de c�digo, ou Projeto > Adicionar Item Existente para adicionar arquivos de c�digo existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, v� para Arquivo > Abrir > Projeto e selecione o arquivo. sln