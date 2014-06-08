#include <stdio.h>

int main() {
    
	float h, c, d, p, altura, day = 0, n;
	while(scanf("%f %f %f %f", &h, &c, &d, &p), h) {
		altura = 0;
		n = p*c*0.01;
		day = 0;
		while (1) {
			day++;
			altura += c;
			if (altura > h) {
				printf("success ");
				break;
			}
			altura -= d;
			if (altura < 0) {
				printf("failure ");
				break;
			}
			c -= n;
			if (c < 0) c = 0;
		}
		printf("on day %0.0f\n", day);
	}
	
	return 0;
}