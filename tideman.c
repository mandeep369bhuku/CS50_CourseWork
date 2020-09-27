#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool isSorted(int ar[], int size);
void selectSort(int array[], int size);
void swapMaximum(int arr[], int n, int ct);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strlen(candidates[i]) == strlen(name))
        {
            for (int j = 0, k = strlen(name); j < k; j++)
            {
                if (candidates[i][j] != name[j])
                {
                    return false;
                }
            }
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i != j && ranks[i] != ranks[j])
            {
                preferences[ranks[i]][ranks[j]] += 1;
            }
        }
    }
    // TODO
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > 0 && preferences[i][j] != preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    // Total number of pairs.
    pair_count++;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair Max, temp;
    int maxVote = 0;
    int orignalPairs[pair_count], sortedPairs[pair_count];
    for (int i = 0; i < pair_count; i++){
        preferences[pairs[i].winner][pairs[i].loser] = orignalPairs[i];
        sortedPairs[i] = orignalPairs[i];
    }

    selectSort(sortedPairs, pair_count);

    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

// Triggers the select sort algorithm
void selectSort(int array[], int size)
{
    //Count for keeping how many elements are sorted.
    int count = 0;
    while(!isSorted(array,size))
    {
        swapMaximum(array,size,count);
        count++;
    }
}

//Checks if array is sorted from highest to lowest value.
bool isSorted(int array[], int size){
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (array[i] < array[j])
            {
                return false;
            }
        }
    }
    return true;
}


//Swaps the maximum element in array
void swapMaximum(int arr[], int n, int ct){
    int max = arr[ct];
    int indexMax = ct, temp;
    for (int i=ct; i<n; i++){
        if (max < arr[i]){
            max = arr[i];
            indexMax = i;
        }
    }
    temp = arr[ct];
    arr[ct] = max;
    arr[indexMax] = temp;
    
    return;
}