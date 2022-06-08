// ID: 68818565
// https://contest.yandex.ru/contest/37787/problems/6/

#include <bits/stdc++.h>
using namespace std;

class SufTree {
private:
    int flag_;
    int tree_size_;
    string text_;
    struct Character {
        map<char, unique_ptr<Character>> ways_;
        int begin_;
        Character* suf_link_;
        int end_;
        int launch_by_word_one = 0;
        int launch_by_word_two = 0;
        Character* have_another(char symbol) {
            return ways_.find(symbol)->second.get();
        }
        int there_is_way(char symbol) {
            return (ways_.find(symbol) != ways_.end());
        }
        void push_way(char symbol, Character* chr) {
            auto it = ways_.find(symbol);
            if (it != ways_.end()) {
                it->second.release();
                it->second.reset(chr);
            }
            else {
                ways_.emplace_hint(it, symbol, chr);
            }
        }
        Character(int start, int _end) : suf_link_(nullptr), begin_(start), end_(_end) {}
    };
    static void init_suf_link(Character*& from, Character* to) {
        if (from != nullptr) {
            from->suf_link_ = to;
            from = nullptr;
        }
    }
    struct TerminalCharacter {
        Character* chr__;
        int way__;
        int dist_;
    };
    
    int search_chapter_helper(Character* chr_, long long& k, vector<char>& way_to_correct_word) const;
    
    unique_ptr<Character> root_;
    TerminalCharacter terminal_character_;
    
    int go_by_character(Character* curr_character) {
        int way_dist = curr_character->end_ - curr_character->begin_ + 1;
        if (terminal_character_.dist_ < way_dist) {
            return 0;
        }
        else {
            terminal_character_.chr__ = curr_character;
            terminal_character_.dist_ -= way_dist;
            terminal_character_.way__ += way_dist;
            return 1;
        }
    }
    void separate(Character* next, int i_in_way, int pos, Character*& finish_inited_character) {
        Character* new_internal_chr_ = new Character(next->begin_, i_in_way - 1);
        terminal_character_.chr__->push_way(text_[next->begin_], new_internal_chr_);
        Character* end_char = new Character(pos, text_.size() - 1);
        new_internal_chr_->push_way(text_[pos], end_char);
        tree_size_++;
        new_internal_chr_->push_way(text_[next->begin_ + terminal_character_.dist_],
            next);
        next->begin_ += terminal_character_.dist_;
        init_suf_link(finish_inited_character, new_internal_chr_);
        finish_inited_character = new_internal_chr_;
        tree_size_++;
    }
    void move_terminal_character(int pos) {
        if (terminal_character_.chr__ == root_.get() && terminal_character_.dist_ > 0) {
            --terminal_character_.dist_;
            terminal_character_.way__ = pos - flag_ + 1;
        }
        else {
            terminal_character_.chr__ = (terminal_character_.chr__->suf_link_ == nullptr)
                ? root_.get()
                : terminal_character_.chr__->suf_link_;
        }
    }
public:
    explicit SufTree(string text);
    Character* take_root() const {
        return root_.get();
    }
    string search_chapter(long long k) const {
        vector<char> way_to_correct_word;
        for (const auto& chr_way : root_->ways_) {
            if (search_chapter_helper(chr_way.second.get(), k,
                way_to_correct_word)) {
                way_to_correct_word.push_back(chr_way.first);
                break;
            }
        }
        string result;
        Character* now_character = root_.get();
        for (auto it = way_to_correct_word.rbegin(); it != way_to_correct_word.rend(); ++it) {
            now_character = now_character->have_another(*it);
            long long way_dist = now_character->end_ - now_character->begin_ + 1;
            if (it == way_to_correct_word.rend() - 1) { way_dist = k; k = 0; }
            for (int i = 0; i < way_dist; ++i) {
                result.push_back(text_[now_character->begin_ + i]);
            }
        }
        if (k <= 0) {
            return result;
        }
        else {
            return "-1";
        }
    }
    void insert_symbol(int pos) {
        Character* finish_inited_character = nullptr;
        for (++flag_; flag_ > 0;) {
            if (terminal_character_.dist_ == 0) {
                terminal_character_.way__ = pos;
            }
            if (!terminal_character_.chr__->there_is_way(text_[terminal_character_.way__])) {
                ++tree_size_;
                Character* end_char = new Character(pos, text_.size() - 1);
                terminal_character_.chr__->push_way(text_[terminal_character_.way__], end_char);
                init_suf_link(finish_inited_character, terminal_character_.chr__);
            }
            else {
                Character* next = terminal_character_.chr__->have_another(text_[terminal_character_.way__]);
                if (go_by_character(next)) {
                    continue;
                }
                int i_in_way = next->begin_ + terminal_character_.dist_;
                if (text_[i_in_way] == text_[pos]) {
                    ++terminal_character_.dist_;
                    if (terminal_character_.chr__ != root_.get())
                        init_suf_link(finish_inited_character, terminal_character_.chr__);
                    break;
                }
                else {
                    separate(next, i_in_way, pos, finish_inited_character);
                }
            }
            --flag_;
            move_terminal_character(pos);
        }
    }
    void dfs(Character* chr_, int first_string_size) {
        if (chr_->ways_.empty()) {
            (chr_->begin_ <= first_string_size) ? chr_->launch_by_word_one = 1 : chr_->launch_by_word_two = 1;
        }
        for (const auto& chr_way : chr_->ways_) {
            dfs(chr_way.second.get(), first_string_size);
            chr_->launch_by_word_one |= chr_way.second->launch_by_word_one;
            chr_->launch_by_word_two |=
                chr_way.second->launch_by_word_two;
        }
    }
};

SufTree::SufTree(string text) : root_(nullptr), terminal_character_({ nullptr, 0, 0 }), text_(move(text)), flag_(0), tree_size_(1) {
    root_ = make_unique<Character>(-1, 0);
    terminal_character_.chr__ = root_.get();
    for (int pos = 0; pos < text_.size(); ++pos) {
        insert_symbol(pos);
    }
}

int SufTree::search_chapter_helper(
    SufTree::Character* chr_, long long& k,
    vector<char>& way_to_correct_word) const {
    if (chr_->launch_by_word_one && chr_->launch_by_word_two) {
        int way_dist = chr_->end_ - chr_->begin_ + 1;
        if (way_dist < k) {
            k -= way_dist;
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
    for (const auto& chr_way : chr_->ways_) {
        if (search_chapter_helper(chr_way.second.get(), k,
            way_to_correct_word)) {
            way_to_correct_word.push_back(chr_way.first);
            return 1;
        }
    }
    return 0;
}

int main() {
    long long n = 0;
    string a, b;
    cin >> a >> b >> n;
    string c = a + "#" + b + "$";
    SufTree suf_tree(c);
    suf_tree.dfs(suf_tree.take_root(), a.size());
    cout << suf_tree.search_chapter(n);
}