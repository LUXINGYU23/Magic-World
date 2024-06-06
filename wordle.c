/*Wordle游戏的规则非常简单，它要求玩家在6次之内猜出一个由5个字母组成的单词。每次输入单词时，如果输入的字母在目标单词中，但是位置不对，那么格子会显示成黄色；如果输入的字母在目标单词中，且位置正确，那么格子会显示成绿色；如果都不对，则会显示成灰色。玩家需要根据每次猜词后的反馈来调整自己的猜词策略，最终猜出单词
//后端程序模块主要函数：1.按照顺序从text文件当中读取单词并且载入，返回值单词字符串 2.比较函数，输入两个字符串（单词串和玩家输入串），返回值为字符串，字符串的每个字符代表对应位置的比较结果，G代表位置和字母都正确，Y代表字母正确但位置不对，R代表字母不在答案中 
//3.主函数，实现游戏逻辑，包括读取单词，比较单词，输出结果，判断游戏是否结束等
//前端程序模块主要函数：1.绘制游戏界面，包括单词输入框，结果显示框，按钮等 2.获取玩家输入，将输入传递给后端程序模块 3.根据后端程序模块返回的结果，更新游戏界面，显示结果，判断游戏是否结束等
//Path: wordle.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "wordle.h"
// 从文件中读取单词
//文件格式：单词1\n单词2\n单词3\n...
//传入文件路径，单词序号，返回单词字符串
/*
void fill_results_in_array(char array[5][5], const char* result, int count) {
    // 确保count在有效范围内
    if (count < 0 || count >= 5) {
        printf("Error: Invalid count value.\n");
        return;
    }

    // 将结果复制到数组的适当行，我们从底部的行开始填充
    int row_to_fill = 4 - count; // 从底部开始填充，递减行索引
    strncpy(array[row_to_fill], result, 5); // 复制结果到指定行，最多5个字符
    array[row_to_fill][5] = '\0'; // 确保每行以null字符结束（用于打印或其他处理）
}

char* read_word_from_file(const char* file_path, int word_index) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", file_path);
        exit(1);
    }
    char* word = (char*)malloc(7);
    for (int i = 0; i <= word_index; i++) {
        if (fgets(word, 7, file) == NULL) {
            printf("Failed to read word from file: %s\n", file_path);
            exit(1);
        }
    }
    fclose(file);
    word[strlen(word) - 1] = '\0';
    return word;
}

// 比较两个字符串，返回比较结果
// 比较结果字符串的每个字符代表对应位置的比较结果
// G代表位置和字母都正确，Y代表字母正确但位置不对，R代表字母不在答案中
char* compare_words(const char* target, const char* guess) {
    char* result = (char*)malloc(strlen(target) + 1);
    for (int i = 0; i < strlen(target); i++) {
        if (target[i] == guess[i]) {
            result[i] = 'G';
        } else if (strchr(target, guess[i])) {
            result[i] = 'Y';
        } else {
            result[i] = 'R';
        }
    }
    result[strlen(target)] = '\0';
    return result;
}
*/
/*//测试函数
int main() {
    const char* file_path = "words.txt";
    int word_index = 1;
    char* target_word = read_word_from_file(file_path, word_index);
    printf("Target word: %s\n", target_word);
    char guess[6];
    int attempts = 0;
    while (attempts < 6) {
        printf("Enter your guess: ");
        scanf("%s", guess);
        char* result = compare_words(target_word, guess);
        printf("Result: %s\n", result);
        if (strcmp(result, "GGGGG") == 0) {
            printf("Congratulations! You guessed the word.\n");
            break;
        }
        attempts++;
    }
    if (attempts == 6) {
        printf("Sorry, you ran out of attempts. The word was: %s\n", target_word);
    }
    free(target_word);
    return 0;
}*/




