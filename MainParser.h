
// Generated from Main.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  MainParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, TYPE = 44, 
    INT = 45, VAR = 46, CHAR = 47, CHARESC = 48, STR = 49, WS = 50
  };

  enum {
    RuleProg = 0, RuleFunct = 1, RuleExpr = 2, RuleCompare = 3, RuleElemlv = 4, 
    RuleElemrv = 5, RuleIfins = 6, RuleElseifins = 7, RuleElseins = 8, RuleWhileins = 9, 
    RuleForins = 10, RuleDeclarvar = 11, RuleDeclararray = 12, RuleDefvar = 13, 
    RuleDeffunc = 14, RuleDeclarfunc = 15, RuleExecfunc = 16, RuleBlock = 17, 
    RuleExprstat = 18, RuleStatement = 19, RuleRet = 20, RuleParamdec = 21, 
    RuleParam = 22
  };

  MainParser(antlr4::TokenStream *input);
  ~MainParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class FunctContext;
  class ExprContext;
  class CompareContext;
  class ElemlvContext;
  class ElemrvContext;
  class IfinsContext;
  class ElseifinsContext;
  class ElseinsContext;
  class WhileinsContext;
  class ForinsContext;
  class DeclarvarContext;
  class DeclararrayContext;
  class DefvarContext;
  class DeffuncContext;
  class DeclarfuncContext;
  class ExecfuncContext;
  class BlockContext;
  class ExprstatContext;
  class StatementContext;
  class RetContext;
  class ParamdecContext;
  class ParamContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunctContext *> funct();
    FunctContext* funct(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  FunctContext : public antlr4::ParserRuleContext {
  public:
    FunctContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeffuncContext *deffunc();
    DeclarfuncContext *declarfunc();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctContext* funct();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParContext : public ExprContext {
  public:
    ParContext(ExprContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultdivmodContext : public ExprContext {
  public:
    MultdivmodContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstContext : public ExprContext {
  public:
    ConstContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SizeofContext : public ExprContext {
  public:
    SizeofContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *VAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarContext : public ExprContext {
  public:
    VarContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CmpContext : public ExprContext {
  public:
    CmpContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    CompareContext *compare();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprBinContext : public ExprContext {
  public:
    ExprBinContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddsubContext : public ExprContext {
  public:
    AddsubContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ElemarrayContext : public ExprContext {
  public:
    ElemarrayContext(ExprContext *ctx);

    ElemrvContext *elemrv();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OuExBinContext : public ExprContext {
  public:
    OuExBinContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PostopContext : public ExprContext {
  public:
    PostopContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExfuncContext : public ExprContext {
  public:
    ExfuncContext(ExprContext *ctx);

    ExecfuncContext *execfunc();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OuBinContext : public ExprContext {
  public:
    OuBinContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignementContext : public ExprContext {
  public:
    AssignementContext(ExprContext *ctx);

    ExprContext *expr();
    antlr4::tree::TerminalNode *VAR();
    ElemlvContext *elemlv();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharContext : public ExprContext {
  public:
    CharContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *CHAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PreopContext : public ExprContext {
  public:
    PreopContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EtBinContext : public ExprContext {
  public:
    EtBinContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  CompareContext : public antlr4::ParserRuleContext {
  public:
    CompareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompareContext* compare();

  class  ElemlvContext : public antlr4::ParserRuleContext {
  public:
    ElemlvContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElemlvContext* elemlv();

  class  ElemrvContext : public antlr4::ParserRuleContext {
  public:
    ElemrvContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElemrvContext* elemrv();

  class  IfinsContext : public antlr4::ParserRuleContext {
  public:
    IfinsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    StatementContext *statement();
    BlockContext *block();
    std::vector<ElseifinsContext *> elseifins();
    ElseifinsContext* elseifins(size_t i);
    ElseinsContext *elseins();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfinsContext* ifins();

  class  ElseifinsContext : public antlr4::ParserRuleContext {
  public:
    ElseifinsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    StatementContext *statement();
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElseifinsContext* elseifins();

  class  ElseinsContext : public antlr4::ParserRuleContext {
  public:
    ElseinsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElseinsContext* elseins();

  class  WhileinsContext : public antlr4::ParserRuleContext {
  public:
    WhileinsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    StatementContext *statement();
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileinsContext* whileins();

  class  ForinsContext : public antlr4::ParserRuleContext {
  public:
    ForinsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    BlockContext *block();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForinsContext* forins();

  class  DeclarvarContext : public antlr4::ParserRuleContext {
  public:
    DeclarvarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarvarContext* declarvar();

  class  DeclararrayContext : public antlr4::ParserRuleContext {
  public:
    DeclararrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclararrayContext* declararray();

  class  DefvarContext : public antlr4::ParserRuleContext {
  public:
    DefvarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DefvarContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DefvarContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DefWithDeclarContext : public DefvarContext {
  public:
    DefWithDeclarContext(DefvarContext *ctx);

    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *VAR();
    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DefvarContext* defvar();

  class  DeffuncContext : public antlr4::ParserRuleContext {
  public:
    DeffuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeffuncContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DeffuncContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DefFuncVoidContext : public DeffuncContext {
  public:
    DefFuncVoidContext(DeffuncContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    BlockContext *block();
    ParamdecContext *paramdec();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DefFuncNormalContext : public DeffuncContext {
  public:
    DefFuncNormalContext(DeffuncContext *ctx);

    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *VAR();
    BlockContext *block();
    ParamdecContext *paramdec();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeffuncContext* deffunc();

  class  DeclarfuncContext : public antlr4::ParserRuleContext {
  public:
    DeclarfuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeclarfuncContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DeclarfuncContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DeclarFuncNormalContext : public DeclarfuncContext {
  public:
    DeclarFuncNormalContext(DeclarfuncContext *ctx);

    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *VAR();
    ParamdecContext *paramdec();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclarFuncVoidContext : public DeclarfuncContext {
  public:
    DeclarFuncVoidContext(DeclarfuncContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    ParamdecContext *paramdec();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclarfuncContext* declarfunc();

  class  ExecfuncContext : public antlr4::ParserRuleContext {
  public:
    ExecfuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExecfuncContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExecfuncContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  GetcharContext : public ExecfuncContext {
  public:
    GetcharContext(ExecfuncContext *ctx);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PutcharContext : public ExecfuncContext {
  public:
    PutcharContext(ExecfuncContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NormalExecContext : public ExecfuncContext {
  public:
    NormalExecContext(ExecfuncContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    ParamContext *param();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrintfContext : public ExecfuncContext {
  public:
    PrintfContext(ExecfuncContext *ctx);

    antlr4::tree::TerminalNode *STR();
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExecfuncContext* execfunc();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  ExprstatContext : public antlr4::ParserRuleContext {
  public:
    ExprstatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprstatContext* exprstat();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RetContext *ret();
    DefvarContext *defvar();
    ExprstatContext *exprstat();
    DeclarvarContext *declarvar();
    DeclararrayContext *declararray();
    IfinsContext *ifins();
    WhileinsContext *whileins();
    ForinsContext *forins();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetContext* ret();

  class  ParamdecContext : public antlr4::ParserRuleContext {
  public:
    ParamdecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> TYPE();
    antlr4::tree::TerminalNode* TYPE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamdecContext* paramdec();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

