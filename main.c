/* *** ******* ALUNOS ******* *** */
// Augusto Furlan   201400093
// Matheus Barros   201710669
/* ******* ---------- ******* *** */

/* ******* FUNCIONALIDADES ******* *** */
/*
 * Criar Diretorios - OK
 * Navegar pelos diretorios OK
 * Listar diretorios OK
 * Exibir posicao (pwd) OK
 * Login - OK
 * Exibir nomes da equipe copyright - OK
 * Exibir informação do usuário id username - OK
 * Encerrar sessao logout - OK
 
 * Remover Diretorio (Verificar se existe filho)
 * Adicionar user adduser username so root pode
 * Remover user deluser username so root pode
 * Bloquear usuario block username so root pode
 * Desbloquear username unlock username so root pode
 * o usuario so pode editar as pastas abaixo dele
 * Encerrar programa (poweroff) apenas o root pode fazer
 * Exibir a data date - pode ser junto com hr ?
 * Exibir a hora time - - pode ser junto com hr ?
 * Salvar todos os dados em arquivo para nao perder na hora reiniciar o programa
 */
/* ******* -------------- ******* *** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[9];
    int father_id;
    int property_id;
    struct Dirs *prox;
    
} Dirs;

typedef struct {
    int id;
    char name[100];
    char login[9];
    int status;
    int dirId;
    struct Users *prox;
    
} Users;
//typedef struct Dirs TDirs;
//---------------------------------------------------------------------------



/* -----------------------------------------------------------------------------
 Prototipos das funcoes
 ------------------------------------------------------------------------------*/
void Inicializar_Dirs (Dirs *inicio);
void Inicializar_Users (Users *users);
void Inserir (Dirs *inicio);
void Listar (Dirs *inicio);
void Remove (Dirs *inicio);
void PWD (Dirs *inicio);
void CD (Dirs *inicio);
void Copyright();
void userInfo (Users *inicio);
void Logout ();

void Login (Users *inicio, char* name);
void ShowDateTime ();


/* Variaveis global */
int id=0, currentDir = 0, current_user = 0, userId=0;
char parans[9];


/* -----------------------------------------------------------------------------
 PRINCIPAL
 ------------------------------------------------------------------------------*/
int main(void)
{
    
    Dirs *ini = (Dirs *) malloc(sizeof(Dirs));
    Users *ini_users = (Users *) malloc(sizeof(Users));
    
    char linha_comando[80], *comando, *parametro, *aux;
    Inicializar_Dirs(&ini);
    Inicializar_Users(&ini_users);
    
    
    
    while (1>0) {
    if(current_user == 0) {
        while (0 == 0) {
            printf("Digite o login: ");
            gets(aux);
            Login(&ini_users, aux);
            if(current_user == 0) {
                printf("\n Desculpe login invalido \n");
            } else {
                break;
            }
        }
    }
    printf("$ ");
    gets(linha_comando);
    comando = strtok(linha_comando, " ");
    parametro = strtok(NULL, "\0");
    if(parametro == NULL) {
        strcpy(parans, " ");
    } else {
        strcpy(parans, parametro);
    }
    
    if(strcmp (comando, "mkdir") == 0) {
        Inserir(&ini);
    }
    if(strcmp (comando, "id") == 0) {
        userInfo(&ini_users);
    }
    if(strcmp (comando, "date") == 0) {
        ShowDateTime();
    }
    if(strcmp (comando, "copyright") == 0) {
        Copyright();
    }
    if(strcmp (comando, "logout") == 0) {
        Logout();
    }
        
    //Inserir(&ini);
    //Inserir(&ini);
    //Inserir(&ini, "TES");
    //Remove(&ini, "test");
    //printf("%s", ini.name);
    if(strcmp (comando, "ls") == 0) {
        Listar(&ini);
    }
    if(strcmp (comando, "pwd") == 0) {
        PWD(&ini);
        //printf("ENTROU PWD");
    }
    if(strcmp (comando, "rmdir") == 0) {
        Remove(&ini);
    }
    if(strcmp (comando, "cd") == 0) {
        CD(&ini);
    }
        
    }
    
    
    
    return 0;
    
}


void Inicializar_Dirs (Dirs *inicio)
{
    inicio->id = id;
    strcpy(inicio->name, "/");
    inicio->father_id = 0;
    inicio->property_id = 1;
    inicio->prox = NULL;
}

void Inicializar_Users (Users *users)
{
    users->id = 1;
    strcpy(users->name, "ROOT");
    strcpy(users->login, "root");
    users->status = 0;
    users->dirId = 0;
    users->prox = NULL;
}

void Inserir (Dirs *inicio)
{
    id++;
    Dirs *percorre;
    
    /* Criacao do novo no - AlocaÁ„o de memoria */
    Dirs *no_novo = (Dirs *) malloc(sizeof(Dirs));
    no_novo -> id = id;
    no_novo -> father_id = currentDir;
    no_novo -> property_id = userId;
    strcpy(no_novo->name, parans);
    no_novo -> prox = NULL;
    
        percorre = inicio;
        while (percorre->prox != NULL)
        {
            percorre = percorre -> prox;
        }
        percorre->prox = no_novo;
    
}


void Listar (Dirs *inicio)
{
    Dirs *percorre;
    percorre = inicio;
    while (1 > 0)
    {
        if(percorre->father_id == currentDir && strcmp (percorre->name, "/") != 0) {
            printf("       %s \n", percorre->name);
        }
        //printf("\n %s", percorre->name);
        
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
    }
    //printf("\n %d", percorre->id);
    
}

void Remove (Dirs *inicio)
{
    int i =0;
    Dirs *percorre, *percorreAnt;
    percorre = inicio;
    while (1 > 0)
    {
        if(percorre->father_id == currentDir && strcmp (percorre->name, parans) == 0 &&percorre->id !=0) {
            
        //if(percorre->id == 1) {
            if(percorre->prox == NULL) {
                percorreAnt -> prox = NULL;
                free(percorre);
            } else {
                //meio
                percorreAnt->prox = percorre->prox;
            }
        }
        if(percorre->prox == NULL) {break;}
        percorreAnt = percorre;
        percorre = percorre -> prox;
        i++;
    }
  
}


void CD (Dirs *inicio)
{
    Dirs *percorre;
    percorre = inicio;
    if(strcmp (parans, "..") == 0) {
        //ir ao pai
        while (1 > 0)
        {
            if(percorre->id == currentDir) {
                currentDir = percorre->father_id;
            }
            if(percorre->prox == NULL) {break;}
            percorre = percorre -> prox;
        }
    } else {
        //entrar
        while (1 > 0)
        {
            if(percorre->father_id == currentDir && strcmp (percorre->name, parans) == 0 &&percorre->id !=0) {
                currentDir = percorre->id;
            }
            if(percorre->prox == NULL) {break;}
            percorre = percorre -> prox;
        }
    }
    
    
}

void PWD (Dirs *inicio) {
    Dirs *percorre;
    percorre = inicio;
    while (1 > 0)
    {
        if(percorre->id == currentDir) {break;}
        percorre = percorre -> prox;
    }
    printf("%s \n", percorre->name);
}


void Login (Users *inicio, char* name) {
    Users *percorre;
    percorre = inicio;
    while (1 > 0)
    {
        if(strcmp (percorre->login, name) == 0) {
            current_user = percorre->id;
            currentDir = percorre->dirId;
            printf("\n Bem-Vindo %s \n", percorre->name);
        } else{
            current_user = 0;
        }
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
        
    }
}

void userInfo (Users *inicio) {
    Users *percorre;
    percorre = inicio;
    int i =0; //count of localized user
    while (1 > 0)
    {
        if(strcmp (percorre->login, parans) == 0) {
            i++;
            printf("\n Nome: %s \n", percorre->name);
        }
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
    }
    if(i == 0) {
        printf("Usuario nao localizado \n");
    }
}

void ShowDateTime () {
    printf(" \n DATA : %s HORA: %s \n",__DATE__,__TIME__);
}

void Copyright () {
    printf("*** ******* ------- ******* *** \n");
    printf("   Augusto Furlan \n");
    printf("   Matheus Barros \n");
    printf("*** ******* ------- ******* *** \n");
}

void Logout () {
    current_user = 0;
}



void Poweroff (Dirs *inicio, Users *user_inicio) {
    if(current_user != 1) {
        printf("Desculpe, mas você não tem permissao psra executar este comando");
    } else {
        //save in file and close
    }
}
