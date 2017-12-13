
// 定義
export type Token = string|symbol;
export interface LexDefinitionSection{
	token: Token|null;
	pattern: string|RegExp;
}
export type LexDefinitions = Array<LexDefinitionSection>;

// 実際の字句規則
const lex: LexDefinitions = [
	{token:"DIGITS", pattern:/[1-9][0-9]*/},
	{token:"PLUS", pattern:"+"},
	{token:"ASTERISK", pattern:"*"},
	{token:"LPAREN", pattern:"("},
	{token:"RPAREN", pattern:")"},
	{token:null, pattern:/\s/},
	{token:"INVALID", pattern:/./},
];