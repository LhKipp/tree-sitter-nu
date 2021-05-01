[1mdiff --git a/grammar.js b/grammar.js[m
[1mindex 00d08db..c829944 100644[m
[1m--- a/grammar.js[m
[1m+++ b/grammar.js[m
[36m@@ -200,11 +200,15 @@[m [mmodule.exports = grammar({[m
         repeat(seq('.', $.identifier))[m
     ),[m
 [m
[31m-    file_path: $ => choice([m
[31m-        // '-', //previous pwd (conflicts with operator)[m
[31m-        /\s\.\.|\.\s/, [m
[31m-        /(([\w\.]+\/)*)([\w\.]+)\.\w+/, //filepath must end with <.file_ending> for now[m
[31m-    ),[m
[32m+[m[32m    file_path: $ => {[m
[32m+[m[32m        const ws_no_newline = RegExp('[^\S\r\n]+')[m
[32m+[m[32m        const current_dir_or_parent = RegExp('\.|\.\.')[m
[32m+[m[32m        return choice([m
[32m+[m[32m            // '-', //previous pwd (conflicts with operator)[m
[32m+[m[32m            RegExp(ws_no_newline.source + current_dir_or_parent.source + ws_no_newline.source),[m
[32m+[m[32m            /(([\w\.]+\/)*)([\w\.]+)\.\w+/, //filepath must end with <.file_ending> for now[m
[32m+[m[32m        );[m
[32m+[m[32m    },[m
 [m
     range: $ => seq([m
         $.number_literal,[m
[1mdiff --git a/src/grammar.json b/src/grammar.json[m
[1mindex e3d2937..edbd257 100644[m
[1m--- a/src/grammar.json[m
[1m+++ b/src/grammar.json[m
[36m@@ -608,7 +608,7 @@[m
       "members": [[m
         {[m
           "type": "PATTERN",[m
[31m-          "value": "\\s\\.\\.|\\.\\s"[m
[32m+[m[32m          "value": "[^S\\r\\n]+.|..[^S\\r\\n]+"[m
         },[m
         {[m
           "type": "PATTERN",[m
[1mdiff --git a/src/parser.c b/src/parser.c[m
[1mindex c2f2aad..7b2d3ad 100644[m
[1m--- a/src/parser.c[m
[1m+++ b/src/parser.c[m
[36m@@ -6,7 +6,7 @@[m
 #endif[m
 [m
 #define LANGUAGE_VERSION 13[m
[31m-#define STATE_COUNT 246[m
[32m+[m[32m#define STATE_COUNT 360[m
 #define LARGE_STATE_COUNT 2[m
 #define SYMBOL_COUNT 97[m
 #define ALIAS_COUNT 0[m
[36m@@ -808,1696 +808,6708 @@[m [mstatic bool ts_lex(TSLexer *lexer, TSStateId state) {[m
   eof = lexer->eof(lexer);[m
   switch (state) {[m
     case 0:[m
[31m-      if (eof) ADVANCE(42);[m
[31m-      if (lookahead == '!') ADVANCE(74);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '%') ADVANCE(130);[m
[31m-      if (lookahead == '&') ADVANCE(73);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == '(') ADVANCE(53);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(126);[m
[31m-      if (lookahead == '+') ADVANCE(123);[m
[31m-      if (lookahead == ',') ADVANCE(47);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(94);[m
[31m-      if (lookahead == '/') ADVANCE(128);[m
[31m-      if (lookahead == ':') ADVANCE(50);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[31m-      if (lookahead == '<') ADVANCE(146);[m
[31m-      if (lookahead == '=') ADVANCE(63);[m
[31m-      if (lookahead == '>') ADVANCE(140);[m
[31m-      if (lookahead == '?') ADVANCE(52);[m
[31m-      if (lookahead == '[') ADVANCE(45);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == ']') ADVANCE(48);[m
[31m-      if (lookahead == 'd') ADVANCE(75);[m
[31m-      if (lookahead == 'l') ADVANCE(76);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '|') ADVANCE(65);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32m      if (eof) ADVANCE(87);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(124);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(134);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(231);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(144);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(254);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(123);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(136);[m
[32m+[m[32m      if (lookahead == '(') ADVANCE(100);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(101);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(248);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(243);[m
[32m+[m[32m      if (lookahead == ',') ADVANCE(93);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(245);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(148);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(251);[m
[32m+[m[32m      if (lookahead == ':') ADVANCE(97);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(221);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(278);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(111);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(269);[m
[32m+[m[32m      if (lookahead == '?') ADVANCE(99);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(90);[m
[32m+[m[32m      if (lookahead == '\\') ADVANCE(77);[m
[32m+[m[32m      if (lookahead == ']') ADVANCE(94);[m
[32m+[m[32m      if (lookahead == 'd') ADVANCE(125);[m
[32m+[m[32m      if (lookahead == 'l') ADVANCE(126);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(224);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(113);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(226);[m
       if (lookahead == '\t' ||[m
           lookahead == '\n' ||[m
           lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(5);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);[m
[31m-      if (lookahead != 0) ADVANCE(83);[m
[32m+[m[32m          lookahead == ' ') SKIP(0)[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(119);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(133);[m
       END_STATE();[m
     case 1:[m
[31m-      if (lookahead == '\n') ADVANCE(119);[m
[31m-      if (lookahead == '!') ADVANCE(23);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '%') ADVANCE(129);[m
[31m-      if (lookahead == '&') ADVANCE(13);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(125);[m
[31m-      if (lookahead == '+') ADVANCE(122);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(96);[m
[31m-      if (lookahead == '/') ADVANCE(127);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[31m-      if (lookahead == '<') ADVANCE(147);[m
[31m-      if (lookahead == '=') ADVANCE(24);[m
[31m-      if (lookahead == '>') ADVANCE(141);[m
[31m-      if (lookahead == '[') ADVANCE(45);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '|') ADVANCE(66);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(232);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(151);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(171);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(227);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(1);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);[m
[32m+[m[32m          lookahead == ' ') ADVANCE(150);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
       if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(104);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 2:[m
[31m-      if (lookahead == '\n') ADVANCE(121);[m
[31m-      if (lookahead == '!') ADVANCE(23);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '%') ADVANCE(129);[m
[31m-      if (lookahead == '&') ADVANCE(13);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(125);[m
[31m-      if (lookahead == '+') ADVANCE(122);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(19);[m
[31m-      if (lookahead == '/') ADVANCE(127);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[31m-      if (lookahead == '<') ADVANCE(147);[m
[31m-      if (lookahead == '=') ADVANCE(24);[m
[31m-      if (lookahead == '>') ADVANCE(141);[m
[31m-      if (lookahead == '[') ADVANCE(45);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '|') ADVANCE(66);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(232);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(3);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(218);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(227);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(2);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);[m
[32m+[m[32m          lookahead == ' ') ADVANCE(1);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
       if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(104);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 3:[m
[31m-      if (lookahead == ' ') ADVANCE(113);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == ',') ADVANCE(46);[m
[31m-      if (lookahead == '.') ADVANCE(93);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(232);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(4);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(227);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r') SKIP(3)[m
[32m+[m[32m          lookahead == ' ') ADVANCE(1);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 4:[m
[31m-      if (lookahead == ' ') ADVANCE(113);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == ',') ADVANCE(46);[m
[31m-      if (lookahead == '.') ADVANCE(21);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(232);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(4);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(227);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r') SKIP(4)[m
[32m+[m[32m          lookahead == ' ') ADVANCE(150);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 5:[m
[31m-      if (lookahead == '!') ADVANCE(74);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '%') ADVANCE(130);[m
[31m-      if (lookahead == '&') ADVANCE(73);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == '(') ADVANCE(53);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(126);[m
[31m-      if (lookahead == '+') ADVANCE(123);[m
[31m-      if (lookahead == ',') ADVANCE(47);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(94);[m
[31m-      if (lookahead == '/') ADVANCE(128);[m
[31m-      if (lookahead == ':') ADVANCE(50);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[31m-      if (lookahead == '<') ADVANCE(146);[m
[31m-      if (lookahead == '=') ADVANCE(63);[m
[31m-      if (lookahead == '>') ADVANCE(140);[m
[31m-      if (lookahead == '?') ADVANCE(52);[m
[31m-      if (lookahead == '[') ADVANCE(45);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == ']') ADVANCE(48);[m
[31m-      if (lookahead == 'd') ADVANCE(75);[m
[31m-      if (lookahead == 'l') ADVANCE(76);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '|') ADVANCE(65);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32m      if (lookahead == '\n') SKIP(6)[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(181);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(171);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == ']') ADVANCE(95);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(198);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(5);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);[m
[31m-      if (lookahead != 0) ADVANCE(83);[m
[32m+[m[32m          lookahead == ' ') ADVANCE(179);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 6:[m
[31m-      if (lookahead == '!') ADVANCE(23);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '%') ADVANCE(129);[m
[31m-      if (lookahead == '&') ADVANCE(13);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(125);[m
[31m-      if (lookahead == '+') ADVANCE(122);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(15);[m
[31m-      if (lookahead == '/') ADVANCE(127);[m
[31m-      if (lookahead == '<') ADVANCE(147);[m
[31m-      if (lookahead == '=') ADVANCE(24);[m
[31m-      if (lookahead == '>') ADVANCE(141);[m
[31m-      if (lookahead == '[') ADVANCE(45);[m
[31m-      if (lookahead == ']') ADVANCE(48);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '|') ADVANCE(29);[m
[32m+[m[32m      if (lookahead == '\n') SKIP(6)[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(7);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(218);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == ']') ADVANCE(95);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(70);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(7);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);[m
[32m+[m[32m          lookahead == ' ') ADVANCE(5);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
       if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(104);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 7:[m
[31m-      if (lookahead == '!') ADVANCE(23);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '%') ADVANCE(129);[m
[31m-      if (lookahead == '&') ADVANCE(13);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(125);[m
[31m-      if (lookahead == '+') ADVANCE(122);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(18);[m
[31m-      if (lookahead == '/') ADVANCE(127);[m
[31m-      if (lookahead == '<') ADVANCE(147);[m
[31m-      if (lookahead == '=') ADVANCE(24);[m
[31m-      if (lookahead == '>') ADVANCE(141);[m
[31m-      if (lookahead == '[') ADVANCE(45);[m
[31m-      if (lookahead == ']') ADVANCE(48);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '|') ADVANCE(29);[m
[32m+[m[32m      if (lookahead == '\n') SKIP(6)[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(8);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == ']') ADVANCE(95);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(70);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(7);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);[m
[32m+[m[32m          lookahead == ' ') ADVANCE(5);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
       if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(104);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 8:[m
[31m-      if (lookahead == '!') ADVANCE(23);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '%') ADVANCE(129);[m
[31m-      if (lookahead == '&') ADVANCE(13);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(125);[m
[31m-      if (lookahead == '+') ADVANCE(122);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(93);[m
[31m-      if (lookahead == '/') ADVANCE(127);[m
[31m-      if (lookahead == '<') ADVANCE(147);[m
[31m-      if (lookahead == '=') ADVANCE(24);[m
[31m-      if (lookahead == '>') ADVANCE(141);[m
[31m-      if (lookahead == ']') ADVANCE(48);[m
[31m-      if (lookahead == '|') ADVANCE(29);[m
[32m+[m[32m      if (lookahead == '\n') SKIP(6)[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(8);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == ']') ADVANCE(95);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(198);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') SKIP(8)[m
[32m+[m[32m          lookahead == ' ') ADVANCE(179);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
       if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 9:[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(86);[m
[31m-      if (lookahead == '\\') ADVANCE(36);[m
[32m+[m[32m      if (lookahead == '\n') SKIP(10)[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(182);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(171);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(198);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(87);[m
[31m-      if (lookahead != 0) ADVANCE(88);[m
[32m+[m[32m          lookahead == ' ') ADVANCE(180);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 10:[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '(') ADVANCE(53);[m
[31m-      if (lookahead == ',') ADVANCE(46);[m
[31m-      if (lookahead == '-') ADVANCE(14);[m
[31m-      if (lookahead == '.') ADVANCE(22);[m
[31m-      if (lookahead == ':') ADVANCE(49);[m
[31m-      if (lookahead == '?') ADVANCE(51);[m
[31m-      if (lookahead == ']') ADVANCE(48);[m
[32m+[m[32m      if (lookahead == '\n') SKIP(10)[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(11);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(218);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(70);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') SKIP(10)[m
[32m+[m[32m          lookahead == ' ') ADVANCE(9);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
       if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 11:[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[32m+[m[32m      if (lookahead == '\n') SKIP(10)[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(12);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(70);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') SKIP(11)[m
[31m-      if (lookahead != 0 &&[m
[31m-          (lookahead < '"' || '$' < lookahead) &&[m
[31m-          (lookahead < '\'' || ')' < lookahead) &&[m
[31m-          lookahead != '-' &&[m
[31m-          lookahead != ';' &&[m
[31m-          (lookahead < '[' || ']' < lookahead) &&[m
[31m-          lookahead != '{' &&[m
[31m-          lookahead != '}') ADVANCE(83);[m
[32m+[m[32m          lookahead == ' ') ADVANCE(9);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 12:[m
[31m-      if (lookahead == '#') ADVANCE(89);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == '\\') ADVANCE(35);[m
[32m+[m[32m      if (lookahead == '\n') SKIP(10)[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(12);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(198);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(90);[m
[31m-      if (lookahead != 0) ADVANCE(91);[m
[32m+[m[32m          lookahead == ' ') ADVANCE(180);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 13:[m
[31m-      if (lookahead == '&') ADVANCE(133);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(234);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(153);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(102);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(171);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(152);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 14:[m
[31m-      if (lookahead == '-') ADVANCE(30);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(234);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(15);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(102);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(218);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(13);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 15:[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(234);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(16);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(102);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(97);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(13);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 16:[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(234);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(16);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(102);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(152);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 17:[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(235);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(155);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(171);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(154);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 18:[m
[31m-      if (lookahead == '.') ADVANCE(98);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(235);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(19);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(42);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(97);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(17);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 19:[m
[31m-      if (lookahead == '.') ADVANCE(102);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(235);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(19);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(169);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
       if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(97);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(154);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 20:[m
[31m-      if (lookahead == '.') ADVANCE(26);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(236);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(157);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(171);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(156);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 21:[m
[31m-      if (lookahead == '.') ADVANCE(100);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(236);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(22);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(20);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 22:[m
[31m-      if (lookahead == '.') ADVANCE(20);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(236);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(22);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(156);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 23:[m
[31m-      if (lookahead == '=') ADVANCE(138);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(237);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(159);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(171);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(227);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(158);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 24:[m
[31m-      if (lookahead == '=') ADVANCE(137);[m
[31m-      if (lookahead == '~') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(237);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(25);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(218);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(227);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(23);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 25:[m
[31m-      if (lookahead == 'e') ADVANCE(27);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(237);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(26);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(227);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(23);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 26:[m
[31m-      if (lookahead == 'r') ADVANCE(25);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(237);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(26);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '}') ADVANCE(227);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(158);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 27:[m
[31m-      if (lookahead == 's') ADVANCE(28);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(238);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(161);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(102);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(171);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(160);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 28:[m
[31m-      if (lookahead == 't') ADVANCE(58);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(238);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(29);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(102);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(218);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(27);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 29:[m
[31m-      if (lookahead == '|') ADVANCE(131);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(238);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(30);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(102);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(27);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
[32m+[m[32m      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m          lookahead == '_' ||[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(72);[m
       END_STATE();[m
     case 30:[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(238);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(30);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(194);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(199);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(183);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == ')') ADVANCE(102);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(147);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(195);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32m      if (lookahead == 'S') ADVANCE(209);[m
[32m+[m[32m      if (lookahead == '[') ADVANCE(91);[m
[32m+[m[32m      if (lookahead == '{') ADVANCE(225);[m
[32m+[m[32m      if (lookahead == '|') ADVANCE(114);[m
[32m+[m[32m      if (lookahead == '\t' ||[m
[32m+[m[32m          lookahead == ' ') ADVANCE(160);[m
[32m+[m[32m      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);[m
       if (('A' <= lookahead && lookahead <= 'Z') ||[m
           lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);[m
[32m+[m[32m          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);[m
[32m+[m[32m      if (lookahead != 0) ADVANCE(199);[m
       END_STATE();[m
     case 31:[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);[m
[32m+[m[32m      if (lookahead == '\n') ADVANCE(239);[m
[32m+[m[32m      if (lookahead == '\r') ADVANCE(32);[m
[32m+[m[32m      if (lookahead == '!') ADVANCE(60);[m
[32m+[m[32m      if (lookahead == '"') ADVANCE(135);[m
[32m+[m[32m      if (lookahead == '#') ADVANCE(230);[m
[32m+[m[32m      if (lookahead == '$') ADVANCE(145);[m
[32m+[m[32m      if (lookahead == '%') ADVANCE(255);[m
[32m+[m[32m      if (lookahead == '&') ADVANCE(51);[m
[32m+[m[32m      if (lookahead == '\'') ADVANCE(137);[m
[32m+[m[32m      if (lookahead == '*') ADVANCE(249);[m
[32m+[m[32m      if (lookahead == '+') ADVANCE(244);[m
[32m+[m[32m      if (lookahead == '-') ADVANCE(246);[m
[32m+[m[32m      if (lookahead == '.') ADVANCE(43);[m
[32m+[m[32m      if (lookahead == '/') ADVANCE(252);[m
[32m+[m[32m      if (lookahead == ';') ADVANCE(222);[m
[32m+[m[32m      if (lookahead == '<') ADVANCE(279);[m
[32m+[m[32m      if (lookahead == '=') ADVANCE(61);[m
[32m+[m[32m      if (lookahead == '>') ADVANCE(270);[m
[32m+[m[32mTATE();[m
    case 17:[m
      if (lookahead =[m
\ No newline at end of file[m
[32m+[m[32m= 'b') ADVANCE(26);[m
      END_STATE();[m
  [m
\ No newline at end of file[m
[32m+[m[32m  case 18:[m
      if (lookahead == 'i') ADV[m
\ No newline at end of file[m
[32m+[m[32mANCE(27);[m
      END_STATE();[m
    case 19:[m
[32m+[m[32m      ACCEPT_TOKEN(anon_sym_any[m
\ No newline at end of file[m
[32m+[m[32m);[m
      END_STATE();[m
    case 20:[m
      [m
\ No newline at end of file[m
[32m+[m[32mif (lookahead == 'c') ADVANCE(28);[m
      END_STATE();[m
    case 2[m
\ No newline at end of file[m
[32m+[m[32m1:[m
      ACCEPT_TOKEN(anon_sym_int);[m
      END_STATE[m
\ No newline at end of file[m
[32m+[m[32m();[m
    case 22:[m
      if (loo[m
\ No newline at end of file[m
[32m+[m[32mkahead == 'b') ADVANCE(29);[m
      END_STATE();[m
    case 23:[m
    [m
\ No newline at end of file[m
[32m+[m[32m  if (lookahead == 'h') ADVANCE(30);[m
  [m
\ No newline at end of file[m
     if (lookahead =[m
\ No newline at end of file[m
 = 't') ADVANC[m
\ No newline at end of file[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32mE(31);[m
      END_STATE();[m
    case 24:[m
    [m
\ No newline at end of file[m
[32m+[m[32m  if (lookahead == 'g') ADVANCE(32);[m
     [m
\ No newline at end of file[m
[32m+[m[32m END_STATE();[m
    case 25:[m
      if (looka[m
\ No newline at end of file[m
[32m+[m[32mhead == 'i') ADVANCE(33);[m
      END_STATE([m
\ No newline at end of file[m
[32m+[m[32m);[m
    case 26:[m
      if (lookahead == 'l'[m
\ No newline at end of file[m
[32m+[m[32m) ADVANCE(34);[m
      END_STATE();[m
    case[m
\ No newline at end of file[m
[32m+[m[32m 27:[m
      if (lookahead == 't') ADVANCE(3[m
\ No newline at end of file[m
[32m+[m[32m5);[m
      END_STATE();[m
    case 28:[m
      [m
\ No newline at end of file[m
[32m+[m[32mif (lookahead == 'k') ADVANCE(36);[m
      EN[m
\ No newline at end of file[m
[32m+[m[32mD_STATE();[m
    case 29:[m
      if (lookahea[m
\ No newline at end of file[m
[32m+[m[32md == 'e') ADVANCE(37);[m
      END_STATE();[m
[32m+[m[32m    case 30:[m
      ACCEPT_TOKEN(anon_sym_p[m
\ No newline at end of file[m
[32m+[m[32math);[m
      END_STATE();[m
    case 31:[m
    [m
\ No newline at end of file[m
[32m+[m[32m  if (lookahead == 'e') ADVANCE(38);[m
     [m
\ No newline at end of file[m
[32m+[m[32m END_STATE();[m
    case 32:[m
      if (looka[m
\ No newline at end of file[m
[32m+[m[32mhead == 'e') ADVANCE(39);[m
      END_STATE([m
\ No newline at end of file[m
[32m+[m[32m);[m
    case 33:[m
      if (lookahead == 'n'[m
\ No newline at end of file[m
[32m+[m[32m) ADVANCE(40);[m
      END_STATE();[m
    case[m
\ No newline at end of file[m
[32m+[m[32m 34:[m
      if (lookahead == 'e') ADVANCE(4[m
\ No newline at end of file[m
[32m+[m[32m1);[m
      END_STATE();[m
    case 35:[m
     [m
\ No newline at end of file[m
[32m+[m[32m ACCEPT_TOKEN(anon_sym_unit);[m
      END_ST[m
\ No newline at end of file[m
[32m+[m[32mATE();[m
    case 36:[m
      ACCEPT_TOKEN(ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_block);[m
      END_STATE()[m
\ No newline at end of file[m
[32m+[m[32m;[m
    case 37:[m
      if (lookahead == 'r')[m
\ No newline at end of file[m
[32m+[m[32m ADVANCE(42);[m
      END_STATE();[m
    case 38:[m
      if (lookahea[m
\ No newline at end of file[m
[32m+[m[32md == 'r') ADVANCE(43);[m
      END_STATE();[m
    case 3[m
\ No newline at end of file[m
 9:[m
      ACCEPT_TOKEN(anon_sym[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(111);[m
[32m+[m[32m_range);[m
      END_STATE();[m
    case 40:[m
      if (lookahead == [m
\ No newline at end of file[m
[32m+[m[32m'g') ADVANCE(44);[m
      END_STATE();[m
   [m
\ No newline at end of file[m
  case 41:[m
      ACC[m
\ No newline at end of file[m
 EPT_TOKEN(ano[m
\ No newline at end of file[m
[31m-      if (lookahead == '.' ||[m
[31m-          ('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32mn_sym_table);[m
      END_STATE();[m
    case 4[m
\ No newline at end of file[m
[32m+[m[32m2:[m
      ACCEPT_TOKEN(anon_sym_number);[m
   [m
\ No newline at end of file[m
[32m+[m[32m   END_STATE();[m
    case 43:[m
      if (loo[m
\ No newline at end of file[m
[32m+[m[32mkahead == 'n') ADVANCE(45);[m
      END_STAT[m
\ No newline at end of file[m
[32m+[m[32mE();[m
    case 44:[m
      ACCEPT_TOKEN(anon_[m
\ No newline at end of file[m
[32m+[m[32msym_string);[m
      END_STATE();[m
    case 4[m
\ No newline at end of file[m
[32m+[m[32m5:[m
      ACCEPT_TOKEN(anon_sym_pattern);[m
 [m
\ No newline at end of file[m
[32m+[m[32m     END_STATE();[m
    default:[m
      retur[m
\ No newline at end of file[m
[32m+[m[32mn false;[m
  }[m
}[m

static TSLexMode ts_lex_mod[m
\ No newline at end of file[m
[32m+[m[32mes[STATE_COUNT] = {[m
  [0] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m0},[m
  [1] = {.lex_state = 43},[m
  [2] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 39},[m
  [3] = {.lex_state = 39},[m
\ No newline at end of file[m
[32m+[m
  [4] = {.lex_state = 39},[m
  [5] = {.lex_[m
\ No newline at end of file[m
[32m+[m[32mstate = 39},[m
  [6] = {.lex_state = 39},[m
  [m
\ No newline at end of file[m
[32m+[m[32m[7] = {.lex_state = 39},[m
  [8] = {.lex_sta[m
\ No newline at end of file[m
[32m+[m[32mte = 3},[m
  [9] = {.lex_state = 3},[m
  [10] [m
\ No newline at end of file[m
[32m+[m[32m= {.lex_state = 3},[m
  [11] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 3},[m
  [12] = {.lex_state = 3},[m
  [13] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 3},[m
  [14] = {.lex_state = 3}[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [15] = {.lex_state = 3},[m
  [16] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 3},[m
  [17] = {.lex_state = 3},[m
[32m+[m[32m  [18] = {.lex_state = 3},[m
  [19] = {.lex_[m
\ No newline at end of file[m
[32m+[m[32mstate = 3},[m
  [20] = {.lex_stat[m
\ No newline at end of file[m
[32m+[m[32me = 3},[m
  [21] = {.lex_state = 39},[m
  [22][m
\ No newline at end of file[m
[32m+[m[32m = {.lex_state = 39},[m
  [23] = {.lex_state = 39},[m
  [24] = {.lex[m
\ No newline at end of file[m
[32m+[m[32m_state = 39},[m
  [25] = {.lex_state = 39},[m
  [26] = {[m
\ No newline at end of file[m
 .lex_state = 39},[m
  [27] = {.l[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);[m
[32m+[m[32mex_state = 39},[m
  [28] = {.lex_state = 40},[m
  [29] = {.lex_state[m
\ No newline at end of file[m
[32m+[m[32m = 39},[m
  [30] = {.lex_state = 39},[m
  [3[m
\ No newline at end of file[m
 1] = {.lex_state = [m
\ No newline at end of file[m
 39},[m
  [32] =[m
\ No newline at end of file[m
[31m-      if (lookahead != 0 &&[m
[31m-          lookahead != '\t' &&[m
[31m-          lookahead != '\n' &&[m
[31m-          lookahead != '\r' &&[m
[31m-          lookahead != ' ') ADVANCE(83);[m
[32m+[m[32m {.lex_state = 40},[m
  [33] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m39},[m
  [34] = {.lex_state = 39},[m
  [35] = [m
\ No newline at end of file[m
[32m+[m[32m{.lex_state = 39},[m
  [36] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 39},[m
  [37] = {.lex_state = 39},[m
  [38] =[m
\ No newline at end of file[m
[32m+[m[32m {.lex_state = 39},[m
  [39] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 39},[m
  [40] = {.lex_state = 39},[m
  [41] =[m
\ No newline at end of file[m
[32m+[m[32m {.lex_state = 39},[m
  [42] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 39},[m
  [43] = {.lex_state = 39},[m
  [44] [m
\ No newline at end of file[m
[32m+[m[32m= {.lex_state = 39},[m
  [45] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 39},[m
  [46] = {.lex_state = 39},[m
  [47] =[m
\ No newline at end of file[m
[32m+[m[32m {.lex_state = 39},[m
  [48] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 39},[m
  [49] = {.lex_state = 39},[m
  [50] =[m
\ No newline at end of file[m
[32m+[m[32m {.lex_state = 39},[m
  [51] = {.lex_state [m
\ No newline at end of file[m
[32m+[m[32m= 39},[m
  [52] = {.lex_state = 39},[m
  [53] [m
\ No newline at end of file[m
[32m+[m[32m= {.lex_state = 39},[m
  [54] = {.lex_state [m
\ No newline at end of file[m
[32m+[m[32m= 39},[m
  [55] = {.lex_state = 39},[m
  [56] [m
\ No newline at end of file[m
[32m+[m[32m= {.lex_state = 39},[m
  [57] = {.lex_state[m
\ No newline at end of file[m
[32m+[m[32m = 39},[m
  [58] = {.lex_state = 39},[m
  [59][m
\ No newline at end of file[m
[32m+[m[32m = {.lex_state = 3},[m
  [60] = {.lex_state [m
\ No newline at end of file[m
[32m+[m[32m= 41},[m
  [61] = {.lex_state = 41},[m
  [62][m
\ No newline at end of file[m
[32m+[m[32m = {.lex_state = 41},[m
  [63] = {.lex_state[m
\ No newline at end of file[m
[32m+[m[32m = 43},[m
  [64] = {.lex_state = 43},[m
  [65][m
\ No newline at end of file[m
[32m+[m[32m = {.lex_state = 43},[m
  [66] = {.lex_state[m
\ No newline at end of file[m
[32m+[m[32m = 41},[m
  [67] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m43},[m
  [68] = {.lex_state = 43},[m
  [69] =[m
\ No newline at end of file[m
[32m+[m[32m {.lex_state = 43},[m
  [70] = {.lex_state = 43},[m
  [71] = {.lex_s[m
\ No newline at end of file[m
[32m+[m[32mtate = 43},[m
  [72] = {.lex_state = 43},[m
  [73] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 41},[m
  [74] = {.lex[m
\ No newline at end of file[m
[32m+[m[32m_state = 41},[m
  [75] = {.lex_state = 41},[m
  [76] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 41},[m
  [77] = {.lex_state = 41},[m
  [78[m
\ No newline at end of file[m
 ] = {.lex_state = 4[m
\ No newline at end of file[m
 1},[m
  [79] = [m
\ No newline at end of file[m
[31m-      if (lookahead != 0) ADVANCE(91);[m
[32m+[m[32m{.lex_state = 41},[m
  [80] = {.lex_state = 4[m
\ No newline at end of file[m
[32m+[m[32m1},[m
  [81] = {.lex_state = 41},[m
  [82] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 41},[m
  [83] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m41},[m
  [84] = {.lex_state = 43},[m
  [85] = [m
\ No newline at end of file[m
[32m+[m[32m{.lex_state = 43},[m
  [86] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m43},[m
  [87] = {.lex_state = 43},[m
  [88] = [m
\ No newline at end of file[m
[32m+[m[32m{.lex_state = 43},[m
  [89] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m4},[m
  [90] = {.lex_state = 4},[m
  [91] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 4},[m
  [92] = {.lex_state = 4},[m
\ No newline at end of file[m
[32m+[m
  [93] = {.lex_state = 4},[m
  [94] = {.lex[m
\ No newline at end of file[m
[32m+[m[32m_state = 4},[m
  [95] = {.lex_state = 4},[m
  [m
\ No newline at end of file[m
[32m+[m[32m[96] = {.lex_state = 4},[m
  [97] = {.lex_st[m
\ No newline at end of file[m
[32m+[m[32mate = 4},[m
  [98] = {.lex_state = 4},[m
  [9[m
\ No newline at end of file[m
[32m+[m[32m9] = {.lex_state = 4},[m
  [100] = {.lex_sta[m
\ No newline at end of file[m
[32m+[m[32mte = 4},[m
  [101] = {.lex_state = 4},[m
  [10[m
\ No newline at end of file[m
[32m+[m[32m2] = {.lex_state = 4},[m
  [103] = {.lex_sta[m
\ No newline at end of file[m
[32m+[m[32mte = 4},[m
  [104] = {.lex_state = 4},[m
  [1[m
\ No newline at end of file[m
[32m+[m[32m05] = {.lex_state = 4},[m
  [106] = {.lex_st[m
\ No newline at end of file[m
[32m+[m[32mate = 4},[m
  [107] = {.lex_state = 4},[m
  [1[m
\ No newline at end of file[m
[32m+[m[32m08] = {.lex_state = 4},[m
  [109] = {.lex_s[m
\ No newline at end of file[m
[32m+[m[32mtate = 4},[m
  [110] = {.lex_state = 7},[m
  [[m
\ No newline at end of file[m
[32m+[m[32m111] = {.lex_state = 7},[m
  [112] = {.lex_s[m
\ No newline at end of file[m
[32m+[m[32mtate = 7},[m
  [113] = {.lex_state = 7},[m
  [[m
\ No newline at end of file[m
[32m+[m[32m114] = {.lex_state = 43},[m
  [11[m
\ No newline at end of file[m
[32m+[m[32m5] = {.lex_state = 43},[m
  [116] = {.lex_s[m
\ No newline at end of file[m
[32m+[m[32mtate = 43},[m
  [117] = {.lex_state = 43},[m
  [118] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 43},[m
  [119] = {.lex_state = 43},[m
  [120] = {.lex_s[m
\ No newline at end of file[m
[32m+[m[32mtate = 43},[m
  [121] = {.lex_st[m
\ No newline at end of file[m
[32m+[m[32mate = 43},[m
  [122] = {.lex_state = 43},[m
  [123] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m43},[m
  [124] = {.lex_state = 43},[m
  [12[m
\ No newline at end of file[m
 5] = {.lex_state = [m
\ No newline at end of file[m
 43},[m
  [126] [m
\ No newline at end of file[m
[31m-      if (lookahead != 0) ADVANCE(88);[m
[32m+[m[32m= {.lex_state = 43},[m
  [127] = {.lex_state [m
\ No newline at end of file[m
[32m+[m[32m= 43},[m
  [128] = {.lex_state = 43},[m
  [129[m
\ No newline at end of file[m
[32m+[m[32m] = {.lex_state = 43},[m
  [130] = {.lex_sta[m
\ No newline at end of file[m
[32m+[m[32mte = 43},[m
  [131] = {.lex_state = 43},[m
  [[m
\ No newline at end of file[m
[32m+[m[32m132] = {.lex_state = 43},[m
  [133] = {.lex_[m
\ No newline at end of file[m
[32m+[m[32mstate = 43},[m
  [134] = {.lex_state = 43},[m
[32m+[m[32m  [135] = {.lex_state = 43},[m
  [136] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 43},[m
  [137] = {.lex_state = 43[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [138] = {.lex_state = 43},[m
  [139] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 6},[m
  [140] = {.lex_state = 6[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [141] = {.lex_state = 43},[m
  [142] = [m
\ No newline at end of file[m
[32m+[m[32m{.lex_state = 6},[m
  [143] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m6},[m
  [144] = {.lex_state = 42},[m
  [145] =[m
\ No newline at end of file[m
[32m+[m[32m {.lex_state = 6},[m
  [146] = {.lex_state =[m
\ No newline at end of file[m
[32m+[m[32m 41},[m
  [147] = {.lex_state = 6},[m
  [148] [m
\ No newline at end of file[m
[32m+[m[32m= {.lex_state = 6},[m
  [149] = {.lex_state [m
\ No newline at end of file[m
[32m+[m[32m= 41},[m
  [150] = {.lex_state = 6},[m
  [151][m
\ No newline at end of file[m
[32m+[m[32m = {.lex_state = 41},[m
  [152] = {.lex_stat[m
\ No newline at end of file[m
[32m+[m[32me = 41},[m
  [153] = {.lex_state = 41},[m
  [1[m
\ No newline at end of file[m
[32m+[m[32m54] = {.lex_state = 41},[m
  [155] = {.lex_[m
\ No newline at end of file[m
[32m+[m[32mstate = 41},[m
  [156] = {.lex_state = 41},[m
[32m+[m[32m  [157] = {.lex_state = 41},[m
  [158] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 41},[m
  [159] = {.lex_state = 41[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [160] = {.lex_state = 41},[m
\ No newline at end of file[m
[32m+[m
  [161] = {.lex_state = 41},[m
  [162] = {.[m
\ No newline at end of file[m
[32m+[m[32mlex_state = 41},[m
  [163] = {.lex_state = 41},[m
  [164] = {.lex_st[m
\ No newline at end of file[m
[32m+[m[32mate = 41},[m
  [165] = {.lex_state = 6},[m
  [166] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 41},[m
  [167] = {.le[m
\ No newline at end of file[m
[32m+[m[32mx_state = 6},[m
  [168] = {.lex_state = 6},[m
  [169] = {.lex_state [m
\ No newline at end of file[m
[32m+[m[32m= 6},[m
  [170] = {.lex_state = 6},[m
  [171[m
\ No newline at end of file[m
 ] = {.lex_state = 6[m
\ No newline at end of file[m
 },[m
  [172] = [m
\ No newline at end of file[m
[31m-      if (eof) ADVANCE(42);[m
[31m-      if (lookahead == '\n') ADVANCE(119);[m
[31m-      if (lookahead == '!') ADVANCE(23);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '%') ADVANCE(129);[m
[31m-      if (lookahead == '&') ADVANCE(13);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(125);[m
[31m-      if (lookahead == '+') ADVANCE(122);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(95);[m
[31m-      if (lookahead == '/') ADVANCE(127);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[31m-      if (lookahead == '<') ADVANCE(147);[m
[31m-      if (lookahead == '=') ADVANCE(24);[m
[31m-      if (lookahead == '>') ADVANCE(141);[m
[31m-      if (lookahead == '[') ADVANCE(45);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '|') ADVANCE(66);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32m{.lex_state = 6},[m
  [173] = {.lex_state = 4[m
\ No newline at end of file[m
[32m+[m[32m1},[m
  [174] = {.lex_state = 6},[m
  [175] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 0},[m
  [176] = {.lex_state = 0[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [177] = {.lex_state = 0},[m
  [178] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 0},[m
  [179] = {.lex_state = 4[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [180] = {.lex_state = 0},[m
  [181] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 0},[m
  [182] = {.lex_state = 1[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [183] = {.lex_state = 1},[m
  [184] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 1},[m
  [185] = {.lex_state = 0}[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [186] = {.lex_state = 41},[m
  [187] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 0},[m
  [188] = {.lex_state = 0[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [189] = {.lex_state = 5},[m
  [190] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 8},[m
  [191] = {.lex_state = 5[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [192] = {.lex_state = 5},[m
  [193] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 8},[m
  [194] = {.lex_state = 2[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [195] = {.lex_state = 4},[m
  [196] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 8},[m
  [197] = {.lex_state = 8[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [198] = {.lex_state = 8},[m
  [199] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 5},[m
  [200] = {.lex_state = 8[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [201] = {.lex_state = 5},[m
  [202] = [m
\ No newline at end of file[m
[32m+[m[32m{.lex_state = 8},[m
  [203] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m1},[m
  [204] = {.lex_state = 8},[m
  [205] = [m
\ No newline at end of file[m
[32m+[m[32m{.lex_state = 5},[m
  [206] = {.lex_state = [m
\ No newline at end of file[m
 4},[m
  [207] = {.lex_state = 8},[m
\ No newline at end of file[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(1);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);[m
[32m+[m
  [208] = {.lex_state = 5},[m
  [209] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 5},[m
  [210] = {.lex_state = 8},[m
  [211] = {.lex_state[m
\ No newline at end of file[m
  = 5},[m
  [212] = {.lex_state = 8},[m
  [213] = {.lex_s[m
\ No newline at end of file[m
 tate = 1},[m
  [214] = {.lex_sta[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(104);[m
[32m+[m[32mte = 5},[m
  [215] = {.lex_state = 5},[m
  [216] = {.lex_state = 0},[m
\ No newline at end of file[m
[32m+[m
  [217] = {.lex_state = 1},[m
  [218] = {[m
\ No newline at end of file[m
 .lex_state = 4},[m
  [m
\ No newline at end of file[m
 [219] = {.lex[m
\ No newline at end of file[m
[31m-      if (eof) ADVANCE(42);[m
[31m-      if (lookahead == '\n') ADVANCE(120);[m
[31m-      if (lookahead == '!') ADVANCE(23);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '%') ADVANCE(129);[m
[31m-      if (lookahead == '&') ADVANCE(13);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(125);[m
[31m-      if (lookahead == '+') ADVANCE(122);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(93);[m
[31m-      if (lookahead == '/') ADVANCE(127);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[31m-      if (lookahead == '<') ADVANCE(147);[m
[31m-      if (lookahead == '=') ADVANCE(24);[m
[31m-      if (lookahead == '>') ADVANCE(141);[m
[31m-      if (lookahead == '|') ADVANCE(66);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32m_state = 1},[m
  [220] = {.lex_state = 0},[m
  [m
\ No newline at end of file[m
[32m+[m[32m[221] = {.lex_state = 1},[m
  [222] = {.lex_[m
\ No newline at end of file[m
[32m+[m[32mstate = 1},[m
  [223] = {.lex_state = 1},[m
 [m
\ No newline at end of file[m
[32m+[m[32m [224] = {.lex_state = 1},[m
  [225] = {.lex[m
\ No newline at end of file[m
[32m+[m[32m_state = 0},[m
  [226] = {.lex_state = 1},[m
 [m
\ No newline at end of file[m
[32m+[m[32m [227] = {.lex_state = 1},[m
  [228] = {.lex[m
\ No newline at end of file[m
[32m+[m[32m_state = 1},[m
  [229] = {.lex_state = 1},[m
 [m
\ No newline at end of file[m
[32m+[m[32m [230] = {.lex_state = 1},[m
  [231] = {.le[m
\ No newline at end of file[m
[32m+[m[32mx_state = 1},[m
  [232] = {.lex_state = 0},[m
 [m
\ No newline at end of file[m
[32m+[m[32m [233] = {.lex_state = 1},[m
  [234] = {.lex[m
\ No newline at end of file[m
[32m+[m[32m_state = 1},[m
  [235] = {.lex_state = 1},[m
 [m
\ No newline at end of file[m
[32m+[m[32m [236] = {.lex_state = 0},[m
  [237] = {.lex[m
\ No newline at end of file[m
[32m+[m[32m_state = 4},[m
  [238] = {.lex_state = 0},[m
 [m
\ No newline at end of file[m
[32m+[m[32m [239] = {.lex_state = 43},[m
  [240] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 4},[m
  [241] = {.lex_state = 0},[m
\ No newline at end of file[m
[32m+[m
  [242] = {.lex_state = 4},[m
  [243] = {.l[m
\ No newline at end of file[m
[32m+[m[32mex_state = 0},[m
  [244] = {.lex_state = 0},[m
\ No newline at end of file[m
[32m+[m
  [245] = {.lex_state = 43},[m
  [246] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 0},[m
  [247] = {.lex_state = 0[m
\ No newline at end of file[m
[32m+[m[32m},[m
  [248] = {.lex_state = 4},[m
  [249] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 0},[m
  [250] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m0},[m
  [251] = {.lex_state = 43},[m
  [252] =[m
\ No newline at end of file[m
[32m+[m[32m {.lex_state = 4},[m
  [253] = {.lex_state =[m
\ No newline at end of file[m
  0},[m
  [254] = {.lex_state = 4}[m
\ No newline at end of file[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') SKIP(38)[m
[32m+[m[32m,[m
  [255] = {.lex_state = 4},[m
  [256] = {[m
\ No newline at end of file[m
[32m+[m[32m.lex_state = 0},[m
  [257] = {.lex_state = 0},[m
  [258] = {.lex_sta[m
\ No newline at end of file[m
[32m+[m[32mte = 0},[m
  [259] = {.lex_state = 43},[m
  [260] = {.le[m
\ No newline at end of file[m
[32m+[m[32mx_state = 4},[m
  [261] = {.lex_[m
\ No newline at end of file[m
[32m+[m[32mstate = 0},[m
  [262] = {.lex_state = 0},[m
  [263] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m43},[m
  [264] = {.lex_state = 43},[m
  [26[m
\ No newline at end of file[m
 5] = {.lex_state = [m
\ No newline at end of file[m
 4},[m
  [266] =[m
\ No newline at end of file[m
[31m-      if (eof) ADVANCE(42);[m
[31m-      if (lookahead == '\n') ADVANCE(120);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '.') ADVANCE(21);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[31m-      if (lookahead == '|') ADVANCE(64);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32m {.lex_state = 0},[m
  [267] = {.lex_state = [m
\ No newline at end of file[m
[32m+[m[32m0},[m
  [268] = {.lex_state = 43},[m
  [269] =[m
\ No newline at end of file[m
[32m+[m[32m {.lex_state = 0},[m
  [270] = {.lex_state [m
\ No newline at end of file[m
[32m+[m[32m= 0},[m
  [271] = {.lex_state = 0},[m
  [272] [m
\ No newline at end of file[m
[32m+[m[32m= {.lex_state = 0},[m
  [273] = {.lex_state [m
\ No newline at end of file[m
[32m+[m[32m= 4},[m
  [274] = {.lex_state = 4},[m
};[m

stat[m
\ No newline at end of file[m
[32m+[m[32mic uint16_t ts_parse_table[LARGE_STATE_COU[m
\ No newline at end of file[m
[32m+[m[32mNT][SYMBOL_COUNT] = {[m
  [0] = {[m
    [ts_b[m
\ No newline at end of file[m
[32m+[m[32muiltin_sym_end] = ACTIONS(1),[m
    [sym_word[m
\ No newline at end of file[m
[32m+[m[32m] = ACTIONS(1),[m
    [anon_sym_def] = ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(1),[m
    [anon_sym_LBRACK] = ACTIONS(1),[m
\ No newline at end of file[m
[32m+[m
    [anon_sym_COMMA] = ACTIONS(1),[m
    [a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_RBRACK] = ACTIONS(1),[m
    [anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_COLON] = ACTIONS(1),[m
    [anon_sym_QMAR[m
\ No newline at end of file[m
[32m+[m[32mK] = ACTIONS(1),[m
    [anon_sym_LPAREN] = A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(1),[m
    [anon_sym_RPAREN] = ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(1),[m
    [anon_sym_DOT_DOT_DOTrest] = ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(1),[m
    [anon_sym_int] = ACTIONS(1),[m
[32m+[m[32m    [anon_sym_string] = ACTIONS(1),[m
    [a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_path] = ACTIONS(1),[m
    [anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mtable] = ACTIONS(1),[m
    [anon_sym_unit] [m
\ No newline at end of file[m
[32m+[m[32m= ACTIONS(1),[m
    [anon_sym_number] = ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(1),[m
    [anon_sym_pattern] = ACTIONS(1[m
\ No newline at end of file[m
 ),[m
    [anon_sym_range] = ACTIO[m
\ No newline at end of file[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') SKIP(39)[m
[32m+[m[32mNS(1),[m
    [anon_sym_block] = ACTIONS(1),[m
\ No newline at end of file[m
[32m+[m
    [anon_sym_any] = ACTIONS(1),[m
    [anon_sym_let] = ACTIONS(1[m
\ No newline at end of file[m
[32m+[m[32m),[m
    [anon_sym_EQ] = ACTIONS(1),[m
    [anon_sym_PIP[m
\ No newline at end of file[m
[32m+[m[32mE] = ACTIONS(1),[m
    [sym_numb[m
\ No newline at end of file[m
[32m+[m[32mer_literal] = ACTIONS(1),[m
    [anon_sym_DQUOTE] = ACTIONS(1),[m
  [m
\ No newline at end of file[m
[32m+[m[32m  [anon_sym_SQUOTE] = ACTIONS(1),[m
    [[m
\ No newline at end of file[m
 anon_sym_DOLLAR] = [m
\ No newline at end of file[m
 ACTIONS(1),[m
 [m
\ No newline at end of file[m
[31m-      if (eof) ADVANCE(42);[m
[31m-      if (lookahead == '\n') ADVANCE(121);[m
[31m-      if (lookahead == '!') ADVANCE(23);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '%') ADVANCE(129);[m
[31m-      if (lookahead == '&') ADVANCE(13);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == '*') ADVANCE(125);[m
[31m-      if (lookahead == '+') ADVANCE(122);[m
[31m-      if (lookahead == '-') ADVANCE(124);[m
[31m-      if (lookahead == '.') ADVANCE(19);[m
[31m-      if (lookahead == '/') ADVANCE(127);[m
[31m-      if (lookahead == ';') ADVANCE(112);[m
[31m-      if (lookahead == '<') ADVANCE(147);[m
[31m-      if (lookahead == '=') ADVANCE(24);[m
[31m-      if (lookahead == '>') ADVANCE(141);[m
[31m-      if (lookahead == '[') ADVANCE(45);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '|') ADVANCE(66);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32m   [anon_sym_DOT] = ACTIONS(1),[m
    [anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DOT_DOT] = ACTIONS(1),[m
    [anon_sym_DO[m
\ No newline at end of file[m
[32m+[m[32mLLAR_LPAREN] = ACTIONS(1),[m
    [anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mEMI] = ACTIONS(1),[m
    [anon_sym_LBRACE] =[m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(1),[m
    [anon_sym_RBRACE] = ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(1),[m
    [sym_comment] = ACTIONS(3),[m
   [m
\ No newline at end of file[m
[32m+[m[32m [anon_sym_PLUS] = ACTIONS(1),[m
    [anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DASH] = ACTIONS(1),[m
    [anon_sym_STAR][m
\ No newline at end of file[m
[32m+[m[32m = ACTIONS(1),[m
    [anon_sym_SLASH] = ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(1),[m
    [anon_sym_PERCENT] = ACTIONS(1)[m
\ No newline at end of file[m
[32m+[m[32m,[m
    [anon_sym_PIPE_PIPE] = ACTIONS(1),[m
 [m
\ No newline at end of file[m
[32m+[m[32m   [anon_sym_AMP_AMP] = ACTIONS(1),[m
    [a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_BANG_EQ] = ACTIONS(1),[m
    [anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT] = ACTIONS(1),[m
    [anon_sym_GT_EQ] [m
\ No newline at end of file[m
[32m+[m[32m= ACTIONS(1),[m
    [anon_sym_LT_EQ] = ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(1),[m
    [anon_sym_LT] = ACTIONS(1),[m
   [m
\ No newline at end of file[m
[32m+[m[32m [anon_sym_LT_LT] = ACTIONS(1),[m
    [anon_[m
\ No newline at end of file[m
[32m+[m[32msym_GT_GT] = ACTIONS(1),[m
  },[m
  [1] = {[m
  [m
\ No newline at end of file[m
[32m+[m[32m  [sym_source_file] = STATE(271),[m
    [sym[m
\ No newline at end of file[m
[32m+[m[32m__statements] = STATE(270),[m
    [sym__stat[m
\ No newline at end of file[m
[32m+[m[32mement] = STATE(173),[m
    [sym_function_de[m
\ No newline at end of file[m
[32m+[m[32mfinition] = STATE(173),[m
    [sym_variable_[m
\ No newline at end of file[m
[32m+[m[32mdeclaration] = STATE(173),[m
    [sym_comman[m
\ No newline at end of file[m
 d] = STATE(173),[m
    [sym_pipel[m
\ No newline at end of file[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(2);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);[m
[32m+[m[32mine] = STATE(173),[m
    [sym_value_path] = [m
\ No newline at end of file[m
[32m+[m[32mSTATE(78),[m
    [sym_command_substitution] = STATE(78),[m
    [sym_[m
\ No newline at end of file[m
 math_mode] = STATE(78),[m
    [sym_block] = STATE(173)[m
\ No newline at end of file[m
 ,[m
    [sym__math_expression] =[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(104);[m
[32m+[m[32m STATE(78),[m
    [sym_parenthesized_math_expression] = STATE(78),[m
\ No newline at end of file[m
[32m+[m
    [sym_binary_expression] = STATE(78)[m
\ No newline at end of file[m
 ,[m
    [aux_sym__sta[m
\ No newline at end of file[m
 tements_repea[m
\ No newline at end of file[m
[31m-      if (eof) ADVANCE(42);[m
[31m-      if (lookahead == '#') ADVANCE(118);[m
[31m-      if (lookahead == '$') ADVANCE(92);[m
[31m-      if (lookahead == '(') ADVANCE(53);[m
[31m-      if (lookahead == ')') ADVANCE(54);[m
[31m-      if (lookahead == ',') ADVANCE(46);[m
[31m-      if (lookahead == '-') ADVANCE(31);[m
[31m-      if (lookahead == '=') ADVANCE(62);[m
[31m-      if (lookahead == 'd') ADVANCE(106);[m
[31m-      if (lookahead == 'l') ADVANCE(107);[m
[31m-      if (lookahead == '{') ADVANCE(114);[m
[31m-      if (lookahead == '}') ADVANCE(115);[m
[32m+[m[32mt1] = STATE(86),[m
    [ts_builtin_sym_end] =[m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(5),[m
    [anon_sym_def] = ACTIONS(7[m
\ No newline at end of file[m
[32m+[m[32m),[m
    [anon_sym_LPAREN] = ACTIONS(9),[m
   [m
\ No newline at end of file[m
[32m+[m[32m [anon_sym_let] = ACTIONS(11),[m
    [sym_nu[m
\ No newline at end of file[m
[32m+[m[32mmber_literal] = ACTIONS(13),[m
    [anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DOLLAR] = ACTIONS(15),[m
    [anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR_LPAREN] = ACTIONS(17),[m
    [sym_identif[m
\ No newline at end of file[m
[32m+[m[32mier] = ACTIONS(19),[m
    [anon_sym_LBRACE] [m
\ No newline at end of file[m
[32m+[m[32m= ACTIONS(21),[m
    [sym_comment] = ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m3),[m
  },[m
};[m

static uint16_t ts_small_pars[m
\ No newline at end of file[m
[32m+[m[32me_table[] = {[m
  [0] = 15,[m
    ACTIONS(23),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_LBRACK,[m
    ACTIONS(27)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_number_literal,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(29), 1,[m
      anon_sym_DQUOTE,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(31), 1,[m
      anon_sym_SQUOTE,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(33), 1,[m
      anon_sym_DOLLAR,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(37), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
[32m+[m[32m    ACTIONS(39), 1,[m
      sym_identifier,[m
[32m+[m[32m    ACTIONS(41), 1,[m
      anon_sym_LBRACE,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(43), 1,[m
      sym_comment,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(45), 1,[m
      anon_sym_LF,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(4), 1,[m
      aux_sym_command_repeat1[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(35), 2,[m
      aux_sym_file_p[m
\ No newline at end of file[m
 ath_token1,[m
      aux_sym_file_[m
\ No newline at end of file[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') SKIP(41)[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);[m
[32m+[m[32mpath_token2,[m
    ACTIONS(25), 4,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_RPAREN,[m
      anon_sym_PIPE,[m
      anon_sym_SEMI,[m
      an[m
\ No newline at end of file[m
 on_sym_RBRACE,[m
    STATE(44), 11,[m
      sym__express[m
\ No newline at end of file[m
 ion,[m
      sym_string,[m
      s[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32mym_value_path,[m
      sym_file_path,[m
      sym_range,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32mommand_substitution,[m
      sym_math_mode[m
\ No newline at end of file[m
 ,[m
      sym_table,[m
       sym_arr[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(ts_builtin_sym_end);[m
[32m+[m[32may,[m
      sym_block,[m
      sym_operator,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(47), 16,[m
      anon_sym_PLUS,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DASH,[m
      anon_sym_STAR,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_SLASH,[m
      anon_sym_PERCENT[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
[32m+[m[32m      anon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_BANG_EQ,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT,[m
      anon_sym_LT_LT,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_GT_GT,[m
  [75] = 15,[m
    ACT[m
\ No newline at end of file[m
 IONS(43), 1,[m
      [m
\ No newline at end of file[m
 sym_comment,[m
[31m-      ACCEPT_TOKEN(anon_sym_def);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[32m+[m[32m    ACTIONS(49), 1,[m
      anon_sym_LBRACK,[m
[32m+[m[32m    ACTIONS(54), 1,[m
      sym_number_liter[m
\ No newline at end of file[m
[32m+[m[32mal,[m
    ACTIONS(57), 1,[m
      anon_sym_DQU[m
\ No newline at end of file[m
[32m+[m[32mOTE,[m
    ACTIONS(60), 1,[m
      anon_sym_SQ[m
\ No newline at end of file[m
[32m+[m[32mUOTE,[m
    ACTIONS(63), 1,[m
      anon_sym_DOLLAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(69), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    A[m
\ No newline at end of file[m
 CTIONS(72), 1,[m
      sym_ident[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32mifier,[m
    ACTIONS(75), 1,[m
      anon_sym_LBRACE,[m
    ACTIONS(78[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_LF,[m
   [m
\ No newline at end of file[m
[32m+[m[32m STATE(3), 1,[m
      aux_sym_command_repeat1[m
\ No newline at end of file[m
 ,[m
    ACTIONS(66), [m
\ No newline at end of file[m
 2,[m
      aux_[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_def);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32msym_file_path_token1,[m
      aux_sym_file_p[m
\ No newline at end of file[m
[32m+[m[32math_token2,[m
    ACTIONS(52), 4,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RPAREN,[m
      anon_sym_PIPE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_SEMI,[m
      anon_sym_RBRACE,[m
    S[m
\ No newline at end of file[m
[32m+[m[32mTATE(44), 11,[m
      sym__expression,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_string,[m
      sym_value_pa[m
\ No newline at end of file[m
[32m+[m[32mth,[m
      sym_file_path,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_range,[m
      sym_command_substitut[m
\ No newline at end of file[m
 ion,[m
      sym_math[m
\ No newline at end of file[m
 _mode,[m
      [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LBRACK);[m
[32m+[m[32msym_table,[m
      sym_array,[m
      sym_bloc[m
\ No newline at end of file[m
[32m+[m[32mk,[m
      sym_operator,[m
    ACTIONS(80), 16[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PLUS,[m
      anon_sym_DAS[m
\ No newline at end of file[m
[32m+[m[32mH,[m
      anon_sym_STAR,[m
      anon_sym_SL[m
\ No newline at end of file[m
[32m+[m[32mASH,[m
      anon_sym_PERCENT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PIPE_PIPE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_AMP_AMP,[m
      anon_sym_EQ_TIL[m
\ No newline at end of file[m
 DE,[m
      anon_sym_[m
\ No newline at end of file[m
 EQ_EQ,[m
      [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_COMMA);[m
[32m+[m[32manon_sym_BANG_EQ,[m
      anon_sym_GT,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT,[m
      anon_sym_LT_LT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_GT_GT,[m
  [150] = 15,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(23), 1,[m
      anon_sym_LBRACK,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(27), 1,[m
      sym_number_literal,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(29), 1,[m
      anon_sym_DQUOTE,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(31), 1,[m
      anon_sym_SQUOTE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(33), 1,[m
      anon_sym_DOLLAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(37), 1,[m
      anon_sym_DOLLAR_L[m
\ No newline at end of file[m
[32m+[m[32mPAREN,[m
    ACTIONS(39), 1,[m
      sym_ident[m
\ No newline at end of file[m
[32m+[m[32mifier,[m
    ACTIONS(41), 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLBRACE,[m
    ACTIONS(43), 1,[m
      sym_comm[m
\ No newline at end of file[m
[32m+[m[32ment,[m
    ACTIONS(85), 1,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mF,[m
    STATE(3), 1,[m
      aux_sym_command_[m
\ No newline at end of file[m
[32m+[m[32mrepeat1,[m
    ACTIONS(35), 2,[m
      aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_file_path_token1,[m
      aux_sym_file_pa[m
\ No newline at end of file[m
[32m+[m[32mth_token2,[m
    ACTIONS(83), 4,[m
[32m+[m[32m      anon_sym_RPAREN,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PIPE,[m
      anon_sym_SEM[m
\ No newline at end of file[m
[32m+[m[32mI,[m
      anon_sym_RBRACE,[m
    STATE(4[m
\ No newline at end of file[m
[32m+[m[32m4), 11,[m
      sym__expression,[m
      sym_string,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_value_path,[m
      sym_f[m
\ No newline at end of file[m
[32m+[m[32mile_path,[m
      sym_range,[m
      sym_command_substitution,[m
     [m
\ No newline at end of file[m
  sym_math_mode,[m
   [m
\ No newline at end of file[m
    sym_table,[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_COMMA);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m
      sym_array,[m
      sym_block,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_operator,[m
    ACTIONS(47), 16,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PLUS,[m
      anon_sym_DASH,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_STAR,[m
      anon_sym_SLA[m
\ No newline at end of file[m
[32m+[m[32mSH,[m
      anon_sym_PERCENT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_PIPE_PIPE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_EQ,[m
      anon_sym_BANG[m
\ No newline at end of file[m
 _EQ,[m
      anon_sym[m
\ No newline at end of file[m
 _GT,[m
      an[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_RBRACK);[m
[32m+[m[32mon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT,[m
      anon_sym_LT_LT,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT_GT,[m
  [225] = 15,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m43), 1,[m
      sym_comment,[m
    ACTIONS(87[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_LBRACK,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m90), 1,[m
      sym_number_literal,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(93), 1,[m
      anon_sym_DQUOTE,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(96), 1,[m
      anon_sym_SQUOTE,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(99), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DOLLAR,[m
    ACTIONS(105), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOLLAR_LPAREN,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(108), 1,[m
      sym_identifi[m
\ No newline at end of file[m
[32m+[m[32mer,[m
    ACTIONS(111), 1,[m
      anon_sym_LBRACE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(5), 1,[m
      aux_sym_com[m
\ No newline at end of file[m
[32m+[m[32mmand_repeat1,[m
    ACTIONS(52), 2,[m
      anon_sym_PIPE,[m
      ano[m
\ No newline at end of file[m
 n_sym_SEMI,[m
    ACT[m
\ No newline at end of file[m
 IONS(78), 2,[m
[31m-      ACCEPT_TOKEN(anon_sym_COLON);[m
[32m+[m[32m      ts_builtin_sym_end,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mF,[m
    ACTIONS(102), 2,[m
      aux_sym_file[m
\ No newline at end of file[m
[32m+[m[32m_path_token1,[m
      aux_sym_fil[m
\ No newline at end of file[m
[32m+[m[32me_path_token2,[m
    STATE(45), 1[m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym__expression,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_string,[m
      sym_value_path,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_file_path,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_range,[m
      sym_command_substitution,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mmath_mode,[m
      sym_table,[m
      sym_array,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_block,[m
      sym_operator,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(114), 16,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PLUS,[m
      anon_sym_DASH,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mSTAR,[m
      anon_sym_SLASH,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PERCENT,[m
      anon_sym_PIPE_[m
\ No newline at end of file[m
 PIPE,[m
      anon_sy[m
\ No newline at end of file[m
 m_AMP_AMP,[m
  [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_COLON);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m    anon_sym_EQ_TILDE,[m
      anon_sym_EQ_E[m
\ No newline at end of file[m
[32m+[m[32mQ,[m
      anon_sym_BANG_EQ,[m
      anon_sym_G[m
\ No newline at end of file[m
[32m+[m[32mT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT[m
\ No newline at end of file[m
[32m+[m[32m_EQ,[m
      anon_sym_LT,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_LT_LT,[m
      anon_sym_G[m
\ No newline at end of file[m
[32m+[m[32mT_GT,[m
  [299] = 15,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(43), 1,[m
      sym_comment,[m
    ACTIONS(11[m
\ No newline at end of file[m
[32m+[m[32m7), 1,[m
      anon_sym_LBRACK,[m
    ACTION[m
\ No newline at end of file[m
 S(119), 1,[m
      sy[m
\ No newline at end of file[m
 m_number_lite[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_QMARK);[m
[32m+[m[32mral,[m
    ACTIONS(121), 1,[m
      anon_sym_D[m
\ No newline at end of file[m
[32m+[m[32mQUOTE,[m
    ACTIONS(123), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SQUOTE,[m
    ACTIONS(125), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOLLAR,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(129), 1,[m
      anon_sym_DOLLAR_LPAREN[m
\ No newline at end of file[m
 ,[m
    ACTIONS(131),[m
\ No newline at end of file[m
  1,[m
      sym[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_QMARK);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m_identifier,[m
    ACTIONS(133), 1,[m
      an[m
\ No newline at end of file[m
 on_sym_LBRACE,[m
    [m
\ No newline at end of file[m
 STATE(5), 1,[m
[31m-      ACCEPT_TOKEN(anon_sym_LPAREN);[m
[32m+[m[32m      aux_sym_command_repeat1,[m
    ACTION[m
\ No newline at end of file[m
 S(83), 2,[m
      ano[m
\ No newline at end of file[m
 n_sym_PIPE,[m
 [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_RPAREN);[m
[32m+[m[32m     anon_sym_SEMI,[m
    ACTIONS(85), 2,[m
 [m
\ No newline at end of file[m
      ts_builtin_sym[m
\ No newline at end of file[m
 _end,[m
      a[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_flag_name);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);[m
[32m+[m[32mnon_sym_LF,[m
    ACTIONS(127), 2,[m
      aux[m
\ No newline at end of file[m
 _sym_file_path_toke[m
\ No newline at end of file[m
 n1,[m
      aux[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_flag_name);[m
[32m+[m[32m_sym_file_path_token2,[m
    STATE(45), 11,[m
[32m+[m[32m      sym__expression,[m
      sym_string,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_value_path,[m
      sym_file_path,[m
       sym_range,[m
      sym_command_substitution,[m
   [m
\ No newline at end of file[m
    sym_math_mode,[m
      sym_table,[m
      sym_array,[m
       sym_block,[m
      sym_ope[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);[m
[32m+[m[32mrator,[m
    ACTIONS(135), 16,[m
      anon_sym_PLUS,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DASH,[m
      anon_sym_STAR,[m
[32m+[m[32m      anon_sym_SLASH,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_PERCENT,[m
      anon_sym_PIPE_PIPE,[m
  [m
\ No newline at end of file[m
     anon_sym_AMP_AM[m
\ No newline at end of file[m
 P,[m
      anon[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_flag_shorthand_name);[m
[32m+[m[32m_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_BANG_EQ,[m
      anon_sym_GT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT,[m
      anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
\ No newline at end of file[m
[32m+[m
  [373] = 15,[m
    ACTIONS(43)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_comment,[m
    ACTIONS(117), 1,[m
      anon_sym_LBR[m
\ No newline at end of file[m
 ACK,[m
    ACTIONS(11[m
\ No newline at end of file[m
 9), 1,[m
      [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);[m
[32m+[m[32msym_number_literal,[m
    ACTIONS(121), 1,[m
[32m+[m[32m      anon_sym_DQUOTE,[m
    ACTIONS(123), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_SQUOTE,[m
    ACTIONS(125), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_DOLLAR,[m
    ACTIONS(129), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR_LPAREN,[m
    ACTIONS(1[m
\ No newline at end of file[m
[32m+[m[32m31), 1,[m
      sym_identifier,[m
    ACTIONS(133), 1,[m
      anon_sy[m
\ No newline at end of file[m
 m_LBRACE,[m
    STATE[m
\ No newline at end of file[m
 (6), 1,[m
     [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m aux_sym_command_repeat1,[m
    ACTIONS(25)[m
\ No newline at end of file[m
 , 2,[m
      anon_sym[m
\ No newline at end of file[m
 _PIPE,[m
      [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_let);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32manon_sym_SEMI,[m
    ACTIONS(45), 2,[m
      t[m
\ No newline at end of file[m
[32m+[m[32ms_builtin_sym_end,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LF,[m
    ACTIONS(127), 2,[m
      aux_sym_[m
\ No newline at end of file[m
[32m+[m[32mfile_path_token1,[m
      aux_[m
\ No newline at end of file[m
[32m+[m[32msym_file_path_token2,[m
    STATE(45), 11,[m
  [m
\ No newline at end of file[m
     sym__expression[m
\ No newline at end of file[m
 ,[m
      sym_s[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_let);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mtring,[m
      sym_value_path,[m
      sym_fil[m
\ No newline at end of file[m
[32m+[m[32me_path,[m
      sym_range,[m
      sym_command[m
\ No newline at end of file[m
[32m+[m[32m_substitution,[m
      sym_math_m[m
\ No newline at end of file[m
[32m+[m[32mode,[m
      sym_table,[m
      sym_array,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_block,[m
      sym_oper[m
\ No newline at end of file[m
[32m+[m[32mator,[m
    ACTIONS(135), 16,[m
      anon_sym_[m
\ No newline at end of file[m
 PLUS,[m
      anon_sy[m
\ No newline at end of file[m
 m_DASH,[m
     [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_EQ);[m
[32m+[m[32m anon_sym_STAR,[m
      anon_sym_SLASH,[m
    [m
\ No newline at end of file[m
   anon_sym_PERCENT,[m
\ No newline at end of file[m
 [m
      anon_s[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_EQ);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == '~') ADVANCE(136);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
\ No newline at end of file[m
 [m
      anon_sym_BAN[m
\ No newline at end of file[m
 G_EQ,[m
      a[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_PIPE);[m
[32m+[m[32mnon_sym_GT,[m
      anon_sym_GT_EQ,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LT_EQ,[m
      anon_sym_LT,[m
      anon_sym_LT_L[m
\ No newline at end of file[m
[32m+[m[32mT,[m
      anon_sym_GT_GT,[m
  [447] = 17,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(137), 1,[m
      anon_sym_LBRACK,[m
    ACTIONS(139), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_RBRACK,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(141), 1,[m
      sym_number_l[m
\ No newline at end of file[m
[32m+[m[32miteral,[m
    ACTIONS(143), 1,[m
      anon_sym[m
\ No newline at end of file[m
 _DQUOTE,[m
    ACTION[m
\ No newline at end of file[m
 S(145), 1,[m
  [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_PIPE);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == '|') ADVANCE(132);[m
[31m-      if (!sym_word_character_set_2(lookahead)) ADVANCE(83);[m
[32m+[m[32m    anon_sym_SQUOTE,[m
    ACTIONS(147), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DOLLAR,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(151), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(153), 1,[m
      sym_identifier,[m
    ACTIONS(155)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_LBRACE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  STATE(19), 1,[m
      aux_sym_array_repeat1,[m
    STATE(195), 1,[m
[32m+[m[32m      aux_sym_column_header_[m
\ No newline at end of file[m
[32m+[m[32mrepeat1,[m
    STATE(269), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_column_header,[m
    ACTIONS(149), 2,[m
       aux_sym_file_[m
\ No newline at end of file[m
 path_token1,[m
[31m-      ACCEPT_TOKEN(anon_sym_PIPE);[m
[31m-      if (lookahead == '|') ADVANCE(131);[m
[32m+[m[32m      aux_sym_file_path_token2,[m
    ACTIO[m
\ No newline at end of file[m
 NS(157), 7,[m
      a[m
\ No newline at end of file[m
 non_sym_PLUS,[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_number_literal);[m
[31m-      if (lookahead == '.') ADVANCE(71);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m
      anon_sym_DASH,[m
      anon_sym_STAR[m
\ No newline at end of file[m
 ,[m
      anon_sym_SL[m
\ No newline at end of file[m
 ASH,[m
      an[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_number_literal);[m
[31m-      if (lookahead == '.') ADVANCE(72);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);[m
[32m+[m[32mon_sym_PERCENT,[m
      anon_sym_GT,[m
      [m
\ No newline at end of file[m
 anon_sym_LT,[m
    AC[m
\ No newline at end of file[m
 TIONS(159), 9[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_number_literal);[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);[m
[32m+[m[32m,[m
      anon_sym_PIPE_PIPE,[m
      anon_sym[m
\ No newline at end of file[m
 _AMP_AMP,[m
      ano[m
\ No newline at end of file[m
 n_sym_EQ_TILD[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_number_literal);[m
[31m-      if (lookahead == '.') ADVANCE(69);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);[m
[32m+[m[32mE,[m
      anon_sym_EQ_EQ,[m
      anon_sym_BA[m
\ No newline at end of file[m
[32m+[m[32mNG_EQ,[m
      anon_sym_GT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT_EQ,[m
      anon_sym_LT_LT,[m
[32m+[m[32m      anon_sym_GT_GT,[m
    ST[m
\ No newline at end of file[m
[32m+[m[32mATE(219), 11,[m
      sym__expression,[m
      [m
\ No newline at end of file[m
 sym_string,[m
      s[m
\ No newline at end of file[m
 ym_value_path[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_number_literal);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m,[m
      sym_file_path,[m
      sym_range,[m
  [m
\ No newline at end of file[m
     sym_command_sub[m
\ No newline at end of file[m
 stitution,[m
  [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_number_literal);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);[m
[32m+[m[32m    sym_math_mode,[m
      sym_ta[m
\ No newline at end of file[m
[32m+[m[32mble,[m
      sym_array,[m
      sym_block,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_operator,[m
  [524] = 1[m
\ No newline at end of file[m
[32m+[m[32m6,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
 [m
\ No newline at end of file[m
    ACTIONS(137), 1,[m
\ No newline at end of file[m
 [m
      anon_s[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '&') ADVANCE(134);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mym_LBRACK,[m
    ACTIONS(141), 1,[m
      sym_number_lit[m
\ No newline at end of file[m
[32m+[m[32meral,[m
    ACTIONS(143), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_DQUOTE,[m
    ACTIONS(145), 1,[m
      anon_sym_SQUOTE,[m
     ACTIONS(147), 1[m
\ No newline at end of file[m
 ,[m
      anon_[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '=') ADVANCE(139);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32msym_DOLLAR,[m
    ACTIONS(151), 1,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR_LPAREN,[m
    ACTIONS(155), 1,[m
      anon_sym_LBRAC[m
\ No newline at end of file[m
[32m+[m[32mE,[m
    ACTIONS(161), 1,[m
      anon_sym_RBRACK,[m
    ACTIONS(163),[m
\ No newline at end of file[m
  1,[m
      sym_ident[m
\ No newline at end of file[m
 ifier,[m
    ST[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == 'e') ADVANCE(78);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mATE(15), 1,[m
      aux_sym_array_repeat1,[m
    STATE(2[m
\ No newline at end of file[m
[32m+[m[32m66), 1,[m
      sym_column_header,[m
    ACTIONS(149), 2[m
\ No newline at end of file[m
[32m+[m[32m,[m
      aux_sym_file_path_toke[m
\ No newline at end of file[m
[32m+[m[32mn1,[m
      aux_sym_file_path_token2,[m
    ACTIONS(157), 7,[m
      a[m
\ No newline at end of file[m
 non_sym_PLUS,[m
     [m
\ No newline at end of file[m
  anon_sym_DAS[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == 'e') ADVANCE(81);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mH,[m
      anon_sym_STAR,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_SLASH,[m
      anon_sym_PERCENT,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT,[m
      anon_sym_LT,[m
    ACTIONS(159), 9,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_PIPE_PIPE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
 [m
\ No newline at end of file[m
      anon_sym_BANG_[m
\ No newline at end of file[m
 EQ,[m
      ano[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == 'e') ADVANCE(80);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mn_sym_GT_EQ,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLT_EQ,[m
      anon_sym_LT_LT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_GT_GT,[m
    STATE(2[m
\ No newline at end of file[m
[32m+[m[32m19), 11,[m
      sym__expression,[m
\ No newline at end of file[m
[32m+[m
      sym_string,[m
      sym_value_path,[m
 [m
\ No newline at end of file[m
      sym_file_path,[m
\ No newline at end of file[m
 [m
      sym_ra[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == 'f') ADVANCE(44);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mnge,[m
      sym_command_subst[m
\ No newline at end of file[m
[32m+[m[32mitution,[m
      sym_math_mode,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_table,[m
      sym_array[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_block,[m
      sym_operator,[m
  [[m
\ No newline at end of file[m
 598] = 16,[m
    ACTI[m
\ No newline at end of file[m
 ONS(43), 1,[m
 [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == 'r') ADVANCE(77);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m     sym_comment,[m
    ACTIONS(137), 1,[m
 [m
\ No newline at end of file[m
      anon_sym_LBRAC[m
\ No newline at end of file[m
 K,[m
    ACTION[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == 's') ADVANCE(82);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mS(141), 1,[m
      sym_number_literal,[m
   [m
\ No newline at end of file[m
  ACTIONS(143), 1,[m
 [m
\ No newline at end of file[m
      anon_sym[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == 't') ADVANCE(61);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m_DQUOTE,[m
    ACTIONS(145), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_SQUOTE,[m
    ACTIONS(147), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_DOLLAR,[m
    ACTIONS(151[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(155), 1,[m
      anon_sym_LBRACE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(163), 1,[m
      sym_identifier,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(165), 1,[m
      anon_sym_RBRACK,[m
[32m+[m[32m    STATE(17), 1,[m
      aux_sym_array_repe[m
\ No newline at end of file[m
[32m+[m[32mat1,[m
    STATE(272), 1,[m
      sym_column_h[m
\ No newline at end of file[m
[32m+[m[32meader,[m
    ACTIONS(149), 2,[m
      aux_sym_[m
\ No newline at end of file[m
[32m+[m[32mfile_path_token1,[m
      aux_sym_file_path_[m
\ No newline at end of file[m
[32m+[m[32mtoken2,[m
    ACTIONS(157), 7,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_PLUS,[m
      anon_sym_DASH,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_STAR,[m
      anon_sym_SLASH,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PERCENT,[m
      anon_sym_GT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT,[m
    ACTIONS(159), 9,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_BANG_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT_EQ,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLT_EQ,[m
      anon_sym_LT_LT,[m
      an[m
\ No newline at end of file[m
 on_sym_GT_GT,[m
    S[m
\ No newline at end of file[m
 TATE(219), 11[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == 't') ADVANCE(59);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m,[m
      sym__expression,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_string,[m
      sym_value_path,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_file_path,[m
      sym_range,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcommand_substitution,[m
      sym_math_mode,[m
\ No newline at end of file[m
[32m+[m
      sym_table,[m
      sym_array,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_block,[m
      sym_operator,[m
  [672] = 1[m
\ No newline at end of file[m
[32m+[m[32m6,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(137), 1,[m
      anon_sym_LBRACK[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(141), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_number_literal,[m
    ACTIONS(1[m
\ No newline at end of file[m
[32m+[m[32m43), 1,[m
      anon_sym_DQUOTE,[m
    AC[m
\ No newline at end of file[m
 TIONS(145), 1,[m
    [m
\ No newline at end of file[m
   anon_sym_SQ[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_word);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mUOTE,[m
    ACTIONS(147), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOLLAR,[m
    ACTIONS(151), 1,[m
[32m+[m[32m      anon_sym_DOLLAR_LPAREN,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m155), 1,[m
      anon_sym_LBRACE,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(163), 1,[m
      sym_identifier,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(167), 1,[m
      anon_sym_RBRACK,[m
    ST[m
\ No newline at end of file[m
[32m+[m[32mATE(19), 1,[m
      aux_sym_array_repeat1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(269), 1,[m
      sym_column_header,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(149), 2,[m
      aux_sym_file_[m
\ No newline at end of file[m
[32m+[m[32mpath_token1,[m
      aux_sym_file_path_token2[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(157), 7,[m
      anon_sym_PLUS[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DASH,[m
      anon_sym_STAR[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_SLASH,[m
      anon_sym_PER[m
\ No newline at end of file[m
[32m+[m[32mCENT,[m
      anon_sym_GT,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mT,[m
    ACTIONS(159), 9,[m
      anon_sym_PIP[m
\ No newline at end of file[m
[32m+[m[32mE_PIPE,[m
      anon_sym_AMP_AMP,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_BANG_EQ,[m
      anon_sym_GT_EQ,[m
[32m+[m[32m      anon_sym_LT_EQ,[m
      anon_sym_LT_LT[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_GT_GT,[m
    STATE(219), 11[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym__expression,[m
      sym_string[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_value_path,[m
      sym_file_pat[m
\ No newline at end of file[m
[32m+[m[32mh,[m
      sym_range,[m
      sym_command_subs[m
\ No newline at end of file[m
[32m+[m[32mtitution,[m
      sym_math_mode,[m
[32m+[m[32m      sym_table,[m
      sym_array,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_block,[m
      sym_operator,[m
  [746] = 16,[m
    ACTIONS(43), 1,[m
[32m+[m[32m      sym_comment,[m
    ACTIONS(137), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LBRACK,[m
    ACTIONS(141), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_number_literal,[m
    ACTIONS(143), 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mDQUOTE,[m
    ACTIONS(145), 1,[m
      anon[m
\ No newline at end of file[m
 _sym_SQUOTE,[m
    AC[m
\ No newline at end of file[m
 TIONS(147), 1[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DQUOTE);[m
[32m+[m[32m,[m
      anon_sym_DOLLAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(151), 1,[m
      anon_sym_DOLLAR_LPA[m
\ No newline at end of file[m
[32m+[m[32mREN,[m
    ACTIONS(155), 1,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mBRACE,[m
    ACTIONS(163), 1,[m
      sym_ide[m
\ No newline at end of file[m
[32m+[m[32mntifier,[m
    ACTIONS(169), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_RBRACK,[m
    STATE(13), 1,[m
      aux_sym[m
\ No newline at end of file[m
[32m+[m[32m_array_repeat1,[m
    STATE(256), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_column_header,[m
    ACTIONS(149), 2,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   aux_sym_file_path_token1,[m
      aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_file_path_token2,[m
    ACTIONS(157), 7,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PLUS,[m
      anon_sym_DASH,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_STAR,[m
      anon_sym_SLASH,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PERCENT,[m
      anon_sym_GT,[m
[32m+[m[32m      anon_sym_LT,[m
    ACTIONS(159), 9,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PIPE_PIPE,[m
      anon_sym_AMP[m
\ No newline at end of file[m
[32m+[m[32m_AMP,[m
      anon_sym_EQ_TILDE,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  STATE(219), 11,[m
      sym__expression,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_string,[m
      sym_value_path,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_file_path,[m
      sym_range,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_command_substitution,[m
      sym_math_m[m
\ No newline at end of file[m
[32m+[m[32mode,[m
      sym_table,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_array,[m
      sym_block,[m
      sym_operat[m
\ No newline at end of file[m
[32m+[m[32mor,[m
  [820] = 15,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(141), 1,[m
      sym_number_literal,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m143), 1,[m
      anon_sym_DQUOTE[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(145), 1,[m
      anon_sym_SQUOTE,[m
    ACTIONS(147), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_DOLLAR,[m
    ACTIONS(1[m
\ No newline at end of file[m
 51), 1,[m
      anon_[m
\ No newline at end of file[m
 sym_DOLLAR_LP[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_SQUOTE);[m
[32m+[m[32mAREN,[m
    ACTIONS(155), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_LBRACE,[m
    ACTIONS(163), 1,[m
[32m+[m[32m      sym_identifier,[m
    ACTIONS(171), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LBRACK,[m
    ACTIONS(173),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_RBRACK,[m
    STATE(16), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      aux_sym_array_repeat1,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(149), 2,[m
      aux_sym_file_path_token1,[m
\ No newline at end of file[m
[32m+[m
      aux_sym_file_path_token2,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(157), 7,[m
      anon_sym_PLUS,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DASH,[m
      anon_sym_STAR,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_SLASH,[m
      anon_sym_PERCENT,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_GT,[m
      anon_sym_LT,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(159), 9,[m
      anon_sym_PIPE_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_AMP_AMP,[m
      anon_sym_EQ_TIL[m
\ No newline at end of file[m
[32m+[m[32mDE,[m
      anon_sym_EQ_EQ,[m
      anon_sym_B[m
\ No newline at end of file[m
[32m+[m[32mANG_EQ,[m
      anon_sym_GT_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT_EQ,[m
      anon_sym_LT_LT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_GT_GT,[m
    STATE(219), 11,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m__expression,[m
      sym_string,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mvalue_path,[m
      sym_file_path,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_range,[m
      sym_command_substitution,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_math_mode,[m
      sym_table,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_array,[m
      sym_block,[m
      sym_ope[m
\ No newline at end of file[m
[32m+[m[32mrator,[m
  [891] = 15,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(43), 1,[m
      sym_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m141), 1,[m
      sym_number_literal,[m
    ACTIONS(143), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DQUOTE,[m
    ACTIONS(145), 1,[m
      anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mQUOTE,[m
    ACTIONS(147), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DOLLAR,[m
    ACTIONS(151), 1,[m
      anon_sym_DOLLAR_[m
\ No newline at end of file[m
[32m+[m[32mLPAREN,[m
    ACTIONS(155), 1,[m
      anon[m
\ No newline at end of file[m
 _sym_LBRACE,[m
    AC[m
\ No newline at end of file[m
 TIONS(163), 1[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_qouted_string_content);[m
[31m-      if (lookahead == '\n') ADVANCE(88);[m
[31m-      if (lookahead == '\\') ADVANCE(117);[m
[31m-      if (lookahead != 0 &&[m
[31m-          lookahead != '"') ADVANCE(86);[m
[31m-      END_STATE();[m
[31m-    case 87:[m
[31m-      ACCEPT_TOKEN(sym_qouted_string_content);[m
[31m-      if (lookahead == '"') ADVANCE(84);[m
[31m-      if (lookahead == '#') ADVANCE(86);[m
[31m-      if (lookahead == '\\') ADVANCE(36);[m
[32m+[m[32m,[m
      sym_identifier,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(171), 1,[m
      anon_sym_LBRACK,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(175), 1,[m
      anon_sym_RBRACK,[m
[32m+[m[32m    STATE(18), 1,[m
      aux_sym_array_repe[m
\ No newline at end of file[m
[32m+[m[32mat1,[m
    ACTIONS(149), 2,[m
      aux_sym_fi[m
\ No newline at end of file[m
[32m+[m[32mle_path_token1,[m
      aux_sym_file_path_t[m
\ No newline at end of file[m
[32m+[m[32moken2,[m
    ACTIONS(157), 7,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_PLUS,[m
      anon_sym_DASH,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_STAR,[m
      anon_sym_SLASH,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PERCENT,[m
      anon_sym_GT,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LT,[m
    ACTIONS(159), 9,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
     [m
\ No newline at end of file[m
  anon_sym_EQ_TILDE,[m
      anon_[m
\ No newline at end of file[m
 sym_EQ_EQ,[m
      anon_sym_BANG_[m
\ No newline at end of file[m
 EQ,[m
      anon_sym_GT_EQ,[m
     [m
\ No newline at end of file[m
[31m-          lookahead == ' ') ADVANCE(87);[m
[31m-      if (lookahead != 0) ADVANCE(88);[m
[32m+[m[32m anon_sym_LT_EQ,[m
      anon_sym_LT_LT[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_GT_GT,[m
    STATE(219), 11,[m
      sym__expressio[m
\ No newline at end of file[m
[32m+[m[32mn,[m
      sym_string,[m
      sym_value_path,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_file_path,[m
      sym_range,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_command_substitution,[m
      sym_math_mode,[m
      sym_ta[m
\ No newline at end of file[m
[32m+[m[32mble,[m
      sym_arra[m
\ No newline at end of file[m
[32m+[m[32my,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mblock,[m
      sym_operator,[m
  [962] = 15,[m
\ No newline at end of file[m
 [m
    ACTIONS(43), 1[m
\ No newline at end of file[m
 ,[m
      sym_c[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_qouted_string_content);[m
[31m-      if (lookahead == '\\') ADVANCE(36);[m
[31m-      if (lookahead != 0 &&[m
[31m-          lookahead != '"') ADVANCE(88);[m
[32m+[m[32momment,[m
    ACTIONS(141), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_number_literal,[m
    ACTIONS(143), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DQUOTE,[m
    ACTIONS(145), 1,[m
      anon_sym_SQUO[m
\ No newline at end of file[m
[32m+[m[32mTE,[m
    ACTIONS(147), 1,[m
      anon_sym_DOLLAR,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(151), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR_LPAREN,[m
    ACTIONS(155), 1,[m
      anon_sym_LBRACE,[m
   [m
\ No newline at end of file[m
  ACTIONS(163), 1,[m
 [m
\ No newline at end of file[m
      sym_iden[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_single_qouted_string_content);[m
[31m-      if (lookahead == '\n') ADVANCE(91);[m
[31m-      if (lookahead == '\\') ADVANCE(116);[m
[31m-      if (lookahead != 0 &&[m
[31m-          lookahead != '\'') ADVANCE(89);[m
[32m+[m[32mtifier,[m
    ACTIONS(171), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LBRACK,[m
    ACTIONS(177), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_RBRACK,[m
    STATE(16), 1,[m
      aux_sym_array_repe[m
\ No newline at end of file[m
 at1,[m
    ACTIONS(14[m
\ No newline at end of file[m
 9), 2,[m
      [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_single_qouted_string_content);[m
[31m-      if (lookahead == '#') ADVANCE(89);[m
[31m-      if (lookahead == '\'') ADVANCE(85);[m
[31m-      if (lookahead == '\\') ADVANCE(35);[m
[31m-      if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(90);[m
[31m-      if (lookahead != 0) ADVANCE(91);[m
[32m+[m[32maux_sym_file_path_token1,[m
      aux_s[m
\ No newline at end of file[m
 ym_file_path_token2[m
\ No newline at end of file[m
 ,[m
    ACTIONS[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_single_qouted_string_content);[m
[31m-      if (lookahead == '\\') ADVANCE(35);[m
[32m+[m[32m(157), 7,[m
      anon_sym_PLUS,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DASH,[m
      anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mTAR,[m
      anon_sym_SLASH,[m
      anon_sym_[m
\ No newline at end of file[m
 PERCENT,[m
      anon_sym_GT,[m
[31m-          lookahead != '\'') ADVANCE(91);[m
[32m+[m[32m      anon_sym_LT,[m
    ACTIONS(159), 9,[m
   [m
\ No newline at end of file[m
    anon_sym_PIPE_PI[m
\ No newline at end of file[m
 PE,[m
      ano[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOLLAR);[m
[31m-      if (lookahead == '(') ADVANCE(103);[m
[32m+[m[32mn_sym_AMP_AMP,[m
      anon_sym_EQ_TIL[m
\ No newline at end of file[m
 DE,[m
      anon_sym_[m
\ No newline at end of file[m
 EQ_EQ,[m
      [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT);[m
[32m+[m[32manon_sym_BANG_EQ,[m
      anon_sym_GT_[m
\ No newline at end of file[m
[32m+[m[32mEQ,[m
      anon_sym_LT_EQ,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mT_LT,[m
      anon_sym_GT_GT,[m
    STATE(219), 11,[m
      sym__exp[m
\ No newline at end of file[m
 ression,[m
      sym_[m
\ No newline at end of file[m
 string,[m
     [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT);[m
[31m-      if (lookahead == '.') ADVANCE(101);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(97);[m
[31m-      if (lookahead != 0 &&[m
[31m-          (lookahead < '"' || '$' < lookahead) &&[m
[31m-          (lookahead < '\'' || ')' < lookahead) &&[m
[31m-          lookahead != '-' &&[m
[31m-          lookahead != ';' &&[m
[31m-          (lookahead < '[' || ']' < lookahead) &&[m
[31m-          lookahead != '{' &&[m
[31m-          lookahead != '}') ADVANCE(83);[m
[32m+[m[32m sym_value_path,[m
      sym_file_path,[m
\ No newline at end of file[m
 [m
      sym_range,[m
 [m
\ No newline at end of file[m
      sym_comm[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT);[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(97);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);[m
[32m+[m[32mand_substitution,[m
      sym_math_mode[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_table,[m
      sym_ar[m
\ No newline at end of file[m
[32m+[m[32mray,[m
      sym_block,[m
      sym_operator,[m
[32m+[m[32m  [1033] = 15,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_comment,[m
    ACTIONS(179),[m
\ No newline at end of file[m
  1,[m
      anon_sym_[m
\ No newline at end of file[m
 LBRACK,[m
    A[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT);[m
[31m-      if (lookahead == '.') ADVANCE(98);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (lookahead == '\t' ||[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(97);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);[m
[32m+[m[32mCTIONS(182), 1,[m
      anon_sym_RBRAC[m
\ No newline at end of file[m
 K,[m
    ACTIONS(184)[m
\ No newline at end of file[m
 , 1,[m
      sy[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(aux_sym_file_path_token1);[m
[32m+[m[32mm_number_literal,[m
    ACTIONS(187), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_DQUOTE,[m
    ACTIONS(190)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_SQUOTE,[m
    ACTIONS(193), 1,[m
      anon_sy[m
\ No newline at end of file[m
 m_DOLLAR,[m
    ACTIO[m
\ No newline at end of file[m
 NS(199), 1,[m
 [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(aux_sym_file_path_token1);[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);[m
[32m+[m[32m     anon_sym_DOLLAR_LPAREN,[m
    ACT[m
\ No newline at end of file[m
 IONS(202), 1,[m
     [m
\ No newline at end of file[m
  sym_identifi[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(aux_sym_file_path_token2);[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);[m
[32m+[m[32mer,[m
    ACTIONS(205), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LBRACE,[m
    STATE(16), 1,[m
      aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_array_repeat1,[m
    ACTIONS(196), 2,[m
      aux_sym_file_path_[m
\ No newline at end of file[m
 token1,[m
      aux_s[m
\ No newline at end of file[m
 ym_file_path_t[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT_DOT);[m
[32m+[m[32moken2,[m
    ACTIONS(208), 7,[m
      ano[m
\ No newline at end of file[m
 n_sym_PLUS,[m
      a[m
\ No newline at end of file[m
 non_sym_DASH,[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT_DOT);[m
[31m-      if (lookahead == '.') ADVANCE(79);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m      anon_sym_STAR,[m
      anon_sym_S[m
\ No newline at end of file[m
 LASH,[m
      anon_sy[m
\ No newline at end of file[m
 m_PERCENT,[m
   [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOT_DOT);[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);[m
[32m+[m[32m   anon_sym_GT,[m
      anon_sym_LT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(211), 9,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_EQ_TILDE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
    [m
\ No newline at end of file[m
   anon_sym_GT_EQ,[m
 [m
\ No newline at end of file[m
      anon_sym_[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DOLLAR_LPAREN);[m
[31m-      END_STATE();[m
[31m-    case 104:[m
[31m-      ACCEPT_TOKEN(sym_identifier);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);[m
[32m+[m[32mLT_EQ,[m
      anon_sym_LT_LT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT_GT,[m
    STATE(219), 11,[m
      sym__expression,[m
     [m
\ No newline at end of file[m
  sym_string,[m
      sym_value_path,[m
      sym_file_pa[m
\ No newline at end of file[m
 th,[m
      sym_range,[m
      sym[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(104);[m
[32m+[m[32m_command_substitution,[m
      sym_math_mode,[m
      sym_table,[m
   [m
\ No newline at end of file[m
    sym_array,[m
     [m
\ No newline at end of file[m
[31m-    case 105:[m
[31m-      ACCEPT_TOKEN(sym_identifier);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (lookahead == '.') ADVANCE(16);[m
[31m-      if (lookahead == '/') ADVANCE(33);[m
[32m+[m[32m sym_block,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_operator,[m
  [1104] = 15,[m
  [m
\ No newline at end of file[m
   ACTIONS(43), 1,[m
      sym_comment,[m
    ACTIONS(141[m
\ No newline at end of file[m
 ), 1,[m
      sym_number_literal,[m
    ACTIONS(143), 1,[m
\ No newline at end of file[m
 [m
      anon_sym_DQUOTE,[m
    AC[m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);[m
[32m+[m[32mTIONS(145), 1,[m
      anon_sym_SQUOTE,[m
    ACTIONS(147), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_DOLLAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(151[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    ACTIO[m
\ No newline at end of file[m
 NS(155), 1,[m
      a[m
\ No newline at end of file[m
 non_sym_LBRACE[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_identifier);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (lookahead == 'e') ADVANCE(108);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32m,[m
    ACTIONS(163), 1,[m
      sym_identifier,[m
 [m
\ No newline at end of file[m
    ACTIONS(171), 1,[m
\ No newline at end of file[m
 [m
      anon_sy[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_identifier);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (lookahead == 'e') ADVANCE(109);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32mm_LBRACK,[m
    ACTIONS(214), 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mRBRACK,[m
    STATE(16), 1,[m
      aux_sym_ar[m
\ No newline at end of file[m
[32m+[m[32mray_repeat1,[m
    ACTIONS(149), 2,[m
      aux_sym_file_path_toke[m
\ No newline at end of file[m
 n1,[m
      aux_sym_f[m
\ No newline at end of file[m
 ile_path_token[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_identifier);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (lookahead == 'f') ADVANCE(43);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);[m
[32m+[m[32m2,[m
    ACTIONS(157), 7,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_PLUS,[m
      anon_sym_DASH,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_STAR,[m
      anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
      [m
\ No newline at end of file[m
 anon_sym_GT,[m
      anon_sym_LT,[m
    ACTIONS(159), 9,[m
\ No newline at end of file[m
 [m
      anon_sym_PIPE_PIPE,[m
   [m
\ No newline at end of file[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32m   anon_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      anon_sym_EQ_[m
\ No newline at end of file[m
 EQ,[m
      anon_sym_[m
\ No newline at end of file[m
 BANG_EQ,[m
     [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_identifier);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (lookahead == 't') ADVANCE(60);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32m anon_sym_GT_EQ,[m
      anon_sym_LT[m
\ No newline at end of file[m
[32m+[m[32m_EQ,[m
      anon_sym_LT_LT,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mGT_GT,[m
    STATE(219), 11,[m
      sym__expression,[m
      sym_st[m
\ No newline at end of file[m
 ring,[m
      sym_val[m
\ No newline at end of file[m
 ue_path,[m
     [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_identifier);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);[m
[31m-      if (('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(110);[m
[32m+[m[32m sym_file_path,[m
      sym_range,[m
       sym_command_s[m
\ No newline at end of file[m
 ubstitution,[m
 [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_identifier);[m
[31m-      if (lookahead == '-') ADVANCE(32);[m
[31m-      if (('0' <= lookahead && lookahead <= '9') ||[m
[31m-          ('A' <= lookahead && lookahead <= 'Z') ||[m
[31m-          lookahead == '_' ||[m
[31m-          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(111);[m
[32m+[m[32m     sym_math_mode,[m
      sym_tab[m
\ No newline at end of file[m
[32m+[m[32mle,[m
      sym_array,[m
      sym_block,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_operator,[m
  [1175] = 15,[m
    ACTIONS(43), 1,[m
      sym_c[m
\ No newline at end of file[m
 omment,[m
    ACTIONS[m
\ No newline at end of file[m
 (141), 1,[m
    [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_SEMI);[m
[32m+[m[32m  sym_number_literal,[m
    ACTIONS(1[m
\ No newline at end of file[m
 43), 1,[m
      anon_[m
\ No newline at end of file[m
 sym_DQUOTE,[m
  [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_);[m
[31m-      if (lookahead == ' ') ADVANCE(113);[m
[32m+[m[32m  ACTIONS(145), 1,[m
      anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mQUOTE,[m
    ACTIONS(147), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DOLLAR,[m
    ACTIONS(151), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DOLLAR_LPAREN,[m
    ACTIONS(155), 1,[m
      anon_sym_LBRACE,[m
     ACTIONS(163), 1[m
\ No newline at end of file[m
 ,[m
      sym_id[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LBRACE);[m
[32m+[m[32mentifier,[m
    ACTIONS(171), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LBRACK,[m
    ACTIONS(216), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_RBRACK,[m
    STATE([m
\ No newline at end of file[m
[32m+[m[32m16), 1,[m
      aux_sym_array_repeat1,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(149), 2,[m
      aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_file_path_token1,[m
      aux_sym_file_path[m
\ No newline at end of file[m
 _token2,[m
    ACTION[m
\ No newline at end of file[m
 S(157), 7,[m
   [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_RBRACE);[m
[32m+[m[32m   anon_sym_PLUS,[m
      anon_sym_DA[m
\ No newline at end of file[m
[32m+[m[32mSH,[m
      anon_sym_STAR,[m
      anon_sym_SL[m
\ No newline at end of file[m
 ASH,[m
      anon_sym[m
\ No newline at end of file[m
 _PERCENT,[m
    [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_comment);[m
[31m-      if (lookahead == '\n') ADVANCE(91);[m
[31m-      if (lookahead != 0) ADVANCE(89);[m
[32m+[m[32m  anon_sym_GT,[m
      anon_sym_LT,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(159), 9,[m
      anon_sym_PIPE_PIPE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_AMP_AMP,[m
      anon_sym_EQ_TI[m
\ No newline at end of file[m
[32m+[m[32mLDE,[m
      anon_sym_EQ_EQ,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mBANG_EQ,[m
      anon_sym_GT_EQ,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LT_EQ,[m
      anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
    STATE[m
\ No newline at end of file[m
[32m+[m[32m(219), 11,[m
      sym__expression,[m
      sym_string,[m
[32m+[m[32m      sym_value_path,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_file_path,[m
      sym_range,[m
      sym_command_substitution,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_math_mode,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_table,[m
      sym_array,[m
      sym_block,[m
 [m
\ No newline at end of file[m
      sym_operator,[m
   [1246] = 15,[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_comment);[m
[31m-      if (lookahead == '\n') ADVANCE(88);[m
[31m-      if (lookahead != 0) ADVANCE(86);[m
[32m+[m
    ACTIONS(43), 1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(141), 1,[m
      sym_number_liter[m
\ No newline at end of file[m
[32m+[m[32mal,[m
    ACTIONS(143), 1,[m
      anon_sym_DQ[m
\ No newline at end of file[m
[32m+[m[32mUOTE,[m
    ACTIONS(145), 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mSQUOTE,[m
    ACTIONS(147), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR,[m
    ACTIONS(151), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(155), 1,[m
      anon_sym_LBRACE,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(163), 1,[m
      sym_identifier[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(171), 1,[m
      anon_sym_LBRACK,[m
    ACTIONS(218), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_RBRACK,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  STATE(16), 1,[m
      aux_sym_array_repeat1[m
\ No newline at end of file[m
 ,[m
    ACTIONS(149),[m
\ No newline at end of file[m
  2,[m
      aux_[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(sym_comment);[m
[32m+[m[32msym_file_path_token1,[m
      aux_sym_file[m
\ No newline at end of file[m
[32m+[m[32m_path_token2,[m
    ACTIONS(157), 7,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PLUS,[m
      anon_sym_DASH,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_STAR,[m
      anon_sym_SLASH,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PERCENT,[m
      anon_sym_GT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT,[m
    ACTIONS(159), 9,[m
      anon_sym_PIPE_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_EQ_EQ,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mBANG_EQ,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon_[m
\ No newline at end of file[m
 sym_LT_LT,[m
      anon_sym_GT[m
\ No newline at end of file[m
[31m-          lookahead != '\n') ADVANCE(118);[m
[32m+[m[32m_GT,[m
    STATE(219), 11,[m
      sym__express[m
\ No newline at end of file[m
 ion,[m
      sym_stri[m
\ No newline at end of file[m
 ng,[m
      sym_[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LF);[m
[31m-      if (lookahead == '\n') ADVANCE(119);[m
[31m-      if (lookahead == '\t' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(1);[m
[32m+[m[32mvalue_path,[m
      sym_file_path,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_range,[m
      sym_command_substitution,[m
[32m+[m[32m      sym_math_mode,[m
      sym_table,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_array,[m
      sym_block,[m
      sym_operator,[m
  [1317] = 13,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(15), 1,[m
      anon_sym_DOLLAR,[m
    ACTIONS(17), 1[m
\ No newline at end of file[m
 ,[m
      anon_sym_DO[m
\ No newline at end of file[m
 LLAR_LPAREN,[m
 [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LF);[m
[31m-      if (lookahead == '\n') ADVANCE(120);[m
[32m+[m[32m   ACTIONS(43), 1,[m
      sym_comment,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(220), 1,[m
      anon_sym_LBRACK,[m
[32m+[m[32m    ACTIONS(222), 1,[m
      sym_number_literal,[m
    ACTIONS(224),[m
\ No newline at end of file[m
  1,[m
      anon_sym_[m
\ No newline at end of file[m
 DQUOTE,[m
    AC[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LF);[m
[31m-      if (lookahead == '\n') ADVANCE(121);[m
[31m-      if (lookahead == '\t' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') ADVANCE(2);[m
[32m+[m[32mTIONS(226), 1,[m
      anon_sym_SQUOTE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(230), 1,[m
      sym_identifier,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(232), 1,[m
      anon_sym_LBRACE,[m
    ACTIONS(228), 2,[m
[32m+[m[32m      aux_sym_file_path_token1,[m
      aux_sym_file_path_token2[m
\ No newline at end of file[m
 ,[m
    ACTIONS(234),[m
\ No newline at end of file[m
  7,[m
      anon[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_PLUS);[m
[32m+[m[32m_sym_PLUS,[m
      anon_sym_DASH,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_STAR,[m
      anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
     [m
\ No newline at end of file[m
  anon_sym_GT,[m
     [m
\ No newline at end of file[m
  anon_sym_LT,[m
[31m-      ACCEPT_TOKEN(anon_sym_PLUS);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m    ACTIONS(236), 9,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_TILDE,[m
      anon_sym_EQ_[m
\ No newline at end of file[m
[32m+[m[32mEQ,[m
      anon_sym_BANG_EQ,[m
      anon_sym_GT_EQ,[m
      anon_s[m
\ No newline at end of file[m
 ym_LT_EQ,[m
      ano[m
\ No newline at end of file[m
 n_sym_LT_LT,[m
 [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_DASH);[m
[32m+[m[32m     anon_sym_GT_GT,[m
    STATE[m
\ No newline at end of file[m
[32m+[m[32m(159), 11,[m
      sym__expression,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_string,[m
      sym_value_path,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mfile_path,[m
      sym_range,[m
      sym_command_substitution,[m
  [m
\ No newline at end of file[m
     sym_math_mode,[m
       sym_tabl[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_STAR);[m
[32m+[m[32me,[m
      sym_array,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mblock,[m
      sym_operator,[m
  [1382] = 5,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(43), 1,[m
      sym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(240), 1,[m
      anon_sym_DOT,[m
    ACTIONS(243), 1,[m
    [m
\ No newline at end of file[m
   anon_sym_LF,[m
    [m
\ No newline at end of file[m
 STATE(21), 1,[m
[31m-      ACCEPT_TOKEN(anon_sym_STAR);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m      aux_sym_value_path_repea[m
\ No newline at end of file[m
[32m+[m[32mt1,[m
    ACTIONS(238), 30,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mBRACK,[m
      anon_sym_RPAREN,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PIPE,[m
      sym_number_literal,[m
      anon_sym_DQUOTE,[m
    [m
\ No newline at end of file[m
   anon_sym_SQUOTE,[m
       anon_sym[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_SLASH);[m
[32m+[m[32m_DOLLAR,[m
      aux_sym_file_pa[m
\ No newline at end of file[m
[32m+[m[32mth_token1,[m
      aux_sym_file_path_token2,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DOLLAR_LPAREN,[m
      sym_i[m
\ No newline at end of file[m
[32m+[m[32mdentifier,[m
      anon_sym_SEMI,[m
      anon_sym_LBRACE,[m
      a[m
\ No newline at end of file[m
 non_sym_RBRACE,[m
   [m
\ No newline at end of file[m
    anon_sym_PL[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_SLASH);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mUS,[m
      anon_sym_DASH,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_STAR,[m
      anon_sym_SLASH,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_PERCENT,[m
      anon_sym_PIPE_P[m
\ No newline at end of file[m
[32m+[m[32mIPE,[m
      anon_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      an[m
\ No newline at end of file[m
 on_sym_EQ_EQ,[m
     [m
\ No newline at end of file[m
  anon_sym_BANG[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_PERCENT);[m
[32m+[m[32m_EQ,[m
      anon_sym_GT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LT,[m
      anon_sym_LT_LT,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_GT_GT,[m
  [1427] = 5,[m
    ACTIONS(43), 1,[m
      sym_c[m
\ No newline at end of file[m
 omment,[m
    ACTIONS[m
\ No newline at end of file[m
 (247), 1,[m
    [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_PERCENT);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m  anon_sym_DOT,[m
    ACTIONS(24[m
\ No newline at end of file[m
[32m+[m[32m9), 1,[m
      anon_sym_LF,[m
    STATE(21), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      aux_sym_value_path_repeat1,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(245), 30,[m
      anon_sym_LBRACK,[m
      anon_sym_RPAREN,[m
       anon_sym_PIPE[m
\ No newline at end of file[m
 ,[m
      sym_nu[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);[m
[32m+[m[32mmber_literal,[m
      anon_sym_D[m
\ No newline at end of file[m
[32m+[m[32mQUOTE,[m
      anon_sym_SQUOTE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DOLLAR,[m
      aux_sym_file_path_token1,[m
\ No newline at end of file[m
[32m+[m
      aux_sym_file_path_token2,[m
      anon_sym_DOLLAR_LPAREN,[m
\ No newline at end of file[m
 [m
      sym_identifi[m
\ No newline at end of file[m
 er,[m
      anon[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m_sym_SEMI,[m
      anon_sym_LBRA[m
\ No newline at end of file[m
[32m+[m[32mCE,[m
      anon_sym_RBRACE,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPLUS,[m
      anon_sym_DASH,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mSTAR,[m
      anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
      anon[m
\ No newline at end of file[m
 _sym_PIPE_PIPE,[m
   [m
\ No newline at end of file[m
    anon_sym_AM[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_AMP_AMP);[m
[32m+[m[32mP_AMP,[m
      anon_sym_EQ_TILDE[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_EQ_EQ,[m
      anon_sym_BAN[m
\ No newline at end of file[m
[32m+[m[32mG_EQ,[m
      anon_sym_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_[m
\ No newline at end of file[m
 LT_EQ,[m
      anon_s[m
\ No newline at end of file[m
 ym_LT,[m
      a[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_AMP_AMP);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mnon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
   [1472] = 5,[m
    A[m
\ No newline at end of file[m
 CTIONS(43), 1,[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_EQ_TILDE);[m
[32m+[m
      sym_comment,[m
    ACTIONS(247),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_DOT,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(253), 1,[m
      anon_sym_LF,[m
    STATE[m
\ No newline at end of file[m
[32m+[m[32m(22), 1,[m
      aux_sym_value[m
\ No newline at end of file[m
[32m+[m[32m_path_repeat1,[m
    ACTIONS(251), 30,[m
      [m
\ No newline at end of file[m
 anon_sym_LBRACK,[m
  [m
\ No newline at end of file[m
     anon_sym_R[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_EQ_TILDE);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mPAREN,[m
      anon_sym_PIPE,[m
      sym[m
\ No newline at end of file[m
 _number_literal,[m
  [m
\ No newline at end of file[m
     anon_sym_D[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_EQ_EQ);[m
[32m+[m[32mQUOTE,[m
      anon_sym_SQUOTE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DOLLAR,[m
      aux_sym_f[m
\ No newline at end of file[m
[32m+[m[32mile_path_token1,[m
      aux_sym_file_path_t[m
\ No newline at end of file[m
[32m+[m[32moken2,[m
      anon_sym_DOLLAR[m
\ No newline at end of file[m
[32m+[m[32m_LPAREN,[m
      sym_identifier,[m
      anon_s[m
\ No newline at end of file[m
 ym_SEMI,[m
      anon[m
\ No newline at end of file[m
 _sym_LBRACE,[m
 [m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_BANG_EQ);[m
[32m+[m[32m     anon_sym_RBRACE,[m
      anon_sym_PLUS,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DASH,[m
      anon_sym_STAR,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PIPE_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_AMP_AMP,[m
      anon_sym_EQ_TILD[m
\ No newline at end of file[m
 E,[m
      anon_sym_E[m
\ No newline at end of file[m
 Q_EQ,[m
      an[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_BANG_EQ);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mon_sym_BANG_EQ,[m
      anon_sym_GT,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT,[m
      anon_sym_LT_LT,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_GT_GT,[m
  [1517] = 3,[m
    ACTIONS(43), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(243), 1,[m
      anon_sym_LF,[m
[32m+[m[32m    ACTIONS(238), 31,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LBRACK,[m
      anon_sym_RPAREN,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_PIPE,[m
      sym_number_literal[m
\ No newline at end of file[m
 ,[m
      anon_sym_DQ[m
\ No newline at end of file[m
 UOTE,[m
      an[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_GT);[m
[31m-      if (lookahead == '=') ADVANCE(143);[m
[31m-      if (lookahead == '>') ADVANCE(151);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mon_sym_SQUOTE,[m
      anon_sym_DOLLAR,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DOT,[m
      aux_sym_file_path_token1,[m
\ No newline at end of file[m
[32m+[m
      aux_sym_file_path_tok[m
\ No newline at end of file[m
[32m+[m[32men2,[m
      anon_sym_DOLLAR_LPAREN,[m
      s[m
\ No newline at end of file[m
 ym_identifier,[m
    [m
\ No newline at end of file[m
   anon_sym_SEM[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_GT);[m
[31m-      if (lookahead == '=') ADVANCE(142);[m
[31m-      if (lookahead == '>') ADVANCE(150);[m
[32m+[m[32mI,[m
      anon_sym_LBRACE,[m
      anon_sym_RBRACE,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_PLUS,[m
      anon_sym_DASH,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_STAR,[m
      anon_sym_SLASH,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PERCENT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
   [m
\ No newline at end of file[m
    anon_sym_EQ_TILD[m
\ No newline at end of file[m
 E,[m
      anon_[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_GT_EQ);[m
[32m+[m[32msym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_sym_GT,[m
[32m+[m[32m      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LT,[m
      anon_sym_LT_LT,[m
[32m+[m[32m      anon_sym_GT_GT,[m
  [1557] = 5,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(43), 1,[m
      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(255), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DOT,[m
    STATE(25), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     aux_sym_value_path_repeat1,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(243), 2,[m
      ts_builtin_sym_end,[m
  [m
\ No newline at end of file[m
     anon_sym_LF,[m
  [m
\ No newline at end of file[m
   ACTIONS(238)[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_GT_EQ);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[31m-      END_STATE();[m
[32m+[m[32m, 28,[m
      anon_sym_LBRACK,[m
      anon_sym_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_number_literal,[m
      anon_sym_DQUOT[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      anon_sym_SQUOTE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DOLLAR,[m
      aux_sym_file_pat[m
\ No newline at end of file[m
[32m+[m[32mh_token1,[m
      aux[m
\ No newline at end of file[m
 _sym_file_path[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LT_EQ);[m
[32m+[m[32m_token2,[m
      anon_sym_DOLLAR_LPAREN[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_identifier,[m
      anon_sym_SEM[m
\ No newline at end of file[m
 I,[m
      anon_sym_L[m
\ No newline at end of file[m
 BRACE,[m
      a[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LT_EQ);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32mnon_sym_PLUS,[m
      anon_sym_DASH,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_STAR,[m
      anon_sym_SLASH,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PERCENT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
[32m+[m[32m      anon_sym_EQ_TILDE,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
       anon_sym_GT,[m
       anon_sym[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LT);[m
[31m-      if (lookahead == '<') ADVANCE(149);[m
[31m-      if (lookahead == '=') ADVANCE(145);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m_GT_EQ,[m
      anon_sym_LT_EQ,[m
    [m
\ No newline at end of file[m
   anon_sym_LT,[m
    [m
\ No newline at end of file[m
   anon_sym_LT_[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LT);[m
[31m-      if (lookahead == '<') ADVANCE(148);[m
[31m-      if (lookahead == '=') ADVANCE(144);[m
[32m+[m[32mLT,[m
      anon_sym_GT_GT,[m
  [1601][m
\ No newline at end of file[m
[32m+[m[32m = 5,[m
    ACTIONS(43), 1,[m
      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(258), 1,[m
      anon_sym_DOT,[m
\ No newline at end of file[m
[32m+[m
    STATE(27), 1,[m
      aux_sym_value_pat[m
\ No newline at end of file[m
[32m+[m[32mh_repeat1,[m
    ACTIONS(253), 2,[m
      ts_b[m
\ No newline at end of file[m
[32m+[m[32muiltin_sym_end,[m
      anon_sym_LF,[m
    ACTIONS(251),[m
\ No newline at end of file[m
[32m+[m[32m 28,[m
      anon_sym_LBRACK,[m
      anon_sym_PIPE,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_number_literal,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DQUOTE,[m
      anon_sym_SQUOTE,[m
      anon_sym_DOLLAR,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    aux_sym_file_path_token1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      aux_sym_file_path_token2,[m
      ano[m
\ No newline at end of file[m
 n_sym_DOLLAR_LPAREN[m
\ No newline at end of file[m
 ,[m
      sym_id[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_LT_LT);[m
[32m+[m[32mentifier,[m
      anon_sym_SEMI,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LBRACE,[m
      anon_sym_PLUS,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DASH,[m
      anon_sym_STAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
      anon_sym_PI[m
\ No newline at end of file[m
 PE_PIPE,[m
      anon[m
\ No newline at end of file[m
 _sym_AMP_AMP,[m
[31m-      ACCEPT_TOKEN(anon_sym_LT_LT);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[32m+[m[32m      anon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
\ No newline at end of file[m
 [m
      anon_sym_BAN[m
\ No newline at end of file[m
 G_EQ,[m
      an[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_GT_GT);[m
[32m+[m[32mon_sym_GT,[m
      anon_sym_GT_EQ,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LT_EQ,[m
      anon_sym_LT,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLT_LT,[m
      anon_sym_GT_GT,[m
  [1645] = 5,[m
[32m+[m[32m    ACTIONS(43), 1,[m
      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(258), 1,[m
      anon_sym_DOT,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(25), 1,[m
      aux_sym_value_path_rep[m
\ No newline at end of file[m
[32m+[m[32meat1,[m
    ACTIONS(249), 2,[m
      ts_builti[m
\ No newline at end of file[m
[32m+[m[32mn_sym_end,[m
      anon_sym_LF,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m245), 28,[m
      anon_sym_LBRACK,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_PIPE,[m
      sym_number_literal,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_DQUOTE,[m
      anon_sym_SQUOTE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOLLAR,[m
      aux_sym_file_p[m
\ No newline at end of file[m
[32m+[m[32math_token1,[m
      aux_sym_file_path_token2[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DOLLAR_LPAREN,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32midentifier,[m
      anon_sym_SEMI,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LBRACE,[m
      anon_sym_PLUS,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DASH,[m
      anon_sym_STAR,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_SLASH,[m
      anon_sym_PERCENT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_[m
\ No newline at end of file[m
[32m+[m[32mAMP,[m
      anon_sym_EQ_TILDE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT,[m
      anon_sym_GT_EQ,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LT_EQ,[m
      anon_sym_LT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [1689[m
\ No newline at end of file[m
[32m+[m[32m] = 4,[m
    ACTIONS(43), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_comment,[m
    ACTIONS(262), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DOT_DOT,[m
    ACTIONS(264), 1,[m
      anon_sym_LF,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(260), 30,[m
      anon_sym_LBRACK,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_RPAREN,[m
      anon_sym_PIPE,[m
\ No newline at end of file[m
[32m+[m
      sym_number_literal,[m
      anon_sym_DQUOTE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SQUOTE,[m
      anon_sym_DOLLAR,[m
      au[m
\ No newline at end of file[m
 x_sym_file_path_tok[m
\ No newline at end of file[m
 en1,[m
      aux[m
\ No newline at end of file[m
[31m-      ACCEPT_TOKEN(anon_sym_GT_GT);[m
[31m-      if (lookahead == '\\') ADVANCE(34);[m
[31m-      if (!sym_word_character_set_1(lookahead)) ADVANCE(83);[m
[31m-      END_STATE();[m
[31m-    default:[m
[31m-      return false;[m
[31m-  }[m
[31m-}[m
[31m-[m
[31m-static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {[m
[31m-  START_LEXER();[m
[31m-  eof = lexer->eof(lexer);[m
[31m-  switch (state) {[m
[31m-    case 0:[m
[31m-      if (lookahead == 'a') ADVANCE(1);[m
[31m-      if (lookahead == 'b') ADVANCE(2);[m
[31m-      if (lookahead == 'i') ADVANCE(3);[m
[31m-      if (lookahead == 'n') ADVANCE(4);[m
[31m-      if (lookahead == 'p') ADVANCE(5);[m
[31m-      if (lookahead == 'r') ADVANCE(6);[m
[31m-      if (lookahead == 's') ADVANCE(7);[m
[31m-      if (lookahead == 't') ADVANCE(8);[m
[31m-      if (lookahead == 'u') ADVANCE(9);[m
[32m+[m[32m_sym_file_path_token2,[m
      anon_sym_DOLLAR_L[m
\ No newline at end of file[m
[32m+[m[32mPAREN,[m
      sym_identifier,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SEMI,[m
      anon_sym_LBRACE,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_RBRACE,[m
      anon_sym_PLUS,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DASH,[m
      anon_sym_STAR,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_SLASH,[m
      anon_sym_PERCENT,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AM[m
\ No newline at end of file[m
[32m+[m[32mP,[m
      anon_sym_EQ_TILDE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_GT,[m
      anon_sym_GT_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT_EQ,[m
      anon_sym_LT,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LT_LT,[m
      anon_sym_GT_GT,[m
  [1731] = [m
\ No newline at end of file[m
[32m+[m[32m3,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(268), 1,[m
      anon_sym_LF,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(266), 30,[m
      anon_sym_LBRACK,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_RPAREN,[m
      anon_sym_PIP[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      sym_number_literal,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DQUOTE,[m
      anon_sym_SQUOTE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DOLLAR,[m
      aux_sym_file_path_toke[m
\ No newline at end of file[m
[32m+[m[32mn1,[m
      aux_sym_file_path_token2,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DOLLAR_LPAREN,[m
      sym_identif[m
\ No newline at end of file[m
[32m+[m[32mier,[m
      anon_sym_SEMI,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mBRACE,[m
      anon_sym_RBRACE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PLUS,[m
      anon_sym_DASH,[m
      anon_s[m
\ No newline at end of file[m
 ym_STAR,[m
      anon_sym_SLASH,[m
[31m-          lookahead == '\n' ||[m
[31m-          lookahead == '\r' ||[m
[31m-          lookahead == ' ') SKIP(0)[m
[32m+[m[32m      anon_sym_PERCENT,[m
      anon_sym_PIP[m
\ No newline at end of file[m
[32m+[m[32mE_PIPE,[m
      anon_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT,[m
      anon_sym_GT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT_EQ,[m
      anon_sym_LT,[m
      anon_sym_LT_LT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_GT_GT,[m
  [1770] = 3,[m
    ACT[m
\ No newline at end of file[m
 IONS(43), 1,[m
      [m
\ No newline at end of file[m
[31m-    case 1:[m
[31m-      if (lookahead == 'n') ADVANCE(10);[m
[32m+[m[32msym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(272), 1,[m
      anon_sym_LF,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(270), 30,[m
      anon_sym_LBRACK,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_RPAREN,[m
      anon_sym_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_number_literal,[m
      anon_sym_DQUOT[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      anon_sym_SQUOTE,[m
      anon_sym_D[m
\ No newline at end of file[m
[32m+[m[32mOLLAR,[m
      aux_sym_file_path_token1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   aux_sym_file_path_token2,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR_LPAREN,[m
      sym_identifier,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SEMI,[m
      anon_sym_LBRACE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RBRACE,[m
      anon_sym_PLUS,[m
[32m+[m[32m      anon_sym_DASH,[m
      anon_sym_STAR,[m
[32m+[m[32m      anon_sym_SLASH,[m
      anon_sym_PERCE[m
\ No newline at end of file[m
[32m+[m[32mNT,[m
      anon_sym_PIPE_PIPE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_GT,[m
      anon_sym_GT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT_EQ,[m
      anon_sym_LT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [1809] = 3,[m
    ACTIONS(43), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_comment,[m
    ACTIONS(276), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LF,[m
    ACTIONS(274), 30,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LBRACK,[m
      anon_sym_RPAREN,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PIPE,[m
      sym_number_literal,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DQUOTE,[m
      anon_sym_SQUOTE[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DOLLAR,[m
      [m
\ No newline at end of file[m
[32m+[m[32maux_sym_file_path_token1,[m
      aux_sym_fi[m
\ No newline at end of file[m
[32m+[m[32mle_path_token2,[m
      anon_sym_DOLLAR_LPAREN,[m
      sym_identifi[m
\ No newline at end of file[m
[32m+[m[32mer,[m
      anon_sym_SEMI,[m
      anon_sym_LBRACE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_RBRACE,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_PLUS,[m
      anon_sym_DASH,[m
      anon_sym_STAR,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_SLASH,[m
      anon_sym_PERCENT,[m
      [m
\ No newline at end of file[m
 anon_sym_PIPE_PIPE,[m
\ No newline at end of file[m
[31m-    case 2:[m
[31m-      if (lookahead == 'l') ADVANCE(11);[m
[32m+[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT,[m
      anon_sym_GT_EQ,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LT_EQ,[m
      anon_sym_LT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [1848[m
\ No newline at end of file[m
[32m+[m[32m] = 4,[m
    ACTIONS(43), 1,[m
      sym_comme[m
\ No newline at end of file[m
[32m+[m[32mnt,[m
    ACTIONS(278), 1,[m
      anon_sym_DO[m
\ No newline at end of file[m
[32m+[m[32mT_DOT,[m
    ACTIONS(264), 2,[m
      ts_built[m
\ No newline at end of file[m
[32m+[m[32min_sym_end,[m
      anon_sym_LF,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(260), 28,[m
      anon_sym_LBRACK,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_PIPE,[m
      sym_number_literal,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DQUOTE,[m
      anon_sym_SQUOTE,[m
[32m+[m[32m      anon_sym_DOLLAR,[m
      aux_sym_file_[m
\ No newline at end of file[m
[32m+[m[32mpath_token1,[m
      aux_sym_file_path_token[m
\ No newline at end of file[m
[32m+[m[32m2,[m
      anon_sym_DOLLAR_LPAREN,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_identifier,[m
      anon_sym_SEMI,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LBRACE,[m
      anon_sym_PLUS,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DASH,[m
      anon_sym_STAR,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_SLASH,[m
      anon_sym_PERCENT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PIPE_PIPE,[m
      anon_sym_AMP[m
\ No newline at end of file[m
[32m+[m[32m_AMP,[m
      anon_sym_EQ_TILDE,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT,[m
      anon_sym_GT_EQ,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_LT_EQ,[m
      anon_sym_LT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LT_LT,[m
      anon_sym_GT[m
\ No newline at end of file[m
[32m+[m[32m_GT,[m
  [1889] = 3,[m
    ACTIONS(43), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    ACTIONS(282), 1,[m
      anon_sym_LF,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(280), 30,[m
      anon_sym_LBRACK,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mRPAREN,[m
      anon_sym_PIPE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_number_literal,[m
      anon_sym_DQUOTE,[m
      anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mQUOTE,[m
      anon_sym_DOLLAR,[m
      aux_[m
\ No newline at end of file[m
 sym_file_path_token[m
\ No newline at end of file[m
[31m-    case 3:[m
[31m-      if (lookahead == 'n') ADVANCE(12);[m
[32m+[m[32m1,[m
      aux_s[m
\ No newline at end of file[m
[32m+[m[32mym_file_path_token2,[m
      anon_sym_DOLLAR_LPA[m
\ No newline at end of file[m
[32m+[m[32mREN,[m
      sym_identifier,[m
      anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mEMI,[m
      anon_sym_LBRACE,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mRBRACE,[m
      anon_sym_PLUS,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DASH,[m
      anon_sym_STAR,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_SLASH,[m
      anon_sym_PERCENT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_TILDE,[m
      anon_sym_EQ_[m
\ No newline at end of file[m
[32m+[m[32mEQ,[m
      anon_sym_BANG_EQ,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mT_EQ,[m
      anon_sym_LT,[m
      anon_sym_LT[m
\ No newline at end of file[m
[32m+[m[32m_LT,[m
      anon_sym_GT_GT,[m
  [1928] = 3,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(43), 1,[m
      sym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(286), 1,[m
      anon_sym_LF,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(284), 30,[m
      anon_sym_LBRACK,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_RPAREN,[m
      anon_sym_PIPE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_number_literal,[m
      anon_sym_DQ[m
\ No newline at end of file[m
[32m+[m[32mUOTE,[m
      anon_sym_SQUOTE,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR,[m
      aux_sym_file_path_token1,[m
[32m+[m[32m      aux_sym_file_path_token2,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DOLLAR_LPAREN,[m
      sym_identifier,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_SEMI,[m
      anon_sym_LBRAC[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      anon_sym_RBRACE,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mLUS,[m
      anon_sym_DASH,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_STAR,[m
      anon_sym_SLASH,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_PERCENT,[m
      anon_sym_PIPE_PIPE,[m
      anon_sym_AMP[m
\ No newline at end of file[m
[32m+[m[32m_AMP,[m
      anon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_BANG_EQ,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT,[m
      anon_sym_LT_LT,[m
     [m
\ No newline at end of file[m
  anon_sym_GT_GT,[m
  [m
\ No newline at end of file[m
[31m-    case 4:[m
[31m-      if (lookahead == 'u') ADVANCE(13);[m
[32m+[m[32m[1967] = 3,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(43), 1,[m
      sym_comment,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(290), 1,[m
      anon_sym_LF,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m288), 30,[m
      anon_sym_LBRACK,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_RPAREN,[m
      anon_sym_PIPE,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_number_literal,[m
      anon_sym_DQUOTE,[m
[32m+[m[32m      anon_sym_SQUOTE,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR,[m
      aux_sym_file_path_token1,[m
      [m
\ No newline at end of file[m
[32m+[m[32maux_sym_file_path_token2,[m
      anon_sym_D[m
\ No newline at end of file[m
[32m+[m[32mOLLAR_LPAREN,[m
      sym_identifier,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_SEMI,[m
      anon_sym_LBRACE,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_RBRACE,[m
      anon_sym_PLUS,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_DASH,[m
      anon_sym_STAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_PIPE_PIPE,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mAMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_GT,[m
      anon_sym_GT_EQ,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LT_EQ,[m
      anon_sym_LT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [2[m
\ No newline at end of file[m
[32m+[m[32m006] = 3,[m
    ACTIONS(43), 1,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS(294), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LF,[m
    ACTIONS(292), 30,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LBRACK,[m
      anon_sym_RPAREN,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_PIPE,[m
      sym_number_lit[m
\ No newline at end of file[m
[32m+[m[32meral,[m
      anon_sym_DQUOTE,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_SQUOTE,[m
      anon_sym_DOLLAR,[m
      aux_sym_file_path_token1,[m
\ No newline at end of file[m
[32m+[m
      aux_sym_file_path_token2,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR_LPAREN,[m
      sym_identifie[m
\ No newline at end of file[m
[32m+[m[32mr,[m
      anon_sym_SEMI,[m
      anon_sym_LBRACE,[m
      anon_sym_RB[m
\ No newline at end of file[m
[32m+[m[32mRACE,[m
      anon_sym_PLUS,[m
      anon_sy[m
\ No newline at end of file[m
 m_DASH,[m
      anon_[m
\ No newline at end of file[m
[31m-    case 5:[m
[31m-      if (lookahead == 'a') ADVANCE(14);[m
[32m+[m[32msym_STAR,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AM[m
\ No newline at end of file[m
[32m+[m[32mP,[m
      anon_sym_EQ_TILDE,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mEQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_GT,[m
      anon_sym_GT_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT_EQ,[m
      anon_sym_LT,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LT_LT,[m
      anon_sym_GT_GT,[m
  [2045] = [m
\ No newline at end of file[m
[32m+[m[32m3,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(298), 1,[m
      anon_sym_LF,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(296), 30,[m
      anon_sym_LBRACK,[m
[32m+[m[32m      anon_sym_RPAREN,[m
      anon_sym_PIPE[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_number_literal,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DQUOTE,[m
      anon_sym_SQUOTE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DOLLAR,[m
      aux_sym_file_path_token[m
\ No newline at end of file[m
[32m+[m[32m1,[m
      aux_sym_file_path_token2,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DOLLAR_LPAREN,[m
      sym_identifie[m
\ No newline at end of file[m
[32m+[m[32mr,[m
      anon_sym_SEMI,[m
      anon_sym_LBR[m
\ No newline at end of file[m
[32m+[m[32mACE,[m
      anon_sym_RBRACE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_PLUS,[m
      anon_sym_DASH,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_STAR,[m
      anon_sym_SLASH,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_PERCENT,[m
      anon_sym_PIPE_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_AMP_AMP,[m
      anon_sym_EQ_TILD[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      anon_sym_EQ_EQ,[m
      anon_sym_BA[m
\ No newline at end of file[m
[32m+[m[32mNG_EQ,[m
      anon_sym_GT,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LT,[m
      anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [2[m
\ No newline at end of file[m
[32m+[m[32m084] = 3,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(302), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LF,[m
    ACTIONS(300), 30,[m
      anon_sym_LBRACK,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_RPAREN,[m
      anon_sym_PIPE,[m
      sy[m
\ No newline at end of file[m
 m_number_literal,[m
 [m
\ No newline at end of file[m
[31m-    case 6:[m
[31m-      if (lookahead == 'a') ADVANCE(15);[m
[32m+[m[32m     anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mDQUOTE,[m
      anon_sym_SQUOTE,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mDOLLAR,[m
      aux_sym_file_path_token1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   aux_sym_file_path_token2,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR_LPAREN,[m
      sym_identifier,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SEMI,[m
      anon_sym_LBRACE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RBRACE,[m
      anon_sym_PLUS,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DASH,[m
      anon_sym_STAR,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_SLASH,[m
      anon_sym_PERC[m
\ No newline at end of file[m
[32m+[m[32mENT,[m
      anon_sym_PIPE_PIPE,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_GT,[m
      anon_sym_GT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT_EQ,[m
      anon_sym_LT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [2123] = 3,[m
    ACTIONS(43), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_comment,[m
    ACTIONS(306), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LF,[m
    ACTIONS(304), 30,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LBRACK,[m
      anon_sym_RPAREN,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PIPE,[m
      sym_number_literal,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_DQUOTE,[m
      anon_sym_SQUOTE,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DOLLAR,[m
      aux_sym_fil[m
\ No newline at end of file[m
[32m+[m[32me_path_token1,[m
      aux_sym_file_path_tok[m
\ No newline at end of file[m
[32m+[m[32men2,[m
      anon_sym_DOLLAR_LPAREN,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_identifier,[m
      anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mEMI,[m
      anon_sym_LBRACE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_RBRACE,[m
      anon_sym_PLUS,[m
      anon_sym_DASH,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_STAR,[m
      anon_sym_SLASH,[m
      anon_sym_PERCENT[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PIPE_PIPE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      anon_sym_EQ[m
\ No newline at end of file[m
[32m+[m[32m_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_[m
\ No newline at end of file[m
 sym_GT,[m
      anon_[m
\ No newline at end of file[m
[31m-    case 7:[m
[31m-      if (lookahead == 't') ADVANCE(16);[m
[32m+[m[32msym_GT_EQ,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LT_EQ,[m
      anon_sym_LT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [2162[m
\ No newline at end of file[m
[32m+[m[32m] = 3,[m
    ACTIONS(43), 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(310), 1,[m
      anon_sym_LF,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(308), 30,[m
      anon_sym_LBRA[m
\ No newline at end of file[m
[32m+[m[32mCK,[m
      anon_sym_RPAREN,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPIPE,[m
      sym_number_literal,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DQUOTE,[m
      anon_sym_SQUOTE,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DOLLAR,[m
      aux_sym_file_path_t[m
\ No newline at end of file[m
[32m+[m[32moken1,[m
      aux_sym_file_path_token2,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DOLLAR_LPAREN,[m
      sym_identi[m
\ No newline at end of file[m
[32m+[m[32mfier,[m
      anon_sym_SEMI,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLBRACE,[m
      anon_sym_RBRACE,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_PLUS,[m
      anon_sym_DASH,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_STAR,[m
      anon_sym_SLASH,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_PERCENT,[m
      anon_sym_PIPE_PIPE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_AMP_AMP,[m
      anon_sym_EQ_TI[m
\ No newline at end of file[m
[32m+[m[32mLDE,[m
      anon_sym_EQ_EQ,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mBANG_EQ,[m
      anon_sym_GT,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT,[m
      anon_sym_LT_LT,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT_GT,[m
  [2201] = 3,[m
    ACTIONS(43), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
    ACTIONS(243), 2,[m
[32m+[m[32m      ts_builtin_sym_end,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mF,[m
    ACTIONS(238), 29,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LBRACK,[m
      anon_sym_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_number_literal,[m
      anon_sym_DQUOTE,[m
      anon_sym_SQUO[m
\ No newline at end of file[m
[32m+[m[32mTE,[m
      anon_sym_DOLLAR,[m
      anon_sym_DOT,[m
     [m
\ No newline at end of file[m
[32m+[m[32m aux_sym_file_path_token1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   aux_sym_file_path_token2,[m
      anon_sym_DOLLAR_LPAREN,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_identifier,[m
      anon_sym_SEMI,[m
  [m
\ No newline at end of file[m
     anon_sym_LBRACE[m
\ No newline at end of file[m
[31m-    case 8:[m
[31m-      if (lookahead == 'a') ADVANCE(17);[m
[32m+[m[32m,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PLUS,[m
      anon_sym_DASH,[m
      anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mTAR,[m
      anon_sym_SLASH,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mERCENT,[m
      anon_sym_PIPE_PIPE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_EQ,[m
      anon_sym_BANG_E[m
\ No newline at end of file[m
[32m+[m[32mQ,[m
      anon_sym_GT,[m
      anon_sym_GT_EQ[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LT_EQ,[m
      anon_sym_LT,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LT_LT,[m
      anon_sym_GT_G[m
\ No newline at end of file[m
[32m+[m[32mT,[m
  [2240] = 3,[m
    ACTIONS(43), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_comment,[m
    ACTIONS(314), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LF,[m
    ACTIONS(312), 30,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LBRACK,[m
      anon_sym_RPAREN,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_PIPE,[m
      sym_number_literal,[m
[32m+[m[32m      anon_sym_DQUOTE,[m
      anon_sym_SQUO[m
\ No newline at end of file[m
[32m+[m[32mTE,[m
      anon_sym_DOLLAR,[m
      aux_sym_f[m
\ No newline at end of file[m
[32m+[m[32mile_path_token1,[m
      aux_sym_file_path_t[m
\ No newline at end of file[m
[32m+[m[32moken2,[m
      anon_sym_DOLLAR_LPAREN,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_identifier,[m
      anon_sym_SEMI,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LBRACE,[m
      anon_sym_RBRACE,[m
[32m+[m[32m      anon_sym_PLUS,[m
      anon_sym_DASH,[m
[32m+[m[32m      anon_sym_STAR,[m
      anon_sym_SLASH[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PERCENT,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_BANG_EQ,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_GT,[m
      anon_sym_GT_EQ,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LT_EQ,[m
      anon_sym_LT,[m
      anon_sym_LT_LT,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT_GT,[m
  [2279] = 3,[m
    ACTIONS(43), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    ACTIONS(318), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LF,[m
    ACTIONS(316), 30,[m
      anon_sym_LBRACK[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_RPAREN,[m
      anon_sym_[m
\ No newline at end of file[m
 PIPE,[m
      sym_num[m
\ No newline at end of file[m
[31m-    case 9:[m
[31m-      if (lookahead == 'n') ADVANCE(18);[m
[32m+[m[32mber_literal,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DQUOTE,[m
      anon_sym_SQUOTE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOLLAR,[m
      aux_sym_file_pa[m
\ No newline at end of file[m
[32m+[m[32mth_token1,[m
      aux_sym_file_path_token2,[m
[32m+[m[32m      anon_sym_DOLLAR_LPAREN,[m
      sym_id[m
\ No newline at end of file[m
[32m+[m[32mentifier,[m
      anon_sym_SEMI,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LBRACE,[m
      anon_sym_RBRACE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PLUS,[m
      anon_sym_DASH,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_STAR,[m
      anon_sym_SLASH,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PERCENT,[m
      anon_sym_PIPE_PIPE[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_AMP_AMP,[m
      anon_sym_EQ[m
\ No newline at end of file[m
[32m+[m[32m_TILDE,[m
      anon_sym_EQ_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_BANG_EQ,[m
      anon_sym_GT,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LT,[m
      anon_sym_LT_LT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_GT_GT,[m
  [2318] = 3,[m
    ACTIONS(43),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
    ACTIONS(322), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LF,[m
    ACTIONS(320), 30,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LBRACK,[m
      anon_sym_RPA[m
\ No newline at end of file[m
[32m+[m[32mREN,[m
      anon_sym_PIPE,[m
      sym_number[m
\ No newline at end of file[m
[32m+[m[32m_literal,[m
      anon_sym_DQUOTE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_SQUOTE,[m
      anon_sym_DOLLAR,[m
     [m
\ No newline at end of file[m
[32m+[m[32m aux_sym_file_path_token1,[m
      aux_sym_[m
\ No newline at end of file[m
[32m+[m[32mfile_path_token2,[m
      anon_sym_DOLLAR_LP[m
\ No newline at end of file[m
[32m+[m[32mAREN,[m
      sym_identifier,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SEMI,[m
      anon_sym_LBRACE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RBRACE,[m
      anon_sym_PLUS,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DASH,[m
      anon_sym_STAR,[m
      anon_sym_SLASH,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_PERCENT,[m
      anon_sym_PIPE_PIPE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_AMP_AMP,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
[32m+[m[32m      anon_sym_GT,[m
      anon_sym_GT_EQ,[m
\ No newline at end of file[m
 [m
      anon_sym_LT_[m
\ No newline at end of file[m
[31m-    case 10:[m
[31m-      if (lookahead == 'y') ADVANCE(19);[m
[32m+[m[32mEQ,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT,[m
      anon_sym_LT_LT,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mGT_GT,[m
  [2357] = 3,[m
    ACTIONS(43), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
    ACTIONS(322), 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  ts_builtin_sym_end,[m
      anon_sym_LF,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(320), 28,[m
      anon_sym_LBRACK[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PIPE,[m
      sym_number_li[m
\ No newline at end of file[m
[32m+[m[32mteral,[m
      anon_sym_DQUOTE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_SQUOTE,[m
      anon_sym_DOLLAR,[m
      au[m
\ No newline at end of file[m
[32m+[m[32mx_sym_file_path_token1,[m
      aux_sym_file[m
\ No newline at end of file[m
[32m+[m[32m_path_token2,[m
      anon_sym_DOLLAR_LPAREN,[m
\ No newline at end of file[m
[32m+[m
      sym_identifier,[m
      anon_sym_SEMI[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LBRACE,[m
      anon_sym_PL[m
\ No newline at end of file[m
[32m+[m[32mUS,[m
      anon_sym_DASH,[m
      anon_sym_ST[m
\ No newline at end of file[m
[32m+[m[32mAR,[m
      anon_sym_SLASH,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mERCENT,[m
      anon_sym_PIPE_PIPE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_EQ,[m
      anon_sym_BANG_E[m
\ No newline at end of file[m
[32m+[m[32mQ,[m
      anon_sym_GT,[m
      anon_sym_GT_EQ[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LT_EQ,[m
      anon_sym_LT,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LT_LT,[m
      anon_sym_GT_G[m
\ No newline at end of file[m
[32m+[m[32mT,[m
  [2395] = 3,[m
    ACTIONS(43), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_comment,[m
    ACTIONS(282), 2,[m
      [m
\ No newline at end of file[m
[32m+[m[32mts_builtin_sym_end,[m
      anon_sym_LF,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(280), 28,[m
      anon_sym_LBRACK,[m
[32m+[m[32m      anon_sym_PIPE,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mnumber_literal,[m
      anon_sym_DQUOTE,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SQUOTE,[m
      anon_sym_DOLLAR,[m
      aux_sym_file_pa[m
\ No newline at end of file[m
[32m+[m[32mth_token1,[m
      aux_sym_file_path_token2,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DOLLAR_LPAREN,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_identifier,[m
      anon_sym_SEMI,[m
      anon_sym_LBRACE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PLUS,[m
      anon_sym_DASH,[m
     [m
\ No newline at end of file[m
  anon_sym_STAR,[m
   [m
\ No newline at end of file[m
[31m-    case 11:[m
[31m-      if (lookahead == 'o') ADVANCE(20);[m
[32m+[m[32m   anon_sym_SL[m
\ No newline at end of file[m
[32m+[m[32mASH,[m
      anon_sym_PERCENT,[m
      anon_sym_PI[m
\ No newline at end of file[m
[32m+[m[32mPE_PIPE,[m
      anon_sym_AMP_AMP,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_BANG_EQ,[m
      anon_sym_GT,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT,[m
      anon_sym_LT_LT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_GT_GT,[m
  [2433] = 3,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(43), 1,[m
      sym_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m290), 2,[m
      ts_builtin_sym_end,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_LF,[m
    ACTIONS(288), 28,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LBRACK,[m
      anon_sym_PIPE,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_number_literal,[m
      anon_sym_DQUOTE,[m
[32m+[m[32m      anon_sym_SQUOTE,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR,[m
      aux_sym_file_path_token1,[m
      [m
\ No newline at end of file[m
[32m+[m[32maux_sym_file_path_token2,[m
      anon_sym_D[m
\ No newline at end of file[m
[32m+[m[32mOLLAR_LPAREN,[m
      sym_identifier,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_SEMI,[m
      anon_sym_LBRACE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_PLUS,[m
      anon_sym_DASH,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_STAR,[m
      anon_sym_SLASH,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_PERCENT,[m
      anon_sym_PIPE_P[m
\ No newline at end of file[m
[32m+[m[32mIPE,[m
      anon_sym_AMP_AMP,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_BANG_EQ,[m
      anon_sym_GT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT_EQ,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLT_EQ,[m
      anon_sym_LT,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mT_LT,[m
      anon_sym_GT_GT,[m
  [2471] = 3,[m
    ACTIONS(43), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
    ACTIONS(276), 2,[m
      ts_built[m
\ No newline at end of file[m
[32m+[m[32min_sym_end,[m
      anon_sym_LF,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(274), 28,[m
      anon_sym_LBRACK,[m
      anon_sym_PIP[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      sym_number_literal,[m
      anon_[m
\ No newline at end of file[m
 sym_DQUOTE,[m
      a[m
\ No newline at end of file[m
[31m-    case 12:[m
[31m-      if (lookahead == 't') ADVANCE(21);[m
[32m+[m[32mnon_sym_SQUOTE[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DOLLAR,[m
      aux_sym_file_pa[m
\ No newline at end of file[m
[32m+[m[32mth_token1,[m
      aux_sym_file_path_token2,[m
[32m+[m[32m      anon_sym_DOLLAR_LPAREN,[m
      sym_ide[m
\ No newline at end of file[m
[32m+[m[32mntifier,[m
      anon_sym_SEMI,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LBRACE,[m
      anon_sym_PLUS,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DASH,[m
      anon_sym_STAR,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_SLASH,[m
      anon_sym_PERCENT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_EQ_TILDE,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mEQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT,[m
      anon_sym_GT_EQ,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LT_EQ,[m
      anon_sym_LT,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LT_LT,[m
      anon_sym_GT_GT,[m
  [2509] = 3[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(294), 2,[m
      ts_builtin_sym_e[m
\ No newline at end of file[m
[32m+[m[32mnd,[m
      anon_sym_LF,[m
    ACTIONS(292), 2[m
\ No newline at end of file[m
[32m+[m[32m8,[m
      anon_sym_LBRACK,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mIPE,[m
      sym_number_literal,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_DQUOTE,[m
      anon_sym_SQUOTE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DOLLAR,[m
      aux_sym_file_path_to[m
\ No newline at end of file[m
[32m+[m[32mken1,[m
      aux_sym_file_path_token2,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_DOLLAR_LPAREN,[m
      sym_ident[m
\ No newline at end of file[m
[32m+[m[32mifier,[m
      anon_sym_SEMI,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LBRACE,[m
      anon_sym_PLUS,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DASH,[m
      anon_sym_STAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
      anon_sym_PIPE[m
\ No newline at end of file[m
[32m+[m[32m_PIPE,[m
      anon_sym_AMP_AMP,[m
      anon_sym_EQ_TIL[m
\ No newline at end of file[m
[32m+[m[32mDE,[m
      anon_sym_EQ_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_BANG_EQ,[m
      anon_sym_GT,[m
      anon_sym_GT_EQ,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LT_EQ,[m
      anon_sym_LT,[m
  [m
\ No newline at end of file[m
     anon_sym_LT_LT,[m
\ No newline at end of file[m
[31m-    case 13:[m
[31m-      if (lookahead == 'm') ADVANCE(22);[m
[32m+[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT_GT,[m
  [2547] = 3,[m
    ACTIONS(43), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    ACTIONS(268), 2,[m
      [m
\ No newline at end of file[m
[32m+[m[32mts_builtin_sym_end,[m
      anon_sym_LF,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(266), 28,[m
      anon_sym_LBRACK,[m
[32m+[m[32m      anon_sym_PIPE,[m
      sym_number_lite[m
\ No newline at end of file[m
[32m+[m[32mral,[m
      anon_sym_DQUOTE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SQUOTE,[m
      anon_sym_DOLLAR,[m
      aux_[m
\ No newline at end of file[m
[32m+[m[32msym_file_path_token1,[m
      aux_sym_file_p[m
\ No newline at end of file[m
[32m+[m[32math_token2,[m
      anon_sym_DOLLAR_LPAREN,[m
[32m+[m[32m      sym_identifier,[m
      anon_sym_SEMI,[m
[32m+[m[32m      anon_sym_LBRACE,[m
      anon_sym_PLUS[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DASH,[m
      anon_sym_STAR[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_SLASH,[m
      anon_sym_PER[m
\ No newline at end of file[m
[32m+[m[32mCENT,[m
      anon_sym_PIPE_PIPE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_GT,[m
      anon_sym_GT_EQ,[m
[32m+[m[32m      anon_sym_LT_EQ,[m
      anon_sym_LT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
\ No newline at end of file[m
[32m+[m
  [2585] = 3,[m
    ACTIONS(43), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIONS(318), 2,[m
      ts[m
\ No newline at end of file[m
[32m+[m[32m_builtin_sym_end,[m
      anon_sym_LF,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(316), 28,[m
      anon_sym_LBRACK,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PIPE,[m
      sym_number_litera[m
\ No newline at end of file[m
[32m+[m[32ml,[m
      anon_sym_DQUOTE,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SQUOTE,[m
      anon_sym_DOLLAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     aux_sym_file_path_token1,[m
      aux_sym_file_path_token2,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOLLAR_LPAREN,[m
      sym_identifier,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SEMI,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LBRACE,[m
      anon_sym_PLUS,[m
      anon_sym_DASH,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_STAR,[m
      anon_sym_SLASH,[m
      [m
\ No newline at end of file[m
 anon_sym_PERCENT,[m
 [m
\ No newline at end of file[m
[31m-    case 14:[m
[31m-      if (lookahead == 't') ADVANCE(23);[m
[32m+[m[32m     anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_BANG_EQ,[m
      anon_sym_GT,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LT,[m
      anon_sym_LT_LT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT_GT,[m
  [2623] = 3,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m43), 1,[m
      sym_comment,[m
    ACTIONS(310[m
\ No newline at end of file[m
[32m+[m[32m), 2,[m
      ts_builtin_sym_end,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LF,[m
    ACTIONS(308), 28,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LBRACK,[m
      anon_sym_PIPE,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mnumber_literal,[m
      anon_sym_DQUOTE,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SQUOTE,[m
      anon_sym_DOLLAR,[m
\ No newline at end of file[m
[32m+[m
      aux_sym_file_path_token1,[m
      aux[m
\ No newline at end of file[m
[32m+[m[32m_sym_file_path_token2,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR_LPAREN,[m
      sym_identifier,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_SEMI,[m
      anon_sym_LBRACE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PLUS,[m
      anon_sym_DASH,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_STAR,[m
      anon_sym_SLASH,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PERCENT,[m
      anon_sym_PIPE_PIPE[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_AMP_AMP,[m
      anon_sym_E[m
\ No newline at end of file[m
[32m+[m[32mQ_TILDE,[m
      anon_sym_EQ_EQ,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_BANG_EQ,[m
      anon_sym_GT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_LT,[m
      anon_sym_LT_LT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_GT_GT,[m
  [2661] = 3,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(43), 1,[m
      sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(302), 2,[m
      ts_builtin_sym_end,[m
      anon_sym_LF,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(300), 28,[m
      anon_sym_LBRACK,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_PIPE,[m
      sym_number_lit[m
\ No newline at end of file[m
[32m+[m[32meral,[m
      anon_sym_DQUOTE,[m
      anon_sym_SQUOTE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DOLLAR,[m
      aux_sym_file_path_token[m
\ No newline at end of file[m
 1,[m
      aux_sym_fi[m
\ No newline at end of file[m
[31m-    case 15:[m
[31m-      if (lookahead == 'n') ADVANCE(24);[m
[32m+[m[32mle_path_token2[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DOLLAR_LPAREN,[m
      sym_iden[m
\ No newline at end of file[m
[32m+[m[32mtifier,[m
      anon_sym_SEMI,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LBRACE,[m
      anon_sym_PLUS,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DASH,[m
      anon_sym_STAR,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_SLASH,[m
      anon_sym_PERCENT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
[32m+[m[32m      anon_sym_EQ_TILDE,[m
      anon_sym_EQ[m
\ No newline at end of file[m
[32m+[m[32m_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LT_EQ,[m
      anon_sym_LT,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mT_LT,[m
      anon_sym_GT_GT,[m
  [2699] = 3,[m
[32m+[m[32m    ACTIONS(43), 1,[m
      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(298), 2,[m
      ts_builtin_sym_end[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LF,[m
    ACTIONS(296), 28,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LBRACK,[m
      anon_sym_PIP[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      sym_number_literal,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DQUOTE,[m
      anon_sym_SQUOTE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DOLLAR,[m
      aux_sym_file_path_toke[m
\ No newline at end of file[m
[32m+[m[32mn1,[m
      aux_sym_file_path_token2,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DOLLAR_LPAREN,[m
      sym_identifi[m
\ No newline at end of file[m
[32m+[m[32mer,[m
      anon_sym_SEMI,[m
      anon_sym_LB[m
\ No newline at end of file[m
[32m+[m[32mRACE,[m
      anon_sym_PLUS,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DASH,[m
      anon_sym_STAR,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SLASH,[m
      anon_sym_PERCENT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_PIPE_PIPE,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mAMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_sym_GT,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLT,[m
      anon_sym_LT_LT,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_GT_GT,[m
  [2737] = 3,[m
    ACTIONS(43), 1,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS(286), 2,[m
      ts_bui[m
\ No newline at end of file[m
 ltin_sym_end,[m
     [m
\ No newline at end of file[m
[31m-    case 16:[m
[31m-      if (lookahead == 'r') ADVANCE(25);[m
[32m+[m[32m anon_sym_LF,[m
[32m+[m[32m    ACTIONS(284), 28,[m
      anon_sym_LBRACK,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PIPE,[m
      sym_number_litera[m
\ No newline at end of file[m
[32m+[m[32ml,[m
      anon_sym_DQUOTE,[m
      anon_sym_SQ[m
\ No newline at end of file[m
[32m+[m[32mUOTE,[m
      anon_sym_DOLLAR,[m
      aux_sym[m
\ No newline at end of file[m
[32m+[m[32m_file_path_token1,[m
      aux_sym_file_path[m
\ No newline at end of file[m
[32m+[m[32m_token2,[m
      anon_sym_DOLLAR_LPAREN,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_identifier,[m
      anon_sym_SEMI,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LBRACE,[m
      anon_sym_PLUS,[m
[32m+[m[32m      anon_sym_DASH,[m
      anon_sym_STAR,[m
[32m+[m[32m      anon_sym_SLASH,[m
      anon_sym_PERCEN[m
\ No newline at end of file[m
[32m+[m[32mT,[m
      anon_sym_PIPE_PIPE,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_GT,[m
      anon_sym_GT_EQ,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LT_EQ,[m
      anon_sym_LT,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[2775] = 3,[m
    ACTIONS(43), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcomment,[m
    ACTIONS(314), 2,[m
      ts_bui[m
\ No newline at end of file[m
[32m+[m[32mltin_sym_end,[m
      anon_sym_LF,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(312), 28,[m
      anon_sym_LBRACK,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PIPE,[m
      sym_number_literal,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DQUOTE,[m
      anon_sym_SQUO[m
\ No newline at end of file[m
[32m+[m[32mTE,[m
      anon_sym_DOLLAR,[m
      aux_sym_f[m
\ No newline at end of file[m
[32m+[m[32mile_path_token1,[m
      aux_sym_file_path_t[m
\ No newline at end of file[m
[32m+[m[32moken2,[m
      anon_sym_DOLLAR_LP[m
\ No newline at end of file[m
[32m+[m[32mAREN,[m
      sym_identifier,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SEMI,[m
      anon_sym_LBRACE,[m
      anon_sym_PLUS,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DASH,[m
      anon_sym_STAR,[m
      anon_sym_SLASH,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PERCENT,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
      anon_sym_EQ_TIL[m
\ No newline at end of file[m
[32m+[m[32mDE,[m
      anon_sym_EQ_EQ,[m
      anon_sym[m
\ No newline at end of file[m
 _BANG_EQ,[m
      ano[m
\ No newline at end of file[m
[31m-    case 17:[m
[31m-      if (lookahead == 'b') ADVANCE(26);[m
[32m+[m[32mn_sym_GT,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT,[m
      anon_sym_LT_LT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_GT_GT,[m
  [2813] = 3,[m
    ACTIONS(43[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_comment,[m
    ACTIONS(306),[m
\ No newline at end of file[m
[32m+[m[32m 2,[m
      ts_builtin_sym_end,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LF,[m
    ACTIONS(304), 28,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LBRACK,[m
      anon_sym_PIPE,[m
      sym_number_literal,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DQUOTE,[m
      anon_sym_SQUOTE,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR,[m
      aux_sym_file_p[m
\ No newline at end of file[m
[32m+[m[32math_token1,[m
      aux_sym_file_path_token2,[m
      anon_sym_DOLLA[m
\ No newline at end of file[m
[32m+[m[32mR_LPAREN,[m
      sym_identifi[m
\ No newline at end of file[m
[32m+[m[32mer,[m
      anon_sym_SEMI,[m
      anon_sym_LBR[m
\ No newline at end of file[m
 ACE,[m
      anon_sym[m
\ No newline at end of file[m
[31m-    case 18:[m
[31m-      if (lookahead == 'i') ADVANCE(27);[m
[32m+[m[32m_PLUS,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DASH,[m
      anon_sym_STAR,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_SLASH,[m
      anon_sym_PERCENT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
[32m+[m[32m      anon_sym_EQ_TILDE,[m
      anon_sym_EQ[m
\ No newline at end of file[m
[32m+[m[32m_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT,[m
      anon_sym_LT_LT,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT_GT,[m
  [2851] = 3,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(43), 1,[m
      sym_comment,[m
    ACTIONS(272), 2,[m
      ts_bu[m
\ No newline at end of file[m
[32m+[m[32miltin_sym_end,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LF,[m
    ACTIONS(270), 28,[m
      anon_sym_[m
\ No newline at end of file[m
 LBRACK,[m
      anon_[m
\ No newline at end of file[m
[31m-    case 19:[m
[31m-      ACCEPT_TOKEN(anon_sym_any);[m
[32m+[m[32msym_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_number_literal,[m
      anon_sym_DQUOTE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SQUOTE,[m
      anon_sym_DOLLAR[m
\ No newline at end of file[m
[32m+[m[32m,[m
      aux_sym_file_path_token1,[m
      au[m
\ No newline at end of file[m
[32m+[m[32mx_sym_file_path_token2,[m
      anon_sym_DOL[m
\ No newline at end of file[m
[32m+[m[32mLAR_LPAREN,[m
      sym_identifier,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_SEMI,[m
      anon_sym_LBRACE,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mLUS,[m
      anon_sym_DASH,[m
      anon_sym_STAR,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SLASH,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_PERCENT,[m
      anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_EQ_TILDE,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
   [m
\ No newline at end of file[m
    anon_sym_GT,[m
   [m
\ No newline at end of file[m
[31m-    case 20:[m
[31m-      if (lookahead == 'c') ADVANCE(28);[m
[32m+[m[32m   anon_sym_GT[m
\ No newline at end of file[m
[32m+[m[32m_EQ,[m
      anon_sym_LT_EQ,[m
      anon_sym_LT,[m
[32m+[m[32m      anon_sym_LT_LT,[m
      anon_sym_GT_GT[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [2889] = 3,[m
    ACTIONS(43), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    ACTIONS(324), 10,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DOLLAR_LPAREN,[m
      anon_sym_PIPE[m
\ No newline at end of file[m
[32m+[m[32m_PIPE,[m
      anon_sym_AMP_AMP,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT_LT,[m
      anon_sym_GT_GT[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(182), 17,[m
      anon_sym_LBRACK,[m
      anon_sym_RB[m
\ No newline at end of file[m
[32m+[m[32mRACK,[m
      sym_number_liter[m
\ No newline at end of file[m
[32m+[m[32mal,[m
      anon_sym_DQUOTE,[m
      anon_sym_S[m
\ No newline at end of file[m
 QUOTE,[m
      anon_s[m
\ No newline at end of file[m
[31m-    case 21:[m
[31m-      ACCEPT_TOKEN(anon_sym_int);[m
[32m+[m[32mym_DOLLAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   aux_sym_file_path_token1,[m
      aux_sym_fil[m
\ No newline at end of file[m
[32m+[m[32me_path_token2,[m
      sym_identifier,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LBRACE,[m
      anon_sym_PLUS,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DASH,[m
      anon_sym_STAR,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
[32m+[m[32m      anon_sym_GT,[m
      anon_sym_LT,[m
  [2[m
\ No newline at end of file[m
[32m+[m[32m924] = 5,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(326), 1,[m
      anon_sym_DOT,[m
    STATE(61),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      aux_sym_value_path_r[m
\ No newline at end of file[m
[32m+[m[32mepeat1,[m
    ACTIONS(249), 2,[m
      ts_builtin_sym_end,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LF,[m
    ACTIONS(245), [m
\ No newline at end of file[m
[32m+[m[32m20,[m
      anon_sym_RPAREN,[m
      anon_sym_P[m
\ No newline at end of file[m
 IPE,[m
      anon_sym[m
\ No newline at end of file[m
[31m-    case 22:[m
[31m-      if (lookahead == 'b') ADVANCE(29);[m
[32m+[m[32m_SEMI,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_RBRACE,[m
      anon_sym_PLUS,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DASH,[m
      anon_sym_STAR,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_SLASH,[m
      anon_sym_PERCENT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_EQ_TILDE,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mEQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT,[m
      anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [2960] = 5,[m
    ACTIONS(43), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment,[m
    ACTIONS(328), 1,[m
      anon_sym_DOT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(61), 1,[m
      aux_s[m
\ No newline at end of file[m
[32m+[m[32mym_value_path_repeat1,[m
    ACTIONS(243), 2,[m
\ No newline at end of file[m
 [m
      ts_builtin_s[m
\ No newline at end of file[m
[31m-    case 23:[m
[31m-      if (lookahead == 'h') ADVANCE(30);[m
[31m-      if (lookahead == 't') ADVANCE(31);[m
[32m+[m[32mym_end,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LF,[m
    ACTIONS(238), 20,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_RPAREN,[m
      anon_sym_PIPE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_SEMI,[m
      anon_sym_RBRACE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PLUS,[m
      anon_sym_DASH,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_STAR,[m
      anon_sym_SLASH,[m
      anon_sym_PE[m
\ No newline at end of file[m
[32m+[m[32mRCENT,[m
      anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_[m
\ No newline at end of file[m
[32m+[m[32mAMP,[m
      anon_sym_EQ_TILDE,[m
[32m+[m[32m      anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_sym_GT,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_GT_EQ,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LT_EQ,[m
      anon_sym_LT,[m
      a[m
\ No newline at end of file[m
 non_sym_LT_LT,[m
    [m
\ No newline at end of file[m
[31m-    case 24:[m
[31m-      if (lookahead == 'g') ADVANCE(32);[m
[32m+[m[32m  anon_sym_GT_[m
\ No newline at end of file[m
[32m+[m[32mGT,[m
  [2996] = 5,[m
    ACTIONS(43), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    ACTIONS(326), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_DOT,[m
    STATE(60), 1,[m
      aux_sym_v[m
\ No newline at end of file[m
[32m+[m[32malue_path_repeat1,[m
    ACTIONS(253), 2,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    ts_builtin_sym_end,[m
      anon_sym_LF,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(251), 20,[m
      anon_sym_RPAREN,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PIPE,[m
      anon_sym_SEMI,[m
      anon_sym_R[m
\ No newline at end of file[m
[32m+[m[32mBRACE,[m
      anon_sym_PLUS,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DASH,[m
      anon_sym_STAR,[m
      anon_sym_SLASH,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PERCENT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
\ No newline at end of file[m
 [m
      anon_sym_EQ_[m
\ No newline at end of file[m
[31m-    case 25:[m
[31m-      if (lookahead == 'i') ADVANCE(33);[m
[32m+[m[32mTILDE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT,[m
      anon_sym_GT_EQ,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LT_EQ,[m
      anon_sym_LT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [3032][m
\ No newline at end of file[m
[32m+[m[32m = 14,[m
    ACTIONS(3), 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(7), 1,[m
      anon_sym_def,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(9), 1,[m
      anon_sym_LPAREN,[m
    ACTIONS(11), 1,[m
[32m+[m[32m      anon_sym_let,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(13), 1,[m
      sym_number_literal,[m
    ACTIONS(15), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DOLLAR,[m
    ACTIONS(1[m
\ No newline at end of file[m
[32m+[m[32m7), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    AC[m
\ No newline at end of file[m
 TIONS(21), 1,[m
     [m
\ No newline at end of file[m
[31m-    case 26:[m
[31m-      if (lookahead == 'l') ADVANCE(34);[m
[32m+[m[32m anon_sym_LBRA[m
\ No newline at end of file[m
[32m+[m[32mCE,[m
    ACTIONS(331), 1,[m
      anon_sym_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(333), 1,[m
      sym_identifier,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  STATE(85), 1,[m
      aux_sym__statements_[m
\ No newline at end of file[m
[32m+[m[32mrepeat1,[m
    STATE(243), 1,[m
      sym__statements,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(78), 6,[m
      sym_value_path,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mmand_substitution,[m
      sym_m[m
\ No newline at end of file[m
[32m+[m[32math_mode,[m
      sym__math_expression,[m
      sym_parenthesized_ma[m
\ No newline at end of file[m
[32m+[m[32mth_expression,[m
      sym_bin[m
\ No newline at end of file[m
[32m+[m[32mary_expression,[m
    STATE(164), 6,[m
      sy[m
\ No newline at end of file[m
 m__statement,[m
     [m
\ No newline at end of file[m
[31m-    case 27:[m
[31m-      if (lookahead == 't') ADVANCE(35);[m
[32m+[m[32m sym_function_[m
\ No newline at end of file[m
[32m+[m[32mdefinition,[m
      sym_variable_declaration,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_command,[m
      sym_pipeline,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_block,[m
  [3085] = 14,[m
    ACTIONS(3), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(7), 1,[m
      anon_sym_def,[m
    ACTIONS(9), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LPAREN,[m
    ACTIONS(11), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_let,[m
    ACTIONS(13), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_number_literal,[m
    ACTIONS(15), 1,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR,[m
    ACTIONS(17), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DOLLAR_LPAREN,[m
    ACTIONS(21), [m
\ No newline at end of file[m
 1,[m
      anon_sym_L[m
\ No newline at end of file[m
[31m-    case 28:[m
[31m-      if (lookahead == 'k') ADVANCE(36);[m
[32m+[m[32mBRACE,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(333), 1,[m
      sym_identifier,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(335), 1,[m
      anon_sym_RBRACE,[m
    STATE[m
\ No newline at end of file[m
[32m+[m[32m(85), 1,[m
      aux_sym__statements_repeat1[m
\ No newline at end of file[m
[32m+[m[32m,[m
    STATE(244), 1,[m
      sym__statements[m
\ No newline at end of file[m
[32m+[m[32m,[m
    STATE(78), 6,[m
      sym_value_path,[m
[32m+[m[32m      sym_command_substitution,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mmath_mode,[m
      sym__math_expression,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_parenthesized_math_expression,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_binary_expression,[m
    STATE(164), 6,[m
\ No newline at end of file[m
[32m+[m
      sym__statement,[m
      sym_function_[m
\ No newline at end of file[m
[32m+[m[32mdefinition,[m
      sym_variable_declaration[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_command,[m
      sym_pipeline,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_block,[m
  [3138] = 14,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_comment,[m
    ACTIONS(7),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_def,[m
    ACTIONS(9), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LPAREN,[m
    ACTIONS(11), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_let,[m
    ACTIONS(13), 1,[m
[32m+[m[32m      sym_number_literal,[m
    ACTIONS(15),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_DOLLAR,[m
    ACTIONS(17[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(21), 1,[m
      anon_sym_LBRACE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(333), 1,[m
      sym_identifier,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(337), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_EQ,[m
    STATE(85), 1,[m
      aux_sym__sta[m
\ No newline at end of file[m
[32m+[m[32mtements_repeat1,[m
    STATE(249), 1,[m
      sym__statements,[m
    S[m
\ No newline at end of file[m
[32m+[m[32mTATE(78), 6,[m
      sym_value_path,[m
      sym_command[m
\ No newline at end of file[m
[32m+[m[32m_substitution,[m
      sym_math_[m
\ No newline at end of file[m
[32m+[m[32mmode,[m
      sym__math_expression,[m
      sym_parenthesized_math_e[m
\ No newline at end of file[m
[32m+[m[32mxpression,[m
      sym_binary_[m
\ No newline at end of file[m
[32m+[m[32mexpression,[m
    STATE(164), 6,[m
      sym__s[m
\ No newline at end of file[m
 tatement,[m
      sym[m
\ No newline at end of file[m
[31m-    case 29:[m
[31m-      if (lookahead == 'e') ADVANCE(37);[m
[32m+[m[32m_function_defi[m
\ No newline at end of file[m
[32m+[m[32mnition,[m
      sym_variable_declaration,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_command,[m
      sym_pipeline,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mblock,[m
  [3191] = 3,[m
    ACTIONS(43), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_comment,[m
    ACTIONS(243), 2,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   ts_builtin_sym_end,[m
      anon_sym_LF,[m
[32m+[m[32m    ACTIONS(238), 21,[m
      anon_sym_RPARE[m
\ No newline at end of file[m
[32m+[m[32mN,[m
      anon_sym_PIPE,[m
      anon_sym_DOT[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_SEMI,[m
      anon_sym_RBRA[m
\ No newline at end of file[m
[32m+[m[32mCE,[m
      anon_sym_PLUS,[m
      anon_sym_DAS[m
\ No newline at end of file[m
[32m+[m[32mH,[m
      anon_sym_STAR,[m
      anon_sym_SLA[m
\ No newline at end of file[m
[32m+[m[32mSH,[m
      anon_sym_PERCENT,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_BANG_EQ,[m
      anon_sym_GT,[m
[32m+[m[32m      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LT,[m
      anon_sym_LT_LT,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_GT_GT,[m
  [3222] = 14,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
      sym_comment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(7), 1,[m
      anon_sym_def,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(9), 1,[m
      anon_sym_LPAREN,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(11), 1,[m
      anon_sym_let,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m13), 1,[m
      sym_number_litera[m
\ No newline at end of file[m
[32m+[m[32ml,[m
    ACTIONS(15), 1,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR,[m
    ACTIONS(17), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(21), 1,[m
      anon_sym_LBRACE,[m
    ACTIONS(333), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_identifier,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(339), 1,[m
      anon_sym_RBRACE,[m
    STATE(85), 1,[m
      au[m
\ No newline at end of file[m
[32m+[m[32mx_sym__statements_repeat1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(253), 1,[m
      sym__statements,[m
  [m
\ No newline at end of file[m
   STATE(78), 6,[m
   [m
\ No newline at end of file[m
[31m-    case 30:[m
[31m-      ACCEPT_TOKEN(anon_sym_path);[m
[32m+[m[32m   sym_value_p[m
\ No newline at end of file[m
[32m+[m[32math,[m
      sym_command_substitution,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_math_mode,[m
      sym__math_expression,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_parenthesized_math_expression,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_binary_expression,[m
    STATE(164),[m
\ No newline at end of file[m
[32m+[m[32m 6,[m
      sym__statement,[m
      sym_functi[m
\ No newline at end of file[m
[32m+[m[32mon_definition,[m
      sym_variable_declarat[m
\ No newline at end of file[m
[32m+[m[32mion,[m
      sym_command,[m
      sym_pipeline[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_block,[m
  [3275] = 14,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(3), 1,[m
      sym_comment,[m
    ACTIONS(7[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_def,[m
    ACTIONS(9), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_LPAREN,[m
    ACTIONS(11),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_let,[m
    ACTIONS(13), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_number_literal,[m
    ACTIONS(15[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_DOLLAR,[m
    ACTIONS(1[m
\ No newline at end of file[m
[32m+[m[32m7), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(21), 1,[m
      anon_sym_LBRACE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(333), 1,[m
      sym_identifier,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(341), 1,[m
      anon_sym_RBRACE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(85), 1,[m
      aux_sym__statement[m
\ No newline at end of file[m
[32m+[m[32ms_repeat1,[m
    STATE(250), 1,[m
      sym__[m
\ No newline at end of file[m
[32m+[m[32mstatements,[m
    STATE(78), 6,[m
      sym_va[m
\ No newline at end of file[m
[32m+[m[32mlue_path,[m
      sym_command_substitution,[m
[32m+[m[32m      sym_math_mode,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32m_math_expression,[m
      sym_parenthesized_[m
\ No newline at end of file[m
[32m+[m[32mmath_expression,[m
      sym_binary_expression,[m
    STATE(164), 6,[m
\ No newline at end of file[m
[32m+[m
      sym__statement,[m
      sym_function_definition[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_variable_declarati[m
\ No newline at end of file[m
[32m+[m[32mon,[m
      sym_command,[m
      sym_pipeline,[m
      sym_block,[m
  [3[m
\ No newline at end of file[m
[32m+[m[32m328] = 14,[m
    ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
    ACTIONS(7), 1,[m
   [m
\ No newline at end of file[m
    anon_sym_def,[m
  [m
\ No newline at end of file[m
[31m-    case 31:[m
[31m-      if (lookahead == 'e') ADVANCE(38);[m
[32m+[m[32m  ACTIONS(9),[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_LPAREN,[m
    ACTIONS(11), 1,[m
[32m+[m[32m      anon_sym_let,[m
    ACTIONS(13), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_number_literal,[m
    ACTIONS(15), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DOLLAR,[m
    ACTIONS(17), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_DOLLAR_LPAREN,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(21), 1,[m
      anon_sym_LBRACE,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(333), 1,[m
      sym_identifier,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(343), 1,[m
      anon_sym_RBRACE,[m
    S[m
\ No newline at end of file[m
[32m+[m[32mTATE(85), 1,[m
      aux_sym__statements_repe[m
\ No newline at end of file[m
[32m+[m[32mat1,[m
    STATE(236), 1,[m
      sym__stateme[m
\ No newline at end of file[m
[32m+[m[32mnts,[m
    STATE(78), 6,[m
      sym_value_pat[m
\ No newline at end of file[m
[32m+[m[32mh,[m
      sym_command_substitution,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_math_mode,[m
      sym__math_expression,[m
[32m+[m[32m      sym_parenthesized_math_expression,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_binary_expression,[m
    STATE(164)[m
\ No newline at end of file[m
[32m+[m[32m, 6,[m
      sym__statement,[m
      sym_funct[m
\ No newline at end of file[m
[32m+[m[32mion_definition,[m
      sym_variable_declara[m
\ No newline at end of file[m
[32m+[m[32mtion,[m
      sym_command,[m
      sym_pipelin[m
\ No newline at end of file[m
[32m+[m[32me,[m
      sym_block,[m
  [3381] = 14,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(3), 1,[m
      sym_comment,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(7), 1,[m
      anon_sym_def,[m
    ACTIONS(9[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_LPAREN,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(11), 1,[m
      anon_sym_let,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(13), 1,[m
      sym_number_literal,[m
    ACTIONS(15), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DOLLAR,[m
    ACTIONS(17), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_DOLLAR_LPAREN,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(21), 1,[m
      anon_sym_LBRACE,[m
    ACTIONS(333), 1,[m
      sym_i[m
\ No newline at end of file[m
[32m+[m[32mdentifier,[m
    ACTIONS(345),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_EQ,[m
    STATE(85), 1,[m
  [m
\ No newline at end of file[m
     aux_sym__statem[m
\ No newline at end of file[m
[31m-    case 32:[m
[31m-      if (lookahead == 'e') ADVANCE(39);[m
[32m+[m[32ments_repeat1,[m
[32m+[m[32m    STATE(258), 1,[m
      sym__statements,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(78), 6,[m
      sym_value_path,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_command_substitution,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_math_mode,[m
      sym__math_expression[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_parenthesized_ma[m
\ No newline at end of file[m
[32m+[m[32mth_expression,[m
      sym_binary_expression,[m
\ No newline at end of file[m
 [m
    STATE(164), 6,[m
\ No newline at end of file[m
[31m-    case 33:[m
[31m-      if (lookahead == 'n') ADVANCE(40);[m
[32m+[m
      sym__st[m
\ No newline at end of file[m
[32m+[m[32matement,[m
      sym_function_definition,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_variable_declaration,[m
      sym_comma[m
\ No newline at end of file[m
[32m+[m[32mnd,[m
      sym_pipeline,[m
      sym_block,[m
[32m+[m[32m  [3434] = 14,[m
    ACTIONS(3), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIONS(7), 1,[m
      anon_sym_def,[m
    ACTIONS(9[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_LPAREN,[m
    ACTIONS(11), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_let,[m
    ACTIONS(1[m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_number_literal,[m
    ACTIONS(15), 1,[m
      anon_[m
\ No newline at end of file[m
 sym_DOLLAR,[m
    ACT[m
\ No newline at end of file[m
[31m-    case 34:[m
[31m-      if (lookahead == 'e') ADVANCE(41);[m
[32m+[m[32mIONS(17), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOLLAR_LPAREN,[m
    ACTIONS(21), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_LBRACE,[m
    ACTIONS(333[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_identifier,[m
    ACTIONS(3[m
\ No newline at end of file[m
[32m+[m[32m47), 1,[m
      anon_sym_EQ,[m
    STATE(85),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      aux_sym__statements_repeat1,[m
    STATE(262[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym__statements,[m
    STATE(78), 6,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_value_path,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mmand_substitution,[m
      sym_math_mode,[m
      sym__math_expressi[m
\ No newline at end of file[m
 on,[m
      sym_paren[m
\ No newline at end of file[m
[31m-    case 35:[m
[31m-      ACCEPT_TOKEN(anon_sym_unit);[m
[32m+[m[32mthesized_math_[m
\ No newline at end of file[m
[32m+[m[32mexpression,[m
      sym_binary_expression,[m
    S[m
\ No newline at end of file[m
[32m+[m[32mTATE(164), 6,[m
      sym__statement,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_function_definition,[m
      sym_variable_declara[m
\ No newline at end of file[m
[32m+[m[32mtion,[m
      sym_command,[m
      sym_pipeline,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_block,[m
  [3487] = 14,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(3), 1,[m
      sym_comment,[m
    ACTIONS(7), 1,[m
      anon_s[m
\ No newline at end of file[m
 ym_def,[m
    ACTIONS[m
\ No newline at end of file[m
[31m-    case 36:[m
[31m-      ACCEPT_TOKEN(anon_sym_block);[m
[32m+[m[32m(9), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LPAREN,[m
    ACTIONS(11), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_let,[m
    ACTIONS(13), 1,[m
      sym_n[m
\ No newline at end of file[m
[32m+[m[32mumber_literal,[m
    ACTIONS(15), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DOLLAR,[m
    ACTIONS(17), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DOLLAR_LPAREN,[m
    ACTIONS(21), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LBRACE,[m
    ACTIONS(333), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_identifier,[m
    ACTIONS(349), 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mEQ,[m
    STATE(85), 1,[m
      au[m
\ No newline at end of file[m
[32m+[m[32mx_sym__statements_repeat1,[m
    STATE(257), 1,[m
      sym__stateme[m
\ No newline at end of file[m
[32m+[m[32mnts,[m
    STATE(78), 6,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_value_path,[m
      sym_comm[m
\ No newline at end of file[m
[32m+[m[32mand_substitution,[m
      sym_math_mode,[m
    [m
\ No newline at end of file[m
   sym__math_express[m
\ No newline at end of file[m
[31m-    case 37:[m
[31m-      if (lookahead == 'r') ADVANCE(42);[m
[32m+[m[32mion,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_parenthesized_math_expression,[m
      sym_bina[m
\ No newline at end of file[m
[32m+[m[32mry_expression,[m
    STATE(164), 6,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm__statement,[m
      sym_function_definitio[m
\ No newline at end of file[m
[32m+[m[32mn,[m
      sym_variable_declaration,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_command,[m
      sym_pipeline,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mblock,[m
  [3540] = 3,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(314), 2,[m
      ts_builtin_sym_end,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LF,[m
    ACTIONS(312), 20[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_RPAREN,[m
      anon_sym_PIPE,[m
      anon_sym_SEM[m
\ No newline at end of file[m
[32m+[m[32mI,[m
      anon_sym_RBRACE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PLUS,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DASH,[m
      anon_sym_STAR,[m
      anon_sy[m
\ No newline at end of file[m
 m_SLASH,[m
      anon[m
\ No newline at end of file[m
[31m-    case 38:[m
[31m-      if (lookahead == 'r') ADVANCE(43);[m
[32m+[m[32m_sym_PERCENT,[m
[32m+[m[32m      anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_A[m
\ No newline at end of file[m
[32m+[m[32mMP,[m
      anon_sym_EQ_TILDE,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LT,[m
      anon_sym_LT_LT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_GT_GT,[m
  [3570] = 7,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(43), 1,[m
      sym_comment,[m
    ACTIONS(351), 2,[m
      t[m
\ No newline at end of file[m
[32m+[m[32ms_builtin_sym_end,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LF,[m
    ACTIONS(355), 2,[m
[32m+[m[32m      anon_sym_PLUS,[m
      anon_sym_DASH,[m
 [m
\ No newline at end of file[m
    ACTIONS(361), 2,[m
\ No newline at end of file[m
[31m-    case 39:[m
[31m-      ACCEPT_TOKEN(anon_sym_range);[m
[32m+[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LT_LT,[m
      anon_sym_GT_GT,[m
    ACTIONS(357[m
\ No newline at end of file[m
[32m+[m[32m), 3,[m
      anon_sym_STAR,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mSLASH,[m
      anon_sym_PERCENT,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(359), 4,[m
      anon_sym_GT,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon_sym_LT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(353), 9,[m
      anon_sym_RPAREN,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_PIPE,[m
      anon_sym_SEM[m
\ No newline at end of file[m
[32m+[m[32mI,[m
      anon_sym_RBRACE,[m
      anon_sym_PIPE_PIPE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_AMP_AMP,[m
      anon_sym_E[m
\ No newline at end of file[m
[32m+[m[32mQ_TILDE,[m
      anon_sym_EQ_EQ,[m
[32m+[m[32m      anon_sym_BANG_EQ,[m
  [3608] = 9,[m
    A[m
\ No newline at end of file[m
 CTIONS(43), 1,[m
    [m
\ No newline at end of file[m
[31m-    case 40:[m
[31m-      if (lookahead == 'g') ADVANCE(44);[m
[32m+[m[32m  sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(363), 1,[m
      anon_sym_AMP_AMP,[m
[32m+[m[32m    ACTIONS(351), 2,[m
      ts_builtin_sym_[m
\ No newline at end of file[m
[32m+[m[32mend,[m
      anon_sym_LF,[m
    ACTIONS(355), [m
\ No newline at end of file[m
[32m+[m[32m2,[m
      anon_sym_PLUS,[m
      anon_sym_DAS[m
\ No newline at end of file[m
[32m+[m[32mH,[m
    ACTIONS(361), 2,[m
      anon_sym_LT_LT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT_GT,[m
    ACTIONS(357), 3,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mSTAR,[m
      anon_sym_SLASH,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_PERCENT,[m
    ACTIONS(365), 3,[m
      anon_sym_EQ_TIL[m
\ No newline at end of file[m
[32m+[m[32mDE,[m
      anon_sym_EQ_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_BANG_EQ,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(359), 4,[m
      anon_sym_GT,[m
      anon_s[m
\ No newline at end of file[m
 ym_GT_EQ,[m
      ano[m
\ No newline at end of file[m
[31m-    case 41:[m
[31m-      ACCEPT_TOKEN(anon_sym_table);[m
[32m+[m[32mn_sym_LT_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_LT,[m
    ACTIONS(353), 5,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_RPAREN,[m
      anon_sym_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_SEMI,[m
      anon_sym_RBRACE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PIPE_PIPE,[m
  [3650] = 3,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_comment,[m
    ACTIONS(351), 2,[m
     [m
\ No newline at end of file[m
[32m+[m[32m ts_builtin_sym_end,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LF,[m
    ACTIONS(353), 20,[m
      anon_sym_RPAREN,[m
      an[m
\ No newline at end of file[m
 on_sym_PIPE,[m
      [m
\ No newline at end of file[m
[31m-    case 42:[m
[31m-      ACCEPT_TOKEN(anon_sym_number);[m
[32m+[m[32manon_sym_SEMI,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_RBRACE,[m
      anon_sym_PLUS,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DASH,[m
      anon_sym_STAR,[m
[32m+[m[32m      anon_sym_SLASH,[m
      anon_sym_PERC[m
\ No newline at end of file[m
[32m+[m[32mENT,[m
      anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AM[m
\ No newline at end of file[m
[32m+[m[32mP,[m
      anon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_BANG_EQ,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      ano[m
\ No newline at end of file[m
 n_sym_LT,[m
      ano[m
\ No newline at end of file[m
[31m-    case 43:[m
[31m-      if (lookahead == 'n') ADVANCE(45);[m
[32m+[m[32mn_sym_LT_LT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_GT_GT,[m
  [3680] = 3,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(43), 1,[m
      sym_comment,[m
    ACTIONS(36[m
\ No newline at end of file[m
[32m+[m[32m7), 2,[m
      ts_builtin_sym_end[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LF,[m
    ACTIONS(369), 20,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_RPAREN,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_PIPE,[m
      anon_sym_SEMI,[m
     [m
\ No newline at end of file[m
  anon_sym_RBRACE,[m
 [m
\ No newline at end of file[m
[31m-    case 44:[m
[31m-      ACCEPT_TOKEN(anon_sym_string);[m
[32m+[m[32m     anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPLUS,[m
      anon_sym_DASH,[m
      anon_sym_STAR[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_SLASH,[m
      anon_sym_PER[m
\ No newline at end of file[m
[32m+[m[32mCENT,[m
      anon_sym_PIPE_PIPE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_AMP_AMP,[m
      anon_sym_EQ[m
\ No newline at end of file[m
[32m+[m[32m_TILDE,[m
      anon_sym_EQ_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_BANG_EQ,[m
      anon_sym_G[m
\ No newline at end of file[m
[32m+[m[32mT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_[m
\ No newline at end of file[m
 EQ,[m
      anon_sym_[m
\ No newline at end of file[m
[31m-    case 45:[m
[31m-      ACCEPT_TOKEN(anon_sym_pattern);[m
[32m+[m[32mLT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [3710] = 1[m
\ No newline at end of file[m
[32m+[m[32m0,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(363), 1,[m
      anon_sym_AMP_AMP,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(375), 1,[m
      anon_sym_PIPE_PIPE,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m355), 2,[m
      anon_sym_PLUS,[m
[32m+[m[32m      anon_sym_DASH,[m
    ACTIONS(361), 2,[m
      anon_sym_LT_LT,[m
[32m+[m[32m      anon_sym_GT_GT,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(371), 2,[m
      ts_builtin[m
\ No newline at end of file[m
[32m+[m[32m_sym_end,[m
      anon_sym_LF,[m
    ACTIONS(35[m
\ No newline at end of file[m
 7), 3,[m
      anon_s[m
\ No newline at end of file[m
[31m-    default:[m
[31m-      return false;[m
[31m-  }[m
[31m-}[m
[31m-[m
[31m-static TSLexMode ts_lex_modes[STATE_COUNT] = {[m
[31m-  [0] = {.lex_state = 0},[m
[31m-  [1] = {.lex_state = 41},[m
[31m-  [2] = {.lex_state = 37},[m
[31m-  [3] = {.lex_state = 37},[m
[31m-  [4] = {.lex_state = 37},[m
[31m-  [5] = {.lex_state = 37},[m
[31m-  [6] = {.lex_state = 37},[m
[31m-  [7] = {.lex_state = 37},[m
[31m-  [8] = {.lex_state = 6},[m
[31m-  [9] = {.lex_state = 6},[m
[31m-  [10] = {.lex_state = 6},[m
[31m-  [11] = {.lex_state = 6},[m
[31m-  [12] = {.lex_state = 6},[m
[31m-  [13] = {.lex_state = 6},[m
[31m-  [14] = {.lex_state = 6},[m
[31m-  [15] = {.lex_state = 6},[m
[31m-  [16] = {.lex_state = 6},[m
[31m-  [17] = {.lex_state = 6},[m
[31m-  [18] = {.lex_state = 6},[m
[31m-  [19] = {.lex_state = 37},[m
[31m-  [20] = {.lex_state = 37},[m
[31m-  [21] = {.lex_state = 37},[m
[31m-  [22] = {.lex_state = 37},[m
[31m-  [23] = {.lex_state = 37},[m
[31m-  [24] = {.lex_state = 37},[m
[31m-  [25] = {.lex_state = 37},[m
[31m-  [26] = {.lex_state = 37},[m
[31m-  [27] = {.lex_state = 37},[m
[31m-  [28] = {.lex_state = 37},[m
[31m-  [29] = {.lex_state = 37},[m
[31m-  [30] = {.lex_state = 37},[m
[31m-  [31] = {.lex_state = 37},[m
[31m-  [32] = {.lex_state = 37},[m
[31m-  [33] = {.lex_state = 40},[m
[31m-  [34] = {.lex_state = 37},[m
[31m-  [35] = {.lex_state = 37},[m
[31m-  [36] = {.lex_state = 37},[m
[31m-  [37] = {.lex_state = 37},[m
[31m-  [38] = {.lex_state = 37},[m
[31m-  [39] = {.lex_state = 37},[m
[31m-  [40] = {.lex_state = 37},[m
[31m-  [41] = {.lex_state = 37},[m
[31m-  [42] = {.lex_state = 37},[m
[31m-  [43] = {.lex_state = 37},[m
[31m-  [44] = {.lex_state = 37},[m
[31m-  [45] = {.lex_state = 37},[m
[31m-  [46] = {.lex_state = 37},[m
[31m-  [47] = {.lex_state = 37},[m
[31m-  [48] = {.lex_state = 37},[m
[31m-  [49] = {.lex_state = 37},[m
[31m-  [50] = {.lex_state = 37},[m
[31m-  [51] = {.lex_state = 37},[m
[31m-  [52] = {.lex_state = 40},[m
[31m-  [53] = {.lex_state = 37},[m
[31m-  [54] = {.lex_state = 37},[m
[31m-  [55] = {.lex_state = 37},[m
[31m-  [56] = {.lex_state = 37},[m
[31m-  [57] = {.lex_state = 6},[m
[31m-  [58] = {.lex_state = 38},[m
[31m-  [59] = {.lex_state = 38},[m
[31m-  [60] = {.lex_state = 38},[m
[31m-  [61] = {.lex_state = 41},[m
[31m-  [62] = {.lex_state = 41},[m
[31m-  [63] = {.lex_state = 38},[m
[31m-  [64] = {.lex_state = 41},[m
[31m-  [65] = {.lex_state = 41},[m
[31m-  [66] = {.lex_state = 41},[m
[31m-  [67] = {.lex_state = 41},[m
[31m-  [68] = {.lex_state = 41},[m
[31m-  [69] = {.lex_state = 37},[m
[31m-  [70] = {.lex_state = 37},[m
[31m-  [71] = {.lex_state = 37},[m
[31m-  [72] = {.lex_state = 37},[m
[31m-  [73] = {.lex_state = 37},[m
[31m-  [74] = {.lex_state = 37},[m
[31m-  [75] = {.lex_state = 37},[m
[31m-  [76] = {.lex_state = 37},[m
[31m-  [77] = {.lex_state = 37},[m
[31m-  [78] = {.lex_state = 41},[m
[31m-  [79] = {.lex_state = 41},[m
[31m-  [80] = {.lex_state = 41},[m
[31m-  [81] = {.lex_state = 41},[m
[31m-  [82] = {.lex_state = 41},[m
[31m-  [83] = {.lex_state = 8},[m
[31m-  [84] = {.lex_state = 8},[m
[31m-  [85] = {.lex_state = 8},[m
[31m-  [86] = {.lex_state = 8},[m
[31m-  [87] = {.lex_state = 6},[m
[31m-  [88] = {.lex_state = 6},[m
[31m-  [89] = {.lex_state = 6},[m
[31m-  [90] = {.lex_state = 6},[m
[31m-  [91] = {.lex_state = 6},[m
[31m-  [92] = {.lex_state = 6},[m
[31m-  [93] = {.lex_state = 6},[m
[31m-  [94] = {.lex_state = 6},[m
[31m-  [95] = {.lex_state = 6},[m
[31m-  [96] = {.lex_state = 6},[m
[31m-  [97] = {.lex_state = 6},[m
[31m-  [98] = {.lex_state = 6},[m
[31m-  [99] = {.lex_state = 6},[m
[31m-  [100] = {.lex_state = 6},[m
[31m-  [101] = {.lex_state = 6},[m
[31m-  [102] = {.lex_state = 6},[m
[31m-  [103] = {.lex_state = 11},[m
[31m-  [104] = {.lex_state = 11},[m
[31m-  [105] = {.lex_state = 11},[m
[31m-  [106] = {.lex_state = 11},[m
[31m-  [107] = {.lex_state = 41},[m
[31m-  [108] = {.lex_state = 41},[m
[31m-  [109] = {.lex_state = 41},[m
[31m-  [110] = {.lex_state = 41},[m
[31m-  [111] = {.lex_state = 41},[m
[31m-  [112] = {.lex_state = 41},[m
[31m-  [113] = {.lex_state = 41},[m
[31m-  [114] = {.lex_state = 41},[m
[31m-  [115] = {.lex_state = 41},[m
[31m-  [116] = {.lex_state = 41},[m
[31m-  [117] = {.lex_state = 41},[m
[31m-  [118] = {.lex_state = 41},[m
[31m-  [119] = {.lex_state = 41},[m
[31m-  [120] = {.lex_state = 41},[m
[31m-  [121] = {.lex_state = 41},[m
[31m-  [122] = {.lex_state = 41},[m
[31m-  [123] = {.lex_state = 41},[m
[31m-  [124] = {.lex_state = 41},[m
[31m-  [125] = {.lex_state = 41},[m
[31m-  [126] = {.lex_state = 41},[m
[31m-  [127] = {.lex_state = 41},[m
[31m-  [128] = {.lex_state = 41},[m
[31m-  [129] = {.lex_state = 41},[m
[31m-  [130] = {.lex_state = 41},[m
[31m-  [131] = {.lex_state = 10},[m
[31m-  [132] = {.lex_state = 41},[m
[31m-  [133] = {.lex_state = 10},[m
[31m-  [134] = {.lex_state = 10},[m
[31m-  [135] = {.lex_state = 10},[m
[31m-  [136] = {.lex_state = 10},[m
[31m-  [137] = {.lex_state = 39},[m
[31m-  [138] = {.lex_state = 10},[m
[31m-  [139] = {.lex_state = 10},[m
[31m-  [140] = {.lex_state = 37},[m
[31m-  [141] = {.lex_state = 10},[m
[31m-  [142] = {.lex_state = 37},[m
[31m-  [143] = {.lex_state = 37},[m
[31m-  [144] = {.lex_state = 37},[m
[31m-  [145] = {.lex_state = 37},[m
[31m-  [146] = {.lex_state = 10},[m
[31m-  [147] = {.lex_state = 10},[m
[31m-  [148] = {.lex_state = 10},[m
[31m-  [149] = {.lex_state = 10},[m
[31m-  [150] = {.lex_state = 10},[m
[31m-  [151] = {.lex_state = 37},[m
[31m-  [152] = {.lex_state = 37},[m
[31m-  [153] = {.lex_state = 10},[m
[31m-  [154] = {.lex_state = 10},[m
[31m-  [155] = {.lex_state = 3},[m
[31m-  [156] = {.lex_state = 8},[m
[31m-  [157] = {.lex_state = 37},[m
[31m-  [158] = {.lex_state = 0},[m
[31m-  [159] = {.lex_state = 0},[m
[31m-  [160] = {.lex_state = 0},[m
[31m-  [161] = {.lex_state = 0},[m
[31m-  [162] = {.lex_state = 0},[m
[31m-  [163] = {.lex_state = 0},[m
[31m-  [164] = {.lex_state = 3},[m
[31m-  [165] = {.lex_state = 10},[m
[31m-  [166] = {.lex_state = 3},[m
[31m-  [167] = {.lex_state = 0},[m
[31m-  [168] = {.lex_state = 12},[m
[31m-  [169] = {.lex_state = 12},[m
[31m-  [170] = {.lex_state = 9},[m
[31m-  [171] = {.lex_state = 12},[m
[31m-  [172] = {.lex_state = 8},[m
[31m-  [173] = {.lex_state = 12},[m
[31m-  [174] = {.lex_state = 9},[m
[31m-  [175] = {.lex_state = 12},[m
[31m-  [176] = {.lex_state = 9},[m
[31m-  [177] = {.lex_state = 12},[m
[31m-  [178] = {.lex_state = 9},[m
[31m-  [179] = {.lex_state = 9},[m
[31m-  [180] = {.lex_state = 12},[m
[31m-  [181] = {.lex_state = 9},[m
[31m-  [182] = {.lex_state = 3},[m
[31m-  [183] = {.lex_state = 4},[m
[31m-  [184] = {.lex_state = 8},[m
[31m-  [185] = {.lex_state = 12},[m
[31m-  [186] = {.lex_state = 3},[m
[31m-  [187] = {.lex_state = 9},[m
[31m-  [188] = {.lex_state = 12},[m
[31m-  [189] = {.lex_state = 9},[m
[31m-  [190] = {.lex_state = 9},[m
[31m-  [191] = {.lex_state = 0},[m
[31m-  [192] = {.lex_state = 3},[m
[31m-  [193] = {.lex_state = 0},[m
[31m-  [194] = {.lex_state = 3},[m
[31m-  [195] = {.lex_state = 3},[m
[31m-  [196] = {.lex_state = 3},[m
[31m-  [197] = {.lex_state = 0},[m
[31m-  [198] = {.lex_state = 3},[m
[31m-  [199] = {.lex_state = 0},[m
[31m-  [200] = {.lex_state = 3},[m
[31m-  [201] = {.lex_state = 3},[m
[31m-  [202] = {.lex_state = 3},[m
[31m-  [203] = {.lex_state = 8},[m
[31m-  [204] = {.lex_state = 3},[m
[31m-  [205] = {.lex_state = 3},[m
[31m-  [206] = {.lex_state = 3},[m
[31m-  [207] = {.lex_state = 3},[m
[31m-  [208] = {.lex_state = 3},[m
[31m-  [209] = {.lex_state = 3},[m
[31m-  [210] = {.lex_state = 3},[m
[31m-  [211] = {.lex_state = 0},[m
[31m-  [212] = {.lex_state = 0},[m
[31m-  [213] = {.lex_state = 41},[m
[31m-  [214] = {.lex_state = 0},[m
[31m-  [215] = {.lex_state = 0},[m
[31m-  [216] = {.lex_state = 8},[m
[31m-  [217] = {.lex_state = 0},[m
[31m-  [218] = {.lex_state = 0},[m
[31m-  [219] = {.lex_state = 0},[m
[31m-  [220] = {.lex_state = 8},[m
[31m-  [221] = {.lex_state = 0},[m
[31m-  [222] = {.lex_state = 0},[m
[31m-  [223] = {.lex_state = 41},[m
[31m-  [224] = {.lex_state = 0},[m
[31m-  [225] = {.lex_state = 0},[m
[31m-  [226] = {.lex_state = 8},[m
[31m-  [227] = {.lex_state = 41},[m
[31m-  [228] = {.lex_state = 8},[m
[31m-  [229] = {.lex_state = 0},[m
[31m-  [230] = {.lex_state = 0},[m
[31m-  [231] = {.lex_state = 8},[m
[31m-  [232] = {.lex_state = 8},[m
[31m-  [233] = {.lex_state = 0},[m
[31m-  [234] = {.lex_state = 0},[m
[31m-  [235] = {.lex_state = 8},[m
[31m-  [236] = {.lex_state = 8},[m
[31m-  [237] = {.lex_state = 41},[m
[31m-  [238] = {.lex_state = 8},[m
[31m-  [239] = {.lex_state = 41},[m
[31m-  [240] = {.lex_state = 0},[m
[31m-  [241] = {.lex_state = 8},[m
[31m-  [242] = {.lex_state = 0},[m
[31m-  [243] = {.lex_state = 0},[m
[31m-  [244] = {.lex_state = 8},[m
[31m-  [245] = {.lex_state = 41},[m
[31m-};[m
[31m-[m
[31m-static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {[m
[31m-  [0] = {[m
[31m-    [ts_builtin_sym_end] = ACTIONS(1),[m
[31m-    [sym_word] = ACTIONS(1),[m
[31m-    [anon_sym_def] = ACTIONS(1),[m
[31m-    [anon_sym_LBRACK] = ACTIONS(1),[m
[31m-    [anon_sym_COMMA] = ACTIONS(1),[m
[31m-    [anon_sym_RBRACK] = ACTIONS(1),[m
[31m-    [anon_sym_COLON] = ACTIONS(1),[m
[31m-    [anon_sym_QMARK] = ACTIONS(1),[m
[31m-    [anon_sym_LPAREN] = ACTIONS(1),[m
[31m-    [anon_sym_RPAREN] = ACTIONS(1),[m
[31m-    [anon_sym_DOT_DOT_DOTrest] = ACTIONS(1),[m
[31m-    [anon_sym_int] = ACTIONS(1),[m
[31m-    [anon_sym_string] = ACTIONS(1),[m
[31m-    [anon_sym_path] = ACTIONS(1),[m
[31m-    [anon_sym_table] = ACTIONS(1),[m
[31m-    [anon_sym_unit] = ACTIONS(1),[m
[31m-    [anon_sym_number] = ACTIONS(1),[m
[31m-    [anon_sym_pattern] = ACTIONS(1),[m
[31m-    [anon_sym_range] = ACTIONS(1),[m
[31m-    [anon_sym_block] = ACTIONS(1),[m
[31m-    [anon_sym_any] = ACTIONS(1),[m
[31m-    [anon_sym_let] = ACTIONS(1),[m
[31m-    [anon_sym_EQ] = ACTIONS(1),[m
[31m-    [anon_sym_PIPE] = ACTIONS(1),[m
[31m-    [sym_number_literal] = ACTIONS(1),[m
[31m-    [anon_sym_DQUOTE] = ACTIONS(1),[m
[31m-    [anon_sym_SQUOTE] = ACTIONS(1),[m
[31m-    [anon_sym_DOLLAR] = ACTIONS(1),[m
[31m-    [anon_sym_DOT] = ACTIONS(1),[m
[31m-    [aux_sym_file_path_token1] = ACTIONS(1),[m
[31m-    [anon_sym_DOT_DOT] = ACTIONS(1),[m
[31m-    [anon_sym_DOLLAR_LPAREN] = ACTIONS(1),[m
[31m-    [anon_sym_SEMI] = ACTIONS(1),[m
[31m-    [anon_sym_LBRACE] = ACTIONS(1),[m
[31m-    [anon_sym_RBRACE] = ACTIONS(1),[m
[31m-    [sym_comment] = ACTIONS(3),[m
[31m-    [anon_sym_PLUS] = ACTIONS(1),[m
[31m-    [anon_sym_DASH] = ACTIONS(1),[m
[31m-    [anon_sym_STAR] = ACTIONS(1),[m
[31m-    [anon_sym_SLASH] = ACTIONS(1),[m
[31m-    [anon_sym_PERCENT] = ACTIONS(1),[m
[31m-    [anon_sym_PIPE_PIPE] = ACTIONS(1),[m
[31m-    [anon_sym_AMP_AMP] = ACTIONS(1),[m
[31m-    [anon_sym_EQ_TILDE] = ACTIONS(1),[m
[31m-    [anon_sym_BANG_EQ] = ACTIONS(1),[m
[31m-    [anon_sym_GT] = ACTIONS(1),[m
[31m-    [anon_sym_GT_EQ] = ACTIONS(1),[m
[31m-    [anon_sym_LT_EQ] = ACTIONS(1),[m
[31m-    [anon_sym_LT] = ACTIONS(1),[m
[31m-    [anon_sym_LT_LT] = ACTIONS(1),[m
[31m-    [anon_sym_GT_GT] = ACTIONS(1),[m
[31m-  },[m
[31m-  [1] = {[m
[31m-    [sym_source_file] = STATE(234),[m
[31m-    [sym__statements] = STATE(222),[m
[31m-    [sym__statement] = STATE(152),[m
[31m-    [sym_function_definition] = STATE(152),[m
[31m-    [sym_variable_declaration] = STATE(152),[m
[31m-    [sym_command] = STATE(152),[m
[31m-    [sym_pipeline] = STATE(152),[m
[31m-    [sym_value_path] = STATE(72),[m
[31m-    [sym_command_substitution] = STATE(72),[m
[31m-    [sym_math_mode] = STATE(72),[m
[31m-    [sym_block] = STATE(152),[m
[31m-    [sym__math_expression] = STATE(72),[m
[31m-    [sym_parenthesized_math_expression] = STATE(72),[m
[31m-    [sym_binary_expression] = STATE(72),[m
[31m-    [aux_sym__statements_repeat1] = STATE(80),[m
[31m-    [ts_builtin_sym_end] = ACTIONS(5),[m
[31m-    [anon_sym_def] = ACTIONS(7),[m
[31m-    [anon_sym_LPAREN] = ACTIONS(9),[m
[31m-    [anon_sym_let] = ACTIONS(11),[m
[31m-    [sym_number_literal] = ACTIONS(13),[m
[31m-    [anon_sym_DOLLAR] = ACTIONS(15),[m
[31m-    [anon_sym_DOLLAR_LPAREN] = ACTIONS(17),[m
[31m-    [sym_identifier] = ACTIONS(19),[m
[31m-    [anon_sym_LBRACE] = ACTIONS(21),[m
[31m-    [sym_comment] = ACTIONS(3),[m
[31m-  },[m
[31m-};[m
[31m-[m
[31m-static uint16_t ts_small_parse_table[] = {[m
[31m-  [0] = 15,[m
[31m-    ACTIONS(23), 1,[m
[32m+[m[32mym_STAR,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(365), 3,[m
      anon_sym_EQ_TILDE,[m
[32m+[m[32m      anon_sym_EQ_EQ,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_BANG_EQ,[m
    ACTIONS(359), 4,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mGT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LT,[m
    ACTIONS(373[m
\ No newline at end of file[m
[32m+[m[32m), 4,[m
      anon_sym_RPAREN,[m
      anon_sym_PIPE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SEMI,[m
      anon_sym_RBRACE[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [3754] = 5,[m
    ACTIONS(43)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_comment,[m
    ACTIONS(351), 2[m
\ No newline at end of file[m
[32m+[m[32m,[m
      ts_builtin_[m
\ No newline at end of file[m
[32m+[m[32msym_end,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LF,[m
    ACTIONS(355), 2,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_PLUS,[m
      anon_sym_DASH,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(357), 3,[m
      anon_sym_STAR,[m
[32m+[m[32m      anon_sym_SLASH,[m
      anon_sym_PERCE[m
\ No newline at end of file[m
[32m+[m[32mNT,[m
    ACTIONS(353), 15,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_RPAREN,[m
      anon_sym_PIPE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SEMI,[m
\ No newline at end of file[m
[32m+[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_RBRACE,[m
      anon_sym_PIPE_PIPE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_AMP_AMP,[m
      anon_sym_EQ[m
\ No newline at end of file[m
[32m+[m[32m_TILDE,[m
      anon_sym_EQ_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_BANG_EQ,[m
      anon_sym_G[m
\ No newline at end of file[m
[32m+[m[32mT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_[m
\ No newline at end of file[m
[32m+[m[32mEQ,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [3788] = 6[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(43), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_comment,[m
    ACTIONS(351), 2,[m
      ts_bu[m
\ No newline at end of file[m
[32m+[m[32miltin_sym_end,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LF,[m
    ACTIONS(355), 2,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mLUS,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DASH,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(361), 2,[m
      anon_sym_LT_LT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_GT_GT,[m
    ACTIONS(357)[m
\ No newline at end of file[m
[32m+[m[32m, 3,[m
      anon_sym_STAR,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SLASH,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_PERCENT,[m
    ACTIONS(353), 13,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RPAREN,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PIPE,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_SEMI,[m
      anon_sym_RBRACE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PIPE_PIPE,[m
      anon_sym_A[m
\ No newline at end of file[m
[32m+[m[32mMP_AMP,[m
      anon_sym_EQ_TILDE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_GT,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LT,[m
  [3824] = 3,[m
[32m+[m[32m    ACTIONS(43), 1,[m
      sym_comment,[m
    ACTIONS(282), 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  ts_builtin_sym_en[m
\ No newline at end of file[m
[32m+[m[32md,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LF,[m
    ACTIONS(280), 20,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_RPAREN,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_PIP[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      anon_sym_SEMI,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_RBRACE,[m
      anon_sym_PLUS,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DASH,[m
      anon_sym_STAR,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_SLASH,[m
      anon_sym_PERCENT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_BANG_EQ,[m
      anon_sym_GT,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mGT_EQ,[m
      anon_sym_LT_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_LT,[m
      anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[3854] = 8,[m
    ACTIONS(43),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
    ACTIONS(351), 2,[m
\ No newline at end of file[m
[32m+[m
      ts_builtin_s[m
\ No newline at end of file[m
[32m+[m[32mym_end,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LF,[m
    ACTIONS(355), 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_PLUS,[m
      anon_sym_DASH,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(361), 2,[m
      anon_sym_LT_LT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_GT_GT,[m
    ACTIONS(357), 3,[m
      anon_sym_STAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SLASH[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PERCENT,[m
    ACTIONS(365), 3,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_EQ_TILDE,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_EQ_E[m
\ No newline at end of file[m
[32m+[m[32mQ,[m
      anon_sym_BANG_EQ,[m
    ACTIONS(359),[m
\ No newline at end of file[m
[32m+[m[32m 4,[m
      anon_sym_GT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT,[m
    ACTIONS(353[m
\ No newline at end of file[m
[32m+[m[32m), 6,[m
      anon_sym_RPAREN,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_PIPE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_SEMI,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_RBRACE,[m
      anon_sym_PIP[m
\ No newline at end of file[m
[32m+[m[32mE_PIPE,[m
      anon_sym_AMP_AMP,[m
  [3894] = [m
\ No newline at end of file[m
[32m+[m[32m4,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(351), 2,[m
      ts_builtin_sym_[m
\ No newline at end of file[m
[32m+[m[32mend,[m
      anon_sym_LF,[m
    ACTIONS(357), [m
\ No newline at end of file[m
[32m+[m[32m3,[m
      anon_sym_STAR,[m
      anon_sym_SLA[m
\ No newline at end of file[m
[32m+[m[32mSH,[m
      anon_sym_PERCENT,[m
    ACTIONS(353), 17,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_RPAREN,[m
      anon_sym_PIPE,[m
      anon_sym_SEMI,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RBRACE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_PLUS,[m
      anon_sym_DASH,[m
      anon_sym_PIPE_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_AMP_AMP,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_BANG_EQ,[m
\ No newline at end of file[m
[32m+[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT,[m
      anon_sym_GT_EQ,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LT_EQ,[m
      anon_sym_LT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [3926[m
\ No newline at end of file[m
[32m+[m[32m] = 12,[m
    ACTIONS(3), 1,[m
      sym_comme[m
\ No newline at end of file[m
[32m+[m[32mnt,[m
    ACTIONS(377), 1,[m
      anon_sym_de[m
\ No newline at end of file[m
[32m+[m[32mf,[m
    ACTIONS(380), 1,[m
      anon_sym_LPA[m
\ No newline at end of file[m
[32m+[m[32mREN,[m
    ACTIONS(383), 1,[m
      anon_sym_let,[m
    ACTIONS(386), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_number_literal,[m
    ACTIONS(389), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DOLLAR,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(392), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
    ACTIONS(395), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_identifier,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(398), 1,[m
      anon_sym_LBRACE,[m
    ST[m
\ No newline at end of file[m
[32m+[m[32mATE(84), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mux_sym__statem[m
\ No newline at end of file[m
[32m+[m[32ments_repeat1,[m
    STATE(78), 6,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_value_path,[m
      sym_command_subst[m
\ No newline at end of file[m
[32m+[m[32mitution,[m
      sym_math_mode,[m
      sym__[m
\ No newline at end of file[m
[32m+[m[32mmath_expression,[m
      sym_parenthesized_[m
\ No newline at end of file[m
[32m+[m[32mmath_expression,[m
      sym_binary_expression,[m
    STATE(186), 6,[m
\ No newline at end of file[m
[32m+[m
      sym__statement,[m
      sym_function_definition[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_variable_declarati[m
\ No newline at end of file[m
[32m+[m[32mon,[m
      sym_command,[m
      sym_pipeline,[m
      sym_block,[m
  [3[m
\ No newline at end of file[m
[32m+[m[32m973] = 12,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    ACTIONS(7), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_def,[m
    ACTIONS(9), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LPAREN,[m
    ACTIONS(11), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_let,[m
    ACTIONS(13), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_number_literal,[m
    ACTIONS(15), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DOLLAR,[m
    ACTIONS(17), 1,[m
      anon_sym_DO[m
\ No newline at end of file[m
[32m+[m[32mLLAR_LPAREN,[m
    ACTIONS(21), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_LBRACE,[m
    ACTIONS(333), 1,[m
      sym_identif[m
\ No newline at end of file[m
[32m+[m[32mier,[m
    STATE(84),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      aux_[m
\ No newline at end of file[m
[32m+[m[32msym__statements_repeat1,[m
    STATE(7[m
\ No newline at end of file[m
[32m+[m[32m8), 6,[m
      sym_value_path,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmmand_substitution,[m
      sym_math_mode,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym__math_expression,[m
      sym_parenthesized_math_expressi[m
\ No newline at end of file[m
[32m+[m[32mon,[m
      sym_binary_expression,[m
    STATE(151), 6,[m
[32m+[m[32m      sym__statement,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_function_definition,[m
      sym_variable_declaration,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_command,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_pipeline,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_block,[m
  [4020] = 12,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(3), 1,[m
      sym_comment,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(7), 1,[m
      anon_sym_def,[m
    ACTIONS(9[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_LPAREN,[m
    ACTIONS(11), 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mlet,[m
    ACTIONS(13), 1,[m
      sym_number_literal,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(15), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_DOLLAR,[m
    ACTIONS(17), 1,[m
      anon_sym_DOLLAR_LPAREN,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(19), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_ident[m
\ No newline at end of file[m
[32m+[m[32mifier,[m
    ACTIONS(21), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LBRACE,[m
    STATE(84), 1,[m
      aux[m
\ No newline at end of file[m
[32m+[m[32m_sym__statements_repeat1,[m
    STATE(78), [m
\ No newline at end of file[m
[32m+[m[32m6,[m
      sym_value_path,[m
      sym_command_substitution,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_math_mode,[m
      sym__math_expression,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mparenthesized_math_expression,[m
\ No newline at end of file[m
[32m+[m
      sym_binary_expression,[m
    STATE(166), 6,[m
      sym__stat[m
\ No newline at end of file[m
[32m+[m[32mement,[m
      sym_fu[m
\ No newline at end of file[m
[32m+[m[32mnction_definit[m
\ No newline at end of file[m
[32m+[m[32mion,[m
      sym_variable_declaration,[m
\ No newline at end of file[m
[32m+[m
      sym_command,[m
      sym_pipeline,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_block,[m
  [4067] = 11,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_comment,[m
    ACTIONS(7), 1,[m
      anon_sym_def[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(9), 1,[m
      anon_sym_LPAREN,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(11), 1,[m
      anon_sym_let[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(13), 1,[m
      sym_number_literal,[m
    ACTIONS(15),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mDOLLAR,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(17), 1,[m
      anon_sym_DOLLAR_[m
\ No newline at end of file[m
[32m+[m[32mLPAREN,[m
    ACTIONS(19), 1,[m
      sym_ide[m
\ No newline at end of file[m
[32m+[m[32mntifier,[m
    ACTIONS(21), 1,[m
      anon_sym_LBRACE,[m
    STATE(78[m
\ No newline at end of file[m
[32m+[m[32m), 6,[m
      sym_value_path,[m
      sym_command_substi[m
\ No newline at end of file[m
[32m+[m[32mtution,[m
      sym_math_mode,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym__math_expression,[m
      sym_parenthesized_math_expressi[m
\ No newline at end of file[m
[32m+[m[32mon,[m
      sym_binar[m
\ No newline at end of file[m
[32m+[m[32my_expression,[m
[32m+[m[32m    STATE(161), 6,[m
      sym__statem[m
\ No newline at end of file[m
[32m+[m[32ment,[m
      sym_function_definition,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_variable_declaration,[m
      sym_command,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_pipeline,[m
      sym_block,[m
  [4111] = 11,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(3), 1,[m
      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(7), 1,[m
      anon_sym_def,[m
    ACTIONS(9), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LPAREN,[m
[32m+[m[32m    ACTIONS(11[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_let,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(13), 1,[m
      sym_number_literal,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(15), 1,[m
      anon_sym_DOLLAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(17), 1,[m
      anon_sym_DOLLAR_LP[m
\ No newline at end of file[m
[32m+[m[32mAREN,[m
    ACTIONS(21), 1,[m
      anon_sym_LBRACE,[m
    ACTIONS(333[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_identifier,[m
    STATE(78), 6,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_value_path,[m
      sym_comm[m
\ No newline at end of file[m
[32m+[m[32mand_substitution,[m
      sym_math_mode,[m
      sym__math_expressio[m
\ No newline at end of file[m
[32m+[m[32mn,[m
      sym_parenthesized_m[m
\ No newline at end of file[m
[32m+[m[32math_expression,[m
      sym_binary_expressio[m
\ No newline at end of file[m
[32m+[m[32mn,[m
    STATE(161), [m
\ No newline at end of file[m
[32m+[m[32m6,[m
      sym__[m
\ No newline at end of file[m
[32m+[m[32mstatement,[m
      sym_function_defini[m
\ No newline at end of file[m
[32m+[m[32mtion,[m
      sym_variable_declaration,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_command,[m
      sym_pipeline,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_block,[m
  [4155] = 5,[m
    ACTIONS(3), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
    ACTIONS(401), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOT,[m
    STATE(90), 1,[m
      aux_sym_v[m
\ No newline at end of file[m
[32m+[m[32malue_path_repeat1,[m
    ACTIONS(251), 2,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT,[m
      anon_sym_LT,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(253), 15,[m
      anon_sym_RPAREN,[m
      anon_sym_PLUS,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DASH,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_STAR,[m
      anon_sym_SLAS[m
\ No newline at end of file[m
[32m+[m[32mH,[m
      anon_sym_PERCENT,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mIPE_PIPE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_AMP_AMP,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_EQ_TILDE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LT_LT,[m
      anon_sym_GT_GT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[4186] = 5,[m
    ACTIONS(3), 1,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32momment,[m
    ACTIONS(401), 1,[m
      anon_sym_DOT,[m
    STATE(91), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      aux_sym_value_path_repeat1,[m
    ACTIONS(245[m
\ No newline at end of file[m
[32m+[m[32m), 2,[m
      anon_sym_GT,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LT,[m
    ACTIONS(249), 15,[m
      anon_sym_RPAREN,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_PLUS,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DASH,[m
      anon_sym_STAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SLASH,[m
      anon_sym_PERCENT[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PI[m
\ No newline at end of file[m
[32m+[m[32mPE_PIPE,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_AMP_AMP,[m
      anon_sym_E[m
\ No newline at end of file[m
[32m+[m[32mQ_TILDE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_EQ_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_BANG_EQ,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT_EQ,[m
      anon_sym_LT_EQ,[m
[32m+[m[32m      anon_sym_LT_LT,[m
      anon_sym_GT_GT[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [4217] = 5,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_comment,[m
    ACTIONS(403),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mDOT,[m
    STATE[m
\ No newline at end of file[m
[32m+[m[32m(91), 1,[m
      aux_sym_value_pa[m
\ No newline at end of file[m
[32m+[m[32mth_repeat1,[m
    ACTIONS(238), 2,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_GT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LT,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(243), 15,[m
      anon_sym_RPAR[m
\ No newline at end of file[m
[32m+[m[32mEN,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPLUS,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DASH,[m
      anon_sym_STAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SLASH,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PERCENT,[m
      anon_sym_PIPE_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_AMP_AMP,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_BANG_EQ,[m
\ No newline at end of file[m
[32m+[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT_EQ,[m
      anon_sym_LT_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT_LT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_GT[m
\ No newline at end of file[m
[32m+[m[32m_GT,[m
  [4248] = 3,[m
    ACTIONS(3), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(238), 2,[m
      anon_sym_GT,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LT,[m
    ACTIONS(243), 16,[m
[32m+[m[32m      anon_sym_RPAREN,[m
      anon_sym_DOT,[m
[32m+[m[32m      anon_sym_PLUS[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DASH,[m
      anon_sym_STAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
[32m+[m[32m      anon_sym_PIPE_PIPE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_AMP_AMP,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_EQ_TILDE[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_EQ_EQ,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_BANG_EQ,[m
      anon_sym_GT_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT_EQ,[m
      anon_sym_LT_LT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_GT_GT,[m
\ No newline at end of file[m
[32m+[m
  [4274] = 6,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mment,[m
    ACTIONS(353), 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_GT,[m
      anon_sym_LT,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(406), 2,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPLUS,[m
      anon_sym_DASH,[m
    ACTIONS(410)[m
\ No newline at end of file[m
[32m+[m[32m, 2,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LT_LT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_GT_GT,[m
    ACTIONS(408),[m
\ No newline at end of file[m
[32m+[m[32m 3,[m
      anon_sym_STAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
[32m+[m[32m    ACTIONS(351), 8[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_RPAREN,[m
      anon_sym_PIPE_PI[m
\ No newline at end of file[m
[32m+[m[32mPE,[m
      anon_sym_AMP_AMP,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mEQ_TILDE,[m
      anon_sym_EQ_EQ,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_BANG_EQ,[m
      anon_sym_G[m
\ No newline at end of file[m
[32m+[m[32mT_EQ,[m
      anon_sym_LT_EQ,[m
  [4305] = 3[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS(369), 2,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_GT,[m
      anon_sym_LT,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(367), 15,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_RPAREN[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PLUS,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DASH,[m
      anon_sym_STAR,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_SLASH,[m
      anon_sym_PERCENT,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PIPE_PIPE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_AMP_AMP,[m
      anon_sym_EQ_TILDE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_EQ_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mBANG_EQ,[m
      anon_sym_GT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT_EQ,[m
      anon_sym_LT_LT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_GT_GT,[m
  [4330] = 3,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(3), 1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(280), 2,[m
      anon_sym_GT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_LT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(282[m
\ No newline at end of file[m
[32m+[m[32m), 15,[m
      anon_sym_RPAREN,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_PLUS,[m
      anon_sym_DASH,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_STAR,[m
      anon_sym_SLASH,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_PERCENT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_TI[m
\ No newline at end of file[m
[32m+[m[32mLDE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_EQ_EQ,[m
      anon_sym_BANG_[m
\ No newline at end of file[m
[32m+[m[32mEQ,[m
      anon_sym_GT_EQ,[m
      anon_sym_LT[m
\ No newline at end of file[m
[32m+[m[32m_EQ,[m
      anon_sym_LT_LT,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mGT_GT,[m
  [4355] = 10,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(3), 1,[m
      sym_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m412), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RPAREN,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(414), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_PIPE_PIPE,[m
    ACTIONS(416), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_AMP_AMP,[m
    ACTIONS(406), 2,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PLUS,[m
      anon_sym_D[m
\ No newline at end of file[m
[32m+[m[32mASH,[m
    ACTIONS(410), 2,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLT_LT,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT_GT,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(420), 2,[m
      anon_sym_G[m
\ No newline at end of file[m
[32m+[m[32mT,[m
      anon_sym_LT,[m
    ACTIONS(422), 2,[m
[32m+[m[32m      anon_sym_GT_EQ,[m
      anon_sym_LT_EQ[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(408), 3,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_STAR,[m
      anon_sym_SLASH,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PERCENT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(418[m
\ No newline at end of file[m
[32m+[m[32m), 3,[m
      anon_sym_EQ_TILDE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
\ No newline at end of file[m
[32m+[m
  [4394] = 10,[m
    ACTIONS(3), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIONS(414), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PIPE_PIPE,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m16), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_AMP_AMP,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(424), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_RPAREN,[m
    ACTIONS(406), 2,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PLUS,[m
      anon_sym_DASH,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m410), 2,[m
      anon_sym_LT_LT,[m
[32m+[m[32m      anon_sym_GT_GT,[m
    ACTIONS(420), 2[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_GT[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT,[m
    ACTIONS(422), 2,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT_EQ,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LT_[m
\ No newline at end of file[m
[32m+[m[32mEQ,[m
    ACTIONS(408), 3,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_STAR,[m
      anon_sym_SLASH,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_PERCENT,[m
    ACTIONS(418), 3,[m
      anon_sym_EQ_TILDE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_EQ[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_BANG_EQ,[m
  [4433] = 10,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(3), 1,[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(414), 1,[m
      anon_sym_PIPE_PI[m
\ No newline at end of file[m
[32m+[m[32mPE,[m
    ACTIONS(416), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_AMP_AMP,[m
    ACTIONS(426), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RPARE[m
\ No newline at end of file[m
[32m+[m[32mN,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(406), 2,[m
      anon_sym_PLUS,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DASH,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(410)[m
\ No newline at end of file[m
[32m+[m[32m, 2,[m
      anon_sym_LT_LT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_GT_GT,[m
    ACTIONS(420),[m
\ No newline at end of file[m
[32m+[m[32m 2,[m
      anon_sym_GT,[m
      anon_sym_LT,[m
[32m+[m[32m    ACTIONS(422), 2,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(408), 3,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_STA[m
\ No newline at end of file[m
[32m+[m[32mR,[m
      anon_sym_SLASH,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_PERCENT,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(418), 3[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_EQ_TILDE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
  [4[m
\ No newline at end of file[m
[32m+[m[32m472] = 10,[m
    ACTIONS(3), 1,[m
      sym_comment,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m14), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_PIPE_PIPE,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(416), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_AMP_AMP,[m
    ACTIONS(428), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_RPAREN,[m
    ACTIONS(406), [m
\ No newline at end of file[m
[32m+[m[32m2,[m
      anon_sym_PLUS,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DASH,[m
    ACTIONS(410), 2,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LT_LT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_G[m
\ No newline at end of file[m
[32m+[m[32mT_GT,[m
    ACTIONS(420), 2,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_GT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LT,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(422), 2,[m
      anon_sym_GT_E[m
\ No newline at end of file[m
[32m+[m[32mQ,[m
      anon_sym_LT_EQ,[m
    ACTIONS(408),[m
\ No newline at end of file[m
[32m+[m[32m 3,[m
      anon_sym_STAR,[m
      anon_sym_SLASH,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPERCENT,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(418), 3,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_EQ_TILDE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
\ No newline at end of file[m
[32m+[m
  [4511] = 5,[m
    ACTIONS(3), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    ACTIONS(353),[m
\ No newline at end of file[m
[32m+[m[32m 2,[m
      anon_sym_GT,[m
      anon_sym_LT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(406), 2,[m
\ No newline at end of file[m
[32m+[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_PLUS,[m
      anon_sym_DASH,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(408), 3,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_STAR,[m
[32m+[m[32m      anon_sym_SLASH,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mERCENT,[m
    ACTIONS(351), 10,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_RPAREN,[m
      anon_sym_PIPE_PIPE,[m
      anon_sym_AMP_AMP,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_EQ_TI[m
\ No newline at end of file[m
[32m+[m[32mLDE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_GT_EQ,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT_EQ,[m
      anon_sym_LT_LT,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_GT_GT,[m
  [4540] = 10,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
      sym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(414), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mIPE_PIPE,[m
    ACTIONS(416), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_AMP_AMP,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(430),[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_RPAREN,[m
    ACTIONS(40[m
\ No newline at end of file[m
[32m+[m[32m6), 2,[m
      anon_sym_PLUS,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DASH,[m
    ACTIONS(410), 2,[m
      anon_sym_LT_LT,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT_GT,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(420), 2,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_GT,[m
      anon_sym_LT,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(422), 2,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_GT_EQ,[m
      anon_sym_LT_EQ,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m408), 3,[m
      anon_sym_STAR[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_SLASH,[m
      anon_sym_PERC[m
\ No newline at end of file[m
[32m+[m[32mENT,[m
    ACTIONS(41[m
\ No newline at end of file[m
[32m+[m[32m8), 3,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_EQ_TILDE,[m
      anon_sym_EQ_EQ[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_BA[m
\ No newline at end of file[m
[32m+[m[32mNG_EQ,[m
  [4579[m
\ No newline at end of file[m
[32m+[m[32m] = 7,[m
    ACTIONS(3), 1,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS(406), 2,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_PLUS,[m
      anon_sym_DASH,[m
    ACTIONS(410), 2,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LT_LT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_GT_GT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(420), 2,[m
      anon_sym_GT,[m
[32m+[m[32m      anon_sym_LT,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m422), 2,[m
      anon_sym_GT_EQ,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LT_EQ,[m
    ACTIONS(408),[m
\ No newline at end of file[m
[32m+[m[32m 3,[m
      anon_sym_STAR,[m
      anon_sym_SLA[m
\ No newline at end of file[m
[32m+[m[32mSH,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPERCENT,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(351), 6,[m
      anon_sym_RPAREN,[m
[32m+[m[32m      anon_sym_PIPE[m
\ No newline at end of file[m
[32m+[m[32m_PIPE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_AMP_AMP,[m
      anon_sym_EQ_TILD[m
\ No newline at end of file[m
[32m+[m[32mE,[m
      anon_sym_EQ_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_BANG_EQ,[m
  [4612] = 10,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(3), 1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(414), 1,[m
      anon_sym_PIPE_P[m
\ No newline at end of file[m
[32m+[m[32mIPE,[m
    ACTIONS(41[m
\ No newline at end of file[m
[32m+[m[32m6), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_AMP_AMP,[m
    ACTIONS(432), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_RP[m
\ No newline at end of file[m
[32m+[m[32mAREN,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(406), 2,[m
      anon_sym_PLUS,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DASH,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m410), 2,[m
      anon_sym_LT_LT,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_GT_GT,[m
    ACTIONS(420),[m
\ No newline at end of file[m
[32m+[m[32m 2,[m
      anon_sym_GT,[m
      anon_sym_LT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(422), 2,[m
\ No newline at end of file[m
[32m+[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_GT_EQ,[m
      anon_sym_LT_EQ,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(408), 3,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_STAR[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_SLASH,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_PERCENT,[m
    ACTIONS(418), 3,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_EQ_TILDE,[m
      anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[4651] = 10,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(3), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_comment,[m
    ACTIONS(414), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_PIPE_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(416), 1,[m
      anon_sym_AMP_AMP,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(434), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_RPAREN,[m
    ACTIONS(406), 2,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PLUS,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_DASH[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(410), 2,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT_LT,[m
      anon_sym_GT_GT,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(420), 2,[m
      anon_sym_GT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LT,[m
    ACTIONS(422), 2,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_GT_EQ,[m
      anon_sym_LT_EQ,[m
    ACTIONS(408), 3,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_STAR,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_SLASH,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_PERCENT,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(418), 3,[m
      anon_sym_EQ_TILDE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
[32m+[m[32m  [4690] = 8,[m
    ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
    ACTIONS(406), 2,[m
[32m+[m[32m      anon_sym_PLUS,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DASH,[m
    ACTIONS(410), 2,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LT_LT,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_GT_G[m
\ No newline at end of file[m
[32m+[m[32mT,[m
    ACTIONS(420), 2,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_GT,[m
      anon_sym_LT,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m22), 2,[m
      anon_sym_GT_EQ,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LT_EQ,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(351), 3,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_RPAREN,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPIPE_PIPE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_AMP_AMP[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(408), 3,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_STAR,[m
      anon_sym_SLASH,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PERCENT,[m
    ACTIONS(418), 3,[m
      anon_sym_EQ_TILDE,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_EQ_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mBANG_EQ,[m
  [4725] = 9,[m
    ACTIONS(3[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(416), 1,[m
      anon_sym_AMP_AMP,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(351), 2,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RPAREN,[m
      anon_sym_PIPE_PIPE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(406), 2,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mLUS,[m
      anon_sym_DASH,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(410), 2,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LT_LT,[m
[32m+[m[32m      anon_sym_GT_GT,[m
    ACTIONS(42[m
\ No newline at end of file[m
[32m+[m[32m0), 2,[m
      anon_sym_GT,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mT,[m
    ACTIONS(422), 2,[m
      anon_sym_GT_EQ,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mT_EQ,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m08), 3,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_STAR,[m
      anon_sym_SLASH,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_PERCENT,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(418), 3,[m
      anon_sym_EQ_TILDE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_EQ_EQ,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_BANG_EQ,[m
  [4762] = 3,[m
    ACTIONS(3[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(353), 2,[m
      anon_sym_GT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_LT,[m
    ACTIONS(351), 15,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_RPAREN,[m
      anon_sym_PLUS,[m
[32m+[m[32m      anon_sym_DASH,[m
      anon_sym_STAR,[m
[32m+[m[32m      anon_sym_SLASH,[m
      anon_sym_PERCENT,[m
      anon_sym_P[m
\ No newline at end of file[m
[32m+[m[32mIPE_PIPE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_AMP_AMP,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_EQ_TILDE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_LT_LT,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_GT_GT,[m
  [4787] = 4,[m
    ACTIONS(3), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(353), 2,[m
      anon_sym_GT,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_LT,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(408), 3,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_STAR,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SLASH,[m
      anon_sym_PERCENT,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(351), 12,[m
      anon_sym_RPAREN,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_PLUS,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_DASH[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_PIPE_PIPE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_AMP_AMP,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_EQ[m
\ No newline at end of file[m
[32m+[m[32m_TILDE,[m
      anon_sym_EQ_EQ,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_BANG_EQ,[m
      anon_sym_GT_EQ,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LT_EQ,[m
      anon_sym_LT_LT,[m
      anon_sym_GT_GT[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [4814] = 3,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
    ACTIONS(312[m
\ No newline at end of file[m
[32m+[m[32m), 2,[m
      anon_sym_GT,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LT,[m
    ACTIONS(314), 15,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_RPAREN,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_PLUS,[m
      anon_sym_DASH,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_STAR,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_SLASH,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_PERCENT,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mPIPE_PIPE,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_AMP_AMP[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_EQ_TILDE,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_EQ_EQ,[m
      anon_sym_BANG_EQ,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_GT_EQ,[m
      anon_sym_LT_EQ,[m
      anon_sym_LT_LT,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_GT_GT[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [4839] = 3[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(3), 1,[m
      sym_comme[m
\ No newline at end of file[m
[32m+[m[32mnt,[m
    STATE(167), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_type,[m
    ACTIONS(436), 10,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_int,[m
      anon_sym_strin[m
\ No newline at end of file[m
[32m+[m[32mg,[m
      anon_sym_path,[m
      anon_sym_tabl[m
\ No newline at end of file[m
[32m+[m[32me,[m
      anon_sym_u[m
\ No newline at end of file[m
[32m+[m[32mnit,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_number,[m
     [m
\ No newline at end of file[m
[32m+[m[32m ano[m
\ No newline at end of file[m
[32m+[m[32mn_[m
\ No newline at end of file[m
[32m+[m[32ms[m
\ No newline at end of file[m
[32m+[m[32mym_pattern,[m
      anon_sym_range,[m
      anon_sym_block,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_any,[m
  [4[m
\ No newline at end of file[m
[32m+[m[32m858] = 3,[m
    ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    STATE([m
\ No newline at end of file[m
[32m+[m[32m147), 1,[m
      sym_type,[m
    ACTIONS(436[m
\ No newline at end of file[m
[32m+[m[32m), 10,[m
      anon_sym_int,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_string,[m
      anon_sym_path,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_table,[m
      anon_sym_unit,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_number,[m
      anon_sym_pattern,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_range,[m
      anon_sym_bl[m
\ No newline at end of file[m
[32m+[m[32mock,[m
      anon_sym_any,[m
  [4877] = 3,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(3), 1,[m
      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m STATE(169), 1,[m
      sym_type,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(436), 10,[m
      anon_sym_in[m
\ No newline at end of file[m
[32m+[m[32mt,[m
      anon_sym_string,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_path,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mtable,[m
      anon_sym_unit,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_number,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_p[m
\ No newline at end of file[m
[32m+[m[32mattern,[m
      anon_sym_range,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_block,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_any,[m
[32m+[m[32m  [4896] = 3,[m
    ACTIONS(3), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    STAT[m
\ No newline at end of file[m
[32m+[m[32mE(172), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_type,[m
    ACTIONS(436), 10,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_int,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mstring,[m
      anon_sym_path,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_table,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_unit,[m
[32m+[m[32m      anon_sym_number,[m
      anon_sym_pat[m
\ No newline at end of file[m
[32m+[m[32mtern,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_range,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_block,[m
      anon_sym_any,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[4915] = 6,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(3), 1,[m
[32m+[m[32m      sym_comment,[m
    ACTIONS(9), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LPAREN,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(15), 1,[m
      anon_sym_DOLLAR,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(17), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DOLLA[m
\ No newline at end of file[m
[32m+[m[32mR_LPAREN,[m
    ACTIONS(438), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mnumber_literal,[m
   [m
\ No newline at end of file[m
[32m+[m[32m STATE(75), 6[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_value_path,[m
      sym_command[m
\ No newline at end of file[m
[32m+[m[32m_substitution,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_math_mo[m
\ No newline at end of file[m
[32m+[m[32mde,[m
      sym__math_expression,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_parenthesized_math[m
\ No newline at end of file[m
[32m+[m[32m_expression,[m
[32m+[m[32m      sym_binary_expression,[m
  [4939] = 6[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32momment,[m
    ACTIONS(440), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LPAREN,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(442), 1,[m
[32m+[m[32m      sym_number_literal,[m
    ACTIONS(444[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(446), 1,[m
      anon_sym_DOLLAR_L[m
\ No newline at end of file[m
[32m+[m[32mPAREN,[m
    STATE(10[m
\ No newline at end of file[m
[32m+[m[32m1), 6,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_value_path,[m
      sym_command_substit[m
\ No newline at end of file[m
[32m+[m[32mution,[m
      sym_ma[m
\ No newline at end of file[m
[32m+[m[32mth_mode,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym__math_expression,[m
      sym_parenth[m
\ No newline at end of file[m
[32m+[m[32mesized_math_express[m
\ No newline at end of file[m
[32m+[m[32mion,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_binary_expression,[m
  [4963] = 6,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(3), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
[32m+[m[32m    ACTIONS(9), 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLPAREN,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(15), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DOLLAR,[m
    ACTIONS(17), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DOLLAR[m
\ No newline at end of file[m
[32m+[m[32m_LPAREN,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(448), 1,[m
      sym_number_[m
\ No newline at end of file[m
[32m+[m[32mliteral,[m
    STATE([m
\ No newline at end of file[m
[32m+[m[32m76), 6,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_value_path,[m
      sym_command_substi[m
\ No newline at end of file[m
[32m+[m[32mtution,[m
      sym_m[m
\ No newline at end of file[m
[32m+[m[32math_mode,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym__math_expression,[m
      sym_parent[m
\ No newline at end of file[m
[32m+[m[32mhesized_math_expression,[m
      sym_binary[m
\ No newline at end of file[m
[32m+[m[32m_expression,[m
  [498[m
\ No newline at end of file[m
[32m+[m[32m7] = 6,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(3), 1,[m
      sym_comment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(9), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LPAREN[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(15), 1,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR,[m
    ACTIONS(17)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DOLLAR_LPAREN,[m
    ACTIONS(450), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_number_[m
\ No newline at end of file[m
[32m+[m[32mliteral,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(82), 6,[m
      sym_value_path,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_command_substi[m
\ No newline at end of file[m
[32m+[m[32mtution,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_math_mode,[m
      sym__math_expressio[m
\ No newline at end of file[m
[32m+[m[32mn,[m
      sym_parent[m
\ No newline at end of file[m
[32m+[m[32mhesized_math_[m
\ No newline at end of file[m
[32m+[m[32mexpression,[m
      sym_binary_expression,[m
[32m+[m[32m  [5011] = 6,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(3), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
    ACTIONS(9),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLPAREN,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(15), 1,[m
      anon_sym_DOLLAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(17), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mDOLLAR_LPAREN,[m
    ACTIONS(452), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_number_literal[m
\ No newline at end of file[m
[32m+[m[32m,[m
    STATE(8[m
\ No newline at end of file[m
[32m+[m[32m0), 6,[m
      sym_value_path,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmmand_substitution,[m
\ No newline at end of file[m
[32m+[m
      sym_ma[m
\ No newline at end of file[m
[32m+[m[32mth_mode,[m
      sym__math_expression,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_parenthesized[m
\ No newline at end of file[m
[32m+[m[32m_math_express[m
\ No newline at end of file[m
[32m+[m[32mion,[m
      sym_binary_expression,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [5035] = 6,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(3), 1,[m
[32m+[m[32m      sym_comment,[m
    ACTIONS(9), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LP[m
\ No newline at end of file[m
[32m+[m[32mAREN,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(15), 1,[m
      anon_sym_DOLLAR,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(17), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DO[m
\ No newline at end of file[m
[32m+[m[32mLLAR_LPAREN,[m
    ACTIONS(454), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_number_literal,[m
[32m+[m[32m    STATE(83)[m
\ No newline at end of file[m
[32m+[m[32m, 6,[m
      sym_value_path,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_command_substituti[m
\ No newline at end of file[m
[32m+[m[32mon,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_math_mode,[m
      sym__math_expression,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_parenthesi[m
\ No newline at end of file[m
[32m+[m[32mzed_math_expr[m
\ No newline at end of file[m
[32m+[m[32mession,[m
      sym_binary_expression,[m
\ No newline at end of file[m
[32m+[m
  [5059] = 6,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
    ACTIONS(440)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LPAREN,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(444), 1,[m
      anon_sym_DOLLAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(446), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DOLLAR_LPAREN,[m
    ACTIONS(456), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_number_[m
\ No newline at end of file[m
[32m+[m[32mliteral,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(99), 6,[m
      sym_value_path,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_command_sub[m
\ No newline at end of file[m
[32m+[m[32mstitution,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_math_mode,[m
 [m
\ No newline at end of file[m
[32m+[m[41m    [m
\ No newline at end of file[m
[32m+[m[32m s[m
\ No newline at end of file[m
[32m+[m[32my[m
\ No newline at end of file[m
[32m+[m[32mm__math_expression,[m
      sym_parenthesized_mat[m
\ No newline at end of file[m
[32m+[m[32mh_expression,[m
      sym_bi[m
\ No newline at end of file[m
[32m+[m[32mnary_expression,[m
  [5083] =[m
\ No newline at end of file[m
[32m+[m[32m 6,[m
    ACTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(9), 1,[m
      anon_sym_LPAR[m
\ No newline at end of file[m
[32m+[m[32mEN,[m
    ACTIONS(15), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_DOLLAR,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(17), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DOLLAR_LPAREN,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(458), 1,[m
      sym_numbe[m
\ No newline at end of file[m
[32m+[m[32mr_literal,[m
    STATE(79), 6,[m
\ No newline at end of file[m
[32m+[m
      sym_value_path,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_command_substitution,[m
[32m+[m[32m      sym_math_mode,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym__math_expression,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_parenthesized_math_expre[m
\ No newline at end of file[m
[32m+[m[32mssion,[m
      sym_binary_exp[m
\ No newline at end of file[m
[32m+[m[32mression,[m
  [5107] = 6,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS(440), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LPAREN,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(444), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DOLLAR,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m46), 1,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR_LPAREN,[m
    ACTIONS(460)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_number_liter[m
\ No newline at end of file[m
[32m+[m[32mal,[m
    STATE(98), 6,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_value_path,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcommand_substitution,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_math_mode,[m
      sym__[m
\ No newline at end of file[m
[32m+[m[32mmath_expression,[m
      sym_p[m
\ No newline at end of file[m
[32m+[m[32marenthesized_math_expression[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_binary_expressio[m
\ No newline at end of file[m
[32m+[m[32mn,[m
  [5131] = 4,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(466), 2,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_RPAREN,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_RBRACE,[m
    ACTIONS(462), [m
\ No newline at end of file[m
[32m+[m[32m4,[m
      anon_sym_def,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_let,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOLLAR,[m
      sym_identifi[m
\ No newline at end of file[m
[32m+[m[32mer,[m
    ACTIONS(464), 4,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LPAREN,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_number_literal,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DOLLAR_LPAREN,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LBRACE,[m
  [5151] = 6,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    ACTIONS(440),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_LPAREN,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(444), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DOLLAR,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m46), 1,[m
      anon_sym_DOLLA[m
\ No newline at end of file[m
[32m+[m[32mR_LPAREN,[m
    ACTIONS(468),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_number_litera[m
\ No newline at end of file[m
[32m+[m[32ml,[m
    STATE(97), 6,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_value_path,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmmand_substitution,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_math_mode,[m
      sym__ma[m
\ No newline at end of file[m
[32m+[m[32mth_expression,[m
      sym_pa[m
\ No newline at end of file[m
[32m+[m[32mrenthesized_math_expression[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_binary_expressi[m
\ No newline at end of file[m
[32m+[m[32mon,[m
  [5175] = 6,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(3), 1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(9), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_LPAREN,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m15), 1,[m
      anon_sym_DOLLA[m
\ No newline at end of file[m
[32m+[m[32mR,[m
    ACTIONS(17), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_DOLLAR_LPAREN,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(470), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_number_literal,[m
    STATE([m
\ No newline at end of file[m
[32m+[m[32m74), 6,[m
      sym_value_path[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_command_substitu[m
\ No newline at end of file[m
[32m+[m[32mtion,[m
      sym_math_mode,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym__math_expression,[m
[32m+[m[32m      sym_parenthesized_math[m
\ No newline at end of file[m
[32m+[m[32m_expression,[m
      sym_binar[m
\ No newline at end of file[m
[32m+[m[32my_expression,[m
  [5199] = 6,[m
[32m+[m[32m    ACTIONS(3), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    ACTIONS(440),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_LPAREN,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(444), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_DOLLAR,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m46), 1,[m
      anon_sym_DOLLA[m
\ No newline at end of file[m
[32m+[m[32mR_LPAREN,[m
    ACTIONS(472), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_number_literal,[m
\ No newline at end of file[m
[32m+[m
    STATE(103), 6,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_value_path,[m
      sym_comm[m
\ No newline at end of file[m
[32m+[m[32mand_substitution,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mmath_mode,[m
      sym__math_e[m
\ No newline at end of file[m
[32m+[m[32mxpression,[m
      sym_parenth[m
\ No newline at end of file[m
[32m+[m[32mesized_math_expression,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_binary_expression,[m
  [[m
\ No newline at end of file[m
[32m+[m[32m5223] = 6,[m
    ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(440), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LPAREN,[m
    ACTIONS(444), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DOLLAR,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(446), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DOLLAR_LPAREN,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(474), 1,[m
      sym_numbe[m
\ No newline at end of file[m
[32m+[m[32mr_literal,[m
    STATE(104), 6,[m
\ No newline at end of file[m
[32m+[m
      sym_value_path,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_command_substitution,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_math_mode,[m
      sym__[m
\ No newline at end of file[m
[32m+[m[32mmath_expression,[m
      sym_pa[m
\ No newline at end of file[m
[32m+[m[32mrenthesized_math_expression,[m
[32m+[m[32m      sym_binary_expression,[m
[32m+[m[32m  [5247] = 6,[m
    ACTIONS(3)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(440), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LPAREN,[m
    ACTIONS(444), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DOLLAR,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(446), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DOLLAR_LPAREN,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(476), 1,[m
      sym_number_li[m
\ No newline at end of file[m
[32m+[m[32mteral,[m
    STATE(96), 6,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_value_path,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32mommand_substitution,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_math_mode,[m
      sym__math_[m
\ No newline at end of file[m
[32m+[m[32mexpression,[m
      sym_parenth[m
\ No newline at end of file[m
[32m+[m[32mesized_math_expression,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_binary_expression,[m
  [52[m
\ No newline at end of file[m
[32m+[m[32m71] = 4,[m
    ACTIONS(3), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_comment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(478), 2,[m
      anon_sym_RPAR[m
\ No newline at end of file[m
[32m+[m[32mEN,[m
      anon_sym_RBRACE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(462), 4,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_def,[m
      anon_sym_let,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DOLLAR,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_identifier,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m464), 4,[m
      anon_sym_LPARE[m
\ No newline at end of file[m
[32m+[m[32mN,[m
      sym_number_literal,[m
[32m+[m[32m      anon_sym_DOLLAR_LPAREN,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LBRACE,[m
  [52[m
\ No newline at end of file[m
[32m+[m[32m91] = 6,[m
    ACTIONS(3), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_comment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(440), 1,[m
      anon_sym_LPAR[m
\ No newline at end of file[m
[32m+[m[32mEN,[m
    ACTIONS(444), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DOLLAR,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(446), 1,[m
      anon_sym_DOL[m
\ No newline at end of file[m
[32m+[m[32mLAR_LPAREN,[m
    ACTIONS(480),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_number_literal,[m
\ No newline at end of file[m
[32m+[m
    STATE(108), 6,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_value_path,[m
      sym_comman[m
\ No newline at end of file[m
[32m+[m[32md_substitution,[m
      sym_mat[m
\ No newline at end of file[m
[32m+[m[32mh_mode,[m
      sym__math_expre[m
\ No newline at end of file[m
[32m+[m[32mssion,[m
      sym_parenthesize[m
\ No newline at end of file[m
[32m+[m[32md_math_expression,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mbinary_expression,[m
  [5315] =[m
\ No newline at end of file[m
[32m+[m[32m 6,[m
    ACTIONS(3), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    ACTIONS(440)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_LPAREN,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(444), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DOLLAR,[m
    ACTIONS(446[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_DOLLAR_L[m
\ No newline at end of file[m
[32m+[m[32mPAREN,[m
    ACTIONS(482), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_number_literal,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(107), 6,[m
      sym_valu[m
\ No newline at end of file[m
[32m+[m[32me_path,[m
      sym_command_sub[m
\ No newline at end of file[m
[32m+[m[32mstitution,[m
      sym_math_mod[m
\ No newline at end of file[m
[32m+[m[32me,[m
      sym__math_expression[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_parenthesized_mat[m
\ No newline at end of file[m
[32m+[m[32mh_expression,[m
      sym_binar[m
\ No newline at end of file[m
[32m+[m[32my_expression,[m
  [5339] = 6,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(3), 1,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32momment,[m
    ACTIONS(440), 1,[m
[32m+[m[32m      anon_sym_LPAREN,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(444), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DOLLAR,[m
    ACTIONS(446), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DOLLAR_LPAREN[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(484), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_number_literal,[m
    STATE[m
\ No newline at end of file[m
[32m+[m[32m(106), 6,[m
      sym_value_pat[m
\ No newline at end of file[m
[32m+[m[32mh,[m
      sym_command_substitu[m
\ No newline at end of file[m
[32m+[m[32mtion,[m
      sym_math_mode,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym__math_expression,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_parenthesized_math_exp[m
\ No newline at end of file[m
[32m+[m[32mression,[m
      sym_binary_exp[m
\ No newline at end of file[m
[32m+[m[32mression,[m
  [5363] = 6,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(3), 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(440), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LPAREN,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(444), 1,[m
      anon_sym_DOLL[m
\ No newline at end of file[m
[32m+[m[32mAR,[m
    ACTIONS(446), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DOLLAR_LPAREN,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(486), 1,[m
      sym_n[m
\ No newline at end of file[m
[32m+[m[32mumber_literal,[m
    STATE(105)[m
\ No newline at end of file[m
[32m+[m[32m, 6,[m
      sym_value_path,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_command_substitution,[m
\ No newline at end of file[m
[32m+[m
      sym_math_mode,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym__math_expression,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_parenthesized_math_expressi[m
\ No newline at end of file[m
[32m+[m[32mon,[m
      sym_binary_expressi[m
\ No newline at end of file[m
[32m+[m[32mon,[m
  [5387] = 6,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_comment,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(440), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LPAREN,[m
    ACTIONS(444)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_DOLLAR,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(446), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DOLLAR_LPAREN,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(488), 1,[m
      sym_number[m
\ No newline at end of file[m
[32m+[m[32m_literal,[m
    STATE(102), 6,[m
[32m+[m[32m      sym_value_path,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_command_substitution,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_math_mode,[m
      sym__m[m
\ No newline at end of file[m
[32m+[m[32math_expression,[m
      sym_par[m
\ No newline at end of file[m
[32m+[m[32menthesized_math_expression,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_binary_expression,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [5411] = 6,[m
    ACTIONS(3), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(440), 1,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mLPAREN,[m
    ACTIONS(444), 1,[m
[32m+[m[32m      anon_sym_DOLLAR,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(446), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DOLLAR_LPAREN,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m90), 1,[m
      sym_number_lite[m
\ No newline at end of file[m
[32m+[m[32mral,[m
    STATE(93), 6,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_value_path,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mmand_substitution,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mmath_mode,[m
      sym__math_ex[m
\ No newline at end of file[m
[32m+[m[32mpression,[m
      sym_parenthes[m
\ No newline at end of file[m
[32m+[m[32mized_math_expression,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_binary_expression,[m
  [5435[m
\ No newline at end of file[m
[32m+[m[32m] = 6,[m
    ACTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m40), 1,[m
      anon_sym_LPAREN[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(444), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DOLLAR,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m446), 1,[m
      anon_sym_DOLLA[m
\ No newline at end of file[m
[32m+[m[32mR_LPAREN,[m
    ACTIONS(492), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_number_literal,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(100), 6,[m
      sym_v[m
\ No newline at end of file[m
[32m+[m[32malue_path,[m
      sym_command_[m
\ No newline at end of file[m
[32m+[m[32msubstitution,[m
      sym_math_[m
\ No newline at end of file[m
[32m+[m[32mmode,[m
      sym__math_express[m
\ No newline at end of file[m
[32m+[m[32mion,[m
      sym_parenthesized[m
\ No newline at end of file[m
[32m+[m[32m_math_expression,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mbinary_expression,[m
  [5459] =[m
\ No newline at end of file[m
[32m+[m[32m 4,[m
    ACTIONS(3), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    ACTIONS(466[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      ts_builtin_sym_e[m
\ No newline at end of file[m
[32m+[m[32mnd,[m
    ACTIONS(462), 4,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_def,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_let,[m
      anon_sym_DOLLA[m
\ No newline at end of file[m
[32m+[m[32mR,[m
      sym_identifier,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(464), 4,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LPAREN,[m
      sym_number[m
\ No newline at end of file[m
[32m+[m[32m_literal,[m
      anon_sym_DOL[m
\ No newline at end of file[m
[32m+[m[32mLAR_LPAREN,[m
      anon_sym_LB[m
\ No newline at end of file[m
[32m+[m[32mRACE,[m
  [5478] = 4,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(3), 1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(478), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32mts_builtin_sym_end,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(462), 4,[m
      anon_sym_[m
\ No newline at end of file[m
[32m+[m[32mdef,[m
      anon_sym_let,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_DOLLAR,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32midentifier,[m
    ACTIONS(464),[m
\ No newline at end of file[m
[32m+[m[32m 4,[m
      anon_sym_LPAREN,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_number_literal,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_DOLLAR_LPAREN,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LBRACE,[m
  [5497] =[m
\ No newline at end of file[m
[32m+[m[32m 7,[m
    ACTIONS(3), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    ACTIONS(494)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_RBRACK,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(496), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_flag_name,[m
    ACTIONS(498),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_DOT_DOT_DO[m
\ No newline at end of file[m
[32m+[m[32mTrest,[m
    ACTIONS(500), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_identifier,[m
    STAT[m
\ No newline at end of file[m
[32m+[m[32mE(140), 1,[m
      aux_sym_sign[m
\ No newline at end of file[m
[32m+[m[32mature_repeat1,[m
    STATE(171)[m
\ No newline at end of file[m
[32m+[m[32m, 3,[m
      sym_parameter,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_flag,[m
      sym_rest,[m
[32m+[m[32m  [5521] = 7,[m
    ACTIONS(3),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(496), 1,[m
      sym_flag[m
\ No newline at end of file[m
[32m+[m[32m_name,[m
    ACTIONS(498), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_DOT_DOT_DOTrest[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(500), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_identifier,[m
    ACTIONS(5[m
\ No newline at end of file[m
[32m+[m[32m02), 1,[m
      anon_sym_RBRACK[m
\ No newline at end of file[m
[32m+[m[32m,[m
    STATE(142), 1,[m
      au[m
\ No newline at end of file[m
[32m+[m[32mx_sym_signature_repeat1,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(171), 3,[m
      sym_para[m
\ No newline at end of file[m
[32m+[m[32mmeter,[m
      sym_flag,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_rest,[m
  [5545] = 3,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(3), 1,[m
      sym_comme[m
\ No newline at end of file[m
[32m+[m[32mnt,[m
    ACTIONS(462), 4,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_def,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_let,[m
      anon_sym_DOLLAR,[m
\ No newline at end of file[m
[32m+[m
      sym_identifier,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(464), 4,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LPAREN,[m
      sym_number_lit[m
\ No newline at end of file[m
[32m+[m[32meral,[m
      anon_sym_DOLLAR_[m
\ No newline at end of file[m
[32m+[m[32mLPAREN,[m
      anon_sym_LBRACE[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [5561] = 7,[m
    ACTIONS(3[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(504), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_RBRACK,[m
    ACTIONS(506), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_flag_name,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(509), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DOT_DOT_DOTrest,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(512), 1,[m
      sym_identi[m
\ No newline at end of file[m
[32m+[m[32mfier,[m
    STATE(142), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  aux_sym_signature_repeat1,[m
[32m+[m[32m    STATE(171), 3,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_parameter,[m
      sym_flag,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_rest,[m
  [5585] = 4,[m
[32m+[m[32m    ACTIONS(3), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcomment,[m
    ACTIONS(517), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_COLON,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(519), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_QMARK,[m
    ACTIONS(515), 5,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_COMMA,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_RBRACK,[m
      sym_fl[m
\ No newline at end of file[m
[32m+[m[32mag_name,[m
      anon_sym_DOT_[m
\ No newline at end of file[m
[32m+[m[32mDOT_DOTrest,[m
      sym_identi[m
\ No newline at end of file[m
[32m+[m[32mfier,[m
  [5602] = 4,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(43), 1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(521), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DOT_DOT,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(264), 2,[m
      ts_builtin_s[m
\ No newline at end of file[m
[32m+[m[32mym_end,[m
      anon_sym_LF,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(260), 4,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_RPAREN,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_PIPE,[m
      anon_sym_SEMI,[m
[32m+[m[32m      anon_sym_RBRACE,[m
  [561[m
\ No newline at end of file[m
[32m+[m[32m9] = 4,[m
    ACTIONS(3), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m525), 1,[m
      anon_sym_COLON[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(527), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_LPAREN,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(523), 5,[m
      anon_sym_COM[m
\ No newline at end of file[m
[32m+[m[32mMA,[m
      anon_sym_RBRACK,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_flag_name,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DOT_DOT_DOTrest,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_identifier,[m
  [5636] = 3[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(43), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    ACTIONS(272)[m
\ No newline at end of file[m
[32m+[m[32m, 2,[m
      ts_builtin_sym_end[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_LF,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(270), 4,[m
      anon_sym_R[m
\ No newline at end of file[m
[32m+[m[32mPAREN,[m
      anon_sym_PIPE,[m
[32m+[m[32m      anon_sym_SEMI,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_RBRACE,[m
  [5650] = 3[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(3), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIONS(531)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_QMARK,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(529), 5,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_COMMA,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_RBRACK,[m
      sym_flag_name[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_DOT_DOT_DOT[m
\ No newline at end of file[m
[32m+[m[32mrest,[m
      sym_identifier,[m
[32m+[m[32m  [5664] = 3,[m
    ACTIONS(3),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(535), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_COLON,[m
    ACTIONS(533), 5[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_COMMA,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_RBRACK,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_flag_name,[m
      anon_sym_DO[m
\ No newline at end of file[m
[32m+[m[32mT_D[m
\ No newline at end of file[m
[32m+[m[32mO[m
\ No newline at end of file[m
[32m+[m[32mT_DOTrest,[m
      sym_identifier,[m
  [5678] = 3,[m
    ACTIONS(43), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_c[m
\ No newline at end of file[m
[32m+[m[32momment,[m
    ACTIONS(306), 2,[m
      ts_b[m
\ No newline at end of file[m
[32m+[m[32muiltin_sym_end,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_LF,[m
    ACTIONS(304), 4,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_RPAREN,[m
      anon_sym_PIPE[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_SEMI,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_RBRACE,[m
  [5692] = 2,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_comment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(537), 6,[m
      anon_sym_COMMA,[m
[32m+[m[32m      anon_sym_RBRACK,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_QMARK,[m
      sym_flag_name,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_DOT_DOT_DOTrest,[m
      sym_identifie[m
\ No newline at end of file[m
[32m+[m[32mr,[m
  [5704] = 6,[m
    ACTIONS(43),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
    ACTIONS(5[m
\ No newline at end of file[m
[32m+[m[32m41), 1,[m
      anon_sym_PIPE,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(543), 1,[m
      anon_sym_SEMI[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(545), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LF,[m
    STATE(123), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m__terminator,[m
    ACTIONS(539), 2,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_RPAREN,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_RBRACE,[m
  [5724] = 3,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m43), 1,[m
      sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(268), 2,[m
      ts_builtin_s[m
\ No newline at end of file[m
[32m+[m[32mym_end,[m
      anon_sym_LF,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(266), 4,[m
      anon_sym_RPA[m
\ No newline at end of file[m
[32m+[m[32mREN,[m
      anon_sym_PIPE,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_SEMI,[m
      anon_sym_RBRACE,[m
  [57[m
\ No newline at end of file[m
[32m+[m[32m38] = 3,[m
    ACTIONS(43), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIONS(298), 2,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   ts_builtin_sym_end,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LF,[m
    ACTIONS(296), 4,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_RPAREN,[m
      anon_sym_PIPE,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_SEMI,[m
      anon_sym_RBRA[m
\ No newline at end of file[m
[32m+[m[32mCE,[m
  [5752] = 3,[m
    ACTIONS(43), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
    ACTIONS(294[m
\ No newline at end of file[m
[32m+[m[32m), 2,[m
      ts_builtin_sym_end,[m
[32m+[m[32m      anon_sym_LF,[m
    ACTIONS(292[m
\ No newline at end of file[m
[32m+[m[32m), 4,[m
      anon_sym_RPAREN,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_PIPE,[m
      anon_sym_SEM[m
\ No newline at end of file[m
[32m+[m[32mI,[m
      anon_sym_RBRACE,[m
  [5766] [m
\ No newline at end of file[m
[32m+[m[32m= 3,[m
    ACTIONS(43), 1,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS(286), 2,[m
      ts_bu[m
\ No newline at end of file[m
[32m+[m[32miltin_sym_end,[m
      anon_sym_LF,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(284), 4,[m
      anon_sym_RPAR[m
\ No newline at end of file[m
[32m+[m[32mEN,[m
      anon_sym_PIPE,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_SEMI,[m
      anon_sym_RBRACE[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [5780] = 3,[m
    ACTIONS(43), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m302), 2,[m
      ts_builtin_sym_end,[m
[32m+[m[32m      anon_sym_LF,[m
    ACTIONS(300)[m
\ No newline at end of file[m
[32m+[m[32m, 4,[m
[32m+[m[32m      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RPAREN,[m
      anon_sym_PIPE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_SEMI,[m
      anon_sym_RB[m
\ No newline at end of file[m
[32m+[m[32mRACE,[m
  [5794] = 3,[m
    ACTIONS(43)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_comment,[m
    ACTIONS(547), 2,[m
\ No newline at end of file[m
[32m+[m
      ts_builtin_sym_end,[m
      anon_sym_LF,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(549), 4,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RPAREN,[m
      anon_sym_PIPE,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_SEMI,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_RBRACE,[m
  [5808] = 3,[m
    ACTIONS(43), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_comment,[m
    ACTIONS(276)[m
\ No newline at end of file[m
[32m+[m[32m, 2,[m
      ts_builtin_sym_end,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_LF,[m
    ACTIONS(274), 4,[m
[32m+[m[32m      anon_sym_RPAREN,[m
      anon_sym_PIPE,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_SEMI,[m
      anon_sym_RBRACE,[m
  [5822][m
\ No newline at end of file[m
[32m+[m[32m = 3,[m
    ACTIONS(43), 1,[m
      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(551), 2,[m
      ts_builtin_sym_[m
\ No newline at end of file[m
[32m+[m[32mend,[m
      anon_sym_LF,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(553), 4,[m
      anon_sym_RPAREN,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PIPE,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SEMI,[m
      anon_sym_RBRACE,[m
  [5836] =[m
\ No newline at end of file[m
[32m+[m[32m 3,[m
    ACTIONS(43), 1,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mment,[m
    ACTIONS(318), 2,[m
      ts_builtin_[m
\ No newline at end of file[m
[32m+[m[32msym_end,[m
      anon_sym_LF,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(316), 4,[m
      anon_sym_RPAREN,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PIPE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_SE[m
\ No newline at end of file[m
[32m+[m[32mMI,[m
\ No newline at end of file[m
[32m+[m
[32m+[m[32m      anon_sym_RBRACE,[m
  [5850] = 3,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(43), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(555), 2,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     ts_builtin_sym_[m
\ No newline at end of file[m
[32m+[m[32mend,[m
      anon_sym_LF,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(557), 4,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RPAREN,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_PIPE,[m
[32m+[m[32m      anon_sym_SEMI,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_RBRACE,[m
\ No newline at end of file[m
[32m+[m
  [5864] = 3,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(43), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    ACTIONS(310), 2[m
\ No newline at end of file[m
[32m+[m[32m,[m
      ts_builtin_s[m
\ No newline at end of file[m
[32m+[m[32mym_end,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_LF,[m
    ACTIONS(308[m
\ No newline at end of file[m
[32m+[m[32m), 4,[m
      anon_sym_RP[m
\ No newline at end of file[m
[32m+[m[32mAREN,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_PIPE,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_SEMI,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_RBRACE,[m
  [5878] = 3,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(43), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
    ACTIONS(290[m
\ No newline at end of file[m
[32m+[m[32m), 2,[m
      ts_builtin_sym_end,[m
[32m+[m[32m      anon_sym_LF,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(288), 4,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RPAREN,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_PIPE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SEMI,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_RBR[m
\ No newline at end of file[m
[32m+[m[32mACE,[m
  [5892] = 6,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(43), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(541), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_PIPE,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(561), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_SEMI,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m563), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LF,[m
    ST[m
\ No newline at end of file[m
[32m+[m[32mATE(129), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym__terminator,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(559), 2,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RPAREN,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_RBRAC[m
\ No newline at end of file[m
[32m+[m[32mE,[m
  [5912] = 3,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m567), 1,[m
      anon_sym_CO[m
\ No newline at end of file[m
[32m+[m[32mLON,[m
    ACTIONS(565), 5[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_COMMA,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RBRACK,[m
[32m+[m[32m      sym_flag_name,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_DOT_DOT[m
\ No newline at end of file[m
[32m+[m[32m_DOTrest,[m
      sym_id[m
\ No newline at end of file[m
[32m+[m[32mentifier,[m
  [5926] = 6[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(43), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(478), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     ts_built[m
\ No newline at end of file[m
[32m+[m[32min_sym_end,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(569), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PIPE,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(571), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_SEMI,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(573), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_LF,[m
    STATE(13[m
\ No newline at end of file[m
[32m+[m[32m7), 1,[m
      sym__termi[m
\ No newline at end of file[m
[32m+[m[32mnator,[m
  [5945] = 2,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(575), 5,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_COMMA,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_RBRACK,[m
      sym_f[m
\ No newline at end of file[m
[32m+[m[32mlag_name,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DOT_DOT_DOTrest,[m
[32m+[m[32m      sym_identifier[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [5956] = 2,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(3), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_comment,[m
    ACTIONS(577),[m
\ No newline at end of file[m
[32m+[m[32m 5,[m
      anon_sym_C[m
\ No newline at end of file[m
[32m+[m[32mOMMA,[m
      anon_sym_RBRACK,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_flag_name,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_DOT_DOT_DOTrest,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_identifier,[m
  [[m
\ No newline at end of file[m
[32m+[m[32m5967] = 2,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(3), 1,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m579), 5,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_COMMA,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_RBRACK,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_flag_name,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DOT_DOT_DOTre[m
\ No newline at end of file[m
[32m+[m[32mst,[m
      sym_ide[m
\ No newline at end of file[m
[32m+[m[32mntifier,[m
  [5978] = 2,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(3), 1,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32momment,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(581), 5,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_COMMA,[m
[32m+[m[32m      anon_sym_RBRAC[m
\ No newline at end of file[m
[32m+[m[32mK,[m
      sym_flag_nam[m
\ No newline at end of file[m
[32m+[m[32me,[m
      anon_sym_DOT[m
\ No newline at end of file[m
[32m+[m[32m_DOT_DOTrest,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_identifier,[m
  [598[m
\ No newline at end of file[m
[32m+[m[32m9] = 3,[m
    ACTIONS(3)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(583), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_COMMA,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(585), 4,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_RBRACK,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mflag_name,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_DOT_DOT_DOTrest,[m
[32m+[m[32m      sym_identifier,[m
[32m+[m[32m  [6002] = 2,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(3), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(587), 5,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_COMMA,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_RBRACK,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_flag_name,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_DOT_[m
\ No newline at end of file[m
[32m+[m[32mDOT_DOTrest,[m
      sym_ide[m
\ No newline at end of file[m
[32m+[m[32mntifier,[m
  [6013] = [m
\ No newline at end of file[m
[32m+[m[32m6,[m
    ACTIONS(43), 1,[m
[32m+[m[32m      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(569), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_PIPE,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(589), 1,[m
      t[m
\ No newline at end of file[m
[32m+[m[32ms_builtin_sym_end,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(591), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SEMI,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(593), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LF,[m
    S[m
\ No newline at end of file[m
[32m+[m[32mTATE(138), 1,[m
      sym__termi[m
\ No newline at end of file[m
[32m+[m[32mnator,[m
  [6032] = 2,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(504), 4,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_RBRACK,[m
[32m+[m[32m      sym_flag_name,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DOT_DOT_DOTrest[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_identifier,[m
  [6042][m
\ No newline at end of file[m
[32m+[m[32m = 4,[m
    ACTIONS(3), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(595), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LBRACK,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(597), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_RBRACK,[m
[32m+[m[32m    STATE(181), 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_array,[m
     [m
\ No newline at end of file[m
[32m+[m[32m aux_sym_table_repeat1[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [6056] = 4,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    ACTIONS(599)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mBRACK,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(602), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_RBRACK,[m
[32m+[m[32m    STATE(176), 2,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_array,[m
     [m
\ No newline at end of file[m
[32m+[m[32m aux_sym_table_repeat[m
\ No newline at end of file[m
[32m+[m[32m1,[m
  [6070] = 4,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(595), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LBRACK,[m
    ACTIONS(604[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_RBR[m
\ No newline at end of file[m
[32m+[m[32mACK,[m
    STATE(176), 2,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_array,[m
      [m
\ No newline at end of file[m
[32m+[m[32maux_sym_table_repeat1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [6084] = 4,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(3), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m595), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_LBRACK,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(606), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RBRACK,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(177), 2,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_array,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  aux_sym_table_repe[m
\ No newline at end of file[m
[32m+[m[32mat1,[m
  [6098] = 5,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m608), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_DQUOTE,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(610), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_SQUOTE,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(612), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_identifier,[m
    STATE([m
\ No newline at end of file[m
[32m+[m[32m220), 1,[m
      sym_s[m
\ No newline at end of file[m
[32m+[m[32mtring,[m
  [6114] = 4,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(3), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcomment,[m
    ACTIONS(5[m
\ No newline at end of file[m
[32m+[m[32m95), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LBRACK,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m614), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_RBRACK,[m
    STATE(176), [m
\ No newline at end of file[m
[32m+[m[32m2,[m
      sym_array,[m
[32m+[m[32m      aux_sym_table_repeat1,[m
  [[m
\ No newline at end of file[m
[32m+[m[32m6128] = 4,[m
    ACTIONS(3), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(595), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_LBRACK,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(616), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_RBRACK,[m
\ No newline at end of file[m
[32m+[m
    STATE(176), 2,[m
\ No newline at end of file[m
[32m+[m
      sym_array,[m
     [m
\ No newline at end of file[m
[32m+[m[32m aux_sym_table_rep[m
\ No newline at end of file[m
[32m+[m[32meat1,[m
  [6142] = 5,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(43), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(238), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_COMMA,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(243), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(618), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_DOT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m STATE(182), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m aux_sym_value_path_r[m
\ No newline at end of file[m
[32m+[m[32mepeat1,[m
  [6158] = 5,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(43), 1,[m
[32m+[m[32m      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(245), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_COMMA,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(249), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_,[m
    ACTIONS(621), 1,[m
[32m+[m[32m      anon_sym_DOT,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  STATE(182), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mux_sym_value_path_r[m
\ No newline at end of file[m
[32m+[m[32mepeat1,[m
  [6174] = 5,[m
[32m+[m[32m    ACTIONS(43), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(251), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_COMMA,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(253),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(621), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_DO[m
\ No newline at end of file[m
[32m+[m[32mT,[m
    STATE(183), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     aux_sym_value_p[m
\ No newline at end of file[m
[32m+[m[32math_repeat1,[m
  [6190] = 4,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
[32m+[m[32m      sym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(595), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_LBRACK,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(623), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_RBRACK,[m
    [m
\ No newline at end of file[m
[32m+[m[32mSTATE(180), 2,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_array,[m
      aux_sym_table[m
\ No newline at end of file[m
[32m+[m[32m_repeat1,[m
  [6204] = [m
\ No newline at end of file[m
[32m+[m[32m5,[m
    ACTIONS(43), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(541), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_PIPE,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(625), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_SEMI,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(627), 1,[m
      anon_sym_LF,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(141), 1,[m
      sym__ter[m
\ No newline at end of file[m
[32m+[m[32mminator,[m
  [6220] = [m
\ No newline at end of file[m
[32m+[m[32m4,[m
    ACTIONS(3), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(595), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_LBRACK,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(629), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_RBRAC[m
\ No newline at end of file[m
[32m+[m[32mK,[m
    STATE(176),[m
\ No newline at end of file[m
[32m+[m[32m 2,[m
      sym_array,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     aux_sym_table_re[m
\ No newline at end of file[m
[32m+[m[32mpeat1,[m
  [6234] =[m
\ No newline at end of file[m
[32m+[m[32m 4,[m
    ACTIONS(3), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_comment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(595), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_LBRACK,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(631),[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_RB[m
\ No newline at end of file[m
[32m+[m[32mRACK,[m
    STATE(187), [m
\ No newline at end of file[m
[32m+[m[32m2,[m
      sym_array,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     aux_sym_table_re[m
\ No newline at end of file[m
[32m+[m[32mpeat1,[m
  [6248] = 4,[m
[32m+[m[32m    ACTIONS(43), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(633), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_DQUOTE,[m
    ACTIONS(6[m
\ No newline at end of file[m
[32m+[m[32m35), 1,[m
      sym_qouted_[m
\ No newline at end of file[m
[32m+[m[32mstring_content,[m
    ST[m
\ No newline at end of file[m
[32m+[m[32mATE(191), 1,[m
      aux_s[m
\ No newline at end of file[m
[32m+[m[32mym_string_repeat1,[m
[32m+[m[32m  [6261] = 4,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(43), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcomment,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(637), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_SQUOTE,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(639), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_single_qouted[m
\ No newline at end of file[m
[32m+[m[32m_string_content,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  STATE(193), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  aux_sym_string_repeat2,[m
[32m+[m[32m  [6274] = 4,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(43), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcomment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m641), 1,[m
      anon_sym_DQ[m
\ No newline at end of file[m
[32m+[m[32mUOTE,[m
    ACTIONS(643[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_qouted_[m
\ No newline at end of file[m
[32m+[m[32mstring_content,[m
    S[m
\ No newline at end of file[m
[32m+[m[32mTATE(191), 1,[m
      aux[m
\ No newline at end of file[m
[32m+[m[32m_sym_string_repeat1,[m
[32m+[m[32m  [6287] = 4,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(43), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcomment,[m
    ACTIONS(635), 1,[m
[32m+[m[32m      sym_qouted_stri[m
\ No newline at end of file[m
[32m+[m[32mng_content,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(646), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_DQUOTE,[m
    STATE([m
\ No newline at end of file[m
[32m+[m[32m191), 1,[m
      au[m
\ No newline at end of file[m
[32m+[m[32mx_sym_string_repeat1,[m
  [6300] [m
\ No newline at end of file[m
[32m+[m[32m= 4,[m
    ACTIONS(43),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(646), 1,[m
      anon_sym_SQUOT[m
\ No newline at end of file[m
[32m+[m[32mE,[m
    ACTIONS(648),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_single_[m
\ No newline at end of file[m
[32m+[m[32mqouted_string_content[m
\ No newline at end of file[m
[32m+[m[32m,[m
    STATE(202), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      aux_sym_str[m
\ No newline at end of file[m
[32m+[m[32ming_repeat2,[m
  [6313] =[m
\ No newline at end of file[m
[32m+[m[32m 4,[m
    ACTIONS(43[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(260), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_COMMA,[m
    ACTIONS(264), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(650), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_DOT_D[m
\ No newline at end of file[m
[32m+[m[32mOT,[m
  [6326] = 4,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
[32m+[m[32m      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(652), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_RBRACK,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(654), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_identifier,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(206), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32maux_sym_column_header_repe[m
\ No newline at end of file[m
[32m+[m[32mat1,[m
  [6339] = 4,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(43), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcomment,[m
    ACTIONS(6[m
\ No newline at end of file[m
[32m+[m[32m56), 1,[m
      anon_sym_S[m
\ No newline at end of file[m
[32m+[m[32mQUOTE,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m658), 1,[m
      sym_sin[m
\ No newline at end of file[m
[32m+[m[32mgle_qouted_string_cont[m
\ No newline at end of file[m
[32m+[m[32ment,[m
    STATE(200)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      aux_sym_str[m
\ No newline at end of file[m
[32m+[m[32ming_repeat2,[m
  [6352] [m
\ No newline at end of file[m
[32m+[m[32m= 4,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(43), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_comment,[m
    ACTIONS(6[m
\ No newline at end of file[m
[32m+[m[32m48), 1,[m
      sym_si[m
\ No newline at end of file[m
[32m+[m[32mngle_qouted_string_content[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(660), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_SQUOT[m
\ No newline at end of file[m
[32m+[m[32mE,[m
    STATE(202), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      aux_sym_string_[m
\ No newline at end of file[m
[32m+[m[32mrepeat2,[m
  [6365] = [m
\ No newline at end of file[m
[32m+[m[32m4,[m
    ACTIONS(43), 1,[m
[32m+[m[32m      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(633), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_SQUOTE,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(648), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_single_qouted_stri[m
\ No newline at end of file[m
[32m+[m[32mng_content,[m
    STATE(2[m
\ No newline at end of file[m
[32m+[m[32m02), 1,[m
      aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_string_repeat2,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [6378] = 4,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(43), 1,[m
      sym_comme[m
\ No newline at end of file[m
[32m+[m[32mnt,[m
    ACTIONS(662)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_DQUOTE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(664), 1,[m
      sym_qoute[m
\ No newline at end of file[m
[32m+[m[32md_string_content,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  STATE(214), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  aux_sym_string_repe[m
\ No newline at end of file[m
[32m+[m[32mat1,[m
  [6391] = 4,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(43), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(648), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_single_qouted[m
\ No newline at end of file[m
[32m+[m[32m_string_content,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(666), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SQUOTE,[m
\ No newline at end of file[m
[32m+[m
    STATE(202), 1,[m
      aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_string_repeat2,[m
  [[m
\ No newline at end of file[m
[32m+[m[32m6404] = 4,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(43), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(635), 1,[m
[32m+[m[32m      sym_qouted_stri[m
\ No newline at end of file[m
[32m+[m[32mng_content,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(666), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DQUOTE,[m
    STA[m
\ No newline at end of file[m
[32m+[m[32mTE(191), 1,[m
      aux_[m
\ No newline at end of file[m
[32m+[m[32msym_string_repeat1,[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m417] = 4,[m
    ACTIONS(43),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(668), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SQUOTE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(670), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_single_qouted_st[m
\ No newline at end of file[m
[32m+[m[32mring_content,[m
    STAT[m
\ No newline at end of file[m
[32m+[m[32mE(202), 1,[m
      aux_s[m
\ No newline at end of file[m
[32m+[m[32mym_string_repeat2,[m
[32m+[m[32m  [6430] = 3,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(43), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mcomment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(243), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(238), 2,[m
      [m
\ No newline at end of file[m
[32m+[m[32manon_sym_COMMA,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_DOT,[m
  [6441][m
\ No newline at end of file[m
[32m+[m[32m = 4,[m
    ACTIONS(43), 1,[m
[32m+[m[32m      sym_comment,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(662), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_SQUOTE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(673), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_single_qouted_s[m
\ No newline at end of file[m
[32m+[m[32mtring_content,[m
    STAT[m
\ No newline at end of file[m
[32m+[m[32mE(197), 1,[m
      aux_[m
\ No newline at end of file[m
[32m+[m[32msym_string_repeat2,[m
  [6454] =[m
\ No newline at end of file[m
[32m+[m[32m 4,[m
    ACTIONS(43), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(637), 1,[m
[32m+[m[32m      anon_sym_DQUOTE,[m
[32m+[m[32m    ACTIONS(675),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_qouted_string_con[m
\ No newline at end of file[m
[32m+[m[32mtent,[m
    STATE(192),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      aux_sym_string_repeat1[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [6467] = 4,[m
    ACTIONS(3), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(677), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_RBRA[m
\ No newline at end of file[m
[32m+[m[32mCK,[m
    ACTIONS(679), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_identif[m
\ No newline at end of file[m
[32m+[m[32mier,[m
    STATE(206)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      aux_sym_colu[m
\ No newline at end of file[m
[32m+[m[32mmn_header_repeat1,[m
\ No newline at end of file[m
[32m+[m
  [6480] = 4,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(43), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(682), 1,[m
      anon_sym_SQ[m
\ No newline at end of file[m
[32m+[m[32mUOTE,[m
    ACTIONS(684[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_s[m
\ No newline at end of file[m
[32m+[m[32mingle_qouted_stri[m
\ No newline at end of file[m
[32m+[m[32mng_content,[m
    S[m
\ No newline at end of file[m
[32m+[m[32mTATE(198), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32maux_sym_string_repeat2[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [6493] = 4,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(43), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(682), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DQUOTE,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(686), 1,[m
      sym_qoute[m
\ No newline at end of file[m
[32m+[m[32md_string_content,[m
    ST[m
\ No newline at end of file[m
[32m+[m[32mATE(189), 1,[m
      aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_string_repeat1,[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m506] = 4,[m
    ACTIONS(43[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mment,[m
    ACTIONS(688)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_DQ[m
\ No newline at end of file[m
[32m+[m[32mUOTE,[m
    ACTIONS(6[m
\ No newline at end of file[m
[32m+[m[32m90), 1,[m
      sym_qout[m
\ No newline at end of file[m
[32m+[m[32med_string_content,[m
   [m
\ No newline at end of file[m
[32m+[m[32m STATE(211), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      aux_sym_stri[m
\ No newline at end of file[m
[32m+[m[32mng_repeat1,[m
  [6519[m
\ No newline at end of file[m
[32m+[m[32m] = 4,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(688),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_SQUOTE,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(692), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_single_qout[m
\ No newline at end of file[m
[32m+[m[32med_string_content,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   STATE(212), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m aux_sym_string_repe[m
\ No newline at end of file[m
[32m+[m[32mat2,[m
  [6532] = 4,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(43), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_comment,[m
    ACTIONS(635[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_qout[m
\ No newline at end of file[m
[32m+[m[32med_string_content,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(694), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_DQUOTE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  STATE(191), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  aux_sym_string_repeat1,[m
[32m+[m[32m  [6545] = 4,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(43), 1,[m
      sym_comm[m
\ No newline at end of file[m
[32m+[m[32ment,[m
    ACTIONS(648[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_single_qouted_st[m
\ No newline at end of file[m
[32m+[m[32mring_content,[m
    ACTIONS(694), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_SQ[m
\ No newline at end of file[m
[32m+[m[32mUOTE,[m
    STATE(202),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      aux_sym_str[m
\ No newline at end of file[m
[32m+[m[32ming_repeat2,[m
  [655[m
\ No newline at end of file[m
[32m+[m[32m8] = 4,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(43), 1,[m
      sym_comm[m
\ No newline at end of file[m
[32m+[m[32ment,[m
    ACTIONS(3[m
\ No newline at end of file[m
[32m+[m[32m00), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_COMMA,[m
    ACTIONS(3[m
\ No newline at end of file[m
[32m+[m[32m02), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_,[m
    ACTIONS(696), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_SEMI,[m
  [[m
\ No newline at end of file[m
[32m+[m[32m6571] = 4,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(43), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(635), 1,[m
[32m+[m[32m      sym_qouted_stri[m
\ No newline at end of file[m
[32m+[m[32mng_content,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(660), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_DQUOTE,[m
    STA[m
\ No newline at end of file[m
[32m+[m[32mTE(191), 1,[m
      aux_[m
\ No newline at end of file[m
[32m+[m[32msym_string_repeat1,[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m584] = 4,[m
    ACTIONS(43),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(656), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_DQUOTE,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(698), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_qouted_string_co[m
\ No newline at end of file[m
[32m+[m[32mntent,[m
    STATE(201),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      aux_sym_stri[m
\ No newline at end of file[m
[32m+[m[32mng_repeat1,[m
  [6597[m
\ No newline at end of file[m
[32m+[m[32m] = 2,[m
    ACTIONS(3),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3[m
\ No newline at end of file[m
[32m+[m[32m18), 2,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_LBRACK,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_RBRACK,[m
  [660[m
\ No newline at end of file[m
[32m+[m[32m5] = 3,[m
    ACTIONS(43)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(300), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_COMMA[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(302), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_,[m
  [6615[m
\ No newline at end of file[m
[32m+[m[32m] = 2,[m
    ACTIONS(3), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(677), 2,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_RBRACK,[m
\ No newline at end of file[m
[32m+[m
      sym_identifier,[m
[32m+[m[32m  [6623] = 3,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(43), 1,[m
      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(700), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_COMMA[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(702), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_,[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m633] = 3,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(3), 1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(704), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_LBRACK,[m
    STATE(2[m
\ No newline at end of file[m
[32m+[m[32m25), 1,[m
      sym_s[m
\ No newline at end of file[m
[32m+[m[32mignature,[m
  [6643] = 3,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(43), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
    ACTIONS(288[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym_COMMA,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(290), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_,[m
  [6653] [m
\ No newline at end of file[m
[32m+[m[32m= 3,[m
    ACTIONS(4[m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_comme[m
\ No newline at end of file[m
[32m+[m[32mnt,[m
    ACTIONS(308),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_COMMA,[m
    ACTIONS(310), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_,[m
  [666[m
\ No newline at end of file[m
[32m+[m[32m3] = 3,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(43), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(264), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(706), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_COMMA,[m
  [6673[m
\ No newline at end of file[m
[32m+[m[32m] = 3,[m
    ACTIONS(43[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(316), 1,[m
[32m+[m[32m      anon_sym_COMMA,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(318), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_,[m
  [6683] = 3,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(3), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_comment,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(21), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_LBRACE,[m
    STA[m
\ No newline at end of file[m
[32m+[m[32mTE(157), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32mblock,[m
  [6693] = 3[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(43), 1,[m
[32m+[m[32m      sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(274),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_C[m
\ No newline at end of file[m
[32m+[m[32mOMMA,[m
    ACTIONS(2[m
\ No newline at end of file[m
[32m+[m[32m76), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_,[m
  [6703] = 3,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(43), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    ACTIONS(2[m
\ No newline at end of file[m
[32m+[m[32m70), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_COMMA,[m
    ACTIONS(27[m
\ No newline at end of file[m
[32m+[m[32m2), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_,[m
  [6713] = 3,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(43), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(284), 1,[m
      anon_[m
\ No newline at end of file[m
[32m+[m[32msym_COMMA,[m
    ACTIONS(286), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      anon_sym_,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[6723] = 3,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(43), 1,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32momment,[m
    ACTIONS(292[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_s[m
\ No newline at end of file[m
[32m+[m[32mym_COMMA,[m
    ACTIONS(294), 1,[m
[32m+[m[32m      anon_sym_,[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m733] = 3,[m
    ACTIONS(43), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
    ACTIONS(296[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_COMMA,[m
    ACTIONS(2[m
\ No newline at end of file[m
[32m+[m[32m98), 1,[m
      anon_sy[m
\ No newline at end of file[m
[32m+[m[32mm_,[m
  [6743] = 3,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(43), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(280), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_COMMA,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(282), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[6753] = 2,[m
    ACTIONS(3), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(302), 2,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mBRACK,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RBRACK,[m
  [6761[m
\ No newline at end of file[m
[32m+[m[32m] = 3,[m
    ACTIONS(43)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(266), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_COM[m
\ No newline at end of file[m
[32m+[m[32mMA,[m
    ACTIONS(268), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_,[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m771] = 3,[m
    ACTIONS(43),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(312), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_COMMA,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(314), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_,[m
  [6781] =[m
\ No newline at end of file[m
[32m+[m[32m 3,[m
    ACTIONS(43), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(304), 1,[m
\ No newline at end of file[m
[32m+[m
      anon_sym_COMMA,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(306), 1,[m
[32m+[m[32m      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_,[m
  [6791] = 2,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(709), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_RBRACE,[m
  [67[m
\ No newline at end of file[m
[32m+[m[32m98] = 2,[m
    ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
[32m+[m[32m    ACTIONS(711), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_identifier,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [6805] = 2,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(3), 1,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS(268)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_L[m
\ No newline at end of file[m
[32m+[m[32mBRACK,[m
  [6812] = 2,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(3), 1,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32momment,[m
    ACTIONS(71[m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_numb[m
\ No newline at end of file[m
[32m+[m[32mer_literal,[m
  [6819] = [m
\ No newline at end of file[m
[32m+[m[32m2,[m
    ACTIONS(3),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_comment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(715), 1,[m
      sy[m
\ No newline at end of file[m
[32m+[m[32mm_identifier,[m
  [6826] = 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(298), [m
\ No newline at end of file[m
[32m+[m[32m1,[m
      anon_sym_LBR[m
\ No newline at end of file[m
[32m+[m[32mACK,[m
  [6833] = 2,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(3), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(717), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_identifier,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [6840] = 2,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(3), 1,[m
      sym_c[m
\ No newline at end of file[m
[32m+[m[32momment,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(719), 1,[m
      anon_sym_RPARE[m
\ No newline at end of file[m
[32m+[m[32mN,[m
  [6847] = 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    sym_comment,[m
[32m+[m[32m    ACTIONS(721),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_R[m
\ No newline at end of file[m
[32m+[m[32mBRACE,[m
  [6854] = 2,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(723), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_number_literal,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [6861] = 2,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(725), 1,[m
  [m
\ No newline at end of file[m
[32m+[m[32m    anon_sym_LBRACE,[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m868] = 2,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m3), 1,[m
      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(727),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      anon_sym_RPA[m
\ No newline at end of file[m
[32m+[m[32mREN,[m
  [6875] = 2,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(729), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_identifier,[m
\ No newline at end of file[m
[32m+[m
  [6882] = 2,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(3), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_comment,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(731), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_RPAREN,[m
  [6889[m
\ No newline at end of file[m
[32m+[m[32m] = 2,[m
    ACTIONS(3), 1,[m
[32m+[m[32m      sym_comment,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(733), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  anon_sym_RBRACE,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[6896] = 2,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mment,[m
    ACTIONS(735),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      sym_number_[m
\ No newline at end of file[m
[32m+[m[32mliteral,[m
  [6903] = 2,[m
    ACT[m
\ No newline at end of file[m
[32m+[m[32mIONS(3), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m737), 1,[m
      sym_id[m
\ No newline at end of file[m
[32m+[m[32mentifier,[m
  [6910] = 2,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_comment,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(739), 1,[m
      anon[m
\ No newline at end of file[m
[32m+[m[32m_sym_RBRACE,[m
  [6917] = 2,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(3), 1,[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(741), 1[m
\ No newline at end of file[m
[32m+[m[32m,[m
      sym_identifie[m
\ No newline at end of file[m
[32m+[m[32mr,[m
  [6924] = 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(743), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_identifier,[m
  [[m
\ No newline at end of file[m
[32m+[m[32m6931] = 2,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_com[m
\ No newline at end of file[m
[32m+[m[32mment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(745), 1,[m
      anon_sym_SEMI,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [6938] = 2,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(3), 1,[m
      [m
\ No newline at end of file[m
[32m+[m[32msym_comment,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(747), 1,[m
[32m+[m[32m      anon_sym_RPARE[m
\ No newline at end of file[m
[32m+[m[32mN,[m
  [6945] = 2,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(3), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIO[m
\ No newline at end of file[m
[32m+[m[32mNS(749), 1,[m
      ano[m
\ No newline at end of file[m
[32m+[m[32mn_sym_RPAREN,[m
  [6952][m
\ No newline at end of file[m
[32m+[m[32m = 2,[m
    ACTIONS(3), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(751), 1,[m
      sym[m
\ No newline at end of file[m
[32m+[m[32m_flag_shorthand_name,[m
  [[m
\ No newline at end of file[m
[32m+[m[32m6959] = 2,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(3), 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(753)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_identif[m
\ No newline at end of file[m
[32m+[m[32mier,[m
  [6966] = 2,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(755), 1,[m
      a[m
\ No newline at end of file[m
[32m+[m[32mnon_sym_LBRACE[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [6973] = 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_comment,[m
    AC[m
\ No newline at end of file[m
[32m+[m[32mTIONS(757), 1,[m
      an[m
\ No newline at end of file[m
[32m+[m[32mon_sym_RPAREN,[m
  [698[m
\ No newline at end of file[m
[32m+[m[32m0] = 2,[m
    ACTIONS(3), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   ACTIONS(759), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   anon_sym_EQ,[m
  [69[m
\ No newline at end of file[m
[32m+[m[32m87] = 2,[m
    ACTIONS(3)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_commen[m
\ No newline at end of file[m
[32m+[m[32mt,[m
    ACTIONS(761), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_number_lit[m
\ No newline at end of file[m
[32m+[m[32meral,[m
  [6994] = 2,[m
    ACTION[m
\ No newline at end of file[m
[32m+[m[32mS(3), 1,[m
      sym_co[m
\ No newline at end of file[m
[32m+[m[32mmment,[m
    ACTIONS(763)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      sym_identi[m
\ No newline at end of file[m
[32m+[m[32mfier,[m
  [7001] = 2,[m
   [m
\ No newline at end of file[m
[32m+[m[32m ACTIONS(3), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m sym_comment,[m
    ACTI[m
\ No newline at end of file[m
[32m+[m[32mONS(765), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SEMI,[m
  [7008] = 2,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(767), 1,[m
     [m
\ No newline at end of file[m
[32m+[m[32m anon_sym_SEMI,[m
  [7015] = 2,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  ACTIONS(3), 1,[m
      sym_comme[m
\ No newline at end of file[m
[32m+[m[32mnt,[m
    ACTIONS(769)[m
\ No newline at end of file[m
[32m+[m[32m, 1,[m
      anon_sym_COM[m
\ No newline at end of file[m
[32m+[m[32mMA,[m
  [7022] = 2,[m
[32m+[m[32m    ACTIONS(3), 1,[m
   [m
\ No newline at end of file[m
[32m+[m[32m   sym_comment,[m
    A[m
\ No newline at end of file[m
[32m+[m[32mCTIONS(771), 1,[m
 [m
\ No newline at end of file[m
[32m+[m[32m     anon_sym_SEMI,[m
  [7029] = 2[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(3), 1,[m
[32m+[m[32m      sym_comment[m
\ No newline at end of file[m
[32m+[m[32m,[m
    ACTIONS(773[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      ts_bu[m
\ No newline at end of file[m
[32m+[m[32miltin_sym_end,[m
  [70[m
\ No newline at end of file[m
[32m+[m[32m36] = 2,[m
    ACTIONS(3[m
\ No newline at end of file[m
[32m+[m[32m), 1,[m
      sym_comme[m
\ No newline at end of file[m
[32m+[m[32mnt,[m
    ACTIONS(775),[m
\ No newline at end of file[m
[32m+[m[32m 1,[m
      ts_builtin_[m
\ No newline at end of file[m
[32m+[m[32msym_end,[m
  [7043] = 2,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(3), 1,[m
    [m
\ No newline at end of file[m
[32m+[m[32m  sym_comment,[m
    ACTIONS[m
\ No newline at end of file[m
[32m+[m[32m(777), 1,[m
      anon_sym[m
\ No newline at end of file[m
[32m+[m[32m_SEMI,[m
  [7050] = 2,[m
    [m
\ No newline at end of file[m
[32m+[m[32mACTIONS(3), 1,[m
      s[m
\ No newline at end of file[m
[32m+[m[32mym_comment,[m
    ACTIONS([m
\ No newline at end of file[m
[32m+[m[32m779), 1,[m
      sym_[m
\ No newline at end of file[m
[32m+[m[32midentifier,[m
  [7057] =[m
\ No newline at end of file[m
[32m+[m[32m 2,[m
    ACTIONS(3), 1,[m
\ No newline at end of file[m
[32m+[m
      sym_comment,[m
\ No newline at end of file[m
[32m+[m
    ACTIONS(781), 1,[m
[32m+[m[32m      sym_identifier,[m
[32m+[m[32m};[m

static uint[m
\ No newline at end of file[m
[32m+[m[32m32_t ts_small_parse_[m
\ No newline at end of file[m
[32m+[m[32mtable_map[] = {[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(2)] = 0,[m
[32m+[m[32m  [SMALL_STATE(3)] = 75[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(4)] [m
\ No newline at end of file[m
[32m+[m[32m= 150,[m
  [SMALL_STATE(5)] [m
\ No newline at end of file[m
[32m+[m[32m= 225,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(6)] = 299,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(7)] = 373,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(8)] = 447,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(9)] = 524[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(10)] =[m
\ No newline at end of file[m
[32m+[m[32m 598,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m11)] = 672,[m
  [SMALL_STATE(12)[m
\ No newline at end of file[m
[32m+[m[32m] = 746,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(13)] = 820,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(14)] = 891,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(15)] = 96[m
\ No newline at end of file[m
[32m+[m[32m2,[m
  [SMALL_STATE(16)[m
\ No newline at end of file[m
[32m+[m[32m] = 1033,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(17)] = 1104,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(18)] = 1175,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(19)] = 1[m
\ No newline at end of file[m
[32m+[m[32m246,[m
  [SMALL_STATE(20)] [m
\ No newline at end of file[m
[32m+[m[32m= 1317,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(21)] = 1382,[m
  [SMALL_STATE(22[m
\ No newline at end of file[m
[32m+[m[32m)] = 1427,[m
  [SMALL_STATE(23)] =[m
\ No newline at end of file[m
[32m+[m[32m 1472,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(24)] = 1517,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(25)] = 1557[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(26)] [m
\ No newline at end of file[m
[32m+[m[32m= 1601,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(27)] = 1645,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(28)] = 1689,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(29)] = 1731,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(3[m
\ No newline at end of file[m
[32m+[m[32m0)] = 1770,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(31)] =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1809,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(32)] = 1848,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(33)] = 1889,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(34)] =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1928,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m35)] = 1967,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(36)] = 2006,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(37)] = 2045,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(38)] = 2084,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(39)] = 21[m
\ No newline at end of file[m
[32m+[m[32m23,[m
  [SMALL_STATE(40)[m
\ No newline at end of file[m
[32m+[m[32m] = 2162,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(41)] = 2201,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(42)] = 2240,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(43)] =[m
\ No newline at end of file[m
[32m+[m[32m 2279,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(44)] = 2318,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(45)] = 2357,[m
[32m+[m[32m  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m46)] = 2395,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(47)] = 2433[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(48)][m
\ No newline at end of file[m
[32m+[m[32m = 2471,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(49)] = 2509,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(50)] = 2547,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(51)] = 2585[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(52)] =[m
\ No newline at end of file[m
[32m+[m[32m 2623,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(53)] = 2661,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(54)] = 2699,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(55)] = 273[m
\ No newline at end of file[m
[32m+[m[32m7,[m
  [SMALL_STATE(56)[m
\ No newline at end of file[m
[32m+[m[32m] = 2775,[m
  [SMALL_STATE(57)] [m
\ No newline at end of file[m
[32m+[m[32m= 2813,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(58)] = 2851,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(59)] = 2889,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(60)] = 2[m
\ No newline at end of file[m
[32m+[m[32m924,[m
  [SMALL_STATE(6[m
\ No newline at end of file[m
[32m+[m[32m1)] = 2960,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(62)] = 2996,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(63)] = 3032,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(64)] =[m
\ No newline at end of file[m
[32m+[m[32m 3085,[m
  [SMALL_STATE(65)[m
\ No newline at end of file[m
[32m+[m[32m] = 3138,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(66)] = 3191,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m67)] = 3222,[m
  [SMALL_STATE(68)][m
\ No newline at end of file[m
[32m+[m[32m = 3275,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(69)] = 3328,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(70)] = 33[m
\ No newline at end of file[m
[32m+[m[32m81,[m
  [SMALL_STATE(71)[m
\ No newline at end of file[m
[32m+[m[32m] = 3434,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(72)] = 3487,[m
[32m+[m[32m  [SMALL_STATE(73)] = 3540,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(74)] = 357[m
\ No newline at end of file[m
[32m+[m[32m0,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(75)] = 3608,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(76)][m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 3650,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(77)] = 3680,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(78)] = 3710,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(79)] [m
\ No newline at end of file[m
[32m+[m[32m= 3754,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(80)] = 3788,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(81)] = 3824,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(82)] = 3854,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(83)] = 389[m
\ No newline at end of file[m
[32m+[m[32m4,[m
  [SMALL_STATE(84)] = [m
\ No newline at end of file[m
[32m+[m[32m3926,[m
  [SMALL_STATE(8[m
\ No newline at end of file[m
[32m+[m[32m5)] = 3973,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(86)] = 4020,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(87)] = 406[m
\ No newline at end of file[m
[32m+[m[32m7,[m
  [SMALL_STATE(88)][m
\ No newline at end of file[m
[32m+[m[32m = 4111,[m
  [SMALL_S[m
\ No newline at end of file[m
[32m+[m[32mTATE(89)] = 4155,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(90)] = 4186[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(91)] = 4217,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(92)] = 42[m
\ No newline at end of file[m
[32m+[m[32m48,[m
  [SMALL_STATE(93[m
\ No newline at end of file[m
[32m+[m[32m)] = 4274,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(94)] = 4305,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(95)] = 4330,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(96)] = 43[m
\ No newline at end of file[m
[32m+[m[32m55,[m
  [SMALL_STATE(97)][m
\ No newline at end of file[m
[32m+[m[32m = 4394,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(98)] = 4433,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(99)] = 4472,[m
[32m+[m[32m  [SMALL_STATE(100)] =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m4511,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m101)] = 4540,[m
  [SMALL_STATE(1[m
\ No newline at end of file[m
[32m+[m[32m02)] = 4579,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(103)] = 4612,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(104)] =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m4651,[m
  [SMALL_STATE(1[m
\ No newline at end of file[m
[32m+[m[32m05)] = 4690,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(106)] = 4725,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(107)][m
\ No newline at end of file[m
[32m+[m[32m = 4762,[m
  [SMALL_STATE(108)][m
\ No newline at end of file[m
[32m+[m[32m = 4787,[m
  [SMALL_S[m
\ No newline at end of file[m
[32m+[m[32mTATE(109)] = 4814,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(110)] = 4839[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(111)] = 4858,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(112)] = 4877,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(113)] = 4[m
\ No newline at end of file[m
[32m+[m[32m896,[m
  [SMALL_STATE(114[m
\ No newline at end of file[m
[32m+[m[32m)] = 4915,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(115)] = 4939,[m
[32m+[m[32m  [SMALL_STATE(116)][m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 4963,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(117)] = 4987,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(118)] = 5011,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(119)][m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 5035,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(120)] = 505[m
\ No newline at end of file[m
[32m+[m[32m9,[m
  [SMALL_STATE(12[m
\ No newline at end of file[m
[32m+[m[32m1)] = 5083,[m
  [SMALL_S[m
\ No newline at end of file[m
[32m+[m[32mTATE(122)] = 5107,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(123)] =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m5131,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m124)] = 5151,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(125)] = 5175,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(126)] = 5199,[m
[32m+[m[32m  [SMALL_STATE(127)] = 5[m
\ No newline at end of file[m
[32m+[m[32m223,[m
  [SMALL_STATE(128)][m
\ No newline at end of file[m
[32m+[m[32m = 5247,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(129)] = 5271,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(130)] = 5291[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(131)][m
\ No newline at end of file[m
[32m+[m[32m = 5315,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(132)] = 5339,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(133)] = 53[m
\ No newline at end of file[m
[32m+[m[32m63,[m
  [SMALL_STATE(134[m
\ No newline at end of file[m
[32m+[m[32m)] = 5387,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(135)] = 5[m
\ No newline at end of file[m
[32m+[m[32m411,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(136)] = 5435,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(137)] = 5459,[m
[32m+[m[32m  [SMALL_STATE(138)][m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 5478,[m
  [SMALL_STATE(139[m
\ No newline at end of file[m
[32m+[m[32m)] = 5497,[m
  [SMALL_S[m
\ No newline at end of file[m
[32m+[m[32mTATE(140)] = 5521,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(141)] = 55[m
\ No newline at end of file[m
[32m+[m[32m45,[m
  [SMALL_STATE(142)[m
\ No newline at end of file[m
[32m+[m[32m] = 5561,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(143)] = 5585,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(144)] = 560[m
\ No newline at end of file[m
[32m+[m[32m2,[m
  [SMALL_STATE(145)] = 5619[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(146)[m
\ No newline at end of file[m
[32m+[m[32m] = 5636,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(147)] = 5650,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(148)] = 5664[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(149)[m
\ No newline at end of file[m
[32m+[m[32m] = 5678,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(150)] = 5692,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(151)] = 5704,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(152)][m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 5724,[m
  [SMALL_STATE(15[m
\ No newline at end of file[m
[32m+[m[32m3)] = 5738,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(154)] = 5752,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(155)] = 5766,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m156)] = 5780,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(157)] = 5794,[m
[32m+[m[32m  [SMALL_STATE(158[m
\ No newline at end of file[m
[32m+[m[32m)] = 5808,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(159)] = 5822,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(160)][m
\ No newline at end of file[m
[32m+[m[32m = 5836,[m
  [SMALL_STATE(161)] = [m
\ No newline at end of file[m
[32m+[m[32m5850,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m162)] = 5864,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(163)][m
\ No newline at end of file[m
[32m+[m[32m = 5878,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(164)] = 5892,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(165)] [m
\ No newline at end of file[m
[32m+[m[32m= 5912,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(166)] = 5926,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(167)] = 594[m
\ No newline at end of file[m
[32m+[m[32m5,[m
  [SMALL_STATE(168)[m
\ No newline at end of file[m
[32m+[m[32m] = 5956,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(169)] = 5967,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(170)] = 5978,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(171)] = 5989,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(172)] = 6[m
\ No newline at end of file[m
[32m+[m[32m002,[m
  [SMALL_STATE(173)[m
\ No newline at end of file[m
[32m+[m[32m] = 6013,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(174)] = 6032,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(175)] = 6[m
\ No newline at end of file[m
[32m+[m[32m042,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(176)] = 6056,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(177)] = 6070,[m
[32m+[m[32m  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m178)] = 6084,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(179)] = 60[m
\ No newline at end of file[m
[32m+[m[32m98,[m
  [SMALL_STATE(18[m
\ No newline at end of file[m
[32m+[m[32m0)] = 6114,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(181)] = 6128,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(182)] = 6142,[m
[32m+[m[32m  [SMALL_STATE(183)][m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 6158,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m184)] = 6174,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(185)] = 6190,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(186)] =[m
\ No newline at end of file[m
[32m+[m[32m 6204,[m
  [SMALL_STATE(1[m
\ No newline at end of file[m
[32m+[m[32m87)] = 6220,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(188)] = 6234,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(189)] = 6248,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(190)] = 6[m
\ No newline at end of file[m
[32m+[m[32m261,[m
  [SMALL_STATE(1[m
\ No newline at end of file[m
[32m+[m[32m91)] = 6274,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(192)] = 6287,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(193)] = 6[m
\ No newline at end of file[m
[32m+[m[32m300,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(194)] = 6313,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(195)] = 6326,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(196)] = 6339,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(197)][m
\ No newline at end of file[m
[32m+[m[32m = 6352,[m
  [SMALL_STATE(198)] = [m
\ No newline at end of file[m
[32m+[m[32m6365,[m
  [SMALL_STATE(199)] = 637[m
\ No newline at end of file[m
[32m+[m[32m8,[m
  [SMALL_STATE(20[m
\ No newline at end of file[m
[32m+[m[32m0)] = 6391,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(201)] = 6404,[m
[32m+[m[32m  [SMALL_STATE(202)] =[m
\ No newline at end of file[m
[32m+[m[32m 6417,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(203)] = 6430,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(204)] = 6441,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(205)] = 645[m
\ No newline at end of file[m
[32m+[m[32m4,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(206)] = 6467,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(207)[m
\ No newline at end of file[m
[32m+[m[32m] = 6480,[m
  [SMALL_S[m
\ No newline at end of file[m
[32m+[m[32mTATE(208)] = 6493,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(209)] = 6[m
\ No newline at end of file[m
[32m+[m[32m506,[m
  [SMALL_STATE(2[m
\ No newline at end of file[m
[32m+[m[32m10)] = 6519,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(211)] = 6532,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(212)] = 65[m
\ No newline at end of file[m
[32m+[m[32m45,[m
  [SMALL_STATE(213)] =[m
\ No newline at end of file[m
[32m+[m[32m 6558,[m
  [SMALL_STATE(21[m
\ No newline at end of file[m
[32m+[m[32m4)] = 6571,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(215)] = 6584,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(216)] = 6597,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(217)][m
\ No newline at end of file[m
[32m+[m[32m = 6605,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(218)] = 6615,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(219)] = 66[m
\ No newline at end of file[m
[32m+[m[32m23,[m
  [SMALL_STATE(220[m
\ No newline at end of file[m
[32m+[m[32m)] = 6633,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(221)] = 664[m
\ No newline at end of file[m
[32m+[m[32m3,[m
  [SMALL_STATE(22[m
\ No newline at end of file[m
[32m+[m[32m2)] = 6653,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(223)] = 6663,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(224)] = 66[m
\ No newline at end of file[m
[32m+[m[32m73,[m
  [SMALL_STATE(22[m
\ No newline at end of file[m
[32m+[m[32m5)] = 6683,[m
  [SMALL_ST[m
\ No newline at end of file[m
[32m+[m[32mATE(226)] = 6693,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(227)] = 670[m
\ No newline at end of file[m
[32m+[m[32m3,[m
  [SMALL_STATE(228[m
\ No newline at end of file[m
[32m+[m[32m)] = 6713,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(229)] = 6723,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(230)] = 6733,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(231)] = 674[m
\ No newline at end of file[m
[32m+[m[32m3,[m
  [SMALL_STATE(232)][m
\ No newline at end of file[m
[32m+[m[32m = 6753,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(233)] = 6761,[m
  [SM[m
\ No newline at end of file[m
[32m+[m[32mALL_STATE(234)] = 677[m
\ No newline at end of file[m
[32m+[m[32m1,[m
  [SMALL_STATE(235)][m
\ No newline at end of file[m
[32m+[m[32m = 6781,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(236)] = 6791,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(237)] = 6[m
\ No newline at end of file[m
[32m+[m[32m798,[m
  [SMALL_STATE(238)] = 6[m
\ No newline at end of file[m
[32m+[m[32m805,[m
  [SMALL_STATE(2[m
\ No newline at end of file[m
[32m+[m[32m39)] = 6812,[m
  [SMALL_STATE(240)[m
\ No newline at end of file[m
[32m+[m[32m] = 6819,[m
  [SMALL_STATE(241)] =[m
\ No newline at end of file[m
[32m+[m[32m 6826,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(242)] = 6833,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(243)] = 68[m
\ No newline at end of file[m
[32m+[m[32m40,[m
  [SMALL_STATE(244[m
\ No newline at end of file[m
[32m+[m[32m)] = 6847,[m
  [SMALL_S[m
\ No newline at end of file[m
[32m+[m[32mTATE(245)] = 6854[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE(246)] = 6861,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(247)] =[m
\ No newline at end of file[m
[32m+[m[32m 6868,[m
  [SMALL_S[m
\ No newline at end of file[m
[32m+[m[32mTATE(248)] = 6875[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [SMALL_STATE([m
\ No newline at end of file[m
[32m+[m[32m249)] = 6882,[m
  [SMA[m
\ No newline at end of file[m
[32m+[m[32mLL_STATE(250)] = 6889,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(251)][m
\ No newline at end of file[m
[32m+[m[32m = 6896,[m
  [SMALL_STA[m
\ No newline at end of file[m
[32m+[m[32mTE(252)] = 6903,[m
  [S[m
\ No newline at end of file[m
[32m+[m[32mMALL_STATE(253)] = 691[m
\ No newline at end of file[m
[32m+[m[32m0,[m
  [SMALL_STATE(254)] [m
\ No newline at end of file[m
[32m+[m[32m= 6917,[m
  [SMALL_STATE(255[m
\ No newline at end of file[m
[32m+[m[32m)] = 6924,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(256)] = 6931,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(257)] = 6938,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(258)] = 694[m
\ No newline at end of file[m
[32m+[m[32m5,[m
  [SMALL_STATE(2[m
\ No newline at end of file[m
[32m+[m[32m59)] = 6952,[m
  [SMALL_[m
\ No newline at end of file[m
[32m+[m[32mSTATE(260)] = 6959,[m
  [m
\ No newline at end of file[m
[32m+[m[32m[SMALL_STATE(261)][m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 6966,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(262)] = 6973,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(263)] =[m
\ No newline at end of file[m
[32m+[m[32m 6980,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(264)] = 6987,[m
  [[m
\ No newline at end of file[m
[32m+[m[32mSMALL_STATE(265)] = 6[m
\ No newline at end of file[m
[32m+[m[32m994,[m
  [SMALL_STATE(266)] [m
\ No newline at end of file[m
[32m+[m[32m= 7001,[m
  [SMALL_STAT[m
\ No newline at end of file[m
[32m+[m[32mE(267)] = 7008,[m
  [SMAL[m
\ No newline at end of file[m
[32m+[m[32mL_STATE(268)] = 7015,[m
\ No newline at end of file[m
[32m+[m
  [SMALL_STATE(269)] =[m
\ No newline at end of file[m
[32m+[m[32m 7022,[m
  [SMALL_STATE[m
\ No newline at end of file[m
[32m+[m[32m(270)] = 7029,[m
  [SMALL[m
\ No newline at end of file[m
[32m+[m[32m_STATE(271)] = 7036,[m
[32m+[m[32m  [SMALL_STATE(272)] = 7043,[m
 [m
\ No newline at end of file[m
[32m+[m[32m [SMALL_STATE(273)] =[m
\ No newline at end of file[m
[32m+[m[32m 7050,[m
  [SMALL_STATE(2[m
\ No newline at end of file[m
[32m+[m[32m74)] = 7057,[m
};[m

stat[m
\ No newline at end of file[m
[32m+[m[32mic TSParseActionEntry[m[41m [m
\ No newline at end of file[m
[32m+[m[32mts_parse_actions[] =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m{[m
  [0] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 0, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m false}},[m
  [1] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, RECOVER([m
\ No newline at end of file[m
[32m+[m[32m),[m
  [3] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable = true}},[m
\ No newline at end of file[m
[32m+[m[32m SHIFT_EXTRA(),[m
  [5] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = true}}, REDUCE(s[m
\ No newline at end of file[m
[32m+[m[32mym_source_file, 0)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [7] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m179),[m
  [9] = {.entry = {.count [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, SHIFT(128),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [11] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(274),[m
  [13] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(78),[m
  [15] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = false}}, SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(273),[m
  [17] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m true}}, SHIFT(71),[m
  [19[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = false}}[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT(7),[m
  [21] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = true}},[m
\ No newline at end of file[m
[32m+[m[32m SHIFT(68),[m
  [23] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = false}}[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT(9),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m25] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, REDUCE(sym[m
\ No newline at end of file[m
[32m+[m[32m_command, 1, .production_i[m
\ No newline at end of file[m
[32m+[m[32md = 1),[m
  [27] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = false}}, SHIF[m
\ No newline at end of file[m
[32m+[m[32mT(28),[m
  [29] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = false}}, SHIFT(2[m
\ No newline at end of file[m
[32m+[m[32m15),[m
  [31] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reusable = fa[m
\ No newline at end of file[m
[32m+[m[32mlse}}, SHIFT(196),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[33] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = fa[m
\ No newline at end of file[m
[32m+[m[32mlse}}, SHIFT(240),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m35] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, SHIFT(35),[m
  [3[m
\ No newline at end of file[m
[32m+[m[32m7] = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = f[m
\ No newline at end of file[m
[32m+[m[32malse}}, SHIFT(63),[m
  [39] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = false}}, SHIFT(44),[m
\ No newline at end of file[m
[32m+[m
  [41] = {.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = false}}[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT(64),[m
  [43] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT_EXTRA(),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m45] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusable = true}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mREDUCE(sym_command, 1[m
\ No newline at end of file[m
[32m+[m[32m, .production_id[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1),[m
  [47] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(40),[m
  [49][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 2, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(aux_sym_c[m
\ No newline at end of file[m
[32m+[m[32mommand_repeat1, 2, .pr[m
\ No newline at end of file[m
[32m+[m[32moduction_id = 4), SHIFT_[m
\ No newline at end of file[m
[32m+[m[32mREPEAT(9),[m
  [52] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = false}}, REDUCE(aux_[m
\ No newline at end of file[m
[32m+[m[32msym_command_repeat1, 2[m
\ No newline at end of file[m
[32m+[m[32m, .production_id = 4),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [54] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 2, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, REDUCE(aux_[m
\ No newline at end of file[m
[32m+[m[32msym_command_repeat1[m
\ No newline at end of file[m
[32m+[m[32m, 2, .production_id =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m4), SHIFT_REPEAT(28),[m
[32m+[m[32m  [57] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 2, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, R[m
\ No newline at end of file[m
[32m+[m[32mEDUCE(aux_sym_command[m
\ No newline at end of file[m
[32m+[m[32m_repeat1, 2, .production_i[m
\ No newline at end of file[m
[32m+[m[32md = 4), SHIFT_REPEAT([m
\ No newline at end of file[m
[32m+[m[32m215),[m
  [60] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 2, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = false}}, REDUCE(a[m
\ No newline at end of file[m
[32m+[m[32mux_sym_command_repeat[m
\ No newline at end of file[m
[32m+[m[32m1, 2, .production_id =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m4), SHIFT_REPEAT(196)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [63] = {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 2, .reusable = false[m
\ No newline at end of file[m
[32m+[m[32m}}, REDUCE(aux_sym_comm[m
\ No newline at end of file[m
[32m+[m[32mand_repeat1, 2, .prod[m
\ No newline at end of file[m
[32m+[m[32muction_id = 4), SHIFT_[m
\ No newline at end of file[m
[32m+[m[32mREPEAT(240),[m
  [66] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count = 2,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = false}},[m
\ No newline at end of file[m
[32m+[m[32m REDUCE(aux_sym_command[m
\ No newline at end of file[m
[32m+[m[32m_repeat1, 2, .prod[m
\ No newline at end of file[m
[32m+[m[32muction_id = 4), SHIFT_REPEAT([m
\ No newline at end of file[m
[32m+[m[32m35),[m
  [69] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 2, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(aux_sym_command_repe[m
\ No newline at end of file[m
[32m+[m[32mat1, 2, .production_[m
\ No newline at end of file[m
[32m+[m[32mid = 4), SHIFT_REPEAT(6[m
\ No newline at end of file[m
[32m+[m[32m3),[m
  [72] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 2, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = false}}, REDU[m
\ No newline at end of file[m
[32m+[m[32mCE(aux_sym_comman[m
\ No newline at end of file[m
[32m+[m[32md_repeat1, 2, .production_id = 4[m
\ No newline at end of file[m
[32m+[m[32m), SHIFT_REPEAT(44),[m
[32m+[m[32m  [75] = {.entry[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 2, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = false}}[m
\ No newline at end of file[m
[32m+[m[32m, REDUCE(aux_sym_com[m
\ No newline at end of file[m
[32m+[m[32mmand_repeat1, 2, .prod[m
\ No newline at end of file[m
[32m+[m[32muction_id = 4), SHIFT[m
\ No newline at end of file[m
[32m+[m[32m_REPEAT(64),[m
  [78] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = true}},[m
\ No newline at end of file[m
[32m+[m[32m REDUCE(aux_sym_command_[m
\ No newline at end of file[m
[32m+[m[32mrepeat1, 2, .production_id[m
\ No newline at end of file[m
[32m+[m[32m = 4),[m
  [80] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 2, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, REDUCE(aux_[m
\ No newline at end of file[m
[32m+[m[32msym_command_repeat1, 2,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.production_id = 4)[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT_REPEAT(40),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[83] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m false}}, REDUCE(sym_c[m
\ No newline at end of file[m
[32m+[m[32mommand, 2, .production[m
\ No newline at end of file[m
[32m+[m[32m_id = 3),[m
  [85[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mtrue}}, REDUCE(sym_co[m
\ No newline at end of file[m
[32m+[m[32mmmand, 2, .production_id =[m
\ No newline at end of file[m
[32m+[m[32m 3),[m
  [87] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 2, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = false}}, REDUCE([m
\ No newline at end of file[m
[32m+[m[32maux_sym_command_repeat1[m
\ No newline at end of file[m
[32m+[m[32m, 2, .production_id =[m
\ No newline at end of file[m
[32m+[m[32m 4), SHIFT_REPEAT(12),[m
[32m+[m[32m  [90] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 2, .reusable = false}}[m
\ No newline at end of file[m
[32m+[m[32m, REDUCE(aux_sym_comm[m
\ No newline at end of file[m
[32m+[m[32mand_repeat1, 2, .produc[m
\ No newline at end of file[m
[32m+[m[32mtion_id = 4), SHIFT_R[m
\ No newline at end of file[m
[32m+[m[32mEPEAT(32),[m
  [93] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 2,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, RE[m
\ No newline at end of file[m
[32m+[m[32mDUCE(aux_sym_command_[m
\ No newline at end of file[m
[32m+[m[32mrepeat1, 2, .production[m
\ No newline at end of file[m
[32m+[m[32m_id = 4), SHIFT_RE[m
\ No newline at end of file[m
[32m+[m[32mPEAT(209),[m
  [96] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 2, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = false}}, REDUCE(aux_sym_com[m
\ No newline at end of file[m
[32m+[m[32mmand_repeat1, 2, .production_id[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 4), SHIFT_REPEAT(2[m
\ No newline at end of file[m
[32m+[m[32m10),[m
  [99] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 2, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = false}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(aux_sym_command_rep[m
\ No newline at end of file[m
[32m+[m[32meat1, 2, .product[m
\ No newline at end of file[m
[32m+[m[32mion_id = 4), SHIFT_REPEAT(237),[m
[32m+[m[32m  [102] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 2, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = false}}, R[m
\ No newline at end of file[m
[32m+[m[32mEDUCE(aux_sym_com[m
\ No newline at end of file[m
[32m+[m[32mmand_repeat1, 2, .pr[m
\ No newline at end of file[m
[32m+[m[32moduction_id = 4), SHIF[m
\ No newline at end of file[m
[32m+[m[32mT_REPEAT(47),[m
  [105][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 2, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(aux_sym_co[m
\ No newline at end of file[m
[32m+[m[32mmmand_repeat1, 2, .produ[m
\ No newline at end of file[m
[32m+[m[32mction_id = 4), SHIFT_REPEA[m
\ No newline at end of file[m
[32m+[m[32mT(65),[m
  [108] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 2, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, REDUCE(aux[m
\ No newline at end of file[m
[32m+[m[32m_sym_command_repeat1, 2,[m
\ No newline at end of file[m
[32m+[m[32m .production_id = 4[m
\ No newline at end of file[m
[32m+[m[32m), SHIFT_REPEAT(45),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [111] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 2, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, REDUCE(aux[m
\ No newline at end of file[m
[32m+[m[32m_sym_command_repeat1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2, .production_[m
\ No newline at end of file[m
[32m+[m[32mid = 4), SHIFT_REPEA[m
\ No newline at end of file[m
[32m+[m[32mT(67),[m
  [114] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 2,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(aux_sym_command_rep[m
\ No newline at end of file[m
[32m+[m[32meat1, 2, .production_id[m
\ No newline at end of file[m
[32m+[m[32m = 4), SHIFT_REPEAT(5[m
\ No newline at end of file[m
[32m+[m[32m2),[m
  [117] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = false}}, SHIFT(12)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [119] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(32),[m
  [12[m
\ No newline at end of file[m
[32m+[m[32m1] = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(209),[m
  [12[m
\ No newline at end of file[m
[32m+[m[32m3] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(210),[m
  [1[m
\ No newline at end of file[m
[32m+[m[32m25] = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mfalse}}, SHIFT(237),[m
  [127] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = false}}, SHIFT(4[m
\ No newline at end of file[m
[32m+[m[32m7),[m
  [129] = {.entry = {.count [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, SHIFT(65),[m
  [131[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusable = f[m
\ No newline at end of file[m
[32m+[m[32malse}}, SHIFT(45),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[133] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(67),[m
  [135][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, SHIF[m
\ No newline at end of file[m
[32m+[m[32mT(52),[m
  [137] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = false}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(8),[m
  [139] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(213),[m
  [141] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = false}}, SHIFT(194)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [143] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mfalse}}, SHIFT(199),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m145] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m false}}, SHIFT(204),[m
[32m+[m[32m  [147] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, SHIFT(254[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [149] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(221),[m
  [151[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(72),[m
  [153] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(223),[m
  [155] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(69),[m
  [157] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, SHIFT(222)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [159] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = true}}, SHIFT(222[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [161] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, SHIFT(38),[m
\ No newline at end of file[m
[32m+[m
  [163] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reusable = f[m
\ No newline at end of file[m
[32m+[m[32malse}}, SHIFT(219),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [165] = {.entry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, SHIFT(156),[m
\ No newline at end of file[m
[32m+[m
  [167] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m217),[m
  [169] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = false}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(53),[m
  [171] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(11),[m
  [173] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, SHIFT(51),[m
  [17[m
\ No newline at end of file[m
[32m+[m[32m5] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = fa[m
\ No newline at end of file[m
[32m+[m[32mlse}}, SHIFT(232),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[177] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, SHIFT(43),[m
  [179] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count = 2,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, REDU[m
\ No newline at end of file[m
[32m+[m[32mCE(aux_sym_array_repea[m
\ No newline at end of file[m
[32m+[m[32mt1, 2), SHIFT_REPEAT(11)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [182] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = false}}, REDUCE([m
\ No newline at end of file[m
[32m+[m[32maux_sym_array_repea[m
\ No newline at end of file[m
[32m+[m[32mt1, 2),[m
  [184] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 2, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, REDUCE(aux_sym_ar[m
\ No newline at end of file[m
[32m+[m[32mray_repeat1, 2), SH[m
\ No newline at end of file[m
[32m+[m[32mIFT_REPEAT(194),[m
  [1[m
\ No newline at end of file[m
[32m+[m[32m87] = {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2, .reusable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, REDUCE(aux_sym_array[m
\ No newline at end of file[m
[32m+[m[32m_repeat1, 2), SHIFT_R[m
\ No newline at end of file[m
[32m+[m[32mEPEAT(199),[m
  [190] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 2,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = false}}, R[m
\ No newline at end of file[m
[32m+[m[32mEDUCE(aux_sym_array_r[m
\ No newline at end of file[m
[32m+[m[32mepeat1, 2), SHIFT_REPEAT(204),[m
\ No newline at end of file[m
[32m+[m
  [193] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 2, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, REDUCE(aux[m
\ No newline at end of file[m
[32m+[m[32m_sym_array_repeat1, 2)[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT_REPEAT(254),[m
[32m+[m[32m  [196] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 2, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m false}}, REDUCE(aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_array_repeat1, 2[m
\ No newline at end of file[m
[32m+[m[32m), SHIFT_REPEAT(221),[m
  [199][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 2, .reusable = true}}, REDUCE([m
\ No newline at end of file[m
[32m+[m[32maux_sym_array_repeat1, 2), SHIFT[m
\ No newline at end of file[m
[32m+[m[32m_REPEAT(72),[m
  [202][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, REDUCE(aux_sym_a[m
\ No newline at end of file[m
[32m+[m[32mrray_repeat1, 2), SHI[m
\ No newline at end of file[m
[32m+[m[32mFT_REPEAT(219),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [205] = {.entry = {.count = 2,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mREDUCE(aux_sym_ar[m
\ No newline at end of file[m
[32m+[m[32mray_repeat1, 2),[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT_REPEAT(69),[m
\ No newline at end of file[m
[32m+[m
  [208] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 2, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, REDUCE(a[m
\ No newline at end of file[m
[32m+[m[32mux_sym_array_repeat1,[m
\ No newline at end of file[m
[32m+[m[32m 2), SHIFT_REPEAT(222[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [211] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 2, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= true}}, REDUCE(aux_sym_a[m
\ No newline at end of file[m
[32m+[m[32mrray_repeat1, 2), SHIFT_[m
\ No newline at end of file[m
[32m+[m[32mREPEAT(222),[m
  [214] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, SHIF[m
\ No newline at end of file[m
[32m+[m[32mT(160),[m
  [216] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(216),[m
  [218] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = false}}[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT(224),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [220] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = false}}, SHIFT(1[m
\ No newline at end of file[m
[32m+[m[32m0),[m
  [222] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = false}}, SHIFT(144[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [224] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m false}}, SHIFT(208),[m
\ No newline at end of file[m
[32m+[m
  [226] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, SHIFT(207),[m
[32m+[m[32m  [228] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m false}}, SHIFT(163),[m
\ No newline at end of file[m
[32m+[m
  [230] = {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = false[m
\ No newline at end of file[m
[32m+[m[32m}}, SHIFT(159),[m
  [232[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = false[m
\ No newline at end of file[m
[32m+[m[32m}}, SHIFT(68),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m234] = {.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = false}},[m
\ No newline at end of file[m
[32m+[m[32m SHIFT(162),[m
  [236] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable = true}}[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT(162),[m
  [238[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = fa[m
\ No newline at end of file[m
[32m+[m[32mlse}}, REDUCE(aux_sym_[m
\ No newline at end of file[m
[32m+[m[32mvalue_path_repeat1, 2[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [240] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 2, .reusable = f[m
\ No newline at end of file[m
[32m+[m[32malse}}, REDUCE(aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm_value_path_repe[m
\ No newline at end of file[m
[32m+[m[32mat1, 2), SHIFT_RE[m
\ No newline at end of file[m
[32m+[m[32mPEAT(248),[m
  [243[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(aux_sym_v[m
\ No newline at end of file[m
[32m+[m[32malue_path_repeat1, 2)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [245] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, REDUCE(sym_[m
\ No newline at end of file[m
[32m+[m[32mvalue_path, 3),[m
  [247] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(248),[m
  [249] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(sym_value_path, 3),[m
[32m+[m[32m  [251] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, REDUCE(sy[m
\ No newline at end of file[m
[32m+[m[32mm_value_path, 2),[m
  [2[m
\ No newline at end of file[m
[32m+[m[32m53] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, REDUCE(sy[m
\ No newline at end of file[m
[32m+[m[32mm_value_path, 2),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[255] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 2, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, REDUCE(aux_[m
\ No newline at end of file[m
[32m+[m[32msym_value_path_repeat[m
\ No newline at end of file[m
[32m+[m[32m1, 2), SHIFT_REPEAT(255),[m
[32m+[m[32m  [258] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m false}}, SHIFT(255),[m
\ No newline at end of file[m
[32m+[m
  [260] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, REDUCE(sym__express[m
\ No newline at end of file[m
[32m+[m[32mion, 1),[m
  [262] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(264),[m
  [264] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = true}}, REDUCE(sym__[m
\ No newline at end of file[m
[32m+[m[32mexpression, 1),[m
  [266] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(sym_string, 3),[m
[32m+[m[32m  [268] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= true}}, REDUCE([m
\ No newline at end of file[m
[32m+[m[32msym_string, 3),[m
  [270] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = false}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mREDUCE(sym_table,[m
\ No newline at end of file[m
[32m+[m[32m 4),[m
  [272] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}}, R[m
\ No newline at end of file[m
[32m+[m[32mEDUCE(sym_table, 4),[m
[32m+[m[32m  [274] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, REDUCE(sym[m
\ No newline at end of file[m
[32m+[m[32m_range, 3),[m
  [276] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = true}}, REDUCE(sy[m
\ No newline at end of file[m
[32m+[m[32mm_range, 3),[m
  [278] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, SHIF[m
\ No newline at end of file[m
[32m+[m[32mT(245),[m
  [280] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, R[m
\ No newline at end of file[m
[32m+[m[32mEDUCE(sym_math_mode[m
\ No newline at end of file[m
[32m+[m[32m, 4),[m
  [282] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = true}},[m
\ No newline at end of file[m
[32m+[m[32m REDUCE(sym_math_mod[m
\ No newline at end of file[m
[32m+[m[32me, 4),[m
  [284] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}},[m
\ No newline at end of file[m
[32m+[m[32m REDUCE(sym_table,[m
\ No newline at end of file[m
[32m+[m[32m 5),[m
  [286] = {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = true}}[m
\ No newline at end of file[m
[32m+[m[32m, REDUCE(sym_table, 5),[m
\ No newline at end of file[m
[32m+[m
  [288] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable = f[m
\ No newline at end of file[m
[32m+[m[32malse}}, REDUCE(sym_file[m
\ No newline at end of file[m
[32m+[m[32m_path, 1),[m
  [290] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = true}}, REDUCE(sym_fil[m
\ No newline at end of file[m
[32m+[m[32me_path, 1),[m
  [292] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable = false[m
\ No newline at end of file[m
[32m+[m[32m}}, REDUCE(sym_block,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2),[m
  [294] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = true}}, REDUCE(sym[m
\ No newline at end of file[m
[32m+[m[32m_block, 2),[m
  [296][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(sym_strin[m
\ No newline at end of file[m
[32m+[m[32mg, 2),[m
  [298] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, REDUCE(sym_s[m
\ No newline at end of file[m
[32m+[m[32mtring, 2),[m
  [300] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = false}}, REDUCE[m
\ No newline at end of file[m
[32m+[m[32m(sym_array, 2),[m
  [302] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, REDUCE(sym_array,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2),[m
  [304] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = false}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(sym_block, 3[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [306] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = true}}, REDU[m
\ No newline at end of file[m
[32m+[m[32mCE(sym_block, 3),[m
  [308] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(sym_op[m
\ No newline at end of file[m
[32m+[m[32merator, 1),[m
  [310] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m true}}, REDUCE(sym_ope[m
\ No newline at end of file[m
[32m+[m[32mrator, 1),[m
  [312] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(sym_command_substitut[m
\ No newline at end of file[m
[32m+[m[32mion, 3),[m
  [314] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .reusable = t[m
\ No newline at end of file[m
[32m+[m[32mrue}}, REDUCE(sym_command_substi[m
\ No newline at end of file[m
[32m+[m[32mtution, 3),[m
  [316] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = false}}, REDUCE([m
\ No newline at end of file[m
[32m+[m[32msym_array, 3),[m
  [318] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(sym_array[m
\ No newline at end of file[m
[32m+[m[32m, 3),[m
  [320] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = false}}, REDUCE([m
\ No newline at end of file[m
[32m+[m[32maux_sym_command_repeat1, 1[m
\ No newline at end of file[m
[32m+[m[32m, .production_id = 2),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [322] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(aux_sym_comm[m
\ No newline at end of file[m
[32m+[m[32mand_repeat1, 1, .pr[m
\ No newline at end of file[m
[32m+[m[32moduction_id = 2),[m
  [3[m
\ No newline at end of file[m
[32m+[m[32m24] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mtrue}}, REDUCE(aux_sym[m
\ No newline at end of file[m
[32m+[m[32m_array_repeat1, 2),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[326] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(265),[m
  [328] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, REDUCE(aux_sym_value_path_re[m
\ No newline at end of file[m
[32m+[m[32mpeat1, 2), SHIFT_REPEA[m
\ No newline at end of file[m
[32m+[m[32mT(265),[m
  [331] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = true}}, SHIFT(127[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [333] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, SHIFT(2),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[335] = {.entry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, SHIFT(36),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[337] = {.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(126),[m
  [339] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = true}}, SHI[m
\ No newline at end of file[m
[32m+[m[32mFT(49),[m
  [341] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(154),[m
  [343] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count = 1[m
\ No newline at end of file[m
[32m+[m[32m, .reusable = true}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(229),[m
  [345] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = true}}, SHIFT(115),[m
[32m+[m[32m  [347] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable = t[m
\ No newline at end of file[m
[32m+[m[32mrue}}, SHIFT(122),[m
[32m+[m[32m  [349] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m true}}, SHIFT(120)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [351] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = true}}, RED[m
\ No newline at end of file[m
[32m+[m[32mUCE(sym_binary_expre[m
\ No newline at end of file[m
[32m+[m[32mssion, 3, .producti[m
\ No newline at end of file[m
[32m+[m[32mon_id = 5),[m
  [353] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = false}}, RE[m
\ No newline at end of file[m
[32m+[m[32mDUCE(sym_binary_expr[m
\ No newline at end of file[m
[32m+[m[32mession, 3, .produc[m
\ No newline at end of file[m
[32m+[m[32mtion_id = 5),[m
  [355] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, SHIFT(119),[m
\ No newline at end of file[m
[32m+[m
  [357] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable = f[m
\ No newline at end of file[m
[32m+[m[32malse}}, SHIFT(116),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m359] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(118),[m
  [361] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reusable = fa[m
\ No newline at end of file[m
[32m+[m[32mlse}}, SHIFT(121),[m
  [363] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(117),[m
  [365] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(125),[m
  [367[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, REDUCE(sym_parenthes[m
\ No newline at end of file[m
[32m+[m[32mized_math_expression, 3),[m
[32m+[m[32m  [369] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(sym_parent[m
\ No newline at end of file[m
[32m+[m[32mhesized_math_expression,[m
\ No newline at end of file[m
[32m+[m[32m 3),[m
  [371] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = true}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(sym__statement, 1[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [373] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, R[m
\ No newline at end of file[m
[32m+[m[32mEDUCE(sym__statement[m
\ No newline at end of file[m
[32m+[m[32m, 1),[m
  [375] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(114),[m
  [377] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count = 2, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = false}},[m
\ No newline at end of file[m
[32m+[m[32m REDUCE(aux_sym__statements_repeat[m
\ No newline at end of file[m
[32m+[m[32m1, 2), SHIFT_REPEAT(17[m
\ No newline at end of file[m
[32m+[m[32m9),[m
  [380] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 2, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = true}}, REDUCE(aux_sy[m
\ No newline at end of file[m
[32m+[m[32mm__statements_repeat1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2), SHIFT_REPEAT(128),[m
[32m+[m[32m  [383] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 2, .reusable = false}}, R[m
\ No newline at end of file[m
[32m+[m[32mEDUCE(aux_sym__statements_repeat[m
\ No newline at end of file[m
[32m+[m[32m1, 2), SHIFT_REPEAT(274),[m
  [3[m
\ No newline at end of file[m
[32m+[m[32m86] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 2, .reusable = tr[m
\ No newline at end of file[m
[32m+[m[32mue}}, REDUCE(aux_sym__s[m
\ No newline at end of file[m
[32m+[m[32mtatements_repeat1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2), SHIFT_REPEAT(78),[m
\ No newline at end of file[m
[32m+[m
  [389] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 2, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, REDUCE(au[m
\ No newline at end of file[m
[32m+[m[32mx_sym__statements_repeat[m
\ No newline at end of file[m
[32m+[m[32m1, 2), SHIFT_REPEAT(273),[m
[32m+[m[32m  [392] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 2, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, REDUCE(aux_sym__st[m
\ No newline at end of file[m
[32m+[m[32matements_repeat1, 2), SH[m
\ No newline at end of file[m
[32m+[m[32mIFT_REPEAT(71),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m395] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 2, .reusable = fa[m
\ No newline at end of file[m
[32m+[m[32mlse}}, REDUCE(aux_s[m
\ No newline at end of file[m
[32m+[m[32mym__statements_repeat1[m
\ No newline at end of file[m
[32m+[m[32m, 2), SHIFT_REPEAT(2),[m
\ No newline at end of file[m
[32m+[m
  [398] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 2,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = true}},[m
\ No newline at end of file[m
[32m+[m[32m REDUCE(aux_sym__stat[m
\ No newline at end of file[m
[32m+[m[32mements_repeat1, 2),[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT_REPEAT(68),[m
[32m+[m[32m  [401] = {.entry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, SHI[m
\ No newline at end of file[m
[32m+[m[32mFT(242),[m
  [403] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 2, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = true}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(aux_sym_value_path_repea[m
\ No newline at end of file[m
[32m+[m[32mt1, 2), SHIFT_REPEAT(24[m
\ No newline at end of file[m
[32m+[m[32m2),[m
  [406] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = true}}, SHIFT(130),[m
  [408] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = true}}, SHIFT(131),[m
  [410[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, SHIFT(136),[m
  [412][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = tr[m
\ No newline at end of file[m
[32m+[m[32mue}}, SHIFT(77),[m
  [4[m
\ No newline at end of file[m
[32m+[m[32m14] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = tr[m
\ No newline at end of file[m
[32m+[m[32mue}}, SHIFT(132),[m
  [416[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}}, SHI[m
\ No newline at end of file[m
[32m+[m[32mFT(133),[m
  [418] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = true}}, SHIFT(134[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [420] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = false}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m135),[m
  [422] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = true}}, SHIF[m
\ No newline at end of file[m
[32m+[m[32mT(135),[m
  [424[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mtrue}}, SHIFT(94),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[426] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = true}}, SHIFT(81),[m
  [428] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(231),[m
  [430] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, SHIFT(9[m
\ No newline at end of file[m
[32m+[m[32m5),[m
  [432] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = true}}, SHIFT(46),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [434] = {.entry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = true}}, SHIFT(33),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [436] = {.entry = {.count = 1[m
\ No newline at end of file[m
[32m+[m[32m, .reusable = true}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(150),[m
  [438] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}}[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT(75),[m
  [440] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = true}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(124),[m
  [442][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count = 1[m
\ No newline at end of file[m
[32m+[m[32m, .reusable = true}}, SHIF[m
\ No newline at end of file[m
[32m+[m[32mT(101),[m
  [444] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, SHIFT(252[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [446] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = true}}, SHIFT(70)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [448] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, SHIFT(76[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [450] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = true}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(82),[m
  [452] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, SHIFT(80),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m454] = {.entry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = true}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m83),[m
  [456] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, SHIFT(99),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [458] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusable = tr[m
\ No newline at end of file[m
[32m+[m[32mue}}, SHIFT(79),[m
  [460[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = true}}, SHIFT(98),[m
  [462[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, REDU[m
\ No newline at end of file[m
[32m+[m[32mCE(aux_sym__statement[m
\ No newline at end of file[m
[32m+[m[32ms_repeat1, 2),[m
  [464] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count = 1[m
\ No newline at end of file[m
[32m+[m[32m, .reusable = true}[m
\ No newline at end of file[m
[32m+[m[32m}, REDUCE(aux_sym__st[m
\ No newline at end of file[m
[32m+[m[32matements_repeat1, 2),[m
\ No newline at end of file[m
[32m+[m
  [466] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = true}}, REDUCE(sym__s[m
\ No newline at end of file[m
[32m+[m[32mtatements, 3),[m
  [468] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = true}}, SHIFT(9[m
\ No newline at end of file[m
[32m+[m[32m7),[m
  [470] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = true}}, SHIFT(74[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [472] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = true}}, SHIFT(1[m
\ No newline at end of file[m
[32m+[m[32m03),[m
  [474] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(104),[m
  [476] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(96),[m
  [4[m
\ No newline at end of file[m
[32m+[m[32m78] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable = true}}, RED[m
\ No newline at end of file[m
[32m+[m[32mUCE(sym__statements, 2[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [480] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= true}}, SHIFT(108),[m
\ No newline at end of file[m
[32m+[m
  [482] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(107),[m
  [484[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = true}}, SHIFT(10[m
\ No newline at end of file[m
[32m+[m[32m6),[m
  [486] = {.entry = {.count [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = true}}, SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(105),[m
  [488] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = true}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m102),[m
  [490] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(93),[m
  [492] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(100),[m
  [494] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= true}}, SHIFT(246),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m496] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, SHIFT(145),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m498] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = tr[m
\ No newline at end of file[m
[32m+[m[32mue}}, SHIFT(148),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [500] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mtrue}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m143),[m
  [502] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = true}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(261),[m
  [504] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = true}}, REDUCE([m
\ No newline at end of file[m
[32m+[m[32maux_sym_signature_rep[m
\ No newline at end of file[m
[32m+[m[32meat1, 2),[m
  [506] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 2, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, REDUCE(au[m
\ No newline at end of file[m
[32m+[m[32mx_sym_signature_repeat1[m
\ No newline at end of file[m
[32m+[m[32m, 2), SHIFT_REPEAT(1[m
\ No newline at end of file[m
[32m+[m[32m45),[m
  [509] = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 2, .reusable = true}}, REDUCE[m
\ No newline at end of file[m
[32m+[m[32m(aux_sym_signature_repeat1, 2)[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT_REPEAT(148),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [512] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 2, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mtrue}}, REDUCE(aux_[m
\ No newline at end of file[m
[32m+[m[32msym_signature_repeat1[m
\ No newline at end of file[m
[32m+[m[32m, 2), SHIFT_REPEAT(14[m
\ No newline at end of file[m
[32m+[m[32m3),[m
  [515] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, REDUCE(sym[m
\ No newline at end of file[m
[32m+[m[32m_parameter, 1),[m
  [517] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m111),[m
  [519] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = true}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m168),[m
  [521] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = false}}, SHI[m
\ No newline at end of file[m
[32m+[m[32mFT(251),[m
  [523] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, REDUCE(sym_flag,[m
\ No newline at end of file[m
[32m+[m[32m 1),[m
  [525] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = true}}, SH[m
\ No newline at end of file[m
[32m+[m[32mIFT(112),[m
  [527] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = true}}, SHIFT(259),[m
\ No newline at end of file[m
[32m+[m
  [529] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= true}}, REDUCE(sym_param[m
\ No newline at end of file[m
[32m+[m[32meter, 3),[m
  [531] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = true}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m170),[m
  [533] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = true}}, REDUC[m
\ No newline at end of file[m
[32m+[m[32mE(sym_rest, 1),[m
  [535] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = true}}, SHIF[m
\ No newline at end of file[m
[32m+[m[32mT(110),[m
  [537] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, RE[m
\ No newline at end of file[m
[32m+[m[32mDUCE(sym_type, 1),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[539] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mfalse}}, REDUCE(sym__sta[m
\ No newline at end of file[m
[32m+[m[32mtements, 2),[m
  [541] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = false}}, SHIFT(88[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [543] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, SHIFT(12[m
\ No newline at end of file[m
[32m+[m[32m3),[m
  [545] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = true}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m123),[m
  [547] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = true}},[m
\ No newline at end of file[m
[32m+[m[32m REDUCE(sym_function[m
\ No newline at end of file[m
[32m+[m[32m_definition, 4, .pr[m
\ No newline at end of file[m
[32m+[m[32moduction_id = 6),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m549] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, REDUCE(sym_function_d[m
\ No newline at end of file[m
[32m+[m[32mefinition, 4, .product[m
\ No newline at end of file[m
[32m+[m[32mion_id = 6),[m
  [551] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count = 1[m
\ No newline at end of file[m
[32m+[m[32m, .reusable = true}}, REDU[m
\ No newline at end of file[m
[32m+[m[32mCE(sym_variable_declara[m
\ No newline at end of file[m
[32m+[m[32mtion, 4, .production_id[m
\ No newline at end of file[m
[32m+[m[32m = 7),[m
  [553] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, REDUCE(sym_variable_declar[m
\ No newline at end of file[m
[32m+[m[32mation, 4, .production_id = 7),[m
\ No newline at end of file[m
[32m+[m
  [555] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = true}}, REDUCE(sym_p[m
\ No newline at end of file[m
[32m+[m[32mipeline, 3),[m
  [557[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, REDUCE(sym_pipe[m
\ No newline at end of file[m
[32m+[m[32mline, 3),[m
  [559] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, REDUCE(s[m
\ No newline at end of file[m
[32m+[m[32mym__statements, 1),[m
  [5[m
\ No newline at end of file[m
[32m+[m[32m61] = {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(129),[m
  [563] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = true}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(129),[m
  [565][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, REDUCE(sym_flag,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m4),[m
  [567] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, SHIFT(113),[m
  [56[m
\ No newline at end of file[m
[32m+[m[32m9] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, SHIFT(87),[m
  [571] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, SHI[m
\ No newline at end of file[m
[32m+[m[32mFT(137),[m
  [573] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .reus[m
\ No newline at end of file[m
[32m+[m[32mable = true}}, SHIFT(13[m
\ No newline at end of file[m
[32m+[m[32m7),[m
  [575] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = true}}, REDUCE(sym_rest, 3),[m
[32m+[m[32m  [577] = {.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}}, REDUCE(sy[m
\ No newline at end of file[m
[32m+[m[32mm_parameter, 2),[m
  [57[m
\ No newline at end of file[m
[32m+[m[32m9] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = true[m
\ No newline at end of file[m
[32m+[m[32m}}, REDUCE(sym_flag[m
\ No newline at end of file[m
[32m+[m[32m, 3),[m
  [581] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = true}}, REDU[m
\ No newline at end of file[m
[32m+[m[32mCE(sym_parameter, 4),[m
[32m+[m[32m  [583] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusable = true}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(174),[m
  [585] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = true}}, RED[m
\ No newline at end of file[m
[32m+[m[32mUCE(aux_sym_signature_re[m
\ No newline at end of file[m
[32m+[m[32mpeat1, 1),[m
  [587] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = true}},[m
\ No newline at end of file[m
[32m+[m[32m REDUCE(sym_flag, 6[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [589] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = true}}, RE[m
\ No newline at end of file[m
[32m+[m[32mDUCE(sym__statements[m
\ No newline at end of file[m
[32m+[m[32m, 1),[m
  [591] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m138),[m
  [593] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, SHIFT(13[m
\ No newline at end of file[m
[32m+[m[32m8),[m
  [595] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusab[m
\ No newline at end of file[m
[32m+[m[32mle = true}}, SHIFT(14),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[597] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(58),[m
  [599][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count = 2, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, REDUCE(aux_sym_tab[m
\ No newline at end of file[m
[32m+[m[32mle_repeat1, 2), SHIFT_REPEAT(1[m
\ No newline at end of file[m
[32m+[m[32m4),[m
  [602] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, REDUCE(au[m
\ No newline at end of file[m
[32m+[m[32mx_sym_table_repeat1[m
\ No newline at end of file[m
[32m+[m[32m, 2),[m
  [604] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = true}}, SHIF[m
\ No newline at end of file[m
[32m+[m[32mT(34),[m
  [606] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = true}}, SHIFT(30),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [608] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = true}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(205),[m
  [610][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count = 1[m
\ No newline at end of file[m
[32m+[m[32m, .reusable = true}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(190),[m
  [612][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count =[m
\ No newline at end of file[m
[32m+[m[32m 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(220),[m
  [61[m
\ No newline at end of file[m
[32m+[m[32m4] = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = true}}, SHIFT(15[m
\ No newline at end of file[m
[32m+[m[32m5),[m
  [616] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = true}}, SHIFT(5[m
\ No newline at end of file[m
[32m+[m[32m5),[m
  [618] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 2, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, REDUCE(aux_s[m
\ No newline at end of file[m
[32m+[m[32mym_value_path_repeat1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m2), SHIFT_REPEAT(260),[m
[32m+[m[32m  [621] = {.entry =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable = false}}[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT(260),[m
  [623] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(146),[m
  [62[m
\ No newline at end of file[m
[32m+[m[32m5] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(141),[m
  [627[m
\ No newline at end of file[m
[32m+[m[32m] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = t[m
\ No newline at end of file[m
[32m+[m[32mrue}}, SHIFT(141),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[629] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mtrue}}, SHIFT(228),[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m31] = {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = true}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(227),[m
  [633] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m152),[m
  [635] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = false}}, SHI[m
\ No newline at end of file[m
[32m+[m[32mFT(191),[m
  [637] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = false}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(241),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[639] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = false}}, SHIFT(19[m
\ No newline at end of file[m
[32m+[m[32m3),[m
  [641] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, REDUCE(aux_[m
\ No newline at end of file[m
[32m+[m[32msym_string_repeat1, 2[m
\ No newline at end of file[m
[32m+[m[32m),[m
  [643] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 2, .reusable = f[m
\ No newline at end of file[m
[32m+[m[32malse}}, REDUCE(aux_sym_[m
\ No newline at end of file[m
[32m+[m[32mstring_repeat1, 2), SHI[m
\ No newline at end of file[m
[32m+[m[32mFT_REPEAT(191),[m
  [646] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 1, .reusable = fal[m
\ No newline at end of file[m
[32m+[m[32mse}}, SHIFT(238),[m
  [648] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(202),[m
  [650] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1, .r[m
\ No newline at end of file[m
[32m+[m[32meusable = false}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(239),[m
  [652] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = true}}[m
\ No newline at end of file[m
[32m+[m[32m, SHIFT(267),[m
  [654] [m
\ No newline at end of file[m
[32m+[m[32m= {.entry = {.count = 1,[m
\ No newline at end of file[m
[32m+[m[32m .reusable = true}}, SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(268),[m
  [656] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, SHIFT(37),[m
\ No newline at end of file[m
[32m+[m
  [658] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, SHIFT(200)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [660] = {.entry = [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = false}}, SHIFT(2[m
\ No newline at end of file[m
[32m+[m[32m33),[m
  [662] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1[m
\ No newline at end of file[m
[32m+[m[32m, .reusable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(230),[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m64] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = fals[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(214),[m
  [66[m
\ No newline at end of file[m
[32m+[m[32m6] = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = false}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(29),[m
  [668][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, RE[m
\ No newline at end of file[m
[32m+[m[32mDUCE(aux_sym_string_rep[m
\ No newline at end of file[m
[32m+[m[32meat2, 2),[m
  [670] = {.e[m
\ No newline at end of file[m
[32m+[m[32mntry = {.count = 2, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mfalse}}, REDUCE(aux_sym_string_r[m
\ No newline at end of file[m
[32m+[m[32mepeat2, 2), SHIFT_REPEAT(202),[m
\ No newline at end of file[m
[32m+[m
  [673] = {.entry = {[m
\ No newline at end of file[m
[32m+[m[32m.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, SHIFT(197),[m
\ No newline at end of file[m
[32m+[m
  [675] = {.entry [m
\ No newline at end of file[m
[32m+[m[32m= {.count = 1, .reusa[m
\ No newline at end of file[m
[32m+[m[32mble = false}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m192),[m
  [677] = {.ent[m
\ No newline at end of file[m
[32m+[m[32mry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = true}}, REDUCE(a[m
\ No newline at end of file[m
[32m+[m[32mux_sym_column_header_repea[m
\ No newline at end of file[m
[32m+[m[32mt1, 2),[m
  [679] = {.entr[m
\ No newline at end of file[m
[32m+[m[32my = {.count = 2, .reusabl[m
\ No newline at end of file[m
[32m+[m[32me = true}}, REDUCE(aux[m
\ No newline at end of file[m
[32m+[m[32m_sym_column_header_repea[m
\ No newline at end of file[m
[32m+[m[32mt1, 2), SHIFT_REPEA[m
\ No newline at end of file[m
[32m+[m[32mT(268),[m
  [682] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .re[m
\ No newline at end of file[m
[32m+[m[32musable = false}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(153),[m
  [684] = {[m
\ No newline at end of file[m
[32m+[m[32m.entry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = fa[m
\ No newline at end of file[m
[32m+[m[32mlse}}, SHIFT(198),[m
 [m
\ No newline at end of file[m
[32m+[m[32m [686] = {.entry =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m{.count = 1, .reusable[m
\ No newline at end of file[m
[32m+[m[32m = false}}, SHIFT(189),[m
\ No newline at end of file[m
[32m+[m
  [688] = {.entry = {.[m
\ No newline at end of file[m
[32m+[m[32mcount = 1, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, SHIFT(54),[m
  [6[m
\ No newline at end of file[m
[32m+[m[32m90] = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = false[m
\ No newline at end of file[m
[32m+[m[32m}}, SHIFT(211),[m
  [692][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = false}}, SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(212),[m
  [694] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = false}}, S[m
\ No newline at end of file[m
[32m+[m[32mHIFT(50),[m
  [696] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}}, RE[m
\ No newline at end of file[m
[32m+[m[32mDUCE(sym_column_hea[m
\ No newline at end of file[m
[32m+[m[32mder, 2),[m
  [698] = {.[m
\ No newline at end of file[m
[32m+[m[32mentry = {.count = 1,[m[41m [m
\ No newline at end of file[m
[32m+[m[32m.reusable = false}},[m[41m [m
\ No newline at end of file[m
[32m+[m[32mSHIFT(201),[m
  [700] = [m
\ No newline at end of file[m
[32m+[m[32m{.entry = {.count = 1, .[m
\ No newline at end of file[m
[32m+[m[32mreusable = false}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m59),[m
  [702] = {.entry =[m
\ No newline at end of file[m
[32m+[m[32m {.count = 1, .reusable =[m
\ No newline at end of file[m
[32m+[m[32m true}}, SHIFT(59),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[704] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mtrue}}, SHIFT(139),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[706] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 2, .reusable[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= false}}, REDUCE(sym_[m
\ No newline at end of file[m
[32m+[m[32m_expression, 1), SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(218),[m
  [709][m
\ No newline at end of file[m
[32m+[m[32m = {.entry = {.count[m
\ No newline at end of file[m
[32m+[m[32m = 1, .reusable = t[m
\ No newline at end of file[m
[32m+[m[32mrue}}, SHIFT(235),[m
  [m
\ No newline at end of file[m
[32m+[m[32m[711] = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = true}[m
\ No newline at end of file[m
[32m+[m[32m}, SHIFT(26),[m
  [713] =[m
\ No newline at end of file[m
[32m+[m[32m {.entry = {.count =[m[41m [m
\ No newline at end of file[m
[32m+[m[32m1, .reusable = true}}, SHI[m
\ No newline at end of file[m
[32m+[m[32mFT(226),[m
  [715] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = true}}, SHIFT(2[m
\ No newline at end of file[m
[32m+[m[32m3),[m
  [717] = {.entry = {.count [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = true}}, SHIFT(9[m
\ No newline at end of file[m
[32m+[m[32m2),[m
  [719] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = tru[m
\ No newline at end of file[m
[32m+[m[32me}}, SHIFT(42),[m
  [72[m
\ No newline at end of file[m
[32m+[m[32m1] = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = tr[m
\ No newline at end of file[m
[32m+[m[32mue}}, SHIFT(39),[m
  [7[m
\ No newline at end of file[m
[32m+[m[32m23] = {.entry = {.cou[m
\ No newline at end of file[m
[32m+[m[32mnt = 1, .reusable = t[m
\ No newline at end of file[m
[32m+[m[32mrue}}, SHIFT(48),[m
  [7[m
\ No newline at end of file[m
[32m+[m[32m25] = {.entry = {.count[m[41m [m
\ No newline at end of file[m
[32m+[m[32m= 1, .reusable = true}}, R[m
\ No newline at end of file[m
[32m+[m[32mEDUCE(sym_signature, 2),[m
\ No newline at end of file[m
[32m+[m
  [727] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusable = t[m
\ No newline at end of file[m
[32m+[m[32mrue}}, SHIFT(165),[m
  [72[m
\ No newline at end of file[m
[32m+[m[32m9] = {.entry = {.co[m
\ No newline at end of file[m
[32m+[m[32munt = 1, .reusable = t[m
\ No newline at end of file[m
[32m+[m[32mrue}}, SHIFT(24),[m
  [7[m
\ No newline at end of file[m
[32m+[m[32m31] = {.entry = {.c[m
\ No newline at end of file[m
[32m+[m[32mount = 1, .reusable =[m[41m [m
\ No newline at end of file[m
[32m+[m[32mtrue}}, SHIFT(56),[m
  [[m
\ No newline at end of file[m
[32m+[m[32m733] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reu[m
\ No newline at end of file[m
[32m+[m[32msable = true}}, SHI[m
\ No newline at end of file[m
[32m+[m[32mFT(149),[m
  [735] = {.e[m
\ No newline at end of file[m
 ntry = {.count = 1, .re[m
\ No newline at end of file[m
[31m-    ACTIONS(28), 1,[m
[32m+[m[32musable = true}}, SHIFT([m
\ No newline at end of file[m
[32m+[m[32m158),[m
  [737] = {.ent[m
\ No newline at end of file[m
 ry = {.count = 1, .reusabl[m
\ No newline at end of file[m
[31m-    ACTIONS(31), 1,[m
 e = true}}, SHIFT(89),[m
[31m-    ACTIONS(34), 1,[m
   [739] = {.entry = {.c[m
\ No newline at end of file[m
[31m-    ACTIONS(37), 1,[m
 ount = 1, .reusable = t[m
\ No newline at end of file[m
[31m-    ACTIONS(43), 1,[m
[32m+[m[32mrue}}, SHIFT(57),[m
  [741] = {.en[m
\ No newline at end of file[m
[32m+[m[32mtry = {.count = 1, .reusable = t[m
\ No newline at end of file[m
 rue}}, SHIFT(184),[m
  [743] = {[m
\ No newline at end of file[m
[31m-    ACTIONS(46), 1,[m
 .entry = {.count = 1, [m
\ No newline at end of file[m
[31m-    ACTIONS(49), 1,[m
[32m+[m[32m.reusable = true}}, S[m
\ No newline at end of file[m
 HIFT(41),[m
  [745] = {.e[m
\ No newline at end of file[m
[31m-    ACTIONS(52), 1,[m
[31m-      sym_comment,[m
[31m-    ACTIONS(54), 1,[m
 ntry = {.count = 1,[m
\ No newline at end of file[m
[31m-    STATE(2), 1,[m
[31m-      aux_sym_command_repeat1,[m
[31m-    ACTIONS(40), 2,[m
[31m-      aux_sym_file_path_token1,[m
[31m-      aux_sym_file_path_token2,[m
[31m-    ACTIONS(26), 4,[m
[31m-      anon_sym_RPAREN,[m
[31m-      anon_sym_PIPE,[m
[31m-      anon_sym_SEMI,[m
[31m-      anon_sym_RBRACE,[m
[31m-    STATE(46), 11,[m
[31m-      sym__expression,[m
[31m-      sym_string,[m
[31m-      sym_value_path,[m
[31m-      sym_file_path,[m
[31m-      sym_range,[m
[31m-      sym_command_substitution,[m
[31m-      sym_math_mode,[m
[31m-      sym_table,[m
[31m-      sym_array,[m
[31m-      sym_block,[m
[31m-      sym_operator,[m
[31m-    ACTIONS(56), 16,[m
  .reusable = true}}, [m
\ No newline at end of file[m
 SHIFT(175),[m
  [747] =[m
\ No newline at end of file[m
  {.entry = {.count = [m
\ No newline at end of file[m
[36m@@ -2514,50 +7526,24 @@[m [mstatic uint16_t ts_small_parse_table[] = {[m
   [755] = {.entry =[m
\ No newline at end of file[m
  {.count = 1, .reusabl[m
\ No newline at end of file[m
 e = true}}, REDUCE(sym[m
\ No newline at end of file[m
[31m-  [75] = 15,[m
[31m-    ACTIONS(52), 1,[m
[32m+[m[32m_signature, 3)[m
\ No newline at end of file[m
[32m+[m[32m,[m
  [757] = {.entry [m
\ No newline at end of file[m
 = {.count = 1, .reu[m
\ No newline at end of file[m
[31m-    ACTIONS(59), 1,[m
[32m+[m[32msable = true}}, SHIFT([m
\ No newline at end of file[m
 73),[m
  [759] = {.entry [m
\ No newline at end of file[m
[31m-    ACTIONS(63), 1,[m
[32m+[m[32m= {.count = 1, .reusa[m
\ No newline at end of file[m
 ble = true}}, SHIFT(20),[m
 [m
\ No newline at end of file[m
[31m-    ACTIONS(65), 1,[m
  [761] = {.entry = {.co[m
\ No newline at end of file[m
[31m-    ACTIONS(67), 1,[m
 unt = 1, .reusable = tr[m
\ No newline at end of file[m
[31m-    ACTIONS(69), 1,[m
 ue}}, SHIFT(31),[m
  [763[m
\ No newline at end of file[m
[31m-    ACTIONS(73), 1,[m
[32m+[m[32m] = {.entry = {.coun[m
\ No newline at end of file[m
[32m+[m[32mt = 1, .reusable = true}}, SHIFT[m
\ No newline at end of file[m
[32m+[m[32m(66),[m
  [765] = {.entry = {.coun[m
\ No newline at end of file[m
 t = 1, .reusable = true}}, SHI[m
\ No newline at end of file[m
[31m-    ACTIONS(75), 1,[m
 FT(178),[m
  [767] = {.e[m
\ No newline at end of file[m
[31m-    ACTIONS(77), 1,[m
[32m+[m[32mntry = {.count = 1, .[m
\ No newline at end of file[m
 reusable = true}}, REDU[m
\ No newline at end of file[m
[31m-    ACTIONS(79), 1,[m
 CE(sym_column_heade[m
\ No newline at end of file[m
[31m-    STATE(4), 1,[m
[31m-      aux_sym_command_repeat1,[m
[31m-    ACTIONS(71), 2,[m
[31m-      aux_sym_file_path_token1,[m
[31m-      aux_sym_file_path_token2,[m
[31m-    ACTIONS(61), 4,[m
[31m-      anon_sym_RPAREN,[m
[31m-      anon_sym_PIPE,[m
[31m-      anon_sym_SEMI,[m
[31m-      anon_sym_RBRACE,[m
[31m-    STATE(46), 11,[m
[31m-      sym__expression,[m
[31m-      sym_string,[m
[31m-      sym_value_path,[m
[31m-      sym_file_path,[m
[31m-      sym_range,[m
[31m-      sym_command_substitution,[m
[31m-      sym_math_mode,[m
[31m-      sym_table,[m
[31m-      sym_array,[m
[31m-      sym_block,[m
[31m-      sym_operator,[m
[31m-    ACTIONS(81), 16,[m
 r, 3),[m
  [769] = {.en[m
\ No newline at end of file[m
 try = {.count = 1, .r[m
\ No newline at end of file[m
 eusable = true}}, SHI[m
\ No newline at end of file[m
[36m@@ -2574,50 +7560,58 @@[m [mstatic uint16_t ts_small_parse_table[] = {[m
 7] = {.entry = {.co[m
\ No newline at end of file[m
 unt = 1, .reusable = t[m
\ No newline at end of file[m
 rue}}, SHIFT(185),[m
  [[m
\ No newline at end of file[m
[31m-  [150] = 15,[m
[31m-    ACTIONS(52), 1,[m
[32m+[m[32m779] = {.entry[m
\ No newline at end of file[m
[32m+[m[32m = {.count = 1, .reu[m
\ No newline at end of file[m
 sable = true}}, SHI[m
\ No newline at end of file[m
[31m-    ACTIONS(59), 1,[m
[32m+[m[32mFT(62),[m
  [781] = {.en[m
\ No newline at end of file[m
 try = {.count = 1, .reu[m
\ No newline at end of file[m
[31m-    ACTIONS(63), 1,[m
[32m+[m[32msable = true}}, SHIFT[m
\ No newline at end of file[m
 (263),[m
};[m

#ifdef __cplusp[m
\ No newline at end of file[m
[31m-    ACTIONS(65), 1,[m
 lus[m
extern "C" {[m
#endif[m
\ No newline at end of file[m
[31m-    ACTIONS(67), 1,[m
 [m
#ifdef _WIN32[m
#define [m
\ No newline at end of file[m
[31m-    ACTIONS(69), 1,[m
 extern __declspec(dllex[m
\ No newline at end of file[m
[31m-    ACTIONS(73), 1,[m
[32m+[m[32mport)[m
#endif[m

extern const TSLan[m
\ No newline at end of file[m
[32m+[m[32mguage *tree_sitter_nu(void) {[m
  [m
\ No newline at end of file[m
 static TSLanguage language = {[m
\ No newline at end of file[m
[31m-    ACTIONS(75), 1,[m
 [m
    .version = LANGUA[m
\ No newline at end of file[m
[31m-    ACTIONS(77), 1,[m
[32m+[m[32mGE_VERSION,[m
    .symb[m
\ No newline at end of file[m
 ol_count = SYMBOL_COUNT[m
\ No newline at end of file[m
[31m-    ACTIONS(85), 1,[m
[32m+[m[32m,[m
    .alias_count = AL[m
\ No newline at end of file[m
 IAS_COUNT,[m
    .tok[m
\ No newline at end of file[m
[31m-    STATE(2), 1,[m
[31m-      aux_sym_command_repeat1,[m
[31m-    ACTIONS(71), 2,[m
[32m+[m[32men_count = TOKEN_COUN[m
\ No newline at end of file[m
[32m+[m[32mT,[m
    .external_toke[m
\ No newline at end of file[m
[32m+[m[32mn_count = EXTERNAL_TO[m
\ No newline at end of file[m
[32m+[m[32mKEN_COUNT,[m
    .state_[m
\ No newline at end of file[m
[32m+[m[32mcount = STATE_COUNT,[m
   [m
\ No newline at end of file[m
[32m+[m[32m .large_state_count = LARG[m
\ No newline at end of file[m
[32m+[m[32mE_STATE_COUNT,[m
    .prod[m
\ No newline at end of file[m
[32m+[m[32muction_id_count = PRODUCT[m
\ No newline at end of file[m
[32m+[m[32mION_ID_COUNT,[m
    .fie[m
\ No newline at end of file[m
[32m+[m[32mld_count = FIELD_COUNT,[m
[32m+[m[32m    .max_alias_sequ[m
\ No newline at end of file[m
[32m+[m[32mence_length = MAX_ALIA[m
\ No newline at end of file[m
[32m+[m[32mS_SEQUENCE_LENGTH,[m
   [m
\ No newline at end of file[m
[32m+[m[32m .parse_table = (co[m
\ No newline at end of file[m
[32m+[m[32mnst uint16_t *)ts_pars[m
\ No newline at end of file[m
[32m+[m[32me_table,[m
    .small_pa[m
\ No newline at end of file[m
[32m+[m[32mrse_table = (c[m
\ No newline at end of file[m
[32m+[m[32monst uint16_t *)ts_s[m
\ No newline at end of file[m
[32m+[m[32mmall_parse_table,[m
 [m
\ No newline at end of file[m
[32m+[m[32m   .small_parse_table_[m
\ No newline at end of file[m
[32m+[m[32mmap = (const uint32_t *[m
\ No newline at end of file[m
[32m+[m[32m)ts_small_parse_table[m
\ No newline at end of file[m
[32m+[m[32m_map,[m
    .parse_actions =[m
\ No newline at end of file[m
[32m+[m[32m ts_parse_actions,[m
    [m
\ No newline at end of file[m
[32m+[m[32m.symbol_names = ts_symb[m
\ No newline at end of file[m
[32m+[m[32mol_names,[m
    .field_na[m
\ No newline at end of file[m
 mes = ts_field_names,[m
    .field[m
\ No newline at end of file[m
 _map_slices = (const TSFieldMapS[m
\ No newline at end of file[m
[31m-    ACTIONS(83), 4,[m
[31m-      anon_sym_RPAREN,[m
[31m-      anon_sym_PIPE,[m
[32m+[m[32mlice *)ts_field_map_slices,[m
  [m
\ No newline at end of file[m
[32m+[m[32m  .field_map_entries =[m
\ No newline at end of file[m
  (const TSFieldMapEnt[m
\ No newline at end of file[m
[32m+[m[32mry *)ts_field_map_entri[m
\ No newline at end of file[m
 es,[m
    .symbol_metadat[m
\ No newline at end of file[m
[31m-    STATE(46), 11,[m
[31m-      sym__expression,[m
[31m-      sym_string,[m
[31m-      sym_value_path,[m
[31m-      sym_file_path,[m
[31m-      sym_range,[m
[31m-      sym_command_substitution,[m
[31m-      sym_math_mode,[m
[31m-      sym_table,[m
[31m-      sym_array,[m
[31m-      sym_block,[m
[31m-      sym_operator,[m
[31m-    ACTIONS(81), 16,[m
[32m+[m[32ma = ts_symbol_metad[m
\ No newline at end of file[m
 ata,[m
    .public_symb[m
\ No newline at end of file[m
 ol_map = ts_symbol_ma[m
\ No newline at end of file[m
 p,[m
    .alias_map = t[m
\ No newline at end of file[m
[36m@@ -2634,49 +7628,25 @@[m [mstatic uint16_t ts_small_parse_table[] = {[m
 n &language;[m
}[m
#ifd[m
\ No newline at end of file[m
 ef __cplusplus[m
}[m
#endi[m
\ No newline at end of file[m
 f[m
                    [m
\ No newline at end of file[m
[31m-  [225] = 15,[m
[31m-    ACTIONS(52), 1,[m
[32m+[m[32m              [m
\ No newline at end of file[m
[32m+[m[32m                    [m
\ No newline at end of file[m
                    [m
\ No newline at end of file[m
[31m-    ACTIONS(87), 1,[m
[32m+[m[32m                     [m
\ No newline at end of file[m
[32m+[m[32m                        [m
\ No newline at end of file[m
[32m+[m[32m                      [m
\ No newline at end of file[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(89), 1,[m
[32m+[m[32m                     [m
\ No newline at end of file[m
                           [m
\ No newline at end of file[m
[31m-    ACTIONS(91), 1,[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(93), 1,[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(95), 1,[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(99), 1,[m
[32m+[m[32m                                [m
\ No newline at end of file[m
[32m+[m[32m                                [m
\ No newline at end of file[m
                               [m
\ No newline at end of file[m
[31m-    ACTIONS(101), 1,[m
                       [m
\ No newline at end of file[m
[31m-    ACTIONS(103), 1,[m
[31m-      anon_sym_LBRACE,[m
[31m-    STATE(7), 1,[m
[31m-      aux_sym_command_repeat1,[m
[31m-    ACTIONS(83), 2,[m
[31m-      anon_sym_PIPE,[m
                      [m
\ No newline at end of file[m
[31m-    ACTIONS(85), 2,[m
[31m-      ts_builtin_sym_end,[m
[32m+[m[32m                       [m
\ No newline at end of file[m
                    [m
\ No newline at end of file[m
[31m-    ACTIONS(97), 2,[m
[31m-      aux_sym_file_path_token1,[m
[31m-      aux_sym_file_path_token2,[m
[31m-    STATE(56), 11,[m
[31m-      sym__expression,[m
[31m-      sym_string,[m
[31m-      sym_value_path,[m
[31m-      sym_file_path,[m
[31m-      sym_range,[m
[31m-      sym_command_substitution,[m
[31m-      sym_math_mode,[m
[31m-      sym_table,[m
[31m-      sym_array,[m
[31m-      sym_block,[m
[31m-      sym_operator,[m
[31m-    ACTIONS(105), 16,[m
                      [m
\ No newline at end of file[m
                      [m
\ No newline at end of file[m
                      [m
\ No newline at end of file[m
[36m@@ -2693,49 +7663,24 @@[m [mstatic uint16_t ts_small_parse_table[] = {[m
                    [m
\ No newline at end of file[m
                       [m
\ No newline at end of file[m
                       [m
\ No newline at end of file[m
[31m-  [299] = 15,[m
[31m-    ACTIONS(52), 1,[m
[32m+[m[32m              [m
\ No newline at end of file[m
[32m+[m[32m                    [m
\ No newline at end of file[m
                    [m
\ No newline at end of file[m
[31m-    ACTIONS(87), 1,[m
[32m+[m[32m                      [m
\ No newline at end of file[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(89), 1,[m
[32m+[m[32m                     [m
\ No newline at end of file[m
                           [m
\ No newline at end of file[m
[31m-    ACTIONS(91), 1,[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(93), 1,[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(95), 1,[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(99), 1,[m
[32m+[m[32m                                [m
\ No newline at end of file[m
[32m+[m[32m                                [m
\ No newline at end of file[m
                               [m
\ No newline at end of file[m
[31m-    ACTIONS(101), 1,[m
                       [m
\ No newline at end of file[m
[31m-    ACTIONS(103), 1,[m
[31m-      anon_sym_LBRACE,[m
[31m-    STATE(5), 1,[m
[31m-      aux_sym_command_repeat1,[m
[31m-    ACTIONS(61), 2,[m
[31m-      anon_sym_PIPE,[m
                      [m
\ No newline at end of file[m
[31m-    ACTIONS(79), 2,[m
[31m-      ts_builtin_sym_end,[m
[32m+[m[32m                       [m
\ No newline at end of file[m
[32m+[m[32m                       [m
\ No newline at end of file[m
                    [m
\ No newline at end of file[m
[31m-    ACTIONS(97), 2,[m
[31m-      aux_sym_file_path_token1,[m
[31m-      aux_sym_file_path_token2,[m
[31m-    STATE(56), 11,[m
[31m-      sym__expression,[m
[31m-      sym_string,[m
[31m-      sym_value_path,[m
[31m-      sym_file_path,[m
[31m-      sym_range,[m
[31m-      sym_command_substitution,[m
[31m-      sym_math_mode,[m
[31m-      sym_table,[m
[31m-      sym_array,[m
[31m-      sym_block,[m
[31m-      sym_operator,[m
[31m-    ACTIONS(105), 16,[m
                      [m
\ No newline at end of file[m
                      [m
\ No newline at end of file[m
                      [m
\ No newline at end of file[m
[36m@@ -2752,49 +7697,24 @@[m [mstatic uint16_t ts_small_parse_table[] = {[m
                    [m
\ No newline at end of file[m
                       [m
\ No newline at end of file[m
                       [m
\ No newline at end of file[m
[31m-  [373] = 15,[m
[31m-    ACTIONS(52), 1,[m
[32m+[m[32m              [m
\ No newline at end of file[m
[32m+[m[32m                    [m
\ No newline at end of file[m
                    [m
\ No newline at end of file[m
[31m-    ACTIONS(107), 1,[m
[32m+[m[32m                      [m
\ No newline at end of file[m
                        [m
\ No newline at end of file[m
[31m-    ACTIONS(110), 1,[m
[32m+[m[32m                     [m
\ No newline at end of file[m
                           [m
\ No newline at end of file[m
[31m-    ACTIO