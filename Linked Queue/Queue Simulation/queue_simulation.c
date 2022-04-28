#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue_simulation.h"

void main() {
	int duration;

	srand(time(NULL));
	while (current_time < MAX_SIMUL_TIME) {
		printf("\n----- time %d ----- \n", current_time);

		if (is_job_arrived()) {
			++new_job_id;
			duration = get_random_duration();
			insert_job_into_queue(new_job_id, current_time, duration);
		}

		if (is_printer_idle()) {
			if (!is_queue_empty()) process_next_job();
		}
		else {
			printf("아직 Jop <%d>을 프린트하고 있습니다 ... 남은 시간 : %d \n", current_job_id, remaining_time);
			--remaining_time;
		}

		queue_show();
		++current_time;
	}

	printf("\n완료된 프린트 job = %d 개 \n", num_printed_jobs);
	printf("평균 지연 시간 = %f 단위시간 \n", (double)total_wait_time / num_printed_jobs);
}

void insert_job_into_queue(int id, int arrival_time, int duration) {
	Job p;

	p.id = id;
	p.arrival_time = arrival_time;
	p.duration = duration;

	addq(p);

	printf(" 새 jop <%d>이 들어 왔습니다. 프린트 시간은 = %d 입니다. \n", id, duration);
}

void process_next_job() {
	Job p = deleteq();
	current_job_id = p.id;
	remaining_time = p.duration - 1;

	total_wait_time += (current_time - p.arrival_time);

	++num_printed_jobs;
	
	printf(" 프린트를 시작합니다 - jop <%d>... \n", current_job_id);
}

boolean is_job_arrived() {
	if (random() < JOB_ARRIVAL_PROB)
		return true;
	else
		return false;
}

boolean is_printer_idle() {
	if (remaining_time <= 0)
		return true;
	else
		return false;
}

double random() {
	return rand() / (double)RAND_MAX;
}

int get_random_duration() {
	return (int)(MAX_PRINTING_TIME * random()) + 1;
}

void addq(Job e) {
	queue_pointer tmp = (queue_pointer)malloc(sizeof(struct queue));
	tmp->item = e;
	tmp->link = NULL;

	if (front == NULL)
		front = rear = tmp;
	else {
		rear->link = tmp;
		rear = tmp;
	}
}

Job deleteq() {
	queue_pointer tmp;
	Job e;

	if (is_queue_empty()) {
		e.arrival_time = e.duration = e.id = NULL;
		printf("\n Queue is empty \n");
		return e;
	}
	else {
		e = front->item;
		tmp = front;
		front = front->link;

		free(tmp);
		
		return e;
	}
}

boolean is_queue_empty() {
	if (front == NULL)
		return true;
	else
		return false;
}

void queue_show() {
	queue_pointer tmp = front;

	printf("\n현재 프린터 큐 :[");
	while (tmp) {
		printf("%3d(%d)", tmp->item.id, tmp->item.duration);

		tmp = tmp->link;
	}
	printf("  ] \n");
}
