Sistema de agenda para um consultório dentário com capacidade para até 50
pacientes e 100 agendamentos. O programa é controlado por menus e deve seguir
obrigatoriamente os layouts definidos no enunciado.

── MENUS ──────────────────────────────────────────────────────────────────────

Menu Principal: Cadastro de pacientes | Agenda de consultas | Fim
Menu Cadastro:  Cadastrar | Excluir | Listar por CPF | Listar por nome | Voltar
Menu Agenda:    Agendar | Cancelar | Listar agenda | Voltar

── CADASTRO DE PACIENTES ──────────────────────────────────────────────────────

Dados necessários: CPF, nome e data de nascimento.
- CPF: 11 dígitos (pode ter zeros à esquerda); tipo long long int; não pode repetir
- Nome: mínimo 4 e máximo 50 caracteres; armazenar em caixa alta
- Data de nascimento: formato DDMMAAAA ou DD/MM/AAAA
- Paciente deve ter 13 anos ou mais na data atual
- Dados inválidos geram mensagem de erro e nova leitura do mesmo dado

Exclusão:
- Fornecer o CPF do paciente
- Paciente com agendamento futuro não pode ser excluído
- Paciente com apenas agendamentos passados pode ser excluído (e seus
  agendamentos também são removidos)

── AGENDAMENTO DE CONSULTA ────────────────────────────────────────────────────

Dados necessários: CPF, data da consulta, hora inicial e hora final.
- CPF deve existir no cadastro
- Data: formato DDMMAAAA ou DD/MM/AAAA
- Hora inicial e final: formato HHMM ou HH:MM
- O agendamento deve ser futuro (data > hoje, ou data = hoje e hora inicial > agora)
- Hora final > hora inicial
- Cada paciente só pode ter um agendamento futuro por vez
- Não pode haver sobreposição com outros agendamentos
- Horas válidas apenas de 15 em 15 minutos (ex: 14:00, 16:15, 17:30, 10:45)
- Horário de funcionamento: 08:00 às 19:00

Cancelamento:
- Fornecer CPF, data e hora inicial do agendamento
- Só é possível cancelar agendamentos futuros

── LISTAGENS ──────────────────────────────────────────────────────────────────

Listagem de pacientes:
- Ordenada por CPF ou por nome (à escolha do usuário)
- Se o paciente tiver agendamento futuro, exibir data e horário abaixo do seu nome
- Layout: CPF | Nome | Dt.Nasc. | Idade

Listagem da agenda:
- Ordenada por data e hora inicial (crescente)
- Usuário escolhe entre listar toda a agenda ou um período (informar data inicial
  e final)
- Layout: Data | H.Ini | H.Fim | Tempo | Nome | Dt.Nasc.
  (a data só é repetida na primeira consulta de cada dia)

── RESTRIÇÕES GERAIS ──────────────────────────────────────────────────────────

- Não usar variáveis globais (somente constantes podem ser globais)
- Dados inválidos sempre geram mensagem de erro e releitura do mesmo campo
- Criar obrigatoriamente funções separadas para:
    - Leitura e validação de cada tipo de dado (CPF, nome, data, hora)
    - Cada operação (cadastrar, excluir, agendar, cancelar, listar)
    - Cada ordenação (por CPF, por nome, por data/hora)
    - Cada menu
- Usar structs para representar pacientes e agendamentos
- Para obter a data/hora atual, usar a função data_hora_atual() fornecida no
  enunciado (requer #include <time.h>)
