#include <iostream>
#include <vector>

using namespace std;

// ** Commands ** //
//cout = saída no terminal
//<< = envia algo para o cout
//endl = pula para a próxima linha
//.size() - Retorna o número de elementos em um vetor ou string.

vector<int> buildPrefixSum(const vector<int>& expenses) {
    vector<int> prefix(expenses.size() + 1, 0); //Cria um vetor zerado (limpo) com uma posicao a mais.

    for (int i = 0; i < static_cast<int>(expenses.size()); ++i) { 
        // prefix[i + 1] garante que a posição zero se mantenha zerada, e o valor acumulado começa a ser preenchido a partir da posição 1.
        prefix[i + 1] = prefix[i] + expenses[i]; 
    }
    return prefix;
}

int rangeSum(const vector<int>& prefix, int left, int right) {
    // Soma de nums[left..right]:
    // removemos do acumulado ate right tudo que veio antes de left.
    return prefix[right + 1] - prefix[left];
}

/*
                            *Enunciado*
                ## Análise de Gastos por Período ##
Você trabalha em um sistema financeiro que registra os gastos diários de um usuário. 
Cada posição do array representa o total gasto em um dia.

Dado um array expenses, onde expenses[i] representa o gasto no dia i, 
implemente uma estrutura que permita responder rapidamente qual foi o total gasto entre dois dias startDay e endDay, inclusive.

Como o sistema pode receber muitas consultas para o mesmo histórico de gastos, 
sua solução deve fazer um pré-processamento inicial e depois responder cada consulta em O(1).
*/

int main() {
    vector<int> expenses = {120, 80, 45, 200, 60, 30, 90};

    vector<int> prefix = buildPrefixSum(expenses); // Primeiro pre-processamos o array uma vez.

    //parametros para indicar a posição inicial (Dia 1 - left) e a final (Dia 3 - right) do intervalo que queremos somar.
    int left = 1;
    int right = 3;

    // Depois cada consulta de intervalo pode ser respondida em O(1).
    int sum = rangeSum(prefix, left, right);

    cout << "Prefix Sum: ";
    for (int value : prefix) {
        cout << value << " ";
    }
    cout << endl;
    cout << "Soma do intervalo [" << left << ", " << right << "]: " << sum << endl;
    return 0;
}
