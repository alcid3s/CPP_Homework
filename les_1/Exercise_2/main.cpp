#include <iostream>
#include <string>

#define charToInt 48

bool startsWith(const std::string& cardNumber, const std::string& substr) {
  return cardNumber.starts_with(substr);
}

int getDigit(int number) {
  if(number > 9) {
    return number - 9;
  } else {
    return number;
  }
}

int sumOfDoubleEvenPlace(const std::string& cardNumber) {
  int sum = 0;
  for(int i = cardNumber.length() - 2; i >= 0; i-=2) {
    int digit = cardNumber.at(i) - charToInt;
    digit *= 2;
    sum += getDigit(digit);
  }
  return sum;
}

int sumOfOddPlace(const std::string& cardNumber) {
  int sum = 0;
  for(int i = cardNumber.length() - 1; i >= 0; i -= 2) {
    sum += cardNumber.at(i) - charToInt;
  }

  return sum;
}

bool isValid(const std::string& cardNumber) {
  if(cardNumber.length() < 13 || cardNumber.length() > 16) {
    return false;
  }

  std::cout << "size of creditcard is ok\n";

  if(!startsWith(cardNumber, "4") && !startsWith(cardNumber, "5") && !startsWith(cardNumber, "37") && !startsWith(cardNumber, "6")) {
    return false;
  }  

  std::cout << "beginnings are fine as well\n";

  int sumEven = sumOfDoubleEvenPlace(cardNumber);
  int sumUneven = sumOfOddPlace(cardNumber);
  int sums = sumEven + sumUneven;

  std::cout << "total sum: " << sums << " modulus: " << sums % 10 << "\n";
  return sums % 10 == 0;
}


int main()
{
  std::string badCreditcard = "4388576018402626";
  std::string goodCreditcard = "4388576018410707";

  std::cout << "starting with isValid\n";
  if(isValid(goodCreditcard)) {
    std::cout << "good creditcard\n";
  } else {
    std::cout << "bad creditcard\n";
  }
  return 0;
}
