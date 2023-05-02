#ifndef TP1_RAYTRACING_SIERPINSKI_HH
#define TP1_RAYTRACING_SIERPINSKI_HH

#include "Triangle.hh"
#include <vector>
#include <queue>

enum class Tokens{
    F,
    G,
    PLUS,
    MINUS,
    END
};

class Sierpinski {
public:
    float angle;
    float depth;

    std::queue<Tokens> tokens;
    std::vector<Triangle> triangles;

    Sierpinski(float angle, float depth){
        this->angle = angle;
        this->depth = depth;

        //initialize stack
        tokens.push(Tokens::F);
        tokens.push(Tokens::MINUS);
        tokens.push(Tokens::G);
        tokens.push(Tokens::MINUS);
        tokens.push(Tokens::G);
        tokens.push(Tokens::END);

        //compute
        computeFractales();
    }

    std::queue<Tokens> applyRule(Tokens token){
        //(F → F−G+F+G−F), (G → GG), + − constants
        std::queue<Tokens> tokensFromRule;

        if (token == Tokens::F) {
            tokensFromRule.push(Tokens::F);
            tokensFromRule.push(Tokens::MINUS);
            tokensFromRule.push(Tokens::G);
            tokensFromRule.push(Tokens::PLUS);
            tokensFromRule.push(Tokens::F);
            tokensFromRule.push(Tokens::PLUS);
            tokensFromRule.push(Tokens::G);
            tokensFromRule.push(Tokens::MINUS);
            tokensFromRule.push(Tokens::F);
        }else if (token == Tokens::G){
            tokensFromRule.push(Tokens::G);
            tokensFromRule.push(Tokens::G);
        }else if(token == Tokens::PLUS){
            tokensFromRule.push(Tokens::PLUS);
        }else if(token == Tokens::MINUS){
            tokensFromRule.push(Tokens::MINUS);
        }

        return tokensFromRule;
    }

    void pushTokens(std::queue<Tokens> src){
        while (!src.empty()) {
            tokens.push(src.front());
            src.pop();
        }
    }

    void computeFractales(){
        //we apply all the rules n times
        for (int i = 0; i < depth; i++) {
            while (tokens.front() != Tokens::END) {
                pushTokens(applyRule(tokens.front()));
                tokens.pop();
            }

            //we remove the old END and add a new END
            tokens.pop();
            tokens.push(Tokens::END);
        }
    }

    void debug(){
        while (!tokens.empty()){
            if (tokens.front() == Tokens::F){
                std::cout << "F";
            }else if (tokens.front() == Tokens::G) {
                std::cout << "G";
            }else if (tokens.front() == Tokens::PLUS) {
                std::cout << "+";
            }else if (tokens.front() == Tokens::MINUS) {
                std::cout << "-";
            }else if (tokens.front() == Tokens::END) {
                std::cout << " END";
            }
            tokens.pop();
        }
        std::cout<< "\n";
    }
};


#endif //TP1_RAYTRACING_SIERPINSKI_HH
