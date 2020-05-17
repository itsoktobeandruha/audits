#include <Windows.h>
#include <tlhelp32.h>
#include <stdio.h>


int main()
{
	FILE* F;
	errno_t err;
	err = fopen_s(&F, "name.txt", "w");
	if (err != 0)
	{
		printf("nice try, Konstantin Andreevich\n");
		system("PAUSE");
		return 0;
	}
	HANDLE hprocsnap;
	hprocsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 process32;
	process32.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hprocsnap, &process32);
	do
	{
		wprintf(L"process name: %s\n", process32.szExeFile);
	} while (Process32Next(hprocsnap, &process32));
	system("PAUSE");
	fclose(F);
	remove("name.txt");
}