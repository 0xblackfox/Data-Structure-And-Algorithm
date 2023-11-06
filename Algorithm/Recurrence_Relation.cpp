#include<math.h>
#include <iostream>
using namespace std;

int main() {
    int a, b, k, p, coeff;
    double log_result;

    cout << "Enter the value of a,b,k,p,coeff : ";
    cin >> a >> b >> k >> p  >> coeff;


    if (coeff < 0) {
        cout << "Invalid\t\tDoes not apply";
    }
    else {

        log_result = log(a) / log(b);

        if (log_result > k) {
            cout << "Case - 1\t Complexity T(n) = O(n ^ log" << b << "base" << a << ")";

        }
        else if (log_result == k) {
            int q = p + 1;
            if (p >= -1) {
                cout << "Case - 2\t Complexity T(n) = O(n ^" << k << "* log ^ " << q << "n)", k, q;

            }
            else if (p == -1) {
                cout << "Case - 2\t Complexity T(n) = O(n ^" << k << " * log log n)";

            }
            else
                cout << "Case - 2\t Complexity T(n) = O(n ^" << k << ")";

        }

        else if (log_result < k) {
            if (p >= 0) {
                if (p > 0) {
                    cout << "Case - 3\t Complexity T(n) = O(n ^" << k << "* log ^ " << p << ")";

                }
                else {
                    cout << "Case - 3\t Complexity T(n) = O(n ^ " << k << ")";

                }
            }
            else {
                cout << "Case - 3\t Complexity T(n) = O(n ^" << k << ")";

            }
        }
    }
}