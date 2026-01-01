

#include <map>
#include <functional>

// Forward declarations
int problem_001(int limit);
int problem_002(int limit);
long long problem_003(long long n);
int problem_004(int numDigits);
long long problem_005(int n);
long long int problem_006( int limit );
long long int problem_007( int limit );
long long int problem_010( int limit );
long long int problem_012( int limit );
long long int problem_014( int limit );
long long int problem_015( int limit );
long long int problem_016( int limit );
int problem_020( int limit );
int problem_025( int limit );
long long int problem_028( int gridSize );
long long int problem_029(int limit);
long long int problem_040();
long long int problem_043();
long long int problem_046();
int problem_053( int limit );
int problem_055( int problemLimit );
int problem_056(int limit);
int problem_071(int limit);
long long int problem_073(int limit);


// Map from problem number to function (uniform signature: long long())
const std::map<int, std::function<long long()>> PROBLEM_MAP = {
    {1,  []() { return problem_001(1000); }},
    {2,  []() { return problem_002(4000000); }},
    {3,  []() { return problem_003(600851475143LL); }},
    {4,  []() { return problem_004(3); }},
    {5,  []() { return problem_005(20); }},
    {6,  []() { return problem_006(100); }},
    {7,  []() { return problem_007(10'001); }},
    {10, []() { return problem_010(2'000'000); }},
    {12, []() { return problem_012(500); }},
    {14, []() { return problem_014(1'000'000); }},
    {15, []() { return problem_015(20); }},
    {16, []() { return problem_016(1'000); }},
    {20, []() { return problem_020(100); }},
    {25, []() { return problem_025(1000); }},
    {28, []() { return problem_028(1001); }},
    {29, []() { return problem_029(100); }},
    {40, []() { return problem_040(); }},
    {43, []() { return problem_043(); }},
    {46, []() { return problem_046(); }},
    {53, []() { return problem_053(100); }},
    {55, []() { return problem_055(10'000); }},
    {56, []() { return problem_056(100); }},
    {71, []() { return problem_071(1'000'000); }},
    {73, []() { return problem_073(12'000); }}
};
