//�߿��� ����v2 20252226������
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


        // �̵����ǿ� �´� ���� ����ϴ� �ڵ�
        if (cat == HME_POS) {
            if (past_cat == HME_POS) {
                mood++;
                printf("%s(��)�� �ڽ��� ������ ������� �����ϴ�: %d->%d\n", str, mood - 1, mood);
            }
        }

        else if (cat == BWL_POS) {
            printf("%s(��)�� ������ ��������ϴ�!\n", str);

            int soup_type = rand() % 3;
            if (soup_type == 0)
                printf("���� ������ ��������ϴ�!\n");
            else if (soup_type == 1)
                printf("����� ������ ��������ϴ�!\n");
            else if (soup_type == 2)
                printf("����ݸ� ������ ��������ϴ�!\n");

            soup++;
            printf("������� ���� ���� ��: %d��\n\n", soup);
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
        //��ȣ�ۿ뼱���ϴ� �κ�
        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�? 0. �ƹ��͵� ���� ���� 1. �ܾ� �ֱ�\n ");

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


    }
    cp = mood - 1 + relationship;
    printf("CP: %d ����Ʈ\n", cp);


    return 0;
}