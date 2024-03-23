#pragma once
typedef struct item{
	char Name;
	int Value;
} item;

typedef struct Node Node;
struct Node{
	void* data;
	Node* prev;
	Node* next;
};


