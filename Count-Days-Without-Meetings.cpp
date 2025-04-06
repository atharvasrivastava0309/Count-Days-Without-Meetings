/*
Problem Title: Count Days Without Meetings (Leetcode 3169)

Description:
You are given a total number of working days (`days`), and a list of scheduled meetings.
Each meeting is represented as a pair [startDay, endDay], indicating a meeting from startDay to endDay (inclusive).

Some meetings may overlap, and your task is to count how many days have NO meeting scheduled.

Approach:
1. First, sort all meetings by their start day.
2. Merge overlapping meetings to avoid counting overlapping days multiple times.
3. Sum all the merged meeting durations.
4. Subtract the total meeting days from the total available days to get the result.

Example:
Input:
days = 10
meetings = [[5,7],[1,3],[9,10]]

Merged meetings = [[1,3], [5,7], [9,10]]
Total meeting days = 3 + 3 + 2 = 8
Answer = 10 - 8 = 2 days without meetings.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count the days with no meetings
int countDaysWithoutMeetings(int totalDays, vector<vector<int>>& meetings) {
    // Step 1: Sort the meetings by starting day
    sort(meetings.begin(), meetings.end());

    // Step 2: Merge overlapping meetings
    vector<vector<int>> mergedMeetings;

    for (const auto& meeting : meetings) {
        // If no overlap with the last merged meeting, add new one
        if (mergedMeetings.empty() || meeting[0] > mergedMeetings.back()[1]) {
            mergedMeetings.push_back(meeting);
        } else {
            // Overlapping meeting, merge them by extending the end time
            mergedMeetings.back()[1] = max(mergedMeetings.back()[1], meeting[1]);
        }
    }

    // Step 3: Count the total days with meetings
    int meetingDays = 0;
    for (const auto& interval : mergedMeetings) {
        meetingDays += interval[1] - interval[0] + 1;  // inclusive range
    }

    // Step 4: Subtract from total available days
    return totalDays - meetingDays;
}

int main() {
    int totalDays, numMeetings;
    cout << "Enter total number of days: ";
    cin >> totalDays;

    cout << "Enter number of meetings: ";
    cin >> numMeetings;

    vector<vector<int>> meetings(numMeetings, vector<int>(2));

    cout << "Enter meetings (start and end day for each meeting):\n";
    for (int i = 0; i < numMeetings; ++i) {
        cin >> meetings[i][0] >> meetings[i][1];
    }

    int availableDays = countDaysWithoutMeetings(totalDays, meetings);

    cout << "Number of days without meetings: " << availableDays << endl;

    return 0;
}


/*
Time complexity: O(N log N) due to sorting, where N = number of meetings.
Space complexity: O(N) for storing merged intervals.
*/