#include <iostream>
#include <vector>
using namespace std;

// A vector is an array of a non fixed size, growing when needed

int main(int argc, char const *argv[])
{
    vector<int> surveyData;
    // Reserve space to avoid frequent resizing
    surveyData.reserve(30);
    int surveyResponse;

    // Gather user input
    cout << "Enter survey response or -1 to end: ";
    cin >> surveyResponse;
    while (surveyResponse != -1)
    {
        // Add response to the vector
        surveyData.push_back(surveyResponse);
        cout << "Enter survey response or -1 to end: ";
        cin >> surveyResponse;
    }

    // Find new size of the vector
    int vectorSize = surveyData.size();

    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    // create a histogram of 0 values
    for (int i = 0; i < MAX_RESPONSE; i++)
    {
        histogram[i] = 0;
    }
    for (int i = 0; i < vectorSize; i++)
    {
        histogram[surveyData[i] - 1]++;
    }

    int mostFrequent = 0;
    for (int i = 0; i < MAX_RESPONSE; i++)
    {
        if (histogram[i] > histogram[mostFrequent]) mostFrequent = i;
        
    }
    mostFrequent++;

    cout << mostFrequent << endl;
    
    
    
    


    return 0;
}
