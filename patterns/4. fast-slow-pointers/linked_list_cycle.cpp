#include <iostream>

using namespace std;

// ** Commands ** //
//cout = saída no terminal
//<< = envia algo para o cout
//endl = pula para a próxima linha

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int nodeValue) {
        value = nodeValue;
        next = nullptr;
    }
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // Anda 1 passo por vez.
        fast = fast->next->next; // Anda 2 passos por vez.

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

/*
                            *Enunciado*
                ## Detectar Ciclo em uma Lista Ligada ##

Voce trabalha em um sistema que processa uma sequencia de eventos encadeados.
Cada evento aponta para o proximo evento da fila.

Por causa de uma falha de integracao, pode acontecer de um evento apontar para
um evento anterior, criando um ciclo infinito.

Dada a cabeca de uma linked list, verifique se existe um ciclo.

Exemplo com ciclo:
1 -> 2 -> 3 -> 4
     ^         |
     |_________|

Resposta esperada:
true

Como a estrutura pode ter um ciclo, nao podemos apenas percorrer ate encontrar
nullptr. Usamos Fast & Slow Pointers:

slow anda 1 passo por vez.
fast anda 2 passos por vez.

Se existir ciclo, fast eventualmente alcanca slow.
Se nao existir ciclo, fast chega em nullptr.
*/

int main() {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Cria um ciclo voltando para o node 2.

    bool result = hasCycle(first);

    cout << "Fast & Slow Pointers - Lista possui ciclo: ";
    cout << (result ? "true" : "false") << endl;

    fourth->next = nullptr;
    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
