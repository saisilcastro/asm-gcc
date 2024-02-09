#ifndef INCLUDE_ASSEMBLY_ASSEMBLY_H_
#define INCLUDE_ASSEMBLY_ASSEMBLY_H_

/*
 +---+--------------------+
 | r |    Register(s)     |
 +---+--------------------+
 | a |   %eax, %ax, %al   |
 | b |   %ebx, %bx, %bl   |
 | c |   %ecx, %cx, %cl   |
 | d |   %edx, %dx, %dl   |
 | S |   %esi, %si        |
 | D |   %edi, %di        |
 +---+--------------------+
 */
#define ASM __asm__ __volatile__

int mul(int a,int b);
int	add(int a, int b);
int sub(int a, int b);
int left(int a);
int	_strlen(unsigned char *s);
void mouse(unsigned char *x, unsigned char *y);
int loop(int *x, int y);
int isnum(int letter);
int isalpha(int letter);
int	hasspace(int c);
int	_strlen(unsigned char *s);
void _memset(void *data, int c, int size);
int	_tolower(int c);
int	_toupper(int c);

#endif /* INCLUDE_ASSEMBLY_ASSEMBLY_H_ */
