#include <stdio.h>

int main() {
    
    unsigned long int varPopulacao_01 = 0, varPopulacao_02 = 0; //DADOS DE POPULAÇÃO

    int varPontosTuristicos_01 = 0, varPontosTuristicos_02 = 0; //DADOS DE PONTOS TURÍSTICOS

    int varSelecaoModoDisputa = 0; //PRIMEIRO SWITCH (SELECÃO MODO DE DISPUTA)

    int varSelecPopulacao = 0, varSelecArea = 0, varSelecPIB = 0, varSelecPontosTuristicos = 0, varSelecDensidadePopulacional = 0, varSelecPIBperCapita = 0, varSelecSuperPoder = 0;

    int varDisputaAtributo01 = 0, varDisputaAtributo02 = 0; //SELEÇÃO DOS ATRIBUTOS DA DISPUTA

    int varPontuacao_01 = 0, varPontuacao_02 = 0, varEmpate = 0; //PONTUAÇÕES OU EMPATE

    float varPIB_01 = 0, varPIB_02 = 0; //DADOS DE PIB

    float varArea_01 = 0, varArea_02 = 0; //DADOS DE ÁREA

    float varDensidadePopulacional_01 = 0, varDensidadePopulacional_02 = 0; //DADOS DE DENSIDADE POPULACIONAL (CALCULADO)

    float varPIBperCapita_01 = 0, varPIBperCapita_02 = 0; //DADOS DE PIB PER CAPITA (CALCULADO)

    float varSuperPoder_01 = 0, varSuperPoder_02 = 0;  //DADOS DE SUPER PODER (CALCULADO)

    char varCidade_01[51], varCidade_02[51]; //NOME CIDADES

    char varEstado_01[3], varEstado_02[3];  //SIGLA ESTADOS

    //INTRUÇÕES INICIAIS
    printf("==== SUPER TRUNFO CIDADES ====");
    printf("\nPara jogar, é necessário cadastrar duas cartas.");
    printf("\nCada carta terá informações de uma cidade.");
    printf("\nO cadastro de cada carta será feito separadamente.\n");
    printf("\nVamos começar!\n"); 

    //COLETA DE DADOS DA PRIMEIRA CARTA
    printf("\nCadastro Primeira Carta");

    printf("\nInforme a sigla do estado da primeira cidade (exemplo: BA para Bahia):\n");
    scanf("%2s", varEstado_01); //%2s LIMITA RECEBER APENAS 2 CARACTERES

    printf("\nInforme o nome da primeira cidade selecionada (Remover os espaços):\n");
    scanf(" %50s", varCidade_01);  //%50s LIMITA RECEBER APENAS 50 CARACTERES
    
    printf("\nInforme a população da primeira cidade (número total de habitantes):\n");
    scanf("%lu", &varPopulacao_01);

    printf("\nInforme a área da primeira cidade em km²:\n");
    scanf("%f", &varArea_01);

    printf("\nInforme o Produto Interno Bruto (PIB) da primeira cidade:\n");
    scanf("%f", &varPIB_01);

    printf("\nInforme o número de pontos turísticos da primeira cidade:\n");
    scanf("%d", &varPontosTuristicos_01);

            //CÁLCULOS PRIMEIRA CARTA
            varDensidadePopulacional_01 = varPopulacao_01/varArea_01;
            varPIBperCapita_01 = varPIB_01/varPopulacao_01;
            varSuperPoder_01 = (
                (float)(varPopulacao_01 + varPontosTuristicos_01) +
                varArea_01 +
                varPIB_01 +
                varPIBperCapita_01 +
                1.0f / varDensidadePopulacional_01
            );
              
    //COLETA DE DADOS DA SEGUNDA CARTA
    printf("\n\nChegou a vez de cadastrar os dados da segunda carta.\nA estrutura é a mesma da primeira.\nVamos lá?\n\nCadastro da Segunda Carta");

    printf("\nInforme a sigla do estado da segunda cidade:\n");
    scanf("%2s", varEstado_02);

    printf("\nInforme o nome da segunda cidade selecionada (Remover os espaços):\n");
    scanf(" %50s", varCidade_02);
    
    printf("\nQual é a população total da segunda cidade? Informe o número de habitantes:\n");
    scanf("%lu", &varPopulacao_02);

    printf("\nQuantos km² a segunda cidade ocupa? Informe a área total:\n");
    scanf("%f", &varArea_02);

    printf("\nO Produto Interno Bruto (PIB) da segunda cidade. Qual é o valor?\n");
    scanf("%f", &varPIB_02);

    printf("\nQuantos pontos turísticos a segunda cidade oferece aos visitantes?\n");
    scanf("%d", &varPontosTuristicos_02);

            //CÁLCULOS SEGUNDA CARTA
            varDensidadePopulacional_02 = varPopulacao_02/varArea_02;
            varPIBperCapita_02 = varPIB_02/varPopulacao_02;
            varSuperPoder_02 = (
                (float)(varPopulacao_02 + varPontosTuristicos_02) +
                varArea_02 +
                varPIB_02 +
                varPIBperCapita_02 +
                1.0f / varDensidadePopulacional_02
            );
    //O JOGADOR FARÁ SELEÇÃO DO MODO DE DISPUTA
    printf("\n\nAgora que as duas cartas foram cadastradas, selecione como deverá ser a disputa:");
    printf("\n1. Comparação de TODOS os Atributos.");
    printf("\n2. Comparação de UM Atributo.");
    printf("\n3. Comparação de DOIS Atributo.");
    printf("\nSelecione: ");
    scanf("%d", &varSelecaoModoDisputa);

    switch (varSelecaoModoDisputa)
    {
    case 1:
    //COMPARAÇÃO DE TODOS OS ATRIBUTOS
        varSelecPopulacao = 1;
        varSelecArea = 1;
        varSelecPIB = 1;
        varSelecPontosTuristicos = 1;
        varSelecDensidadePopulacional = 1;
        varSelecPIBperCapita = 1;
        varSelecSuperPoder = 1;
        break;
    
    case 2:
    //COMPARAÇÃO DE APENAS UM ATRIBUTO
        printf("\nEscolha qual Atributo será comparado:");
        printf("\n1. População");
        printf("\n2. Área");
        printf("\n3. PIB");
        printf("\n4. Pontos Turíticos");
        printf("\n5. Densidade Populacional (menor)");
        printf("\n6. PIB per Capita");
        printf("\nEscolha: ");
        scanf("%d", &varDisputaAtributo01);

        switch (varDisputaAtributo01)
        {
        case 1:
            varSelecPopulacao = 1;
            break;
        case 2:
            varSelecArea = 1;
            break;
        case 3:
            varSelecPIB = 1;
            break;
        case 4:
            varSelecPontosTuristicos = 1;
            break;
        case 5:
            varSelecDensidadePopulacional = 1;
            break;
        case 6:
            varSelecPIBperCapita = 1;
            break;
        
        default:
            printf("Opção Inválida!");
            break;
        }
        break;
    
    case 3:
        //COMPARAÇÃO DE DOIS ATRIBUTOS
            //SELEÇÃO PRIMEIRO ATRIBUTO
        printf("\nEscolha o primeiro Atributo que será comparado:");
        printf("\n1. População");
        printf("\n2. Área");
        printf("\n3. PIB");
        printf("\n4. Pontos Turíticos");
        printf("\n5. Densidade Populacional (menor)");
        printf("\n6. PIB per Capita");
        printf("\nEscolha: ");
        scanf("%d", &varDisputaAtributo01);

        switch (varDisputaAtributo01)
        {
        case 1:
            varSelecPopulacao = 1;
            break;
        case 2:
            varSelecArea = 1;
            break;
        case 3:
            varSelecPIB = 1;
            break;
        case 4:
            varSelecPontosTuristicos = 1;
            break;
        case 5:
            varSelecDensidadePopulacional = 1;
            break;
        case 6:
            varSelecPIBperCapita = 1;
            break;
        default:
            printf("Opção Inválida!");
            break;
        }
            //SELEÇÃO SEGUNDO ATRIBUTO
            //O ATRIBUTO JÁ SELECIONADO NÃO DEVE APARECER
        printf("\nEscolha o segundo Atributo que será comparado:");
        if(varDisputaAtributo01 != 1) printf("\n1. População");
        if(varDisputaAtributo01 != 2) printf("\n2. Área");
        if(varDisputaAtributo01 != 3) printf("\n3. PIB");
        if(varDisputaAtributo01 != 4) printf("\n4. Pontos Turísticos");
        if(varDisputaAtributo01 != 5) printf("\n5. Densidade Populacional");
        if(varDisputaAtributo01 != 6) printf("\n6. PIB per Capita");
        printf("\nEscolha: ");
        scanf("%d", &varDisputaAtributo02);
        //SE O JOGADOR SELECIONAR O MESMO ATRIBUTO QUE O ANTERIOR (MESMO QUE NÃO APARECENDO), O JOGO TEM QUE DAR ERRO.
        if (varDisputaAtributo01 == varDisputaAtributo02)
        {
            printf("Opção Inválida!");
        } else {
            switch (varDisputaAtributo02)
            {
            case 1:
                varSelecPopulacao = 1;
                break;
            case 2:
                varSelecArea = 1;
                break;
            case 3:
                varSelecPIB = 1;
                break;
            case 4:
                varSelecPontosTuristicos = 1;
                break;
            case 5:
                varSelecDensidadePopulacional = 1;
                break;
            case 6:
                varSelecPIBperCapita = 1;
                break;
            default:
                printf("Opção Inválida!");
                break;
            }
        }
        break;
    default:
        printf("Opção Inválida!");
        break;
    }
    //COMPARAÇÕES DE VALORES APENAS SE O ATRIBUTO FOI SELECIONADO
        //POPULAÇÃO
    if (varSelecPopulacao)
    {
        if (varPopulacao_01 == varPopulacao_02)
        {
            varEmpate++;
        } else if (varPopulacao_01 > varPopulacao_02)
        {
            varPontuacao_01++;
        } else {
            varPontuacao_02++;
        }
    }
        //ÁREA
    if (varSelecArea)
    {
        if (varArea_01 == varArea_02)
        {
            varEmpate++;
        } else if (varArea_01 > varArea_02)
        {
            varPontuacao_01++;
        } else {
            varPontuacao_02++;
        }
    }
        //PIB
    if (varSelecPIB)
    {
        if (varPIB_01 == varPIB_02)
        {
            varEmpate++;
        } else if (varPIB_01 > varPIB_02)
        {
            varPontuacao_01++;
        } else {
            varPontuacao_02++;
        }
    }
        //NÚMERO DE PONTOS TURÍSTICOS
    if (varSelecPontosTuristicos)
    {
        if (varPontosTuristicos_01 == varPontosTuristicos_02)
        {
            varEmpate++;
        } else if (varPontosTuristicos_01 > varPontosTuristicos_02)
        {
            varPontuacao_01++;
        } else {
            varPontuacao_02++;
        }
    }
        //DENSIDADE POPULACIONAL (MENOR)
    if (varSelecDensidadePopulacional)
    {
        if (varDensidadePopulacional_01 == varDensidadePopulacional_02)
        {
            varEmpate++;
        } else if (varDensidadePopulacional_01 < varDensidadePopulacional_02)
        {
            varPontuacao_01++;
        } else {
            varPontuacao_02++;
        }
    }
        //PIB PER CAPITA
    if (varSelecPIBperCapita)
    {
        if (varPIBperCapita_01 == varPIBperCapita_02)
        {
            varEmpate++;
        } else if (varPIBperCapita_01 > varPIBperCapita_02)
        {
            varPontuacao_01++;
        } else {
            varPontuacao_02++;
        }
    }
        //SUPER PODER (SÓ NA DISPUTA DE TODOS OS ATRIBUTOS)
    if (varSelecSuperPoder)
    {
        if (varSuperPoder_01 == varSuperPoder_02)
        {
            varEmpate++;
        } else if (varSuperPoder_01 > varSuperPoder_02)
        {
            varPontuacao_01++;
        } else {
            varPontuacao_02++;
        }
    }
    
    //MOSTRANDO OS DADOS DAS CARTAS    
    printf("\nCARTA  1");
    printf("\nCódigo: %s-01", varEstado_01);
    printf("\nNome da Cidade: %s - %s", varCidade_01, varEstado_01);
    printf("\nPopulação: %lu", varPopulacao_01);
    printf("\nÁrea: %.3f Km²", varArea_01); // Usando %.3f para maior precisão
    printf("\nPIB: R$ %.2f", varPIB_01);
    printf("\nNúmero de Pontos Turísticos: %d", varPontosTuristicos_01);
    printf("\nDensidade Populacional: %.1f Hab/km²", varDensidadePopulacional_01);
    printf("\nPIB per Capita: R$ %.2f", varPIBperCapita_01);
    printf("\nSuper Poder: %.3f", varSuperPoder_01);

    printf("\n\nCARTA 2");
    printf("\nCódigo: %s-02", varEstado_02);
    printf("\nNome da Cidade: %s - %s", varCidade_02, varEstado_02);
    printf("\nPopulação: %lu", varPopulacao_02);
    printf("\nÁrea: %.3f Km²", varArea_02); // Usando %.3f para maior precisão
    printf("\nPIB: R$ %.2f", varPIB_02);
    printf("\nNúmero de Pontos Turísticos: %d", varPontosTuristicos_02);
    printf("\nDensidade Populacional: %.1f Hab/km²", varDensidadePopulacional_02);
    printf("\nPIB per Capita: R$ %.2f", varPIBperCapita_02);
    printf("\nSuper Poder: %.3f", varSuperPoder_02);

    printf("\n\nATRIBUTOS COMPARADOS:");
    printf("\n%s", varSelecPopulacao ? "POPULAÇÃO [S]" : "POPULAÇÃO");
    printf("\n%s", varSelecArea ? "ÁREA [S]" : "ÁREA");
    printf("\n%s", varSelecPIB ? "PIB [S]" : "PIB");
    printf("\n%s", varSelecPontosTuristicos ? "PONTOS TURÍSTICOS [S]" : "PONTOS TURÍSTICOS");
    printf("\n%s", varSelecDensidadePopulacional ? "DENSIDADE POPULACIONAL [S]" : "DENSIDADE POPULACIONAL");
    printf("\n%s", varSelecPIBperCapita ? "PIB PER CAPITA [S]" : "PIB PER CAPITA");
    printf("\n%s\n", varSelecSuperPoder ? "SUPER PODER [S]" : "SUPER PODER");

    //COMPARAR AS DUAS PONTUAÇÕES E DECIDE QUAL A CARTA VENCEDORA
    printf("\nA CARTA 1 ( %s - %s ) VENCEU EM %d ATRIBUTO(S).", varCidade_01, varEstado_01, varPontuacao_01);
    printf("\nA CARTA 2 ( %s - %s ) VENCEU EM %d ATRIBUTO(S).", varCidade_02, varEstado_02, varPontuacao_02);
    printf("\nHOUVE EMPATE EM %d ATRIBUTO(S).\n", varEmpate);

    if (varPontuacao_01 > varPontuacao_02)
    {
        printf("\n****PARABÉNS, A CARTA 1 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_01, varEstado_01);
    } else if (varPontuacao_01 < varPontuacao_02)
    {
        printf("\n****PARABÉNS, A CARTA 2 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_02, varEstado_02);
    } else {
        printf("\n****CARTA 1 E CARTA 2 EMPATARAM!****\n");
    }

    return 0;
}