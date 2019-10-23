#! /usr/bin/python3

def create_dataset():
    # 最后一个元素为对应实例的类别标签
    dataset = [
        [1, 1, "yes"],
        [1, 1, "yes"],
        [1, 0, "no"],
        [0, 1, "no"],
        [0, 1, "no"]
    ]

    labels = ["no surfacing", "flippers"]

    return dataset, labels

def split_dataset(dataset, axis, value):
    result = []
    
    for feature_vector in dataset:
        if feature_vector[axis] == value:
            reduced_feature_vector = feature_vector[:axis]
            reduced_feature_vector.extend(feature_vector[axis+1:])

            result.append(reduced_feature_vector)

    return result
        
