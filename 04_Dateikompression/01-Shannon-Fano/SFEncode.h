#ifndef SFENCODE_H
#define SFENCODE_H

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

extern const bool DEBUG;

class SFNode{
    public:
        int start = 0, end = 0;
        float cumProb = 0;
        bool isLeaf = false;

        std::string binValue;


        SFNode * left = nullptr;
        SFNode * right = nullptr;

        SFNode(int start, int end, int prob, const std::string & bin) : start(start), end(end), cumProb(prob), binValue(bin) {
            if(end-start <= 0){
                isLeaf = true;
            }
        }
};

class SFEncode{

    private:

        int totalSize;
        SFNode * root;
        std::string code;

        std::map<char, int> freqTable;
        std::vector<std::pair<char, float>> probTable;

        std::vector<std::pair<char, std::string>> binTable;
        std::map<char, std::string> encodingSheme;

        void calcProbabilities() {
            for(auto it = freqTable.begin(); it != freqTable.end(); ++it){
                std::pair<char, float> temp;
                temp.first = it->first;
                temp.second = it->second / (float) totalSize;
                probTable.push_back(temp);
            }
            std::sort(probTable.begin(), probTable.end(), [](std::pair<char, float> & left, std::pair<char, float> & right){
                return left.second < right.second;
            });
        }
        
        void buildBinaryTree(SFNode * node, float probabilityTarget) {       
            if(node->isLeaf){
                // SEND OUT BINARY REPRESENTATION
                std::pair<char, std::string> temp;
                temp.first = probTable[node->start].first;
                temp.second = node->binValue;
                binTable.push_back(temp);
            }
            else{
                // CALC SEGMENTATION INDEX
                float limit = probabilityTarget/2;
                float cumProb = 0;
                int breakIndex = -1;

                for(int i = node->start; i <= node->end; i++){
                    cumProb += probTable[i].second;
                    if(cumProb >= limit){
                        breakIndex = i;
                        break;
                    }
                }
                

                // CALC LEFT CHILD
                node->left = new SFNode(node->start, breakIndex, cumProb, node->binValue);
                if(DEBUG){
                    std::cout << "(" << node->start << " / " << breakIndex << ") probToGo = " << cumProb << std::endl;
                }
                node->left->binValue += "0";
                buildBinaryTree(node->left, cumProb);
                

                // CALC RIGHT CHILD
                node->right = new SFNode(breakIndex+1, node->end, probabilityTarget-cumProb, node->binValue);
                if(DEBUG){
                    std::cout << "(" << breakIndex+1 << " / " << node->end << ") probToGo = " << probabilityTarget-cumProb << std::endl;
                }
                node->right->binValue += "1";
                buildBinaryTree(node->right, probabilityTarget-cumProb);
            }
        }

    public:
        SFEncode(const std::string & toEncode) : code(toEncode){
            for(unsigned int i = 0; i < toEncode.size(); i++){
                // Check if key with that char already exists
                auto it = freqTable.find(toEncode[i]);
                if( it != freqTable.end() ){
                    it->second++;
                }
                else{
                    freqTable.insert({toEncode[i], 1});
                }
            }
            totalSize = toEncode.size();
            calcProbabilities();
            root = new SFNode(0, probTable.size()-1, 1.0, "");
            buildBinaryTree(root, 1);
            getEncodingSheme();
        }



        void printFreqencies() const {
            for(auto it = probTable.begin(); it != probTable.end(); ++it){
                std::cout << "(" << it->first << " / " << it->second << ")" << std::endl;
            }
        }

        void printBinary() const {
            for(auto it = binTable.begin(); it != binTable.end(); ++it){
                std::cout << "(" << it->first << " / " << it->second << ")" << std::endl;
            }
        }

        const std::map<char, std::string> & getEncodingSheme() {

            for(unsigned int i = 0; i < binTable.size(); i++){
                encodingSheme.insert({binTable[i].first, binTable[i].second});
            }
            return encodingSheme;
        }

        const std::string encode() {
            std::string binary;
            std::cout << "ENCODING ..." << std::endl;
            for(unsigned int i = 0; i < code.size(); i++){
                char key = code[i];
                std::string value = encodingSheme[key];
                binary += value;
            }
            std::cout << " - " << code << " => " << binary << " (" << binary.length() << " bit)" << std::endl;
            return binary;
            
        }
};

#endif