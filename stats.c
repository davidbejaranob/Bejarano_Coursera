/******************************************************************************
 * Copyright (C) 2017 by David Bejarano
 * 
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. David Bejarano is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Does multiple statistical calculations to a dat aset and prints it
 *
 * Analyze an array of unsigned char data items and report analytics on the
 * maximum, minimum, mean, and median of the data set. Reorder this data set
 * from large to small. Round down to the nearest integer. After analysis and
 * sorting is done, print that data to the screen in nicely formatted presentation.
 *
 * @author David Bejarano
 * @date Feb 22
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


void main() {

  unsigned char data[] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  
  // Get the size of the array so any amount of data can be the input and still work
  unsigned int length = sizeof(data) / sizeof(data[0]);
  
  
  // Print the original array
  print_array(data, length);
  
  // Print statistics
  print_statistics(data, length);
  
  // Print the sorted array
  print_array(data, length);
}



/**
 * @brief Calls for all statistics functions and prints the results
 * 
 * A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param data pointer to the data variable
 * @param lenght lenght of the data array
 */
void print_statistics(unsigned char* data, unsigned int length) {
  
  printf("\nStatistics of the array:\n");
  printf("- Minimum: %d\n", find_minimum(data, length));
  printf("- Maximum: %d\n", find_maximum(data, length));
  printf("- Mean: %d\n", find_mean(data, length));
  printf("- Median (already sorted): %d\n\n", find_median(data, length));
}

/**
 * @brief print the data array
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param data pointer to the data variable
 * @param lenght lenght of the data array
 */
void print_array(unsigned char* data, unsigned int length) {
  
  printf("Array elements:\n");
  for (unsigned int i = 0; i < length; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

/**
 * @brief find the median value of the data array
 *
 * Given an array of data and a length, returns the median value
 *
 * @param data pointer to the data variable
 * @param lenght lenght of the data array
 *
 * @return median value of the data array
 */
unsigned char find_median(unsigned char* data, unsigned int length) {
  
  sort_array(data, length);
  if (length % 2 == 0) {
    return (data[length / 2 - 1] + data[length / 2]) / 2;
  } else {
    return data[length / 2];
  }
  
}

/**
 * @brief find the mean value of the data array
 *
 * Given an array of data and a length, returns the mean
 *
 * @param data pointer to the data variable
 * @param lenght lenght of the data array
 *
 * @return mean value of the data array
 */
unsigned char find_mean(unsigned char* data, unsigned int length) {
  
  unsigned int sum = 0;
  for (unsigned int i = 0; i < length; i++) {
      sum += data[i];
  }
  return sum / length;
}

/**
 * @brief find the maximum value of the data array
 *
 * Given an array of data and a length, returns the maximum
 *
 * @param data pointer to the data variable
 * @param lenght lenght of the data array
 *
 * @return maximum value of the data array
 */
unsigned char find_maximum(unsigned char* data, unsigned int length) {

  unsigned char max = data[0];
  for (unsigned int i = 1; i < length; i++) {
      if (data[i] > max) {
          max = data[i];
      }
  }
  return max;
}

/**
 * @brief find the minimum value of the data array
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param data pointer to the data variable
 * @param lenght lenght of the data array
 *
 * @return minimum of the data array
 */
unsigned char find_minimum(unsigned char* data, unsigned int length) {
  
  unsigned char min = data[0];
  for (unsigned int i = 1; i < length; i++) {
      if (data[i] < min) {
          min = data[i];
      }
  }
  return min;
}

/**
 * @brief sort the data array
 *
 * Given an array of data and a length, sorts the array from largest to smallest.
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.)
 *
 * @param data pointer to the data variable
 * @param lenght lenght of the data array
 */
void sort_array(unsigned char* data, unsigned int length) {
  
  unsigned char* ptr1;
  unsigned char* ptr2;
  unsigned char temp;
  for (ptr1 = data; ptr1 < data + length - 1; ptr1++) {
    for (ptr2 = ptr1 + 1; ptr2 < data + length; ptr2++) {
      if (*ptr1 < *ptr2) {
        temp = *ptr1;
          *ptr1 = *ptr2;
          *ptr2 = temp;
      }
    }
  }
}
