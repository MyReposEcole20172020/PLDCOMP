
// Generated from Main.g4 by ANTLR 4.7.1


#include "MainVisitor.h"

#include "MainParser.h"


using namespace antlrcpp;
using namespace antlr4;

MainParser::MainParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MainParser::~MainParser() {
  delete _interpreter;
}

std::string MainParser::getGrammarFileName() const {
  return "Main.g4";
}

const std::vector<std::string>& MainParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MainParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

MainParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MainParser::FunctContext *> MainParser::ProgContext::funct() {
  return getRuleContexts<MainParser::FunctContext>();
}

MainParser::FunctContext* MainParser::ProgContext::funct(size_t i) {
  return getRuleContext<MainParser::FunctContext>(i);
}


size_t MainParser::ProgContext::getRuleIndex() const {
  return MainParser::RuleProg;
}

antlrcpp::Any MainParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ProgContext* MainParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MainParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MainParser::T__36

    || _la == MainParser::TYPE) {
      setState(46);
      funct();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctContext ------------------------------------------------------------------

MainParser::FunctContext::FunctContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::DeffuncContext* MainParser::FunctContext::deffunc() {
  return getRuleContext<MainParser::DeffuncContext>(0);
}

MainParser::DeclarfuncContext* MainParser::FunctContext::declarfunc() {
  return getRuleContext<MainParser::DeclarfuncContext>(0);
}


size_t MainParser::FunctContext::getRuleIndex() const {
  return MainParser::RuleFunct;
}

antlrcpp::Any MainParser::FunctContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitFunct(this);
  else
    return visitor->visitChildren(this);
}

MainParser::FunctContext* MainParser::funct() {
  FunctContext *_localctx = _tracker.createInstance<FunctContext>(_ctx, getState());
  enterRule(_localctx, 2, MainParser::RuleFunct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(54);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(52);
      deffunc();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(53);
      declarfunc();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MainParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MainParser::ExprContext::getRuleIndex() const {
  return MainParser::RuleExpr;
}

void MainParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParContext ------------------------------------------------------------------

MainParser::ExprContext* MainParser::ParContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::ParContext::ParContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::ParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultdivmodContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::MultdivmodContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::MultdivmodContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::MultdivmodContext::MultdivmodContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::MultdivmodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitMultdivmod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::ConstContext::INT() {
  return getToken(MainParser::INT, 0);
}

MainParser::ConstContext::ConstContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::ConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SizeofContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::SizeofContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

tree::TerminalNode* MainParser::SizeofContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::SizeofContext::SizeofContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::SizeofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitSizeof(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::VarContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::VarContext::VarContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CmpContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::CmpContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::CmpContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::CompareContext* MainParser::CmpContext::compare() {
  return getRuleContext<MainParser::CompareContext>(0);
}

MainParser::CmpContext::CmpContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::CmpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitCmp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBinContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::ExprBinContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::ExprBinContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::ExprBinContext::ExprBinContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::ExprBinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitExprBin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddsubContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::AddsubContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::AddsubContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::AddsubContext::AddsubContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::AddsubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitAddsub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ElemarrayContext ------------------------------------------------------------------

MainParser::ElemrvContext* MainParser::ElemarrayContext::elemrv() {
  return getRuleContext<MainParser::ElemrvContext>(0);
}

MainParser::ElemarrayContext::ElemarrayContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::ElemarrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitElemarray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OuExBinContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::OuExBinContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::OuExBinContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::OuExBinContext::OuExBinContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::OuExBinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitOuExBin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostopContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::PostopContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::PostopContext::PostopContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::PostopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitPostop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExfuncContext ------------------------------------------------------------------

MainParser::ExecfuncContext* MainParser::ExfuncContext::execfunc() {
  return getRuleContext<MainParser::ExecfuncContext>(0);
}

MainParser::ExfuncContext::ExfuncContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::ExfuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitExfunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OuBinContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::OuBinContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::OuBinContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::OuBinContext::OuBinContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::OuBinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitOuBin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignementContext ------------------------------------------------------------------

MainParser::ExprContext* MainParser::AssignementContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

tree::TerminalNode* MainParser::AssignementContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ElemlvContext* MainParser::AssignementContext::elemlv() {
  return getRuleContext<MainParser::ElemlvContext>(0);
}

MainParser::AssignementContext::AssignementContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::AssignementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitAssignement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::CharContext::CHAR() {
  return getToken(MainParser::CHAR, 0);
}

MainParser::CharContext::CharContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::CharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreopContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::PreopContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::PreopContext::PreopContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::PreopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitPreop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EtBinContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::EtBinContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::EtBinContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::EtBinContext::EtBinContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::EtBinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitEtBin(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ExprContext* MainParser::expr() {
   return expr(0);
}

MainParser::ExprContext* MainParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MainParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MainParser::ExprContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, MainParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExfuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(57);
      execfunc();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ElemarrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(58);
      elemrv();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SizeofContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(59);
      match(MainParser::T__0);
      setState(60);
      match(MainParser::T__1);
      setState(61);
      _la = _input->LA(1);
      if (!(_la == MainParser::TYPE

      || _la == MainParser::VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(62);
      match(MainParser::T__2);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<PostopContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(63);
      match(MainParser::VAR);
      setState(64);
      _la = _input->LA(1);
      if (!(_la == MainParser::T__3

      || _la == MainParser::T__4)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<PreopContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(65);
      _la = _input->LA(1);
      if (!(_la == MainParser::T__3

      || _la == MainParser::T__4)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(66);
      match(MainParser::VAR);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ConstContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(67);
      match(MainParser::INT);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<VarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(68);
      match(MainParser::VAR);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CharContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(69);
      match(MainParser::CHAR);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ParContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(70);
      match(MainParser::T__1);
      setState(71);
      expr(0);
      setState(72);
      match(MainParser::T__2);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<AssignementContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(76);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(74);
        match(MainParser::VAR);
        break;
      }

      case 2: {
        setState(75);
        elemlv();
        break;
      }

      }
      setState(78);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MainParser::T__15)
        | (1ULL << MainParser::T__16)
        | (1ULL << MainParser::T__17)
        | (1ULL << MainParser::T__18)
        | (1ULL << MainParser::T__19)
        | (1ULL << MainParser::T__20)
        | (1ULL << MainParser::T__21)
        | (1ULL << MainParser::T__22)
        | (1ULL << MainParser::T__23))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(79);
      expr(1);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(106);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(104);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultdivmodContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(82);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(83);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MainParser::T__5)
            | (1ULL << MainParser::T__6)
            | (1ULL << MainParser::T__7))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(84);
          expr(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddsubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(85);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(86);
          _la = _input->LA(1);
          if (!(_la == MainParser::T__8

          || _la == MainParser::T__9)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(87);
          expr(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<EtBinContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(88);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(89);
          match(MainParser::T__10);
          setState(90);
          expr(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<OuExBinContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(91);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(92);
          match(MainParser::T__11);
          setState(93);
          expr(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<OuBinContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(94);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(95);
          match(MainParser::T__12);
          setState(96);
          expr(5);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprBinContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(97);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(98);
          _la = _input->LA(1);
          if (!(_la == MainParser::T__13

          || _la == MainParser::T__14)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(99);
          expr(4);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<CmpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(100);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(101);
          compare();
          setState(102);
          expr(3);
          break;
        }

        } 
      }
      setState(108);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- CompareContext ------------------------------------------------------------------

MainParser::CompareContext::CompareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MainParser::CompareContext::getRuleIndex() const {
  return MainParser::RuleCompare;
}

antlrcpp::Any MainParser::CompareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitCompare(this);
  else
    return visitor->visitChildren(this);
}

MainParser::CompareContext* MainParser::compare() {
  CompareContext *_localctx = _tracker.createInstance<CompareContext>(_ctx, getState());
  enterRule(_localctx, 6, MainParser::RuleCompare);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::T__24:
      case MainParser::T__25: {
        enterOuterAlt(_localctx, 1);
        setState(109);
        _la = _input->LA(1);
        if (!(_la == MainParser::T__24

        || _la == MainParser::T__25)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(111);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MainParser::T__23) {
          setState(110);
          match(MainParser::T__23);
        }
        break;
      }

      case MainParser::T__23:
      case MainParser::T__26: {
        enterOuterAlt(_localctx, 2);
        setState(113);
        _la = _input->LA(1);
        if (!(_la == MainParser::T__23

        || _la == MainParser::T__26)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(114);
        match(MainParser::T__23);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElemlvContext ------------------------------------------------------------------

MainParser::ElemlvContext::ElemlvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MainParser::ElemlvContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ExprContext* MainParser::ElemlvContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}


size_t MainParser::ElemlvContext::getRuleIndex() const {
  return MainParser::RuleElemlv;
}

antlrcpp::Any MainParser::ElemlvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitElemlv(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ElemlvContext* MainParser::elemlv() {
  ElemlvContext *_localctx = _tracker.createInstance<ElemlvContext>(_ctx, getState());
  enterRule(_localctx, 8, MainParser::RuleElemlv);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(MainParser::VAR);
    setState(118);
    match(MainParser::T__27);
    setState(119);
    expr(0);
    setState(120);
    match(MainParser::T__28);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElemrvContext ------------------------------------------------------------------

MainParser::ElemrvContext::ElemrvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MainParser::ElemrvContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ExprContext* MainParser::ElemrvContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}


size_t MainParser::ElemrvContext::getRuleIndex() const {
  return MainParser::RuleElemrv;
}

antlrcpp::Any MainParser::ElemrvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitElemrv(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ElemrvContext* MainParser::elemrv() {
  ElemrvContext *_localctx = _tracker.createInstance<ElemrvContext>(_ctx, getState());
  enterRule(_localctx, 10, MainParser::RuleElemrv);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(MainParser::VAR);
    setState(123);
    match(MainParser::T__27);
    setState(124);
    expr(0);
    setState(125);
    match(MainParser::T__28);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfinsContext ------------------------------------------------------------------

MainParser::IfinsContext::IfinsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::ExprContext* MainParser::IfinsContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::StatementContext* MainParser::IfinsContext::statement() {
  return getRuleContext<MainParser::StatementContext>(0);
}

MainParser::BlockContext* MainParser::IfinsContext::block() {
  return getRuleContext<MainParser::BlockContext>(0);
}

std::vector<MainParser::ElseifinsContext *> MainParser::IfinsContext::elseifins() {
  return getRuleContexts<MainParser::ElseifinsContext>();
}

MainParser::ElseifinsContext* MainParser::IfinsContext::elseifins(size_t i) {
  return getRuleContext<MainParser::ElseifinsContext>(i);
}

MainParser::ElseinsContext* MainParser::IfinsContext::elseins() {
  return getRuleContext<MainParser::ElseinsContext>(0);
}


size_t MainParser::IfinsContext::getRuleIndex() const {
  return MainParser::RuleIfins;
}

antlrcpp::Any MainParser::IfinsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitIfins(this);
  else
    return visitor->visitChildren(this);
}

MainParser::IfinsContext* MainParser::ifins() {
  IfinsContext *_localctx = _tracker.createInstance<IfinsContext>(_ctx, getState());
  enterRule(_localctx, 12, MainParser::RuleIfins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(MainParser::T__29);
    setState(128);
    match(MainParser::T__1);
    setState(129);
    expr(0);
    setState(130);
    match(MainParser::T__2);
    setState(133);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::T__0:
      case MainParser::T__1:
      case MainParser::T__3:
      case MainParser::T__4:
      case MainParser::T__29:
      case MainParser::T__32:
      case MainParser::T__33:
      case MainParser::T__37:
      case MainParser::T__38:
      case MainParser::T__39:
      case MainParser::T__42:
      case MainParser::TYPE:
      case MainParser::INT:
      case MainParser::VAR:
      case MainParser::CHAR: {
        setState(131);
        statement();
        break;
      }

      case MainParser::T__40: {
        setState(132);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(138);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(135);
        elseifins(); 
      }
      setState(140);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(142);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(141);
      elseins();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseifinsContext ------------------------------------------------------------------

MainParser::ElseifinsContext::ElseifinsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::ExprContext* MainParser::ElseifinsContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::StatementContext* MainParser::ElseifinsContext::statement() {
  return getRuleContext<MainParser::StatementContext>(0);
}

MainParser::BlockContext* MainParser::ElseifinsContext::block() {
  return getRuleContext<MainParser::BlockContext>(0);
}


size_t MainParser::ElseifinsContext::getRuleIndex() const {
  return MainParser::RuleElseifins;
}

antlrcpp::Any MainParser::ElseifinsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitElseifins(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ElseifinsContext* MainParser::elseifins() {
  ElseifinsContext *_localctx = _tracker.createInstance<ElseifinsContext>(_ctx, getState());
  enterRule(_localctx, 14, MainParser::RuleElseifins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(MainParser::T__30);
    setState(145);
    match(MainParser::T__1);
    setState(146);
    expr(0);
    setState(147);
    match(MainParser::T__2);
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::T__0:
      case MainParser::T__1:
      case MainParser::T__3:
      case MainParser::T__4:
      case MainParser::T__29:
      case MainParser::T__32:
      case MainParser::T__33:
      case MainParser::T__37:
      case MainParser::T__38:
      case MainParser::T__39:
      case MainParser::T__42:
      case MainParser::TYPE:
      case MainParser::INT:
      case MainParser::VAR:
      case MainParser::CHAR: {
        setState(148);
        statement();
        break;
      }

      case MainParser::T__40: {
        setState(149);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseinsContext ------------------------------------------------------------------

MainParser::ElseinsContext::ElseinsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::StatementContext* MainParser::ElseinsContext::statement() {
  return getRuleContext<MainParser::StatementContext>(0);
}

MainParser::BlockContext* MainParser::ElseinsContext::block() {
  return getRuleContext<MainParser::BlockContext>(0);
}


size_t MainParser::ElseinsContext::getRuleIndex() const {
  return MainParser::RuleElseins;
}

antlrcpp::Any MainParser::ElseinsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitElseins(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ElseinsContext* MainParser::elseins() {
  ElseinsContext *_localctx = _tracker.createInstance<ElseinsContext>(_ctx, getState());
  enterRule(_localctx, 16, MainParser::RuleElseins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    match(MainParser::T__31);
    setState(155);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::T__0:
      case MainParser::T__1:
      case MainParser::T__3:
      case MainParser::T__4:
      case MainParser::T__29:
      case MainParser::T__32:
      case MainParser::T__33:
      case MainParser::T__37:
      case MainParser::T__38:
      case MainParser::T__39:
      case MainParser::T__42:
      case MainParser::TYPE:
      case MainParser::INT:
      case MainParser::VAR:
      case MainParser::CHAR: {
        setState(153);
        statement();
        break;
      }

      case MainParser::T__40: {
        setState(154);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileinsContext ------------------------------------------------------------------

MainParser::WhileinsContext::WhileinsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::ExprContext* MainParser::WhileinsContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::StatementContext* MainParser::WhileinsContext::statement() {
  return getRuleContext<MainParser::StatementContext>(0);
}

MainParser::BlockContext* MainParser::WhileinsContext::block() {
  return getRuleContext<MainParser::BlockContext>(0);
}


size_t MainParser::WhileinsContext::getRuleIndex() const {
  return MainParser::RuleWhileins;
}

antlrcpp::Any MainParser::WhileinsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitWhileins(this);
  else
    return visitor->visitChildren(this);
}

MainParser::WhileinsContext* MainParser::whileins() {
  WhileinsContext *_localctx = _tracker.createInstance<WhileinsContext>(_ctx, getState());
  enterRule(_localctx, 18, MainParser::RuleWhileins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(MainParser::T__32);
    setState(158);
    match(MainParser::T__1);
    setState(159);
    expr(0);
    setState(160);
    match(MainParser::T__2);
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::T__0:
      case MainParser::T__1:
      case MainParser::T__3:
      case MainParser::T__4:
      case MainParser::T__29:
      case MainParser::T__32:
      case MainParser::T__33:
      case MainParser::T__37:
      case MainParser::T__38:
      case MainParser::T__39:
      case MainParser::T__42:
      case MainParser::TYPE:
      case MainParser::INT:
      case MainParser::VAR:
      case MainParser::CHAR: {
        setState(161);
        statement();
        break;
      }

      case MainParser::T__40: {
        setState(162);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForinsContext ------------------------------------------------------------------

MainParser::ForinsContext::ForinsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::StatementContext* MainParser::ForinsContext::statement() {
  return getRuleContext<MainParser::StatementContext>(0);
}

MainParser::BlockContext* MainParser::ForinsContext::block() {
  return getRuleContext<MainParser::BlockContext>(0);
}

std::vector<MainParser::ExprContext *> MainParser::ForinsContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::ForinsContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}


size_t MainParser::ForinsContext::getRuleIndex() const {
  return MainParser::RuleForins;
}

antlrcpp::Any MainParser::ForinsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitForins(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ForinsContext* MainParser::forins() {
  ForinsContext *_localctx = _tracker.createInstance<ForinsContext>(_ctx, getState());
  enterRule(_localctx, 20, MainParser::RuleForins);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(MainParser::T__33);
    setState(166);
    match(MainParser::T__1);
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MainParser::T__0)
      | (1ULL << MainParser::T__1)
      | (1ULL << MainParser::T__3)
      | (1ULL << MainParser::T__4)
      | (1ULL << MainParser::T__37)
      | (1ULL << MainParser::T__38)
      | (1ULL << MainParser::T__39)
      | (1ULL << MainParser::INT)
      | (1ULL << MainParser::VAR)
      | (1ULL << MainParser::CHAR))) != 0)) {
      setState(167);
      expr(0);
    }
    setState(170);
    match(MainParser::T__34);
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MainParser::T__0)
      | (1ULL << MainParser::T__1)
      | (1ULL << MainParser::T__3)
      | (1ULL << MainParser::T__4)
      | (1ULL << MainParser::T__37)
      | (1ULL << MainParser::T__38)
      | (1ULL << MainParser::T__39)
      | (1ULL << MainParser::INT)
      | (1ULL << MainParser::VAR)
      | (1ULL << MainParser::CHAR))) != 0)) {
      setState(171);
      expr(0);
    }
    setState(174);
    match(MainParser::T__34);
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MainParser::T__0)
      | (1ULL << MainParser::T__1)
      | (1ULL << MainParser::T__3)
      | (1ULL << MainParser::T__4)
      | (1ULL << MainParser::T__37)
      | (1ULL << MainParser::T__38)
      | (1ULL << MainParser::T__39)
      | (1ULL << MainParser::INT)
      | (1ULL << MainParser::VAR)
      | (1ULL << MainParser::CHAR))) != 0)) {
      setState(175);
      expr(0);
    }
    setState(178);
    match(MainParser::T__2);
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::T__0:
      case MainParser::T__1:
      case MainParser::T__3:
      case MainParser::T__4:
      case MainParser::T__29:
      case MainParser::T__32:
      case MainParser::T__33:
      case MainParser::T__37:
      case MainParser::T__38:
      case MainParser::T__39:
      case MainParser::T__42:
      case MainParser::TYPE:
      case MainParser::INT:
      case MainParser::VAR:
      case MainParser::CHAR: {
        setState(179);
        statement();
        break;
      }

      case MainParser::T__40: {
        setState(180);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarvarContext ------------------------------------------------------------------

MainParser::DeclarvarContext::DeclarvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MainParser::DeclarvarContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

std::vector<tree::TerminalNode *> MainParser::DeclarvarContext::VAR() {
  return getTokens(MainParser::VAR);
}

tree::TerminalNode* MainParser::DeclarvarContext::VAR(size_t i) {
  return getToken(MainParser::VAR, i);
}


size_t MainParser::DeclarvarContext::getRuleIndex() const {
  return MainParser::RuleDeclarvar;
}

antlrcpp::Any MainParser::DeclarvarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDeclarvar(this);
  else
    return visitor->visitChildren(this);
}

MainParser::DeclarvarContext* MainParser::declarvar() {
  DeclarvarContext *_localctx = _tracker.createInstance<DeclarvarContext>(_ctx, getState());
  enterRule(_localctx, 22, MainParser::RuleDeclarvar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(MainParser::TYPE);
    setState(184);
    match(MainParser::VAR);
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MainParser::T__35) {
      setState(185);
      match(MainParser::T__35);
      setState(186);
      match(MainParser::VAR);
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(192);
    match(MainParser::T__34);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclararrayContext ------------------------------------------------------------------

MainParser::DeclararrayContext::DeclararrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MainParser::DeclararrayContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

tree::TerminalNode* MainParser::DeclararrayContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

tree::TerminalNode* MainParser::DeclararrayContext::INT() {
  return getToken(MainParser::INT, 0);
}


size_t MainParser::DeclararrayContext::getRuleIndex() const {
  return MainParser::RuleDeclararray;
}

antlrcpp::Any MainParser::DeclararrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDeclararray(this);
  else
    return visitor->visitChildren(this);
}

MainParser::DeclararrayContext* MainParser::declararray() {
  DeclararrayContext *_localctx = _tracker.createInstance<DeclararrayContext>(_ctx, getState());
  enterRule(_localctx, 24, MainParser::RuleDeclararray);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(MainParser::TYPE);
    setState(195);
    match(MainParser::VAR);
    setState(196);
    match(MainParser::T__27);
    setState(197);
    match(MainParser::INT);
    setState(198);
    match(MainParser::T__28);
    setState(199);
    match(MainParser::T__34);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefvarContext ------------------------------------------------------------------

MainParser::DefvarContext::DefvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MainParser::DefvarContext::getRuleIndex() const {
  return MainParser::RuleDefvar;
}

void MainParser::DefvarContext::copyFrom(DefvarContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DefWithDeclarContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::DefWithDeclarContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

tree::TerminalNode* MainParser::DefWithDeclarContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ExprContext* MainParser::DefWithDeclarContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::DefWithDeclarContext::DefWithDeclarContext(DefvarContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::DefWithDeclarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDefWithDeclar(this);
  else
    return visitor->visitChildren(this);
}
MainParser::DefvarContext* MainParser::defvar() {
  DefvarContext *_localctx = _tracker.createInstance<DefvarContext>(_ctx, getState());
  enterRule(_localctx, 26, MainParser::RuleDefvar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<DefvarContext *>(_tracker.createInstance<MainParser::DefWithDeclarContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(MainParser::TYPE);
    setState(202);
    match(MainParser::VAR);
    setState(203);
    match(MainParser::T__23);
    setState(204);
    expr(0);
    setState(205);
    match(MainParser::T__34);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeffuncContext ------------------------------------------------------------------

MainParser::DeffuncContext::DeffuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MainParser::DeffuncContext::getRuleIndex() const {
  return MainParser::RuleDeffunc;
}

void MainParser::DeffuncContext::copyFrom(DeffuncContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DefFuncVoidContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::DefFuncVoidContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::BlockContext* MainParser::DefFuncVoidContext::block() {
  return getRuleContext<MainParser::BlockContext>(0);
}

MainParser::ParamdecContext* MainParser::DefFuncVoidContext::paramdec() {
  return getRuleContext<MainParser::ParamdecContext>(0);
}

MainParser::DefFuncVoidContext::DefFuncVoidContext(DeffuncContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::DefFuncVoidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDefFuncVoid(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DefFuncNormalContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::DefFuncNormalContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

tree::TerminalNode* MainParser::DefFuncNormalContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::BlockContext* MainParser::DefFuncNormalContext::block() {
  return getRuleContext<MainParser::BlockContext>(0);
}

MainParser::ParamdecContext* MainParser::DefFuncNormalContext::paramdec() {
  return getRuleContext<MainParser::ParamdecContext>(0);
}

MainParser::DefFuncNormalContext::DefFuncNormalContext(DeffuncContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::DefFuncNormalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDefFuncNormal(this);
  else
    return visitor->visitChildren(this);
}
MainParser::DeffuncContext* MainParser::deffunc() {
  DeffuncContext *_localctx = _tracker.createInstance<DeffuncContext>(_ctx, getState());
  enterRule(_localctx, 28, MainParser::RuleDeffunc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::TYPE: {
        _localctx = dynamic_cast<DeffuncContext *>(_tracker.createInstance<MainParser::DefFuncNormalContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(207);
        match(MainParser::TYPE);
        setState(208);
        match(MainParser::VAR);
        setState(209);
        match(MainParser::T__1);
        setState(211);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MainParser::TYPE) {
          setState(210);
          paramdec();
        }
        setState(213);
        match(MainParser::T__2);
        setState(214);
        block();
        break;
      }

      case MainParser::T__36: {
        _localctx = dynamic_cast<DeffuncContext *>(_tracker.createInstance<MainParser::DefFuncVoidContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(215);
        match(MainParser::T__36);
        setState(216);
        match(MainParser::VAR);
        setState(217);
        match(MainParser::T__1);
        setState(219);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MainParser::TYPE) {
          setState(218);
          paramdec();
        }
        setState(221);
        match(MainParser::T__2);
        setState(222);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarfuncContext ------------------------------------------------------------------

MainParser::DeclarfuncContext::DeclarfuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MainParser::DeclarfuncContext::getRuleIndex() const {
  return MainParser::RuleDeclarfunc;
}

void MainParser::DeclarfuncContext::copyFrom(DeclarfuncContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclarFuncNormalContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::DeclarFuncNormalContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

tree::TerminalNode* MainParser::DeclarFuncNormalContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ParamdecContext* MainParser::DeclarFuncNormalContext::paramdec() {
  return getRuleContext<MainParser::ParamdecContext>(0);
}

MainParser::DeclarFuncNormalContext::DeclarFuncNormalContext(DeclarfuncContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::DeclarFuncNormalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDeclarFuncNormal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarFuncVoidContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::DeclarFuncVoidContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ParamdecContext* MainParser::DeclarFuncVoidContext::paramdec() {
  return getRuleContext<MainParser::ParamdecContext>(0);
}

MainParser::DeclarFuncVoidContext::DeclarFuncVoidContext(DeclarfuncContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::DeclarFuncVoidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDeclarFuncVoid(this);
  else
    return visitor->visitChildren(this);
}
MainParser::DeclarfuncContext* MainParser::declarfunc() {
  DeclarfuncContext *_localctx = _tracker.createInstance<DeclarfuncContext>(_ctx, getState());
  enterRule(_localctx, 30, MainParser::RuleDeclarfunc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(241);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::TYPE: {
        _localctx = dynamic_cast<DeclarfuncContext *>(_tracker.createInstance<MainParser::DeclarFuncNormalContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(225);
        match(MainParser::TYPE);
        setState(226);
        match(MainParser::VAR);
        setState(227);
        match(MainParser::T__1);
        setState(229);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MainParser::TYPE) {
          setState(228);
          paramdec();
        }
        setState(231);
        match(MainParser::T__2);
        setState(232);
        match(MainParser::T__34);
        break;
      }

      case MainParser::T__36: {
        _localctx = dynamic_cast<DeclarfuncContext *>(_tracker.createInstance<MainParser::DeclarFuncVoidContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(233);
        match(MainParser::T__36);
        setState(234);
        match(MainParser::VAR);
        setState(235);
        match(MainParser::T__1);
        setState(237);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MainParser::TYPE) {
          setState(236);
          paramdec();
        }
        setState(239);
        match(MainParser::T__2);
        setState(240);
        match(MainParser::T__34);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecfuncContext ------------------------------------------------------------------

MainParser::ExecfuncContext::ExecfuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MainParser::ExecfuncContext::getRuleIndex() const {
  return MainParser::RuleExecfunc;
}

void MainParser::ExecfuncContext::copyFrom(ExecfuncContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- GetcharContext ------------------------------------------------------------------

MainParser::GetcharContext::GetcharContext(ExecfuncContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::GetcharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitGetchar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PutcharContext ------------------------------------------------------------------

MainParser::ExprContext* MainParser::PutcharContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::PutcharContext::PutcharContext(ExecfuncContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::PutcharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitPutchar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NormalExecContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::NormalExecContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ParamContext* MainParser::NormalExecContext::param() {
  return getRuleContext<MainParser::ParamContext>(0);
}

MainParser::NormalExecContext::NormalExecContext(ExecfuncContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::NormalExecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitNormalExec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintfContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::PrintfContext::STR() {
  return getToken(MainParser::STR, 0);
}

std::vector<tree::TerminalNode *> MainParser::PrintfContext::VAR() {
  return getTokens(MainParser::VAR);
}

tree::TerminalNode* MainParser::PrintfContext::VAR(size_t i) {
  return getToken(MainParser::VAR, i);
}

MainParser::PrintfContext::PrintfContext(ExecfuncContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::PrintfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitPrintf(this);
  else
    return visitor->visitChildren(this);
}
MainParser::ExecfuncContext* MainParser::execfunc() {
  ExecfuncContext *_localctx = _tracker.createInstance<ExecfuncContext>(_ctx, getState());
  enterRule(_localctx, 32, MainParser::RuleExecfunc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(268);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::T__37: {
        _localctx = dynamic_cast<ExecfuncContext *>(_tracker.createInstance<MainParser::PutcharContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(243);
        match(MainParser::T__37);
        setState(244);
        match(MainParser::T__1);
        setState(245);
        expr(0);
        setState(246);
        match(MainParser::T__2);
        break;
      }

      case MainParser::T__38: {
        _localctx = dynamic_cast<ExecfuncContext *>(_tracker.createInstance<MainParser::PrintfContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(248);
        match(MainParser::T__38);
        setState(249);
        match(MainParser::T__1);
        setState(250);
        match(MainParser::STR);
        setState(255);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MainParser::T__35) {
          setState(251);
          match(MainParser::T__35);
          setState(252);
          match(MainParser::VAR);
          setState(257);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(258);
        match(MainParser::T__2);
        break;
      }

      case MainParser::T__39: {
        _localctx = dynamic_cast<ExecfuncContext *>(_tracker.createInstance<MainParser::GetcharContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(259);
        match(MainParser::T__39);
        setState(260);
        match(MainParser::T__1);
        setState(261);
        match(MainParser::T__2);
        break;
      }

      case MainParser::VAR: {
        _localctx = dynamic_cast<ExecfuncContext *>(_tracker.createInstance<MainParser::NormalExecContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(262);
        match(MainParser::VAR);
        setState(263);
        match(MainParser::T__1);
        setState(265);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MainParser::T__0)
          | (1ULL << MainParser::T__1)
          | (1ULL << MainParser::T__3)
          | (1ULL << MainParser::T__4)
          | (1ULL << MainParser::T__37)
          | (1ULL << MainParser::T__38)
          | (1ULL << MainParser::T__39)
          | (1ULL << MainParser::INT)
          | (1ULL << MainParser::VAR)
          | (1ULL << MainParser::CHAR))) != 0)) {
          setState(264);
          param();
        }
        setState(267);
        match(MainParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MainParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MainParser::StatementContext *> MainParser::BlockContext::statement() {
  return getRuleContexts<MainParser::StatementContext>();
}

MainParser::StatementContext* MainParser::BlockContext::statement(size_t i) {
  return getRuleContext<MainParser::StatementContext>(i);
}


size_t MainParser::BlockContext::getRuleIndex() const {
  return MainParser::RuleBlock;
}

antlrcpp::Any MainParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MainParser::BlockContext* MainParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 34, MainParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    match(MainParser::T__40);
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MainParser::T__0)
      | (1ULL << MainParser::T__1)
      | (1ULL << MainParser::T__3)
      | (1ULL << MainParser::T__4)
      | (1ULL << MainParser::T__29)
      | (1ULL << MainParser::T__32)
      | (1ULL << MainParser::T__33)
      | (1ULL << MainParser::T__37)
      | (1ULL << MainParser::T__38)
      | (1ULL << MainParser::T__39)
      | (1ULL << MainParser::T__42)
      | (1ULL << MainParser::TYPE)
      | (1ULL << MainParser::INT)
      | (1ULL << MainParser::VAR)
      | (1ULL << MainParser::CHAR))) != 0)) {
      setState(271);
      statement();
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(277);
    match(MainParser::T__41);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprstatContext ------------------------------------------------------------------

MainParser::ExprstatContext::ExprstatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::ExprContext* MainParser::ExprstatContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}


size_t MainParser::ExprstatContext::getRuleIndex() const {
  return MainParser::RuleExprstat;
}

antlrcpp::Any MainParser::ExprstatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitExprstat(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ExprstatContext* MainParser::exprstat() {
  ExprstatContext *_localctx = _tracker.createInstance<ExprstatContext>(_ctx, getState());
  enterRule(_localctx, 36, MainParser::RuleExprstat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    expr(0);
    setState(280);
    match(MainParser::T__34);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MainParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::RetContext* MainParser::StatementContext::ret() {
  return getRuleContext<MainParser::RetContext>(0);
}

MainParser::DefvarContext* MainParser::StatementContext::defvar() {
  return getRuleContext<MainParser::DefvarContext>(0);
}

MainParser::ExprstatContext* MainParser::StatementContext::exprstat() {
  return getRuleContext<MainParser::ExprstatContext>(0);
}

MainParser::DeclarvarContext* MainParser::StatementContext::declarvar() {
  return getRuleContext<MainParser::DeclarvarContext>(0);
}

MainParser::DeclararrayContext* MainParser::StatementContext::declararray() {
  return getRuleContext<MainParser::DeclararrayContext>(0);
}

MainParser::IfinsContext* MainParser::StatementContext::ifins() {
  return getRuleContext<MainParser::IfinsContext>(0);
}

MainParser::WhileinsContext* MainParser::StatementContext::whileins() {
  return getRuleContext<MainParser::WhileinsContext>(0);
}

MainParser::ForinsContext* MainParser::StatementContext::forins() {
  return getRuleContext<MainParser::ForinsContext>(0);
}


size_t MainParser::StatementContext::getRuleIndex() const {
  return MainParser::RuleStatement;
}

antlrcpp::Any MainParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MainParser::StatementContext* MainParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 38, MainParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(290);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(282);
      ret();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(283);
      defvar();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(284);
      exprstat();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(285);
      declarvar();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(286);
      declararray();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(287);
      ifins();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(288);
      whileins();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(289);
      forins();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

MainParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::ExprContext* MainParser::RetContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}


size_t MainParser::RetContext::getRuleIndex() const {
  return MainParser::RuleRet;
}

antlrcpp::Any MainParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}

MainParser::RetContext* MainParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 40, MainParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(MainParser::T__42);
    setState(293);
    expr(0);
    setState(294);
    match(MainParser::T__34);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamdecContext ------------------------------------------------------------------

MainParser::ParamdecContext::ParamdecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MainParser::ParamdecContext::TYPE() {
  return getTokens(MainParser::TYPE);
}

tree::TerminalNode* MainParser::ParamdecContext::TYPE(size_t i) {
  return getToken(MainParser::TYPE, i);
}

std::vector<tree::TerminalNode *> MainParser::ParamdecContext::VAR() {
  return getTokens(MainParser::VAR);
}

tree::TerminalNode* MainParser::ParamdecContext::VAR(size_t i) {
  return getToken(MainParser::VAR, i);
}


size_t MainParser::ParamdecContext::getRuleIndex() const {
  return MainParser::RuleParamdec;
}

antlrcpp::Any MainParser::ParamdecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitParamdec(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ParamdecContext* MainParser::paramdec() {
  ParamdecContext *_localctx = _tracker.createInstance<ParamdecContext>(_ctx, getState());
  enterRule(_localctx, 42, MainParser::RuleParamdec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    match(MainParser::TYPE);
    setState(297);
    match(MainParser::VAR);
    setState(303);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MainParser::T__35) {
      setState(298);
      match(MainParser::T__35);
      setState(299);
      match(MainParser::TYPE);
      setState(300);
      match(MainParser::VAR);
      setState(305);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

MainParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MainParser::ExprContext *> MainParser::ParamContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::ParamContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}


size_t MainParser::ParamContext::getRuleIndex() const {
  return MainParser::RuleParam;
}

antlrcpp::Any MainParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ParamContext* MainParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 44, MainParser::RuleParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    expr(0);
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MainParser::T__35) {
      setState(307);
      match(MainParser::T__35);
      setState(308);
      expr(0);
      setState(313);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MainParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MainParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MainParser::_decisionToDFA;
atn::PredictionContextCache MainParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MainParser::_atn;
std::vector<uint16_t> MainParser::_serializedATN;

std::vector<std::string> MainParser::_ruleNames = {
  "prog", "funct", "expr", "compare", "elemlv", "elemrv", "ifins", "elseifins", 
  "elseins", "whileins", "forins", "declarvar", "declararray", "defvar", 
  "deffunc", "declarfunc", "execfunc", "block", "exprstat", "statement", 
  "ret", "paramdec", "param"
};

std::vector<std::string> MainParser::_literalNames = {
  "", "'sizeof'", "'('", "')'", "'++'", "'--'", "'*'", "'/'", "'%'", "'+'", 
  "'-'", "'&'", "'^'", "'|'", "'&&'", "'||'", "'*='", "'/='", "'+='", "'-='", 
  "'%='", "'&='", "'^='", "'|='", "'='", "'<'", "'>'", "'!'", "'['", "']'", 
  "'if'", "'else if'", "'else'", "'while'", "'for'", "';'", "','", "'void'", 
  "'putchar'", "'printf'", "'getchar'", "'{'", "'}'", "'return'"
};

std::vector<std::string> MainParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "TYPE", "INT", "VAR", "CHAR", "CHARESC", 
  "STR", "WS"
};

dfa::Vocabulary MainParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MainParser::_tokenNames;

MainParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x34, 0x13d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x35, 
    0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x39, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4f, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x53, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x6b, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x6e, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x72, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x76, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x88, 0xa, 0x8, 0x3, 0x8, 0x7, 0x8, 0x8b, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0x8e, 0xb, 0x8, 0x3, 0x8, 0x5, 0x8, 0x91, 0xa, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x99, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x9e, 0xa, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xa6, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xab, 0xa, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xaf, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0xb3, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb8, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xbe, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0xc1, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xd6, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xde, 0xa, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xe2, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xe8, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xf0, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xf4, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x7, 0x12, 0x100, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
    0x103, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x10c, 0xa, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0x10f, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x113, 0xa, 0x13, 
    0xc, 0x13, 0xe, 0x13, 0x116, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x125, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x130, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0x133, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 
    0x138, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x13b, 0xb, 0x18, 0x3, 0x18, 
    0x2, 0x3, 0x6, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x2, 0xa, 0x4, 0x2, 0x2e, 0x2e, 0x30, 0x30, 0x3, 0x2, 0x6, 
    0x7, 0x3, 0x2, 0x12, 0x1a, 0x3, 0x2, 0x8, 0xa, 0x3, 0x2, 0xb, 0xc, 0x3, 
    0x2, 0x10, 0x11, 0x3, 0x2, 0x1b, 0x1c, 0x4, 0x2, 0x1a, 0x1a, 0x1d, 0x1d, 
    0x2, 0x15a, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4, 0x38, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x52, 0x3, 0x2, 0x2, 0x2, 0x8, 0x75, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x92, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa7, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x22, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x110, 0x3, 0x2, 0x2, 0x2, 0x26, 0x119, 0x3, 0x2, 0x2, 0x2, 0x28, 0x124, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x126, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x134, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x5, 0x4, 
    0x3, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x3, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x39, 0x5, 0x1e, 0x10, 0x2, 0x37, 0x39, 0x5, 0x20, 0x11, 0x2, 0x38, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x8, 0x4, 0x1, 0x2, 0x3b, 0x53, 0x5, 
    0x22, 0x12, 0x2, 0x3c, 0x53, 0x5, 0xc, 0x7, 0x2, 0x3d, 0x3e, 0x7, 0x3, 
    0x2, 0x2, 0x3e, 0x3f, 0x7, 0x4, 0x2, 0x2, 0x3f, 0x40, 0x9, 0x2, 0x2, 
    0x2, 0x40, 0x53, 0x7, 0x5, 0x2, 0x2, 0x41, 0x42, 0x7, 0x30, 0x2, 0x2, 
    0x42, 0x53, 0x9, 0x3, 0x2, 0x2, 0x43, 0x44, 0x9, 0x3, 0x2, 0x2, 0x44, 
    0x53, 0x7, 0x30, 0x2, 0x2, 0x45, 0x53, 0x7, 0x2f, 0x2, 0x2, 0x46, 0x53, 
    0x7, 0x30, 0x2, 0x2, 0x47, 0x53, 0x7, 0x31, 0x2, 0x2, 0x48, 0x49, 0x7, 
    0x4, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x6, 0x4, 0x2, 0x4a, 0x4b, 0x7, 0x5, 
    0x2, 0x2, 0x4b, 0x53, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x7, 0x30, 0x2, 
    0x2, 0x4d, 0x4f, 0x5, 0xa, 0x6, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x51, 0x9, 0x4, 0x2, 0x2, 0x51, 0x53, 0x5, 0x6, 0x4, 0x3, 0x52, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x52, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x41, 0x3, 0x2, 0x2, 0x2, 0x52, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x45, 0x3, 0x2, 0x2, 0x2, 0x52, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x47, 0x3, 0x2, 0x2, 0x2, 0x52, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x53, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x55, 0xc, 0xe, 0x2, 0x2, 0x55, 0x56, 0x9, 0x5, 0x2, 0x2, 0x56, 0x6b, 
    0x5, 0x6, 0x4, 0xf, 0x57, 0x58, 0xc, 0xd, 0x2, 0x2, 0x58, 0x59, 0x9, 
    0x6, 0x2, 0x2, 0x59, 0x6b, 0x5, 0x6, 0x4, 0xe, 0x5a, 0x5b, 0xc, 0x8, 
    0x2, 0x2, 0x5b, 0x5c, 0x7, 0xd, 0x2, 0x2, 0x5c, 0x6b, 0x5, 0x6, 0x4, 
    0x9, 0x5d, 0x5e, 0xc, 0x7, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0xe, 0x2, 0x2, 
    0x5f, 0x6b, 0x5, 0x6, 0x4, 0x8, 0x60, 0x61, 0xc, 0x6, 0x2, 0x2, 0x61, 
    0x62, 0x7, 0xf, 0x2, 0x2, 0x62, 0x6b, 0x5, 0x6, 0x4, 0x7, 0x63, 0x64, 
    0xc, 0x5, 0x2, 0x2, 0x64, 0x65, 0x9, 0x7, 0x2, 0x2, 0x65, 0x6b, 0x5, 
    0x6, 0x4, 0x6, 0x66, 0x67, 0xc, 0x4, 0x2, 0x2, 0x67, 0x68, 0x5, 0x8, 
    0x5, 0x2, 0x68, 0x69, 0x5, 0x6, 0x4, 0x5, 0x69, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x54, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x63, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 0x9, 0x8, 0x2, 
    0x2, 0x70, 0x72, 0x7, 0x1a, 0x2, 0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x76, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x9, 0x9, 0x2, 0x2, 0x74, 0x76, 0x7, 0x1a, 0x2, 0x2, 0x75, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x30, 0x2, 0x2, 0x78, 0x79, 0x7, 0x1e, 
    0x2, 0x2, 0x79, 0x7a, 0x5, 0x6, 0x4, 0x2, 0x7a, 0x7b, 0x7, 0x1f, 0x2, 
    0x2, 0x7b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x30, 0x2, 0x2, 
    0x7d, 0x7e, 0x7, 0x1e, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x6, 0x4, 0x2, 0x7f, 
    0x80, 0x7, 0x1f, 0x2, 0x2, 0x80, 0xd, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 
    0x7, 0x20, 0x2, 0x2, 0x82, 0x83, 0x7, 0x4, 0x2, 0x2, 0x83, 0x84, 0x5, 
    0x6, 0x4, 0x2, 0x84, 0x87, 0x7, 0x5, 0x2, 0x2, 0x85, 0x88, 0x5, 0x28, 
    0x15, 0x2, 0x86, 0x88, 0x5, 0x24, 0x13, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x8b, 0x5, 0x10, 0x9, 0x2, 0x8a, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x91, 0x5, 0x12, 0xa, 0x2, 0x90, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x93, 0x7, 0x21, 0x2, 0x2, 0x93, 0x94, 0x7, 0x4, 0x2, 0x2, 
    0x94, 0x95, 0x5, 0x6, 0x4, 0x2, 0x95, 0x98, 0x7, 0x5, 0x2, 0x2, 0x96, 
    0x99, 0x5, 0x28, 0x15, 0x2, 0x97, 0x99, 0x5, 0x24, 0x13, 0x2, 0x98, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x9a, 0x9d, 0x7, 0x22, 0x2, 0x2, 0x9b, 0x9e, 0x5, 
    0x28, 0x15, 0x2, 0x9c, 0x9e, 0x5, 0x24, 0x13, 0x2, 0x9d, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0xa0, 0x7, 0x23, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x4, 0x2, 
    0x2, 0xa1, 0xa2, 0x5, 0x6, 0x4, 0x2, 0xa2, 0xa5, 0x7, 0x5, 0x2, 0x2, 
    0xa3, 0xa6, 0x5, 0x28, 0x15, 0x2, 0xa4, 0xa6, 0x5, 0x24, 0x13, 0x2, 
    0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x24, 0x2, 0x2, 0xa8, 0xaa, 
    0x7, 0x4, 0x2, 0x2, 0xa9, 0xab, 0x5, 0x6, 0x4, 0x2, 0xaa, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xae, 0x7, 0x25, 0x2, 0x2, 0xad, 0xaf, 0x5, 0x6, 0x4, 
    0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb2, 0x7, 0x25, 0x2, 0x2, 0xb1, 
    0xb3, 0x5, 0x6, 0x4, 0x2, 0xb2, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb7, 0x7, 
    0x5, 0x2, 0x2, 0xb5, 0xb8, 0x5, 0x28, 0x15, 0x2, 0xb6, 0xb8, 0x5, 0x24, 
    0x13, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x2e, 0x2, 0x2, 
    0xba, 0xbf, 0x7, 0x30, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x26, 0x2, 0x2, 0xbc, 
    0xbe, 0x7, 0x30, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0xc3, 0x7, 0x25, 0x2, 0x2, 0xc3, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xc4, 0xc5, 0x7, 0x2e, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x30, 0x2, 0x2, 
    0xc6, 0xc7, 0x7, 0x1e, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x2f, 0x2, 0x2, 0xc8, 
    0xc9, 0x7, 0x1f, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x25, 0x2, 0x2, 0xca, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x2e, 0x2, 0x2, 0xcc, 0xcd, 0x7, 
    0x30, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x1a, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x6, 
    0x4, 0x2, 0xcf, 0xd0, 0x7, 0x25, 0x2, 0x2, 0xd0, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xd1, 0xd2, 0x7, 0x2e, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x30, 0x2, 0x2, 
    0xd3, 0xd5, 0x7, 0x4, 0x2, 0x2, 0xd4, 0xd6, 0x5, 0x2c, 0x17, 0x2, 0xd5, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x5, 0x2, 0x2, 0xd8, 0xe2, 0x5, 
    0x24, 0x13, 0x2, 0xd9, 0xda, 0x7, 0x27, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x30, 
    0x2, 0x2, 0xdb, 0xdd, 0x7, 0x4, 0x2, 0x2, 0xdc, 0xde, 0x5, 0x2c, 0x17, 
    0x2, 0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x5, 0x2, 0x2, 0xe0, 
    0xe2, 0x5, 0x24, 0x13, 0x2, 0xe1, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0xe2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 
    0x2e, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x30, 0x2, 0x2, 0xe5, 0xe7, 0x7, 0x4, 
    0x2, 0x2, 0xe6, 0xe8, 0x5, 0x2c, 0x17, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 
    0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 
    0xe9, 0xea, 0x7, 0x5, 0x2, 0x2, 0xea, 0xf4, 0x7, 0x25, 0x2, 0x2, 0xeb, 
    0xec, 0x7, 0x27, 0x2, 0x2, 0xec, 0xed, 0x7, 0x30, 0x2, 0x2, 0xed, 0xef, 
    0x7, 0x4, 0x2, 0x2, 0xee, 0xf0, 0x5, 0x2c, 0x17, 0x2, 0xef, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xf2, 0x7, 0x5, 0x2, 0x2, 0xf2, 0xf4, 0x7, 0x25, 0x2, 
    0x2, 0xf3, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xf4, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x28, 0x2, 0x2, 0xf6, 
    0xf7, 0x7, 0x4, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x6, 0x4, 0x2, 0xf8, 0xf9, 
    0x7, 0x5, 0x2, 0x2, 0xf9, 0x10f, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 
    0x29, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x4, 0x2, 0x2, 0xfc, 0x101, 0x7, 0x33, 
    0x2, 0x2, 0xfd, 0xfe, 0x7, 0x26, 0x2, 0x2, 0xfe, 0x100, 0x7, 0x30, 0x2, 
    0x2, 0xff, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0x103, 0x3, 0x2, 0x2, 0x2, 
    0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 
    0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x10f, 0x7, 0x5, 0x2, 0x2, 0x105, 0x106, 0x7, 0x2a, 0x2, 0x2, 0x106, 
    0x107, 0x7, 0x4, 0x2, 0x2, 0x107, 0x10f, 0x7, 0x5, 0x2, 0x2, 0x108, 
    0x109, 0x7, 0x30, 0x2, 0x2, 0x109, 0x10b, 0x7, 0x4, 0x2, 0x2, 0x10a, 
    0x10c, 0x5, 0x2e, 0x18, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 
    0x10f, 0x7, 0x5, 0x2, 0x2, 0x10e, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x10e, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x10f, 0x23, 0x3, 0x2, 0x2, 0x2, 0x110, 0x114, 0x7, 
    0x2b, 0x2, 0x2, 0x111, 0x113, 0x5, 0x28, 0x15, 0x2, 0x112, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x116, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x3, 
    0x2, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 
    0x2c, 0x2, 0x2, 0x118, 0x25, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x5, 
    0x6, 0x4, 0x2, 0x11a, 0x11b, 0x7, 0x25, 0x2, 0x2, 0x11b, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x125, 0x5, 0x2a, 0x16, 0x2, 0x11d, 0x125, 0x5, 
    0x1c, 0xf, 0x2, 0x11e, 0x125, 0x5, 0x26, 0x14, 0x2, 0x11f, 0x125, 0x5, 
    0x18, 0xd, 0x2, 0x120, 0x125, 0x5, 0x1a, 0xe, 0x2, 0x121, 0x125, 0x5, 
    0xe, 0x8, 0x2, 0x122, 0x125, 0x5, 0x14, 0xb, 0x2, 0x123, 0x125, 0x5, 
    0x16, 0xc, 0x2, 0x124, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x124, 0x11d, 0x3, 
    0x2, 0x2, 0x2, 0x124, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x124, 0x11f, 0x3, 
    0x2, 0x2, 0x2, 0x124, 0x120, 0x3, 0x2, 0x2, 0x2, 0x124, 0x121, 0x3, 
    0x2, 0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 0x123, 0x3, 
    0x2, 0x2, 0x2, 0x125, 0x29, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x2d, 
    0x2, 0x2, 0x127, 0x128, 0x5, 0x6, 0x4, 0x2, 0x128, 0x129, 0x7, 0x25, 
    0x2, 0x2, 0x129, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x2e, 
    0x2, 0x2, 0x12b, 0x131, 0x7, 0x30, 0x2, 0x2, 0x12c, 0x12d, 0x7, 0x26, 
    0x2, 0x2, 0x12d, 0x12e, 0x7, 0x2e, 0x2, 0x2, 0x12e, 0x130, 0x7, 0x30, 
    0x2, 0x2, 0x12f, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 0x3, 0x2, 
    0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x134, 0x139, 0x5, 0x6, 0x4, 0x2, 0x135, 0x136, 0x7, 0x26, 0x2, 
    0x2, 0x136, 0x138, 0x5, 0x6, 0x4, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 
    0x2, 0x138, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 
    0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x22, 0x33, 0x38, 0x4e, 0x52, 0x6a, 
    0x6c, 0x71, 0x75, 0x87, 0x8c, 0x90, 0x98, 0x9d, 0xa5, 0xaa, 0xae, 0xb2, 
    0xb7, 0xbf, 0xd5, 0xdd, 0xe1, 0xe7, 0xef, 0xf3, 0x101, 0x10b, 0x10e, 
    0x114, 0x124, 0x131, 0x139, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MainParser::Initializer MainParser::_init;
