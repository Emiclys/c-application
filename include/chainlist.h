#pragma once

template <typename T>
struct Node
{
	T data;
	void (*callback_ptr)() = NULL;
	Node<T>* next = NULL;
	Node<T>* previous = NULL;
};

template <typename T>
struct List
{
	Node<T>* firstNode = NULL;
	Node<T>* lastNode = NULL;

	// Adiciona o item ao final da lista e retorna o ponteiro para o mesmo.
	Node<T>* append(T item)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = item;

		Node<T>* temp = firstNode;

		if (firstNode == NULL) // criando o primeiro nó
		{
			firstNode = newNode;
			return newNode;
		}

		while (temp->next != NULL)
			temp = temp->next;

		newNode->previous = temp;
		temp->next = newNode;

		lastNode = newNode;

		return newNode;
	}

	void remove(int index)
	{
		Node<T>* temp = get(index);

		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;

		delete temp;
	}

	int length()
	{
		int i = 0;
		Node<T>* temp = firstNode;

		while (temp != NULL)
		{
			temp = temp->next;
			i += 1;
		}

		return i;
	}

	Node<T>* get(int index)
	{
		Node<T>* temp = firstNode;

		for (int i = 0; i < index; i++)
			temp = temp->next;

		return temp;
	}
};