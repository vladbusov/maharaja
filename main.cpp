#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> position;

class Maharaja {
private:
    int width;
    int height;
    std::vector<bool> cells;
    std::vector<position> positions;

    bool vacant_check(int x, int y) {
        return !cells[y*width + x];
    }

    bool full_check() {
        return std::all_of(positions.begin(), positions.end(), true);
    }

    int count_ceils(int x, int y) {
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

    position search_min_pisition() {
        int x_min,y_min;
        int min_ceils = width*height;
        for (int i = 0; i < width; i++)
            for (int j = 0; j < height; j++) {
                int c = count_ceils(i, j);
                if (c < min_ceils) {
                    x_min = i;
                    y_min = j;
                    min_ceils = c;
                }
            }
        return {x_min,y_min};
    }


public:
    Maharaja(int xM, int yM) {
        this->width = xM;
        this->height = yM;
        this->cells = std::vector<bool>(xM*yM, false);
    };

    bool take_position(int x, int y) {
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

    int greedy_filling() {
        int counter = 0;
        while (!full_check()) {
            position p = search_min_pisition();
            take_position(p.first,p.second);
            counter++;
        }
        return counter;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
