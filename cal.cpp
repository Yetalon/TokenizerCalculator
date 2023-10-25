#include <iostream>
#include <vector>
#include <string>
#include <cmath>
enum operators{
  Plus = 1,
  Minus = 2,
  Multiply = 3,
  Divide = 4,
  Sqrt = 5,
  Power = 6,
  Decimal = 7,
  frontbrace = 8,
  backbrace = 9,

};

struct StrToOp
{
  std::string character;
  operators name;
};

std::vector<std::string> input(std::string usersinput){
  std::vector<std::string> tokens;
  std::string temp = "";

 StrToOp Operatorfinder[] = {
    {"+", Plus},
    {"-", Minus},
    {"*", Multiply},
    {"/", Divide},
    {"sqrt", Sqrt},
    {"^", Power},
    {".", Decimal},
    {"(", frontbrace},
    {")", backbrace}
};


  for(int i = 0; i < usersinput.length(); i++){
    if(isdigit(usersinput[i]) || usersinput[i] == '.'){
      temp += usersinput[i];
    }
    
    else {
      if(!temp.empty()){
        tokens.push_back(temp);
        temp.clear();
      }



      for (int j = 0; j < sizeof(Operatorfinder) / sizeof(Operatorfinder[0]); j++) {
        if (usersinput.substr(i, Operatorfinder[j].character.length()) == Operatorfinder[j].character) {
          tokens.push_back(Operatorfinder[j].character);
          i += Operatorfinder[j].character.length() - 1;
          temp.clear();  
          break;
    }
}

      
    if(!temp.empty()){
      tokens.push_back(temp);
    }

  }
}

if (!temp.empty()) {
        tokens.push_back(temp);
        temp.clear();
    }

return tokens;
}

std::vector<std::string> MultFunc(std::vector<std::string> &inputs){
  
  
  for(int i = 0; i < inputs.size(); i++){
     std::string& token = inputs[i];
    if(token == "*"){
      if(i > 0 && i + 1 < inputs.size()){
        double number1 = std::stod(inputs[i-1]);
        double number2 = std::stod(inputs[i+1]);
        double results = number1 * number2;
        std::string StrToRes = std::to_string(results);
        // Remove the two numbers and the operator from the vector
            inputs.erase(inputs.begin() + i - 1, inputs.begin() + i + 2);

            // Insert the result back into the vector at position i - 1
            inputs.insert(inputs.begin() + i - 1, StrToRes);
        i--;
      }

    }
    
}
return inputs;
}
std::vector<std::string> DivFunc (std::vector<std::string> &inputs){
  
  
for(int i = 0; i < inputs.size(); i++){
     std::string& token = inputs[i];
    if(token == "/"){
      if(i > 0 && i + 1 < inputs.size()){
        double number1 = std::stod(inputs[i-1]);
        double number2 = std::stod(inputs[i+1]);
        double results = number1 / number2;
        std::string StrToRes = std::to_string(results);
        // Remove the two numbers and the operator from the vector
            inputs.erase(inputs.begin() + i - 1, inputs.begin() + i + 2);

            // Insert the result back into the vector at position i - 1
            inputs.insert(inputs.begin() + i - 1, StrToRes);
        i--;
      }

    }
    
}
return inputs;
}
std::vector<std::string> AddFunc(std::vector<std::string> &inputs){
  
  
for(int i = 0; i < inputs.size(); i++){
     std::string& token = inputs[i];
    if(token == "+"){
      if(i > 0 && i + 1 < inputs.size()){
        double number1 = std::stod(inputs[i-1]);
        double number2 = std::stod(inputs[i+1]);
        double results = number1 + number2;
        std::string StrToRes = std::to_string(results);
        // Remove the two numbers and the operator from the vector
            inputs.erase(inputs.begin() + i - 1, inputs.begin() + i + 2);

            // Insert the result back into the vector at position i - 1
            inputs.insert(inputs.begin() + i - 1, StrToRes);
        i--;
      }

    }
    
}
return inputs;
}
std::vector<std::string> MinusFunc(std::vector<std::string> &inputs){
  
  
for(int i = 0; i < inputs.size(); i++){
     std::string& token = inputs[i];
    if(token == "-"){
      if(i > 0 && i + 1 < inputs.size()){
        double number1 = std::stod(inputs[i-1]);
        double number2 = std::stod(inputs[i+1]);
        double results = number1 - number2;
        std::string StrToRes = std::to_string(results);
        // Remove the two numbers and the operator from the vector
            inputs.erase(inputs.begin() + i - 1, inputs.begin() + i + 2);

            // Insert the result back into the vector at position i - 1
            inputs.insert(inputs.begin() + i - 1, StrToRes);
        i--;
      }

    }
    
}
return inputs;
}





int main(){
std::string equation;
std::getline(std::cin, equation);
std::vector<std::string> alltokens = input(equation);

std::vector<std::string> FM1 = MultFunc(alltokens);
std::vector<std::string> FM2 = DivFunc(FM1);
std::vector<std::string> FM3 = AddFunc(FM2);
std::vector<std::string> FM4 = MinusFunc(FM3);

  for(int i=0; i<FM4.size();i++){
    std::cout << FM4[i]<<"\n";
  }

return 0;
}