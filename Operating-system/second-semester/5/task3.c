#include <stdio.h>

int main()
{
	FILE* fs1 = fopen("test_fopen.txt", "w"); 
	FILE* fs2 = fopen("test_fopen.txt", "w");

	int flag = 0;

	for(char c = 'a'; c <= 'z'; c++)
	{
		if (!flag)
		    fprintf(fs1, "%c", c);
		else
		    fprintf(fs2, "%c", c);
		flag = !flag;
	}
	fclose(fs1); 
	fclose(fs2);

	return 0;
}
