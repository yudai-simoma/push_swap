#include <stdio.h>

#ifndef COMP_DEF_FLAG
# define COMP_DEF_FLAG 2
#endif

#if COMP_DEF_FLAG == 1
int main(void) {
	char argc = 1;
#elif COMP_DEF_FALG == 2
int main(void)
	char argc = 2;
#else 
int main(int argc, char **argv) {
#endif
	printf("argc : %d\n", argc);
}
