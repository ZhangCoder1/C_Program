#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/* -------- Definitions & helper functions (do NOT modify) -------- */
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

static Node* make_node(int v) 
{
    Node* p = (Node*)malloc(sizeof * p);
    p->data = v;
    p->next = NULL;
    return p;
}
/* Append using a tail pointer. Use this in main() to build lists. */
static void push_back_tail(Node** head, Node** tail, int v) 
{
    Node* n = make_node(v);
    if (!*head) { *head = *tail = n; }
    else { (*tail)->next = n; *tail = n; }
}
/* --------------------------- TODOs --------------------------- */
void print_list_prefixed(const char* label, const Node* h) 
{
    printf("%s:", label);
    if (h == NULL)//print a blank line after the label if the list is empty 
    {
        printf("\n");
        return;
    }
    while (h != NULL) 
    {
        printf(" %d", h->data);
        h = h->next;
    }
    printf("\n");
}
void free_list(Node* h) 
{
    while (h != NULL)
    {
        Node* next = h->next;  // 先保存下一个节点
        free(h);               // 释放当前节点
        h= next;              // 移动到已保存的下一个节点
    }
}
Node* merge_sorted_lists(const Node* a, const Node* b) 
{
        Node dummy = { 0, NULL };
        Node* tail = &dummy;
        while (a && b) 
        {
            if (a->data <= b->data) 
            {
                tail->next = make_node(a->data);
                tail = tail->next;
                a = a->next;
            }
            else 
            {
                tail->next = make_node(b->data);
                tail = tail->next;
                b = b->next;
            }
        }
        // Append remaining elements 
        while (a) 
        {
            tail->next = make_node(a->data);
            tail = tail->next;
            a = a->next;
        }
        while (b) {
            tail->next = make_node(b->data);
            tail = tail->next;
            b = b->next;
        }
        return dummy.next;
}

void unique_in_place(Node* head) 
{
    for (Node* cur = head; cur && cur->next; ) 
    {
         if (cur->data == cur->next->data) 
         {
             Node * dup = cur->next; // unlink duplicate
             cur->next = dup->next;
             free(dup);
         }
        else 
         { 
             cur = cur->next; 
         }
    }
}

Node* intersect_sorted_lists(const Node* a, const Node* b) 
{
    Node dummy = { 0, NULL }, * tail = &dummy;
     while (a && b) 
     {
        if (a->data < b->data) 
        {
             int v = a->data;
             do {
                 a = a->next; 
                }
             while (a && a->data == v);
            
        }
        else if (b->data < a->data) {
            int v = b->data;
             do { 
                 b = b->next; 
                } 
             while (b && b->data == v);
           
        }
        else {
             int v = a->data; // match
             // Skip runs in both lists
             do { a = a->next; } while (a && a->data == v);
             do { b = b->next; } while (b && b->data == v);
            //Append once
            tail->next = make_node(v);
            tail = tail->next;
           
        }
    }
     return dummy.next;
}

int main() {
    int n, m;
    Node* A = NULL, * At = NULL;   // head & tail of A
    Node* B = NULL, * Bt = NULL;   // head & tail of B

    //TODO: build up the lists
       // Read first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push_back_tail(&A, &At, value);
    }

    // Read second list  
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        push_back_tail(&B, &Bt, value);
    }
    /* -------- Compute and Output (do NOT modify) -------- */
    Node* M = merge_sorted_lists(A, B);     // duplicates-allowing merge
    unique_in_place(M);                     // remove adjacent duplicates IN PLACE
    Node* I = intersect_sorted_lists(A, B); // strictly increasing

    print_list_prefixed("MERGE", M);
    print_list_prefixed("INTERSECTION", I);

    //TODO: implement free_list() and call it for A, B, M, and I
    free_list(A);
    free_list(B);
    free_list(M);
    free_list(I);
    return 0;
}