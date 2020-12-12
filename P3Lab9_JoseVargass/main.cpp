/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: josevargas
 *
 * Created on December 11, 2020, 1:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "csv.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    csv* dataset_dengue = new csv("prototipoChikito.csv",true);
    dataset_dengue->print_data();
    return 0;
}

