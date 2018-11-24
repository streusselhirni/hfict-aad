//
// Created by Nicolas Haenni on 13.11.18.
//

#include "TreeUtil.h"

bool TreeUtil::isBinarySearchTree(std::vector<int> values, int idx, int min, int max) {
    /**
     * Node = i
     * Node.left = 2*i + 1
     * Node.right = 2*i + 2
     * Node.parent = i/2;
     *
     * Node.right muss immer größer sein als Node
     * Node.left muss immer kleiner sein als Node
     */

    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    if (left > values.size() - 1) return true;
    if (values[left] < min || values[left] > values[idx]) return false;

    if (right > values.size() - 1) return true;
    if (values[right] > max || values[right] < values[idx]) return false;

    return (isBinarySearchTree(values, left, min, values[idx]) && isBinarySearchTree(values, right, values[idx], max));
}
