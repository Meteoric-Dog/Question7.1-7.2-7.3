#pragma once

typedef unsigned char uchar;


#define REQUIRE_FORMAT_1 "dow, dd-mm-yyyy"
#define REQUIRE_FORMAT_2 "dd/mm/yyyy"
#define REQUIRE_FORMAT_3 "mm-dd-yyyy"
#define	REQUIRE_FORMAT_4 "dow dd.mm.yy"

#define PRINT_FORMAT_1 "%s, %d-%d-%d\n"
#define PRINT_FORMAT_2 "%d/%d/%d\n"
#define PRINT_FORMAT_3 "%d-%d-%d\n"
#define PRINT_FORMAT_4 "%s %d.%d.%d\n"

struct date {
	uchar dow;
	unsigned int yyyy;
	uchar dd;
	uchar mm;
	////q71->q72a
	//unsigned int yyyy;

	date() {
		this->dow = 0;
		this->dd = 1;         //the value of day should start from 1 
		this->mm = 1;         //the value of month should start from 1
		this->yyyy = 0;
	}

	date(uchar dow, uchar dd, uchar mm, unsigned int yyyy) {
		this->dow = dow;
		this->dd = dd;
		this->mm = mm;
		this->yyyy = yyyy;
	}

	bool checkValidity() {
		if (this->dow > 6)
			return false;
		if (this->dd > 31)
			return false;
		if (this->mm > 12)
			return false;
		return true;
	}
};

date get_date_from_system();

void print_date(date instance, const char *format);
