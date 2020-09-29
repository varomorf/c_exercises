//
// Created by alvaro on 29/9/20.
//

#ifndef AGENDA_LINKEDLISTAGENDA_H
#define AGENDA_LINKEDLISTAGENDA_H

#include "agendaCommon.h"

typedef struct LinkedListAgendaNode {
    AGENDA_ENTRY *entry;
    struct LIST_AGENDA_NODE *next;
} LIST_AGENDA_NODE;


typedef struct LinkedListAgenda {
    LIST_AGENDA_NODE *head;
    unsigned int size;
} LIST_AGENDA;

LIST_AGENDA* createLinkedListAgenda();
void addListEntry(LIST_AGENDA *agenda, AGENDA_ENTRY entry);

#endif //AGENDA_LINKEDLISTAGENDA_H
