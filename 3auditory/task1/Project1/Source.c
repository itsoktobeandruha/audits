#include <stdio.h>
#include <Windows.h>

int main()
{
	printf("type ammount:\n");
	int ammount,sameNumbers=0;
	int newSizeOfMass = 0;
	scanf_s("%d", &ammount);
	int* mass;
	int* mass1;
	mass = (int*)malloc(ammount * sizeof(int));
	printf("type numbers:\n");
	for (int i = 0; i < ammount; i++)
	{
		scanf_s("%d", &mass[i]);
	}
	mass1 = (int*)calloc(ammount, sizeof(int));
	for (int i = 0; i < ammount; i++)
	{
		for (int n = 0; n < ammount; n++)
		{
			if (mass[i] == mass1[n])
			{
				sameNumbers = sameNumbers++;
			}
		}
		if (sameNumbers == 0)
		{
			mass1[newSizeOfMass] = mass[i];
			newSizeOfMass = newSizeOfMass++;
		}
	}
	mass1 = (int*)realloc(mass1, newSizeOfMass*sizeof(int));
	printf("the result is\n");
	for (int i = 0; i < newSizeOfMass; i++)
		printf("%d ", mass1[i]);
}