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
        return "Sign              :";
    }
    else if (type == 1) {
        return "Identifier        :";
    }
    else if (type == 2) {
        return "If                :";
    }
    else if (type == 3) {
        return "While             :";
    }
    else if (type == 4) {
        return "Digit             :";
    }
    else if (type == 5) {
        return "Sign+             :";
    }
    else if (type == 6) {
        return "Sign -            :";
    }
    else if (type == 7) {
        return "Sign :            :";
    }
    else if (type == 8) {
        return "Sign *            :";
    }
    else if (type == 9) {
        return "Sign <            :";
    }
    else if (type == 10) {
        return "Sign >            :";
    }
    else if (type == 11) {
        return "Sign =            :";
    }
    else if (type == 12) {
        return "Sign :=           :";
    }
    else if (type == 13) {
        return "Sign =:=          :";
    }
    else if (type == 14) {
        return "Sign !            :";
    }
    else if (type == 15) {
        return "Sign &&           :";
    }
    else if (type == 16) {
        return "Sign ;            :";
    }
    else if (type == 17) {
        return "Sign (            :";
    }
    else if (type == 18) {
        return "Sign )            :";
    }
    else if (type == 19) {
        return "Sign {            :";
    }
    else if (type == 20) {
        return "Sign }            :";
    }
    else if (type == 21) {
        return "Sign [            :";
    }
    else if (type == 22) {
        return "Sign ]            :";
    }
    else {
        return "Unknown Identifier";
    }
}
