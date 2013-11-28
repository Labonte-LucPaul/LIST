/*
 ============================================================================
 Name        : List.c
 Author      : Luc Paul Labonté
 Date	     : 17-11-2012
 Version     : 1.0
 Copyright   : Copy right 2012-2014
 Description : A two side ways chained list.
 Licence     : http://creativecommons.org/licenses/by-sa/3.0/deed.en_US
 Repository  : https://github.com/Labonte-LucPaul/LIST
 Warning     : This code is provide as is.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct _node {

	/// @brief The pointer to your element.
	Element elem;

	/// @brief The next node.
	Node* next;

	/// @brief The previous node.
	Node* before;

};

struct _list {

	/// @brief The number of elements in the list.
	int size;

	/// @brief The pointer to the head of the list.
	Node* head;

	/// @brief The pointer to the tail of the list.
	Node* tail;

	/// @brief The pointer to the iterator of the list.
	Node* iterator;

	/// @brief A function pointer provided by the user to custum clear the Element structure data.
	void (*clear) (Element);
};

LIST* LIST_createList() {

	LIST* lst = (LIST*) malloc( sizeof(LIST) );

	if( NULL == lst ) {
		return NULL;
	}
	lst->head 	  = NULL;
	lst->tail 	  = NULL;
	lst->iterator     = NULL;
	lst->size 	  = 0;
	lst->clear	  = NULL;

	return lst;
}

void LIST_insertAt( const int pos, Element e, LIST* l ) {

	if( l != NULL ) {
		if( l->size == 0 ) {
			Node* newNode 	= (Node*) malloc( sizeof(Node) );	// TODO NULL verification.
			newNode->elem 	= e;
			newNode->next 	= NULL;
			newNode->before = NULL;

			l->head = newNode;
			l->tail = newNode;
			l->size++;

		} else if( pos <= 0 ) {
			LIST_setHead( e, l );

		} else if( pos >= l->size) {
			LIST_setTail( e, l );

		} else {

			int i;
			Node* tmp = l->head;
			for( i = 0; i < pos && i < l->size; ++i ) {
				tmp = tmp->next;
			}
			Node* newNode 	  = (Node*) malloc( sizeof(Node) );	// TODO NULL verification
			newNode->elem 	  = e;
			newNode->next 	  = tmp;
			newNode->before   = tmp->before;
			tmp->before->next = newNode;
			tmp->before 	  = newNode;
			tmp               = NULL;
			newNode           = NULL;
			l->size++;
		}
	}
}

void LIST_insertBefore( const int pos, Element e, LIST* l ) {
	LIST_insertAt( pos - 1, e, l );
}

void LIST_insertAfter( const int pos, Element e, LIST* l ) {
	LIST_insertAt( pos + 1, e, l );
}

void LIST_setHead( Element e, LIST* l ) {

	if( l->size == 0 ) {
		LIST_insertAt( 0, e, l );
	} else {
		Node* newNode = (Node*) malloc( sizeof(Node) );	// TODO NULL verification

		newNode->elem 	= e;
		newNode->before = NULL;
		l->head->before = newNode;
		newNode->next 	= l->head;
		l->head         = newNode;
		newNode         = NULL;
		l->size++;
	}
}

void LIST_setTail( Element e, LIST* l ) {

	if( l->size == 0 ) {
		LIST_insertAt( 0, e, l );
	} else {
		Node* newNode = (Node*) malloc( sizeof(Node) );	// TODO NULL verification

		newNode->elem 	= e;
		newNode->before = l->tail;
		l->tail->next	= newNode;
		newNode->next 	= NULL;
		l->tail         = newNode;
		newNode         = NULL;
		l->size++;
	}
}

Element LIST_getHead( LIST* l ) {
	return l->head->elem;
}

Element LIST_getTail( LIST* l ) {
	return l->tail->elem;
}

Element LIST_getElemAt( const int pos, LIST* l ) {
	if( l != NULL && l->size > 0 ) {

		if( pos <= 0 ) {
			return LIST_getHead( l );
		} else if( pos >= l->size - 1 ) {
			return LIST_getTail( l );
		} else {
			Node* tmp = l->head;
			int i;

			for( i = 0; i < pos && i < l->size; ++i ) {
				tmp = tmp->next;
			}
			return tmp->elem;
		}

	}

	return NULL;
}

Element LIST_removeElemAt( const int pos, LIST* l ) {

	if( l != NULL && l->size > 0) {
		Node* tmp;

		if( pos <= 0 ) {
			tmp = l->head;
			l->head = tmp->next;
		} else if( pos >= l->size - 1 ) {
			tmp = l->tail;
			l->tail = tmp->before;
		} else {
			int i;
			tmp = l->head;
			for( i = 0; i < pos && i < l->size; ++i ) {
				tmp = tmp->next;
			}
			tmp->before->next = tmp->next;
			tmp->next->before = tmp->before;

			tmp->next   = NULL;
			tmp->before = NULL;
		}
		l->size--;
		return tmp->elem;
	}

	return NULL;
}

void LIST_initIterator( LIST* l ) {
	l->iterator = l->head;
}

Element LIST_iterate( LIST* l ) {
	if( l->iterator != NULL ) {
		Node* it = l->iterator;
		l->iterator = l->iterator->next;
		return it->elem;
	}
	return NULL;
}

int LIST_getSize( LIST* l ) {
	return l->size;
}

void LIST_deleteElemAt( const int pos, LIST* l ) {
	if( l != NULL && l->size > 0 ) {
		Element e = LIST_removeElemAt( pos, l );
		if( l->clear != NULL ) {
			l->clear( e );
		}
		free( e );
		e = NULL;
	}
}

void LIST_setClear( void* c, LIST* l ) {
	l->clear = c;
}

void LIST_destroy( LIST* l ) {
	if( l != NULL && l->size > 0 ) {
		LIST_initIterator( l );
		while( l->size > 0 ) {
			LIST_deleteElemAt(0, l);
		}
		l->head     = NULL;
		l->tail     = NULL;
		l->size     = 0;
		l->iterator = NULL;
		free( l );
	}
}
