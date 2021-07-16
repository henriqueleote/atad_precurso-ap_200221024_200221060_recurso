#pragma once

typedef struct date {
	int day, month, year;
} Date;

/**
 * @brief Create a Date object
 * 
 * @param day [in] day of month.
 * @param month [in] month, where january = 1
 * @param year [in] year
 * @return Date object initialized with arguments. 
 */
Date createDate(int day, int month, int year);

int dateCompare(Date d1, Date d2);
