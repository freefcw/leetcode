#include <cstdio>
class Solution {
public:
    int reverse(int x) {
        long int last = 0;
        long int MAX_INT = ((1l << 31) -1);
        long int MIN_INT = (-(1l << 31));
        // printf("MAX:%ld\n", MAX_INT);
        // printf("MIN:%ld\n", MIN_INT);
        // printf("input is %d\n", x);

        while (true) {
            int current = x % 10;
            last = last * 10;
            if ((last >= MAX_INT - current)
                || (last <= MIN_INT + current)) {
                return 0;
            }
            last = last + current;
            x = x / 10;
            // printf("%d %d\n", last, x);
            if (x == 0) {
                break;
            }
        }

        return last;
    }
};

int main()
{
    Solution s;
    // s = new Solution()
    printf("ret %d\n", s.reverse(123));
    printf("ret %d\n", s.reverse(1230));
    printf("ret %d\n", s.reverse(130));
    printf("ret %d\n", s.reverse(-1230));
    printf("ret %d\n", s.reverse(-130));
    printf("ret %d\n", s.reverse(1294967296));
    printf("ret %d\n", s.reverse(129496729));
    printf("ret %d\n", s.reverse((1 << 31)));
    printf("ret %d\n", s.reverse(-129496729));
    printf("ret %d\n", s.reverse(-(1 << 31)));
    printf("ret %d\n", s.reverse(1463847412));
    return 0;
}