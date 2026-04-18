Programa para calcular orçamentos de instalação de ar-condicionado. O valor
do orçamento é calculado pela fórmula:

    valor do orçamento = (mão de obra + obra bruta) * (1 + ajuste)

Leia primeiro a quantidade de orçamentos (inteiro > 0). Para cada orçamento,
leia os dados na seguinte ordem:

1. Profissionais envolvidos: informe o código e as horas de cada profissional.
   Digite 0 para encerrar a lista. Códigos válidos:
   1 = Pedreiro (R$ 220,00/8h), 2 = Eletricista (R$ 260,00/8h),
   3 = Técnico em AC (R$ 250,00/8h), 4 = Pintor (R$ 240,00/8h)
   Todo profissional trabalha com um ajudante (R$ 100,00/8h).

2. Área do ambiente (metros cúbicos, valor > 0)

3. Tipo do ambiente: 'c'/'C' para casa (R$ 40,00/m³) ou 'a'/'A' para
   apartamento (R$ 50,00/m²)

4. Estação do ano: 'v'/'V' para verão (ajuste de +40%) ou 'i'/'I' para
   inverno (ajuste de -10%)

5. Forma de pagamento: 'v'/'V' para à vista (15% de desconto) ou 'p'/'P'
   para parcelado (12% de juros ao ano). Se parcelado, ler também a
   quantidade de parcelas (inteiro > 1). A mensalidade é calculada por:

       mensalidade = (valor do orçamento × 1,12^(parcelas/12)) / parcelas

Para cada orçamento, imprimir:
- Valor da mão de obra de cada profissional e dos ajudantes
- Valor da obra bruta
- Ajuste em % (positivo ou negativo)
- Valor do orçamento
- Se à vista: valor do desconto e valor total a pagar
- Se parcelado: número de parcelas, valor da parcela, valor total a pagar
  e total de juros (total pago - valor do orçamento)

Restrições importantes:
- Dados inválidos devem gerar mensagem de erro e ser lidos novamente
- Não usar vetores, matrizes ou structs — apenas variáveis simples
- Não usar variáveis globais

Estrutura obrigatória: implementar e usar as duas funções abaixo.
Nenhuma outra função auxiliar pode ser criada além delas e de scanf, printf
e pow (math.h).

calculaOrcamento(...):
  - Parâmetros de entrada: tipo do ambiente, área, estação do ano e horas
    trabalhadas por cada um dos 4 profissionais
  - Parâmetros de saída: mão de obra de cada profissional e ajudantes
    separadamente, valor da obra bruta e percentual do ajuste (com sinal)
  - Retorno: valor do orçamento

calculaValorTotal(...):
  - Parâmetros de entrada: valor do orçamento e número de parcelas
    (0 se pagamento à vista)
  - Parâmetros de saída: desconto ou juros total (negativo se desconto,
    positivo se juros) e valor da mensalidade (0 se à vista)
  - Retorno: valor total a ser pago

Nenhuma das duas funções pode interagir com o usuário e só podem ser
chamadas diretamente do main.
