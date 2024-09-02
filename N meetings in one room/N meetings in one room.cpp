class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
         vector<pair<int, int>> meetings;
        
        // Fill the vector with pairs (end time, start time)
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        
        // Sort meetings based on their end times
        sort(meetings.begin(), meetings.end());

        int meetingCount = 1;  // Count the first meeting
        int lastEndTime = meetings[0].first;  // End time of the first meeting

        // Iterate over sorted meetings to find maximum number of meetings
        for (int i = 1; i < n; i++) {
            if (meetings[i].second > lastEndTime) {
                // If the current meeting starts after the last selected meeting ends
                meetingCount++;
                lastEndTime = meetings[i].first;  // Update the last end time
            }
        }
        
        return meetingCount;

    }
};
