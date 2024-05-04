#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "BinaryTree.h"

using namespace std;

/**
 * helper for printout
*/
static void printOutput(vector<vector<int>>& allLayers) {
    cout<<"Depth: "<< allLayers.size() << endl;
    cout<<"[";
    for (auto layer : allLayers) {
        cout<<"[";
        for (int idex = 0; idex < layer.size(); idex++) {
            cout<< layer.at(idex);
            if (idex != (layer.size() -1)) cout << ",";
        }
        cout<<"]";
    }
    cout<<"]\n";
}

/**
 * compare vector
*/
static bool compareVector(vector<vector<int>>& vector1, vector<vector<int>>& vector2) {
    if (vector1.size() != vector2.size()) return false;
    for (int layer = 0; layer < vector1.size(); layer++) {
        for (int nodeIdx = 0; nodeIdx < vector1.at(layer).size(); nodeIdx++) {
            if (vector1.at(layer).at(nodeIdx) != vector2.at(layer).at(nodeIdx)) return false;
        }
    }
    return true;
}

static void test() {
  /**
   * test case 1
  */
  {
      cout<<"===============TEST 1 START================="<<endl;
      cout<<"Tree:root = [-10,9,20,null,null,15,7]\n";
      int expected = 42;
      cout<<"Expected: "<< expected << endl;
      TreeNode *root = new TreeNode(-10);
      TreeNode *l10 = new TreeNode(9);
      TreeNode *l11 = new TreeNode(20);
      TreeNode *l22 = new TreeNode(15);
      TreeNode *l23 = new TreeNode(7);
      root->left = l10;
      root->right = l11;
      l11->left = l22;
      l11->right = l23;


      // confirm solution
      Solution solution;
      auto result = solution.maxPathSum(root);
      cout<< "Result:" << result << endl;
      cout<< ((result == expected)? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
      delete l11;
      delete l22;
      delete l23;
  }
  /**
   * test case 2
  */
  {
      cout<<"===============TEST 1 START================="<<endl;
      cout<<"Tree:root = [1]\n";
      int expected = 1;
      cout<<"Expected: "<< expected << endl;
      TreeNode *root = new TreeNode(1);



      // confirm solution
      Solution solution;
      auto result = solution.maxPathSum(root);
      cout<< "Result:" << result << endl;
      cout<< ((result == expected)? "PASS": "FAIL") << endl;
      delete root;
  }

    /**
   * test case 2
  */
  {
      cout<<"===============TEST 1 START================="<<endl;
      cout<<"Tree:root = [1,2]\n";
      int expected = 3;
      cout<<"Expected: "<< expected << endl;
      TreeNode *root = new TreeNode(1);
      TreeNode *l10 = new TreeNode(2);
      root->left = l10;


      // confirm solution
      Solution solution;
      auto result = solution.maxPathSum(root);
      cout<< "Result:" << result << endl;
      cout<< ((result == expected)? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
  }
      /**
   * test case 2
  */
  {
      cout<<"===============TEST 1 START================="<<endl;
      cout<<"Tree:root = [1,-2, 3]\n";
      int expected = 4;
      cout<<"Expected: "<< expected << endl;
      TreeNode *root = new TreeNode(1);
      TreeNode *l10 = new TreeNode(-2);
      TreeNode *l11 = new TreeNode(3);
      root->left = l10;
      root->right = l11;


      // confirm solution
      Solution solution;
      auto result = solution.maxPathSum(root);
      cout<< "Result:" << result << endl;
      cout<< ((result == expected)? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
  }
}
/**
 * main function
*/
int main(int argc, const char** argv) {
  test();
  return 0;
}


