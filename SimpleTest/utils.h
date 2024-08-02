#pragma once

template <class T>
void show_data(const T _First, const T _Last) { // order [_First, _Last)
    int i = 0;
    while (_First + i != _Last) {
        cout << i << ". " << *(_First + i) << endl;
        i++;
    }
}