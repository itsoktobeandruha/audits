#include <stdio.h>
#include <Windows.h>

typedef struct
{
	int first, last;
	
}bukvi;

int main()
{
	int cityCount=0,soedCount=0,resCount=0;
	char a;
	bukvi mass[26] = {0};
	FILE* b;
	fopen_s(&b, "input.txt", "r");
	char str[50];
	while (!feof(b))
	{
		fgets(str, 50, b);
		str[0] += 32;
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = 0;
		printf("%s\n", str);
		mass[str[0] - 97].first++;
		mass[str[strlen(str) - 1]-97].last++;
		cityCount++;
	} 
	for (int i = 0; i < 26; i++)
	{
		soedCount += min(mass[i].first, mass[i].last);
	}
	resCount = cityCount - soedCount;
	if (resCount == 1)
		printf("result: Yes you can!");
	else
		printf("result: No, you can't!");
	fclose(b);
}