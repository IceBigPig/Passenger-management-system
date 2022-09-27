#include "httplib.h"
#include "iostream"
#include "include/AIGCJson.hpp"
using namespace aigc;
using namespace std;

#define CPPHTTPLIB_OPENSSL_SUPPORT

class Student
{
public:
	string Name = "ะกร๗";
	int Age = 18;

	AIGC_JSON_HELPER(Name, Age) //class-members register
	AIGC_JSON_HELPER_RENAME("name", "age")//rename class-members
};

int main() {
	// HTTP
	httplib::Server svr;

	Student person;

	string jsonStr = "";
	JsonHelper::ObjectToJson(person, jsonStr);
	cout << jsonStr << endl;

	svr.Get("/hi", [&](const httplib::Request&, httplib::Response& res) {
		res.set_content(jsonStr, "text/plain");
	});

	svr.listen("0.0.0.0", 8080);
}