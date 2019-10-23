#! /usr/bin/python3

import math

def calc_entrophy(dataset):
    # 实例总数
    entry_number = len(dataset)

    # { 特征标签:出现个数 }
    label_count = {}

    entrophy = 0.0
    
    for feature_vector in dataset: 
        current_label = feature_vector[-1]

        if current_label not in label_count.keys():
            label_count[current_label] = 0
        label_count[current_label] += 1

    for key in label_count:
        probability = float(label_count[key]) / entry_number

        # log base 2
        entrophy -= probability * math.log(probability, 2)

    return entrophy
