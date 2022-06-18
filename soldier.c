#include "soldier.h"
#include <stdlib.h> /*for malloc*/
#include <stdio.h>/*for fprintf*/
#include <string.h>/*for fprintf*/

soldier_t *soldier_create(){
  soldier_t *newsoldier;
  newsoldier=(soldier_t*) malloc(sizeof(soldier_t));
  if(newsoldier==NULL){
    fprintf(stderr,"Erreur Allocation solier Impossible");
    return(NULL);
  }
  else{
    newsoldier->cost=0;
    newsoldier->country=NULL;
    newsoldier->day=0;
    newsoldier->first_name=NULL;
    newsoldier->last_name=NULL;
    newsoldier->month=0;
    newsoldier->year=0;
    return(newsoldier);
  }
}

void soldier_free(soldier_t *soldier){
  free(soldier);
}

void soldier_handle_s(soldier_t soldier){
  printf("%s %s (%d-%02d-%02d, %s) %.2f USD\n",soldier.first_name,soldier.last_name,soldier.year,soldier.month,soldier.day,soldier.country,soldier.cost);
}
void soldier_handle_sc(soldier_t soldier,float cost){
  if(soldier.cost==cost){
    printf("%s %s (%d-%02d-%02d, %s) %.2f USD\n",soldier.first_name,soldier.last_name,soldier.year,soldier.month,soldier.day,soldier.country,soldier.cost);
  }
}

void soldier_handle_scge(soldier_t soldier,float cost){
  if(soldier.cost>=cost){
    printf("%s %s (%d-%02d-%02d, %s) %.2f USD\n",soldier.first_name,soldier.last_name,soldier.year,soldier.month,soldier.day,soldier.country,soldier.cost);
  }
}

void soldier_handle_scgt(soldier_t soldier,float cost){
  if(soldier.cost>cost){
    printf("%s %s (%d-%02d-%02d, %s) %.2f USD\n",soldier.first_name,soldier.last_name,soldier.year,soldier.month,soldier.day,soldier.country,soldier.cost);
  }
}
void soldier_handle_scle(soldier_t soldier,float cost){
  if(soldier.cost<=cost){
    printf("%s %s (%d-%02d-%02d, %s) %.2f USD\n",soldier.first_name,soldier.last_name,soldier.year,soldier.month,soldier.day,soldier.country,soldier.cost);
  }
}

void soldier_handle_sclt(soldier_t soldier,float cost){
  if(soldier.cost<cost){
    printf("%s %s (%d-%02d-%02d, %s) %.2f USD\n",soldier.first_name,soldier.last_name,soldier.year,soldier.month,soldier.day,soldier.country,soldier.cost);
  }
}
void soldier_handle_sln(soldier_t soldier,const char*last_name){
  char *ret;
  ret=strstr(soldier.last_name,last_name);
  /*ret vaudra soldier.last_name <=> soldier.last_name contient la chaine de caractere last_name sinon il vaudra NULL */
  if(ret!=NULL){
    printf("%s %s (%d-%02d-%02d, %s) %.2f USD\n",soldier.first_name,soldier.last_name,soldier.year,soldier.month,soldier.day,soldier.country,soldier.cost);
  }
}
