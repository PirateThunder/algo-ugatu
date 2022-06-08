// ID: 68814956
// https://contest.yandex.ru/contest/37787/problems/4/

#define RANDOM_CHARACTER '?'
#define MAX_CHARACTER_LENGTH 26
#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    vector<int> chapters_finds(int character) {
        if (trie[character].lastc) {
            return trie[character].chapters;
        } else {
            return vector <int>(0);
        }
    }
    int trav_(int character, int ch) {
        if (trie[character].trav[ch] == -1) {
            if (trie[character].kent[ch] != -1) {
                trie[character].trav[ch] = trie[character].kent[ch];
            } else {
                if (character == 0) {
                    trie[character].trav[ch] = 0;
                } else {
                    trie[character].trav[ch] = trav_(suf_link(character), ch);
                }
            }
        }
        return trie[character].trav[ch];
    }
    Trie() {
        Character start;
        start.lastc = false;
        start.l = 0;
        start.p = -1;
        start.trav.assign(MAX_CHARACTER_LENGTH, -1);
        start.kent.assign(MAX_CHARACTER_LENGTH, -1);
        trie.push_back(start);
    }
    void insert_word(const string s, int chapter_find) {
        int now_character = 0;
        for (auto ch: s) {
            int c = (int)(ch - 'a');
            if (trie[now_character].kent[c] == -1) {
                int trie_size = trie.size();
                Character new_character;
                new_character.lastc = false;
                new_character.kent.assign(MAX_CHARACTER_LENGTH, -1);
                new_character.trav.assign(26, -1);
                new_character.p = now_character;
                new_character.l = -1;
                new_character.pc = c;
                trie.push_back(new_character);
                trie[now_character].kent[c] = trie.size() - 1;
            }
            now_character = trie[now_character].kent[c];
        }
        trie[now_character].lastc = true;
        trie[now_character].chapters.push_back(chapter_find);
    }
    int suf_link(int character) {
        if (trie[character].l == -1) {
            if (character == 0 || trie[character].p == 0) {
                trie[character].l = 0;
            } else {
                trie[character].l = trav_(suf_link(trie[character].p), trie[character].pc);
            }
        }

        return trie[character].l;
    }
    vector<int> find_(int character) {
        if (trie[character].finds.size() > 0) return trie[character].finds;
        int now_character = character;
        while (now_character != 0) {
            if (trie[now_character].lastc) trie[character].finds.push_back(now_character);
            now_character = suf_link(now_character);
        }
        return trie[character].finds;
    }
private:
    struct Character {
        vector <int> kent;
        bool lastc;
        int p;
        int pc;
        int l;
        vector <int> trav;
        vector <int> finds;
        vector <int> chapters;
    };
    vector <Character> trie;
};

Trie* trie = new Trie;
string pt, t;
vector <int> l(0);
vector <int> d(0);
int f = 1;
string tx;

int main() {
    t = "";
    cin >> pt;
    for (int i = 0; i < pt.length(); i++) {
        char ch = pt[i];
        if (ch == RANDOM_CHARACTER) {
            if (t != "") {
                trie->insert_word(t, l.size() - 1);
                d.push_back(t.length());
                t = "";
            }
            f = 1;
        } else {
            if (f) l.push_back(i); t += ch;
            f = 0;
        }
    }
    trie->insert_word(t, l.size() - 1);
    d.push_back(t.length());
    cin >> tx;
    vector<int> c(tx.length(), 0);
    int now_character = 0;
    for (int i = 0; i < tx.length(); i++) {
        int ch = tx[i] - 'a';
        now_character = trie->trav_(now_character, ch);
        vector <int> ans = trie->find_(now_character);
        for (auto a: ans) {
            vector<int> chapters = trie->chapters_finds(a);
            for (auto chapter_find: chapters) {
                if (i - d[chapter_find] - l[chapter_find] + 1 >= 0) ++c[i - d[chapter_find] - l[chapter_find] + 1];
            }
        }
    }
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == l.size() && i + pt.length() <= tx.length()) {
            cout << i << " ";
        }
    }
    return 0;
}
