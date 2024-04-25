Power of 2

To check if a number `n` is power of 2 or not just do bitwise `and` operation between `n` and `n-1`
When you subtract 1 from a power of 2, the result will have all bits set to 1 up to the position of the least significant bit (LSB) in the original number, and all bits to the right of the LSB will be 0. Therefore, the result of the bitwise AND will be 0 if n is a power of 2, and non-zero otherwise.

if((n&(n-1))==0){return true;}

---

Merging strings alternately

**In loops try to use constant values at condition part**
example

```c
while(i<str.size()) // wrong since str.size() calculated  at each iteration
```

Use constant propogation

```c
int n1 = str.size()
while(i<n1)
```

Solution

```c
int n1 = word1.size();
        int n2 = word2.size();
        while(i<n1 || j<n2){
            if(i<n1){
                str += word1[i++];
            }if(j<n2){
                str += word2[j++];
            }
        }
```

---

Greatest Common Divisor of Strings
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

- str1+str2 == str2+str1 if and only if str1 and str2 have a gcd .
- E.g. str1=abcabc, str2=abc, then str1+str2 = abcabcabc = str2+str1
- This(str1+str2==str2+str1) is a requirement for the strings to have a gcd

```c
 return (str1+str2 == str2+str1)?str1.substr(0,gcd(str1.size(),str2.size())):"";
```

- First check if str1+str2 == str2+str
- substr(0,5): from index 0 to 4, 5 not included

---

Can Place Flowers

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

```c
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(n==0){
            return true;
        }
        for(int i=0;i<size;i++){
            if(flowerbed.at(i)==0 && (i==0 || flowerbed[i-1]==0) && (i==size-1 || flowerbed[i+1]==0) ){
                flowerbed.at(i)=1;
                n--;
                if(n==0){
                    return true;
                }
            }
        }
        return false;
```

---

Reverse vowels of a string

```c
string reverseVowels(string s) {
       int i = 0, j = s.size()-1;
    char temp{};
    while (i < j) {
        if (isVowel(s.at(i)) && isVowel(s.at(j))) {
            // temp = s.at(i);
            // s.at(i) = s.at(j);
            // s.at(j) = temp;
            swap(s.at(i),s.at(j));
            i++;
            j--;
        }
        else if (isVowel(s.at(i))) {
            j--;
        }
        else if (isVowel(s.at(j))) {
            i++;
        }
        else {
            i++;
            j--;
        }
    }
    return s;
    }
    private:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
```

Need to sperately compare each character cannot do it like

```c
c == 'a' ||  'e' ||  'i' ||  'o' ||  'u' // this is wrong
```
