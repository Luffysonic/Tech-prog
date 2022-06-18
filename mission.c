#include <stdlib.h> /*for malloc*/
#include <stdio.h>/*for fprintf*/
#include <string.h>/*for fprintf*/
#include "mission.h"


int mission_add_soldier(mission_t *mission, soldier_t *soldier){
  int i;
  i=mission->nsoldiers;
  mission->soldiers=realloc(mission->soldiers,(i+1)*sizeof(soldier_t));
  if(mission->soldiers==NULL){
    fprintf(stderr,"Erreur Allocation mission Impossible\n");
    return(1);
  }
  else{
    /*Copie de soldier dans mission->soldiers[i]*/
    mission->soldiers[i]=soldier_create();
    mission->soldiers[i]->cost=soldier->cost;
    mission->soldiers[i]->country=soldier->country;
    mission->soldiers[i]->day=soldier->day;
    mission->soldiers[i]->first_name=soldier->first_name;
    mission->soldiers[i]->last_name=soldier->last_name;
    mission->soldiers[i]->month=soldier->month;
    mission->soldiers[i]->year=soldier->year;
    /*on augmente le nb de soldat de 1*/
    mission->nsoldiers=i+1;
    return(0);

  }
}
mission_t *mission_create(){
    mission_t *newmission;
    newmission= (mission_t*) malloc(sizeof(mission_t));
    if(newmission==NULL){
      fprintf(stderr,"Erreur Allocation mission Impossible\n");
      return(NULL);
    }
    else{
      newmission->day=0;
      newmission->country=NULL;
      newmission->month=0;
      newmission->name=NULL;
      newmission->nsoldiers=0;
      newmission->soldiers=NULL;
      newmission->year=0;
      return(newmission);
    }
}
void mission_free(mission_t *mission){
  int i;
  for(i=0;i<mission->nsoldiers;i++){
    soldier_free(mission->soldiers[i]);
  }
  free(mission);
}
void mission_handle_c(mission_t mission){
  printf("%s \n",mission.country);
}
void mission_handle_d(mission_t mission){
  printf("%d-%02d-%02d \n",mission.year,mission.month,mission.day );
}
void mission_handle_m(mission_t mission){
  printf("%s (%d-%02d-%02d, %s)\n",mission.name,mission.year,mission.month,mission.day,mission.country );
}
void mission_handle_n(mission_t mission){
  printf("%s\n",mission.name);
}
void mission_handle_s(mission_t mission){
  int i;
  for(i=0;i<mission.nsoldiers;i++){
    soldier_handle_s(*mission.soldiers[i]);
  }
}
void mission_handle_sc(mission_t mission,float cost){
  int i;
  for(i=0;i<mission.nsoldiers;i++){
    soldier_handle_sc(*mission.soldiers[i],cost);
  }

}
void mission_handle_scge(mission_t mission,float cost){
  int i;
  for(i=0;i<mission.nsoldiers;i++){
    soldier_handle_scge(*mission.soldiers[i],cost);
  }
}
void mission_handle_scgt(mission_t mission,float cost){
  int i;
  for(i=0;i<mission.nsoldiers;i++){
    soldier_handle_scgt(*mission.soldiers[i],cost);
  }
}
void mission_handle_scle(mission_t mission,float cost){
  int i;
  for(i=0;i<mission.nsoldiers;i++){
    soldier_handle_scle(*mission.soldiers[i],cost);
  }

}
void mission_handle_sclt(mission_t mission,float cost){
  int i;
  for(i=0;i<mission.nsoldiers;i++){
    soldier_handle_sclt(*mission.soldiers[i],cost);
  }

}
void mission_handle_sln(mission_t mission,const char *last_name){
  int i;
  for(i=0;i<mission.nsoldiers;i++){
    soldier_handle_sln(*mission.soldiers[i],last_name);
  }

}
void mission_handle_t(mission_t mission){
  int i;
  float total_cost;
  total_cost=0;
  for(i=0;i<mission.nsoldiers;i++){
    total_cost+=mission.soldiers[i]->cost;
  }
  printf("%0.2f USD\n",total_cost);
}
