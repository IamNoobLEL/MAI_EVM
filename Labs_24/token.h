#include <stdbool.h>
enum Meaning {null, isConstant, isVariable, isOperation, isBracket};
union Value
{
    int constant;
    char operation;
    char* variable;    
};
struct Token
{
    union Value value;
    enum Meaning meaning;
};
struct Token *makeToken (char *);
enum Meaning GetMeaning (char *);
bool isAdditive(struct Token*);
bool isMultiplicative(struct Token*);
bool isAlike (struct Token*, struct Token*);
bool isPrioritized (struct Token*, struct Token*);