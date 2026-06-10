class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> nums;

        for(auto& tk : tokens){
            char first = tk[0];
            // if(isalnum(static_cast<unsigned char>(first))){ Nie zadziala dla UJEMNYCH
            if(tk.size() > 1 || isdigit(static_cast<unsigned char>(first))){ 
                nums.push(std::stoi(tk));
            }else if(nums.size() >= 2){
                int numsTop = nums.top();
                nums.pop();
                int numsTop2 = nums.top();
                nums.pop();
                int currRes = 1000;
                switch(first){
                    case '+': currRes = numsTop2 + numsTop; break;
                    case '-': currRes = numsTop2 - numsTop; break;
                    case '*': currRes = numsTop2 * numsTop; break;
                    case '/': currRes = numsTop2 / numsTop; break;
                }
                nums.push(currRes);
            }
        }

        return nums.top();
        
    }
};
