//
//  main.c
//  gerenciadorDeDiretorios
//
//  Created by Augusto Furlan on 20/03/2018.
//  Copyright © 2018 Augusto Furlan. All rights reserved.
//
//Criou uma struct onde será guardado no vetor todos os dirs com id, nome, pai_id
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[7];
    int father_id;
} Dirs;

char * getComand(char str[]);
char * getParam (char str[]);
void ls(Dirs **currentList);
Dirs * initDirs ();
int searchDir (char name[], Dirs **currentList);
Dirs * mkdirConcat(char name[], Dirs **currentList);

int id = 0, tamVet = 1, currentDir = 0;

int main(int argc, const char * argv[]) {
    char comand[30];
    char *comando;
    char *param;
    Dirs *listDirs = initDirs(), *auxDirs;
    //printf("%s", listDirs[0].name);
    
    do{
        fgets(comand, 256, stdin);
        comando = getComand(comand);
        if(strcmp (comando, "ls") == 0) {
            ls(&listDirs);
        }
        if(strcmp (comando, "mkdi") == 0) { //piis eu coleto mkdi
            param = getParam(comand);
            auxDirs = listDirs;
            free(listDirs);
            listDirs =  mkdirConcat(param, &auxDirs);
            printf("%d", listDirs[1].id);
        }
        if(strcmp (comando, "pwd") == 0) {
            printf("pwd entrou");
        }
        if(strcmp (comando, "rmdir") == 0) {
            printf("rmdir entrou");
        }
        if(strcmp (comando, "c") == 0) {
            param = getParam (comand);
            //printf("%s", param);
            //printf("cd entrou");
            if(strcmp (comando, "c") == 0) {
                printf("Teste");
            }
        }
        //printf("%s \n", comando);
    } while (1 < 2);
    
    
    //printf("%s", comando);
    return 0;
}



char * getParam (char str[]) {
    int i,k=0, tamStr=0, tamParam=0;
    for (i=0; str[i] != '\0'; i++) {
        if(str[i] == ' '){tamStr++; tamParam=0;}
        tamParam++;
    }
    char *param = (char *)malloc((tamParam+1)*sizeof(char));
    
    for (i=0; str[i] != '\0'; i++) {
        if(str[i] == ' '){tamStr++; tamParam=0;}
        if(tamParam == 0) {
            param[k] = str[i];
            k++;
        }
    }
    return param;
}


char * getComand (char str[]) {
    int i,k=0, tamStr=0;
    for (i=0; str[i] != '\0'; i++) {
        if(str[i] == ' '){break;}
        tamStr++;
    }
    char *comando = (char *)malloc((tamStr+1)*sizeof(char));
    
    for (i=0; i<tamStr-1; i++) {
        comando[i] = str[i];
    }
    return comando;
}

Dirs * initDirs () {
    Dirs *listDirs = (Dirs *)malloc((tamVet)*sizeof(Dirs));
    listDirs[0].id = id;
    //listDirs[0].name[6] = "/";
    strcpy(listDirs[0].name, "/");
    listDirs[0].father_id = 0;
    return listDirs;
}

Dirs * mkdirConcat(char name[], Dirs **currentList) {
    int i =0;
    int aux = tamVet;
    tamVet++;
    Dirs *listDirs = (Dirs *)malloc((tamVet)*sizeof(Dirs));
    for(i=0; i<tamVet; i++) {
        listDirs[i].id = currentList[i]->id;
        strcpy(listDirs[i].name, currentList[i]->name);
        //listDirs[i].name[0] = currentList[i]->name;
        listDirs[i].father_id = currentList[i]->father_id;
    }
    id++;
    listDirs[aux].id = id;
    strcpy(listDirs[aux].name, name);
    //listDirs[tamVet-1].name[0] = name;
    listDirs[aux].father_id = currentDir;
    //printf("%s", currentList[1]->name);
    return listDirs;
}

int searchDir (char name[], Dirs **currentList) {
    int i=0, retorno =0;
    for(i=0; i<tamVet; i++) {
        if(strcmp (currentList[i]->name, name) == 0 && currentList[i]->father_id == currentDir) {
            retorno = i;
        }
    }
    return retorno;
}

void ls(Dirs **currentList) {
    int i=0;
    for(i=0; i<tamVet; i++) {
        //if(currentList[i]->father_id == currentDir) {
        printf("%s           ", currentList[i]->name);
        //}
    }
}
*/
