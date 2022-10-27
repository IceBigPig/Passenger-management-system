#pragma once
#include <string>
using namespace std;

/*
* ������
*/
class Room
{
public:
	Room() {};
	Room(string room_id, int capactiy, float price ,bool state);
	~Room();
	bool change_room_used_state();
	bool change_room_empty_state();
	void setPrice(float price);
	float getPrice();
	string room_id;
	int capacity;
	float price;
	bool state;
};

Room::Room(string room_id, int capactiy, float price, bool state)
{
	this->room_id = room_id;
	this->capacity = capactiy;
	this->price = price;
	this->state = state;
}

Room::~Room()
{
}

/*
* �ı䷿���״̬Ϊ��ʹ��
*/
bool Room::change_room_used_state() {
	if (this->state) {
		this->state = false;
		return true;
	}
	return false;
}

/*
* �ı䷿���״̬Ϊ����
*/
bool Room::change_room_empty_state() {
	if (!this->state) {
		this->state = true;
		return true;
	}
	return false;
}

float Room::getPrice() {
	return this->price;
}

void Room::setPrice(float price) {
	this->price = price;
}