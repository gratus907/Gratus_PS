import java.io.*;
import java.util.Scanner;

public class Main
{
    static int[] preorder = new int[10101];
    public static void search(int l, int r)
    {
        if (l == r) return;
        if (l + 1 == r)
        {
            System.out.println(preorder[l]);
            return;
        }
        int mid = l;
        while(preorder[mid] <= preorder[l] && mid<r)
            mid++;
        search(l+1, mid);
        search(mid, r);
        System.out.println(preorder[l]);
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int ind = 1;
        while(sc.hasNextInt())
        {
            preorder[ind] = sc.nextInt();
            ind++;
        }
        search(1, ind);
    }
}
