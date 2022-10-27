#pragma once
#include <string>
using namespace std;

/*
* ÂÃ¿ÍÀà
*/
class Traveler
{
public:
	Traveler() {};
	Traveler(string name, string id_code, string mobile, string sex);
	~Traveler();
	string name;
	string id_code;
	string mobile;
	string sex;
};

Traveler::Traveler(string name, string id_code, string mobile, string sex)
{
	this->name = name;
	this->id_code = id_code;
	this->mobile = mobile;
	this->sex = sex;
}

Traveler::~Traveler()
{
}