// sravnit.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"

#define MAX_SIZE 256

int diff(FILE *f1, const char *fname1, FILE *f2, const char *fname2);

void main()
{
	char file1[MAX_SIZE], file2[MAX_SIZE];
	setlocale(LC_ALL, "rus");
	FILE *f1, *f2;
	printf("Введите имя первого файла: ");
	gets_s(file1);
	fflush(stdin);
	printf("Введите имя второго файла: ");
	gets_s(file2);
	fflush(stdin);
	fopen_s(&f1, file1, "rt");
	fopen_s(&f2, file2, "rt");
	if (f1 && f2)
	{
		diff(f1, file1, f2, file2);
	}
	else
	{
		if (f1)
			fclose(f1);
		else
			printf("%s не найден.\n", file1);
		if (f2)
			fclose(f2);
		else
			printf("%s не найден.\n", file2);
	}
	system("pause");
}

int diff(FILE *f1, const char *fname1, FILE *f2, const char *fname2)
{
	char str1[MAX_SIZE], str2[MAX_SIZE];
	fseek(f1, 0, 0);
	fseek(f2, 0, 0);
	printf("\nОтвет:");
	while (!feof(f1))
	{
		int is_matched = 0;
		fgets(str1, MAX_SIZE, f1);
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] == '\n')
				str1[i] = '\0';
		}
		fseek(f2, 0, 0);
		while (!feof(f2) && !is_matched)
		{
			fgets(str2, MAX_SIZE, f2);
			for (int i = 0; i < strlen(str2); i++)
			{
				if (str2[i] == '\n')
					str2[i] = '\0';
			}
			if (!strncmp(str1, str2, MAX_SIZE))
				is_matched = 1;
		}
		if (is_matched)
			printf(" %s", str1);
	}
	printf("\n");
	return 0;
}