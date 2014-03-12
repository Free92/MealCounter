#ifndef MEAL_H
#define MEAL_H
#include <iostream>
#include <vector>

using namespace std;

class Meal{
public:
	Meal();
	Meal(string name, int fat, int carb, int protein);
	Meal(Meal && rhs);
	Meal(const Meal & rhs);
	Meal & operator=(const Meal & rhs);
	Meal & operator=(Meal && rhs);
	void print();
	const int getFat();
	const int getCarb();
	const int getProtein();
	const int getCalorie();
	const string getName();
	void setFat(int get);
	void setCarb(int get);
	void setProtein(int get);
	void setName(string get);
	void setCalorie();
private:
	int fat, carb, protein, calorie;
	string name;
};

#include "meal.hpp"

#endif
