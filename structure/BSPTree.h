#include "node.h"

class BSPTree{
private:
  BSPTreeNode *root;

  BSPTreeNode* buildBSPTree(std::vector<Polygon>& polygons){
    if (polygons.empty()) return nullptr;

    Polygon& partition = polygons[0];
    float A = 0, B = 0, C = 0, D = 0;

    std::vector<Polygon> frontPolygons;
    std::vector<Polygon> backPolygons;

    for (int i = 0; i < polygons.size(); i++){
      const Polygon& polygon = polygons[i];
      if (polygon.isFrontOf(A, B, C, D)){
        frontPolygons.push_back(polygon);
      } else if (polygon.isBackOf(A, B, C, D)){
        backPolygons.push_back(polygon);
      } else {
        Polygon front, back;
        polygon.divide(A, B, C, D, front, back);
        frontPolygons.push_back(front);
        backPolygons.push_back(back);
      }
    }
  }
};