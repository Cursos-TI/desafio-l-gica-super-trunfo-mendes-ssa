#include <stdio.h>

int main() {
    
    unsigned long int varPopulacao_01 = 0, varPopulacao_02 = 0; //PODE RECEBER NÚMEROS MAIORES

    int varPontosTuristicos_01 = 0, varPontosTuristicos_02 = 0;

    int varSelecaoModoDisputa = 0, varSelecaoAtributoDisputa = 0;

    int varPontuacao_01 = 0, varPontuacao_02 = 0, varEmpate = 0;

    float varPIB_01 = 0, varPIB_02 = 0;

    float varArea_01 = 0, varArea_02 = 0;

    float varDensidadePopulacional_01 = 0, varDensidadePopulacional_02 = 0;

    float varPIBperCapita_01 = 0, varPIBperCapita_02 = 0;

    float varSuperPoder_01 = 0, varSuperPoder_02 = 0;

    char varCidade_01[51], varCidade_02[51];

    char varEstado_01[3], varEstado_02[3];

    //INTRUÇÕES INICIAIS
    printf("==== SUPER TRUNFO CIDADES ====");
    printf("\nPara jogar, é necessário cadastrar duas cartas.");
    printf("\nCada carta terá informações de uma cidade.");
    printf("\nO cadastro de cada carta será feito separadamente.\n");
    printf("\nVamos começar!\n"); 

    //DADOS PRIMEIRA CARTA
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

            //CÁLCULOS
            varDensidadePopulacional_01 = varPopulacao_01/varArea_01;
            varPIBperCapita_01 = varPIB_01/varPopulacao_01;
            varSuperPoder_01 = (
                (float)(varPopulacao_01 + varPontosTuristicos_01) +
                varArea_01 +
                varPIB_01 +
                varPIBperCapita_01 +
                1.0f / varDensidadePopulacional_01
            );
              
    //DADOS SEGUNDA CARTA
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

            //CÁLCULOS
            varDensidadePopulacional_02 = varPopulacao_02/varArea_02;
            varPIBperCapita_02 = varPIB_02/varPopulacao_02;
            varSuperPoder_02 = (
                (float)(varPopulacao_02 + varPontosTuristicos_02) +
                varArea_02 +
                varPIB_02 +
                varPIBperCapita_02 +
                1.0f / varDensidadePopulacional_02
            );           

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

    //O JOGADOR FARÁ A SELEÇÃO SE QUER A COMPARAÇÃO DE TODOS OS ATRIBUTOS (CASE 1), OU SE QUER A COMPARAÇÃO DE UM ÚNICO ATRIBUTO (CASE 2).
    printf("\n\nAgora que as duas cartas foram cadastradas, selecione como deverá ser a disputa:");
    printf("\n1. Comparação de TODOS os Atributos.");
    printf("\n2. Comparação de UM Atributo.");
    printf("\nSelecione: ");
    scanf("%d", &varSelecaoModoDisputa);

    switch (varSelecaoModoDisputa)
    {
        //COMPARAÇÃO DE TODOS OS ATRIBUTOS
    case 1:
        //AQUI O PROGRAMA VAI ADICIONANDO 1 PONTO PARA CADA RESULTADO DA COMPARAÇÃO
            //POPULAÇÃO
        if (varPopulacao_01 < varPopulacao_02){
            varPontuacao_02++;
        } else if (varPopulacao_01 > varPopulacao_02){
            varPontuacao_01++;
        } else {
            varEmpate++;
        }
            //ÁREA
        if (varArea_01 < varArea_02){
            varPontuacao_02++;
        } else if (varArea_01 > varArea_02){
            varPontuacao_01++;
        } else {
            varEmpate++;
        }
            //PIB
        if (varPIB_01 < varPIB_02){
            varPontuacao_02++;
        } else if (varPIB_01 > varPIB_02){
            varPontuacao_01++;
        } else {
            varEmpate++;
        }
            //PONTOS TURÍSTICOS
        if (varPontosTuristicos_01 < varPontosTuristicos_02){
            varPontuacao_02++;
        } else if (varPontosTuristicos_01 > varPontosTuristicos_02){
                varPontuacao_01++;
        } else {
            varEmpate++;
        }        
            //DENSIDADE POPULACIONAL (MENOR)
        if (varDensidadePopulacional_01 > varDensidadePopulacional_02){
            varPontuacao_02++;
        } else if (varDensidadePopulacional_01 < varDensidadePopulacional_02){
            varPontuacao_01++;
        } else {
            varEmpate++;
        }
            //PIB PER CAPITA
        if (varPIBperCapita_01 < varPIBperCapita_02){
            varPontuacao_02++;
        } else if (varPIBperCapita_01 > varPIBperCapita_02){
            varPontuacao_01++;
        } else {
            varEmpate++;
        }
            //SUPER PODER
        if (varSuperPoder_01 < varSuperPoder_02){
            varPontuacao_02++;
        } else if (varSuperPoder_01 > varSuperPoder_02){
            varPontuacao_01++;
        } else {
            varEmpate++;
        }

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
            printf("\n****CARTA 1 E CARTA 2 EMPATARAM!****");
        }
    break;

        //COMPARAÇÃO DE UM ÚNICO ATRIBUTO
    case 2:
        printf("\nEscolha qual Atributo será comparado:");
        printf("\n1. População");
        printf("\n2. Área");
        printf("\n3. PIB");
        printf("\n4. Pontos Turíticos");
        printf("\n5. Densidade Populacional (menor)");
        printf("\n6. PIB per Capita");
        printf("\nEscolha: ");
        scanf("%d", &varSelecaoAtributoDisputa);

        switch (varSelecaoAtributoDisputa)
        {
        case 1:
            printf("\nATRIBUTO SELECIONADO: POPULAÇÃO\n");
            if (varPopulacao_01 > varPopulacao_02){
                printf("\nPOPULAÇÃO DA CARTA 1 (%lu Hab) É MAIOR QUE A POPULÇÃO DA CARTA 2 (%lu Hab).", varPopulacao_01, varPopulacao_02);
                printf("\n****PARABÉNS, A CARTA 1 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_01, varEstado_01);
            } else if (varPopulacao_01 < varPopulacao_02){
                printf("\nPOPULAÇÃO DA CARTA 2 (%lu Hab) É MAIOR QUE A POPULAÇÃO DA CARTA 1 (%lu Hab).", varPopulacao_02, varPopulacao_01);
                printf("\n****PARABÉNS, A CARTA 2 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_02, varEstado_02);
            } else {
                printf("\n****CARTA 1 E CARTA 2 EMPATARAM!****\n");
            }
        break;

        case 2:
            printf("\nATRIBUTO SELECIONADO: ÁREA\n");
            if (varArea_01 > varArea_02){
                printf("\nÁREA DA CARTA 1 (%.3f km²) É MAIOR QUE A ÁREA DA CARTA 2 (%.3f km²).", varArea_01, varArea_02);
                printf("\n****PARABÉNS, A CARTA 1 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_01, varEstado_01);
            } else if (varArea_01 < varArea_02){
                printf("\nÁREA DA CARTA 2 (%.3f km²) É MAIOR QUE A ÁREA DA CARTA 1 (%.3f km²).", varArea_02, varArea_01);
                printf("\n****PARABÉNS, A CARTA 2 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_02, varEstado_02);
            } else {
                printf("\n****CARTA 1 E CARTA 2 EMPATARAM!****\n");
            }
        break;

        case 3:
            printf("\nATRIBUTO SELECIONADO: PIB\n");
            if (varPIB_01 > varPIB_02){
              printf("\nPIB DA CARTA 1 (R$ %.2f) É MAIOR QUE O PIB DA CARTA 2 (R$ %.2f).", varPIB_01, varPIB_02);
              printf("\n****PARABÉNS, A CARTA 1 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_01, varEstado_01);
            } else if (varPIB_01 < varPIB_02){
              printf("\nPIB DA CARTA 2 (R$ %.2f) É MAIOR QUE O PIB DA CARTA 1 (R$ %.2f).", varPIB_02, varPIB_01);
              printf("\n****PARABÉNS, A CARTA 2 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_02, varEstado_02);
            } else {
              printf("\n****CARTA 1 E CARTA 2 EMPATARAM!****\n");
            }
        break;

        case 4:
            printf("\nATRIBUTO SELECIONADO: PONTOS TURÍSTICOS\n");
            if (varPontosTuristicos_01 > varPontosTuristicos_02){
                printf("\nNÚMERO DE PONTOS TURÍSTICOS DA CARTA 1 (%d) É MAIOR QUE O NÚMERO DE PONTOS TURÍSTICOS DA CARTA 2 (%d).", varPontosTuristicos_01, varPontosTuristicos_02);
                printf("\n****PARABÉNS, A CARTA 1 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_01, varEstado_01);
            } else if (varPontosTuristicos_01 < varPontosTuristicos_02){
                printf("\nNÚMERO DE PONTOS TURÍSTICOS DA CARTA 2 (%d) É MAIOR QUE O NÚMERO DE PONTOS TURÍSTICOS DA CARTA 1 (%d).", varPontosTuristicos_02, varPontosTuristicos_01);
                printf("\n****PARABÉNS, A CARTA 2 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_02, varEstado_02);
            } else {
                printf("\n****CARTA 1 E CARTA 2 EMPATARAM!****\n");        
            }
        break;

        case 5:
            printf("\nATRIBUTO SELECIONADO: DENSIDADE POPULACIONAL\n");
            if (varDensidadePopulacional_01 < varDensidadePopulacional_02){
                printf("\nDENSIDADE POPULACIONAL DA CARTA 1 (%.1f Hab/km²) É MENOR QUE A DENSIDADE POPULACIONAL DA CARTA 2 (%.1f Hab/km²).", varDensidadePopulacional_01, varDensidadePopulacional_02);
                printf("\n****PARABÉNS, A CARTA 1 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_01, varEstado_01);
            } else if (varDensidadePopulacional_01 > varDensidadePopulacional_02){
                printf("\nDENSIDADE POPULACIONAL DA CARTA 2 (%.1f Hab/km²) É MENOR QUE A DENSIDADE POPULACIONAL DA CARTA 1 (%.1f Hab/km²).", varDensidadePopulacional_02, varDensidadePopulacional_01);
                printf("\n****PARABÉNS, A CARTA 2 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_02, varEstado_02);
            } else {
                printf("\n****CARTA 1 E CARTA 2 EMPATARAM!****\n");
            }
        break;

        case 6:
            printf("\nATRIBUTO SELECIONADO: PIB PER CAPITA\n");
            if (varPIBperCapita_01 > varPIBperCapita_02){
                printf("\nPIB PER CAPITA DA CARTA 1 (R$ %.2f) É MAIOR QUE O PIB PER CAPITA DA CARTA 2 (R$ %.2f).", varPIBperCapita_01, varPIBperCapita_02);
                printf("\n****PARABÉNS, A CARTA 1 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_01, varEstado_01);
            } else if (varPIBperCapita_01 < varPIBperCapita_02){
                printf("\nPIB PER CAPITA DA CARTA 2 (R$ %.2f) É MAIOR QUE O PIB PER CAPITA DA CARTA 1 (R$ %.2f).", varPIBperCapita_02, varPIBperCapita_01);
                printf("\n****PARABÉNS, A CARTA 2 ( %s - %s ) É A VENCEDORA!!****\n", varCidade_02, varEstado_02);
            } else {
                printf("\n****CARTA 1 E CARTA 2 EMPATARAM!****\n");
            }
        break;
        
        default:
            printf("\n**Atributo Inválido!**\n");
        break;
        }
    break;

    default:
        printf("\n**Opção Inválida!**\n");
    break;
    }

    return 0;
}