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

#include "csv.h"
#include <iostream>

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

vector<vector<string>> csv::sort_data(int column,bool up) {

}

vector<string> csv::get_column(int index) {
    vector<string> temp;
    for(int i = 0;i<data_count;i++){
        temp[i] = data[i][index];
    }
    return temp;
}

vector<string> csv::get_row(int index) {
    vector<string> temp;
    for(int i= 0;i<index;i++){
        temp[i] = data[index][i];
    }
    return temp;
}

vector<string> csv::get_max(int column) {

}

vector<string> csv::get_min(int column) {

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
    //vector<vector<string>> data;
    // paso 1 abrir/crear archivo
    write.open (file_name, std::ofstream::out | std::ofstream::trunc);
    // paso 2 guardar contenido del vector
//    for(int i =0;i<mensajes.size();i++){
//        escritura<<mensajes[i]->getPregunta()<<"\n"
//                  << mensajes[i]->getRespuesta()<<"\n";
    for(int i =0;i<this->data_count;i++){
        for(int j = 0; this->data.size();j++){
        write<< data[i][j] << endl;
        }
    }
    //paso 3 cerrar el archivo
    write.close();
}

void csv::load_file(bool headers) {
vector<vector<string>> allData;    
    
   read.open(file_name);
    //paso 2, si está abierto, leer 
    if(read.is_open()){
        string buffer;
        while(getline(read,buffer)){ //leer pregunta
//            Mensaje* msg = new Mensaje();
//           /// msg->setPregunta(buffer);
//            msg->pregunta=buffer;
//            //leer la respuesta
//            getline(lectura,buffer);           
//           // msg->setRespuesta(buffer);
//            msg->respuesta=buffer;
//            mensajesLeidos.push_back(msg);        
        }
        // paso 3: cerrar archivo
        read.close();
    }
}
