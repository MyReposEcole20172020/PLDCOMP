
// Generated from Main.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "MainParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MainParser.
 */
class  MainVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MainParser.
   */
    virtual antlrcpp::Any visitProg(MainParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitFunct(MainParser::FunctContext *context) = 0;

    virtual antlrcpp::Any visitPar(MainParser::ParContext *context) = 0;

    virtual antlrcpp::Any visitMultdivmod(MainParser::MultdivmodContext *context) = 0;

    virtual antlrcpp::Any visitConst(MainParser::ConstContext *context) = 0;

    virtual antlrcpp::Any visitSizeof(MainParser::SizeofContext *context) = 0;

    virtual antlrcpp::Any visitVar(MainParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitCmp(MainParser::CmpContext *context) = 0;

    virtual antlrcpp::Any visitExprBin(MainParser::ExprBinContext *context) = 0;

    virtual antlrcpp::Any visitAddsub(MainParser::AddsubContext *context) = 0;

    virtual antlrcpp::Any visitElemarray(MainParser::ElemarrayContext *context) = 0;

    virtual antlrcpp::Any visitOuExBin(MainParser::OuExBinContext *context) = 0;

    virtual antlrcpp::Any visitPostop(MainParser::PostopContext *context) = 0;

    virtual antlrcpp::Any visitExfunc(MainParser::ExfuncContext *context) = 0;

    virtual antlrcpp::Any visitOuBin(MainParser::OuBinContext *context) = 0;

    virtual antlrcpp::Any visitAssignement(MainParser::AssignementContext *context) = 0;

    virtual antlrcpp::Any visitChar(MainParser::CharContext *context) = 0;

    virtual antlrcpp::Any visitPreop(MainParser::PreopContext *context) = 0;

    virtual antlrcpp::Any visitEtBin(MainParser::EtBinContext *context) = 0;

    virtual antlrcpp::Any visitCompare(MainParser::CompareContext *context) = 0;

    virtual antlrcpp::Any visitElemlv(MainParser::ElemlvContext *context) = 0;

    virtual antlrcpp::Any visitElemrv(MainParser::ElemrvContext *context) = 0;

    virtual antlrcpp::Any visitIfins(MainParser::IfinsContext *context) = 0;

    virtual antlrcpp::Any visitElseifins(MainParser::ElseifinsContext *context) = 0;

    virtual antlrcpp::Any visitElseins(MainParser::ElseinsContext *context) = 0;

    virtual antlrcpp::Any visitWhileins(MainParser::WhileinsContext *context) = 0;

    virtual antlrcpp::Any visitForins(MainParser::ForinsContext *context) = 0;

    virtual antlrcpp::Any visitDeclarvar(MainParser::DeclarvarContext *context) = 0;

    virtual antlrcpp::Any visitDeclararray(MainParser::DeclararrayContext *context) = 0;

    virtual antlrcpp::Any visitDefWithDeclar(MainParser::DefWithDeclarContext *context) = 0;

    virtual antlrcpp::Any visitDefFuncNormal(MainParser::DefFuncNormalContext *context) = 0;

    virtual antlrcpp::Any visitDefFuncVoid(MainParser::DefFuncVoidContext *context) = 0;

    virtual antlrcpp::Any visitDeclarFuncNormal(MainParser::DeclarFuncNormalContext *context) = 0;

    virtual antlrcpp::Any visitDeclarFuncVoid(MainParser::DeclarFuncVoidContext *context) = 0;

    virtual antlrcpp::Any visitPutchar(MainParser::PutcharContext *context) = 0;

    virtual antlrcpp::Any visitPrintf(MainParser::PrintfContext *context) = 0;

    virtual antlrcpp::Any visitGetchar(MainParser::GetcharContext *context) = 0;

    virtual antlrcpp::Any visitNormalExec(MainParser::NormalExecContext *context) = 0;

    virtual antlrcpp::Any visitBlock(MainParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitExprstat(MainParser::ExprstatContext *context) = 0;

    virtual antlrcpp::Any visitStatement(MainParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitRet(MainParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitParamdec(MainParser::ParamdecContext *context) = 0;

    virtual antlrcpp::Any visitParam(MainParser::ParamContext *context) = 0;


};

