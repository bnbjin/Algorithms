#! /usr/bin/python3

import operator

import dataset as ds
import entrophy


def choose_best_feature_to_split(dataset):
    feature_count = len(dataset[0]) - 1
    base_entrophy = entrophy.calc_entrophy(dataset)
    best_infogain = 0.0
    best_feature = -1

    for i in range(feature_count):
        subset_entrophy = 0.0

        for value in set([example[i] for example in dataset]):
            sub_dataset = ds.split_dataset(dataset, i, value)
            probability = len(sub_dataset) / float(len(dataset))
            subset_entrophy += probability * entrophy.calc_entrophy(sub_dataset)

        infogain = base_entrophy - subset_entrophy
        if infogain > best_infogain:
            best_infogain = infogain
            best_feature = i

    return best_feature

def majority_count(class_list):
    class_count = {}
    
    for vote in class_list:
        if vote not in class_count.keys():
            class_count[vote] = 0
        class_count[vote] += 1

    sorted_class_count = sorted(
        class_count.iterItems(),
        key=operator.itemgetter(1),
        reverse=True
    )

    return sorted_class_count[0][0]
    
def create_tree(dataset, labels):
    class_list = [example[-1] for example in dataset]

    # 剩下的实例的类别标签都是一致时，返回类别标签
    if class_list.count(class_list[0]) == len(class_list):
        return class_list[0]

    # 当前为叶节点
    if len(dataset[0]) == 1:
        return majority_count(class_list)

    best_feature = choose_best_feature_to_split(dataset)
    best_feature_label = labels[best_feature]
    my_tree = {best_feature_label: {}}

    del(labels[best_feature])

    feature_values = [example[best_feature] for example in dataset]
    unique_values = set(feature_values)
    
    for value in unique_values:
        sub_labels = labels[:]
        my_tree[best_feature_label][value] = create_tree(
            ds.split_dataset(dataset, best_feature, value),
            sub_labels
        )

    return my_tree
