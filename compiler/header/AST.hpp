#ifndef AST_HPP
#define AST_HPP


#include <string>
#include <map>
#include <vector>
#include "llvm/Support/Casting.h"
#include "APP.hpp"

enum AstID
{
    BaseID
};

/**
 * ASTの基底クラス
 */
class BaseAST{
    AstID ID;

    public:
    BaseAST(AstID id):ID(id){}
    virtual ~BaseAST(){}
    AstID getValueID() const {return ID;}
};