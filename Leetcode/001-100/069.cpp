class Solution {
public:
    int mySqrt(int x) {
      long left = 0, right = x/2, mid = 0;
      while(1){
        mid = left + (right-left)/2;
        // long long a1 = mid * mid;
        // long long a2 = (mid + 1) * (mid+1);
        if (mid*mid <= x && (mid+1)*(mid+1)>x)
          return (int)mid;
        else if (mid*mid < x)
          left = mid+1;
        else
          right = mid-1;
      }
    }
};
