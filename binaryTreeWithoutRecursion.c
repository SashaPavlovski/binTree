#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>
#include "Defining_types.h"

#pragma warning(disable:4996)

TLeaf* Root = NULL;
T_queue* head = NULL;
T_queue* tail = NULL;
int count = 0;


void Additem(DetailsT item)
{

	TLeaf* move = (TLeaf*)malloc(sizeof(TLeaf));
	move->Details = item;
	move->right = NULL;
	move->Left = NULL;
	if (!move)
	{
		exit(1);
	}
	if (Root == NULL)
	{
		Root = move;
		move->level = 0;
	}
	else if (Root->right == NULL)
	{
		Root->right = move;
		move->level = 1;
	}
	else if (Root->Left = NULL)
	{
		Root->Left = move;
		move->level = 1;
	}



}
void Queue_Push(TLeaf* item)
{
	count++;
	T_queue* move = (T_queue*)malloc(sizeof(T_queue));
	if (!move)
	{
		exit(1);
	}
	move->item = item;
	move->next = NULL;
	move->val = count;
	if (head == NULL)
	{
		head = move;
		tail = move;
		move->prev = NULL;
	}
	else
	{
		tail->next = move;
		move->prev = tail;
		tail = move;
	}

}
T_queue* Queue_Pop()
{
	T_queue* curr = head;
	if (curr == NULL)
	{
		return NULL;
	}
	else if (head == tail)
	{
		head = NULL;
		tail = NULL;
		return curr;
	}
	else
	{
		head = head->next;
		head->prev = NULL;
		return curr;
	}

}
void Queue_Status()
{
	T_queue* print = head;
	while (print != NULL)
	{
		printf("%d\n", print->val);
		print = print->next;
	}
}
void Queue_Clear()
{
	head = NULL;
	tail = NULL;

}



void AddTreeItem(DetailsT item)
{
	TLeaf* newLeaf = (TLeaf*)malloc(sizeof(TLeaf));
	newLeaf->Details = item;
	newLeaf->Left = NULL;
	newLeaf->right = NULL;

	if (Root == NULL)
	{
		newLeaf->parent = NULL;
		Root = newLeaf;
		newLeaf->level = 0;
	}
	else
	{
		T_queue* curr;
		TLeaf* foundEmptyPlace = NULL;
		Queue_Pop(Root);
		while ((curr = Queue_Pop()) != NULL)
		{
			foundEmptyPlace = NULL;
			if (curr->item->Left == NULL)
			{
				foundEmptyPlace = curr->item;
				foundEmptyPlace->Left = newLeaf;
				newLeaf->parent = foundEmptyPlace;

			}
			else if (curr->item->right == NULL)
			{
				foundEmptyPlace = curr->item;
				foundEmptyPlace->right = newLeaf;
				newLeaf->parent = foundEmptyPlace;
			}
			else
			{
				Queue_Push(curr->item->Left);
				Queue_Push(curr->item->right);
			}

			if (foundEmptyPlace)
				Queue_Clear();

		}
	}








}



