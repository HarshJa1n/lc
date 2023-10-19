class Solution {
public:
    string textEditorOutput(string inp){
        string stack;
        for (char c: inp){
            if (c == '#'){
                if (stack.size() > 0) stack.pop_back();
            }
            else stack.push_back(c);
        }
        return stack;

    }
    bool backspaceCompare(string s, string t) {
        return textEditorOutput(s) == textEditorOutput(t);
    }
};