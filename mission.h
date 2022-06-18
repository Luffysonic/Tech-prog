/**
  *\file mission.h
*/
#ifndef MISSION_H
#define MISSION_H
#include"soldier.h"/*for soldier_t*/
/**
  *A mission.
*/
typedef struct
{
  int day;/**< The mission date (day).*/
  char *country;/**< The mission location (country).*/
  int month;/**< The mission date (month).*/
  char *name;/**< The mission name.*/
  int nsoldiers;/**< The mission number of soldiers.*/
  soldier_t **soldiers;/**< The mission soldiers.*/
  int year;/**< The mission date (year).*/
}mission_t;
/**
  *Adds a soldier to a mission.
  *\param mission The mission.
  *\param soldier The soldier.
  *\return -1 on error (i.e., if the memory allocation is a failure), else 0
*/
int mission_add_soldier(mission_t *mission, soldier_t *soldier);
/**
  *Creates a mission.
  *\return NULL on error (i.e., if the memory allocation is a failure), else a mission
*/
mission_t *mission_create();
/**
  *Frees a mission.
  *\param mission The mission.
*/
void mission_free(mission_t *mission);
/**
  *Handles the c command for a mission.
  *\param mission The mission.
*/
void mission_handle_c(mission_t mission);
/**
 *Handles the d command for a mission.
 *\param mission The mission.
*/
void mission_handle_d(mission_t mission);
/**
  *Handles the m command for a mission.
  *\param mission The mission.
*/
void mission_handle_m(mission_t mission);
/**
  *Handles the n command for a mission.
  *\param mission The mission.
*/
void mission_handle_n(mission_t mission);
/**
  *Handles the s command for a mission.
  *\param mission The mission.
*/
void mission_handle_s(mission_t mission);
/**
  *Handles the sc command for all the soldiers of a mission.
  *\param mission The mission.
  *\param cost The soldier cost.
*/
void mission_handle_sc(mission_t mission,float cost);
/**
  *Handles the scge command for all the soldiers of a mission.
  *\param mission The mission.
  *\param cost The soldier cost.
*/
void mission_handle_scge(mission_t mission,float cost);
/**
  *Handles the scgt command for all the soldiers of a mission.
  *\param mission The mission.
  *\param cost The soldier cost.
*/
void mission_handle_scgt(mission_t mission,float cost);
/**
  *Handles the scle command for all the soldiers of a mission.
  *\param mission The mission.83*\param cost The soldier cost.
*/
void mission_handle_scle(mission_t mission,float cost);
/**
  *Handles the sclt command for all the soldiers of a mission.
  *\param mission The mission.
  *\param cost The soldier cost.
*/
void mission_handle_sclt(mission_t mission,float cost);
/**
  *Handles the sln command for all the soldiers of a mission.
  *\param mission The mission.
  *\param last_name The soldier last name.
*/
void mission_handle_sln(mission_t mission,const char *last_name);
  /**
  *Handles the t command for a mission.
  *\param mission The mission.
  */
void mission_handle_t(mission_t mission);
#endif
