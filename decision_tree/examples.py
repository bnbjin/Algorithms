#! /usr/bin/python3

import unittest

import dataset as ds
import dtree

class TestDecisionTree(unittest.TestCase):

    def test_create_tree(self):
        dataset, labels = ds.create_dataset()
        decision_tree = dtree.create_tree(dataset, labels)

        print(decision_tree)


if __name__ == "__main__":
    unittest.main()

        
        
