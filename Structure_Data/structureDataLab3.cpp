#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <list>

using namespace std;

struct Position {
    int x, y;
    Position* next;
};

bool hasVisitedTwiceArray(const vector<pair<int, int>>& moves) {
    vector<Position> positions;
    positions.push_back({0, 0}); // начальная позиция

    int x = 0, y = 0;
    for (const auto& move : moves) {
        x += move.first;
        y += move.second;

        for (const auto& pos : positions) {
            if (pos.x == x && pos.y == y) {
                return true;
            }
        }

        positions.push_back({x, y});
    }

    return false;
}

bool hasVisitedTwiceList(const vector<pair<int, int>>& moves) {
    Position* head = new Position{0, 0, nullptr}; // начальная позиция

    Position* current = head;
    int x = 0, y = 0;
    for (const auto& move : moves) {
        x += move.first;
        y += move.second;

        Position* temp = head;
        while (temp) {
            if (temp->x == x && temp->y == y) {
                // Освобождение памяти
                while (head) {
                    Position* toDelete = head;
                    head = head->next;
                    delete toDelete;
                }
                return true;
            }
            temp = temp->next;
        }

        current->next = new Position{x, y, nullptr};
        current = current->next;
    }

    // Освобождение памяти
    while (head) {
        Position* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return false;
}

bool hasVisitedTwiceSTL(const vector<pair<int, int>>& moves) {
    set<pair<int, int>> positions;
    positions.insert({0, 0}); // начальная позиция

    int x = 0, y = 0;
    for (const auto& move : moves) {
        x += move.first;
        y += move.second;

        if (!positions.insert({x, y}).second) {
            return true;
        }
    }

    return false;
}

int main() {
    setlocale(LC_ALL,"RUS");
    int N = 100000; // Количество ходов
    vector<pair<int, int>> moves(N);

    // Генерация случайных ходов
    for (int i = 0; i < N; ++i) {
        int direction = rand() % 8;
        switch (direction) {
            case 0: moves[i] = {1, 0}; break;    // вправо
            case 1: moves[i] = {-1, 0}; break;   // влево
            case 2: moves[i] = {0, 1}; break;    // вверх
            case 3: moves[i] = {0, -1}; break;   // вниз
            case 4: moves[i] = {1, 1}; break;    // вверх-вправо
            case 5: moves[i] = {1, -1}; break;   // вниз-вправо
            case 6: moves[i] = {-1, 1}; break;   // вверх-влево
            case 7: moves[i] = {-1, -1}; break;  // вниз-влево
        }
    }

    // Тестирование Array реализации
    auto start = chrono::high_resolution_clock::now();
    bool resultArray = hasVisitedTwiceArray(moves);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationArray = end - start;
    cout << "Массив: " << (resultArray ? "Посещено дважды" : "Не посещено дважды") << " за " << durationArray.count() << " секунд\n";

    // Тестирование List реализации
    start = chrono::high_resolution_clock::now();
    bool resultList = hasVisitedTwiceList(moves);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationList = end - start;
    cout << "Связанный список: " << (resultList ? "Посещено дважды" : "Не посещено дважды") << " за " << durationList.count() << " секунд\n";

    // Тестирование STL реализации
    start = chrono::high_resolution_clock::now();
    bool resultSTL = hasVisitedTwiceSTL(moves);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationSTL = end - start;
    cout << "STL: " << (resultSTL ? "Посещено дважды" : "Не посещено дважды") << " за " << durationSTL.count() << " секунд\n";
    cout<<"\nВыполнил Корнюхин Виктор\nГруппа: 09.03.04-РПИб-о23";

    return 0;
}
