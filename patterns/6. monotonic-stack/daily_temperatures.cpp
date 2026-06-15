#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// ** Commands ** //
//cout = saída no terminal
//<< = envia algo para o cout
//endl = pula para a próxima linha
//.empty() - Verifica se a pilha está vazia.

//.push() - Adiciona um elemento no topo da pilha.
//.top() - Retorna o elemento do topo da pilha sem removê-lo.
//.pop() - Remove o elemento do topo da pilha.

//vector<int> - array
//stack<int> - pilha (stack)

vector<int> dailyTemperatures(const vector<int>& temperatures) {
    vector<int> answer(temperatures.size(), 0);
    stack<int> pendingDays;

    for (int currentDay = 0; currentDay < static_cast<int>(temperatures.size()); ++currentDay) {
        //enquanto a pilha nao estiver vazia e a temperatura atual for maior que a temperatura do topo da pilha, encontramos a resposta para o dia do topo da pilha.
        while (!pendingDays.empty() && temperatures[currentDay] > temperatures[pendingDays.top()]) { 
            int previousDay = pendingDays.top(); //pegamos o indice do dia anterior que ainda nao encontrou uma temperatura maior.
            pendingDays.pop();                   //removemos esse dia da pilha, pois agora encontramos a resposta para ele.
            
            //calculamos quantos dias se passaram entre o dia anterior e o dia atual, que é a resposta para o dia anterior.
            answer[previousDay] = currentDay - previousDay; 
        }

        // Guarda o indice do dia atual enquanto ainda nao encontramos um dia mais quente.
        pendingDays.push(currentDay);
    }

    return answer;
}

void printVector(const vector<int>& values) {
    for (int value : values) {
        cout << value << " ";
    }

    cout << endl;
}

/*
                            *Enunciado*
                ## Proxima Temperatura Mais Quente ##

Voce trabalha em um sistema de previsao do tempo. Cada posicao do array
temperatures representa a temperatura prevista para um dia.

Dado um array temperatures, retorne um novo array answer onde answer[i] indica
quantos dias e preciso esperar depois do dia i para encontrar uma temperatura
maior.

Se nao existir um dia futuro com temperatura maior, answer[i] deve ser 0.

Exemplo:
temperatures = {73, 74, 75, 71, 69, 72, 76, 73}

Resposta esperada:
{1, 1, 4, 2, 1, 1, 0, 0}

Para resolver, usamos uma Monotonic Stack.

A pilha guarda indices de dias que ainda nao encontraram uma temperatura maior.
Enquanto a temperatura atual for maior que a temperatura do topo da pilha,
encontramos a resposta daquele dia anterior.

Cada indice entra e sai da pilha no maximo uma vez, entao a solucao e O(n).
*/

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> answer = dailyTemperatures(temperatures);

    cout << "Temperaturas: ";
    printVector(temperatures);

    cout << "Dias ate uma temperatura maior: ";
    printVector(answer);

    return 0;
}
