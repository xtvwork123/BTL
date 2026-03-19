#pragma once
#include "MonHoc.h"
#include "SinhVien.h"
#include <iostream>
using namespace std;


bool KiemTraSinhVienDangKy(SinhVien* sv, string MaMon);
void DangKyMonHoc(SinhVien* headSV, DanhSachMonHoc& dsmh, string MaSV, string MaMon);
void HuyDangKy(SinhVien* headSV, DanhSachMonHoc& dsmh, string MaSV, string MaMon);
void DuyetQueueTuDong(SinhVien* headSV, DanhSachMonHoc& dsmh, string MaMon);