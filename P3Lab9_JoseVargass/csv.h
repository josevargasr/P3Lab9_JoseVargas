/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   csv.h
 * Author: josevargas
 *
 * Created on December 11, 2020, 1:23 PM
 */

#ifndef CSV_H
#define CSV_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class csv {
public:
    csv();
    csv(string file_name);
    csv(string file_name, bool headers);
    csv(const csv& orig);
    virtual ~csv();
    int GetData_count() const;
    string GetFile_name() const;
    void SetFile_name(string file_name);
    vector<string> GetHeaders() const;
    vector<string> GetData() const;
    
    //vector<vector<string>> sort_data(int column, bool up);
    vector<string> get_column(int index) const;
    vector<string> get_row(int index) const;
    vector<string> get_max(int column) const;
    vector<string> get_min(int column) const;
    void print_data();
    void truncate_row(int index);
    void truncate_column(int index);
    csv concat(csv file, string file_name);
    void write_file();
    void load_file(bool headers);
    
private:
    string file_name;
    vector<string> headers;
    //vector<vector<string>> data;
    int data_count;
};

#endif /* CSV_H */

