#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "structure.h"
#include <string.h>
#include <stdlib.h>



void fileOpen() {
	FILE* file;
	file = fopen("data.csv", "r");
	if (file == NULL) {
		printf("File not found");
		return 1;
	}
	char buffer[64];
	char* data;
	while (fgets(buffer, 64, file)) {
		item* object = malloc(sizeof(item));
		memset(object, 0, sizeof(item));
		data = strtok(buffer, ",");
		data = strtok(NULL, ",");
		strcpy(object->Name, data);
		
		data = strtok(NULL, ",");
		data = strtok(NULL, ",");
		object->Value = atoi(data);
		
	}
}

void ajouter(Node* head, void* newData) {
	Node* n = malloc(sizeof(Node));
	Node* temp = head;
	n->data = newData;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	n = temp->next;
	n->prev = temp;
	n->next = NULL;
	n->data = newData;
	
}

void enlever(Node* head,Node* value ) {
	Node* temp = head;
	int wasFound = 0;
	while (temp != head->prev) {
		if ((int)temp->data == value) { wasFound = 1; break; }
		temp = temp->next;
	}
	if (!wasFound) {
		return; 
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}

void trier() {
//(ne marche pas aussi)
// 	if head == NULL || head->next == NULL) {
//		return;
//	}
//
//	Node* current, * nextNode;
//	int swapped;
//	do {
//		swapped = 0;
//		current = *head;
//		while (current->next != NULL) {
//			nextNode = current->next;
//			if ((item.current->data)->Value > (item.nextNode->data)->Value) {
//				void* tempData = current->data;
//				current->data = nextNode->data;
//				nextNode->data = tempData;
//				swapped = 1;
//			}
//			current = current->next;
//		}
//	} while (swapped);
//}
	
}

void Value(Node* head, Node* Value) {
	Node* temp = head->next;
	while (((item*)temp->data)->Value != Value)
	{
		if (temp == head->prev) {
			temp = NULL;
			break;
		}
		temp = temp->next;
	}
	return temp->data;
}

void searchName(Node* head, Node* Value) {
	Node* temp = head->next;
	while (((item*)temp->data)->Value != Value)
	{
		if (temp == head->prev) {
			temp = NULL;
			break;
		}
		temp = temp->next;
	}
	return temp->data;



}

void printInventory(Node* inventory) {
	Node* temp = inventory;
	while (temp != NULL) {
		item* itemData = temp->data;
		printf("Item: Name=%c, Value=%d\n", itemData -> Name, itemData->Value);
		temp = temp->next;
	}

}

void main() {
	int selection = 0;
	Node* itemList = NULL; 
	Node* inventory = NULL;
	fileOpen(&itemList, &inventory);
	ajouter(&itemlist, fiole);

	item* fiole = malloc(sizeof(item));
	fiole->Name = 'f';
	fiole->Value = 10;
	ajouter(&inventory, fiole);

	srand(time(NULL));
	int numRandomItems = rand() % 10 + 1; 
	Node* temp = itemList;
	while (temp != NULL && numRandomItems > 0) {
		item* newItem = malloc(sizeof(item));
		newItem->Name = ((item*)temp->data)->Name;
		newItem->Value = ((item*)temp->data)->Value;
		ajouter(&inventory, newItem);
		temp = temp->next;
		numRandomItems--;
	}
	
	printf("Inventory:\n");
	printInventory(inventory);

	
	trier(&inventory);

	
	enlever(&inventory, "f");

	
	printf("\nInventory after sorting and removing 'fiole':\n");
	printInventory(inventory);
	}
	
return 0;
}