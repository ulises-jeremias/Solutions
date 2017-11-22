/*
 * By: ulises-jeremias
 * From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1080
 * Name: Factovisors
 * Date: 21/11/2017
 */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

#define EPS 1e-9
#define INF 1 << 30

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n, m, primes[5000];
bool sieve[24000];
vector<ii> factors;

void calc_primes()
{
        int i, j, prime_idx = 0;

        memset(sieve, -1, sizeof sieve);
        primes[prime_idx++] = 2;

        for (i = 3; i < 230; i += 2) {
                if (sieve[i/2]) {
                        for (j = i*i; j < 48000; j += i << 1) {
                                sieve[j/2] = false;
                        }
                }
        }

        for (i = 3; i < 48000; i += 2) {
                if (sieve[i/2]) {
                        primes[prime_idx++] = i;
                }
        }
}

void prime_factors (int n) {
        factors.clear();
        int PF_idx = 0, PF = primes[0];

        while (PF*PF <= n) {
                if (n % PF == 0) {
                        factors.push_back(ii(PF, 1));
                        n /= PF;
                }

                while (n % PF == 0) {
                        factors.back().second++;
                        n /= PF;
                }

                PF = primes[PF_idx++];
        }

        if (n != 1) {
                factors.push_back(ii(n, 1));
        }
}

bool check ()
{
        int i, j, cant, f, auxn, size = (int) factors.size();

        for (i = 0; i < size; i++) {
                cant = 0; f = factors[i].first; auxn = n;
                while (auxn >= f) {
                        cant += (auxn / f);
                        auxn /= f;
                }

                if (cant < factors[i].second) {
                        return false;
                }
        }

        return true;
}

int main ()
{
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int TC, i, j;

        calc_primes();
        while (cin >> n >> m) {
                prime_factors(m);
                if (check()) {
                        cout << m << " divides " << n << "!" << endl;
                } else {
                        cout << m << " does not divide " << n << "!" << endl;
                }
        }

        return 0;
}
