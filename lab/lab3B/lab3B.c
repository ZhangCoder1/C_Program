#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PARTICIPANTS 1000

// 定义结构体存储参赛者信息
struct Record {
    char name[MAX_NAME_LEN];
    int score;
    int hours;
    int minutes;
};

// 比较函数：根据排序规则比较两个记录
int compareRecords(const struct Record *a, const struct Record *b) {
    // 1. 首先按分数降序排序
    if (a->score != b->score) {
        return b->score - a->score; // 降序：b的分数低返回负数，a排在前面
    }
    
    // 2. 分数相同则按时间升序排序
    if (a->hours != b->hours) {
        return a->hours - b->hours; // 升序：a的时间早返回负数，a排在前面
    }
    if (a->minutes != b->minutes) {
        return a->minutes - b->minutes; // 升序：a的时间早返回负数，a排在前面
    }
    
    // 3. 分数和时间都相同则按姓名字典序排序
    return strcmp(a->name, b->name); // 字典序升序
}

// 交换两个记录
void swapRecords(struct Record *a, struct Record *b) {
    struct Record temp = *a;
    *a = *b;
    *b = temp;
}

// 使用冒泡排序对记录进行排序
void sortRecords(struct Record records[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareRecords(&records[j], &records[j + 1]) > 0) {
                swapRecords(&records[j], &records[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Record records[MAX_PARTICIPANTS];
    
    // 读取输入数据
    for (int i = 0; i < n; i++) {
        char name[MAX_NAME_LEN];
        int score;
        char timeStr[6]; // 存储时间字符串（如"16:16"）
        
        scanf("%s %d %s", name, &score, timeStr);
        
        // 将时间字符串解析为小时和分钟
        sscanf(timeStr, "%d:%d", &records[i].hours, &records[i].minutes);
        
        // 复制姓名到结构体
        strcpy(records[i].name, name);
        records[i].score = score;
    }
    
    // 对记录进行排序
    sortRecords(records, n);
    
    // 输出排序后的姓名
    for (int i = 0; i < n; i++) {
        printf("%s\n", records[i].name);
    }
    
    return 0;
}
