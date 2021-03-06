#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strlen(name) == strlen(candidates[i].name))
        {
            for (int j = 0, n = strlen(name); j < n; j++)
            {
                if (name[j] != candidates[i].name[j])
                {
                    return false;
                }
            }
            candidates[i].votes += 1;
            return true;
        }

    }
    // TODO
    return false;
}


// Print the winner (or winners) of the election
void print_winner(void)
{
    int maxVoteIndex = 0;
    int maxVotes = 0, tie = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxVotes)
        {
            maxVoteIndex = i;
            maxVotes = candidates[i].votes;
        }

        else if (candidates[i].votes == maxVotes)
        {
            tie++;
            //printf("tie %i\n",tie);
        }
    }

    if (tie > 0)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (maxVotes == candidates[i].votes)
            {
                printf("%s\n", candidates[i].name);
            }
        }
    }
    else
    {
        printf("%s\n", candidates[maxVoteIndex].name);
    }
    // TODO
    return;
}

