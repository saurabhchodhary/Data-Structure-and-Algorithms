// C++ program to implement Priority Queue
// using Arrays
#include <bits/stdc++.h>
using namespace std;

// Structure for the elements in the
// priority queue
struct item {
	int value;
	int priority;
};

// Store the element of a priority queue
item pr[100000];

// Pointer to the last index
int size = -1;

// Function to insert a new element
// into priority queue
void enqueue(int value, int priority)
{
	// Increase the size
	size++;

	// Insert the element
	pr[size].value = value;
	pr[size].priority = priority;
}

// Function to check the top element
int peek()
{
	int highestPriority = INT_MIN;
	int ind = -1;

	// Check for the element with
	// highest priority
	for (int i = 0; i <= size; i++) {

		// If priority is same choose
		// the element with the
		// highest value
		if (highestPriority == pr[i].priority && ind > -1
			&& pr[ind].value < pr[i].value) {
			highestPriority = pr[i].priority;
			ind = i;
		}
		else if (highestPriority < pr[i].priority) {
			highestPriority = pr[i].priority;
			ind = i;
		}
	}

	// Return position of the element
	return ind;
}

// Function to remove the element with
// the highest priority
void dequeue()
{
	// Find the position of the element
	// with highest priority
	int ind = peek();

	// Shift the element one index before
	// from the position of the element
	// with highest priority is found
	for (int i = ind; i < size; i++) {
		pr[i] = pr[i + 1];
	}

	// Decrease the size of the
	// priority queue by one
	size--;
}

// Driver Code
int main()
{
	// Function Call to insert elements
	// as per the priority
	enqueue(10, 2);
	enqueue(14, 4);
	enqueue(16, 4);
	enqueue(12, 3);

	// Stores the top element
	// at the moment
	int ind = peek();

	cout << pr[ind].value << endl;

	// Dequeue the top element
	dequeue();

	// Check the top element
	ind = peek();
	cout << pr[ind].value << endl;

	// Dequeue the top element
	dequeue();

	// Check the top element
	ind = peek();
	cout << pr[ind].value << endl;

	return 0;
}


/*//C program to Demonstrate Priority Queue
#include<stdio.h>
#include<limits.h>

#define MAX 100


// denotes where the last item in priority queue is
// initialized to -1 since no item is in queue
int idx = -1;

// pqVal holds data for each index item
// pqPriority holds priority for each index item
int pqVal[MAX];
int pqPriority[MAX];



int isEmpty ()
{
  return idx == -1;
}

int
isFull ()
{
  return idx == MAX - 1;
}

// enqueue just adds item to the end of the priority queue | O(1)
void enqueue (int data, int priority)
{
  if (!isFull ())
    {

      // Increase the index
      idx++;

      // Insert the element in priority queue
      pqVal[idx] = data;
      pqPriority[idx] = priority;
    }
}

// returns item with highest priority
// NOTE: Max Priority Queue High priority number means higher priority | O(N)
int peek ()
{
  // Note : Max Priority, so assigned min value as initial value
  int maxPriority = INT_MIN;
  int indexPos = -1;

  // Linear search for highest priority
  for (int i = 0; i <= idx; i++)
    {
      // If two items have same priority choose the one with 
      // higher data value 
      if (maxPriority == pqPriority[i] && indexPos > -1
	  && pqVal[indexPos] < pqVal[i])
	{
	  maxPriority = pqPriority[i];
	  indexPos = i;
	}

      // note: using MAX Priority so higher priority number
      // means higher priority
      else if (maxPriority < pqPriority[i])
	{
	  maxPriority = pqPriority[i];
	  indexPos = i;
	}
    }

  // Return index of the element where 
  return indexPos;
}

// This removes the element with highest priority
// from the priority queue | O(N)
void dequeue ()
{
  if (!isEmpty ())
    {
      // Get element with highest priority
      int indexPos = peek ();

      // reduce size of priority queue by first
      // shifting all elements one position left
      // from index where the highest priority item was found
      for (int i = indexPos; i < idx; i++)
	{
	  pqVal[i] = pqVal[i + 1];
	  pqPriority[i] = pqPriority[i + 1];
	}

      // reduce size of priority queue by 1
      idx--;
    }
}

void display ()
{
  for (int i = 0; i <= idx; i++)
    {
      printf ("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}

// Driver Code
int main ()
{
  // To enqueue items as per priority
  enqueue (5, 1);
  enqueue (10, 3);
  enqueue (15, 4);
  enqueue (20, 5);
  enqueue (500, 2);

  printf ("Before Dequeue : \n");
  display ();

  // Dequeue the top element
  dequeue ();			// 20 dequeued
  dequeue ();			// 15 dequeued

  printf ("\nAfter Dequeue : \n");
  display ();

  return 0;
}*/
