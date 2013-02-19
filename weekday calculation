// From 1900.1.1

int normalYearDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapYearDay[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year)
{
    return !(year % 4) && (year % 100) || !(year % 400);
}

int calcDayCount(int year, int month, int day)
{
    int totalDayCount = 0;

    for (int i = 1900; i < year; i++)
    {
        if (isLeapYear(i))
            totalDayCount += 366;
        else
            totalDayCount += 365;
    }

    for (int i = 1; i < month; i++)
    {
        if (isLeapYear(year))
            totalDayCount += leapYearDay[i - 1];
        else
            totalDayCount += normalYearDay[i - 1];
    }

    totalDayCount += day - 1;

    return totalDayCount % 7;
}
