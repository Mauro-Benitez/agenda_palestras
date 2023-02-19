#ifndef DADOS_CLIENTE_H_INCLUDED
#define DADOS_CLIENTE_H_INCLUDED
#define SIZE 100

//Função que guarda os dados do usuario
typedef struct {
    char nome [50];
    char cpf[50];
    char email [50];
    char celular [50];
    char categoria [50];
    char atuacao [50];
}dados;


//////////////////////////////////////////////////////////


//login do usuario
typedef struct login_Usu{
    char usuario [50];
    char senha [50] ;
}loginU;

////////////////////////////////////////////////////////////


//login do adm
typedef struct login_Adm{
    char administrador [50];
    char senha [50];
}loginA;




////////////////////////////////////////////////////////////////
//Palestras
typedef struct {
    char Palestra [50];
    char Palestrante [50];
    char Data [50];
    char Local [50];
    char Cadeiras [50];
    char Horario [50];
    int categoria [50];
} infoPalestras;



/////////////////////////////////////////////////
///posição de cursor
//void gotoxy ();


#endif DADOS_CLIENTE_H_INCLUDED
