#include "../include/Estadistica.hpp"

Estadistica::Estadistica(std::string name, std::string desc) {
    this->name = name;
    this->desc = desc;
}

void Estadistica::setName(std::string name) {
    this->name = name;
}

void Estadistica::setDesc(std::string desc) {
    this->desc = desc;
}
std::string Estadistica::getName() {
    return name;
}

std::string Estadistica::getDesc() {
    return desc;
}