#include <stdio.h>
#include <assembly/assembly.h>

int mul(int a, int b) {
	int result;
	asm (
			"movl %1,%%eax;"
			"movl %2,%%ebx;"
			"mul %%ebx;"
			: "=g" (result) : "a" (a), "b" (b)
	);
	return result;
}

int	add(int a, int b)
{
	int result;
	asm (
		"movl %1,%%eax;"
		"movl %2,%%ebx;"
		"addl %%ebx, %%eax;"
		: "=g" (result) : "a" (a), "b" (b)
	);
	return (result);
}

int	sub(int a, int b)
{
	int result;
	asm (
		"movl %1,%%eax;"
		"movl %2,%%ebx;"
		"subl %%ebx, %%eax;"
		: "=g" (result) : "a" (a), "b" (b)
	);
	return (result);
}

int left(int a)
{
	int result;
	asm (
		"movl %1,%%eax;"
		"movl $10,%%ebx;"
		"shl %%eax;"
		"addl %%ebx,%%eax;"
		: "=g" (result) : "a" (a)
	);
	return (result);
}

#include <stdio.h>

int _strlen(unsigned char *str) {
    unsigned char len = 0;
    unsigned char *s = str;

    asm (
        "mov $0, %0;"
        "increase:;"
        "cmpb $0, (%1);"
        "je done;"
        "inc %0;"
        "inc %1;"
        "jmp increase;"
        "done:;"
        : "+r" (len), "+r" (s)
        :
        : "cc", "memory"
    );

    printf("%i\n", len);
    return len;
}

void mouse(unsigned char *x, unsigned char *y)
{
	asm (
		"mov $0x1,%%ax;"
		"mov %%ax,%%dx;"
		"int $0x13;"
		: "=r" (*x)
		:
		: "%ax"
	);
}

int loop(int *x, int y)
{
	while (*x < y)
	{
		printf("%i\n", *x);
		asm (
			"cmp %2,%1;"		// x is greater or equals to y?
			"jge done_loop;"	// yes, finish the function
			"inc %1;"
			"done_loop:"
			: "=a" (*x) : "a" (*x), "b" (y)
		);
	}
	return (1);
}

int isnum(int number)
{
	char range;
	asm (
		"cmp $0x30,%1;"			// compare number with 0
		"jb number_outrange;"	// if it is below finish the function
		"cmp $0x39,%1;"			// compare the number with 9
		"jbe number_range;"		// if it is in range then it is ok
		"number_outrange:"		// it is out of range
		"mov $0,%%dx;"			// changes the range to 0 to say an error
		"jmp number_done;"		// finish the function
		"number_range:"			// number is in range
		"mov $1,%%dx;"			// changes range to 1 to say it is ok
		"number_done:"			// all done
		: "=d" (range)
		: "a" (number)
	);
	return (range);
}

int isalpha(int letter)
{
	char alpha;
	asm (
		"cmp $0x41,%1;" 			// is it below A
		"jb alpha_outrange;"		// yes, finish the function
		"cmp $0x5A,%1;"				// is below the Z
		"jbe alpha_range;"			// it is in range. everything ok
		"cmp $0x61,%1;"				// is it below the a
		"jb alpha_outrange;"		// yes, finish the function
		"cmp $0x7A,%1;"				// is it below the z
		"jbe alpha_range;"			// yes, it is in range. everything ok
		"alpha_outrange:"			// we are outrange
		"mov $0,%%dx;"				// say that we've got an error with value 0
		"jmp alpha_done;"			// jump to the end with fail
		"alpha_range:"				// we are in range
		"mov $1,%%dx;"				// change the flag to say we are in range
		"alpha_done:"				// we are done here
		: "=d" (alpha)
		: "a" (letter)
	);
	return (alpha);
}