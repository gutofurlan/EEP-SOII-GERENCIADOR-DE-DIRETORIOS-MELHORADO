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
 * Adicionar user adduser username so root pode - OK
 * Bloquear usuario block username so root pode - OK
 * Desbloquear username unlock username so root pode - OK
 * Remover user deluser username so root pode - OK
 * Exibir a data date - OK
 * Exibir a hora time - OK
 * Remover Diretorio (Verificar se existe filho)
 * o usuario so pode editar as pastas abaixo dele - OK
 
 * Encerrar programa (poweroff) apenas o root pode fazer
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
    char datetime[50];
    struct Dirs *prox;
    
} Dirs;

typedef struct {
    int id;
    char name[100];
    char login[9];
    int status; // 1- enable
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
void Listar (Dirs *inicio, Users *ini_users);
void Remove (Dirs *inicio);
void PWD (Dirs *inicio);
void CD (Dirs *inicio);
void Copyright();
void userInfo (Users *inicio);
void Logout ();
void InsertHome (Dirs *inicio, char* name);

void Login (Users *inicio, char* name);
void ShowDateTime ();
void AddUser (Users *user_ini);
void BlockUsername (Users *inicio);
void UnlockUsername (Users *inicio);
void RmR (Dirs *inicio);
void DelUser (Users *inicio);
int VerifyProperty (Dirs *inicio, int dirId);
void ShowTimes();
int VerifyChilds (Dirs *inicio, int dirId);
char* ReturnNameProperty (Users *inicio, int dirId);

/* Variaveis global */
int id=0, currentDir = 0, current_user = 0, userId=1;
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
    if(strcmp (comando, "time") == 0) {
        ShowTimes();
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
        Listar(&ini, &ini_users);
    }
    if(strcmp (comando, "pwd") == 0) {
        PWD(&ini);
        //printf("ENTROU PWD");
    }
    if(strcmp (comando, "rmdir") == 0) {
        Remove(&ini);
    }
    if(strcmp (comando, "adduser") == 0) {
        if(current_user != 1) {
            printf("Desculpe mas voce nao tem essa permissao \n");
        } else {
            InsertHome(&ini, parans);
            AddUser(&ini_users);
        }
        
        
    }
        
    if(strcmp (comando, "blockuser") == 0) {
        if(current_user != 1) {
            printf("Desculpe mas voce nao tem essa permissao \n");
        } else {
            BlockUsername(&ini_users);
        }
    }
        
    if(strcmp (comando, "unlockuser") == 0) {
        if(current_user != 1) {
            printf("Desculpe mas voce nao tem essa permissao \n");
        } else {
            UnlockUsername(&ini_users);
        }
    }
        
    if(strcmp (comando, "cd") == 0) {
        CD(&ini);
    }
        
    if(strcmp (comando, "deluser") == 0) {
        if(current_user != 1) {
            printf("Desculpe mas voce nao tem essa permissao \n");
        } else {
            DelUser(&ini_users);
            RmR(&ini);
        }
    }
        
}
    
    
    
    return 0;
    
}

int VerifyProperty (Dirs *inicio, int dirId) {
    int id = 0;
    Dirs *percorre;
    percorre = inicio;
    //printf("%d \n", current_user);
        //entrar
        while (1 > 0)
        {
            //printf("\n Nome: %s | pproperty: %d | ID: %d \n", percorre->name, percorre->property_id, percorre->id);
            //printf("\n ID: %d \n", percorre->id);
            if(percorre->id == dirId) {
                id = percorre->property_id;
                break;
            }
            if(percorre->prox == NULL) {break;}
            percorre = percorre -> prox;
        }
    
    return id;
}


int VerifyChilds (Dirs *inicio, int dirId) {
    int count = 0;
    Dirs *percorre;
    percorre = inicio;
    //printf("%d \n", current_user);
    //entrar
    while (1 > 0)
    {
        //printf("\n Nome: %s | pproperty: %d | ID: %d \n", percorre->name, percorre->property_id, percorre->id);
        //printf("\n ID: %d \n", percorre->id);
        if(percorre->father_id == dirId) {
            count++;
            break;
        }
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
    }
    
    return count;
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
    users->id = userId;
    strcpy(users->name, "ROOT");
    strcpy(users->login, "root");
    users->status = 1;
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
    no_novo -> property_id = current_user;
    char datetime[50];
    strcpy(datetime, __DATE__);
    strcat(datetime, " ");
    strcat(datetime, __TIME__);
    strcpy(no_novo->datetime, datetime);
    strcpy(no_novo->name, parans);
    no_novo -> prox = NULL;
    
        percorre = inicio;
        while (percorre->prox != NULL)
        {
            percorre = percorre -> prox;
        }
        percorre->prox = no_novo;
    
}

void InsertHome (Dirs *inicio, char* name)
{
    id++;
    Dirs *percorre;
    
    /* Criacao do novo no - AlocaÁ„o de memoria */
    Dirs *no_novo = (Dirs *) malloc(sizeof(Dirs));
    no_novo -> id = id;
    no_novo -> father_id = 0;
    no_novo -> property_id = userId;
    char datetime[50];
    strcpy(datetime, __DATE__);
    strcat(datetime, " ");
    strcat(datetime, __TIME__);
    strcpy(no_novo->datetime, datetime);
    strcpy(no_novo->name, name);
    no_novo -> prox = NULL;
    
    percorre = inicio;
    while (percorre->prox != NULL)
    {
        percorre = percorre -> prox;
    }
    percorre->prox = no_novo;
    
}


void Listar (Dirs *inicio, Users *ini_users)
{
    Dirs *percorre;
    percorre = inicio;
    while (1 > 0)
    {
        if(percorre->father_id == currentDir && strcmp (percorre->name, "/") != 0) {
            printf("       %s   | %s   | %s  \n", percorre->name, percorre->datetime, ReturnNameProperty (ini_users, percorre->property_id));
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
            i++;
            if(VerifyChilds (inicio, percorre->id) == 0) {
                if(percorre->prox == NULL) {
                    percorreAnt -> prox = NULL;
                    free(percorre);
                } else {
                    //meio
                    percorreAnt->prox = percorre->prox;
                }
            } else {
                printf("Impossivel remover pois esse diretorio tem subdiretorios \n");
            }
        }
        if(percorre->prox == NULL) {break;}
        percorreAnt = percorre;
        percorre = percorre -> prox;
    }
  
}


void RmR (Dirs *inicio) //del folder and content
{
    int currentDirOld = currentDir;
    currentDir = 0;
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
    
    currentDir = currentDirOld;
    
}


void CD (Dirs *inicio)
{
    Dirs *percorre;
    percorre = inicio;
    if(strcmp (parans, "..") == 0) {
        //ir ao pai
        while (1 > 0)
        {
            if(percorre->id == currentDir ) {
//                printf("Proprietario: %d \n", VerifyProperty(inicio, percorre->father_id));
                if(VerifyProperty(inicio, percorre->father_id) == current_user || ( VerifyProperty(inicio, percorre->father_id) == 1) && current_user == 1 ) {
                        currentDir = percorre->father_id;
                } else {
                    //printf("Voce esta tentando acessar um diretorio que nao e seu %d %d \n", userId, VerifyProperty(&inicio, percorre->father_id));
                    printf("Voce esta tentando acessar um diretorio que nao e seu\n");
                }
                
            }
            if(percorre->prox == NULL) {break;}
            percorre = percorre -> prox;
        }
    } else {
        //entrar
        //n precisa de permissao pois o user q entrou n consegue subir sem ser o root
        while (1 > 0)
        {
            if(percorre->father_id == currentDir && strcmp (percorre->name, parans) == 0 &&percorre->id !=0 ) {
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
    int i =0;
    while (1 > 0)
    {
        if(strcmp (percorre->login, name) == 0) {
            i++;
            if(percorre->status == 1) {
                current_user = percorre->id;
                currentDir = percorre->dirId;
                printf("\n Bem-Vindo %s \n", percorre->name);
            } else {
                printf("Nao e possivel logar em um usuario bloqueado \n");
            }
        }
        
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
    }
    if(current_user == 0 && i == 0) {
        printf("\n Desculpe login invalido \n");
    }
    if(i == 0) {current_user = 0;}
}

void userInfo (Users *inicio) {
    Users *percorre;
    percorre = inicio;
    int i =0; //count of localized user
    while (1 > 0)
    {
        if(strcmp (percorre->login, parans) == 0) {
            i++;
            char status[50];
            if(percorre->status == 0) {
                strcpy(status, "Bloqueado");
            } else {
                strcpy(status, "Ativo");
            }
            printf("\n Nome: %s   |   Status: %s \n", percorre->name, status);
        }
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
    }
    if(i == 0) {
        printf("Usuario nao localizado \n");
    }
}

char* ReturnNameProperty (Users *inicio, int dirId) {
    Users *percorre;
    char* name;
    percorre = inicio;
    int i =0; //count of localized user
    while (1 > 0)
    {
        if(percorre->id == dirId) {
            i++;
            strcpy(name, percorre->name);
        }
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
    }
    
    return name;
}

void BlockUsername (Users *inicio) {
    Users *percorre;
    percorre = inicio;
    int i =0; //count of localized user
    while (1 > 0)
    {
        if(strcmp (percorre->login, parans) == 0) {
            i++;
            if(percorre->status == 0){
                printf("Esse usuario ja esta bloqueado \n");
            } else {
                printf("\n  %s bloqueado com sucesso \n", percorre->name);
                percorre->status = 0;
            }
        }
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
    }
    if(i == 0) {
        printf("Usuario nao localizado \n");
    }
}

void UnlockUsername (Users *inicio) {
    Users *percorre;
    percorre = inicio;
    int i =0; //count of localized user
    while (1 > 0)
    {
        if(strcmp (percorre->login, parans) == 0) {
            i++;
            if(percorre->status == 1){
                printf("Esse usuario ja esta desbloqueado \n");
            } else {
                printf("\n  %s desbloqueado com sucesso \n", percorre->name);
                percorre->status = 1;
            }
            
        }
        if(percorre->prox == NULL) {break;}
        percorre = percorre -> prox;
    }
    if(i == 0) {
        printf("Usuario nao localizado \n");
    }
}

void ShowDateTime () {
    printf(" \n DATA : %s \n",__DATE__);
}

void ShowTimes() {
    printf("HORA: %s \n", __TIME__);
    
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
//Pendente
void AddUser (Users *user_ini)
{
    
    userId++;
    Users *percorre;
    char fullname[100];
    printf("Nome Completo: ");
    gets(fullname);
    /* Criacao do novo no - AlocaÁ„o de memoria */
    Users *no_novo = (Users *) malloc(sizeof(Users));
    no_novo -> id = userId;
    no_novo->status = 1;
    no_novo->dirId = id;
    strcpy(no_novo->name, fullname);
    strcpy(no_novo->login, parans);
    no_novo -> prox = NULL;
    
    percorre = user_ini;
    while (percorre->prox != NULL)
    {
        percorre = percorre -> prox;
    }
    percorre->prox = no_novo;
    
}

void DelUser (Users *inicio)
{
    int i =0;
    Users *percorre, *percorreAnt;
    percorre = inicio;
    while (1 > 0)
    {
        if(strcmp (percorre->login, parans) == 0 &&percorre->id !=1) {
            
            //if(percorre->id == 1) {
            if(percorre->prox == NULL) {
                percorreAnt -> prox = NULL;
                free(percorre);
            } else {
                //meio
                percorreAnt->prox = percorre->prox;
            }
            i++;
        }
        if(percorre->prox == NULL) {break;}
        percorreAnt = percorre;
        percorre = percorre -> prox;
    }
    if(i > 0) {
        printf("Usuario deletado com sucesso \n");
    } else {
        printf("Usuario invalido \n");
    }
    
}



void Poweroff (Dirs *inicio, Users *user_inicio) {
    if(current_user != 1) {
        printf("Desculpe, mas você não tem permissao para executar este comando");
    } else {
        //save in file and close
    }
}
