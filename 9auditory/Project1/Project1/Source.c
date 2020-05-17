#include <stdio.h>
#include <Windows.h>
#include <time.h>

void month(struct tm time_date)
{
    if (time_date.tm_mon == 0)
        printf("Current month is: January");
    else if (time_date.tm_mon == 1)
        printf("Current month is: February");
    else if (time_date.tm_mon == 2)
        printf("Current month is: March");
    else if (time_date.tm_mon == 3)
        printf("Current month is: April");
    else if (time_date.tm_mon == 4)
        printf("Current month is: May");
    else if (time_date.tm_mon == 5)
        printf("Current month is: June");
    else if (time_date.tm_mon == 6)
        printf("Current month is: July");
    else if (time_date.tm_mon == 7)
        printf("Current month is: August");
    else if (time_date.tm_mon == 8)
        printf("Current month is: September");
    else if (time_date.tm_mon == 9)
        printf("Current month is: October");
    else if (time_date.tm_mon == 10)
        printf("Current month is: November");
    else if (time_date.tm_mon == 11)
        printf("Current month is: December");
}

void wday(struct tm time_date)
{
    if (time_date.tm_wday == 0)
        printf("Current wday is: Monday\n");
    else if (time_date.tm_wday == 1)
        printf("Current wday is: Tuesday\n");
    else if (time_date.tm_wday == 2)
        printf("Current wday is: Wednesday\n");
    else if (time_date.tm_wday == 3)
        printf("Current wday is: Thursday\n");
    else if (time_date.tm_wday == 4)
        printf("Current wday is: Friday\n");
    else if (time_date.tm_wday == 5)
        printf("Current wday is: Saturday\n");
    else if (time_date.tm_wday == 6)
        printf("Current wday is: Sunday\n");
}

int main()
{
	LPWSTR lpBuffer[50];
	DWORD pcbBuffer=50;
	DWORD nSize=50;
	GetUserNameW(lpBuffer, &pcbBuffer);
	wprintf(L"Username is: %s\n", lpBuffer);
	GetComputerNameW(lpBuffer, &nSize);
	wprintf(L"Computer Name is: %s\n", lpBuffer);
	struct tm currenttime;
	time_t closecurtime;
	time(&closecurtime);
	localtime_s(&currenttime, &closecurtime);
	printf("Current year: %d\n", currenttime.tm_year+1900);
    month(currenttime);
    printf("\n");
    wday(currenttime);
}