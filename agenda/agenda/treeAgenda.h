//
// The tree will be a binary tree sorted by full name
// Created by alvaro on 30/9/20.
//

#ifndef AGENDA_TREEAGENDA_H
#define AGENDA_TREEAGENDA_H

#include "agendaCommon.h"

typedef struct TreeAgendaNode {
    AGENDA_ENTRY *entry;
    struct TreeAgendaNode *left;
    struct TreeAgendaNode *right;
} TREE_AGENDA_NODE;


typedef struct TreeAgenda {
    TREE_AGENDA_NODE *head;
    unsigned int size;
} TREE_AGENDA;

TREE_AGENDA* createTreeAgenda();
void addTreeEntry(TREE_AGENDA *agenda, AGENDA_ENTRY *entry);
void removeTreeEntry(TREE_AGENDA *agenda, char *fullName);
void listTreeAgendaAsIs(TREE_AGENDA *agenda);
void listTreeAgendaAlphabetically(TREE_AGENDA *agenda);
void listTreeAgendaByAge(TREE_AGENDA *agenda);

#endif //AGENDA_TREEAGENDA_H
