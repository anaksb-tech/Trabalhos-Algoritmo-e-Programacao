Leia um número inteiro k com 3 a 10 dígitos (zeros à esquerda não contam).
Em seguida, leia operações repetidamente e aplique-as sobre k até receber o
comando de encerramento. Após cada operação, exiba o valor atualizado de k.

Operações disponíveis (aceitas em maiúscula ou minúscula):
- D n → rotaciona k à direita em n dígitos (n > 0)
- E n → rotaciona k à esquerda em n dígitos (n > 0)
- I n → insere o dígito n no início de k, descartando o dígito mais à direita (0 ≤ n ≤ 9)
- F n → insere o dígito n no fim de k, descartando o dígito mais à esquerda (0 ≤ n ≤ 9)
- T → encerra o programa

Restrições importantes:
- O tipo de k deve ser long long int (%lld)
- Se k não tiver entre 3 e 10 dígitos, exibir erro e pedir novamente
- Ao imprimir k, exibir no mínimo 3 dígitos (ex: 7 → "007"), sem ultrapassar
  a quantidade de dígitos original
- Se n estiver fora das restrições de cada operação, exibir erro e não executar
- Se a operação for inválida, exibir mensagem de erro
- Não usar vetores, matrizes ou structs — apenas variáveis simples
- Não usar variáveis globais

Estrutura obrigatória: criar uma sub-rotina para cada uma das 4 operações (D, E, I, F).
Cada sub-rotina deve:
- Receber o número por referência e o valor de n
- Validar n internamente e retornar 1 se executou com sucesso, 0 caso contrário
- Não realizar nenhuma leitura ou saída de dados

Toda entrada e saída deve estar apenas no main. Nenhuma outra função auxiliar
pode ser criada além das quatro sub-rotinas e das funções scanf, printf, fflush
e funções de math.h e locale.h.
