#include<bits/stdc++.h>
using namespace std;
// A function to check if a string str is palindrome
void isPalindrome(char str[])
{
    int l = 0;
    int h = strlen(str) - 1;

    while (h > l){
        if (str[l++] != str[h--]){
            printf("%s is Not Palindrome", str);
            return;
        }
    }
    printf("%s is palindrome", str);
}
int main()
{
    char str[10] = "abacaba";
    isPalindrome(str);
}

