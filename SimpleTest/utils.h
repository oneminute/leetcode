#pragma once

template <class T>
void show_data(const T _First, const T _Last) { // order [_First, _Last)
    int i = 0;
    while (_First + i != _Last) {
        cout << i << ". " << *(_First + i) << endl;
        i++;
    }
}

template <class T>
void show_data_h(const T _First, const T _Last) { // order [_First, _Last)
    int i = 0;
    cout << "[";
    while (_First + i != _Last) {
        cout << *(_First + i);
        i++;
        if (_First + i != _Last)
            cout << ", ";
    }
    cout << "]" << endl;
}