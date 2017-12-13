"use strict";
exports.__esModule = true;
// 実際の字句規則
var lex = [
    { token: "DIGITS", pattern: "[1-9][0-9]*" },
    { token: "PLUS", pattern: "+" },
    { token: "ASTERISK", pattern: "*" },
    { token: "LPAREN", pattern: "(" },
    { token: "RPAREN", pattern: ")" },
    { token: null, pattern: "\s" },
    { token: "INVALID", pattern: "." },
];
