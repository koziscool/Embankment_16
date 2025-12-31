
#include <stack>
#include <unordered_map>

long long int problem_014( int limit ){
    std::unordered_map<int, long long int> collatzMap;
    std::stack<int> collatzChain;

    collatzMap[1] = 1;
    long long int longestChain = 1, longestIndex = 1, currentKey, 
        newKey, anchorLength, extraLinks;
    int index = 1;

    while( index < limit ){
        currentKey = index;

        while( collatzMap.find(currentKey) == collatzMap.end() ) {
            collatzChain.push(currentKey);
            if( currentKey % 2 == 0){
                currentKey /= 2;
            } else {
                currentKey = 3 * currentKey + 1;
            }
        }

        extraLinks = 1;
        anchorLength = collatzMap.find(currentKey)->second;

        while( collatzChain.size() > 0 ){
            newKey = collatzChain.top();
            collatzChain.pop();
            collatzMap[newKey] = anchorLength + extraLinks;
            if( anchorLength + extraLinks > longestChain && newKey < limit ) {
                longestChain = anchorLength + extraLinks;
                longestIndex = newKey;
            }
            extraLinks++;
        }
        index++;
    }

    return longestIndex;
}
