//
// Created by Yener Özsoy on 02.05.17.
//
#include "../includes/Ausgabe.h"

void Ausgabe::write(int type, int row, int column, char* key) {
    if (stream.good()) {
        stream << getType(type) << " Row: " << row << " Column: " << column << " Key: " << key << std::endl;
    }
}

char* Ausgabe::getType(int type) {
    if (type == 0) {
        return "Sign              ";
    }
    else if (type == 1) {
        return "Identifier        ";
    }
    else if (type == 2) {
        return "If                ";
    }
    else if (type == 3) {
        return "While             ";
    }
    else if (type == 4) {
        return "Digit             ";
    }
    else if (type == 8) {
        return "Unknown Identifier";
    }
    return nullptr;
}

