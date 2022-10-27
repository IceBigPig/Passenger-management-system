#pragma once
#include <iostream>
#include <string>
#include "lodging.h"
#include "room.h"
#include "traveler.h"

using namespace std;

// 全局变量
Lodging loding_static[10];
Room room_static[10];
Traveler traveler_static[20];

int taverler_num;
int room_num;
int lodging_num;


int findRoomID(string room_id);

void serviceInit() {
	taverler_num = 0;
	room_num = 0;
	lodging_num = 0;
}

void addRooms() {
	Room room_temp;
	cout << "房间号：";
	cin >> room_temp.room_id;
	cout << "人数：";
	cin >> room_temp.capacity;
	cout << "价格：";
	cin >> room_temp.price;
	room_temp.state = true;
	room_static[room_num++] = room_temp;
	cout << "添加成功\n";
}

void changeRoomInfo() {
	cout << "输入要修改的房间号：";
	string room_id;
	cin >> room_id;
	int cur = findRoomID(room_id);
	cout << "修改房间号：";
	cin >> room_static[cur].room_id;
	cout << "人数：";
	cin >> room_static[cur].capacity;
	cout << "价格：";
	cin >> room_static[cur].price;
	cout << "修改成功\n";
}

int findRoomID(string room_id) {
	for (int i = 0; i < room_num; i++) {
		if (room_static[i].room_id == room_id) {
			return i;
		}
	}
	return -1;
}

Traveler addTraveler() {
	Traveler traveler_temp;
	cout << "姓名：";
	cin >> traveler_temp.name;
	cout << "性别：";
	cin >> traveler_temp.sex;
	cout << "身份证号：";
	cin >> traveler_temp.id_code;
	cout << "手机号：";
	cin >> traveler_temp.mobile;
	traveler_static[taverler_num++] = traveler_temp;
	cout << "添加成功\n";
	return traveler_temp;
}

void lodging() {
	if (room_num == 0) {
		cout << "请先创建房间!\n";
	}
	else {
		cout << "请输入房间号：";
		string room_id_temp;
		cin >> room_id_temp;
		int room_cur = findRoomID(room_id_temp);
		if (room_cur >= 0) {
			if (room_static[room_cur].state) {
				int days;
				cout << "请输入住宿时长：";
				cin >> days;
				room_static[room_cur].state = false;
				Lodging lodging_temp(room_static[room_cur], addTraveler());
				lodging_temp.days = days;
				loding_static[lodging_num++] = lodging_temp;
				cout << "办理住宿成功！\n";
			} 
			else
			{
				cout << "房间已被使用\n";
			}
		}
		else
		{
			cout << "房间不存在！\n";
		}
	}
}

Lodging getLodgingByRoomId(string room_id) {
	for (int i = 0; i < lodging_num; i++) {
		if (loding_static[i].room.room_id == room_id) {
			return loding_static[i];
		}
	}
}

void viewLodgingState() {
	cout << "住宿状态：\n\n";
	cout << "房间号\t容纳人数\t价格\t入住状态\n";
	for (int i = 0; i < room_num; i++) {
		string state_title;
		if (room_static[i].state)
			state_title = "空房间";
		else
			state_title = "已入住";
		cout << room_static[i].room_id << "\t" << room_static[i].capacity << "\t" << room_static[i].price << "\t" << state_title << endl;
	}
}

int findLodging(string room_id) {
	for (int i = 0; i < lodging_num; i++) {
		if (loding_static[i].room.room_id == room_id && loding_static[i].room.state == false) {
			return i;
		}
	}
	return -1;
}

void settlement() {
	cout << "请输入要结算的房间：";
	string room_id;
	cin >> room_id;
	int lodging_cur = findLodging(room_id);
	if (lodging_cur >= 0) {
		loding_static[lodging_cur].room.state = true;
		string room_id = loding_static[lodging_cur].room.room_id;
		int room_cur = findRoomID(room_id);
		room_static[room_cur].state = true;
		cout << "结算费用：" << loding_static[lodging_cur].getTotalCost() << endl;
	}
	else
	{
		cout << "房间不存在或房间未入住\n";
	}
}