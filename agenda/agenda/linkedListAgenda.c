//
// Created by alvaro on 29/9/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedListAgenda.h"

LIST_AGENDA *createLinkedListAgenda() {
    LIST_AGENDA *agenda = malloc(sizeof(LIST_AGENDA));

    agenda->head = NULL;
    agenda->size = 0;

    return agenda;
}

void addListEntry(LIST_AGENDA *agenda, AGENDA_ENTRY *entry) {
    LIST_AGENDA_NODE *node = malloc(sizeof(LIST_AGENDA_NODE));

    node->entry = entry;
    node->next = NULL;

    if (agenda->head == NULL) {
        // there are no entries on the agenda
        agenda->head = node;
        agenda->last = node;
    } else {
        // there are at least one entry
        agenda->last->next = node;
        agenda->last = node;
    }

    agenda->size++;
}

void removeListEntry(LIST_AGENDA *agenda, char *fullNameToRemove) {
    // pre-conditions
    if (agenda->size == 0) {
        return;
    }

    // iterate over the list to find the node previous to the node being deleted
    char *entryFullName;
    LIST_AGENDA_NODE *previousNode, *iterator;
    previousNode = iterator = agenda->head;
    while (iterator != NULL){
        entryFullName = getFullName(iterator->entry);
        int found = strcmp(entryFullName, fullNameToRemove) == 0;
        if(found){
            if(iterator == agenda->head){
                //special case deleting the head
                agenda->head = iterator->next;
                agenda->last = agenda->head;
            } else if(iterator == agenda->last){
                //special case deleting last node
                agenda->last = previousNode;
                previousNode->next = NULL;
            } else {
                // normal case
                previousNode->next = iterator->next;
            }

            freeAgendaEntry(iterator->entry);
            free(iterator);

            agenda->size--;
        }

        // clean up allocated memory
        free(entryFullName);

        if(found){
            break;
        }

        // move the pointers
        if(iterator != agenda->head){
            // the previous node pointer must be moved only if the iterator is not the agenda's head
            previousNode = iterator;
        }

        iterator = iterator->next;
    }

}

AGENDA_ENTRY **getListEntries(LIST_AGENDA *agenda) {
    if (agenda->size == 0) {
        return NULL;
    }

    AGENDA_ENTRY **entries = malloc(agenda->size * sizeof(AGENDA_ENTRY));

    LIST_AGENDA_NODE *iterator = agenda->head;
    int i = 0;
    while(iterator != NULL){
        entries[i] = iterator->entry;

        iterator = iterator->next;
        i++;
    }

    return entries;
}

void listListAgendaAlphabetically(LIST_AGENDA *agenda) {
    printf("Listing agenda alphabetically:\n");

    AGENDA_ENTRY **entries = getListEntries(agenda);
    if (entries == NULL) {
        return;
    }

    listEntriesWithComparator(entries, agenda->size, &fullNameComparator);
}

void listListAgendaByAge(LIST_AGENDA *agenda) {
    printf("Listing agenda by age:\n");

    AGENDA_ENTRY **entries = getListEntries(agenda);
    if (entries == NULL) {
        return;
    }

    listEntriesWithComparator(entries, agenda->size, &ageComparator);
}
