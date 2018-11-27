// COMP1511 18s2 -- a Set ADT
#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

// Define a new `Set` type.
struct _node {
    item data;
    struct _node *next;
};

typedef struct _node *Node;

struct _set {
    Node head;
};

// Define an `item` type.  `Set` manipulates `item`s.
//typedef int item;

// Create a new `Set`.
Set newSet(void) {
    Set new_set = malloc(sizeof(struct _set));
    new_set->head = NULL;
    //new_set->head->data
    //new_set.item = 0;
    //new_set->next = NULL;
    //Set newSet = malloc(sizeof(*newSet)); the two are same
    return new_set;
}

// Release all resources associated with a `Set`.
void destroySet(Set s) {
    
    while (s->head != NULL) {
        Node tem = s->head;
        s->head = s->head->next;
        free (tem);
    }
    free(s);
}

// Add an `item` to the `Set`.
void setAdd(Set s, item item) {
    Node new_node = malloc(sizeof(struct _node));
    new_node->data = item;
    new_node->next = NULL;
    Node curr = s->head;

    if (! setContains(s, item)) {
        if (s->head == NULL) {
            s->head = new_node;
            //return s;
         } else {   
            while (curr->next != NULL) {
                curr = curr->next;
                }
                curr->next = new_node;
        }  
    }
    
}

// Remove an `item` from the `Set`.
void setRemove(Set s, item item) {
    if (setContains(s, item)) {
        if (s->head == NULL) {
            return ;
        }
        
        Node prev = s->head;
        Node curr = s->head->next;
        while (curr != NULL && curr->data != item) {
            curr = curr->next;
        }
        
        if (curr != NULL) {
            prev->next = curr->next;
            free(curr);
        }
        
        if (s->head->data == item) {
            curr = s->head->next;
            free (s->head);
            s->head = curr;
        } 
    }
}
// Does the `Set` contain this `item`?
bool setContains(Set s, int item) {
    Node curr = s->head;
    
    if (curr == NULL) {
        return false;
    }
    
    while (curr != NULL) {
        if (curr->data == item) {
            return true;
        }
        curr = curr->next;    
    }  
    return false;
}

// How many items are in the `Set`?
int setSize(Set s) {
    Node curr = s->head;
    int count = 0;
    while (curr != NULL) {
        count ++;
        curr = curr->next;
    }
    return count;
}

// Take the union of two sets(a â?ª b).
Set setUnion(Set a, Set b) {
    Node aSet = a->head;
    Node bSet = b->head;
    Node pre_aSet;
    Set coSet;
    // one set is null
    if (aSet == NULL) {
       coSet = b; 
    } else if (bSet == NULL) {
        coSet = a;
    }
     
    while (aSet != NULL) {
        if (bSet != NULL) {
           setRemove (b, aSet->data);
        }
        pre_aSet = aSet;
        aSet = aSet->next;
    }
    pre_aSet->next = bSet;
    coSet->head = a->head;
    
    return coSet;
}

// Take the intersection of two sets(a â?© b).
Set setIntersection(Set a, Set b) {
    Set inter_Set = newSet();
    Node aSet = a->head;
    Node bSet = b->head;
    //Node interSet = inter_Set->head;
    //Node temInter = inter_Set->head;

    if (aSet == NULL) {
       inter_Set = a; 
    } else if (bSet == NULL) {
        inter_Set = b;
    }
    
    while (aSet != NULL) { 
        if (setContains(b, aSet->data)) { 
            setAdd(inter_Set, aSet->data);
        }
        
        aSet = aSet->next;
    }

    return inter_Set;
}

/*
s = newSet();
if (setIsEmpty(s)) {
    print hi

bool setIsEmpty(Set s);
*/

// Is `a` a subset of `b`(a â?? b)?
bool setSubset(Set a, Set b) {
    Node aSet = a->head;
    Node bSet = b->head;
    int count = 0;
    
    if (aSet == NULL) {
       return true; 
    } else if (bSet == NULL) {
        return false;
    }
    
    while (aSet != NULL) {
        if (setContains(b,aSet->data)) {
            count ++;
        }
        aSet = aSet->next;
    }   
    
    if (count == setSize(a)) {
        return true;
    }
    return false;
}




// Is `a` equal to `b`(where a â?? b and b â?? a, a == b).
bool setEqual(Set a, Set b) {
    Node aSet = a->head;
    Node bSet = b->head;
    //int count = 0;
    
    if (aSet == NULL && bSet == NULL) {
       return true; 
    } 
    
    if (setSize(a) == setSize(b)) {
        if(setSubset(a,b) && setSubset(b,a)) {
            return true;
        }
    }
    
    return false;
    
}








