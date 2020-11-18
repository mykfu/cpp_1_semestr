// ControlWork1Ped.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
#include <string>

using namespace std;

/*
������� 1.
������� ������ �� ��������� ����� �����, ��� ������ ������� ������ ����������� �� 7.
��������� ������� �������� � ���������.
�������:
 0, -1 => []
 0, 1 => [0]
 0, 7 => [0, 7]
 7, 7 => [7]
 10, 25 => [10, 17, 24]
*/

int* getSevensArray(int start, int limit) {
    int counter = 0;
    for (int i = start; i <= limit; i += 7) {
        counter++;
    }
    int* result = new int[counter];

    for (int i = start, j = 0; i <= limit; i += 7, j++) {
        result[j] = i;
    }

    return result;
}
/*
 ������� 2.

 ���� ������, ���������� ISBN. ��������, "978-5-9775-0735-6". ��������� �������� �� ISBN ��������.
 ISBN ������� �� 13 ����. ��������� ����� ����������� � ����������� �� ����������.
 ����������� �� ��������� EAN-13 ��������� �������:
 1. ����������� ����� ���� �� ������ ��������;
 2. ���������� ����� ���������� �� ���;
 3. ����������� ����� ���� �� �������� ������;
 4. ���������� ����� � �.2 � �.3 ����������;
 5. ����������� ������� � �������� �� 10, � �������� ����������� �����.
 ���� ��������� ����� ����� �� �.4 = 0, �� ����������� ����� ����� ����.
 ������ �����, ������ ����� ��������� ����� ������������� �����, ��� ������ ����� ���� ��� ������.

 ������:
 0. "978-5-9775-0735-6" =>  "9785977507356"
 1. 7+5+7+5+7+5 = 36
 2. 36 * 3 = 108
 3. 9+8+9+7+0+3 = 36
 4. 108 + 36 = 144
 5. 10 - 4 = 6
 6. 6 == 6

*/
bool isISBNValid(string isbn) {
    int pos = -1;
    while ((pos = isbn.find('-')) != string::npos) {
        isbn.erase(pos, 1);
    }
    if (isbn.size() != 13 || !(isbn[isbn.size() - 1] >= '0' && isbn[isbn.size() - 1] <= '9')) return false;
    int sum = 0;
    for (int i = 0; i < isbn.size() - 1; i++)
    {
        if (!(isbn[i] >= '0' && isbn[i] <= '9')) return false;
        if (i % 2 == 0) {
            sum += isbn[i] - '0';
        }
        else {
            sum += 3 * (isbn[i] - '0');
        }
    }

    return (10 - sum % 10) % 10 == isbn[isbn.size() - 1] - '0';
}

string printArray(int* array) {
    string result = "[";
    int length = _msize(array) / sizeof(int);
    for (int i = 0; i < length; i++)
    {
        result += to_string(array[i]) + (i < length - 1 ? ", " : "");
    }
    return result + "]\n";
}

void cw1()
{
    cout << "Task 1.";
    cout << " Sevens \"array\": \n";

    cout << "  Expected: [], actual: " << printArray(getSevensArray(0, -1));
    cout << "  Expected: [0], actual: " << printArray(getSevensArray(0, 1));
    cout << "  Expected: [0, 7], actual: " << printArray(getSevensArray(0, 7));
    cout << "  Expected: [-20, -13, -6], actual: " << printArray(getSevensArray(-20, -3));
    cout << "  Expected: [7], actual: " << printArray(getSevensArray(7, 7));
    cout << "  Expected: [10, 17, 24], actual: " << printArray(getSevensArray(10, 25));

    cout << "Task 2.\n";
    cout << "  ISBN 978-5-9775-0735-6 " << (isISBNValid("978-5-9775-0735-6") ? "true" : "false") << endl;
    cout << "  ISBN 978-1-60309-432-0 " << (isISBNValid("978-1-60309-432-0") ? "true" : "false") << endl;
    cout << "  ISBN 978-5-9775-0735-4 (wrong) " << (isISBNValid("978-5-9775-0735-4") ? "true" : "false") << endl;
    cout << "  ISBN 116 (wrong) " << (isISBNValid("116") ? "true" : "false") << endl;
    cout << "  ISBN 000 (wrong) " << (isISBNValid("000") ? "true" : "false") << endl;
    cout << "  not ISBN (wrong) " << (isISBNValid("asdfasdfasdff") ? "true" : "false") << endl;



}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
