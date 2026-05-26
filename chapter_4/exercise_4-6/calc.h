// control plane conventions
// commands 256-511 inclusive
// simple one char operations, number indicator, variables 1-255 inclusive
// miscs starts from 512 inclusive

#define NUMBER '0'
#define BUFSIZE 100
#define STACKSIZE 1024
#define OPSIZE 256
#define CMDSIZE 16
#define ANS '@'

enum operations {SIN = 256, COS, TAN, EXP, POW, EQA};
enum miscs {VARIABLE = 512, ERR_ILLEGAL_COMMAND};
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
