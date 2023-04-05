#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "simple_hash_table.h"
#include "simple_hash_table.c"


int dice(int max)
{
    return rand() % max + 1;
}

void printLine(int n)
{
    if (n == 1) puts("==================");
    if (n == 2) puts("------------------");
    if (n == 3) puts("============================");
}

int printPlayerStatus(int hp, int atk)
{
    printf("Your Status\n");
    printf("HP : %d\n", hp);
    printf("ATK : %d\n", atk);
    return hp > 0;
}

void printMobsHP(Hashtable *mobsHP)
{
    ItemArray ia = HashtableGetItems(mobsHP);
    printLine(1);
    puts("Enemys Status");
    for (int i = 0; i < ia.length; i++)
    {
        printLine(2);
        printf("mob: %s\n", ia.items[i].key);
        printf("HP : %d\n", HashtableGet(mobsHP, ia.items[i].key));
    }
    printLine(1);
}

int main()
{
    srand(time(NULL));
    int playerHP = 20, playerATK = 5, round = 0;
    Hashtable *mobsHP = newHashtable(), *mobsATK = newHashtable();
    ItemArray ia;
    HashtableSet(mobsHP, "Zombie", 20);
    HashtableSet(mobsATK, "Zombie", 3);
    HashtableSet(mobsHP, "Creeper", 20);
    HashtableSet(mobsATK, "Creeper", 43);
    HashtableSet(mobsHP, "Slime", 1);
    HashtableSet(mobsATK, "Slime", 0);
    HashtableSet(mobsHP, "Witch", 26);
    HashtableSet(mobsATK, "Witch", 6);
    HashtableSet(mobsHP, "Enderman", 40);
    HashtableSet(mobsATK, "Enderman", 7);
    
    printLine(3);
    printPlayerStatus(playerHP, playerATK);
    printLine(3);
    ia = HashtableGetItems(mobsHP);
    puts("Your enemys");
    for (int i = 0; i < ia.length; i++)
    {
        printLine(2);
        printf("mob: %s\n", ia.items[i].key);
        printf("HP : %d\n", HashtableGet(mobsHP, ia.items[i].key));
        printf("ATK: %d\n", HashtableGet(mobsATK, ia.items[i].key));
    }
    printLine(3);
    
    while (mobsHP->length > 0)
    {
        printf("Round %d!!\n", ++round);
        printPlayerStatus(playerHP, playerATK);
        printMobsHP(mobsHP);
        ia = HashtableGetItems(mobsHP);
        for (int i = 0; i < ia.length; i++)
        {
            if (i) printLine(2);
            char *enemy = ia.items[i].key;
            int enemyHP = HashtableGet(mobsHP, enemy);
            HashtableSet(mobsHP, enemy, enemyHP - playerATK);
            printf("%s took %d points of damage.\n", enemy, playerATK);
            printf("%s HP: %d\n", enemy, enemyHP = HashtableGet(mobsHP, enemy));
            if (enemyHP <= 0)
            {
                printf("%s dead.\n", enemy);
                HashtableDelete(mobsHP, enemy);
                HashtableDelete(mobsATK, enemy);
                continue;
            }
            int diceNum = dice(6);
            printf("You roll a %d.", diceNum);
            if (diceNum == 1)
            {
                printf("\n");
                int damage = HashtableGet(mobsATK, enemy);
                printf("You got %d points of damage by %s.\n", damage, enemy);
                printf("Your HP: %d\n", playerHP -= damage);
                if (strcmp(enemy, "Creeper") == 0)
                {
                    printf("%s exploded and dead.\n", enemy);
                    HashtableDelete(mobsHP, enemy);
                    HashtableDelete(mobsATK, enemy);
                }
                if (playerHP <= 0)
                {
                    printf("You are dead.\nGame Over\n");
                    break;
                }
            }
            else
            {
                printf(" %s attacked you but missed.\n", enemy);
            }
        }
        printLine(3);
        if (playerHP <= 0)
        {
            break;
        }
    }
    ia = HashtableGetItems(mobsHP);
    if (ia.length == 0)
    {
        printf("You Kill all the mobs.\nYou win!\n");
    }
    else
    {
        printf("You lose\n");
    }
    printf("Your HP: %d\n", playerHP);
}