#include <stdio.h>  
#include <map>  
#include <vector>  
  
const int MAX_VERTEX = 100;  
// 测试次数，点数，边数，限制的k，如果不能得到小于k的结果，就输出-1  
int num_of_test, num_of_vertex, num_of_edge, k;  
// 存储最优的点的信息  
std::vector<int> result_vertex_list;  
  
// 处理度为1的结点  
void deal_with_degree_one(std::map<int, std::map<int, int> > &info, std::map<int, int> &searched, int &checked_vertex, int &checked_edge){  
    bool flag = true;  
    int tmp;  
    int length;  
    while (flag){  
        flag = false;  
        for (std::map<int, std::map <int, int> >::iterator iter = info.begin(); iter != info.end();){  
            length = iter->second.size();  
            if (length == 1){  
                // 增加search过的边和元素  
                tmp = iter->second.begin()->first;  
                if (searched.count(tmp) == 0)  
                    ++checked_vertex;  
                // iter->second.erase(tmp);  
                searched[tmp] = 1;  
                // 必定加入的点要删除所有相关的点  
                for (std::map<int, int>::iterator iter1 = info[tmp].begin(); iter1 != info[tmp].end();){  
                    info[iter1->first].erase(tmp);  
                    ++checked_edge;  
                    info[tmp].erase(iter1++);  
                }  
                // 删除边和元素  
                info.erase(iter++);  
                flag = true;  
            } else if (length == 0) {  
                info.erase(iter++);  
            } else {  
                ++iter;  
            }  
        }  
    }  
}  
  
//遍历  
void dfs(int index, int *minimum, int checked_vertex, int checked_edge, std::map<int, std::map<int, int> > &info, std::map<int, int> &searched){  
    // 标记此点已经检查过  
    searched[index] = 1;  
    // 如果加上该点已经检查过比minimum多的点，则不可能更优了，返回  
    if (checked_vertex + 1 >= *minimum){  
        searched.erase(index);  
        return;  
    }  
    // 假如加入该点  
    // 如果已经覆盖了全部的边  
    if (checked_edge + info[index].size() == num_of_edge){  
        if (checked_vertex + 1 < *minimum){  
            *minimum = checked_vertex + 1;  
            result_vertex_list.clear();  
            for (std::map<int, int>::iterator iter = searched.begin(); iter != searched.end(); iter++)  
                result_vertex_list.push_back(iter->first);  
        }  
        searched.erase(index);  
        return;  
    }  
    // 存储修改后的变量  
    std::map<int, std::map<int, int> > tmp_info, tmp_info_not;  
    std::map<int, int> tmp_searched, tmp_searched_not;  
    int tmp_checked_vertex = checked_vertex, tmp_checked_vertex_not = checked_vertex;  
    int tmp_checked_edge = checked_edge, tmp_checked_edge_not = checked_edge;  
    for (std::map<int, std::map<int, int> >::iterator iter = info.begin(); iter != info.end(); iter++){  
        tmp_info[iter->first] = iter->second;  
        tmp_info_not[iter->first] = iter->second;  
    }  
    for (std::map<int, int>::iterator iter = searched.begin(); iter != searched.end(); iter++){  
        tmp_searched[iter->first] = iter->second;  
        tmp_searched_not[iter->first] = iter->second;  
    }  
    // 如果使用该点  
    // 删除本点的信息和其他点的关于该点的信息，修改相关信息  
    ++tmp_checked_vertex;  
    tmp_checked_edge += info[index].size();  
    for (std::map<int, int>::iterator iter = info[index].begin(); iter != info[index].end(); iter++)  
        tmp_info[iter->first].erase(index);  
    tmp_info.erase(index);  
    // 处理度为1的点  
    deal_with_degree_one(tmp_info, tmp_searched, tmp_checked_vertex, tmp_checked_edge);  
    // 如果找到了所需要的边数  
    if (tmp_checked_edge == num_of_edge){  
        if (tmp_checked_vertex < *minimum){  
            *minimum = tmp_checked_vertex;  
            result_vertex_list.clear();  
            for (std::map<int, int>::iterator iter = tmp_searched.begin(); iter != tmp_searched.end(); iter++)  
                result_vertex_list.push_back(iter->first);  
        }  
        searched.erase(index);  
        return;  
    }  
    // 寻找下一个最大度数的点  
    bool found = false;  
    int temp_index = 0, tmp_max_length = 0, tmp_second_max_length = 0;  
    for (std::map<int, std::map<int, int> >::iterator iter = tmp_info.begin(); iter !=tmp_info.end(); iter++){  
        if (tmp_searched.count(iter->first) == 0){  
            int tmp_length = iter->second.size();  
            if (tmp_length > tmp_max_length){  
                found = true;  
                temp_index = iter->first;  
                tmp_second_max_length = tmp_max_length;  
                tmp_max_length = tmp_length;  
            } else if (tmp_length > tmp_second_max_length) {  
                tmp_second_max_length = tmp_length;  
            }  
        }  
    }  
    int weight;  
    if (*minimum - tmp_checked_vertex <= 2)  
    {  
        weight = tmp_max_length * (*minimum - tmp_checked_vertex -1);  
    }  
    else  
    {  
        weight = tmp_max_length + tmp_second_max_length * ((*minimum - tmp_checked_vertex - 2));  
    }  
    if (weight >= num_of_edge - tmp_checked_edge){  
        dfs(temp_index, minimum, tmp_checked_vertex, tmp_checked_edge, tmp_info, tmp_searched);  
    }  
    // 如果不使用该点，那么所有与该点相邻的点都必须被使用，否则必存在着边无法被消去  
    // 消去该点相邻的点  
    // 本点不被使用  
    tmp_searched_not.erase(index);  
    // 找到该点相邻的点  
    for (std::map<int, int>::iterator iter = info[index].begin(); iter != info[index].end(); iter++){  
        // 删除tmp_info_not中的该点相邻的点，标记使用  
        tmp_searched_not[iter->first] = 1;  
        ++tmp_checked_vertex_not;  
  
        for (std::map<int, int>::iterator iter1 = info[iter->first].begin(); iter1 != info[iter->first].end(); iter1 ++){  
            // 如果该边还未在之前其他点的时候被删除  
            if (tmp_info_not.count(iter1->first) > 0){  
                tmp_info_not[iter1->first].erase(iter->first);  
                tmp_info_not[iter->first].erase(iter1->first);  
                ++tmp_checked_edge_not;  
            }  
        }  
        tmp_info_not.erase(iter->first);  
    }  
    // 处理度为1的点  
    deal_with_degree_one(tmp_info_not, tmp_searched_not, tmp_checked_vertex_not, tmp_checked_edge_not);  
    // 如果找到了所需要的边数  
    if (tmp_checked_edge_not == num_of_edge){  
        if (tmp_checked_vertex_not < *minimum){  
            *minimum = tmp_checked_vertex_not;  
            result_vertex_list.clear();  
            for (std::map<int, int>::iterator iter = tmp_searched_not.begin(); iter != tmp_searched_not.end(); iter++)  
                result_vertex_list.push_back(iter->first);  
        }  
        searched.erase(index);  
        return;  
    }  
    // 寻找下一个最大度数的点  
    found = false;  
    temp_index = 0, tmp_max_length = 0, tmp_second_max_length = 0;  
    for (std::map<int, std::map<int, int> >::iterator iter = tmp_info_not.begin(); iter !=tmp_info_not.end(); iter++){  
        if (tmp_searched_not.count(iter->first) == 0){  
            int tmp_length = iter->second.size();  
            if (tmp_length > tmp_max_length){  
                found = true;  
                temp_index = iter->first;  
                tmp_second_max_length = tmp_max_length;  
                tmp_max_length = tmp_length;  
            } else if (tmp_length > tmp_second_max_length) {  
                tmp_second_max_length = tmp_length;  
            }  
        }  
    }  
    if (*minimum - tmp_checked_vertex <= 2)  
    {  
        weight = tmp_max_length * (*minimum - tmp_checked_vertex -1);  
    }  
    else  
    {  
        weight = tmp_max_length + tmp_second_max_length * ((*minimum - tmp_checked_vertex - 2));  
    }  
    if (weight >= num_of_edge - tmp_checked_edge){  
        dfs(temp_index, minimum, tmp_checked_vertex_not, tmp_checked_edge_not, tmp_info_not, tmp_searched_not);  
    }  
    searched.erase(index);  
    return;  
}  
  
int main(){  
    // 读取的边  
    int u = 0, v = 0;  
    // 记录已经寻找到的点数， 边数  
    int checked_vertex, checked_edge;  
    // 保存边的信息  
    std::map<int, std::map<int, int> > info;  
    // 保存已经搜索的点的信息  
    std::map<int, int> searched;  
    // 开始读取  
    //scanf("%d", &num_of_test);  
    //for (int i = 0; i < num_of_test; i++){  
        info.clear();  
        searched.clear();  
        result_vertex_list.clear();  
        scanf("%d %d %d", &num_of_vertex, &num_of_edge, &k);  
        // 初始化  
        checked_vertex = 0, checked_edge = 0;  
        // 读取数据  
        for (int j = 0; j < num_of_edge; j++){  
            scanf("%d %d", &u, &v);  
            info[u][v] = 1;  
            info[v][u] = 1;  
        }  
        // 处理度为1的点  
        deal_with_degree_one(info, searched, checked_vertex, checked_edge);  
        // 需要传送的参数  
        int minimum = k+1;  
        // 如果去除了为1的点之后已经所有的边都去掉了  
        if (checked_edge == num_of_edge){  
            if (checked_vertex < minimum){  
                minimum = checked_vertex;  
                result_vertex_list.clear();  
                for (std::map<int, int>::iterator iter = searched.begin(); iter != searched.end(); iter++)  
                    result_vertex_list.push_back(iter->first);  
            }  
        } else {  
            // 仍然有边剩余，进行处理  
            // int minimum = k+1;  
            int temp_index = 0, tmp_max_length = 0;  
            for (std::map<int, std::map<int, int> >::iterator iter = info.begin(); iter != info.end(); iter++){  
                if (searched.count(iter->first) == 0){  
                    int tmp_length = iter->second.size();  
                    if (tmp_length > tmp_max_length){  
                        temp_index = iter->first;  
                        tmp_max_length = tmp_length;  
                    }  
                }  
            }  
            dfs(temp_index, &minimum, checked_vertex, checked_edge, info, searched);   
        }  
        // 如果找不到小等于k个节点的情况则输出-1，否则输出点数和一种结果的情况  
        if (minimum > k){  
            printf("%d\n", -1);  
        } else {  
            printf("%d\n", minimum);  
            for (std::vector<int>::iterator iter = result_vertex_list.begin(); iter != result_vertex_list.end(); iter++)  
                printf("%d ", *iter);  
            printf("\n");  
        }  
   // }  
    return 0;  
}  
