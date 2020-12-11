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
#include <iostream>
#include <iomanip>
#include <fstream> //file stream

using namespace std;

csv::csv() {

}

csv::csv(string file_name) {
    this->file_name = file_name;
    hay_headers = false;
    load_file(false);
}

csv::csv(string file_name, bool headers) {
    this->file_name = file_name;
    hay_headers = headers;
    load_file(headers);

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

vector<vector<string> > csv::GetData() const {
    return data;
}

int csv::GetData_count() const {
    return data_count;
}

vector<vector<string> > csv::sort_data(int column, bool up) {

}

vector<string> csv::get_column(int index) const {
    vector<string> temporal;
    for (int i = 0; i < data.size(); i++) {
        temporal.push_back(data[i][index]);
    }
    return temporal;
}

vector<string> csv::get_row(int index) const {
    vector<string> temporal = data[index];
    return temporal;
}

vector<string> csv::get_max(int column) const {
    int fila = 0;
    vector<string> temporal;
    for (int i = 0; i < data.size(); i++) {
        temporal.push_back(data[i][column]);
    }
    string mayor = temporal[0];
    for (int j = 0; j < temporal.size(); j++) {
        if (temporal[j] > mayor) {
            mayor = temporal[j];
            fila = j;
        }
    }
    vector<string> temporal2 = data[fila];
    return temporal2;
}

vector<string> csv::get_min(int column) const {
    int fila = 0;
    vector<string> temporal;
    for (int i = 0; i < data.size(); i++) {
        temporal.push_back(data[i][column]);
    }
    string menor = temporal[0];
    for (int j = 0; j < temporal.size(); j++) {
        if (temporal[j] < menor) {
            menor = temporal[j];
            fila = j;
        }
    }
    vector<string> temporal2 = data[fila];
    return temporal2;
}

void csv::print_data() {
    if (hay_headers) {
        for (int h = 0; h < data.size(); h++)
            cout << headers[h] << "     ";
        cout << endl;
    }

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data [i].size(); j++) {
            cout << data [i][j] << "       ";
        }
        cout << endl;
    }
}

void csv::truncate_row(int index) {
    data.erase(data.begin() + index);
}

void csv::truncate_column(int index) {
    for (unsigned i = 0; i < data.size(); ++i) {
        if (data[i].size() > index) {
            data[i].erase(data[i].begin() + index);
        }
    }
}

csv csv::concat(csv file, string file_name) {

}

void csv::write_file() {

}

void csv::load_file(bool headers) {
    ifstream leerArchivo;
    leerArchivo.open(file_name);
    if (leerArchivo.is_open()) {
        string buffer = "";
        if (headers) {
            getline(leerArchivo, buffer);
            string datos = "";
            for (int i = 0; i < buffer.length(); i++) {

                if (buffer[i] == ',') {
                    this->headers.push_back(datos);
                    datos.clear();

                } else if (i == buffer.length() - 1) {
                    this->headers.push_back(datos);
                    datos.clear();

                } else {
                    datos += buffer[i];
                }

            }

            buffer.clear();
        }
        while (getline(leerArchivo, buffer)) {

            vector<string> listaD;
            string datos = "";
            for (int i = 0; i < buffer.length(); i++) {

                if (buffer[i] == ',') {
                    listaD.push_back(datos);
                    datos.clear();

                } else if (i == buffer.length() - 1) {
                    listaD.push_back(datos);
                    datos.clear();

                } else {
                    datos += buffer[i];
                }
            }

            data.push_back(listaD);
            listaD.clear();

        }
    }

    leerArchivo.close();
}