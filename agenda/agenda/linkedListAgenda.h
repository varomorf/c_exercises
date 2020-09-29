//
// Created by alvaro on 29/9/20.
//

#ifndef AGENDA_LINKEDLISTAGENDA_H
#define AGENDA_LINKEDLISTAGENDA_H

#include "agendaCommon.h"

typedef struct LinkedListAgendaNode {
    AGENDA_ENTRY entry;
    struct LinkedListAgendaNode *next;
} LIST_AGENDA_NODE;


typedef struct LinkedListAgenda {
    LIST_AGENDA_NODE *head;
    LIST_AGENDA_NODE *last;
    unsigned int size;
} LIST_AGENDA;

LIST_AGENDA* createLinkedListAgenda();
void addListEntry(LIST_AGENDA *agenda, AGENDA_ENTRY entry);
void listListAgendaAsIs(LIST_AGENDA *agenda);
void listListAgendaAlphabetically(LIST_AGENDA *agenda);
void listListAgendaByAge(LIST_AGENDA *agenda);

#endif //AGENDA_LINKEDLISTAGENDA_H
