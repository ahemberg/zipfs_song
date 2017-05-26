#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct songlist {
    string si;
    double fi;
    double zi;
    double rec_pos;
};

bool top_zipf(const songlist& x, const songlist& y) {
    return (x.zi > y.zi) || ((x.zi == y.zi) && (x.rec_pos < y.rec_pos));
}

int main() {

    unsigned long n, m;

    cin >> n >> m;

    vector<songlist> songs(n);

    for (int i = 0; i < n; i++) {
        cin >> songs[i].fi >> songs[i].si;
        songs[i].rec_pos = (i+1);
        songs[i].zi = songs[i].fi*songs[i].rec_pos;
    }

    //Sort according to zipf score
    sort(songs.begin(), songs.end(), top_zipf);

    int j = 1;
    for (int i = 0; i < n; i++) {
        cout << songs[i].si << endl;
        if (j == m) return 0;
        j++;
    }
    return 0;
}