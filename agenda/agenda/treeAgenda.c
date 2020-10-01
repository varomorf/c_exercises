//
// Created by alvaro on 30/9/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "treeAgenda.h"

unsigned int traversePrintNode(TREE_AGENDA_NODE *node, unsigned int pos);
unsigned int traverseGetArrayOfNodes(TREE_AGENDA_NODE *node, unsigned int pos, AGENDA_ENTRY *entries);
void traverseAddingFromNode(TREE_AGENDA_NODE *root, TREE_AGENDA_NODE *traversableNode);
void traverseRemovingFromNode(TREE_AGENDA_NODE *node, char *fullName, bool right);

void addEntryToNode(TREE_AGENDA_NODE *traversingNode, TREE_AGENDA_NODE *newNode);

TREE_AGENDA *createTreeAgenda() {
    TREE_AGENDA *agenda = malloc(sizeof(TREE_AGENDA));

    agenda->size = 0;
    agenda->head = NULL;

    return agenda;
}

void addTreeEntry(TREE_AGENDA *agenda, AGENDA_ENTRY entry) {
    TREE_AGENDA_NODE *newNode = malloc(sizeof(TREE_AGENDA_NODE));
    newNode->entry = entry;

    if (agenda->head == NULL) {
        agenda->head = newNode;
    } else {
        addEntryToNode(agenda->head, newNode);
    }

    agenda->size++;
}

void removeTreeEntry(TREE_AGENDA *agenda, char *fullName) {
    TREE_AGENDA_NODE *nodeToBeRemoved = NULL;
    TREE_AGENDA_NODE *traversingNode = agenda->head;

    int comparison = strcmp(getFullName(&traversingNode->entry), fullName);
    if(comparison == 0){
        // special case (head is the node to be deleted)
        nodeToBeRemoved = traversingNode;
        
        agenda->head = traversingNode->left;
        
        traverseAddingFromNode(agenda->head, traversingNode->right);
        free(nodeToBeRemoved);
    } else if (comparison < 0) {
        traverseRemovingFromNode(agenda->head, fullName, true);
    } else {
        traverseRemovingFromNode(agenda->head, fullName, false);
    }

    agenda->size--;
}

void listTreeAgendaAsIs(TREE_AGENDA *agenda) {
    printf("Listing agenda alphabetically (AS IS):\n");

    traversePrintNode(agenda->head, 0);
    printf("\n\n");
}

void listTreeAgendaAlphabetically(TREE_AGENDA *agenda) {
    // agenda is sorted by full name already
    listTreeAgendaAsIs(agenda);
}

void listTreeAgendaByAge(TREE_AGENDA *agenda) {
    printf("Listing agenda by age:\n");

    // get all the entries and use existing code to print with comparator
    AGENDA_ENTRY *entries = (AGENDA_ENTRY*) malloc(agenda->size * sizeof(AGENDA_ENTRY));
    traverseGetArrayOfNodes(agenda->head, 0, entries);

    listEntriesWithComparator(entries, agenda->size, &ageComparator);
}

unsigned int traverseGetArrayOfNodes(TREE_AGENDA_NODE *node, unsigned int pos, AGENDA_ENTRY *entries) {
    if (node == NULL) {
        return pos;
    }

    unsigned int newPos = traverseGetArrayOfNodes(node->left, pos, entries);
    entries[newPos] = node->entry;
    newPos = traverseGetArrayOfNodes(node->right, newPos + 1, entries);

    return newPos;
}

unsigned int traversePrintNode(TREE_AGENDA_NODE *node, unsigned int pos) {
    if (node == NULL) {
        return pos;
    }

    unsigned int newPos = traversePrintNode(node->left, pos);
    printEntry(&node->entry, newPos);
    newPos = traversePrintNode(node->right, newPos + 1);

    return newPos;
}

void traverseAddingFromNode(TREE_AGENDA_NODE *root, TREE_AGENDA_NODE *traversableNode) {
    if(traversableNode == NULL){
        return;
    }
    
    traverseAddingFromNode(root, traversableNode->left);
    addEntryToNode(root, traversableNode);
    traverseAddingFromNode(root, traversableNode->right);
}

void traverseRemovingFromNode(TREE_AGENDA_NODE *node, char *fullName, bool right) {
    TREE_AGENDA_NODE *nodeToBeRemoved;

    if(right){
        int comparison = strcmp(getFullName(&node->right->entry), fullName);
        if(comparison == 0){
            // node to be removed is on left part of node
            nodeToBeRemoved = node->right;
            node->right = NULL;

            traverseAddingFromNode(node, nodeToBeRemoved->left);
            traverseAddingFromNode(node, nodeToBeRemoved->right);

            free(nodeToBeRemoved);
        } else if (comparison < 0){
            traverseRemovingFromNode(node->right, fullName, true);
        } else {
            traverseRemovingFromNode(node->right, fullName, false);
        }
    } else {
        int comparison = strcmp(getFullName(&node->left->entry), fullName);
        if(comparison == 0){
            // node to be removed is on left part of node
            nodeToBeRemoved = node->left;
            node->left = NULL;

            traverseAddingFromNode(node, nodeToBeRemoved->left);
            traverseAddingFromNode(node, nodeToBeRemoved->right);

            free(nodeToBeRemoved);
        } else if (comparison < 0){
            traverseRemovingFromNode(node->left, fullName, true);
        } else {
            traverseRemovingFromNode(node->left, fullName, false);
        }
    }
}

void addEntryToNode(TREE_AGENDA_NODE *traversingNode, TREE_AGENDA_NODE *newNode) {
    AGENDA_ENTRY traversingNodeEntry = traversingNode->entry;
    if (fullNameComparator(&traversingNodeEntry, &newNode->entry) > 0) {
        // traversing node is bigger, new node must be on the left
        if (traversingNode->left == NULL) {
            // add tree node as left node
            traversingNode->left = newNode;
        } else {
            // add tree entry to left node
            addEntryToNode(traversingNode->left, newNode);
        }
    } else {
        // traversing node is slower, new node must be on the right
        if (traversingNode->right == NULL) {
            // add tree node as right node
            traversingNode->right = newNode;
        } else {
            // add tree entry to right node
            addEntryToNode(traversingNode->right, newNode);
        }
    }
}
