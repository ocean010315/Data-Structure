#pragma once

#define MAX 100

typedef struct {
	char name[10];
	int id;
	char grade[4];
} StudentRecord;

StudentRecord r[MAX];
int num_record = 0;
char* fname = "grade.txt";

void read_record(char* fname);
void print_record(); //구조체의 배열을 차례로 읽어 자료 전체를 출력
void search_record(); //이름을 입력 받아 해당 학생의 자료를 출력
void change_record(); //이름과 성적을 입력 받아 해당 자료를 수정
void write_record(char* fname); //requires: 파일 이름. results: 구조체의 배열 차례로 읽어 자료 전체를 파일에 저장
