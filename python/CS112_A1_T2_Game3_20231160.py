# File: CS112_A1_T2_3_20231160.py
# purpose: There is a pile of coins between the two players in this mathematical subtraction game.
#          Every time they remove a coin from the pile, the players alternately remove a non-zero square number of coins.
#          the winner being the one who removes the last coin.
# Author: Mariam Ehab Hassan Mohammed  20231160

# initial game status
print('"welccome to Subtract a square game"\nthis game needs two players and number of coins to play with.\nthen each player choose a square number.\nthe winner is the one who get the last coin from the pile\n\n')

while True:  # loop 1
    choice = input("choose what u want\n1-Play with friend\n2-play with a computer\n3-Exit\n").lower()

    if choice == '1' or choice == 'play with friend' or choice == 'friend':  # starting the game with a friend
        # let the users enter thier name and number of coins
        player1 = input('Enter first player name\n').capitalize()
        player2 = input('Enter second player name\n').capitalize()
        coins = int(input("enter number of coins \n"))

        while coins > 0:  # loop 2
            player_1 = int(input(f"{player1}: write a non zero square number \n"))
            # check if the num is not square or zero
            if player_1 <= 0 or player_1**0.5 != int(player_1**0.5):
                print("invalid number. Please enter a non-zero square number")
            else:
                coins -= player_1
                # if coins reach zero then first player is the winner
                if coins == 0:
                    print(f"congrats! {player1} is the winner")
                    print()
                elif coins < 0:
                    # if number of coins is less than zero user should rewrite another number 
                    coins += player_1  
                    print("invalid number. this is too much")
                    continue  # reloop for loop 2
                else:
                    while True:  # loop 3
                        player_2 = int(input(f"now number of coins = {coins} \n{player2}: write a non zero square number \n"))

                        if player_2 <= 0 or player_2**0.5 != int(player_2**0.5):  # check if the num is not square or zero
                            print("invalid number. Please enter a non-zero square number")
                            continue  # if its invalid number, it will loop 3 agn 
                        else:
                            coins -= player_2
                            # if coins reach zero then second player is the winner
                            if coins == 0:
                                print(f"congrats! {player2} is the winner")
                                print()
                                # if second player wins, coins is not greater than zero --> it will end the game
                                break
                            elif coins < 0:
                                coins += player_2  # add player_2 because we subtract it before
                                print("invalid number. this is too much")
                                continue  # reloop for loop 3
                            else:
                                print(f"now number of coins = {coins}")
                                break  # break loop 3

    elif choice == '2' or choice == 'play with computer' or choice == 'computer':  # play with a computer
        import random
        import time
        player1 = input('Enter first player name\n').capitalize()
        coins = int(input("enter number of coins \n"))

        while coins > 0:
            player_1 = int(input(f"{player1}: write a non zero square number \n"))

            if player_1 <= 0 or player_1**0.5 != int(player_1**0.5):  # check if zero or not a square num
                print("invalid number. Please enter a non-zero square number")
            else:
                coins -= player_1
                if coins == 0:
                    print(f"congrats! {player1} is the winner!!")
                    print()
                elif coins < 0:
                    coins += player_1
                    print("invalid number. this is too much")
                    continue
                else:
                    i = 1  # non zero
                    list = []  # empty list to fill it with square numbers
                    while i < coins:
                        if i ** 0.5 == int(i ** 0.5) and i <= coins:  # check if the num is square to put it in the list
                            list.append(i)
                        i += 1
                    computer = random.choice(list)  # take a random number from the list
                    print(f"now number of coins = {coins} \ncomputer number is {computer}\n")
                    coins -= computer
                    if coins == 0:
                        print("computer is the winner!!")
                        print()
                    elif coins > 0:
                        time.sleep(0.5)  # take half a sec before print the next statement
                        print(f"now number of coins = {coins} \n")
                    else:
                        continue

    elif choice == '3' or choice == 'exit':
        print("Exiting program...")
        break  # exiting program by break loop 1
    else:
        print("Please enter a valid choice")  # reloop loop 1
