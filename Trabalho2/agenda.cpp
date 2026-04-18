#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#define maximopacientes 50
#define maximoagendamentos 100

typedef struct 
{
    long long cpf;
    char nome [51];
    int dianascimento, mesnascimento, anonascimento;
} Paciente;

typedef struct 
{
    long long cpfpaciente;
    int dia, mes, ano;
    int horainicia, minutoinicia, horafim, minutofim;
} Agendamento;






int calcularidade(int dianascimento, int mesnascimento, int anonascimento){



    time_t t = time(NULL);
    struct tm lt = *localtime(&t);

    int anoatual = lt.tm_year + 1900;
    int mesatual = lt.tm_mon + 1;
    int diaatual = lt.tm_mday;

    int idade = anoatual - anonascimento;

    if (mesatual < mesnascimento || (mesatual == mesnascimento && diaatual < dianascimento)){

        idade--;

    }

    return idade;
}





void cadastrarpaciente (Paciente pacientes[], int *numPacientes) {
         if (*numPacientes >= maximopacientes) {
        printf("Erro: limite de pacientes atingido.\n");
        return;
    }

    char cpftemporario[12]; 
    long long cpfConvertido;

    printf("CPF: ");
    scanf("%s", cpftemporario);

    
    while (strlen(cpftemporario) != 11 || strspn(cpftemporario, "0123456789") != 11) {
        printf("CPF inválido. Digite novamente (somente 11 dígitos): ");
        scanf("%s", cpftemporario);
    }

   
    cpfConvertido = strtoll(cpftemporario, NULL, 10);

    
    pacientes[*numPacientes].cpf = cpfConvertido;
       




        
        printf("Nome: ");

        getchar();
        
        fgets( pacientes[*numPacientes].nome, 52, stdin);
        pacientes[*numPacientes].nome[strcspn(pacientes[*numPacientes].nome, "\n")] = '\0';

        //scanf("%s", pacientes[*numPacientes].nome);
   
        while (strlen(pacientes[*numPacientes].nome) < 4)
        {
            printf("Nome inválido. Digite novamente:");
           
            fgets(pacientes[*numPacientes].nome, 52, stdin);

            //scanf("%s", pacientes[*numPacientes].nome);
        }
        





     printf("Data de nascimento no formato DDMMAAAA:");
     scanf("%2d%2d%4d", 
     &pacientes[*numPacientes].dianascimento,
     &pacientes[*numPacientes].mesnascimento,
     &pacientes[*numPacientes].anonascimento);

     while(calcularidade(     
     pacientes[*numPacientes].dianascimento,
     pacientes[*numPacientes].mesnascimento,
     pacientes[*numPacientes].anonascimento) < 13)

     {
        
        printf("Erro: paciente deve ter 13 anos ou mais. tente novamente: \n");
        printf("Data de nascimento no formato DDMMAAAA:");

        scanf("%2d%2d%4d", 
     &pacientes[*numPacientes].dianascimento,
     &pacientes[*numPacientes].mesnascimento,
     &pacientes[*numPacientes].anonascimento);

     

     }
     

     (*numPacientes)++;
     printf("Cadastro realizado com sucesso!\n");
     

}








void excluirpaciente(Paciente pacientes[], int *numPacientes, Agendamento agendamentos[], int *numAgendamentos){

    long long cpf;
    int cpfencontrado = -1;

    printf("Digite o CPF do paciente para ser excluido: ");
    scanf("%lld", &cpf);

    for(int i = 0; i < *numPacientes; i++){
        if (pacientes[i].cpf == cpf)
        {
            cpfencontrado = i;
            break;
        }
        
    }



    if (cpfencontrado == -1)
    {
        printf("Erro: paciente não encontrado. \n");
        return;
    }
    
    //VERIFICA AGENDAMENTOS FUTUROS
    for (int i = 0; i < *numAgendamentos; i++)
    {
        if (agendamentos[i].cpfpaciente == cpf)
        {
            time_t t = time(NULL);
            struct tm lt = *localtime(&t);

            int anoatual = lt.tm_year + 1900;
            int mesatual = lt.tm_mon + 1;
            int diaatual = lt.tm_mday;
            int horaatual = lt.tm_hour * 100 + lt.tm_min;

            if(agendamentos[i].ano > anoatual || 
            (agendamentos[i].ano == anoatual && agendamentos[i].mes > mesatual) ||
            (agendamentos[i].ano == anoatual && agendamentos[i].mes == mesatual && agendamentos[i].dia > diaatual) ||
            (agendamentos[i].ano == anoatual && agendamentos[i].mes == mesatual && agendamentos[i].dia == diaatual && (agendamentos[i].horainicia * 100 + agendamentos[i].minutoinicia > horaatual)) )
            {
                printf("Erro: paciente está agendado para %02d/%02d/%04d às %02d:%02d.\n",
                agendamentos[i].dia,
                agendamentos[i].mes,
                agendamentos[i].ano,
                agendamentos[i].horainicia,
                agendamentos[i].minutoinicia);

                return;
            }
        }
        
    }
    
    for (int i = 0; i < *numAgendamentos;)
    {
        if (agendamentos[i].cpfpaciente == cpf)
        {
            for (int j = i; j < *numAgendamentos - 1; j++)
            {
                agendamentos[j] = agendamentos[j+1];
            }

            (*numAgendamentos)--;
        } 
        
        else {i++;}
        
    }
    
    for (int i = cpfencontrado; i < *numPacientes - 1; i++)
    {
        pacientes[i] = pacientes[i+1];
    }
    
    (*numPacientes)--;

    printf("Paciente excluido com sucesso! \n");

}







void agendarconsulta(Paciente pacientes[], int numPacientes, Agendamento agendamentos[], int *numAgendamentos){

    if (*numAgendamentos >= maximoagendamentos)
    {
        printf("Erro: Limite de agendamentos atingido.");
        return;
    }
    
    long long cpf;
    int pacienteindice = -1;





    printf("Digite o cpf do paciente para agendar a consulta: ");
    scanf("%lld", &cpf);

    for (int i = 0; i < numPacientes; i++)
    {
        if (pacientes[i].cpf == cpf)
        {
            pacienteindice = i;
            break;
        }
    }
    
        
  


       
while (1)
{
    if (pacienteindice == -1)
    {
        printf("Erro: paciente não encontrado.\n");
        printf("Digite o CPF do paciente para agendar a consulta: ");
        scanf("%lld", &cpf);

        // Repetir a busca pelo índice do paciente
        for (int i = 0; i < numPacientes; i++)
        {
            if (pacientes[i].cpf == cpf)
            {
                pacienteindice = i;
                break;
            }
        }
    }
    
    // Se o paciente foi encontrado, sair do loop
    if (pacienteindice != -1)
        break;
}

    




    
    int dia, mes, ano, horainicio, minutoinicio, horafim, minutofim;
     time_t t = time(NULL);
    struct tm tm_atual = *localtime(&t); // Obtém a data e hora atuais

int dia_atual = tm_atual.tm_mday;
    int mes_atual = tm_atual.tm_mon + 1;
    int ano_atual = tm_atual.tm_year + 1900;
    int hora_atual = tm_atual.tm_hour;
    int minuto_atual = tm_atual.tm_min;









 for (int i = 0; i < *numAgendamentos; i++) {
        if (agendamentos[i].cpfpaciente == cpf) {
            // Verificar se o agendamento é futuro
            if (agendamentos[i].ano > ano_atual || 
                (agendamentos[i].ano == ano_atual && agendamentos[i].mes > mes_atual) || 
                (agendamentos[i].ano == ano_atual && agendamentos[i].mes == mes_atual && agendamentos[i].dia > dia_atual) || 
                (agendamentos[i].ano == ano_atual && agendamentos[i].mes == mes_atual && agendamentos[i].dia == dia_atual && 
                 (agendamentos[i].horainicia > hora_atual || 
                  (agendamentos[i].horainicia == hora_atual && agendamentos[i].minutoinicia > minuto_atual)))) {
                printf("Erro: paciente já possui um agendamento futuro em %02d/%02d/%04d das %02d:%02d às %02d:%02d.\n", 
                       agendamentos[i].dia, agendamentos[i].mes, agendamentos[i].ano, 
                       agendamentos[i].horainicia, agendamentos[i].minutoinicia, 
                       agendamentos[i].horafim, agendamentos[i].minutofim);
                return;
            }
        }
    }


















    


    while (1){
    printf("Digite a data da consulta (DDMMAAAA): ");
    scanf("%2d%2d%4d", &dia, &mes, &ano);


if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 1900) {
            if (ano > tm_atual.tm_year + 1900 || (ano == tm_atual.tm_year + 1900 && mes > tm_atual.tm_mon + 1) ||
                (ano == tm_atual.tm_year + 1900 && mes == tm_atual.tm_mon + 1 && dia >= tm_atual.tm_mday)) {

                break; // Data válida e no futuro ou igual à data atual
            } else {

                printf("Erro: data de agendamento não pode ser no passado. Tente novamente.\n");
            }
        } else {
            printf("Erro: data inválida. Tente novamente.\n");
        }
    }





    
while (1) {
        printf("Digite o horário de início (HHMM): ");
        scanf("%2d%2d", &horainicio, &minutoinicio);


            if (minutoinicio % 15 != 0) {
            printf("Erro: minutos de início devem ser múltiplos de 15. Tente novamente.\n");
            continue;
        }



         if (horainicio < 8 || (horainicio == 18 && minutoinicio > 45) || horainicio > 18) {
        printf("Erro: o horário de início deve estar entre 08:00 e 18:45. Tente novamente.\n");
        continue;
    }



        printf("Digite o horário de término (HHMM): ");
        scanf("%2d%2d", &horafim, &minutofim);


          if (minutofim % 15 != 0) {
            printf("Erro: minutos de término devem ser múltiplos de 15. Tente novamente.\n");
            continue;
        }


        if (horafim < 8 || horafim > 19 || (horafim == 19 && minutofim != 0)) {
        printf("Erro: o horário de término deve estar entre 08:15 e 19:00. Tente novamente.\n");
        continue;
    }



        if (horainicio >= 0 && horainicio <= 23 && minutoinicio >= 0 && minutoinicio <= 59 &&
            horafim >= 0 && horafim <= 23 && minutofim >= 0 && minutofim <= 59) {

            if (horafim > horainicio || (horafim == horainicio && minutofim > minutoinicio))
            
            
             {
                break; 
            } else {
                printf("Erro: horário de término deve ser após o horário de início. Tente novamente.\n");
            }
        } else {
            printf("Erro: horários inválidos. Tente novamente.\n");
        }
    }






    for (int i = 0; i < *numAgendamentos; i++)
    {
        if (agendamentos[i].ano == ano && agendamentos[i].mes == mes && agendamentos[i].dia == dia)
        {
            int consultainicio = horainicio * 100 + minutoinicio;
            int consultafim = horafim * 100 + minutofim;

            int agendamentoinicio = agendamentos[i].horainicia * 100 + agendamentos[i].minutoinicia;
            int agendamentofim = agendamentos[i].horafim * 100 + agendamentos[i].minutofim;




            if ((consultainicio >= agendamentoinicio && consultainicio < agendamentofim) || 
            (consultafim > agendamentoinicio && consultafim <= agendamentofim) ||
            (consultainicio <= agendamentoinicio && consultafim >= agendamentofim))
            {
               printf("Erro: horário já ocupado por outro agendamento no dia %02d/%02d/%04d. \n", dia, mes, ano);
               
               return;
            }
            
        }
        
    }
    

    Agendamento novoagendamento;
    novoagendamento.cpfpaciente = cpf;
    novoagendamento.dia = dia;
    novoagendamento.mes = mes;
    novoagendamento.ano = ano;
    novoagendamento.horainicia = horainicio;
    novoagendamento.minutoinicia = minutoinicio;
    novoagendamento.horafim = horafim;
    novoagendamento.minutofim = minutofim;

    agendamentos[*numAgendamentos] = novoagendamento;
    (*numAgendamentos)++;

    printf("Consulta agendada com sucesso para %02d/%02d/%04d das %02d:%02d até às %02d:%02d. \n", dia, mes, ano, horainicio, minutoinicio, horafim, minutofim);

}










    void cancelaragendamento (Agendamento agendamentos[], int *numAgendamentos){

        if (*numAgendamentos == 0)
        {
            printf("Erro: Não há agendamentos para cancelar");
            return;
        }

        long long cpf;
        int dia, mes, ano, horainicio, minutoinicio;
        int agendamentoindice = -1;

        printf("Digite o cpf do paciente para cancelar o agendamento: ");
        scanf("%lld", &cpf);

        printf("Digite a data do agendamento (DDMMAAAA): ");
        scanf("%2d%2d%4d", &dia, &mes, &ano);

        printf("Digite o horaio de inicio do agendamento (HHMM):");
        scanf("%2d%2d", &horainicio, &minutoinicio);






            time_t now;
            struct tm *currentTime;
            time(&now);
            currentTime = localtime(&now);





        for (int i = 0; i < *numAgendamentos; i++)
        {
            if (agendamentos[i].cpfpaciente == cpf &&
            agendamentos[i].dia == dia &&
            agendamentos[i].mes == mes &&
            agendamentos[i].ano == ano && 
            agendamentos[i].horainicia == horainicio &&
            agendamentos[i].minutoinicia == minutoinicio)
            {
                agendamentoindice = i;
                break;
            }     
        }
        
        if(agendamentoindice == -1){
            printf("Erro: agendamento não encontrado.");
            return;
        }





        struct tm agendamentoData = {0};
            agendamentoData.tm_year = ano - 1900;  
            agendamentoData.tm_mon = mes - 1;      
            agendamentoData.tm_mday = dia;
            agendamentoData.tm_hour = horainicio;
         agendamentoData.tm_min = minutoinicio;

    // Verifica se o agendamento é futuro
    if (difftime(mktime(&agendamentoData), now) <= 0) {
        printf("Erro: Só é possível cancelar agendamentos futuros.\n");
        return;
    }






        for (int i = agendamentoindice; i < *numAgendamentos - 1; i++)
        {
            agendamentos[i] = agendamentos[i+1];
        }

        (*numAgendamentos)--;

        printf("Agendamento do dia %02d/%02d/%04d às %02d:%02d cancelado com sucesso.\n", dia, mes, ano, horainicio, minutoinicio);
        

    }


   
   
   
   
   
   
   
   
   

  
    void listarpacientescpf(Paciente pacientes[], int numPacientes, Agendamento agendamentos[], int numAgendamentos) {
    // Ordenação por CPF em ordem crescente
    for (int i = 0; i < numPacientes; i++) {
        for (int j = i + 1; j < numPacientes; j++) {
            if (pacientes[i].cpf > pacientes[j].cpf) {
                Paciente temp = pacientes[i];
                pacientes[i] = pacientes[j];
                pacientes[j] = temp;
            }
        }
    }

    
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("CPF\t\t\tNome\t\t\t\t\tDt.Nasc.\tIdade\n");
    printf("-----------------------------------------------------------------------------------------------\n");

   
    for (int i = 0; i < numPacientes; i++) {
        int idade = calcularidade(pacientes[i].dianascimento, pacientes[i].mesnascimento, pacientes[i].anonascimento);

        printf("%011lld\t\t%-30s\t\t%02d/%02d/%04d\t%d\n",  
            pacientes[i].cpf,
            pacientes[i].nome,
            pacientes[i].dianascimento,
            pacientes[i].mesnascimento, 
            pacientes[i].anonascimento,
            idade);

        
        int encontrouAgendamento = 0;
        for (int j = 0; j < numAgendamentos; j++) {
            if (agendamentos[j].cpfpaciente == pacientes[i].cpf) {
                encontrouAgendamento = 1;
                printf("   Agendado para: %02d/%02d/%04d\n",
                       agendamentos[j].dia, agendamentos[j].mes, agendamentos[j].ano);
                printf("   %02d:%02d às %02d:%02d\n",
                       agendamentos[j].horainicia, agendamentos[j].minutoinicia,
                       agendamentos[j].horafim, agendamentos[j].minutofim);
            }
        }

        if (!encontrouAgendamento) {
            printf("   Sem agendamentos futuros.\n");
        }
    }

    
    printf("-----------------------------------------------------------------------------------------------\n");
}


    











void listarpacientesnome(Paciente pacientes[], int numPacientes, Agendamento agendamentos[], int numAgendamentos) {
   
    for (int i = 0; i < numPacientes - 1; i++) {
        for (int j = i + 1; j < numPacientes; j++) {
            if (strcmp(pacientes[i].nome, pacientes[j].nome) > 0) {
                Paciente temp = pacientes[i];
                pacientes[i] = pacientes[j];
                pacientes[j] = temp;
            }
        }
    }

    
    printf("------------------------------------------------------------\n");
    printf("CPF\t\t\tNome\t\t\t\t\tDt.Nasc.\tIdade\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numPacientes; i++) {int idade = calcularidade(pacientes[i].dianascimento, pacientes[i].mesnascimento, pacientes[i].anonascimento);
        printf("%011lld\t\t%-30s\t\t%02d/%02d/%04d\t%d\n",
               pacientes[i].cpf, pacientes[i].nome,
               pacientes[i].dianascimento, pacientes[i].mesnascimento, pacientes[i].anonascimento, idade);

        // Verifica se há agendamentos futuros para o paciente
        int encontrouAgendamento = 0;
        for (int j = 0; j < numAgendamentos; j++) {
            if (agendamentos[j].cpfpaciente == pacientes[i].cpf) {
                encontrouAgendamento = 1;
                printf("   Agendado para: %02d/%02d/%04d\n",
                       agendamentos[j].dia, agendamentos[j].mes, agendamentos[j].ano);
                printf("   %02d:%02d às %02d:%02d\n",
                       agendamentos[j].horainicia, agendamentos[j].minutoinicia,
                       agendamentos[j].horafim, agendamentos[j].minutofim);
            }
        }

        if (!encontrouAgendamento) {
            printf("   Sem agendamentos futuros.\n");
        }
    }

    printf("------------------------------------------------------------\n");
}
















// Função para comparar duas datas 
int compararDatas(Agendamento a, Agendamento b) {
    if (a.ano != b.ano) return a.ano - b.ano;
    if (a.mes != b.mes) return a.mes - b.mes;
    if (a.dia != b.dia) return a.dia - b.dia;
    if (a.horainicia != b.horainicia) return a.horainicia - b.horainicia;
    if (a.minutoinicia != b.minutoinicia) return a.minutoinicia - b.minutoinicia;
    return 0;
}

// Função para calcular o tempo de consulta
void calcularTempoConsulta(Agendamento agendamento, char *tempoConsulta) {
    int inicioMinutos = agendamento.horainicia * 60 + agendamento.minutoinicia;
    int fimMinutos = agendamento.horafim * 60 + agendamento.minutofim;
    int duracao = fimMinutos - inicioMinutos;

    int horas = duracao / 60;
    int minutos = duracao % 60;

    sprintf(tempoConsulta, "%02d:%02d", horas, minutos);
}





















void listaragenda(Agendamento agendamentos[], int numAgendamentos, Paciente pacientes[], int numPacientes) {
    char opcao;
    printf("Apresentar a agenda T-Toda ou P-Periodo: ");
    getchar();  
    scanf("%c", &opcao);

    if (opcao == 'P' || opcao == 'p') {
        int diaInicio, mesInicio, anoInicio;
        int diaFim, mesFim, anoFim;

      
        printf("Data inicial (DDMMYYYY): ");
        scanf("%2d%2d%4d", &diaInicio, &mesInicio, &anoInicio);
        printf("Data final (DDMMYYYY): ");
        scanf("%2d%2d%4d", &diaFim, &mesFim, &anoFim);

        // Verifica se as datas são válidas
        if (anoInicio > anoFim || 
            (anoInicio == anoFim && mesInicio > mesFim) || 
            (anoInicio == anoFim && mesInicio == mesFim && diaInicio > diaFim)) {
            printf("Erro: Data inicial deve ser anterior ou igual à data final.\n");
            return;
        }

     
        printf("-------------------------------------------------------------\n");
        printf("Data\tH.Ini H.Fim Tempo\tNome\t\t Dt.Nasc.\n");
        printf("-------------------------------------------------------------\n");

        for (int i = 0; i < numAgendamentos; i++) {
            // Verifica se o agendamento está dentro do intervalo
            int agendamentoData = agendamentos[i].ano * 10000 + agendamentos[i].mes * 100 + agendamentos[i].dia;
            int dataInicio = anoInicio * 10000 + mesInicio * 100 + diaInicio;
            int dataFim = anoFim * 10000 + mesFim * 100 + diaFim;

            if (agendamentoData >= dataInicio && agendamentoData <= dataFim) {
                // Encontra o paciente associado ao agendamento
                for (int j = 0; j < numPacientes; j++) {
                    if (pacientes[j].cpf == agendamentos[i].cpfpaciente) {
                        char tempoConsulta[6];
                        calcularTempoConsulta(agendamentos[i], tempoConsulta);

                       
                        printf("%02d/%02d/%04d %02d:%02d %02d:%02d %s\t%s\t\t%02d/%02d/%04d\n",
                               agendamentos[i].dia, agendamentos[i].mes, agendamentos[i].ano,
                               agendamentos[i].horainicia, agendamentos[i].minutoinicia,
                               agendamentos[i].horafim, agendamentos[i].minutofim,
                               tempoConsulta, pacientes[j].nome, pacientes[j].dianascimento,
                               pacientes[j].mesnascimento, pacientes[j].anonascimento);
                    }
                }
            }
        }
        printf("-------------------------------------------------------------\n");
    } else  {
        // Ordena os agendamentos pela data e hora inicial
        for (int i = 0; i < numAgendamentos - 1; i++) {
            for (int j = i + 1; j < numAgendamentos; j++) {
                if (compararDatas(agendamentos[i], agendamentos[j]) > 0) {
                    Agendamento temp = agendamentos[i];
                    agendamentos[i] = agendamentos[j];
                    agendamentos[j] = temp;
                }
            }
        }

      
        printf("-------------------------------------------------------------\n");
        printf("Data\tH.Ini H.Fim Tempo\tNome\t\t Dt.Nasc.\n");
        printf("-------------------------------------------------------------\n");

        for (int i = 0; i < numAgendamentos; i++) {
            // Encontra o paciente associado ao agendamento
            for (int j = 0; j < numPacientes; j++) {
                if (pacientes[j].cpf == agendamentos[i].cpfpaciente) {
                    char tempoConsulta[6];
                    calcularTempoConsulta(agendamentos[i], tempoConsulta);

                    
                    printf("%02d/%02d/%04d %02d:%02d %02d:%02d %s %s\t\t%02d/%02d/%04d\n",
                           agendamentos[i].dia, agendamentos[i].mes, agendamentos[i].ano,
                           agendamentos[i].horainicia, agendamentos[i].minutoinicia,
                           agendamentos[i].horafim, agendamentos[i].minutofim,
                           tempoConsulta, pacientes[j].nome, pacientes[j].dianascimento,
                           pacientes[j].mesnascimento, pacientes[j].anonascimento);
                }
            }
        }
        printf("-------------------------------------------------------------\n");
    }
}












int menuprincipal(){
    int opcao;
    printf("Menu Principal\n");
    printf("1-Cadastro de pacientes\n");
    printf("2-Agenda de consultas\n");
    printf("3-Fim\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int menucadastropacientes(){
    int opcao;
    printf("Menu de Cadastro de Pacientes\n");
    printf("1-Cadastrar novo paciente\n");
    printf("2-Excluir paciente\n");
    printf("3-Listar pacientes (ordenado por CPF)\n");
    printf("4-Listar pacientes (ordenado por nome)\n");
    printf("5-Voltar p/ menu principal\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuagendaconsultas(){
    int opcao;
    printf("Menu da Agenda de Consultas\n");
    printf("1-Agendar consulta\n");
    printf("2-Cancelar agendamento\n");
    printf("3-Listar agenda\n");
    printf("4-Voltar p/ menu principal\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){

    Paciente pacientes[maximopacientes];
    int numPacientes = 0;

    Agendamento agendamentos[maximoagendamentos];
    int numAgendamentos = 0;

   

    int opcaoprincipal, opcaosubmenu;

    do
    {
        
        opcaoprincipal = menuprincipal();
        switch (opcaoprincipal)
        {
        case 1:
            do
            {
                opcaosubmenu = menucadastropacientes();
                switch (opcaosubmenu)
                {
                case 1:
                    cadastrarpaciente(pacientes, &numPacientes);
                    break;
                case 2:
                    excluirpaciente(pacientes, &numPacientes, agendamentos, &numAgendamentos);
                    break;
                case 3:
                    listarpacientescpf(pacientes, numPacientes, agendamentos, numAgendamentos);
                    break;
                case 4:
                    listarpacientesnome(pacientes, numPacientes, agendamentos, numAgendamentos);
                    break;
                case 5:
                    printf("Voltando ao menu principal. \n");
                    break;
                default:
                    printf("Opcao invalida.");
                
                }
            } while (opcaosubmenu != 5);
            
            break;
        case 2:
        do
        {
           opcaosubmenu = menuagendaconsultas();
           switch (opcaosubmenu)
           {
           case 1:
            agendarconsulta(pacientes, numPacientes, agendamentos, &numAgendamentos);
            break;
            case 2:
            cancelaragendamento(agendamentos, &numAgendamentos);
            break;
            case 3:
            listaragenda(agendamentos, numAgendamentos, pacientes, numPacientes);
            break;
            case 4:
            printf("Voltando ao menu principal. \n");
            break;
           
           default:
           printf("Opcao invalida.\n");
            break;
           }
        } while (opcaosubmenu != 4);
        break;
        case 3:
        printf("Saindo. \n");
        break;
        
        default:
        printf("Opcao invalida. \n");
            
        }

    } while (opcaoprincipal != 3);
    

    return 0;
}
