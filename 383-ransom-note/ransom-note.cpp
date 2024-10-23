class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //Create a hashmap to store character frequencies from the magazine
        unordered_map<char, int> mag;

        // Count the occurrences of each character in the magazine
        for (auto it : magazine) {
            mag[it]++;
        }

        //Try to match each character of the ransomNote with the magazine
        for (int i = 0; i < ransomNote.length(); i++) {
            if (mag.find(ransomNote[i]) != mag.end()) {
                mag[ransomNote[i]]--;   //Decrease the count of the character in the map
            } else {
                return false;  //If the character is not found, return false
            }
        }

        
       
        for (auto &it : mag) {
            if (it.second < 0) {    //Ensure that no character count has gone negative
                return false;       //If a character count is negative, it means we used more than available
            }
        }

        return true;    //If all checks pass, return true
    }
};