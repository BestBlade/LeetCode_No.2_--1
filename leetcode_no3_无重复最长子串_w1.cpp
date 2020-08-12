/*--------------------------------------------------------------------------------------|
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。							|
																						|
示例 1:																					|
																						|
输入: "abcabcbb"																		|
输出: 3																					|
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。								|
示例 2:																					|
																						|
输入: "bbbbb"																			|
输出: 1																					|
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。									|
示例 3:																					|
																						|
输入: "pwwkew"																			|
输出: 3																					|
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。								|
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。				|
																						|
来源：力扣（LeetCode）																	|
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters	|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。					|
---------------------------------------------------------------------------------------*/

/*	遍历方法暴力破解
*	执行用时：1224 ms, 在所有 C++ 提交中击败了5.02%的用户
*	内存消耗：6.9 MB, 在所有 C++ 提交中击败了91.59%的用户
*/

#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
	int result = { 0 };
	int length = s.length();
	int slength = { 1 };

	if (!length)
	{
		return length;
	}

	if (length == 2)
	{
		if (s[0] == s[1])
			return length - 1;
		else
			return length;
	}

	for (int start = 0; start < length - 1; start++)
	{
		for (int end = start + 1; end < length; end++)
		{
			for (int i = start; i < end; i++)
			{
				if (s[end] == s[i])
				{
					slength = end - start;
					result = max(result, slength);
					start++;
					end = start;
					break;
				}
				if ((i == length - 2) && (s[end] != s[i]))
				{
					slength = end - start + 1;
					result = max(result, slength);
					start++;
					end = start;
					break;
				}
			}
		}
	}

	return max(result, slength);
}

int main()
{
	string str1 = "abcabcbb";
	string str2 = "bbbbb";
	string str3 = "pwwkew";

	int result1 = lengthOfLongestSubstring(str1);
	int result2 = lengthOfLongestSubstring(str2);
	int result3 = lengthOfLongestSubstring(str3);

	cout << result1 << result2 << result3 << endl;

	return 0;

}