#define _CRT_SECURE_NO_WARNINGS

#define MAX 200

#include <stdio.h>
#include <stdlib.h>

int recursion1(int n) {
	if (n == 0) return 1;
	return n*recursion1(n - 1);
}

typedef struct _node node;

struct _node {
	node *ptr;
	int num;
} typedef node;

node* head = NULL;
node* tail = NULL;

void insertQueue(int data) {
	node *newOne = (node*)malloc(sizeof(node));
	newOne->num = data;
	newOne->ptr = NULL;
	if (head == NULL) {
		head->ptr = newOne;
		tail->ptr = newOne;
	}
	else {
		tail->ptr = newOne;
		tail = newOne;
	}
}

int deleteQueue() {
	node* temp;

	if (head == NULL)
		return -1;
	temp = head;
	head = head->ptr;
	if (head == NULL)
		tail = NULL;
	int r = temp->num;
	free(temp);
	return r;
}

void printList(node* from) {
	node* temp;
	if (from == NULL) return;
	temp = from;
	while (temp != NULL) {
		printf("%d", temp->num);
		temp = temp->ptr;
	}
}

void recursive_printList(node* from) {
	if (from == NULL) return;
	printf("%d", from->num);
	recursive_printList(from->ptr);

}

void printList2(node* from) {
	if (from == NULL) return;
	recursive_printList(from->ptr);
	printf("%d", from->num);
}

long long choose(int n, int r) {
	if (r == 0 || n == r) return 1;
	if (r > 0) {
		return choose(n - 1, r - 1) + choose(n - 1, r);
	}
}



long long choose2(int n, int r) {
	static long long value[52][52];
	
	if (value[n][r] > 0) return value[n][r];
	
	if (r == 0 || n == r) {
		return value[n][r] = 1;
	}
	
	return value[n][r] = choose(n - 1, r - 1) + choose(n - 1, r);
	
}

long long fibonacci(int n) {
	static long long value[100];
	if (value[n] > 0) return value[n];
 	if (n == 1 || n==2) return 1;
	return value[n] = fibonacci(n - 1) + fibonacci(n - 2);

}

int recusrsion_pay(int bill_num, int money, int * bill_array) {
	if (bill_num == 1) {
		if (money%bill_array[0] == 0) 
			return 1;
		else 
			return 0;
	}
	int t = money/bill_array[bill_num-1];
	int res = 0;
	for (int i = 0; i <= t; i++) {
			res += recusrsion_pay(bill_num-1, money - bill_array[bill_num-1]*i, bill_array);
	}
	return res;
}

void pay() {
	int bill_num;
	int money;

	fputs("input number of bills: ",stdout);
	scanf("%d", &bill_num);

	int* bill_ptr = (int*)malloc(sizeof(int)*bill_num);
	fputs("input bills: ", stdout);
	for (int i = 0; i < bill_num; i++) {
		scanf("%d", &bill_ptr[i]);
	}

	fputs("input money: ", stdout);
	scanf("%d", &money);

	printf("%d\n", recusrsion_pay(bill_num,money,bill_ptr));
}

void print_arr(int arr[], int arr_len) {
	for (int i = 0; i < arr_len-1; i++) {
		printf("%d + ", arr[i]);
	}
	printf("%d\n", arr[arr_len-1]);
}

int partition(int n, int m,int arr[],int arr_len) {
	if (n < m)
		m = n;
	if (n == 0) {
		print_arr(arr, arr_len);
		return 1;
	}
	int count = 0;
	for (int i = 1; i <= m; i++) {
		arr[arr_len] = i;
		count += partition(n - i, i, arr, arr_len+1);
		
	}
	return count;
}

int partition_with_memoization(int n, int m, int arr[], int arr_len) {
	static int memo[MAX][MAX];
	if (n < m)
		m = n;
	if (memo[n][m] > 0)
		return memo[n][m];
	if (n == 0) {
		//print_arr(arr, arr_len);
		return memo[n][m]=1;
	}
	int count = 0;
	for (int i = 1; i <= m; i++) {
		arr[arr_len] = i;
		count += partition_with_memoization(n - i, i, arr, arr_len + 1);

	}
	return memo[n][m] = count;
}

int partition2(int m,int arr_len) {
	static int iarr[100];
	int count = 0;
	if (m == 0) {
		iarr[arr_len] = 1;
		print_arr(iarr, arr_len);
		return 1;
	}
	for (int i = 1; i <= m; i++) {
		iarr[arr_len] = i;
		count += partition2(m - i,arr_len+1);
	}
	return count;
}

void printcharray(char any_array[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%c", any_array[i]);
	}
	puts("", stdout);
}
void grayCode_reverse(char charray[], int len, int index);

void grayCode(char charray[], int len, int index) {
	if (index == len) {
		printcharray(charray, len);
		return;
	}
	charray[index] = '0';
	grayCode(charray, len, index + 1);
	charray[index] = '1';
	grayCode_reverse(charray, len, index + 1);
	return;
}

void grayCode_reverse(char charray[], int len, int index) {
	if (index == len) {
		printcharray(charray, len);
		return;
	}
	charray[index] = '1';
	grayCode(charray, len, index + 1);
	charray[index] = '0';
	grayCode_reverse(charray, len, index + 1);
}

void printiarray(int any_array[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d", any_array[i]);
	}
	puts("", stdout);
}

void grayCode2(int iarray[], int len, int index, int reverse) {
	if (index == len) {
		printiarray(iarray, len);
		return;
	}
	iarray[index] = reverse;
	grayCode2(iarray, len, index + 1, 0);
	iarray[index] = 1-reverse;
	grayCode2(iarray, len, index + 1, 1);
	return;
}

int additional_a(int n, int k) {
	if (n == 1) return 1;
	int s=1;
	for (int i = 0; i < k; i++) {
		s *= n;
	}
	return s+additional_a(n-1,k);
}

void printdoublearray(int pascalarray[10][10]) {
	
}

void pascal_(int n, int k) {
	static int pascalarray[10][10];
	if (k == 1) {
		pascalarray[0][0] = 1;
		return;
	}
	pascal_(n, k - 1);
	pascalarray[k - 1][0] = pascalarray[k - 1][k - 1] = 1;
	for (int i = 1; i < k-1; i++) {
		pascalarray[k-1][i] = pascalarray[k-2][i-1] + pascalarray[k - 2][i];
	}
	if (n == k) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				printf("%d ", pascalarray[i][j]);
			}
			puts("");
		}
	};
	return;
}

int main(void) {
	pascal_(5,5);
}
