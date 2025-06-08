//야옹이 스프v2 20252226서동완
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <time.h>

#define ROOM_WIDTH 15
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

int main(void) {
    char str[100];
    int soup = 0;
    int relationship = 2;
    int interaction;
    int number;
    int cat = 3;
    int past_cat = cat;
    int cp = 0;
    int mood = 3;


    printf("**** 야옹이와 수프 ****\n\n");

    printf("          /\\_/\\\n");
    printf(" / \\    / o o \\\n");
    printf("/  /\\   \\~(*)~/\n");
    printf("`   \\/      ^  /\n");
    printf("    |  \\ | |  | |\n");
    printf("    \\  `| |  | |\n");
    printf("     \\ )()-())\n");

    printf("\n야옹이의 이름을 지어 주세요: ");
    scanf_s(" %s", str, sizeof(str));

    printf("야옹이의 이름은 %s입니다.\n", str);

    Sleep(1000);
    system("cls");

    srand(time(NULL));

    while (1) {
        Sleep(2500);
        system("cls");

        printf("=============== 현재 상태 ===============\n");
        printf("CP:%d 포인트\n", cp);
        printf("%s 기분(0~3):%d\n", str, mood);

        printf("현재까지 만든 수프: %d개\n", soup);
        printf("집사와의 관계 (0~4): %d\n", relationship);

        if (relationship == 0)
            printf("곁에 오는 것조차 싫어합니다.\n");
        else if (relationship == 1)
            printf("간식 자판기 취급입니다.\n");
        else if (relationship == 2)
            printf("그럭저럭 쓸만한 집사입니다.\n");
        else if (relationship == 3)
            printf("훌륭한 집사로 인정받고 있습니다.\n");
        else if (relationship == 4)
            printf("집사 껌딱지입니다.\n");

        printf("==========================================\n\n");

        Sleep(500);

        printf("%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", str);
        printf("주사위 눈이 3 이상이면 냄비 쪽으로 이동합니다.\n");
        printf("주사위를 굴립니다. 또르륵...\n");
        Sleep(500);

        number = rand() % 6 + 1;
        printf("%d(이)가 나왔습니다!\n", number);
        Sleep(500);
        past_cat = cat;

        // 고양이가 이동하는 코드
        if (number >= 3) {
            if (cat + 1 < ROOM_WIDTH - 1) {
                cat++;
                printf("냄비 쪽으로 움직입니다!\n");
            }
            else {
                printf("오른쪽 벽에 막혀서 이동하지 못했습니다.\n");
            }
        }
        else {
            if (cat - 1 > 0) {
                cat--;
                printf("집 쪽으로 움직입니다!\n");
            }
            else {
                printf("왼쪽 벽에 막혀서 이동하지 못했습니다.\n");
            }
        }

        printf("\n");
        Sleep(500);


        // 이동조건에 맞는 값을 출력하는 코드
        if (cat == HME_POS) {
            printf("%s(은)는 자신의 집에서 편안함을 느낍니다.\n\n", str);
        }
        else if (cat == BWL_POS) {
            printf("%s(은)는 수프를 만들었습니다!\n", str);

            int soup_type = rand() % 3;
            if (soup_type == 0)
                printf("감자 수프를 만들었습니다!\n");
            else if (soup_type == 1)
                printf("양송이 수프를 만들었습니다!\n");
            else if (soup_type == 2)
                printf("브로콜리 수프를 만들었습니다!\n");

            soup++;
            printf("현재까지 만든 수프 수: %d개\n\n", soup);
        }
        Sleep(500);



        for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0)
                printf("#");
            else if (i == HME_POS)
                printf("H");
            else if (i == BWL_POS)
                printf("B");
            else if (i == ROOM_WIDTH - 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0)
                printf("#");
            else if (i == cat)
                printf("C");
            else if (i == past_cat && cat != past_cat)
                printf(".");
            else if (i == ROOM_WIDTH - 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
        printf("\n\n");
        //상호작용선택하는 부분
        printf("어떤 상호작용을 하시겠습니까? 0. 아무것도 하지 않음 1. 긁어 주기\n ");

        while (1) {
            printf(">>");
            scanf_s("%d", &interaction);

            if (interaction == 0 || interaction == 1) {
                break;
            }
            else {

            }
        }

        Sleep(500);

        number = rand() % 6 + 1;

        if (interaction == 0) {
            printf("아무것도 하지 않습니다.\n");
            printf("4/6 확률로 친밀도가 떨어집니다.\n");
            Sleep(500);
            printf("주사위를 굴립니다. 또르륵...\n");
            printf("%d(이)가 나왔습니다!\n", number);

            if (number <= 4) {
                if (relationship > 0) {
                    relationship--;
                    printf("친밀도가 떨어집니다.\n");
                }
                else {
                    printf("친밀도는 0 이하로 내려가지 않음.\n");
                }
            }
            else {
                printf("다행히 친밀도가 떨어지지 않았습니다.\n");
            }
            printf("현재 친밀도: %d\n\n", relationship);
        }
        else if (interaction == 1) {
            printf("%s의 턱을 긁어주었습니다.\n", str);
            printf("2/6 확률로 친밀도가 올라갑니다.\n");
            Sleep(500);
            printf("주사위를 굴립니다. 또르륵...\n");
            printf("%d(이)가 나왔습니다!\n", number);

            if (number >= 5) {
                if (relationship < 4) {
                    relationship++;
                    printf("친밀도가 높아집니다.\n");
                }
                else {
                    printf("친밀도는 4보다 더 올라가지 않음.\n");
                }
            }
            else {
                printf("친밀도는 그대로입니다.\n");
            }
            printf("현재 친밀도: %d\n\n", relationship);
        }

    }

    return 0;
}