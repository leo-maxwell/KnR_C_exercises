// control plane conventions
// commands 256-511 inclusive
// simple one char operations and variables 1-255 inclusive
// signals starts from 512 inclusive

#define BUFSIZE 100
#define STACKSIZE 1024
#define OPSIZE 256
#define LINE_TOKENS 512
#define CMDSIZE 16
#define LINESIZE 2048
#define ANS '@'

enum operations {SIN = 256, COS, TAN, EXP, POW, EQA};
enum signals {NUMBER = 512, ONECHAROP, VARIABLE, ERR_ILLEGAL_COMMAND, ERR_ILLEGAL_NUMBER, ERR_ILLEGAL_OP};
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
