#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "clsString.h"
using namespace std;

class clsDate
{
private:
	
	short _Year = 1;
	short _Month = 1;
	short _Day = 1900;


public:
	enum EnReturn { Before = -1, Euals = 0, After = 1 };

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{

		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}

	clsDate(short Day, short Month, short Year)
	{

		_Day = Day;
		_Month = Month;
		_Year = Year;

	}

	clsDate(short DateOrderInYear, short Year)
	{
		//This will construct a date by date order in year
		clsDate Date1 = CalcyearToDays(DateOrderInYear, Year);
		_Day = Date1.Day;
		_Month = Date1.Month;
		_Year = Date1.Year;
	}

	void SetDay(short Day) {
		_Day = Day;
	}

	short GetDay() {
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) {
		_Month = Month;
	}

	short GetMonth() {
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;


	void SetYear(short Year) {
		_Year = Year;
	}

	short GetYear() {
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	void Print()
	{
		cout << DateToString() << endl;
	}

	static string GetSystemDateTimeToString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short day, month, year, hour, minute, Secound;

		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;
		hour = now->tm_hour;
		minute = now->tm_min;
		Secound = now->tm_sec;

		return to_string((day)) + "/" + to_string((month)) + "/" + to_string((year))
			+ " - " + to_string((hour)) + " : " + to_string((minute)) + " : "
			+ to_string((Secound));
	}

	static bool isLeapYear(short year)
	{
		return (year % 400 == 0) ? true : (year % 4 == 0 && year % 100 != 0) ? true : false;
	}
	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static short NumberOfDaysinyear(short year)
	{
		return isLeapYear(year) ? 366 : 365;
	}
	short NumberOfDaysinyear()
	{
		return NumberOfDaysinyear(_Year);
	}


	static short NumberOfHoursInyear(short year)
	{
		return 	NumberOfDaysinyear(year) * 24;
	}
	short NumberOfHoursInyear( )
	{
		return 	NumberOfHoursInyear(_Year);
	}

	static int NumberOfMinInyear(short year)
	{
		return 	NumberOfHoursInyear(year) * 60;
	}
	int NumberOfMinInyear()
	{
		return NumberOfMinInyear(_Year);
	}

	static int NumberOfSecoundInYear(short year)
	{
		return NumberOfMinInyear(year) * 60;

	}
	int NumberOfSecoundInYear()
	{
		return NumberOfSecoundInYear(_Year);
	}

	static short NumberOfDaysinMonth(short year, short Month)
	{
		if (Month < 1 || Month >12)
			return 0;

		int NumberOfDays[12] = { 31,28,31,30,31,30, 31,31,30,31,30,31 };

		return (Month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
	}
	short NumberOfDaysinMonth()
	{
		return NumberOfDaysinMonth(_Year, _Month);
	}

	static short NumberOfHoursInMonth(short year, short Month)
	{
		return NumberOfDaysinMonth(year, Month) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Year,_Month);
	}

	static int NumberOfMinutesInMonth(short year, short Month)
	{
		return NumberOfHoursInMonth(year, Month) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Year, _Month);
	}

	static int NumberOfSecoundsInMonth(short year, short Month)
	{
		return NumberOfMinutesInMonth(year, Month) * 60;
	}
	int NumberOfSecoundsInMonth()
	{
		return NumberOfSecoundsInMonth(_Year,_Month);
	}

	static int DayOfWeekOrder(short year, short Month, short Day)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = year - a;
		m = Month + 12 * a - 2;	

		return  (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
	}
	int DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Year, _Month, _Day);
	}

	static int DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date._Year, Date._Month, Date._Day);
	}
	

	static string  dayShortName(short DaysOfWeeks)
	{
		string ArrDays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday" };
		return ArrDays[DaysOfWeeks];
	}
	string  dayShortName()
	{
		return dayShortName(DayOfWeekOrder());
	}


	static string MonthShortName(short Month)
	{
		string ArrMonths[12] = { "January","February","March","April","May","June","July","August","Sep","Oct","Nov","Dec" };

		return ArrMonths[Month - 1];

	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

    static void PrintMonthOfYear(short year, short Month)
	{
		int Current = DayOfWeekOrder(year, Month, 1);

		int NumberOfDayes = NumberOfDaysinMonth(year, Month);

		cout << "\n------------------------" << MonthShortName(Month) << "------------------------\n\n";
		printf("Sun Mon Tue Wed Thu Fri Sat\n");

		int i;
		for (i = 0; i < Current; i++)
		{
			printf("    ");
		}

		for (int j = 1; j <= NumberOfDayes; j++)
		{
			printf("%3d ", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		cout << "\n---------------------------------------------------\n";
	}
	void PrintMonthOfYear()
	{
		return PrintMonthOfYear(_Year, _Month);
	} 

   static void PrintYear(short year)
	{
		printf("\n-------------------------------------\n\n");
		printf("           Clander - %d\n", year);
		printf("\n-------------------------------------\n\n");

		for (short i = 1; i <= 12; i++)
		{

			PrintMonthOfYear(year, i);
		}
	}
	void PrintYear()
	{
		return PrintYear(_Year);
	}

	static short ClacDaysOfyear(short year, short Month, short Day)
	{
		int Sum = 0;
		for (int i = 1; i < Month; i++)
		{
			Sum += NumberOfDaysinMonth(year, i);
		}
		Sum += Day;
		return Sum;
	}
	short ClacDaysOfyear()
	{
		return ClacDaysOfyear(_Year,_Month,_Day);
	}

	static clsDate CalcyearToDays(short DateDayinOrder, short year)
	{
		clsDate Date;
		short RemaingDays = DateDayinOrder;
		short MonthDays = 0;

		Date._Year = year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysinMonth(year, Date._Month);

			if (RemaingDays > MonthDays)
			{
				RemaingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemaingDays;
				break;
			}


		}

		return Date;

	}
	
	static clsDate DateAddDays(short Days, clsDate Date)
	{

		short RemaingDays = Days + ClacDaysOfyear(Date._Year, Date._Month, Date._Day);
		short MonthDays = 0;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysinMonth(Date._Year, Date._Month);

			if (RemaingDays > MonthDays)
			{

				RemaingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{

				Date._Day = RemaingDays;
				break;
			}
		}

		return Date;

	}
	clsDate DateAddDays(short Days)
	{
		return DateAddDays(Days,*this);
	}

	static bool CheckifDateLess(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true
			: ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month) ? true
				: (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false) : false);
	}
	bool CheckifDateLess(clsDate Date2)
	{
		return CheckifDateLess(*this, Date2);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;
		Temp._Year = Date1._Year;
		Temp._Month = Date1._Month;
		Temp._Day = Date1._Day;

		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;

		Date2._Year = Temp._Year;
		Date2._Month = Temp._Month;
		Date2._Day = Temp._Day;
	}

	static bool IsDateEquals(clsDate Date1, clsDate Date2)
	{
	return (Date1._Year == Date2._Year) && (Date1._Month == Date2._Month) && (Date1._Day == Date2._Day);
	}

	bool IsDateEquals(clsDate Date2)
	{
		return IsDateEquals(*this, Date2);
	}

	static bool CheckifDateBefor(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true
			: ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month) ? true
				: (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false) : false);
	}
	bool CheckifDateBefor(clsDate Date2)
	{
		return CheckifDateBefor(*this,Date2);
	}

	static bool CheckifDateAfter(clsDate Date1, clsDate Date2)
	{
		return (!CheckifDateBefor(Date1, Date2) && !IsDateEquals(Date1, Date2));
	}
	bool CheckifDateAfter(clsDate Date2)
	{
		return CheckifDateAfter(*this,Date2);
	}


	static bool IsLastDayInMonth(clsDate Date1)
	{
		return (Date1._Day == NumberOfDaysinMonth(Date1._Year, Date1._Month));
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}
	
	static bool IsLastMonthInYear(clsDate Date)
	{
		if (Date._Month < 1 || Date._Month >12)
			return 0;
		return (Date._Month == 12);
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(*this);
	}

	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date))
			{
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;

			}
		}
		else
		{
			Date._Day++;
		}


		return Date;
	}
	clsDate AddOneDay()
	{
		return AddOneDay(*this);
	}

	static int DifDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (CheckifDateLess(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);

		}


		return IncludeEndDay ? ++Days : Days;
	}
	int DifDays(clsDate Date2)
	{
		return DifDays(*this,Date2,false);
	}

	static clsDate GetSystemDate()
	{
		clsDate Date;
		time_t Time = time(0);
		tm* now = localtime(&Time);

		Date._Year = now->tm_year + 1900;
		Date._Month = now->tm_mon + 1;
		Date._Day = now->tm_mday;

		return Date;
	}

	static int DiffrenceDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		int SwapValue = 1;
		if (!CheckifDateLess(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapValue = -1;
		}


		while (CheckifDateLess(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}


		return IncludeEndDay ? ++Days * SwapValue : Days * SwapValue;
	}
	int DiffrenceDays(clsDate Date2)
	{
		return DiffrenceDays(*this, Date2, false);
	}

	static clsDate IncreaseDateByXDay(clsDate &Date, short Days)
	{
		for (int i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDay(short Days)
	{
		 IncreaseDateByXDay(*this, Days);
	}

	static clsDate IncreaseDateByOneWeek(clsDate &Date)
	{
		for (int i = 1; i <= 7; i++)
		{

			Date = AddOneDay(Date);

		}
		return Date;
	}
	void IncreaseDateByOneWeek()
	{
		 IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeek(clsDate& Date, short Weeks)
	{
		for (int i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);

		}
		return Date;
	}
	void IncreaseDateByXWeek(short Weeks)
	{
		 IncreaseDateByXWeek(*this,Weeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysinMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;

		}
		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		 IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonth(clsDate& Date, short Month)
	{
		for (int i = 1; i <= Month; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonth(short Month)
	{
		 IncreaseDateByXMonth(*this,Month);
	}


    static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date._Year++;
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		 IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYear(clsDate& Date, short Year)
	{
		for (int i = 1; i <= Year; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXYear(short Year)
	{
		 IncreaseDateByXYear(*this,Year);
	}

	static clsDate IncreaseDateByXYearFaster(clsDate& Date, short Year)
	{
		Date._Year += Year;
		return Date;
	}
	void IncreaseDateByXYearFaster(short Year)
	{
		 IncreaseDateByXYearFaster(*this,Year);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		Date._Year += 10;
		return Date;
	}
	void IncreaseDateByOneDecade()
	{
		 IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecade(clsDate& Date, short Decade)
	{
		for (int i = 1; i <= Decade; i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}
		return Date;
	}
	void IncreaseDateByXDecade(short Decade)
	{
		 IncreaseDateByXDecade(*this,Decade);
	}

	static clsDate IncreaseDateByXDecadeFaster(clsDate& Date, short Decade)
	{
		Date._Year += Decade * 10;
		return Date;
	}
	void IncreaseDateByXDecadeFaster(short Decade)
	{
		 IncreaseDateByXDecadeFaster(*this, Decade);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		Date._Year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury()
	{
		 IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		Date._Year += 1000;
		return Date;
	}
	void IncreaseDateByOneMillennium()
	{
		 IncreaseDateByOneMillennium(*this);
	}

	static bool isFirstDayInMonth(clsDate& Date)
	{
		return (Date._Day == 1);
	}
	static bool isFirstMonthInYear(clsDate& Date)
	{
		if (Date._Month < 1 || Date._Month >12)
			return 0;
		return (Date._Month == 1);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{

		if (isFirstDayInMonth(Date))
		{
			if (isFirstMonthInYear(Date))
			{
				Date._Year--;
				Date._Day = 31;
				Date._Month = 12;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysinMonth(Date._Year, Date._Month);
			}
		}
		else
		{
			Date._Day--;
		}
		return Date;
	}
	clsDate DecreaseDateByOneDay()
	{
		return DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate& Date, short Days)
	{
		for (int i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXDays(short Days)
	{
		return DecreaseDateByXDays(*this,Days);
	}


	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByOneWeek()
	{
		return DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate& Date, short Weeks)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXWeeks(short Weeks)
	{
		return DecreaseDateByXWeeks(*this,Weeks);
	}


	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
		{
			Date._Month--;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysinMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;

		}
		return Date;
	}
	clsDate DecreaseDateByOneMonth()
	{
		return DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate& Date, short Months)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXMonths(short Months)
	{
		return DecreaseDateByXMonths(*this,Months);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date._Year--;
		return Date;
	}
	clsDate DecreaseDateByOneYear()
	{
		return DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate& Date, short Years)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXYears(short Years)
	{
		return DecreaseDateByXYears(*this,Years);
	}


	static clsDate DecreaseDateByXYearsFaster(clsDate& Date, short Years)
	{
		Date._Year -= Years;
		return Date;
	}
	clsDate DecreaseDateByXYearsFaster(short Years)
	{
		return DecreaseDateByXYearsFaster(*this,Years);
	}


	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		Date._Year -= 10;
		return Date;
	}
	clsDate DecreaseDateByOneDecade()
	{
		return DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate& Date, short Decads)
	{
		for (short i = 1; i <= Decads; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXDecades(short Decads)
	{
		return DecreaseDateByXDecades(*this,Decads);
	}

	static clsDate DecreaseDateByXDecadesFaster(clsDate& Date, short Decads)
	{
		Date._Year -= Decads * 10;
		return Date;
	}
	clsDate DecreaseDateByXDecadesFaster(short Decads)
	{
		return DecreaseDateByXDecadesFaster(*this,Decads);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		Date._Year -= 100;
		return Date;
	}
	clsDate DecreaseDateByOneCentury()
	{
		return DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		Date._Year -= 1000;
		return Date;
	}
	clsDate DecreaseDateByOneMillennium()
	{
		return DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date);
		return(DayIndex == 5) || (DayIndex == 6);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	static int DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	static int DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate CalcMonths;
		CalcMonths._Day = NumberOfDaysinMonth(Date._Year, Date._Month);
		CalcMonths._Month = Date._Month;
		CalcMonths._Year = Date._Year;

		return DifDays(Date, CalcMonths, true);
	}

	static int DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate CalcMonths;
		CalcMonths._Day = 31;
		CalcMonths._Month = 12;
		CalcMonths._Year = Date._Year;
		return DifDays(Date, CalcMonths, true);
	}

	static short GetActucalVacationDays(clsDate VacationFrom, clsDate VacationTo)
	{
		short DaysCount = 0;
		while (CheckifDateLess(VacationFrom, VacationTo))
		{
			if (IsBusinessDay(VacationFrom))
			{
				DaysCount++;
			}
			VacationFrom = AddOneDay(VacationFrom);
		}
		return DaysCount;
	}
	short GetActucalVacationDays(clsDate VacationTo)
	{
		return GetActucalVacationDays(*this, VacationTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate VacationFrom, short VacationDays)
	{
		short WeekendCounter = 0;

		while (IsWeekEnd(VacationFrom))
		{
			VacationFrom = AddOneDay(VacationFrom);
		}

		for (short i = 1; i <= VacationDays + WeekendCounter; i++)
		{
			if (IsWeekEnd(VacationFrom))
			{
				WeekendCounter++;
			}
			VacationFrom = AddOneDay(VacationFrom);
		}
		while (IsWeekEnd(VacationFrom))
		{
			VacationFrom = AddOneDay(VacationFrom);
		}
		return VacationFrom;
	}
	clsDate CalculateVacationReturnDate(short VacationDays)
	{
		return CalculateVacationReturnDate(*this, VacationDays);
	}

	static EnReturn CompareDates(clsDate Date1, clsDate Date2)
	{
		return IsDateEquals(Date1, Date2) ? EnReturn::Euals : CheckifDateAfter(Date1, Date2) ? EnReturn::After : EnReturn::Before;
		//الطريقه التانيه 
		if (IsDateEquals(Date1, Date2))
			return EnReturn::Euals;

		if (CheckifDateAfter(Date1, Date2))
			return EnReturn::After;

		return EnReturn::Before;
	}
	EnReturn CompareDates(clsDate Date2)
	{
		return CompareDates(*this,Date2);
	}

	static bool isPeriodOverlap(clsDate Period, clsDate Period2)
	{
		if (CompareDates(Period2, Period) == EnReturn::Before 
			|| CompareDates(Period2, Period) == EnReturn::After)
			return false;
		else
			return true;
	}
	bool isPeriodOverlap(clsDate Period2)
	{
		return isPeriodOverlap(*this,Period2);
	}

	static int PeriodLengthInDays(clsDate Period, bool IncludeEndDay = false)
	{
		return DifDays(Period, Period, IncludeEndDay);
	}

	static bool isDataWithinPeriod(clsDate Period)
	{
		return  !(CompareDates(Period, Period) == EnReturn::Before ||
			CompareDates(Period, Period) == EnReturn::After);
	}


	static bool isValidateDate(clsDate Date)
	{
		if (Date._Day < 1 || Date._Day > 31)
			return false;
		if (isLeapYear(Date._Year) && Date._Day >= 30 && (Date._Month == 2))
			return false;
		if (!isLeapYear(Date._Year) && (Date._Day >= 29) && (Date._Month == 2))
			return false;

		if (Date._Month < 1 || Date._Month >12)
			return false;

		if ((Date._Month == 4 || Date._Month == 6 || Date._Month == 9 || Date._Month == 11) && (Date._Day >= 31))
			return false;
		short DaysInMonth = NumberOfDaysinMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysinMonth(Date._Year, Date._Month));
		return false;

		return true;
	}
	bool isValidateDate()
	{
		return isValidateDate(*this);
	}

	static clsDate StringToDate(string S1)
	{
		clsDate Date;
		vector<string>Split;
		Split = clsString::Split(S1, "/");

		if (Split.size() == 3)
		{
			Date._Day = stoi(Split[0]);
			Date._Month = stoi(Split[1]);
			Date._Year = stoi(Split[2]);
		}
		return Date;
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}


	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDatastring = "";
		FormattedDatastring = clsString::ReplaceWord(DateFormat, "dd", to_string(Date._Day));
		FormattedDatastring = clsString::ReplaceWord(FormattedDatastring, "mm", to_string(Date._Month));
		FormattedDatastring = clsString::ReplaceWord(FormattedDatastring, "yyyy", to_string(Date._Year));

		return FormattedDatastring;
	}


};