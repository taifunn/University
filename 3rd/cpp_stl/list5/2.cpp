#include <string>
#include <forward_list>
#include <span>
#include <cctype>
#include <iostream>
using namespace std;

using TokenSpan = span<const char>;
using TokenList = forward_list<TokenSpan>;

TokenList lex(const string& text) {
    TokenList tokens;
    auto tail = tokens.before_begin();

    auto push_token = [&](size_t start, size_t end) {
        if (start >= end) return;
        TokenSpan sp(text.data() + start, end - start);
        tail = tokens.insert_after(tail, sp);
    };

    size_t i = 0;
    const size_t n = text.size();

    while (i < n) {
        unsigned char uc = static_cast<unsigned char>(text[i]);
        char c = text[i];

        if (isspace(uc)) {
            ++i;
            continue;
        }

        if (isalpha(uc) || c == '_') {
            size_t start = i;
            i++;
            while (i < n) {
                unsigned char uc2 = static_cast<unsigned char>(text[i]);
                if (!isalnum(uc2) && text[i] != '_') break;
                i++;
            }
            push_token(start, i);
            continue;
        }

        if (isdigit(uc)) {
            size_t start = i;
            ++i;
            while (i < n && isdigit(static_cast<unsigned char>(text[i]))) {
                ++i;
            }
    
            if (i < n && text[i] == '.') {
                size_t j = i + 1;
                while (j < n && isdigit(static_cast<unsigned char>(text[j]))) {
                    ++j;
                }
                if (j > i + 1) {
                    i = j;
                }
            }
            push_token(start, i);
            continue;
        }

        if (i + 1 < n) {
            char n1 = text[i + 1];
            if ((c == '=' && n1 == '=') ||
                (c == '!' && n1 == '=') ||
                (c == '<' && n1 == '=') ||
                (c == '>' && n1 == '=')) {
                push_token(i, i + 2);
                i += 2;
                continue;
            }
        }

        switch (c) {
            case '+': case '-': case '*': case '/': case '%':
            case '(': case ')':
            case '{': case '}':
            case '[': case ']':
            case ';': case ',':
            case '<': case '>':
            case '=':
                push_token(i, i + 1);
                ++i;
                break;

            default:
                push_token(i, i + 1);
                ++i;
                break;
        }
    }

    return tokens;
}

