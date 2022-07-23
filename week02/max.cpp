#include <iostream>
/**
 * @brief
 * @author panwenmei (2021112834.stu.hit.edu.cn)
 */
using namespace std;
int main() {
    int A, B, C;
    int max;
    do {
        cin >> A;
        cin >> B;
        cin >> C;
    } while (A < 0 || B < 0 || C < 0);
    max = A < B ? B : A;
    max = max < C ? C : max;
    cout << max << endl;
    system("pause");
    return 0;
}