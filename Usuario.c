#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include "ferramentas.h"
#define col 3



//Função de login
void log (){

    loginU log_1[5];
    char l[50];
    char snh[50];
    int op_else;
    int tam=0;

    memset(l, 0x00, sizeof(l));
    memset(snh, 0x00, sizeof(snh));

//Definindo o login é a senha
strcpy (log_1[0] .usuario, "Oruam");
strcpy (log_1[0] . senha, "6567");


gotoxy(col,1); printf("-------[Informe o Login e a Senha]-------");
gotoxy(col,3);printf("Login: ");
gotoxy(col,5);printf("Senha: ");
gotoxy(col,7);printf("------------------------------------------");
gotoxy (10,3); scanf ("%s", l);
fflush (stdin);
gotoxy(10,5);do{
            snh[tam] = getch();
            if(snh[tam]== 0x08 && tam > 0){ //backspace
                printf("\b \b");
                snh[tam] =  0x00;
                tam --;
            }
            else if (snh[tam]== 13) {      //enter
                snh[tam] = 0x00;
                break;
            }

            else if (snh[tam] != 0x08){
                putchar('*');
                tam++;
            }
}   while (tam < 10);

//gotoxy(10,5);scanf("%s", s);



    //validando a senha e o usuario
if ((strcmp(l,log_1[0] . usuario) == 0) && (strcmp (snh,log_1[0].senha) == 0)){
        system ("color 02");

        gotoxy(col,9);printf("Login Efetuado com Sucesso... ");
            sleep(2);
            system("cls");
            system ("color 06");
            menu_usuario ();
         }
         else{
            system ("color 4");
            gotoxy(col,9);printf("**[Senha e/ou login incorretas]**");
            gotoxy(col,11);printf("1-Tente novamente");
            gotoxy(col,13);printf("2-Sair");
            gotoxy(col,15);printf("Selecione: ");
            scanf("%d", &op_else);
            fflush(stdin);
            printf("\n");

            switch (op_else){
                case 1:
                    gotoxy(col,17);printf("Tente novamente...");
                    sleep (1);
                    system("cls");
                    system("color 06");
                    log ();
                    break;

                case 2:
                    gotoxy(col,17);printf("Encerrando a sessão...");
                    sleep (1);
                    system ("cls");
                    system("color 06");
                    main ();
                    break;





               default:
               {
                    gotoxy(col,17);printf("Opção inválida, encerrando a sessão...");
                    sleep (1);
                    system ("cls");
                    //system("color 06");
                    main ();
                    break;

               }

            }


         }



}
//////////////////////////////////////////////////////////////////////////////////////
//menu do usuario
void menu_usuario (){
int op;
gotoxy(col,1);printf ("------------[Menu]------------");
gotoxy(col,3);printf("[1] Cadastrar Palestra");
gotoxy(col,5);printf("[2] Palestras Disponiveis ");
//gotoxy(col,7);printf("[3] Cadeiras Disponiveis");
gotoxy(col,7);printf("[3] Sair");
gotoxy(col,9);printf("------------------------------");
gotoxy(col,11);printf("Selecione: ");
scanf("%d", &op);

    switch(op){
        case 1:
            gotoxy(col,13);printf("Carregando...");
            sleep(2);
            system("cls");
            cadastrar_Palestra();
            break;


        case 2:
            gotoxy(col,13);printf("Carregando...");
            sleep(2);
            system("cls");
            palestras_cadastradas();
            break;

        case 3:
            gotoxy(col,13);printf("Encerrando a sessão...");
            sleep(2);
            system("cls");
            main();
            break;

        default:
            gotoxy(col,13);printf("Opção Inválida!");
            Sleep(2);
            system("cls");
            menu_usuario();


    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//função responsavel por cadastrar as palestras

void cadastrar_Palestra (){
    int op;
    int categoria=0;
    infoPalestras info_p;

    FILE *Cad_Palestra;

                gotoxy(col,1); printf("-------[Cadastrar Nova Palestra]-------");
                gotoxy(col,3);printf("Tema da Palestra:");
                gotoxy(col,5);printf("Palestrante:");
                gotoxy(col,7);printf("Data:");
                gotoxy(col,9);printf("Local:");
                gotoxy(col,11);printf("Horário:");
                gotoxy(col,13);printf("Cadeiras:");
                gotoxy(col,15);printf("[1] Motivacional");
                gotoxy(col,16);printf("[2] Educacional");
                gotoxy(col,17);printf("Selecione a categoria:");
                gotoxy(col,19);printf("---------------------------------------");
                fflush(stdin);
                gotoxy(21,3);fgets(info_p.Palestra, 50,stdin);
                    info_p.Palestra[strcspn(info_p.Palestra, "\n")]=0;
                gotoxy(16,5);fgets(info_p.Palestrante, 50, stdin);
                    info_p.Palestrante[strcspn(info_p.Palestrante, "\n")]=0;
                gotoxy(9,7);fgets(info_p.Data, 50, stdin);
                    info_p.Data[strcspn(info_p.Data, "\n")]=0;
                gotoxy(10,9);fgets(info_p.Local, 50, stdin);
                    info_p.Local[strcspn(info_p.Local, "\n")]=0;
                gotoxy(12,11);fgets(info_p.Horario, 50, stdin);
                    info_p.Horario[strcspn(info_p.Horario, "\n")]=0;
                gotoxy(13,13);fgets(info_p.Cadeiras, 50, stdin);
                    info_p.Cadeiras[strcspn(info_p.Cadeiras, "\n")]=0;
                gotoxy(26,17);scanf("%d",&categoria);
                gotoxy(col,21);printf("Dados Preenchidos.");
                gotoxy(col,23);printf("[1]Salvar");
                gotoxy(col,24);printf("[2]Cancelar");
                gotoxy(col,26);printf("Selecione:");
                gotoxy(15,26);scanf("%d", &op);
                    if(op==1){

                                if(categoria==1){
                                  Cad_Palestra=fopen("Palestras_mot.dat", "ab+");
                                    //if(Cad_Palestra == NULL){printf("Erro ao salvar os dados");
                                        fwrite(&info_p, sizeof(infoPalestras),1,Cad_Palestra);
                                        gotoxy(col,28);printf("Salvando Os Dados...");
                                        sleep(1);
                                        system("color 02");
                                        gotoxy(col,28);printf("Dados Salvos! Retornando ao menu...");
                                        fclose(Cad_Palestra);
                                        sleep(2);
                                        system("cls");
                                        system("color 06");
                                        menu_usuario();

                                      }


                                   else if(categoria ==2){
                                       Cad_Palestra=fopen("Palestras_edu.dat", "ab+");
                                      //if(Cad_Palestra == NULL){
                                        //gotoxy(col,29);printf("Erro ao salvar os dados");}
                                        fwrite(&info_p, sizeof(infoPalestras),1,Cad_Palestra);
                                        gotoxy(col,28);printf("Salvando Os Dados...");
                                        sleep(1);
                                        system("color 02");
                                        gotoxy(col,28);printf("Dados Salvos! Retornando ao menu...");
                                        fclose(Cad_Palestra);
                                        sleep(2);
                                        system("cls");
                                        system("color 06");
                                        menu_usuario();

                                       }
                                }



                            else if (op==2){
                                system("color 04");
                                gotoxy(col,28);printf("Cancelado! Retornando ao menu...");
                                sleep(2);
                                system("cls");
                                system("color 06");
                                menu_usuario();
                            }


                        else
                        {

                            gotoxy(col,28);printf("Opção inválida, retornando ao menu...");
                            sleep(2);
                            system("cls");
                            menu_usuario();



                        }






                    }



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void relatorio_palestras ()
{

        FILE *RelatorioPalestras;
        FILE *Palestras_m;
        FILE *Palestras_e;
        infoPalestras info_p;
        int op;




        RelatorioPalestras= fopen("Relatorio_Palestras.csv", "w+");
        Palestras_e = fopen("Palestras_edu.dat", "rb");
        Palestras_m = fopen("Palestras_mot.dat", "rb");
        fputs("TEMA; PALESTRANTE; DATA; LOCAL; HORARIO; CADEIRAS;\r", RelatorioPalestras);

        fread(&info_p, sizeof(infoPalestras),1, Palestras_e);
        while (!feof(Palestras_e))
        {
           fprintf(RelatorioPalestras, "%s; %s; %s; %s; %s; %s; \r", info_p.Palestra, info_p.Palestrante, info_p.Data, info_p.Local, info_p.Horario, info_p.Cadeiras);
            fread(&info_p, sizeof(infoPalestras),1, Palestras_e);

        }

        fread(&info_p, sizeof(infoPalestras), 1, Palestras_m);
        while(!feof(Palestras_m))
        {
         fprintf(RelatorioPalestras, "%s; %s; %s; %s; %s; %s; \r", info_p.Palestra, info_p.Palestrante, info_p.Data, info_p.Local, info_p.Horario, info_p.Cadeiras);
         fread(&info_p, sizeof(infoPalestras), 1, Palestras_m);
        }





            fclose(RelatorioPalestras);
            fclose(Palestras_e);
            fclose(Palestras_m);

             gotoxy(col,13);printf("Relatório gerado com sucesso!");

                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("   \n          --------------------");
                            gotoxy(col,15);printf("**Este relatório foi gerado no excel**\n");
                            printf("      -----------------------------");
                            gotoxy(col,19);printf("[1] Retornar ao menu");
                            gotoxy(col,20);printf("[2] Abrir excel");
                            gotoxy(col,22);printf("Selecione: ");
                            gotoxy(14,22);scanf("%d", &op);

                             switch  (op)
                        {
                        case 1:
                          gotoxy(col, 24);printf("Retornando ao menu...");
                          sleep(2);
                          system("cls");
                          system("color 06");
                          menu_administrador();
                          break;


                        case 2:
                          gotoxy(col,24);printf("Abrindo Excel...");
                          sleep(2);
                          system("start Excel");
                          system("cls");
                          system("color 06");
                          menu_administrador();
                          break;


                         default:

                             gotoxy(col, 24);printf("Opção inválida, retornando ao menu...");
                             sleep(2);
                             system("cls");
                             system("color 06");
                             menu_administrador();
                             break;


                        }





}







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void palestras_cadastradas(){

        FILE *p_cadastradas;
        infoPalestras info_p;
        int categoria;
        int op;
        int cont;


            gotoxy(col,1);printf("-----------[Filtrar Palestra]-----------");
            gotoxy(col,3);printf("[1] Motivacional");
            gotoxy(col,5);printf("[2] Educacional");
            gotoxy(col,7);printf("Selecione: ");
            gotoxy(col,9);printf("----------------------------------------");
            gotoxy(14,7);scanf("%d", &categoria);

            if(categoria==1){
                p_cadastradas=fopen("Palestras_mot.dat", "rb");
                if(p_cadastradas==NULL){
                    printf("Erro ao carregar os dados");

                }
                else if (p_cadastradas)
                    {


                        printf("\n");
                        printf("\n");
                        printf("\n");
                        printf("\t \t \t \t \t   PRÓXIMAS PALESTRAS MOTIVACIONAIS:");

                    while(!feof(p_cadastradas)){
                       if( fread(&info_p, sizeof(infoPalestras),1,p_cadastradas)){
                    //printf("\n");
                    //printf("\n");
                    printf("\n");
                    printf("\n");
                    //printf("   ------ Próxima palestra Motivacional ------\n");
                    printf(" TEMA:%s", info_p.Palestra);
                    printf("  PALESTRANTE: %s", info_p.Palestrante);
                    printf("  DATA:%s", info_p.Data);
                    printf("  LOCAL:%s", info_p.Local);
                    printf("  HORÁRIO:%s", info_p.Horario);
                    printf("  CADEIRAS:%s", info_p.Cadeiras);
                    //printf("   ------------------------------------------");
                    }
                    }
                    fclose(p_cadastradas);
                    //gotoxy(col,27);
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("[1]Fazer outra busca");
                    //gotoxy(col,28);
                    //printf("\n");
                    printf("\n");
                    printf("[2]Retornar ao menu");
                    //gotoxy(col,30);
                    printf("\n");
                    printf("\n");
                    printf("Selecione: ");scanf("%d", &op);
                    //gotoxy(14,30);

                        switch (op){

                        case 1:
                                printf("\n");
                                printf("Limpando..");
                                sleep(2);
                                system("cls");
                                palestras_cadastradas();
                                break;

                            case 2:
                                printf("\n");
                                printf("Retornando ao menu...");
                                sleep(2);
                                system("cls");
                                menu_usuario();
                                break;

                            }






                    }
        }



            if(categoria==2){
                p_cadastradas=fopen("Palestras_edu.dat", "rb");
                if(p_cadastradas==NULL){
                    printf("Erro ao carregar os dados");

                }
                else if (p_cadastradas)
                    {
                        printf("\n");
                        printf("\n");
                        printf("\n");
                        printf("\t \t \t \t \t   PRÓXIMAS PALESTRAS EDUCACIONAIS:");

                    while(!feof(p_cadastradas)){
                       if( fread(&info_p, sizeof(infoPalestras),1,p_cadastradas)){
                    printf("\n");
                    printf("\n");
                    //printf("   ------ Próxima palestra Motivacional ------\n");
                    printf(" TEMA:%s", info_p.Palestra);
                    printf("  PALESTRANTE: %s", info_p.Palestrante);
                    printf("  DATA:%s", info_p.Data);
                    printf("  LOCAL:%s", info_p.Local);
                    printf("  HORÁRIO:%s", info_p.Horario);
                    printf("  CADEIRAS:%s", info_p.Cadeiras);
                    }
                    }
                    fclose(p_cadastradas);
                    //gotoxy(col,27);
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("[1]Fazer outra busca");
                    //gotoxy(col,28);
                    printf("\n");
                    printf("[2]Retornar ao menu");
                    //gotoxy(col,30);
                    printf("\n");
                    printf("\n");
                    printf("Selecione: ");scanf("%d", &op);
                    //gotoxy(14,30);



                        switch (op){

                            case 1:
                                printf("\n");
                                printf("Limpando..");
                                sleep(2);
                                system("cls");
                                palestras_cadastradas();
                                break;

                            case 2:
                                printf("\n");
                                printf("Retornando ao menu...");
                                sleep(2);
                                system("cls");
                                menu_usuario();
                                break;

                            }






                    }
        }









}






















































