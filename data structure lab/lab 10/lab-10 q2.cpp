#include <stdio.h>
    #include <string.h>
    
    #define MAX_N 1000
    #define WORD_LEN 3
    #define MAX_WORDS (3 * MAX_N)
    
    char allWords[MAX_WORDS][WORD_LEN + 1];
    int wordCounts[MAX_WORDS];
    int totalWords = 0;
    
    void addWord(char *word) {
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(allWords[i], word) == 0) {
                wordCounts[i]++;
                return;
            }
        }
        strcpy(allWords[totalWords], word);
        wordCounts[totalWords] = 1;
        totalWords++;
    }
    
    int getWordCount(char *word) {
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(allWords[i], word) == 0) {
                return wordCounts[i];
            }
        }
        return 0;
    }
    
    int main() {
        int t;
        printf("Enter the number of test case :");
        scanf("%d", &t);
    
        while (t--) {
            int n;
            printf("Enter the number of words per player :");
            scanf("%d", &n);
    
            totalWords = 0;
            char words[3][MAX_N][WORD_LEN + 1];
            int scores[3] = {0, 0, 0};
    
            // Read words
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%s", words[i][j]);
                    addWord(words[i][j]);
                }
            }
    
            // Compute scores
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < n; j++) {
                    int count = getWordCount(words[i][j]);
                    if (count == 1)
                        scores[i] += 3;
                    else if (count == 2)
                        scores[i] += 1;
                }
            }
    
            printf("%d %d %d\n", scores[0], scores[1], scores[2]);
        }
    
        return 0;
    }
    
    