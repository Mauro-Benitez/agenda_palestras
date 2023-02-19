#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "ferramentas.h"
#include <conio.h>
#define col 3





void log_adm (){
    loginA log_A1 [5];
    //variaveis que aramazenaram a senha e o adm
    char a [50];
    char s [50];
    int op_else;
    int tam=0;

     memset(a, 0x00, sizeof(a));
    memset(s, 0x00, sizeof(s)); //limpando as variaveis



    //definindo a senha e o adm
    strcpy (log_A1 [0] .administrador, "mauro-adm");
    strcpy (log_A1 [0].senha, "93129");


gotoxy(col,1);printf("----------[Administrador e Senha]----------");
gotoxy(col,3);printf("Administrador: ");
gotoxy(col,5);printf("Senha: ");
gotoxy(col,7);printf("------------------------------------------");
gotoxy(18,3);scanf ("%s", a);
fflush (stdin);
gotoxy(10,5);do{
            s[tam] = getch();
            if(s[tam]== 0x08 && tam > 0){ //backspace
                printf("\b \b");
                s[tam] =  0x00;
                tam --;
            }
            else if (s[tam]== 13) {      //enter
                s[tam] = 0x00;
                break;
            }

            else if (s[tam] != 0x08){
                putchar('*');
                tam++;
            }
}   while (tam < 10);


    //validando a senha e o usuario
    if ( (strcmp(a , log_A1[0].administrador) == 0) && (strcmp (s, log_A1[0].senha) == 0)){
        system ("color 02");
        gotoxy (col,9);printf("Login efetuado com sucesso!");
        sleep(2);
        system ("cls");
        system("color 06");
        menu_administrador();
        }

        else {

            system ("color 04");
            gotoxy(col,9);printf("**[Senha e/ou Administrador incorretas]**");
            gotoxy(col,11);printf(" [1]-Tentar novamente");
            gotoxy(col,13);printf(" [2]-Sair");
            gotoxy(col,15);printf(" Escolha um opção: ");
            scanf("%d", &op_else);
            fflush(stdin);
            printf("\n");


            switch (op_else){
                case 1:
                    gotoxy(col,17);printf("Tente novamente...");
                    sleep(1);
                    system("cls");
                    system("color 06");
                    log_adm ();
                    break;


                case 2:
                    gotoxy(col,19);printf("Encerrando a sessão...");
                    sleep(2);
                    system("cls");
                    system("color 06");
                    main ();
                    break;




                default:
                    gotoxy(col,19);printf("Opção inválida, encerrando a sessão...");
                    sleep(2);
                    system("cls");
                    system("color 06");
                    main ();
                    break;

            }


        }

}

///////////////////////////////////////////////////////////////////////
//menu do adm
void menu_administrador(){

    int op;

gotoxy(col,1);printf ("------------[Menu]------------");
gotoxy(col,3);printf("[1] Cadastrar Palestrante");
gotoxy(col,5);printf("[2] Dados dos Palestrantes");
gotoxy(col,7);printf("[3] Relatorios");
gotoxy(col,9);printf("[4] Sair");
gotoxy(col,11);printf("------------------------------");
gotoxy(col,13);printf("Escolha uma opção: ");
scanf("%d", &op);

    switch (op){

    case 1:
        gotoxy(col,15);printf("Carregando...");
        sleep(2);
        system("cls");
        cadastro_p();

    case 2:
        gotoxy(col,15);printf("Carregando dados...");
        sleep(2);
        system("cls");
        dados_p ();
        break;

    case 3:
        gotoxy(col,15);printf("Carregando...");
        sleep(2);
        system("cls");
        relatorios();

    case 4:
        gotoxy(col,15);printf("Encerrando a sessão...");
        sleep(2);
        system ("cls");
        main ();
        break;
    default:
        gotoxy(col,15);printf("Opção inválida.");
        sleep(2);
        system("cls");
        menu_administrador();
        break;


    }




}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//cadastro de usuario

    void cadastro_p(){
        dados dd  ;
        int op;
        FILE *P_Cad;
            fflush(stdin);
            gotoxy(col,1);printf("-----------[CADASTRO DE PALESTRANTE]-----------");
            gotoxy(col,3);printf("NOME: ");
            gotoxy(col,5);printf("CPF: ");
            gotoxy(col,7);printf("E-MAIL: ");
            gotoxy(col,9);printf("CELULAR: ");
            gotoxy(col,11);printf("CATEGORIA: ");
            gotoxy(col,13);printf("ÁREA DE ATUAÇÃO: ");
            gotoxy(col,15);printf("-----------------------------------------------");
            fflush(stdin);
            gotoxy(9,3);fgets(dd.nome, 50, stdin);
            dd.nome[strcspn(dd.nome, "\n")]=0;
            gotoxy(8,5);fgets(dd.cpf, 50, stdin);
            dd.cpf[strcspn(dd.cpf, "\n")]=0;
            gotoxy(11,7);fgets(dd.email, 50, stdin);
            dd.email[strcspn(dd.email, "\n")]=0;
            gotoxy(12,9);fgets(dd.celular,50, stdin);
            dd.celular[strcspn(dd.celular, "\n")]=0;

            gotoxy(14,11);fgets(dd.categoria,50 ,stdin);
            dd.categoria[strcspn(dd.categoria, "\n")]=0;
            gotoxy(20,13);fgets(dd.atuacao, 50, stdin);
              dd.atuacao[strcspn(dd.atuacao, "\n")]=0;


            gotoxy(col,17);printf("Dados Preenchidos.");
            gotoxy(col,19);printf("[1]Salvar");
            gotoxy(col,20);printf("[2]Cancelar");
            gotoxy(col,22);printf("Selecione:");
            gotoxy(14,22);scanf("%d", &op);
                if(op==1){

                    P_Cad= fopen ("Palestrantes_Cadastrados.dat","ab+");
                        if (P_Cad==NULL){
                            printf("Erro ao salvar arquivo");
                        }
                          else {
                            fwrite(&dd, sizeof(dados), 1, P_Cad);
                            gotoxy(col,25);printf("Salvando Os Dados...");
                            sleep(1);
                            system("color 02");
                            gotoxy(col,27);printf("Dados Salvos! Retornando ao menu...");
                            sleep(2);
                            fclose(P_Cad);
                            system("cls");
                            system("color 06");
                            menu_administrador();



                          }


                }

                else if(op==2){
                    system("color 04");
                    gotoxy(col,25);printf("Cancelado! Retornando ao menu...");
                    sleep(2);
                    system("cls");
                    system("color 06");
                    menu_administrador();









                }


                else
                {

                     gotoxy(col, 25);printf("Opção invalida, retornando ao menu...");
                            sleep(2);
                            system("cls");
                            menu_administrador();


                }






    }












/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Dados palestrantes


 void dados_p (){
    dados dd  ;
    FILE *P_dados;
    int op;

    //gotoxy(col,1);
    printf("\t \t \t \t ----------[DADOS DOS PALESTRANTES]----------");
    //printf("----------[DADOS DOS PALESTRANTES]----------");

        P_dados=fopen("Palestrantes_Cadastrados.dat","rb");

            if(P_dados == NULL){
            printf("Erro ao carregar dados");
            }

                else if (P_dados){
                   while(!feof(P_dados)){
                    if(fread(&dd, sizeof(dados), 1, P_dados)){
                       printf("\n");
                       printf("\n");
                       printf("   NOME: %s", dd.nome);
                       printf("   EMAIL: %s", dd.email);
                       printf("   TIPO: %s", dd.categoria);
                    }

                   } fclose(P_dados);

                        gotoxy(32,14);printf("      -------------------------------------");
                            gotoxy(30,15);printf("**Para dados mais detalhados, no menu selecione 'Relatório'**\n");
                           gotoxy(32,16); printf("      -------------------------------------");
                        printf("\n");
                        printf("\n");
                        printf("   [1] Retornar ao menu");
                        printf("\n");
                        printf("\n");
                        printf("   Selecione: ");
                        scanf("%d",&op);

                        switch(op){

                        case 1:
                            printf("\n");
                            printf("\n");
                            printf("   Retornando ao menu...");
                            sleep(2);
                            system("cls");
                            menu_administrador();
                            break;

                        default:
                            printf("\n");
                            printf("\n");
                            printf("   Opção invalida, retornando ao menu...");
                            sleep(2);
                            system("cls");
                            menu_administrador();
                            break;


                        }



            }



 }





//relatorios
//////////////////////////////////////////////////////////////////////////////////////////////////////

void relatorios (){
 FILE *rel;
 FILE *dados_pa;
 FILE *rel_p;
 FILE *P_Cad;
 char senha[50]; strcpy(senha, "93129");
 char teste_senha [50];
 int op;
 dados dd  ;
 int op1;
 int tam =0;




        gotoxy(col,1);printf("------------[RELATÓRIOS]------------");
        gotoxy(col,3);printf("[1] Dados Completos dos Palestrantes");
        gotoxy(col,5);printf("[2] Todas as Palestras ");
        gotoxy(col,7);printf("[3] Sair");
        gotoxy(col,9);printf("------------------------------------");
        gotoxy(col,10);printf("Selecione:");
        gotoxy(14,10);scanf("%d", &op);

                if(op==1){

                gotoxy(col,13);printf("Digite a senha novamente:");
                gotoxy(col,15);printf("Senha:");
                gotoxy(10,15);do{
                teste_senha[tam] = getch();
                if(teste_senha[tam]== 0x08 && tam > 0){ //backspace
                printf("\b \b");
                teste_senha[tam] =  0x00;
                tam --;
                    }
                    else if (teste_senha[tam]== 13) {      //enter
                    teste_senha[tam] = 0x00;
                    break;
                    }

                    else if (teste_senha[tam] != 0x08){
                    putchar('*');
                    tam++;
                    }
                }    while (tam < 10);
                    if(strcmp(teste_senha, senha)==0)

                    {
                    system("color 02");
                    gotoxy(col,17);printf("Gerando relatório...");
                    sleep(1);
                    rel=fopen("Relatorio_palestrantes.csv","w+");
                    dados_pa=fopen("Palestrantes_Cadastrados.dat", "rb");
                    fputs("NOME; CPF; EMAIL; CELULAR; CATEGORIA; ÁREA;\r", rel);
                    fread(&dd, sizeof(dados), 1, dados_pa);
                    while(!feof(dados_pa))
                    {
                        fprintf(rel, "%s; %s; %s; %s; %s; %s; \r", dd.nome, dd.cpf, dd.email, dd.celular, dd.categoria, dd.atuacao);
                        fread(&dd, sizeof(dados), 1, dados_pa);

                    }




                        fclose(rel);
                        fclose(dados_pa);
                         gotoxy(col,13);printf("Relatório gerado com sucesso!");

                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("   \n          --------------------");
                            gotoxy(col,15);printf("**Este relatório foi gerado no excel**\n");
                            printf("      -----------------------------");
                            gotoxy(col,20);printf("[1] Retornar ao menu");
                            gotoxy(col,21);printf("[2] Abrir excel");


                    gotoxy(col,23);printf("Selecione: ");
                    gotoxy(14,23);scanf("%d", &op1);


                        switch  (op1)
                        {
                        case 1:
                          gotoxy(col, 25);printf("Retornando ao menu...");
                          sleep(2);
                          system("cls");
                          system("color 06");
                          menu_administrador();
                          break;


                        case 2:
                          gotoxy(col,25);printf("Abrindo Excel...");
                          sleep(2);
                          system("start Excel");
                          system("cls");
                          system("color 06");
                          menu_administrador();
                          break;


                         default:

                             gotoxy(col, 25);printf("Opção inválida, retornando ao menu...");
                             sleep(2);
                             system("cls");
                             system("color 06");
                             menu_administrador();
                             break;


                        }


                    }

                    else


                    {

                        fflush(stdin);
                        system("color 04");
                        gotoxy(col,19);printf("Senha invalida, retornando ao menu...");
                        sleep(2);
                        system("cls");
                        system("color 06");
                        menu_administrador();

                    }




                }


            else if(op==2)
            {

                gotoxy(col,13);printf("Digite a senha novamente:");
                gotoxy(col,15);printf("Senha:");
                gotoxy(10,15);do{
            teste_senha[tam] = getch();
            if(teste_senha[tam]== 0x08 && tam > 0){ //backspace
                printf("\b \b");
                teste_senha[tam] =  0x00;
                tam --;
            }
            else if (teste_senha[tam]== 13) {      //enter
                teste_senha[tam] = 0x00;
                break;
            }

            else if (teste_senha[tam] != 0x08){
                putchar('*');
                tam++;
            }
                }   while (tam < 10);


                if(strcmp(teste_senha, senha)==0)
                {   system("color 02");
                    gotoxy(col,17);printf("Gerando relatorio...");
                    sleep(2);
                    relatorio_palestras();


                }





            }

            else if(op==3)
            {
                        gotoxy(col, 13);printf("Retornando ao menu...");
                        sleep(2);
                        system("cls");
                        system("color 06");
                        menu_administrador();
            }



            else
            {
                gotoxy(col, 13);printf("Opção invalida, retornando ao menu...");
                        sleep(2);
                        system("cls");
                        system("color 06");
                        menu_administrador();
            }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//relatorio das palestras



























