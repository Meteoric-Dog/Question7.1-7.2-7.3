#pragma once
#include<iostream>
#include<stdio.h>
#include"Q71.h"

using namespace std;

int main() {
	date current_date = get_date_from_system();
	print_date(current_date, REQUIRE_FORMAT_1);
	print_date(current_date, REQUIRE_FORMAT_2);
	print_date(current_date, REQUIRE_FORMAT_3);
	print_date(current_date, REQUIRE_FORMAT_4);

	printf("%d\n", sizeof(date));

	system("pause");
	return 0;
}