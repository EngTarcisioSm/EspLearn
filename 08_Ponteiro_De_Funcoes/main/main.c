#include <stdio.h>
#include <string.h>
#include <stdlib.h> //utilizar malloc

/*
 * Utilização de ponteiro de funções
 * 
 */ 

typedef struct Person_struct{
  char firstName[20];
  char lastName[50];
  int age;
}Person2;

void updatePerson(Person2 *person, char *dataRetrieveded){
  strcpy(person->firstName,"data from dataRetrieveded");
  strcpy(person->lastName, "data from dataRetrieveded");
  person->age = 29;
}

/*
 * A função a seguir simulará uma conexão a internet para recebimento de dados 
 * 
 */
void connectAndGetInfo(char *url, void (*DoWork)(char *dataRetrieved))
{
  //connect to wireless - implementado futuramente
  //connect to endopoint - implementado futuramente
  //alocate memory
  char *dataRetrieved = (char *) malloc(1024); 
  //fill buffer with data: getRequest(&dataRetrieved); - implementado futuramente
  //do work and get a person object
  DoWork(dataRetrieved);
  //clean up memory and other resources
  free((void *) dataRetrieved);
}

void DoWorkFromPerson(char *dataRetrieveded)
{
  Person2 person2;
  updatePerson(&person2, dataRetrieveded);
  printf("person: %s %s is %d years old \n", person2.firstName, person2.lastName, person2.age);
}


void app_main(void)
{
  connectAndGetInfo("http://getperson.com");
}
