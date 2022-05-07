#include<stdio.h>
#include<math.h>
struct point{
	int x; 
	int y;
};
float distance(point A, point B, point C){
	float a, b, c, AB, AC,result;
	a = pow((B.x - C.x),2) + pow((B.y - C.y),2);
	b = pow((A.x - C.x),2) + pow((A.y - C.y),2);
	c = pow((A.x - B.x),2) + pow((A.y - B.y),2);
	AB = sqrt(c); AC = sqrt(b);
	if (a + c == b / 2 || a + b == c / 2 || b + c == a / 2) return 0;
	result = sqrt(b * (1 - pow(((b + c - a) / (2 * AB * AC)), 2)));
	return result;
}
int main()
{
	point A, B, C;
	scanf_s("%d %d %d %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
	printf("%f", distance(A, B, C));
	return 0;
}