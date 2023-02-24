package lesson1;

public class GetMax {
    public static int getMax(int[] arr){
        return 0;
    }
    public static int process(int[] arr , int L , int R){
        if(L == R) {
            return arr[L];
        }
        //取中点 右位移的速度比除二更快 并且为了防溢出
        int mid = L + ((R - L) >> 1);
        int left = process(arr , L , mid);
        int right = process(arr , mid + 1, R);
        return Math.max(left, right);
    }
}
