#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char arr[] = "abcdef";

	printf("%d\n", sizeof(arr));
	//7 sizeof(arr)计算的是数组大小，是7个字节
	printf("%d\n", sizeof(arr + 0));
	//4/8 arr是首元素地址，arr + 0是首元素的地址  
	printf("%d\n", sizeof(*arr));
	//1 arr是首元素地址，*arr是首元素，sizeof（*arr）计算首元素大小
	printf("%d\n", sizeof(arr[1]));
	//1 arr[1]为第二个元素，字符大小字节为1
	printf("%d\n", sizeof(&arr));
	//4/8 &arr为数组的地址，仍是地址，所以4/8个字节
	printf("%d\n", sizeof(&arr + 1));
	//4/8 &arr+1是跳过整个数组的地址，也是地址，所以4/8个字节
	printf("%d\n", sizeof(&arr[0] + 1));
	//4/8 &arr[0]+1 表示第二个元素的地址




	char* p = "abcdef";

	printf("%d\n", sizeof(p));
	//4/8 p为指针变量，sizeof(p)计算指针变量的大小，4/8字节
	printf("%d\n", sizeof(p + 1));
	//4/8 p为首元素地址，p+1为第二个元素的地址，地址的大小为4/8个字节
	printf("%d\n", sizeof(*p));
	//1 p为首元素地址，*p为第一个字符'a'为一个字节
	printf("%d\n", sizeof(p[0]));
	//1  p[0] == *(p + 0) == 'a',是一个字节
	printf("%d\n", sizeof(&p));
	//4/8 取出p的整个字符串地址，还是地址
	printf("%d\n", sizeof(&p+1));
	//4/8 跳过整个字符串的的地址，还是地址
	printf("%d\n", sizeof(&p[0] + 1));
	//4/8 &p[0]+1为第二个元素的地址，还是地址
 


	//strlen求字符串长度
	printf("%d\n", strlen(p));
	//6 p存储的是a的地址，char只能存一个字节大小，"字符串默认后面又'\0'"，所以是6个
	printf("%d\n", strlen(p + 1));
	//5 p+1是b的地址，从b往后找'\0'，所以为5
	printf("%d\n", strlen(*p));
	//error p为首元素地址，*p为a，传过去的是a的ASCII的值
	printf("%d\n", strlen(p[0]));
	//error p[0]是首元素，传过去为a的ASCII的值，和上一个一样
	printf("%d\n", strlen(&p));
	//随机值 p的值是首元素地址，&p是p的地址，往后找'\0'完全随机
	printf("%d\n", strlen(&p + 1));
	//随机值 和上一个一样，只不过随机值比上一个少一次。
	printf("%d\n", strlen(&p[0] + 1));
	//5 &p[0]+1为第二个元素的地址，往后找'\0'，为5



	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
	//48 a为整个二维数组的大小 4 * 4 * 3 = 48
	printf("%d\n", sizeof(a[0][0]));
	//4 a[0][0]表示第一个整型大小，为四个字节
	printf("%d\n", sizeof(a[0]));
	//16 a[0]相当第一行作为一维数组的数组名 4 * 4 = 16
	printf("%d\n", sizeof(a[0] + 1));
	//4/8 a[0]是第一行的数组名，数组名此时是首元素的地址，a[0]其实是第一行第一个元素的地址，所以a[0]+1就是第一行第二个元素的地址，地址大小为4/8个字节
	printf("%d\n", sizeof(*(a[0] + 1)));
	//4 *(a[0] + 1)是第一行第二个元素，一个整型大小为4/8个字节
	printf("%d\n", sizeof(a + 1));
	//4 a是二维数组的数组名，没有sizeof(a),也灭有&a，所以a是首元素地址，而把二维数组看成一维数组是，二位数组的首元素是它的第一行，a就是第一行的地址，a+1就是第二行的地址，地址的大小为4/8个字节
	printf("%d\n", sizeof(*(a + 1 )));
	//16 相当于sizeof(a[1])计算第二行的大小，为十六个字节
	printf("%d\n", sizeof(&a[0] + 1));
	//4 第二行的地址，地址4/8个字节大小
	printf("%d\n", sizeof(*(&a[0] + 1)));
	//16 计算第二行大小，为十六个字节
	printf("%d\n", sizeof(*a));
	//16 a是首元素大小，解引用，是第一行元素，计算第一行的大小，为十六个字节
	printf("%d\n", sizeof(a[3]));
	//16 sizeof（）括号里面的表达式不会计算，不参与计算，也不会访问二维数组第四行，只是放了第四行的数组名，效果和a[0]一样，只会计算四个整型的大小。所以这也是为什么数组可以没有行，但必须有列的原因之一。


}