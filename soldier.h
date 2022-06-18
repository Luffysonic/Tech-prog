/***\file soldier.h*/
#ifndef SOLDIER_H
#define SOLDIER_H
/**
*A soldier.
*/
typedef struct{
  float cost;/**< The soldier cost (in USD).*/
  char *country;/**< The soldier birthplace (country).*/
  int day;/**< The soldier birthdate (day).*/
  char *first_name;/**< The soldier first name.*/
  char*last_name;/**< The soldier last name.*/
  int month;/**< The soldier birthdate (month).*/
  int year;/**< The soldier birthdate (year).*/
} soldier_t;
/**
*Creates a soldier.
*\return NULL on
error (i.e., if the memory allocation is a failure), else a soldier.
*/

soldier_t *soldier_create();
/***Frees a soldier.
*\param soldier The soldier.
*/
void soldier_free(soldier_t *soldier);
/***Handles the s command for a soldier.
*\param soldier The soldier.
*/
void soldier_handle_s(soldier_t soldier);
/**
*Handles the sc command for a soldier.
*\param soldier The soldier.
*\param cost The soldier cost.
*/
void soldier_handle_sc(soldier_t soldier,float cost);
/**
*Handles the scge command for a soldier.
*\param soldier The soldier.
*\param cost The soldier cost.
*/
void soldier_handle_scge(soldier_t soldier,float cost);
/**
  *Handles the scgt command for a soldier.
  *\param soldier The soldier.
  *\param cost The soldier cost.
*/
void soldier_handle_scgt(soldier_t soldier,float cost);
/**
  *Handles the scle command for a soldier.
  *\param soldier The soldier
  *\param cost The soldier cost.
*/
void soldier_handle_scle(soldier_t soldier,float cost);
/**
 *Handles the sclt command for a soldier.
 *\param soldier The soldier.
 *\param cost The soldier cost.
*/
void soldier_handle_sclt(soldier_t soldier,float cost);
/**
  *Handles the sln command for a soldier.
  *\param soldier The soldier
  *\param last_name The soldier last name
  */
void soldier_handle_sln(soldier_t soldier,const char*last_name);
#endif
