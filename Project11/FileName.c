//야옹이 스프v2 20252226서동완
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <time.h>
#include <stdbool.h>

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
    int shop_choice;
    const char* item[] = { "장난감 쥐", "레이저 포인터", "스크래처", "캣타워" };
    int item_cost[] = { 1, 2, 4, 6 };
    bool item_purchased[] = { false, false, false, false };
    int item_pos[ROOM_WIDTH] = { 0 };
    int item_type[] = { 0, 0, 1, 2 };
    int interaction_order[2] = { -1, -1 };
    int interaction_count = 0;
    int pos;



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

        printf("6-%d: 주사위 눈이 %d이하면 그냥 기분이 나빠집니다.\n", relationship, 6 - relationship);
        printf("주사위를 굴립니다. 또르륵...\n");
        Sleep(500);

        number = rand() % 6 + 1;
        printf("%d(이)가 나왔습니다!\n", number);
        Sleep(500);
        past_cat = cat;
        if (number <= 6 - relationship) {
            if (mood > 0) mood--;
            printf("%s(은)는 기분이 나빠집니다:%d\n", str, mood);
        }
        else {
            printf("%s(은)는 기분이 그대로입니다.\n", str);
        }


        // 고양이가 이동하는 코드
        if (mood == 0) {
            if (cat > HME_POS) {
                cat--;
                printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", str);
            }
        }

        else if (mood == 2) {
            printf("%s(은)는 기분좋게 식빵을 굽고 있습니다.\n", str);

        }
        else if (mood == 3) {
            if (cat < BWL_POS) {
                cat++;
                printf("%s(은)는 골골송을 부르며 수프를 만들러 갑니다.\n", str);
            }
        }



        printf("\n");
        Sleep(500);


        // 이동조건에 맞는 값을 출력하는 코드
        if (cat == HME_POS) {
            if (past_cat == HME_POS) {
                mood++;
                printf("%s(은)는 자신의 집에서 편안함을 느낍니다: %d->%d\n", str, mood - 1, mood);
            }
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
            if (mood < 0) {
                mood--;
                printf("%s의 기분이 나빠집니다:%d\n", str, mood);
            }
            else {
                printf(" %s의 기분은 이미 0입니다.\n", str);
            }

            printf("친밀도는 주사위를 던져서 눈이 5이하이면 1감소.\n");
            Sleep(500);
            printf("주사위를 굴립니다. 또르륵...\n");
            printf("%d(이)가 나왔습니다!\n", number);

            if (number <= 5) {
                if (relationship > 0) {
                    relationship--;
                    printf("집사와의 관계가 나빠집니다.\n");
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
            printf("%s의 기분은 그대로입니다:%d\n", str, mood);
            printf("친밀도는 주사위 5이상이면 1증가\n");
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
    cp = mood - 1 + relationship;
    printf("CP: %d 포인트\n", cp);
    printf("\n상점에서 물건을 살 수 있습니다.\n");
    printf("0. 아무것도 사지 않는다\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s: %d CP", i + 1, item[i], item_cost[i]);
        if (item_purchased[i]) printf(" (품절)");
        printf("\n");
    }
    // 입력값이 유효할 때까지 반복
    printf(">> ");
    scanf_s("%d", &shop_choice);
    while (shop_choice < 0 || shop_choice > 4) {
        printf("잘못된 입력입니다. 다시 입력하세요.\n");
        printf(">> ");
        scanf_s("%d", &shop_choice);
    }

    if (shop_choice == 0) {
        printf("구매하지 않았습니다.\n\n");
    }
    else if (shop_choice >= 1 && shop_choice <= 4) {
        int index = shop_choice - 1;
        if (cp < item_cost[index]) {
            printf("CP가 부족합니다.\n\n");
        }
        else if (item_purchased[index]) {
            printf("이미 구매한 아이템입니다.\n\n");
        }
        else {
            item_purchased[index] = true;
            cp -= item_cost[index];
            printf("%s를 구매했습니다. 남은 CP: %d 포인트\n\n", item[index], cp);
            // 장난감(0,1번)만 구매 순서 저장
            if (index == 0 || index == 1) {
                if (interaction_count < 2) {
                    interaction_order[interaction_count++] = index;
                }
            }
            if (index == 2 || index == 3) {

                pos = rand() % (ROOM_WIDTH - 2) + 1; // 1~13 사이
                while (pos == HME_POS || pos == BWL_POS || pos == cat) {
                    pos = rand() % (ROOM_WIDTH - 2) + 1;
                }

                if (index == 2) {
                    item_pos[pos] = 1; // 스크래처
                }
                else {
                    item_pos[pos] = 2; // 캣타워
                }

                printf("%s를 방의 위치 %d에 배치했습니다.\n\n", item[index], pos);
            }
        }
    }
    }

    return 0;
}