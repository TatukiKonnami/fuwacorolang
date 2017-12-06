#ifndef LEXER_H
#define LEXER_H

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "APP.hpp"

enum TokenType{
    TOK_IDENTIFER,
    TOK_NUMBER,
    TOK_SYMBOL,
    TOK_INT,
    TOK_FLOAT,
    TOK_BOOL,
    TOK_STRING,
    TOK_OBJEXT,
    TOK_IF,
    TOK_SWITCH,
    TOK_FOR,
    TOK_WHILE,
    TOK_RETURN,
    TOK_EOF
};

/**
 * 個別トークン格納クラス 
 */
class Token{
private:
    TokenType Type; // Token Kind
    std::string TokenString; //Token String
    int Line; //Tokenがでた行数

    int Number;

public:
    Token(std::string string, TokenType type, int line)
        : TokenString(string), Type(type), Line(line)
    {
        if (type == TOK_NUMBER)
            Number = atoi(string.c_str());
        else
            Number = 0x7fffffff;
    };

~Token(){};

/**
 * 個別トークンの色々を取得する関数
*/
TokenType getTokenType(){return Type;};
std::string getTokenString(){return TokenString;};
int getNumberValue(){return Number;};
int getLine(){return Line;};

};

/**
 * 切り出したToken格納クラス
*/
class TokenStream{
    private:
        std::vector<Token*> Tokens; //Token格納ベクタ
        int CurIndex; // 呼び出し対象のTokenのインデックス

    public:
        TokenStream():CurIndex(0){}
        ~TokenStream();

        bool ungetToken(int Times=1);
        bool getNextToken();
        bool pushToken(Token *token){
            Tokens.push_back(token); //要素を末尾に加える
            return true;
        }
        Token getToken();

        // Tokenの種類を取得
        TokenType getCurType(){return Tokens[CurIndex] -> getTokenType();}
        // Tokenの文字列表現を取得
        std::string getCurString(){return Tokens[CurIndex] -> getTokenString();}
        // Tokenの数値を取得
        int getCurNumVal(){return Tokens[CurIndex] -> getNumberValue();}
        // 現在のインデックスを取得
        int getCurIndex(){return CurIndex;}
        // インデックスを指定した値に設定(debug用)
        bool applyTokenIndex(int index){
            CurIndex = index;
            return true;
            }
        bool printToken(); // Tokenの出力

};

/**
  * デストラクタ
  */
TokenStream::~TokenStream(){
    for(int i=0; i<Tokens.size(); i++){
        SAFE_DELETE(Tokens[i]);
    }
    Tokens.clear();
}

/**
 * トークン取得
 * @return CureIndex番目のToken
 */
Token TokenStream::getToken(){
    return *Tokens[CurIndex];
}

/**
 * 次のトークンに進む
 *  @return 成功:true 失敗:false
 */
bool TokenStream::getNextToken(){
    int size=Tokens.size();
    if(--size<=CurIndex){
        return false;
    }else{
        CurIndex++;
        return true;
    }
}

/**
 * インデックスをtimes回戻す
 * @return true
 */
bool TokenStream::ungetToken(int times){
    for(int i=0; i<times; i++){
        if(CurIndex == 0)
            return false;
        else 
            CurIndex--;
    }
    return true;
}

/**
 * 格納されたトークン一覧を表示
 */
bool TokenStream::printToken(){
    std::vector<Token*>::iterator titer = Tokens.begin();
    while( titer != Tokens.end() ){
        fprintf(stdout, "%d:", (*titer)->getTokenType());
        if((*titer)->getTokenType()!=TOK_EOF)
            fprintf(stdout, "%s\n", (*titer)->getTokenString().c_str());
        ++titer;
    }
    return true;
}


#endif