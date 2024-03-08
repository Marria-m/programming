# Program: A board of 3 x 3 is displayed and player 1 takes odd numbers 1,3, 5, 7, 9 and
#          player 2 takes even numbers 0, 2, 4, 6, 8. Players take turns to write their numbers.
#          Odd numbers start. Use each number only once. The first person to complete a line
#          that adds up to 15 is the winner. The line can have both odd and even numbers.

# Author: Mariam Ehab Hassan
# ID: 20231160
# Game: 2, "tic-tac-toe game"

# Date: Fri, Mar 1, 2024
# VERSION: 3.0


# Main.............

row1 = ["A", "B", "C"]
row2 = ["D", "E", "F"]
row3 = ["G", "H", "I"]

dic = {'A': 100, 'B': 100, 'C': 100, 'D': 100, 'E': 100, 'F': 100, 'G': 100, 'H': 100, 'I': 100, '1': 1, '2': 2,
       '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

list1 = ['1', '3', '5', '7', '9']
list2 = ['2', '4', '6', '8']

print("**Welcome to tic-tac-toe game** \n")
while True:
    print("", row1, "\n",  row2, "\n", row3)
    player1 = input(f"Player1: a number from the list {list1}: ")
    if player1 not in list1:
        print("Invalid. please enter a valid number")
        continue
    pos1 = input("Enter a position to put the number in: ").upper()
    while pos1 not in row1 and pos1 not in row2 and pos1 not in row3:
        pos1 = input("Invalid. please enter a valid position: ").upper()
        continue
    list1.remove(player1)

    x = 0
    while x < 3:
        if row1[x] == pos1:
            row1[x] = player1
        elif row2[x] == pos1:
            row2[x] = player1
        elif row3[x] == pos1:
            row3[x] = player1
        x += 1

    if dic[row1[0]] + dic[row2[0]] + dic[row3[0]] == 15 or dic[row1[1]] + dic[row2[1]] + dic[row3[1]] == 15 or dic[row1[2]] + dic[row2[2]] + dic[row3[2]] == 15:
        print("Player one is the winner!!!!!")
        break
    elif dic[row1[0]] + dic[row2[1]] + dic[row3[2]] == 15 or dic[row1[2]] + dic[row2[1]] + dic[row3[0]] == 15:
        print("Player one is the winner!!!!!")
        break
    elif dic[row1[0]] + dic[row1[1]] + dic[row1[2]] == 15 or dic[row2[0]] + dic[row2[1]] + dic[row2[2]] == 15 or dic[row3[0]] + dic[row3[1]] + dic[row3[2]] == 15:
        print("Player one is the winner!!!!!")
    elif list1 == []:
        print("Draw. NO winner")
        break
    else:
        print("", row1, "\n", row2, "\n", row3)
        while True:
            player2 = input(f"Player2: Enter a number from the list {list2}: ")
            if player2 not in list2:
                print("Invalid. please enter a valid number")
                continue
            pos2 = input("Enter a position to put the number in: ").upper()
            while pos2 not in row1 and pos2 not in row2 and pos2 not in row3:
                pos2 = input("Invalid. please enter a valid position: ").upper()
                continue
            list2.remove(player2)

            x = 0
            while x < 3:
                if row1[x] == pos2:
                    row1[x] = player2
                elif row2[x] == pos2:
                    row2[x] = player2
                elif row3[x] == pos2:
                    row3[x] = player2
                x += 1
            break

        if dic[row1[0]] + dic[row2[0]] + dic[row3[0]] == 15 or dic[row1[1]] + dic[row2[1]] + dic[row3[1]] == 15 or dic[row1[2]] + dic[row2[2]] + dic[row3[2]] == 15:
            print("Player two is the winner!!!!!")
            break
        elif dic[row1[0]] + dic[row2[1]] + dic[row3[2]] == 15 or dic[row1[2]] + dic[row2[1]] + dic[row3[0]] == 15:
            print("Player two is the winner!!!!!")
            break
        elif dic[row1[0]] + dic[row1[1]] + dic[row1[2]] == 15 or dic[row2[0]] + dic[row2[1]] + dic[row2[2]] == 15 or dic[row3[0]] + dic[row3[1]] + dic[row3[2]] == 15:
            print("Player two is the winner!!!!!")
            break
        elif list2 == []:
            print("Draw. NO winner")
            break
        else:
            continue
