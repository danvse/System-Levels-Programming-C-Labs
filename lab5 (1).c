#include <stdio.h>

int main() {
    int month_days, begining_of_month;
    int i;
    int today = 1;
    
    printf("Enter number of days in month: ");
    scanf("%d", &month_days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &begining_of_month);
    printf("Your requested month’s calendar is:\n");
for (i = 1; i < begining_of_month; i++) { 
	printf("   "); } 
for (i=begining_of_month; i <=7; i++) {
	if (today <= month_days){ 
		printf("%3d ", today++);
	}
}
printf("\n");
while (today <= month_days){
for (i=1; i<=7 && today <= month_days; i++) {
	printf("%3d ", today++);
}
printf("\n");
}
    return 0;
}

