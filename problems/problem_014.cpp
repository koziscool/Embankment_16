
#include <stack>
#include <unordered_map>

long long int problem_014( int limit ){
    std::unordered_map<long long, long long> collatzMap;
    std::stack<long long> collatzChain;

    collatzMap[1] = 1;
    long long longestChain = 1, longestIndex = 1, currentKey,
        newKey, anchorLength, extraLinks;
    int index = 1;

    while( index < limit ){
        currentKey = index;

        auto it = collatzMap.find(currentKey);
        while( it == collatzMap.end() ) {
            collatzChain.push(currentKey);
            if( currentKey & 1 ){  // Odd
                currentKey = 3 * currentKey + 1;
            } else {  // Even
                currentKey >>= 1;
            }
            it = collatzMap.find(currentKey);
        }

        extraLinks = 1;
        anchorLength = it->second;  // Reuse cached iterator

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
