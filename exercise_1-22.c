#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 10
#define TAB_SIZE 8

typedef struct node {
    struct node *pp;
    int c;
    int idx;
    struct node *np;
} Node;

void destroy(Node* n) {
    while (n) {
        Node *np = n->np;
        free(n);
        n = np;
    }
}

void print_all(Node *n) {
    while (n) {
        putchar(n->c);
        n = n->np;
    }
}

void print_until(Node *n, int idx) {
    while(n) {
        if (n->idx < idx) {
            putchar(n->c);
        } else {
            return;
        }
        n = n->np;
    }
}

Node* init_node(int c) {
    Node* n = malloc(sizeof *n);
    n->pp = NULL;
    n->idx = 0;
    n->np = NULL;
    n->c = c;
    return n;
}

void multiple_split(Node *buf_head) {
    Node *cur;
    Node *expedition;
    Node *breaker;
    // Node *prev_breaker;
    int column = -1;
    int realtext_flag = 0;
    cur = buf_head;
    expedition = buf_head;
    breaker = NULL;
    // prev_breaker = NULL;
    while (1) {
        if (!expedition || expedition->c == '\n') break;
        if (expedition->c != '\t' || expedition->c != ' ') {
            realtext_flag = 1;
        }
        // traverse the buffer one by one and find breakers
        if (expedition->c == '\t' || expedition->c == ' ') {
            // prev_breaker = breaker;
            if (realtext_flag) breaker = expedition;
        }
        // update the column and continue traversal
        column = (expedition->c) == '\t' ? (column/TAB_SIZE + 1) * TAB_SIZE : column + 1;
        if (column > MAX_LINE_LEN-1) { // trigger fold operation, column is zero indexed
            if (breaker != NULL && breaker->idx > cur->idx) {
            // if there is a breaker and the index is larger than the current output line start
                print_until(cur, breaker->idx);
                putchar('\n');
                cur = breaker;
            } else {
            // if there is no breaker in current output line, then force break
                expedition = expedition->pp;
                print_until(cur, expedition->idx); // notice the expedition is NOT included in the print
                putchar('-');
                putchar('\n');
                cur = expedition;
            }
            column = -1;
            expedition = cur;
            breaker = NULL;
            realtext_flag = 0;
            // prev_breaker = NULL;
        } else {
        // we only perform the advance if no folding is occured
            expedition = expedition->np;
        }
    }
    print_all(cur); // print out the remaining part
}

int main() {
    int c;
    Node *buf_head = NULL;
    Node *buf_tail = NULL;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            multiple_split(buf_head);
            putchar('\n');
            destroy(buf_head);
            buf_head = NULL;
            buf_tail = NULL;
        } else {
            if (!buf_head) {
                buf_head = init_node(c);
                buf_tail = buf_head;
            } else {
                Node *new = malloc(sizeof *new);
                new->pp = buf_tail;
                new->idx = buf_tail->idx + 1;
                new->np = NULL;
                new->c = c;
                buf_tail->np = new;
                buf_tail = new;
            }
        }
    }
    if (buf_head) multiple_split(buf_head);
    destroy(buf_head);
    return 0;
}
