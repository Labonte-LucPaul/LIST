/*
 * 		list.h
 *
 *  Created on: 17-11-2012
 *  Author: Luc Paul Labonté
 *
 *
 */

#ifndef LIST_H_
#define LIST_H_

//#define FORCE_NULL

/**
 * @defgroup mod_list list.h
 * @file list.h
 * @brief This module allows you to create a dynamic list of that contains
 * elements of your choices! It can be integers, chars, pointers, structs, etc.
 *
 *	@warning This module is provided "as is".
 *
 *	@author Luc Paul Labonté
 *	@date 17-11-2012
 *	@version 1.0
 *
 *	@htmlonly
 *	<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/deed.en_US">
 *	<img alt="Creative Commons License" style="border-width:0"
 *	src="http://i.creativecommons.org/l/by-sa/3.0/88x31.png" /></a><br />
 *	<span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">LIST.c</span>
 *	by <span xmlns:cc="http://creativecommons.org/ns#" property="cc:attributionName">
 *	list</span> is licensed under a <a rel="license"
 *	href="http://creativecommons.org/licenses/by-sa/3.0/deed.en_US">
 *	Creative Commons Attribution-ShareAlike 3.0 Unported License</a>.
 *	@endhtmlonly
 */

/// @brief A pointer to the element to store in the list.
typedef void* Element;

/// @brief A node of the chain of the list.
typedef struct _node Node;

/// @brief The structure of the list.
typedef struct _list LIST;

/**
 * @brief The "Constructor" of the list. Creates the structure with malloc.
 * @return A pointer to the structure of the list.
 * @return NULL if there was an error with malloc.
 */
LIST* LIST_createList();

/**
 * @brief Insert the Element <i>e</i> at the specified position <i>pos</i>.
 * 		  If an element already exist at the position <i>pos</i>, it is moved
 * 		  has the next element of the inserted one. If <i>pos</i> is greater
 * 		  or equals than <i>size</i> the element is added at the end.
 * 		  If <i>pos</i> is less than or equals 0, it is added at the head.
 *
 * @param pos (const int) The position to insert the Element <i>e</i> at.
 * @param e (Element) The element to add in the list. (int, char, struct,...)
 * 		@pre e != NULL
 * 		@post e is added to the list
 * @param l (LIST*) The list.
 * 		@pre l != NULL
 * 		@post The Element <i>e</i> is added to the list.
 */
void LIST_insertAt(const int pos, Element e, LIST* l);

/**
 *	@brief Will insert the Element <i>e</i> <b>before</b> the selected position
 *		   <i>pos</i>. If pos is less or equals than 0, it will be added at the
 *		   head of the <b>LIST</b>. If <i>pos</i> is greater of equals
 *		   <i>size</i> it will be added at the tail of the list.
 *
 * @param pos (const int) The position to insert the Element before.
 * @param e (Element) The Element to insert in the list. (int, char, struct,...)
 * 		@pre i != NULL
 * @param l (LIST*) The structure of the list.
 * 		@pre i != NULL
 */
void LIST_insertBefore(const int pos, Element e, LIST* l);

/**
 * 	@brief Insert the Element <i>e</i> <b>after</b> the selected position
 * 		   <i>pos</i>. If pos is less or equals than 0, it will be added at the
 *		   head of the <b>LIST</b>. If <i>pos</i> is greater of equals
 *		   <i>size</i> it will be added at the tail of the list.
 * @param pos (const int) The position to insert the Element after.
 * @param e (Element) The Element to insert in the list. (int, char, struct,...)
 * 		@pre i != NULL
 * @param l (LIST*) The structure of the list.
 * 		@pre i != NULL
 */
void LIST_insertAfter(const int pos, Element e, LIST* l);

/**
 *  @brief Insert the Element <i>e</i> at the head of the list.
 *
 * @param e (Element) The Element to insert in the list. (int, char, struct,...)
 * 		@pre i != NULL
 * @param l (LIST*) The structure of the list.
 * 		@pre i != NULL
 */
void LIST_setHead(Element e, LIST* l);

/**
 *  @brief Insert the Element <i>e</i> at the tail of the list.
 *
 * @param e (Element) The Element to insert in the list. (int, char, struct,...)
 * 		@pre i != NULL
 * @param l (LIST*) The structure of the list.
 * 		@pre i != NULL
 */
void LIST_setTail(Element e, LIST* l);

/**
 *  @brief Return the Element at the head of the list.
 *
 * @param l (LIST*) The structure of the list.
 * 		@pre i != NULL
 * @return (Element) The Element at the beginning of the list.
 * 	@post Use a type cast.
 */
Element LIST_getHead(LIST* l);

/**
 *  @brief Return the Element at the tail of the list.
 *
 * @param l (LIST*) The structure of the list.
 * 		@pre i != NULL
 * @return (Element) The Element at the end of the list.
 * 	@post Use a type cast. See example.
 */
Element LIST_getTail(LIST* l);

/**
 *  @brief Get the Element at the specified position <i>pos</i> of the list.
 *  	   If the position is greater or equals than size, the tail is returned.
 *  	   If the position is less or equals than 0, the head is returned.
 *
 * @param pos (const int) The position of the element.
 * @param l (LIST*) The structure List.
 * @return (Element) The element at the specified position.
 * 	@post Use a type cast. See example.
 */
Element LIST_getElemAt(const int pos, LIST* l);

/**
 *  @brief Remove the Element specified at the position. The pointer to the
 *  	   Element is returned. No free() instruction is used here.
 *  	   If the position is greater or equals than size, the tail is returned.
 *  	   If the position is less or equals than 0, the head is returned.
 *
 * @param pos (const int) The position to remove and return the Element.
 * @param l (LIST*) The strucutre of the list.
 * 		@pre l != NULL
 * @return (Element) The element removed from the list at the given position.
 */
Element LIST_removeElemAt(const int pos, LIST* l);

/**
 *  @brief Iterator of the LIST. Return the Element at the current iterate
 *  	   position, then point to the next. If the iterator has reach a NULL
 *  	   for the Next Node of an Element, NULL will be returned.
 *
 *  @pre The function LIST_initIterator() must be used first and every time
 *  	 the iterator should be resetted to the beginning.
 *
 * @param l (LIST*) The strucutre of the list.
 * 		@pre l != NULL
 * @return (Element) The Element where the iterator is pointing.
 */
Element LIST_iterate(LIST* l);

/**
 *	@brief Initialize the Iterator. It will point to the head of the LIST
 *		   every time it is called. To be used before using the
 *		   <i>LST_iterate()</i> function.

 *	@warning To use only when wanting to reset the iterator to the head.
 *
 * @param l (LIST*) The strucutre of the list.
 * 		@pre l != NULL
 */
void LIST_initIterator(LIST* l);

/**
 * 	@brief Get the size of the list. The number of Element in the list.
 *
 * @param l (LIST*) The strucutre of the list.
 * 		@pre l != NULL
 * @return (int) The number of Element in the lise.
 */
int LIST_getSize(LIST* l);

/**
 * 	@brief Allows the user to set his clear function to destroy the content of
 * 			the <b>Element</b> in the structure. This is used in case the <b>Element</b>
 * 			is a structure. The user provide the destructive code to free the
 * 			memory of the structure.
 *
 * 	@warning THE USE OF THIS FUNCTION IS YOUR OWN RISK.
 *
 * @param c (void*)(Element) The name of your function.
 * @param l (LIST*) The strucutre of the list.
 * 		@pre l != NULL
 */
void LIST_setClear(void* c, LIST* l);

/**
 * 	@brief Allows the user to set a function for handling errors.
 * @param e (void*)(char*) The function to execute when an error occurs. Takes a char* param.
 * @param l (LIST*) The structure of the list.
 * 		@pre l != NULL
 */
void LIST_setErrorHandler(void* e, LIST* l);

/**
 * 	@brief Delete from the list the Element at the specified position
 * 		   <i>pos</i>. The Element is removed from the list, then the
 * 		   function <b>free()</b> is uded. The Element is <b>NOT</b> returne.
 * 		   If the position is greater or equals than size, the tail is returned.
 *  	   If the position is less or equals than 0, the head is returned.
 *		   If the function <b>LIST_setClear()</b> is used before the destructive
 *		   function of the user will be used before to clear it's element properly.
 *
 * @warning TO USE WITH CAUTION! THE FUNCTION FREE IS USED. IT MYGHT BE BETTER
 * 	        TO USE THE FUNCTION <b>LIST_removeElemAt()</b> INSTEAD.
 *
 * @param pos (const int) The position to remove and return the Element.
 * @param l (LIST*) The strucutre of the list.
 * 		@pre l != NULL
 */
void LIST_deleteElemAt(const int pos, LIST* l);

/**
 * @brief Delete the entire list. Iterate through the Elements of the list and
 * 		  use the function <b>free()</b> to clear the memory.
 * 		  Also clear the function pointers.
 *
 * @param l (LIST*) The strucutre of the list.
 * 		@pre l != NULL
 */
void LIST_destroy(LIST* l);

/**
 * @example
 * 	How to use the list.
 * @code
 *
 #include <stdio.h>
 #include <stdlib.h>
 #include "list.h"

 void myClear( Element e ) {
	free( e );
	e = NULL;
 }
 int main( void ) {

	 char* s1 = "1";
	 char* s2 = "2";
	 char* s3 = "3";
	 char* s4 = "4";
	 char* c1 = "My string!";

	 LIST* lst = LIST_createList();

	 LIST_setHead( "First Element", lst );
	 LIST_setTail( "My second Element", lst );
	 LIST_insertAt( 1, s4, lst );
	 LIST_insertAt( 2, s1, lst );
	 LIST_insertAt( 3, s3, lst );
	 LIST_insertAt( 3, s2, lst );
	 LIST_insertAt( 6, c1, lst );
	 LIST_insertAt( 1, (char*) LIST_removeElemAt(5,lst), lst );
	 LIST_insertAt( 5, (char*) LIST_removeElemAt(2,lst), lst );

	 LIST_initIterator( lst );

	 printf( "Nb Elements: %d\n", LIST_getSize(lst) );
	 char* tmp;
	 int i = 0;
	 while( (tmp = (char*) LIST_iterate(lst)) != NULL ) {
		 printf( "%d: %s\n", i, tmp );
		 ++i;
	 }

	 LIST_setClear( myClear, lst );

	 LIST_destroy( lst );

	 return 0;
 }

 Result:
 Nb Elements: 7
 0: First Element
 1: My second Element
 2: 1
 3: 2
 4: 3
 5: 4
 6: My string!
 * @endcode
 */

#endif /* LIST_H_ */
