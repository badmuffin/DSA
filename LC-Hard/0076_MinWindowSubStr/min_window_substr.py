'''
76. Minimum Window Substring
-------------------------------
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.


Input : s = "ABCAAC", t = "AAC"
Output: "CAA"
'''
class Solution:
  def minWindow(self, s: str, t: str) -> str:
    left, right = 0, 0
    count = len(t)
    start_index = -1
    min_len = float('inf')
    hash = {}

    for ch in t:
      hash[ch] = hash.get(ch, 0) + 1

    while right < len(s):
      if (hash.get(s[right], 0) > 0):
        count -= 1
      hash[s[right]] = hash.get(s[right], 0) - 1
      right += 1

      while count == 0:
        # compare the current size of the window
        if(right - left < min_len):
          min_len = right - left
          start_index = left

        hash[s[left]] = hash.get(s[left], 0) + 1
        if (hash.get(s[left], 0) > 0):
          count += 1

        left += 1

    return "" if start_index == -1 else s[start_index : start_index + min_len]
            
def main():
  s = "ABCAAC"
  t = "AAC"
  
  # instantiate the class
  solution = Solution()
  
  # call the method on the instance
  result = solution.minWindow(s, t)
  print(f'Result {result}')
  
if __name__ == "__main__":
  main()