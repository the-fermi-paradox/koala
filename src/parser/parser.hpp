#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "../lexer/lexer.hpp"
#include "type_system.hpp"
#include "expression.hpp"
#include "expressions/unary_expr.hpp"
#include "expressions/binary_expr.hpp"
#include "expressions/integer_expr.hpp"
#include "statement.hpp"

#include "common.hpp"

namespace koala {
    class parser {
        lexer*                   m_lexer;
        std::vector <statement*> m_ast;
        type_system              m_ts;
        lexer_token              m_current;

        bool expect(int token);
        type_signature parse_type();
        expression* parse_primary();
        expression* parse_expression();
        expression* parse_expression_impl(expression* lhs, int mp);
        statement* parse_statement();
        statement* parse_function_def();
        statement* parse_variable_def();
    
    public:
        parser(lexer& lexer) :
            m_lexer(&lexer) {};
        
        void parse();
    };
}