/*
Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his among all the possibilities.
You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only have to report the distance of a (the) shortest path.
Constraints
5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.
Input
You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.
Output
Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. Each line looks like ‘#x answer’ where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space.
I/O Example
Input (20 lines in total. In the first test case, the locations of the office and the home are (0, 0) and (100, 100) respectively, and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)
5 ← Starting test case #1
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6 ← Starting test case #2
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
10 ← Starting test case #3
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
Output (10 lines in total)
#1 200
#2 304
#3 366
*/

#include <bits/stdc++.h>
using namespace std;
int n,x1,y1,x2,y2,x[20],y[20],ans;

int abs(int x)
{
    if(x<0) return (-1)*x;
    return x;
}

int dist(int i,int j) /* distance between two points */
{
    return (abs(x[i]-x[j]) + abs(y[i]-y[j]));
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void permute(int *arr, int start, int endd)
{
    if(start == endd){

        int value = 0;
        value += abs(x1 - x[arr[0]]) + abs(y1 - y[arr[0]]);

        for(int j=0;j<endd-1;j++){
            value += (dist(arr[j],arr[j+1]));
        }

        value += (abs(x[arr[endd-1]]-x2) + abs(y[arr[endd-1]]-y2));
        ans = min(ans,value);
        return;
    }

    permute(arr, start + 1, endd);
    int i;
    for(i = start + 1; i < endd; i++){
        swap(arr, start, i);
        permute(arr, start + 1, endd);
        swap(arr, start, i);
    }
}

int main(){
	int tCases;
	cin >> tCases;//For testcases
	for(int t=1;t<=tCases;t++){
        ans = INT_MAX;
		cin >> n;
		cin>> x1 >> y1 >> x2 >> y2;
		for(int i=0;i<n;i++){//Input drop off location coordinates
			cin >> x[i] >> y[i];
		}
		int arr[n];
		for(int i=0;i<n;i++){
            arr[i] = i;
		}

		permute(arr,0,n);

		cout << "#" << t << " " << ans << endl;
	}
}
