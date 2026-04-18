Leia uma matriz m de inteiros N x N (N >= 5), definida como constante no código.
Em seguida, leia uma sequência s com k números inteiros (2 <= k <= N) e busque
essa sequência na matriz nos quatro sentidos abaixo, obrigatoriamente nessa ordem:

1. Esquerda para direita (por linha)
2. Direita para esquerda (por linha)
3. Cima para baixo (por coluna)
4. Baixo para cima (por coluna)

Para cada ocorrência encontrada, exiba a posição (x, y) onde a sequência começa
— x é o índice da linha e y é o índice da coluna — seguida do sentido da busca.
Se a sequência não for encontrada em nenhum sentido, exiba "Sequência não encontrada."

Após cada busca, perguntar se o usuário deseja buscar uma nova sequência.

Restrições importantes:
- N >= 5. A constante N e a matriz m devem ser declaradas exatamente assim:
    const int N = 5;
    int main() {
        int m[N][N];
        // restante do código
    }
  O valor de N será trocado durante a correção (ex: 8, 10, 12), então o código
  deve funcionar para qualquer N >= 5.
- Se k estiver fora do intervalo [2, N], exibir erro e pedir novamente
- Todo o código deve estar no main, sem funções auxiliares próprias
- Não usar variáveis globais (constantes são permitidas)
