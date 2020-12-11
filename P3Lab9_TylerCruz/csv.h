/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   csv.h
 * Author: Tyler C
 *
 * Created on December 11, 2020, 1:14 PM
 */

#ifndef CSV_H
#define CSV_H
#include <string>
#include <vector>
#include <iostream>
using std::endl;
using std::vector;
using std::string;


#include <fstream>
using std::ifstream;
using std::ofstream;

class csv {
public:
    csv();
    csv(string);
    csv(string,bool);
    
    //getters && setters
    int getData_Count();
    void setFileName(string);
    string getFileName();
    vector<string> getHeaders();
    vector<vector<string>> getData();
    
    //functions
    vector<vector<string>> sort_data(int,bool); 
    vector<string> get_column(int);
    vector<string> get_row(int);
    vector<string> get_max(int);
    vector<string> get_min(int);
    void print_data();
    void truncate_row(int);
    void truncate_column(int);
    csv concat(csv,string);
    void write_file();
    void load_file(bool);
    
private:
    vector <string> headers;
    vector<vector<string>> data;
    string file_name;
    int data_count;
    bool header;
    
    //fstream
    ifstream read;
    ofstream write;
};

#endif /* CSV_H */

