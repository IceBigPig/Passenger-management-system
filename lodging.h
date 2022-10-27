#pragma once
#include <string>
#include <iostream>
#include "room.h"
#include "traveler.h"
using namespace std;

/*
* ס�޹�ϵ��
*/
class Lodging
{
public:
	Lodging() {};
	Lodging(Room room, Traveler traveler);
	float getTotalCost();
	Room room;
	Traveler traveler;
	int days;
	float total_price;
};

/*
* ������������ڹ�����һ���ÿ�ס����һ������
*/
Lodging::Lodging(Room room, Traveler traveler)
{
	this->room = room;
	this->traveler = traveler;
	// TODO ����ʱ��ͬʱд�뵽�ڴ��¼��Ӧ�ķ�����Ϣ
	if (!room.change_room_used_state()) {
		cout << "��������ס\n";
	}
}


/*
* ���㻨��
*/
float Lodging::getTotalCost() {
	this->total_price = this->room.getPrice() * this->days;
	return this->total_price;
}