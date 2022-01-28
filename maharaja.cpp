//
// Created by User on 28.01.2022.
//

#include "maharaja.h"

bool Maharaja::full_check() {
        for (auto v : cells)
            if(!v)
                return false;
        return true;
}

int Maharaja::count_ceils(int x, int y) {
    int count = 0;


    for (int i = 0; i < width; i++)
        if (!cells[y*width + i])
            count++;

    for (int i = 0; i < height; i++)
        if (!cells[i*width + x])
            count++;

    if (y > x) {
        for (int i = 0, j = (y-x); i< width, j < height; i++,j++) {
            if (!cells[j*width + i])
                count++;
        }
    } else {
        for (int i = (x-y), j = 0; i< width, j < height; i++,j++) {
            if(!cells[j*width + i])
                count++;
        }
    }

    if (y > (7-x)) {
        for (int i = 7, j = (y + x - 7); i > 0, j < height; i--,j++) {
            if(!cells[j*width + i])
                count++;
        }
    } else {
        for (int i = (x+y), j = 0; i > 0, j < height; i--,j++) {
            if (!cells[j*width + i])
                count++;
        }
    }

    return count-4;
}

position Maharaja::search_min_pisition() {
    int x_min,y_min;
    int min_ceils = width*height;
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++) {
            if (cells[j*width + i])
                continue;
            int c = count_ceils(i, j);
            if (c < min_ceils) {
                x_min = i;
                y_min = j;
                min_ceils = c;
            }
        }
    return {x_min,y_min};
}

bool Maharaja::take_position(int x, int y) {
    if (cells[y*width + x]) {
        return false;
    }

    this->positions.emplace_back(x,y);

    for (int i = 0; i < width; i++)
        cells[y*width + i] = true;

    for (int i = 0; i < height; i++)
        cells[i*width + x] = true;

    if (y > x) {
        for (int i = 0, j = (y-x); i< width, j < height; i++,j++) {
            cells[j*width + i] = true;
        }
    } else {
        for (int i = (x-y), j = 0; i< width, j < height; i++,j++) {
            cells[j*width + i] = true;
        }
    }

    if (y > (7-x)) {
        for (int i = 7, j = (y + x - 7); i > 0, j < height; i--,j++) {
            cells[j*width + i] = true;
        }
    } else {
        for (int i = (x+y), j = 0; i > 0, j < height; i--,j++) {
            cells[j*width + i] = true;
        }
    }
    return true;
}

int Maharaja::greedy_filling() {
    int counter = 0;
    while (!full_check()) {
        position p = search_min_pisition();
        take_position(p.first,p.second);
        counter++;
    }
    return counter;
}

