#include <iostream>
using namespace std;

class PoolRent
{
public:

	int Rent_Pool_For_1_Hour()
	{
		return 50;
	}
	int Rent_Pool_For_half_day()
	{
		return 100;
	}
	int Rent_Pool_For_all_day()
	{
		return 200;
	}
	
};

class Bar
{
public:

	int Ordering_beverages(int age, string sex, bool need_for_alcohol)
	{

		if (need_for_alcohol == true)
		{
			if (age >= 18)
			{
				if (sex == "woman")
				{
					return 80;
				}
				else
				{
					return 100;
				}
			}
			else
			{
				return 40;
			}
		}
		else
		{
			return 40;
		}

	}	

};

class Restauran
{
public:

	int Dinner_in_restaurant(int count_people, bool need_for_alcohol)
	{
		if (need_for_alcohol == true)
		{
			return 40 * count_people + 50;
		}
		else
		{
			return 40 * count_people;
		}
	}

	int Breakfast_in_restaurant(int count_people)
	{
	
		return 25 * count_people;
		
	}

	int Lunch_in_restaurant(int count_people)
	{

		return 60 * count_people;

	}

	
};

class Billiard
{
public:

	int Rent_Billiard_For_1_Hour(int count_people, bool need_for_alcohol)
	{
		if (need_for_alcohol == true)
		{
			return 10 * count_people+20;
		}
		else
		{
			return 10 * count_people;
		}
	}
	int Rent_Billiard_For_2_Hour(int count_people,bool need_for_alcohol)
	{
		if (need_for_alcohol == true)
		{
			return 20 * count_people+20;
		}
		else
		{
		   return 20 * count_people;
		}

	}
	int Rent_Billiard_For_3_Hour(int count_people, bool need_for_alcohol)
	{
		if (need_for_alcohol == true)
		{
			return 30 * count_people+20;
		}
		else
		{
			return 30 * count_people;
		}
	}

};

class Massage
{
public:

	int Rent_Massage_For_1_Hour(int age, string sex)
	{
		if (age < 18)
		{
			if (sex == "woman")
			{
				return 70;
			}
			else
			{
				return 90;
			}
		}
		else
		{
			if (sex == "woman")
			{
				return 100;
			}
			else
			{
				return 110;
			}
		}
	}
	
	int Rent_Massage_For_2_Hour(int age, string sex)
	{
		if (age < 18)
		{
			if (sex == "woman")
			{
				return 90;
			}
			else
			{
				return 120;
			}
		}
		else
		{
			if (sex == "woman")
			{
				return 120;
			}
			else
			{
				return 130;
			}
		}
	}


	

};

class ObarivResort
{
private:
	PoolRent  poolRent;
	Bar bar;
	Restauran restauran;
	Billiard billiard;
	Massage  massage;

public:

	int One_hour_pleasure(int count_people, int age, bool need_for_alcohol,string sex)
	{
		int BarPrice = bar.Ordering_beverages(age,sex, need_for_alcohol);
		int BilliardPrice = billiard.Rent_Billiard_For_1_Hour(count_people,need_for_alcohol);

		return  BarPrice + BilliardPrice;
	}
	int One_evening_pleasure(int count_people, int age, bool need_for_alcohol, string sex)
	{
		int BarPrice = bar.Ordering_beverages(age, sex, need_for_alcohol);
		int RestauranPrice = restauran.Dinner_in_restaurant(count_people,need_for_alcohol);
		int MassagePrice = massage.Rent_Massage_For_2_Hour(age,sex);

		return  BarPrice + RestauranPrice + MassagePrice;
	}
	int One_night_pleasure(int count_people, int age, bool need_for_alcohol, string sex)
	{
		int BarPrice = bar.Ordering_beverages(age, sex, need_for_alcohol);
		int RestauranPrice = restauran.Lunch_in_restaurant(count_people);
		int poolPrice = poolRent.Rent_Pool_For_all_day();
		int BilliardPrice = billiard.Rent_Billiard_For_1_Hour(count_people, need_for_alcohol);

		return  BarPrice + RestauranPrice + poolPrice + BilliardPrice;
	}
	int  Holidays_pleasure(int count_people, int age, bool need_for_alcohol, string sex)
	{
		int BarPrice = bar.Ordering_beverages(age, sex, need_for_alcohol);
		int RestauranPrice=0;
		RestauranPrice += restauran.Lunch_in_restaurant(count_people);
		RestauranPrice += restauran.Breakfast_in_restaurant(count_people);
		RestauranPrice += restauran.Dinner_in_restaurant(count_people, need_for_alcohol);
		int poolPrice = poolRent.Rent_Pool_For_all_day();
		int BilliardPrice = billiard.Rent_Billiard_For_2_Hour(count_people, need_for_alcohol);
		int MassagePrice = massage.Rent_Massage_For_2_Hour(age, sex);

		return  BarPrice + RestauranPrice + poolPrice + BilliardPrice + MassagePrice;
	}
	

 };


int main()
{
	ObarivResort  obarivResort;

	int weekendRestPrice = obarivResort.One_evening_pleasure(1,10,true,"woman");
	cout << "Price: " << weekendRestPrice << endl;

	system("pause");
	return 0;
}