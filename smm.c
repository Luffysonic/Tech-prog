#include <string.h>
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
/*libxml is for parse the xml file */
#include"soldier.h"
#include"mission.h"

void charCommand(char c,mission_t m){
  switch (c) {
    case 'h' :
            printf("c: Prints the mission country\n");
            printf("d: Prints the mission date\n");
            printf("h: Prints this help\n");
            printf("m: Prints the mission\n");
            printf("n: Prints the mission name\n");
            printf("s: Prints the mission soldiers\n");
            printf("sc COST: Prints the mission soldiers with the cost equal to COST\n");
            printf("scge COST: Prints the mission soldiers with the cost greater than or equal to COST\n");
            printf("scgt COST: Prints the mission soldiers with the cost greater than COST\n");
            printf("scle COST: Prints the mission soldiers with the cost less than or equal to COST\n");
            printf("sclt COST: Prints the mission soldiers with the cost less than COST\n");
            printf("sln LN: Prints the mission soldiers with the last name containing LN\n");
            printf("t: Prints the mission total cost\n");
            printf("v: Prints the SMM version\n");
            printf("q: Quits SMM\n");
            break;
      case 'c' :
            mission_handle_c(m);
            break;
      case 'd' :
            mission_handle_d(m);
            break;
      case 'm' :
            mission_handle_m(m);
            break;
      case 'n' :
            mission_handle_n(m);
            break;
      case 's' :
            mission_handle_s(m);
            break;
      case 't' :
            mission_handle_t(m);
            break;
      case 'v':
      printf("SMM (Soldier Mission Manager) 20201116 \n \n Copyright (C) 2020 Khao Ricky and Mhand Youssef\n \n Written by Khao Ricky <rkhao@univ-pau.fr> and Mhand Youssef<ymhand@etud.univ-pau.fr>.\n");

            break;
      default :
            printf("./smm.out Invalid command \n");
            break;

  }
}
void wordCommand(char w[2],char *second,mission_t m){
  double valeur;

  if(strcmp(w,"sc")==0){
    if(second==NULL){
      printf("Missing parameter for the %s command\n",w);
    }
    else{
      valeur=strtod(second,NULL);
      if(valeur==0){
        printf("./smm.out Invalid parameter for the %s command\n",w);
      }
      else{
        mission_handle_sc(m,valeur);
      }
    }
  }

  if(strcmp(w,"scge")==0){
    if(second==NULL){
      printf("Missing parameter for the %s command\n",w);
    }
    else{
      valeur=strtod(second,NULL);
      if(valeur==0){
        printf("./smm.out Invalid parameter for the %s command\n",w);
      }
      else{
        mission_handle_scge(m,valeur);
      }
    }
  }

  if(strcmp(w,"scgt")==0){
    if(second==NULL){
      printf("Missing parameter for the %s command\n",w);
    }
    else {
      valeur=strtod(second,NULL);
      if(valeur==0){
        printf("./smm.out Invalid parameter for the %s command\n",w);
      }
      else{
        mission_handle_scgt(m,valeur);
      }
    }
  }

  if(strcmp(w,"scle")==0){
    if(second==NULL){
      printf("Missing parameter for the %s command\n",w);
    }
    else {
      valeur=strtod(second,NULL);
      if(valeur==0){
        printf("./smm.out Invalid parameter for the %s command\n",w);
      }
      else{
        mission_handle_scle(m,valeur);
      }
    }
  }
  if(strcmp(w,"sclt")==0){
    if(second==NULL){
      printf("Missing parameter for the %s command\n",w);
    }
    else {
      valeur=strtod(second,NULL);
      if(valeur==0){
        printf("./smm.out Invalid parameter for the %s command\n",w);
      }
      else{
        mission_handle_sclt(m,valeur);
      }
    }
  }
  if(strcmp(w,"sln")==0){
    if(second==NULL){
      printf("Missing parameter for the %s command\n",w);
    }
    else {
      if(second==NULL){
        printf("./smm.out Invalid parameter for the %s command\n",w);
      }
      else{
        mission_handle_sln(m,second);
      }
    }
  }
  if( (strcmp(w,"sc")!=0) && (strcmp(w,"scge")!=0) && (strcmp(w,"scgt")!=0) && (strcmp(w,"scle")!=0) && (strcmp(w,"sclt")!=0) && (strcmp(w,"sln")!=0)  ){
    printf("./smm.out Invalid command\n");
  }
}


/*----------------Programme Principal --------------------------*/
int main(int argc,char **argv){
  xmlDoc *Document;
  xmlNode *racine;
  char* nodeName, *nodeValue;
  /*
  nodeName : Les noms des racines
  nodeValue : Les noms des valeurs de fichier xml
  */
  mission_t *mission;
  char input[18],*input2,*input3; /*Tableau contient les caractères tapés par l'utilisteur */

  xmlNode *itemR, *itemC, *itemT, *itemD;
  /*
  itemR : pour les racines du mission
  itemC : pour les racines du soldiers
  itemT : pour les racines de soldier
  itemD : pour les racines de date
  */

  if(argc!=2){
    fprintf(stderr,"./smm.out: Invalid number of arguments\n");
    return 1;
  }
  Document=xmlParseFile(argv[1]);
  if(Document==NULL){
    return 1;
    fprintf(stderr,"I/O warning : failed to load external entity %s\n",argv[1]);
  }
  else{
    racine=xmlDocGetRootElement(Document);
    mission=mission_create();
    nodeValue = (char *) xmlGetProp(racine, (const xmlChar *)"name");
    /* Mettre le nom du racine du mission "Save the soldier Ryan" dans nodeValue*/
    mission->name=(char*) realloc(nodeValue,strlen(nodeValue));
    itemR = racine->children;/*Entrer dans les sous racines de mission */

    /*Récupération des donnés a partir du fichier xml */
    /***************************************************************************************/
    while(itemR){
      nodeName = (char*) itemR->name; /* Récupération des noms des racine de mission */

      /*Racine "date"*/
      if(!strcmp(nodeName,"date")){ /*Vérifier si le nom du racine du "mission" est "date"*/
        itemD = itemR->children; /*Entrer dans les sous racine de "date"*/
        while(itemD){
          nodeName = (char*) itemD->name; /* Récupération des noms des racines de "date"*/
          if(!strcmp(nodeName,"day")){ /*Vérifier si le nom du racine du "date" est "day"*/
            nodeValue = (char*) xmlNodeListGetString(Document,itemD->xmlChildrenNode,1); /*Récupération des valeurs de "day" du racine "date"*/
            mission->day = strtol(nodeValue,NULL,10);/*Convertir les valeurs de "day" depuis un string vers un long et les mettre dans "mission->day"*/
          }
          if(!strcmp(nodeName,"month")){/*Vérifier si le nom du racine du "date" est "month"*/
            nodeValue = (char*) xmlNodeListGetString(Document,itemD->xmlChildrenNode,1);/*Récupération des valeurs de "month" du racine "date"*/
            mission->month = strtol(nodeValue,NULL,10);/*Convertir les valeurs de "month" depuis un string vers un long et les mettre dans "mission->month"*/
          }
          if(!strcmp(nodeName,"year")){/*Vérifier si le nom du racine du "date" est "year"*/
            nodeValue = (char*) xmlNodeListGetString(Document,itemD->xmlChildrenNode,1);/*Récupération des valeurs de "year" du racine "date"*/
            mission->year = strtol(nodeValue,NULL,10);/*Convertir les valeurs de "year" depuis un string vers un long et les mettre dans "mission->year"*/
          }

          itemD = itemD->next; /*Entrer dans le suivant sous racine de "date"*/
        }
      }

      /*Racine "country"*/
      if(!strcmp(nodeName,"country")){/*Vérifier si le nom du racine du mission est "country"*/
        nodeValue = (char*) xmlNodeListGetString(Document,itemR->xmlChildrenNode,1);/*Récupération des valeurs de "country" du racine "mission"*/
        mission->country = (char*) realloc(nodeValue,sizeof(char)*strlen(nodeValue));
      }

      /*Racine "soldiers"*/
      if(!strcmp(nodeName,"soldiers")) { /*Vérifier si le nom du racine du mission est "soldiers"*/
        itemC = itemR->children; /*Entrer dans les sous racine de "soldiers"*/
        while(itemC){
          nodeName = (char*) itemC->name; /* Récupération des noms des racines de "soldiers"*/
          if(!strcmp(nodeName,"soldier")){/*Vérifier si le nom du racine du "soldiers" est "soldier"*/
            mission->soldiers = (soldier_t**) realloc(mission->soldiers,sizeof(soldier_t)*(mission->nsoldiers+1));/*Récupération des valeurs de "soldier" du racine "soldiers"*/
            mission->soldiers[mission->nsoldiers] = soldier_create();

            /* Trouver les propriétés des soldiers */
            nodeValue = (char *)xmlGetProp(itemC, (const xmlChar *)"first-name");
            mission->soldiers[mission->nsoldiers]->first_name = (char*) realloc(nodeValue,sizeof(char)*strlen(nodeValue));
            nodeValue = (char *)xmlGetProp(itemC, (const xmlChar *)"last-name");
            mission->soldiers[mission->nsoldiers]->last_name = (char*) realloc(nodeValue,sizeof(char)*strlen(nodeValue));

            itemT = itemC->children;
            while(itemT){
              nodeName = (char*) itemT->name;
              if(!strcmp(nodeName,"cost")){
                nodeValue = (char*) xmlNodeListGetString(Document,itemT->xmlChildrenNode,1);
                mission->soldiers[mission->nsoldiers]->cost = strtod(nodeValue,NULL);
              }
              if(!strcmp(nodeName,"country")){
                nodeValue = (char*) xmlNodeListGetString(Document,itemT->xmlChildrenNode,1);
                mission->soldiers[mission->nsoldiers]->country = (char*) realloc(nodeValue,sizeof(char)*strlen(nodeValue));
              }
              if(!strcmp(nodeName,"date")){
                itemD = itemT->children;
                while(itemD){
                  nodeName = (char*) itemD->name;
                  if(!strcmp(nodeName,"day")){
                    nodeValue = (char*) xmlNodeListGetString(Document,itemD->xmlChildrenNode,1);
                    mission->soldiers[mission->nsoldiers]->day = strtol(nodeValue,NULL,10);
                  }
                  if(!strcmp(nodeName,"month")){
                    nodeValue = (char*) xmlNodeListGetString(Document,itemD->xmlChildrenNode,1);
                    mission->soldiers[mission->nsoldiers]->month = strtol(nodeValue,NULL,10);
                  }
                  if(!strcmp(nodeName,"year")){
                    nodeValue = (char*) xmlNodeListGetString(Document,itemD->xmlChildrenNode,1);
                    mission->soldiers[mission->nsoldiers]->year = strtol(nodeValue,NULL,10);
                  }

                  itemD = itemD->next;
                }

              }
              itemT = itemT->next;
            }
            mission->nsoldiers ++;
          }
          itemC = itemC->next;
        }
      }
      itemR = itemR->next;
    }

   /***********************************************************************************************************/
      input2=malloc(sizeof(char));
      input3=malloc(sizeof(char));

      while(strcmp(input,"q")!=0){
        printf("SMM> ");
        fgets(input,20,stdin);

        if(strlen(input)<0){
          printf("./smm.out: Too few characters for the command\n");
        }
        if(strlen(input)>18){
          printf("./smm.out: Too many characters for the command\n");
        }
        else{
          input2=strstr(input,"\n");
            /*cherche un \n dans l'input*/
          if(input2!=NULL){
            *input2='\0';
              /*Pour remplacer le \n entrée par fgets par un \0*/
            input3=NULL;
            /*Réinitialise input3 */
          }
          input2=strstr(input," ");
          /* on cherche cette fois l'espace par exemple avec sc 1800*/
          if(input2!=NULL){
            input3=input2+1;
            /*On avance de 1 pour enlever l'espace et le deuxième argument sera stocké dans input3*/
            *input2='\0';
          }

          /*printf("entree = %s entree 3=%s \n",input,input3);*/
          if( (strlen(input)==1) && (strcmp(input,"q")!=0) ){
            charCommand(input[0],*mission);

          }
          if(strlen(input) > 1 ){
            wordCommand(input,input3,*mission);

          }
        }
    }
    printf("Goodbye !\n");
    free(input2);
    free(input3);
  xmlFreeDoc(Document);
  }
  return 0;
}
