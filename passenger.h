#pragma once
#include "iostream"
#include "include/AIGCJson.hpp"
using namespace std;
using namespace aigc;
#define CPPHTTPLIB_OPENSSL_SUPPORT

class Passenger {
public:
	Passenger() {
		this->id = "1";
		this->mobile = "2";
		this->name = "3";
	};
	Passenger(string id, string name, string mobile);
	AIGC_JSON_HELPER(id, name,mobile) //class-members register
	AIGC_JSON_HELPER_RENAME("id", "name", "mobile")//rename class-members
private:
	string id;
	string name;
	string mobile;
};

Passenger::Passenger(string id, string name, string mobile) {
	this->id = id;
	this->name = name;
	this->mobile = mobile;
}