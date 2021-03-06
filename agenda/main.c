#include <stdio.h>
#include <stdlib.h>
#include "agenda/arrayAgenda.h"
#include "agenda/linkedListAgenda.h"
#include "agenda/treeAgenda.h"
#include "utils/utils.h"

#define ADD_ENTRY 1
#define REMOVE_ENTRY 2
#define LIST_ALPHABETICALLY 3
#define LIST_BY_AGE 4
#define SAVE_TO_FILE 5
#define EXIT 99

int executeForArray();

int executeForList();

int executeForTree();

int getOption();

AGENDA_ENTRY *getAgendaEntryFromUser();

char *getFullNameFromUser();

void removeEntryFromArrayAgenda(ARRAY_AGENDA *agenda);

void removeEntryFromListAgenda(LIST_AGENDA *agenda);

void removeEntryFromTreeAgenda(TREE_AGENDA *agenda);

void saveArrayAgendaToFile(ARRAY_AGENDA *agenda);

void saveListAgendaToFile(LIST_AGENDA *agenda);

void saveTreeAgendaToFile(TREE_AGENDA *agenda);

/*
 * A ver q casi me pasa, que te parece facer en C un programilla de agenda.
 * Para hacerlo simple, los contactos tienen nombre apellido DNI y edad.
 * Tienes q almacenarlos de tres formas distintas: en un array dinámico, en una lista enlazada y en un árbol binario.
 * Si quieres que los datos persistan en disco, wai. Así al arrancar se puede leer de un fichero.
 * Si no na, q te permita meter contactos en consola y te pregunte de qué forma los quieres almacenar en memoria (array lista o árbol)
 * Y luego q te dejé sacar listados, alfabéticos y por edad por ejemplo
 *
 */

int main() {
    printf("Hello and welcome to Zapienda! The \"AI-powered\" agenda.\n\n");
    printf("Which version of the agenda do you want to test out?\n");
    printf("1 - Dynamic array\n");
    printf("2 - Linked list\n");
    printf("3 - Binary tree\n");

    int option = readIntFromStdin();

    switch (option) {
        case 1:
            return executeForArray();
        case 2:
            return executeForList();
        case 3:
            return executeForTree();
        default:
            printf("Wrong option");
            return 1;
    }
}

int executeForArray() {
    printf("**** ARRAY VERSION ****\n\n");
    ARRAY_AGENDA *agenda = createArrayAgenda(2);

    // pre-loaded data
    AGENDA_ENTRIES_FROM_FILE *entriesFromFile = getEntriesFromFile();
    for (int i = 0; i < entriesFromFile->entryCount; ++i) {
        addEntry(agenda, entriesFromFile->entries[i]);
    }

    free(entriesFromFile->entries);
    free(entriesFromFile);

    int option = getOption();
    while (option != EXIT) {
        switch (option) {
            case ADD_ENTRY:
                addEntry(agenda, getAgendaEntryFromUser());
                break;
            case REMOVE_ENTRY:
                removeEntryFromArrayAgenda(agenda);
                break;
            case LIST_ALPHABETICALLY:
                listAgendaAlphabetically(agenda);
                break;
            case LIST_BY_AGE:
                listAgendaByAge(agenda);
                break;
            case SAVE_TO_FILE:
                saveArrayAgendaToFile(agenda);
                break;
            default:
                printf("Wrong option");
                return 1;
        }

        option = getOption();
    }

    return 0;
}

int executeForList() {
    printf("**** LINKED LIST VERSION ****\n\n");
    LIST_AGENDA *agenda = createLinkedListAgenda();

    // pre-loaded data
    AGENDA_ENTRIES_FROM_FILE *entriesFromFile = getEntriesFromFile();
    for (int i = 0; i < entriesFromFile->entryCount; ++i) {
        addListEntry(agenda, entriesFromFile->entries[i]);
    }

    free(entriesFromFile->entries);
    free(entriesFromFile);

    int option = getOption();
    while (option != EXIT) {
        switch (option) {
            case ADD_ENTRY:
                addListEntry(agenda, getAgendaEntryFromUser());
                break;
            case REMOVE_ENTRY:
                removeEntryFromListAgenda(agenda);
                break;
            case LIST_ALPHABETICALLY:
                listListAgendaAlphabetically(agenda);
                break;
            case LIST_BY_AGE:
                listListAgendaByAge(agenda);
                break;
            case SAVE_TO_FILE:
                saveListAgendaToFile(agenda);
                break;
            default:
                printf("Wrong option");
                return 1;
        }

        option = getOption();
    }

    return 0;
}

int executeForTree() {
    printf("**** TREE VERSION ****\n\n");
    TREE_AGENDA *agenda = createTreeAgenda();

    // pre-loaded data
    AGENDA_ENTRIES_FROM_FILE *entriesFromFile = getEntriesFromFile();
    for (int i = 0; i < entriesFromFile->entryCount; ++i) {
        addTreeEntry(agenda, entriesFromFile->entries[i]);
    }

    free(entriesFromFile->entries);
    free(entriesFromFile);

    int option = getOption();
    while (option != EXIT) {
        switch (option) {
            case ADD_ENTRY:
                addTreeEntry(agenda, getAgendaEntryFromUser());
                break;
            case REMOVE_ENTRY:
                removeEntryFromTreeAgenda(agenda);
                break;
            case LIST_ALPHABETICALLY:
                listTreeAgendaAlphabetically(agenda);
                break;
            case LIST_BY_AGE:
                listTreeAgendaByAge(agenda);
                break;
            case SAVE_TO_FILE:
                saveTreeAgendaToFile(agenda);
                break;
            default:
                printf("Wrong option");
                return 1;
        }

        option = getOption();
    }

    return 0;
}

void removeEntryFromArrayAgenda(ARRAY_AGENDA *agenda) {
    char *fullNameToRemove = getFullNameFromUser();
    removeEntry(agenda, fullNameToRemove);
    free(fullNameToRemove);
}

void removeEntryFromListAgenda(LIST_AGENDA *agenda) {
    char *fullNameToRemove = getFullNameFromUser();
    removeListEntry(agenda, fullNameToRemove);
    free(fullNameToRemove);
}

void removeEntryFromTreeAgenda(TREE_AGENDA *agenda) {
    char *fullNameToRemove = getFullNameFromUser();
    removeTreeEntry(agenda, fullNameToRemove);
    free(fullNameToRemove);
}

int getOption() {
    printf("Choose an action:\n");
    printf("%d - Add entry\n", ADD_ENTRY);
    printf("%d - Remove entry\n", REMOVE_ENTRY);
    printf("%d - List all entries by name\n", LIST_ALPHABETICALLY);
    printf("%d - List all entries by age\n", LIST_BY_AGE);
    printf("File actions:\n");
    printf("%d - Save to file:\n", SAVE_TO_FILE);
    printf("\n");
    printf("%d - EXIT\n", EXIT);

    return readIntFromStdin();
}

AGENDA_ENTRY *getAgendaEntryFromUser() {
    char *nameBuffer, *surnameBuffer, *idBuffer;
    int age;
    printf("Give me the name:\n");
    nameBuffer = readStringFromStdin();
    printf("Give me the surname:\n");
    surnameBuffer = readStringFromStdin();
    printf("Give me the ID:\n");
    idBuffer = readStringFromStdin();
    printf("Give me the age:\n");
    age = readIntFromStdin();

    AGENDA_ENTRY *newEntry = createAgendaEntry(nameBuffer, surnameBuffer, idBuffer, age);

    free(nameBuffer);
    free(surnameBuffer);
    free(idBuffer);

    return newEntry;
}

char *getFullNameFromUser() {
    printf("Enter full name:\n");

    return readStringFromStdin();
}

void saveArrayAgendaToFile(ARRAY_AGENDA *agenda) {
    AGENDA_ENTRY **entries = getArrayEntries(agenda);
    saveEntriesToFile(entries, agenda->entryCount);
    free(entries);
}

void saveListAgendaToFile(LIST_AGENDA *agenda) {
    AGENDA_ENTRY **entries = getListEntries(agenda);
    saveEntriesToFile(entries, agenda->size);
    free(entries);
}

void saveTreeAgendaToFile(TREE_AGENDA *agenda) {
    AGENDA_ENTRY **entries = getTreeEntries(agenda);
    saveEntriesToFile(entries, agenda->size);
    free(entries);
}
