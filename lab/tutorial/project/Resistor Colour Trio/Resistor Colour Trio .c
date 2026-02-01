#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*Task and Objectives
Objective : Create a helpful program so that you don't have to remember the values of 
the bands.
Task : Your program should take an array of 3 colours characters as input, output the
correct string value, in ohms& kiloohms, and return the integer resistance value.The
colours encoding is as follows :
‘k’ : 0 (black)
‘n’ : 1 (brown)
‘r’ : 2 (red)
‘o’ : 3 (orange)
‘y’ : 4 (yellow)
‘g’ : 5 (green)
‘b’ : 6 (blue)
‘v’ : 7 (violet)
‘e’ : 8 (grey)
‘w’ : 9 (white)
Note : You should decode the first two colours as the main value, and the third coluor
stands for how many zeros need to be added to the main value.The main value plus
the “tailing” zeros gives us a value in ohms.For example :
{ ‘o’, ‘o’, ‘k’ } would be 33 with no zeros, which is 33 ohms.
{ ‘o’, ‘o’, ‘r’ } would be 33 with 2 zeros, which is 3300 ohms.
Your program should output the value with the corresponding unit and return only the
integer value after all the operations.For instance, the input of{ ‘o’, ‘o’, ‘r’ } should return
“3300 ohms”, and { ‘o’, ‘o’, ‘o’ } returns “33 kiloohms”.You can consider only ohms and
kiloohms as units and ignore other units, such as megaohms.However, you are
encouraged to also cover those units.*/

// 颜色到数字的映射函数
int color_to_digit(char c) {
    // 大写字母映射
    if (c == 'K') return 0;
    if (c == 'N') return 1;
    if (c == 'R') return 2;
    if (c == 'O') return 3;
    if (c == 'Y') return 4;
    if (c == 'G') return 5;
    if (c == 'B') return 6;
    if (c == 'V') return 7;
    if (c == 'E') return 8;
    if (c == 'W') return 9;

    // 小写字母映射
    if (c == 'k') return 0;
    if (c == 'n') return 1;
    if (c == 'r') return 2;
    if (c == 'o') return 3;
    if (c == 'y') return 4;
    if (c == 'g') return 5;
    if (c == 'b') return 6;
    if (c == 'v') return 7;
    if (c == 'e') return 8;
    if (c == 'w') return 9;

    return -1; // 无效颜色
}

// 将非负整数转换为字符串
void uint_to_str(char* buf, unsigned long long n) {
    if (n == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return;
    }

    char tmp[20];
    int len = 0;
    // 将数字逆序存入临时数组
    while (n > 0) {
        tmp[len++] = '0' + (n % 10);
        n /= 10;
    }

    // 反转数字到正确顺序
    for (int i = 0; i < len; i++) {
        buf[i] = tmp[len - 1 - i];
    }
    buf[len] = '\0';
}

// 电阻解码主函数
int decode_resistor(char band1, char band2, char band3) {
    int d1 = color_to_digit(band1);
    int d2 = color_to_digit(band2);
    int d3 = color_to_digit(band3);
// 计算阻值：前两位组成数字，第三位表示零的个数
    unsigned long long base_value = d1 * 10 + d2;
    unsigned long long multiplier = 1;
// 计算乘数（10的d3次方）
    for (int i = 0; i < d3; i++) {
        multiplier *= 10;
    }
 unsigned long long resistance = base_value * multiplier;
// 选择单位并输出
    if ((resistance >= 1000000) && (resistance % 1000000 == 0)) {
        // 兆欧
        unsigned long long mega_value = resistance / 1000000;
        char num_str[20];
        uint_to_str(num_str, mega_value);
        printf("%s megaohms", num_str);
    }
    else if ((resistance >= 1000)&&(resistance%1000 == 0)){
        // 千欧
        unsigned long long kilo_value = resistance / 1000;
        char num_str[20];
        uint_to_str(num_str, kilo_value);
        printf("%s kiloohms", num_str);
    }
    else {
        // 欧姆
        char num_str[20];
        uint_to_str(num_str, resistance);
        printf("%s ohms", num_str);
    }

    return (int)resistance;
}

int main() {
    while (1) {
        printf("\n请输入3个颜色字符（用空格分隔，如: o o k）: ");
        char b1, b2, b3;
        scanf(" %c %c %c", &b1, &b2, &b3);
        printf("结果: ");
        int user_result = decode_resistor(b1, b2, b3);
    }
        return 0;
}





	 
