/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   csv.cpp
 * Author: josevargas
 * 
 * Created on December 11, 2020, 1:23 PM
 */

#include "csv.h"

csv::csv() {

}

csv::csv(string file_name) {
    this->file_name = file_name;
}

csv::csv(string file_name, bool headers) {
    this->file_name = file_name;
}

csv::csv(const csv& orig) {
}

csv::~csv() {
}

string csv::GetFile_name() const {
    return file_name;
}

void csv::SetFile_name(string file_name) {
    this->file_name = file_name;
}

vector<string> csv::GetHeaders() const {
    return headers;
}



//vector<string> csv::GetData() const {
//    return headers;
//}

int csv::GetData_count() const {
    return data_count;
}

vector<string> csv::get_column(int index) const {

}

vector<string> csv::get_row(int index) const {

}

vector<string> csv::get_max(int column) const {

}

vector<string> csv::get_min(int column) const {

}

void csv::print_data() {

}

void csv::truncate_row(int index) {

}

void csv::truncate_column(int index) {

}

csv csv::concat(csv file, string file_name) {

}

void csv::write_file() {

}

void csv::load_file(bool headers) {

}