#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

void stack_queue() {
	int array_for_queue[100], array_for_deque[100];
	int queue_num = 0;
	int deque_num = 0;

	int input = 0;
	do {
		fputs("insert num: ", stdout);
		scanf("%d", &input);
		
		if (input == 0) { //deque
			if (deque_num <= 0) {
				if (queue_num <= 0) {
					puts("no num queued!", stdout);
				}
				else {
					for (; queue_num > 0;) {
						array_for_deque[deque_num++] = array_for_queue[queue_num-1];
						queue_num--;
					}
					printf("dequed: %d\n", array_for_deque[deque_num-1]);
					deque_num--;
				}
			}
			else {
				printf("dequed: %d\n", array_for_deque[deque_num - 1]);
				deque_num--;
			}
		}
		else if (input > 0){
			array_for_queue[queue_num] = input;
			queue_num++;
			printf("enqued: %d\n", array_for_queue[queue_num - 1]);
		}
	} while (input >= 0);
}

void count_binary(int decimal) {
	int count = 0;
	for (; decimal > 0;) {
		if (decimal & 1) {
			count++;
		}
		decimal = decimal >> 1;
		printf("%d\n", decimal);
	}
	printf("%d", count);
}

void dec_to_binary(int decimal) {
	int length = 0;
	char charray[30];
	for (; decimal > 0;) {
		charray[length++] = (decimal & 1);
		decimal = decimal >> 1;
	}
	for (int i = length - 1; i >= 0; i--) {
		printf("%d", charray[i]);
	}
}

void find_biggest_portion(int a[], int p, int len) {
	int left_max = 0;
	int left_sum = 0;
	int max_point_left = p-1;
	
	
	int right_max = 0;
	int right_sum = 0;
	int max_point_right = p+1;

	for (int p_to_left = p - 1; p_to_left >= 0; p_to_left--) {
		left_sum += a[p_to_left];
		if (left_sum >= left_max) {
			left_max = left_sum;
			max_point_left = p_to_left;
		}
	}
	for (int p_to_right = p + 1; p_to_right < len; p_to_right++) {
		right_sum += a[p_to_right];
		if (right_sum >= right_max) {
			right_max = right_sum;
			max_point_right = p_to_right;
		}
	}

	printf("left point: %d / right point: %d / max_value: %d", max_point_left, max_point_right, a[p] + left_max + right_max);
}

int main(void) {
	int iarr[] = { -1,-2,5,-1,3,2,10,1,2,-2,3,5,-9 };
	find_biggest_portion(iarr, 6, 13);
}