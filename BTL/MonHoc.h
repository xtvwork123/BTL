#pragma once
#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

const int MAX = 500;
struct MonHoc {
	string MaMon;
	string TenMon;
	int TinChi;
	int TietLyThuyet;
	int TietThucHanh;
	int SiSo;
	int SiSoDangKy;
	bool DaHuy;
	Queue HangDoi;
};

struct DanhSachMonHoc {
	MonHoc ds[MAX];
	int soluong = 0;
};

int TimViTriMonHoc(DanhSachMonHoc& dsmh, string maMon);
bool ThemMonHoc(DanhSachMonHoc& dsmh, MonHoc mhMoi);
bool XoaMonHoc(DanhSachMonHoc& dsmh, string maMon);
bool SuaMonHoc(DanhSachMonHoc& dsmh, string maMon);
void SapXepMonHoc(DanhSachMonHoc& dsmh);
