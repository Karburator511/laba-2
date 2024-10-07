#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_power_of_two(int n) {
    if (n < 1) return false;
    return (n & (n - 1)) == 0;
}

void process_sequence(int N) {
    int current_number;
    int sum = 0;
    int max_number = -1;  
    int min_number = INT32_MAX; 
    int count_multiples_of_five = 0;
    int count_powers_of_two = 0;
    int count_exceeding_sum_of_previous_two = 0;

 
    int prev1 = -1, prev2 = -1;

    for (int i = 0; i < N; ++i) {
        cin >> current_number;

   
        if (is_prime(current_number)) {
            cout << current_number << endl;
        }

        sum += current_number;

        if (current_number > max_number) {
            max_number = current_number;
        }
        if (current_number < min_number) {
            min_number = current_number;
        }

        if (current_number % 5 == 0) {
            count_multiples_of_five++;
        }

        if (is_power_of_two(current_number)) {
            count_powers_of_two++;
        }

        if (i >= 2 && current_number > (prev1 + prev2)) {
            count_exceeding_sum_of_previous_two++;
        }

        prev2 = prev1;
        prev1 = current_number;
    }

    cout << fixed << setprecision(2) << (double)sum / N << endl;

    cout << max_number - min_number << endl;
    cout << count_multiples_of_five << endl;
    cout << count_powers_of_two << endl;
    cout << count_exceeding_sum_of_previous_two << endl;
}

void simplified_interface() {
    int N;
    cin >> N;
    process_sequence(N);
}

void full_interface() {
    int N;
    cout << "Введите количество чисел: ";
    cin >> N;
    cout << "Введите последовательность из " << N << " чисел, каждое с новой строки: " << endl;
    process_sequence(N);
}

int main() {
    int choice;

    cout << "Выберите режим работы:\n";
    cout << "1. Упрощенный интерфейс\n";
    cout << "2. Полный интерфейс\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) {
        simplified_interface();
    }
    else if (choice == 2) {
        full_interface();
    }
    else {
        cout << "Неверный выбор!" << endl;
    }

    return 0;
}