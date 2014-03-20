#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "meal.h"

using namespace std;

const int NUMCATEGORY = 10;
const char FILENAME[] = "./Resources/Foodlist.csv";
const string FOODCATEGORY[] = {"Lighter Side","Warm Ups","Fit Salads","Muscle Maker Wraps","Sandwiches","Vegetarian","Power Pasta","Guiltless Entrees","Low Carb Solutions","Extras"};


struct mealList{
public:
	mealList(string name){
		this->name = name;
	}
	string name;
	vector<Meal> meals;
};

int populate(vector<mealList> & list, ifstream & fin);
void parser(Meal meal, string toParse);
void menu(vector<mealList> & list);
void catNames(vector<mealList> & list);
void addFood(vector<mealList> & list);
void editFood();
void deleteFood();
void addData();
void editData();
void deleteData();

int main(void){
	vector<mealList> list;
	for(int i = 0; i < NUMCATEGORY; ++i)
		list.push_back(FOODCATEGORY[i]);	

	ifstream fin(FILENAME);
	if(fin.fail()){
		cout << "ERROR OPENING FILE!" << endl;
		return 1;
	}

	if(populate(list, fin) == 1)
		return 1;
	menu(list);

	return 0;
}

int populate(vector<mealList> & list, ifstream & fin){
	string tempLine;
	getline(fin, tempLine);
	int catIndex = 1;

	if(tempLine != FOODCATEGORY[0]){
		cout << "ERROR: Incorrect File Format!" << endl;
		return 1;
	}
	auto itr = list.begin();
	while(getline(fin, tempLine)){
		if(tempLine == FOODCATEGORY[catIndex]){
			++catIndex;
			++itr;
			getline(fin, tempLine);
		}

		stringstream ss(tempLine);
		string name, tempFat, tempCarb, tempProtein;
		int fat, carb, protein;
		getline(ss,name,',');
		getline(ss,tempFat,',');
		getline(ss,tempCarb,',');
		getline(ss,tempProtein,',');
		fat = atoi(tempFat.c_str());
		carb = atoi(tempCarb.c_str());
		protein = atoi(tempProtein.c_str());
		Meal testMeal(name,fat,carb,protein);
		itr->meals.push_back(testMeal);
	}
	/*for(itr = list.begin(); itr != list.end(); ++itr){
		cout << itr->name << endl;
		for(auto itr2 = itr->meals.begin(); itr2 != itr->meals.end(); ++itr2){
			itr2->print();
		}
	}*/
	return 0;
}


void menu(vector<mealList> & list){
	string temp;
	int input;
	cout << "What is the name of today's meal plan?" << endl;
	cin >> temp;
	do{
		cout << "1. Add food to today's meal plan\n2. Edit food from today's meal"
		     << "\n3. Delete food from today's meal\n4. Add food data\n5. Edit food data"
		     << "\n6. Delete food data\n7. Exit" << endl;
		cin >> input;
		switch(input){
		case 1:
			addFood(list);
			break;
		case 2:
			editFood();
			break;
		case 3:
			deleteFood();
			break;
		case 4:
			addData();
			break;
		case 5:
			editData();
			break;
		case 6:
			deleteData();
			break;
		case 7:
			break;
		default:
			cout << "Invalid input!" << endl;
		}
	} while(input != 7);
}

void catNames(vector<mealList> & list){
	for(auto itr = list.begin(); itr != list.end(); ++itr){
		cout << itr->name << endl;
	}
}

void addFood(vector<mealList> & list){
	int menuChoice = 0;
	string mealPlanChoices = "Which meal plan is this for?\n1. Mass\n2. Maintain\n3. Lean\n4. Cancel";
	string mealChoices = "What meal of the day is it?\n1. Meal 1\n2. Meal 2\n3. Meal 3\n4. Cancel";

	cout << mealPlanChoices << endl;
	cin >> menuChoice;
	switch(menuChoice){
	case 1:
		cout << mealChoices << endl;
		cin >> menuChoice;
		switch(menuChoice){
		case 1: 
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			menu(list);
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		break;
	case 2:
		cout << mealChoices << endl;
		break;
	case 3:
		cout << mealChoices << endl;
		break;
	case 4:
		menu(list);
		break;
	default:
		cout << "Invalid input!" << endl;
		addFood(list);
	}
}

void editFood(){
	cout << "Do something here!" << endl;
}

void deleteFood(){
	cout << "Do something here!" << endl;
}

void addData(){
	cout << "Do something here!" << endl;
}

void editData(){
	cout << "Do something here!" << endl;
}

void deleteData(){
	cout << "Do something here!" << endl;
}
