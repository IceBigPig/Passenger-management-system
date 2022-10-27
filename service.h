#pragma once
#include <iostream>
#include <string>
#include "lodging.h"
#include "room.h"
#include "traveler.h"

using namespace std;

// ȫ�ֱ���
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
	cout << "����ţ�";
	cin >> room_temp.room_id;
	cout << "������";
	cin >> room_temp.capacity;
	cout << "�۸�";
	cin >> room_temp.price;
	room_temp.state = true;
	room_static[room_num++] = room_temp;
	cout << "��ӳɹ�\n";
}

void changeRoomInfo() {
	cout << "����Ҫ�޸ĵķ���ţ�";
	string room_id;
	cin >> room_id;
	int cur = findRoomID(room_id);
	cout << "�޸ķ���ţ�";
	cin >> room_static[cur].room_id;
	cout << "������";
	cin >> room_static[cur].capacity;
	cout << "�۸�";
	cin >> room_static[cur].price;
	cout << "�޸ĳɹ�\n";
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
	cout << "������";
	cin >> traveler_temp.name;
	cout << "�Ա�";
	cin >> traveler_temp.sex;
	cout << "���֤�ţ�";
	cin >> traveler_temp.id_code;
	cout << "�ֻ��ţ�";
	cin >> traveler_temp.mobile;
	traveler_static[taverler_num++] = traveler_temp;
	cout << "��ӳɹ�\n";
	return traveler_temp;
}

void lodging() {
	if (room_num == 0) {
		cout << "���ȴ�������!\n";
	}
	else {
		cout << "�����뷿��ţ�";
		string room_id_temp;
		cin >> room_id_temp;
		int room_cur = findRoomID(room_id_temp);
		if (room_cur >= 0) {
			if (room_static[room_cur].state) {
				int days;
				cout << "������ס��ʱ����";
				cin >> days;
				room_static[room_cur].state = false;
				Lodging lodging_temp(room_static[room_cur], addTraveler());
				lodging_temp.days = days;
				loding_static[lodging_num++] = lodging_temp;
				cout << "����ס�޳ɹ���\n";
			} 
			else
			{
				cout << "�����ѱ�ʹ��\n";
			}
		}
		else
		{
			cout << "���䲻���ڣ�\n";
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
	cout << "ס��״̬��\n\n";
	cout << "�����\t��������\t�۸�\t��ס״̬\n";
	for (int i = 0; i < room_num; i++) {
		string state_title;
		if (room_static[i].state)
			state_title = "�շ���";
		else
			state_title = "����ס";
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
	cout << "������Ҫ����ķ��䣺";
	string room_id;
	cin >> room_id;
	int lodging_cur = findLodging(room_id);
	if (lodging_cur >= 0) {
		loding_static[lodging_cur].room.state = true;
		string room_id = loding_static[lodging_cur].room.room_id;
		int room_cur = findRoomID(room_id);
		room_static[room_cur].state = true;
		cout << "������ã�" << loding_static[lodging_cur].getTotalCost() << endl;
	}
	else
	{
		cout << "���䲻���ڻ򷿼�δ��ס\n";
	}
}