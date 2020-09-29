//
// Created by alvaro on 29/9/20.
//

#include <stdlib.h>
#include "linkedListAgenda.h"

LIST_AGENDA* createLinkedListAgenda() {
    LIST_AGENDA *agenda = malloc(sizeof(LIST_AGENDA));

    agenda->head = NULL;
    agenda->size = 0;

    return agenda;
}

void addListEntry(LIST_AGENDA *agenda, AGENDA_ENTRY entry){

}