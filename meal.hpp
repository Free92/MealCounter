#include <iostream>
#include "meal.h"

Meal::Meal(){
	name = "";
	fat = 0;
	carb = 0;
	protein = 0;
}

Meal::Meal(string name, int fat, int carb, int protein){
	this->name = name;
	this->fat = fat;
	this->carb = carb;
	this->protein = protein;
	setCalorie();
}

Meal::Meal(const Meal & rhs): name(rhs.name),
			      fat(rhs.fat),
			      carb(rhs.carb),
			      protein(rhs.protein){
	setCalorie();	
}

Meal::Meal(Meal && rhs):      name(rhs.name),
			      fat(rhs.fat),
			      carb(rhs.carb),
			      protein(rhs.protein){
	setCalorie();
}

Meal & Meal::operator=(const Meal & rhs){
	name = rhs.name;
	fat = rhs.fat;
	carb = rhs.carb;
	protein = rhs.protein;
	calorie = rhs.calorie;
	return *this;
}
	
Meal & Meal::operator=(Meal && rhs){
	name = rhs.name;
	fat = rhs.fat;
	carb = rhs.carb;
	protein = rhs.protein;
	calorie = rhs.calorie;
	return *this;
}

void Meal::print(){
	cout << getName() << " " << getFat() << " " << getCarb() << " " << getProtein() << endl;
}

const int Meal::getFat(){
	return fat;
}

const int Meal::getCarb(){
	return carb;
}

const int Meal::getProtein(){
	return protein;
}

const int Meal::getCalorie(){
	return calorie;
}

const string Meal::getName(){
	return name;
}

void Meal::setFat(int get){
	fat = get;
}

void Meal::setCarb(int get){
	carb = get;
}

void Meal::setProtein(int get){
	protein = get;
}

void Meal::setName(string get){
	name = get;
}

void Meal::setCalorie(){
	calorie = (getFat() * 9) + (getCarb() * 4) + (getProtein() * 4);
}
