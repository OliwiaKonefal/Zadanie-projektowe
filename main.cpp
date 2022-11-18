#include <iostream>
#include <string>
#include<array>

using namespace std;

int getLargestSubsets(int arr[], int lengthOfArray);

int main()
{
    int tab[10] = {-10, 5, 8, 1, -4, -4, 10, 3, -1, 1};

    getLargestSubsets(tab, 10); //wywoluje funkcje zawieracaja glowny kod programu

    return 0;
}

int getLargestSubsets(int arr[], int lengthOfArray)
{
    string currentSubset = std::to_string(arr[0]); //konwertuje int na string
    string finalSubset;
    int currentSubsetLength = 1;
    int lengthOfLargestSubset = 1;

    for(int i = 1; i <= lengthOfArray - 1; i++)
    {
       if(arr[i] < arr[i-1]) {
        currentSubsetLength++;
        currentSubset = currentSubset + ", " + std::to_string(arr[i]); // dlugosc obecnego ciagu wzrasta o 1
       } else {
            if (lengthOfLargestSubset == currentSubsetLength){ // gdy dlugosc poprzednio znalezionego najdluzszego ciagu jest rowna obecnemu, obydwa ciagi staja sie wynikiem koncowym
                finalSubset = finalSubset + " oraz " + currentSubset;
            } else if (lengthOfLargestSubset < currentSubsetLength)  {
                lengthOfLargestSubset = currentSubsetLength; // gdy dlugosc poprzednio znalezionego najdluzszego ciagu jest mniejsza od obecnego, nadpisuje koncowy wynik obecnym ciagiem
                finalSubset = currentSubset;
            }
        //resetuje dane tymczasowe, gdy ciag zostaje przerwany
        currentSubsetLength = 1;
        currentSubset = std::to_string(arr[i]);
       }
    }

    //blok, ktory pokrywa przypadek, gdy najdluzszy podciag konczy sie na ostatnim indeksie tablicy
    if (lengthOfLargestSubset == currentSubsetLength) {
        finalSubset = finalSubset + " oraz " + currentSubset;
    } else if (lengthOfLargestSubset < currentSubsetLength)  {
        lengthOfLargestSubset = currentSubsetLength;
        finalSubset = currentSubset;
    }

    cout<<"Najdluzsze malejace podciagi to : "<<finalSubset<<endl;
}
