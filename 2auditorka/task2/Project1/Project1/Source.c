#include <stdio.h>
#include <Windows.h>

int main()
{
	int asciiCheck;
	int num1; // �������� ����� [1]=2 [2]=3 [3]=4 => 234
	int* firstMass;
	int* readyMass;
	int escape = 0;
	int temporary;
	printf("Press ESC to stop\n");
	while (escape != 27)
	{
		num1 = 0;
		asciiCheck = 0;
		temporary = 0;
		escape = getche();
		if (escape == 27)
			break;
		firstMass = (int*)malloc(100 * sizeof(int));
		if (escape > 47 && escape < 58)
		{
			for (int i = 1; asciiCheck != 32; i++) //������� ����� � ������ [1]=2 [2]=3 [3]=4;
			{
				if (temporary < 1)
					asciiCheck = escape;
				else
					asciiCheck = getche();
				if (asciiCheck == 32)
					continue;
				if (asciiCheck >= 48 && asciiCheck <= 57)
				{
					asciiCheck -= 48;
				}
				firstMass[i] = asciiCheck;
				firstMass[i + 1] = 666;
				temporary = temporary + 1;
			}
			int n = 1;
			for (int i = 1; firstMass[i] != 666; i++)
			{
				if (firstMass[i] != 666)
					n = n * 10;
			}
			n = n / 10; // ���������� ���������� ��������� 
			for (int i = 1; firstMass[i] != 666; i++)
			{
				num1 = num1 + (firstMass[i] * n);
				n = n / 10;
			} // ������� �����
			readyMass = (int*)malloc(100 * sizeof(int)); //������� �����
			for (int i = 1; i < 2; i++)
			{
				readyMass[i] = num1 * num1;
				printf("%d\n", readyMass[i]);//����� �����
			}
			free(firstMass);
			free(readyMass);
		}
	}
	system("pause");
}