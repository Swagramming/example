#include <time.h>
#include <stdio.h>

int main()
{
    time_t rawtime;
    struct tm* timeinfo, *timeinfo2;
    int year, month ,day;
    const char* weekday[] = { "Sunday", "Monday",
                              "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday"};

    printf("Year: "); scanf("%d", &year);
    printf("Month: "); scanf("%d", &month);
    printf("Day: "); scanf("%d", &day);

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900; /* Godine su relativne 1900-toj */
    timeinfo->tm_mon = month - 1; /* January = 0 */
    timeinfo->tm_mday = day;
    mktime(timeinfo);
    printf("Weekday: %s\n", weekday[timeinfo->tm_wday]);

    timeinfo2 = localtime(&rawtime);
    mktime(timeinfo2);
    printf("Today's weekday: %s\n", weekday[timeinfo2->tm_wday]);
}
