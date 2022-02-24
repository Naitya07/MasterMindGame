#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int found(int a[], int size, int value) // search for value in array, if present return its index else return -1
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (a[i] == value)
      return i;
  }
  return -1;
}
int uniqueRand(int random_numbers[], int size) // method that generates unique random numbers of given size
{
  srand(time(0));
  int i = 0;
  while (i < size)
  {
    int random_number = rand() % 10; // creates a random number
    if (random_number >= 1 && random_number <= 9 && found(random_numbers, size, random_number) == -1)
    // if number is in between 1 & 9 and must not be present in array previously, then add into array
    {
      random_numbers[i] = random_number;
      i++;
    }
  }
  return 1;
}
int duplicatesFound(int arr[], int size) // method that checks for duplicates
{
  int i, j;
  for (i = 1; i <= 9; i++)
  {
    int count = 0;
    for (j = 0; j < size; j++)
    {
      if (arr[j] == i)
        count++;
    }
    if (count >= 2)
      return j;
  }
  return -1;
}
int main()
{

  printf("----------------------------------\n");
  printf("Welcome to MasterMind Game!!!\n");
  printf("Version 0 \n");
  printf("Release Date : Feb. 25, 2021 \n");
  printf("Programmer: Naitya Patel. \n");
  printf("-----------------------------------\n");
  printf(" * * * * \n");
  while (1)
  {
    int len;
    printf("Enter number of digits to be hidden(Enter number in between 1 to 7): ");
    scanf("%d", &len);
    if (len >= 1 && len <= 7)
    {
      int random_numbers[len], i, j;
      int count = 1;

      uniqueRand(random_numbers, len);
      printf("Enter number of guesses you want from 1-100: ");
      scanf("%d", &i);

      time_t start, end;
      double time_used;

      // starting time as soon as the user enters the number of guesses
      start = time(NULL);

      if (i >= 1 && i <= 100)
      {
        for (; i > 0; i--)
        {
          printf("You have %d tries to guess\n", i);
          printf("Enter your numbers with spaces between each number: ");
          int userNum[len];
          for (j = 0; j < len; j++)
            scanf("%d", &userNum[j]);              // take user numbers as input
          if (duplicatesFound(userNum, len) != -1) //if all are not unique then, print error message
          {
            printf("Invalid numbers\n");
          }
          else
          {
            // correct_numbers indicate numbers that are present in array but not in correct position
            // correct_location indicate that number present in array along with correct location or index
            int index, correct_numbers = 0, correct_location = 0;
            for (j = 0; j < len; j++)
            {
              index = found(random_numbers, len, userNum[j]);
              if (index != -1)
              {
                if (index == j)
                  correct_location++;
                correct_numbers++;
              }
            }
            if (correct_location == len) // if all the numbers are guessed correctly, then user is the winner
            {
              //ending time as soon as user gets the correct answer
              end = time(NULL);
              // finding time used in seconds
              time_used = (double)(difftime(end, start));

              printf("Congratulations... You have won the game!!!!!\n");
              printf("Excellent!!! you solved it with %d guesses in %0.2f seconds\n", count, time_used);
              break;
            }
            printf("Correct numbers: %d\t Correct Positioned Numbers: %d\n", correct_numbers, correct_location);
            // print hints to user about correct numbers and correct positioned numbers
            count++;
          }
        }
        if (i == 0) // if user is unable to guess numbers in chances, then printing he lost  and print unique random numbers
        {
          printf("Sorry, you lost the game!!!!\nCorrect numbers are: ");
          for (i = 0; i < len; i++)
            printf("%d ", random_numbers[i]);
          printf("\n");
        }
        int playAgain;

        printf("would you like to play again? (No: 0 ,Yes:1)\n");
        scanf("%d", &playAgain);
        if (playAgain != 1)
          break;
      }
      else
      {
        printf("Invalid number of guesses input\n");
      }
    }
    else
    {
      printf("Invalid length input\n");
    }
  }
}
