#include "laxter.hpp"
/**
 * トークン切り出し関数
 * @param 字句解析対象ファイル名
 * @return 切り出したトークンを格納したTokenStream
 */
TokenStream *LexicalAnalysis(std::string input_fileName){
    TokenStream *tokens=new TokenStream();
    std::ifstream ifs;
    std::string cur_line;
    std::string token_str;
    int line_num=0;
    bool iscoment=false;

    ifs.open(input_fileName.c_str(), std::ios::in);
    if(!ifs)
        return NULL;
    while(ifs && getline(ifs, cur_line)){
        char next_char;
        std::string line;
        Token *next_token;
        int index = 0;
        int length = cur_line.length();

        while(index<length){
            next_char = cur_line.at(index++);

            // コメントを無視
            if(iscomment){
                if( (length-index < 2
                    || (cur_line.at(index) != '*')
                    || (cur_line.at(index++) != '/') ){
                        continue;
                    }else{
                        iscomment=false;
                    }
            }

            // EOF 
            if(next_char == EOF){
                token_str = EOF;
                next_token = new Token(token_str, TOK_EOF, line_num);
            }else if(isspace(next_char)){ 
                continue;

            // IDENTOFIER
            } else if(isspace(next_char)){
                token_str += next_char;
                next_char = cur_line.at(index++);
                while(isalnum(next_char)){
                    token_str += next_char;
                    next_char = cur_line.at(index++);
                    if(index==length)
                        break;
                }
                index--;

                if(token_str == "int"){
                    next_token = new Token(token_str, TOK_INT, line_num);
                }else if(token_str == "return"){
                    next_token = new Token(token_str, TOK_RETURN, line_num)
                }
            }
        }
    }
}
