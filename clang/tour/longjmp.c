#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf mark;

void p(void);
void recover(void);

int main() {
	// save stack environment
	if(setjmp(mark) != 0) {
		printf("longjmp has been called\n");
		recover();
		exit(1);
	}
	printf("setjmp has bee called\n");
	printf("Calling function p()\n");
	p();
	printf("Never reached point ...\n");
	return 0;
}

void p(void) {
	printf("Calling longjmp() from function p()\n");
	// void longjmp(jmp_buf env, int value);
	// value 是 nonzero 如果是 0 会减一
	longjmp(mark, -1);
	printf("Never reached point ...\n");
}

void recover(void) {
	printf("Performing function recover()\n");
}
