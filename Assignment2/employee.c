#include "employee.h"
EMPLOYEE* list_of_employees=NULL;

void printEmployee(EMPLOYEE e){
    printf("Name: %s, ID: %d\n", e.name, e.id);
    if(e.payments == NULL) {
      printf("No payments..\n");
    }
    else {
      printf("---------------------\n");
      printf("Date                   Amount\n");
      printf("----                   ------\n");
      PAYMENT* temp = e.payments;
      while(temp != NULL) {
        printf("%s             %f\n", temp->date, temp->amount);
        temp = temp->next;
      }
    }
    if(e.next != NULL) {
      printf("===================================");
      printEmployee(*e.next);
    }
}

void addEmployee(int e_id, char* e_name){
  EMPLOYEE* e = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
  e->id = e_id;
  e->name = e_name;
  e->payments = NULL;
  e->next = list_of_employees;
  list_of_employees = e;
}

void printEmployees(){
  if(list_of_employees == NULL) {
    printf("The list is empty..");
  }
  EMPLOYEE* e = list_of_employees;
  while(e != NULL) {
    printf("Name: %s, ID: %d\n", e->name, e->id);
    if(e->payments == NULL) {
      printf("No payments..\n");
    }
    else {
      printf("---------------------\n");
      printf("Date                   Amount\n");
      printf("----                   ------\n");
      PAYMENT* temp = e->payments;
      while(temp != NULL) {
        printf("%s             %f\n", temp->date, temp->amount);
        temp = temp->next;
      }
    }
    printf("==================================\n");
    e = e->next;
  }    
}

int addPayment(int e_id, char* p_date, float p_amount){
  PAYMENT* p = (PAYMENT*) malloc(sizeof(PAYMENT));
  p->amount = p_amount;
  p->date = p_date;
  EMPLOYEE* e = list_of_employees;
  int flag = 0;
  while(e != NULL && flag != 1) {
    if(e->id == e_id) {
      flag = 1;
    }
    else {
      e = e->next;
    }
  }
  if(e == NULL) {
    return 0;
  }
  else {
    p->next = e->payments;
    e->payments = p;
    return 1;
  }
}

int deleteEmployee(int e_id, char* e_name){
  EMPLOYEE* e = list_of_employees;
  EMPLOYEE* prev;
  int flag = 0;
  while(e != NULL && flag != 1) {
    if(e->id == e_id) {
      flag = 1;
      if(e == list_of_employees) {
        list_of_employees = e->next;
      }
      else {
        prev->next = e->next;
      }
    }
    else {
      prev = e;
      e = e->next;
    }
  }
  if(e == NULL) {
    return 0;
  }
  free(e);
  e = NULL;
  return 1;
}