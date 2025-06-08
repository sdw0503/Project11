//�߿��� ����v2 20252226������
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
    int mood = 0;
    int player, computer;
    int turn_count = 0;
    int shop_choice;
    const char* item[] = { "�峭�� ��", "������ ������", "��ũ��ó", "ĹŸ��" };
    int item_cost[] = { 1, 2, 4, 6 };
    bool item_purchased[] = { false, false, false, false };
    int item_pos[ROOM_WIDTH] = { 0 };
    int item_type[] = { 0, 0, 1, 2 };
    int interaction_order[2] = { -1, -1 };
    int interaction_count = 0;
    int pos;


    printf("**** �߿��̿� ���� ****\n\n");

    printf("          /\\_/\\\n");
    printf(" / \\    / o o \\\n");
    printf("/  /\\   \\~(*)~/\n");
    printf("`   \\/      ^  /\n");
    printf("    |  \\ | |  | |\n");
    printf("    \\  `| |  | |\n");
    printf("     \\ )()-())\n");

    printf("\n�߿����� �̸��� ���� �ּ���: ");
    scanf_s(" %s", str, sizeof(str));

    printf("�߿����� �̸��� %s�Դϴ�.\n", str);

    Sleep(1000);
    system("cls");

    srand(time(NULL));

    while (1) {
        turn_count++;
        if (turn_count % 3 == 0) {
            printf("=== ���� ����Ʈ! ===\n");
            printf("%s�� ���������� ����� ��û�մϴ�.\n", str);
            printf("%s�� ���������� ���ӿ��� �̱�ʽÿ�.\n", str);
            while (1) {
                printf("����(1) ����(2) ��(3) >> ");
                scanf_s("%d", &player);


                if (player < 1 || player > 3) {
                    printf("�ٽ� �Է��ϼ���.\n");
                    continue;
                }


                computer = rand() % 3 + 1;


                if (player == 1)
                    printf("Player: ����\n");
                else if (player == 2)
                    printf("Player: ����\n");
                else
                    printf("Player: ��\n");


                if (computer == 1)
                    printf("Computer: ����\n");
                else if (computer == 2)
                    printf("Computer: ����\n");
                else
                    printf("Computer: ��\n");


                if (player == computer) {
                    printf("�����ϴ�.\n");
                    printf("�ٽ� �õ� �ϼ���.\n");
                }
                else if ((player == 1 && computer == 3) ||
                    (player == 2 && computer == 1) ||
                    (player == 3 && computer == 2)) {
                    printf("Player�� �̰���ϴ�.\n");
                    break;
                }
                else {
                    printf("Computer�� �̰���ϴ�.\n");
                    printf("�ٽ� �õ� �ϼ���.\n");
                }
                Sleep(1000);
                printf("\n");
            }
        }
        Sleep(2500);
        system("cls");

        printf("=============== ���� ���� ===============\n");
        printf("CP:%d ����Ʈ\n", cp);
        printf("%s ���(0~3):%d\n", str, mood);
        printf("������� ���� ����: %d��\n", soup);
        printf("������� ���� (0~4): %d\n", relationship);

        if (relationship == 0)
            printf("�翡 ���� ������ �Ⱦ��մϴ�.\n");
        else if (relationship == 1)
            printf("���� ���Ǳ� ����Դϴ�.\n");
        else if (relationship == 2)
            printf("�׷����� ������ �����Դϴ�.\n");
        else if (relationship == 3)
            printf("�Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
        else if (relationship == 4)
            printf("���� �������Դϴ�.\n");

        printf("==========================================\n\n");

        Sleep(500);

        printf("6-%d: �ֻ��� ���� %d���ϸ� �׳� ����� �������ϴ�.\n", relationship, 6 - relationship);
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
        Sleep(500);

        number = rand() % 6 + 1;
        printf("%d(��)�� ���Խ��ϴ�!\n", number);
        Sleep(500);
        past_cat = cat;
        if (number <= 6 - relationship) {
            if (mood > 0) mood--;
            printf("%s(��)�� ����� �������ϴ�:%d\n", str, mood);
        }
        else {
            printf("%s(��)�� ����� �״���Դϴ�.\n", str);
        }

        // ����̰� �̵��ϴ� �ڵ�
        if (mood == 0) {
            if (cat > HME_POS) {
                cat--;
                printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", str);
            }
        }
        else if (mood == 1) {
            // ���� ����� ���հ� ã��
            int closest_dist = ROOM_WIDTH;
            int target_pos = -1;
            for (int i = 0; i < ROOM_WIDTH; i++) {
                if (item_pos[i] == 1 || item_pos[i] == 2) { // ��ũ��ó(S) �Ǵ� ĹŸ��(T)
                    int dist = abs(i - cat);
                    if (dist < closest_dist) {
                        closest_dist = dist;
                        target_pos = i;
                    }
                }
            }
            if (target_pos != -1) {
                if (cat < target_pos) cat++;
                else if (cat > target_pos) cat--;
                printf("%s(��)�� �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n", str);
            }
            else {
                printf("���հ��� ��� ����� �ſ� �������ϴ�.\n");
            }
        }
        else if (mood == 2) {
            printf("%s(��)�� ������� �Ļ��� ���� �ֽ��ϴ�.\n", str);

        }
        else if (mood == 3) {
            if (cat < BWL_POS) {
                cat++;
                printf("%s(��)�� ������ �θ��� ������ ���鷯 ���ϴ�.\n", str);
            }
        }


        printf("\n");
        Sleep(500);

        if (cat == HME_POS) {

            if (past_cat == HME_POS) {
                mood++;
                printf("������ ���� ���� %s(��)�� ����� ���� �������ϴ�: %d->%d\n", str, mood - 1, mood);
            }
        }
        else if (cat == BWL_POS) {
            printf("%s(��)�� ������ ��������ϴ�!\n", str);
            const char* soups[] = { "���� ����", "����� ����", "����ݸ� ����" };
            printf("%s�� ��������ϴ�!\n", soups[rand() % 3]);
            soup++;
            printf("������� ���� ���� ��: %d��\n\n", soup);
        }
        else if (item_pos[cat] == 1) {
            // ��ũ��ó
            mood++;
            printf("%s(��)�� ��ũ��ó�� �ܰ� ��ҽ��ϴ�. ����� ���� ���������ϴ�: %d->%d\n", str, mood - 1, mood);
        }
        else if (item_pos[cat] == 2) {
            // ĹŸ��
            mood += 2;
            printf("%s(��)�� ĹŸ���� �پ�ٴմϴ�. ����� ���� ���������ϴ�: %d->%d\n", str, mood - 2, mood);
        }

        Sleep(500);

        // �� ���
        for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
        printf("\n");
        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0) printf("#");
            else if (i == HME_POS) printf("H");
            else if (i == BWL_POS) printf("B");
            else if (i == ROOM_WIDTH - 1) printf("#");
            else printf(" ");
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0) printf("#");
            else if (i == cat) printf("C");
            else if (item_pos[i] == 1) printf("S");
            else if (item_pos[i] == 2) printf("T");
            else if (i == ROOM_WIDTH - 1) printf("#");
            else printf(" ");
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
        printf("\n\n");

        // ��ȣ�ۿ�
        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
        printf("0. �ƹ��͵� ���� ����\n");
        printf("1. �ܾ� �ֱ�\n");
        for (int i = 0; i < interaction_count; i++) {
            int idx = interaction_order[i];
            printf("%d. %s�� ���\n", i + 2, item[idx]);
        }
        // �Է°��� ��ȿ�� ������ �ݺ�
        printf(">> ");
        scanf_s("%d", &interaction);
        while (interaction < 0 || interaction > interaction_count + 1) {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
            printf(">> ");
            scanf_s("%d", &interaction);
        }

        Sleep(500);
        number = rand() % 6 + 1;
        if (interaction == 0) {
            printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
            if (mood < 0) {
                mood--;
                printf("%s�� ����� �������ϴ�:%d\n", str, mood);
            }
            else {
                printf(" %s�� ����� �̹� 0�Դϴ�.\n", str);
            }

            printf("ģ�е��� �ֻ����� ������ ���� 5�����̸� 1����.\n");
            Sleep(500);
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            printf("%d(��)�� ���Խ��ϴ�!\n", number);

            if (number <= 5) {
                if (relationship > 0) {
                    relationship--;
                    printf("������� ���谡 �������ϴ�.\n");
                }
                else {
                    printf("ģ�е��� 0 ���Ϸ� �������� ����.\n");
                }
            }
            else {
                printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
            }
            printf("���� ģ�е�: %d\n\n", relationship);
        }
        else if (interaction == 1) {
            printf("%s�� ���� �ܾ��־����ϴ�.\n", str);
            printf("%s�� ����� �״���Դϴ�:%d\n", str, mood);
            printf("ģ�е��� �ֻ��� 5�̻��̸� 1����\n");
            Sleep(500);
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            printf("%d(��)�� ���Խ��ϴ�!\n", number);

            if (number >= 5) {
                if (relationship < 4) {
                    relationship++;
                    printf("ģ�е��� �������ϴ�.\n");
                }
                else {
                    printf("ģ�е��� 4���� �� �ö��� ����.\n");
                }
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n");
            }
            printf("���� ģ�е�: %d\n\n", relationship);

        }
       

        cp = mood - 1 + relationship;
        printf("CP: %d ����Ʈ\n", cp);
        printf("\n�������� ������ �� �� �ֽ��ϴ�.\n");
        printf("0. �ƹ��͵� ���� �ʴ´�\n");
        for (int i = 0; i < 4; i++) {
            printf("%d. %s: %d CP", i + 1, item[i], item_cost[i]);
            if (item_purchased[i]) printf(" (ǰ��)");
            printf("\n");
        }
        // �Է°��� ��ȿ�� ������ �ݺ�
        printf(">> ");
        scanf_s("%d", &shop_choice);
        while (shop_choice < 0 || shop_choice > 4) {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
            printf(">> ");
            scanf_s("%d", &shop_choice);
        }

        if (shop_choice == 0) {
            printf("�������� �ʾҽ��ϴ�.\n\n");
        }
        else if (shop_choice >= 1 && shop_choice <= 4) {
            int index = shop_choice - 1;
            if (cp < item_cost[index]) {
                printf("CP�� �����մϴ�.\n\n");
            }
            else if (item_purchased[index]) {
                printf("�̹� ������ �������Դϴ�.\n\n");
            }
            else {
                item_purchased[index] = true;
                cp -= item_cost[index];
                printf("%s�� �����߽��ϴ�. ���� CP: %d ����Ʈ\n\n", item[index], cp);
                // �峭��(0,1��)�� ���� ���� ����
                if (index == 0 || index == 1) {
                    if (interaction_count < 2) {
                        interaction_order[interaction_count++] = index;
                    }
                }
                if (index == 2 || index == 3) {

                    pos = rand() % (ROOM_WIDTH - 2) + 1; // 1~13 ����
                    while (pos == HME_POS || pos == BWL_POS || pos == cat) {
                        pos = rand() % (ROOM_WIDTH - 2) + 1;
                    }

                    if (index == 2) {
                        item_pos[pos] = 1; // ��ũ��ó
                    }
                    else {
                        item_pos[pos] = 2; // ĹŸ��
                    }

                    printf("%s�� ���� ��ġ %d�� ��ġ�߽��ϴ�.\n\n", item[index], pos);
                }
            }
        }
    }

    return 0;
}