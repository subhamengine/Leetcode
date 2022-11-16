/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        
        while(low<=high){
            long mid = low+(high-low)/2;
            int temp = guess(mid);
            if(temp == 0){
                return (int)mid;
            }
            else if(temp == -1){
                high = mid-1;
            }
            else low = mid+1;
        }
        return 0;
    }
};