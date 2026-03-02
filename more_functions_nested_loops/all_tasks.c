#include "main.h"
#include <unistd.h>
int _putchar(char c){return write(1,&c,1);}
int _isupper(int c){return (c>='A' && c<='Z');}
int _isdigit(int c){return (c>='0' && c<='9');}
int mul(int a,int b){return a*b;}
void print_numbers(void){int i;for(i='0';i<='9';i++)_putchar(i);_putchar('\n');}
void print_most_numbers(void){int i;for(i='0';i<='9';i++){if(i!='2' && i!='4')_putchar(i);}_putchar('\n');}
void more_numbers(void){int i,j;for(i=0;i<10;i++){for(j=0;j<=14;j++){if(j>=10)_putchar('1');_putchar('0'+j%10);}_putchar('\n');}}
void print_line(int n){int i;for(i=0;i<n;i++)_putchar('_');_putchar('\n');}
int main(void){_putchar('\n');print_numbers();print_most_numbers();more_numbers();print_line(0);print_line(2);print_line(10);print_line(-4);return 0;}
