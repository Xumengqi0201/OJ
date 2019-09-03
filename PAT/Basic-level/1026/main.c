#include  <stdio.h>

#define CLK_TCK 100

int main() {
	int c1, c2, tick;
	scanf_s("%d %d", &c1, &c2);
	tick = (c2 - c1+50)/CLK_TCK;//注意向下取整，为保证四舍五入加上50

	int hour = tick / 3600;
	int min = (tick - hour * 3600) / 60;
	int sec = tick - hour * 3600 - min * 60;

	printf("%02d:%02d:%02d\n", hour, min, sec);
	return 0;
}
