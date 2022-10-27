#pragma once
#include <string>
#include <iostream>
#include "room.h"
#include "traveler.h"
using namespace std;

/*
* 住宿关系类
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
* 构造参数，用于关联哪一个旅客住宿哪一个房间
*/
Lodging::Lodging(Room room, Traveler traveler)
{
	this->room = room;
	this->traveler = traveler;
	// TODO 构造时，同时写入到内存记录对应的房间信息
	if (!room.change_room_used_state()) {
		cout << "房间已入住\n";
	}
}


/*
* 计算花费
*/
float Lodging::getTotalCost() {
	this->total_price = this->room.getPrice() * this->days;
	return this->total_price;
}