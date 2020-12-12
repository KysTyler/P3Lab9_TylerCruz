/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   csv.cpp
 * Author: Tyler C
 * 
 * Created on December 11, 2020, 1:14 PM
 */
// < big to small
// > small to big

#include "csv.h"
#include <iostream>
#include <stdio.h> 
#include <string.h> 
void swapping(string &a, string &b);

csv::csv() {
}

csv::csv(string file_name) {
    this->file_name = file_name;
}

csv::csv(string file_name, bool header) {
    this->file_name = file_name;
    this->header = header;
}

int csv::getData_Count() {
    return this->data_count;
}

void csv::setData_Count(int ndata_count){
    this->data_count = ndata_count;
}

void csv::setFileName(string file_name) {
    this->file_name = file_name;
}

string csv::getFileName() {
    return this->file_name;
}

vector<string> csv::getHeaders() {
    return this->headers;
}

vector<vector<string>> csv::getData() {
    return this->data;
}

vector<vector<string>> csv::sort_data(int column, bool up) {
    vector<string> temp;
    for (int i = 0; i < data_count; i++) {
        temp[i] = data[i][column];
    }
    if (up) {
        for (int i = 0; i < temp.size(); i++) {
            int swaps = 0;
            for (int j = 0; j < temp.size() - i - 1; j++) {
                if (temp[j] > temp[j + 1]) {
                    swapping(temp[j], temp[j + 1]);
                    swaps = 1;
                }
            }
            if (!swaps)
                break;
        }
    } else {
        for (int i = 0; i < temp.size(); i++) {
            int swaps = 0;
            for (int j = 0; j < temp.size() - i - 1; j++) {
                if (temp[j] < temp[j + 1]) {
                    swapping(temp[j], temp[j + 1]);
                    swaps = 1;
                }
            }
            if (!swaps)
                break;
        }
    }
    vector<vector<string>> newTemp;
    for(int i = 0;i < data_count;i++){
        newTemp[i][column] = temp[i];
    }
    return newTemp;
}

vector<string> csv::get_column(int index) {
    vector<string> temp;
    for (int i = 0; i < data_count; i++) {
        temp[i] = data[i][index];
    }
    return temp;
}

vector<string> csv::get_row(int index) {
    vector<string> temp;
    for (int i = 0; i < index; i++) {
        temp[i] = data[index][i];
    }
    return temp;
}

vector<string> csv::get_max(int column) {
    vector<string> temp;
    for (int i = 0; i < data_count; i++) {
        temp[i] = data[i][column];
    }
    for (int i = 0; i < temp.size(); i++) {
        int swaps = 0;
        for (int j = 0; j < temp.size() - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swapping(temp[j], temp[j + 1]);
                swaps = 1;
            }
        }
        if (!swaps)
            break;
    }
    return temp;
}

vector<string> csv::get_min(int column) {
    vector<string> temp;
    for (int i = 0; i < data_count; i++) {
        temp[i] = data[i][column];
    }
    for (int i = 0; i < temp.size(); i++) {
        int swaps = 0;
        for (int j = 0; j < temp.size() - i - 1; j++) {
            if (temp[j] < temp[j + 1]) {
                swapping(temp[j], temp[j + 1]);
                swaps = 1;
            }
        }
        if (!swaps)
            break;
    }
    return temp;
}

void csv::print_data() {
    for (int i = 0; i<this->data_count; i++) {
        for (int j = 0; j < data.size(); j++) {
            cout << data[i][j] << endl;
        }
    }

}

void csv::truncate_row(int index) {
    this->data.at(0).erase(data.at(0).begin() + index);
    this->data_count--;

}

void csv::truncate_column(int index) {
    
}

csv csv::concat(csv file, string file_name) {
    csv newFile;
    return newFile;
}

void csv::write_file() {
    //vector<vector<string>> data;
    // paso 1 abrir/crear archivo
    write.open(file_name, std::ofstream::out | std::ofstream::trunc);
    // paso 2 guardar contenido del vector
    //    for(int i =0;i<mensajes.size();i++){
    //        escritura<<mensajes[i]->getPregunta()<<"\n"
    //                  << mensajes[i]->getRespuesta()<<"\n";
    for (int i = 0; i<this->data_count; i++) {
        for (int j = 0; this->data.size(); j++) {
            write << data[i][j] << endl;
        }
    }
    //paso 3 cerrar el archivo
    write.close();
}

void csv::load_file(bool headers) {
    cout << file_name << "this" << endl;
    read.open(file_name);
    //paso 2, si está abierto, leer 
    if (read.is_open()) {
        cout << "File Found" << endl;
        string buffer = "";
        vector<string> temp;
        while (getline(read, buffer)) { //leer pregunta
            //            char *token = strtok(buffer, ",");
            //            while (token != NULL) {
            //                //printf("%s\n", token);
            //                temp.push_back(token);",");
            //                token = strtok(NULL, ",");
            //            }
            data.push_back(temp);
            temp.clear();
        }

        // paso 3: cerrar archivo
        read.close();
    } else {
        cout << "File Not Found" << endl;
    }
}

void swapping(string &a, string &b) {
    string temp;
    temp = a;
    a = b;
    b = temp;
}


