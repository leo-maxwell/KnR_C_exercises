#define NUMBER '0'
#define BUFSIZE 100
#define STACKSIZE 1024
#define OPSIZE 256
#define CMDSIZE 16
#define ERR_ILLEGAL_COMMAND -1

enum operations {SIN = 256, COS, TAN, EXP, POW};
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

double peek(void);
void print_top(void);
void dup_top(void);
void clear(void);
void swap_top(void);
