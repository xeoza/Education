// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

extern "C" int DlinaStroki(char *s);
extern "C" char *CopyStr(char *s1, char *s2, int L);

int _tmain(int argc, _TCHAR* argv[])
{
	char *s = "string";
	int a;
	a = DlinaStroki(s);

	char *s0 = new char[10];
	
	s0[0] = 'a';
	s0[1] = 'b';
	s0[2] = 'c';
	s0[3] = 'd';
	s0[4] = 'e';
	s0[5] = 'f';
	s0[6] = 'g';
	s0[7] = 'h';
	s0[8] = 'i';
	s0[9] = '\0';

	char *s1 = &s0[2];
	char *s2 = &s0[4];

	int L = 3;
	char *s3 = nullptr;
	s3 = CopyStr(s1, s2, L);

	delete s0;

	return 0;
}

