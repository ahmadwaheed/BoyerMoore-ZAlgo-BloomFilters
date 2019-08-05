#include "RandomMatrixHash.h"

RandomMatrixHash::RandomMatrixHash(unsigned int m) {
    
    int my_Min_int = std::numeric_limits<int>::min()
    int my_Max_int = std::numeric_limits<int>::max()
    
    int b = log(m)/log(2);
    int num_ints = my_Max_int - my_Min_int;
    int u = log(num_ints)/log(2);
    
    int matrix[b][u];
    int a, c;
    
    for(a=0;a<=b;a++){
        for(c=0;c<=u;c++){
            auto random_value = Random::get({0, 1});
            matrix[a][b] = random_value;
        }
    }
    
    // We need to convert the values into binary     
    std::vector<int>
}  //This function will create the matrix

// Use mod 2 matrix multiplication for your hash function.
size_t RandomMatrixHash::Hash(int key) const {
    
    
    std::string binaryKey = std::bitset<u>(key).to_string();
    int binaryKeyArray[u];
    int newKeyArray[b];
    for (int i = 0; i < binary.length(); i++)
    {
        binaryKeyArray[i] = binaryKey[i];
    }
    
    for (int j = 0; j < b; j++)
    {
        int sum = 0;
        `         for (int k = 0; k < u; k++)
        {
            sum += matrix[j][k] * binaryArray[k];
        }
        newKeyArray[i] = (sum % 2);
    }

    
    
    
}  // This function will multiply matrix with the key and after %2 it will return new key
