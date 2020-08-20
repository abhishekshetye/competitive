class Solution {
public:

	set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	

	string toGoatLatin(string S) {
		vector<string> ans;
		bool first = true, shouldAdd = true;
		string suffix = "", a = "a", word = "";
		
		for (int i = 0; i < S.size(); ++i) {

			if (S[i] == ' ') {
				word += suffix;
				if (shouldAdd) {
					word += a;
					a += "a";
				}
				suffix = "";
				first = true;
				shouldAdd = false;
				ans.push_back(word + " ");
				word = "";
			}
			else if (first) {
				string curr {S[i]};
				suffix = (vowels.find(S[i]) != vowels.end()) ? "ma" : (curr + "ma");
				word = (vowels.find(S[i]) != vowels.end()) ? curr : "";
				first = false;
				shouldAdd = true;
			} else 
				word += S[i];
		}
		
		if (word.size() != 0 || suffix.size() != 0) {
			word += suffix;
			word += a;
			ans.push_back(word);
		}

		string result = "";
		for (int i = 0; i < ans.size(); ++i)
			result += ans[i];
		

		return result;

	}
};