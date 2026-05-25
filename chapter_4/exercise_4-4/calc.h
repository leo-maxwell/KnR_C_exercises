#define NUMBER '0'
#define BUFSIZE 100
#define STACKSIZE 1024
#define OPSIZE 256
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

void print_top(void);
void dup_top(void);
void clear(void);
void swap_top(void);
