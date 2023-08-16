#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int OddNumbersFromLeft(std::string cardNumber);
int EvenNumbersFromLeft(std::string cardNumber);
bool Validate(std::string result1, std::string result2);

int main()
{
    std::string cardNumber;
    char firstNumber;
    std::string typeOfCard;
    bool containsNonDigits = true;
    std::string cvv;

    do
    {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Please enter your card number: ";
        std::getline(std::cin, cardNumber);
        std::cout << "Please enter CVV/CVC: ";
        std::getline(std::cin, cvv);
        std::cout << "-------------------------------" << std::endl;
        cardNumber.erase(std::remove_if(cardNumber.begin(), cardNumber.end(), ::isspace), cardNumber.end());
        cvv.erase(std::remove_if(cvv.begin(), cvv.end(), ::isspace), cvv.end());

        for(char c : cardNumber)
        {
            if(isdigit(c))
            {
                containsNonDigits = false;
            }
            else
            {
                containsNonDigits = true;
                std::cout << "*****************************************" << std::endl;
                std::cout << "Card number should only include digits!!!" << std::endl;
                std::cout << "*****************************************" << std::endl;
                break;
            }
        }

        for(char c : cvv)
        {
            if(isdigit(c))
            {
                containsNonDigits = false;
            }
            else
            {
                containsNonDigits = true;
                std::cout << "*************************************" << std::endl;
                std::cout << "CVV/CVC should only include digits!!!" << std::endl;
                std::cout << "*************************************" << std::endl;
                break;
            }
        }

        if(cardNumber.length() < 15)
        {
            std::cout << "********************************************" << std::endl;
            std::cout << "Card number needs to be minimum 15 digits!!!" << std::endl;
            std::cout << "********************************************" << std::endl;
        }
        else if(cardNumber.length() > 19)
        {
            std::cout << "*********************************************" << std::endl;
            std::cout << "Card number can not be more then 19 digits!!!" << std::endl;
            std::cout << "*********************************************" << std::endl;
        }

        if(cvv.length() < 3)
        {
            std::cout << "***************************************" << std::endl;
            std::cout << "CVV/CVC needs to be minimum 3 digits!!!" << std::endl;
            std::cout << "***************************************" << std::endl;
        }
        else if(cvv.length() > 4)
        {
            std::cout << "****************************************" << std::endl;
            std::cout << "CVV/CVC can not be more then 4 digits!!!" << std::endl;
            std::cout << "****************************************" << std::endl;
        }

    } while (cardNumber.length() < 15 || cardNumber.length() > 19 || cvv.length() < 3 || cvv.length() > 4 || containsNonDigits != false);

    firstNumber = cardNumber[0];

    switch (firstNumber)
    {
    case '3':
        typeOfCard = "Type of card: American Express";
        break;
    case '4':
        typeOfCard = "Type of card: Visa";
        break;
    case '5':
        typeOfCard = "Type of card: Mastercard";
        break;
    case '6':
        typeOfCard = "Type of card: Discover";
        break;
    
    default:
        break;
    }

    if((cvv.length() == 3 && typeOfCard == "Type of card: American Express") || (cvv.length() == 4 && typeOfCard != "Type of card: American Express"))
    {
        cvv = "CVV/CVC number is invalid!";
    }
    else
    {
        cvv = "CVV/CVC number is valid!";
    }



    if((OddNumbersFromLeft(cardNumber) + EvenNumbersFromLeft(cardNumber)) % 10 == 0)
    {
        std::cout << "*********************" << std::endl;
        std::cout << "Card number is valid!" << std::endl;
        std::cout << cvv << std::endl;
        std::cout << typeOfCard << std::endl;
        std::cout << "*********************" << std::endl;
    }
    else
    {
        std::cout << "***********************" << std::endl;
        std::cout << "Card number is invalid!" << std::endl;
        std::cout << "***********************" << std::endl;
    }
    

    return 0;
}

int OddNumbersFromLeft(std::string cardNumber)
{
    int temp;
    std::string temp2;
    std::string newNumbers;
    int sum;

    for(int i=1; i < cardNumber.length() + 1; i++)
    {
        if(i % 2 != 0)
        {
            temp = cardNumber[i-1] - '0';
            temp = temp * 2; 
            if(temp > 9)
            {
                temp2 = std::to_string(temp);
                for(int x = 0; x < 2; x++)
                {
                    newNumbers += temp2[x];
                }
            }
            else
            {
                temp2 = std::to_string(temp);
                newNumbers += temp2;
            }
        }
        else
        {
            continue;
        }
    }

    temp = 0;

    for(int i = 0; i < newNumbers.length(); i++)
    {
        temp = newNumbers[i] - '0';
        sum += temp;
    }

    return(sum);
}
int EvenNumbersFromLeft(std::string cardNumber)
{
    int temp;
    int sum;

    for(int i=1; i < cardNumber.length() + 1; i++)
    {
        if(i % 2 == 0)
        {
            temp = cardNumber[i-1] - '0';
            sum += temp;
        }
        else
        {
            continue;
        }
    }

    return(sum);
}