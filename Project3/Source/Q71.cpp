#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<string.h>
#include<stdio.h>
#include"Q71.h"

const char *dayofweek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
enum ADDITION{MONTH=1, YEAR=1900};

date get_date_from_system() {
	time_t raw_time;
	struct tm *time_info;
	
	time(&raw_time);
	time_info = localtime(&raw_time);
	
	if (time_info) {
		date result;
		result.dow = (uchar)time_info->tm_wday;
		result.dd = (uchar) time_info->tm_mday;
		result.mm = (uchar) (time_info->tm_mon + ADDITION::MONTH);
		result.yyyy = time_info->tm_year + ADDITION::YEAR;
		return result;
	}
	else
		return date(0, 0, 0, 0);
}

void print_date(date instance, const char *format) {
	if (strcmp(format, REQUIRE_FORMAT_1) == 0)
		printf(PRINT_FORMAT_1, dayofweek[instance.dow], instance.dd, instance.mm, instance.yyyy);
	else
		if (strcmp(format, REQUIRE_FORMAT_2) == 0)
			printf(PRINT_FORMAT_2, instance.dd, instance.mm, instance.yyyy);
		else
			if (strcmp(format, REQUIRE_FORMAT_3) == 0)
				printf(PRINT_FORMAT_3, instance.mm, instance.dd, instance.yyyy);
			else
				if (strcmp(format, REQUIRE_FORMAT_4) == 0) {
					printf(PRINT_FORMAT_4, dayofweek[instance.dow], instance.dd, instance.mm, (instance.yyyy % 100));     //yy in question
				}
}

	