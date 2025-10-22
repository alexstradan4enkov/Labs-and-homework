#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    char str[256];
    cout << "Enter a string with 10 words: ";
    cin.getline(str, 255);

    int a_start = 0;
    int min_length = 256;
    int a_in_last = 0;
    int same_ends_count = 0;

    char words[10][50];
    int word_count = 0;

    // ��������� ���� ������ �� �����
    int i = 0, j = 0;
    while (str[i] != '\0' && word_count < 10) {
        if (str[i] != ' ') {
            words[word_count][j++] = str[i];
        }
        else {
            if (j > 0) {
                words[word_count][j] = '\0';
                word_count++;
                j = 0;
            }
        }
        i++;
    }

    // ��� ��������� �����
    if (j > 0) {
        words[word_count][j] = '\0';
        word_count++;
    }

    //������� ���-�� ���� ������������ � "a"; ����� ������ ��������� �����; ���-�� ����, ������������ � ��������������� �� ���� ������
    //�������� ��� ����� � ������� �������� �� ��������
    for (int i = 0; i < word_count; i++) {
        int len = strlen(words[i]);

        if (tolower(words[i][0]) == 'a') a_start++;
        if (len < min_length) min_length = len;
        if (words[i][0] == words[i][len - 1]) same_ends_count++;

        for (int j = 0; j < len; j++) {
            words[i][j] = tolower(words[i][j]);
        }
    }

    //���-�� ���� "a" � ��������� �����
    char* last_word = words[word_count - 1];
    for (int i = 0; last_word[i] != '\0'; i++) {
        if (last_word[i] == 'a') a_in_last++;
    }

    //������� ����� �������� �����, �������� ������ � ���������� 
    int shortest_word_index = 0;
    for (int i = 1; i < word_count; i++) {
        if (strlen(words[i]) < strlen(words[shortest_word_index])) {
            shortest_word_index = i;
        }
    }
    // ���� ����� �����, ������� ���� �� ���� ������
    char common_letters[50] = "";
    int common_count = 0;

    // ����� ������ ����� ��� �������
    for (int i = 0; words[0][i] != '\0'; i++) {
        char letter = words[0][i];
        bool in_all = true;

     //���������, ���� �� ��� ����� �� ���� ��������� ������
        for (int j = 1; j < word_count; j++) {
            bool found = false;
            for (int k = 0; words[j][k] != '\0'; k++) {
                if (words[j][k] == letter) {
                    found = true;
                    break;
                }
            }
        if (!found) {
            in_all = false;
            break;
            }
        }

    //���� ����� ���� �� ���� ������, ��������� ��
        if (in_all) {
            common_letters[common_count] = letter;
            common_count++;
            common_letters[common_count] = '\0';
        }
    }

    //������� ���������
    if (common_count > 0) {
        cout << "common letters in all words: " << common_letters << endl;
    }
    else {
        cout << "no common letters found!" << endl;
    }
    // ����� ���� �����������
    cout << "words starting with 'a': " << a_start << endl;
    cout << "shortest word length: " << min_length << endl;
    cout << "'a' count in last word: " << a_in_last << endl;
    cout << "words with same first/last char: " << same_ends_count << endl;
    cout << "lowercase string: ";
    for (int i = 0; i < word_count; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    return 0;
}
