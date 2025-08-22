#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

// Use __int128_t to handle large numbers suggested by sample cases.
using u128 = __int128_t;

// Helper function to print __int128_t.
void print_u128(u128 n) {
    if (n == 0) {
        std::cout << "0";
        return;
    }
    std::string s = "";
    while (n > 0) {
        s += (n % 10) + '0';
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
}

// Precompute powers of 10 for u128 to avoid repeated calculations.
std::vector<u128> p10_u128(40);

void precompute_p10() {
    p10_u128[0] = 1;
    for (int i = 1; i < 40; ++i) {
        p10_u128[i] = p10_u128[i - 1] * 10;
    }
}

// Memoization table for the recursive function.
std::map<long long, u128> memo;

// Function to calculate the sum of digits for all numbers from 1 to n.
u128 sum_digits_up_to(long long n) {
    if (n < 0) return 0;
    if (n < 10) return (u128)n * (n + 1) / 2;
    if (memo.count(n)) return memo[n];

    std::string s = std::to_string(n);
    int len = s.length();
    u128 p10 = p10_u128[len - 1];

    long long msd = n / p10;
    long long rest = n % p10;
    
    // This is the recursive step based on digit DP.
    // It calculates the sum for numbers up to the largest power of 10 below n,
    // then adds the contribution from the remaining numbers.
    u128 res = (u128)msd * (msd - 1) / 2 * p10;
    res += (u128)msd * (len - 1) * 45 * (p10 / 10);
    res += (u128)msd * (rest + 1);
    res += sum_digits_up_to(rest);
    
    return memo[n] = res;
}

void solve() {
    long long k;
    std::cin >> k;
    
    u128 total_sum = 0;
    long long d = 1;
    long long p10_ll = 1; // Represents 10^(d-1)
    
    while (true) {
        long long count = 9 * p10_ll;
        u128 digits_in_block = (u128)d * count;
        
        if ((u128)k > digits_in_block) {
            k -= digits_in_block;
            
            // Efficiently calculate sum of digits for a full block of d-digit numbers.
            u128 s_d_full = (u128)d * 45 * p10_u128[d - 1];
            u128 s_d_minus_1_full = (d == 1) ? 0 : (u128)(d - 1) * 45 * p10_u128[d - 2];
            total_sum += s_d_full - s_d_minus_1_full;

            d++;
            // Check to prevent long long overflow for p10_ll
            if (p10_ll > 200000000000000000LL) break;
            p10_ll *= 10;
        } else {
            // k falls into the current block of d-digit numbers
            long long start_num = p10_ll;
            long long num_full_numbers = k / d;
            long long end_num = start_num + num_full_numbers - 1;
            
            if (num_full_numbers > 0) {
                total_sum += sum_digits_up_to(end_num) - sum_digits_up_to(start_num - 1);
            }
            
            long long remaining_digits_count = k % d;
            
            if (remaining_digits_count > 0) {
                long long partial_num = end_num + 1;
                std::string s = std::to_string(partial_num);
                for (int i = 0; i < remaining_digits_count; ++i) {
                    total_sum += (s[i] - '0');
                }
            }
            break;
        }
    }
    
    print_u128(total_sum);
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    precompute_p10();
    int t;
    std::cin >> t;
    while(t--) {
        memo.clear();
        solve();
    }
    return 0;
}