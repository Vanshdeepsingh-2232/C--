#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{

private:
    unordered_map<string, vector<pair<string, int>>> ADJ_LIST;
    unordered_map<string, int> final_distances;

public:
    void print_map(unordered_map<string, int> &map)
    {
        for (const auto &entry : map)
        {
            cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
        }

        cout << endl;
    }
    string to_key(pair<int, int> &p)
    {
        string s = to_string(p.first) + "," + to_string(p.second);
        return s;
    }
    pair<int, int> to_pair(string s)
    {
        // Find the position of the comma
        size_t comma_pos = s.find(',');

        // Extract the first and second parts of the string
        string x_str = s.substr(0, comma_pos);
        string y_str = s.substr(comma_pos + 1);

        // Convert the substrings to integers
        int x = stoi(x_str);
        int y = stoi(y_str);

        // Create and return the pair
        return make_pair(x, y);
    }

    void print_adj_list()
    {
        for (const auto &entry : ADJ_LIST)
        {
            cout << "Key: " << entry.first << " -> ";
            for (const auto &pair : entry.second)
            {
                cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            cout << endl;
        }
    }
    void make_adj_list(vector<vector<int>> &points)
    {
        for (int i = 0; i < points.size(); i++)
        {
            int xi = points[i][0];
            int yi = points[i][1];
            for (int j = 0; j < points.size(); j++)
            {
                int xj = points[j][0];
                int yj = points[j][1];
                int M_distance = abs(xi - xj) + abs(yi - yj);
                if (i == j)
                    continue;
                pair<int, int> p = make_pair(xi, yi);
                string s1 = to_key(p);
                pair<int, int> p2 = make_pair(xj, yj);
                string s2 = to_key(p2);
                ADJ_LIST[s1].push_back(make_pair(s2, M_distance));
            }
        }
    }
    pair<string, int> find_minimum_edge(unordered_map<string, int> &final_distances, unordered_map<string, bool> &mst)
    {
        pair<string, int> p = make_pair("00", INT32_MAX);
        for (auto nodes : final_distances)
        {
            if (nodes.second < p.second && !mst[nodes.first])
            {
                p.first = nodes.first;
                p.second = nodes.second;
            }
        }
        return p;
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {

        unordered_map<string, bool> mst;

        make_adj_list(points);

        for (int i = 0; i < points.size(); i++)
        {
            pair<int, int> p = make_pair(points[i][0], points[i][1]);
            string s = to_key(p);
            final_distances[s] = INT32_MAX;
            mst[s] = false;
        }

        print_map(final_distances);
        for (const auto &entry : mst)
        {
            cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
        }

        cout << "________________________________________________" << endl;

        pair<int, int> s1 = make_pair(points[0][0], points[0][1]);
        string source = to_key(s1);
        // mst[source] = true;
        final_distances[source] = 0;

        cout << s1.first << "--" << s1.second << endl;
        cout << "________________________________________________" << endl;

        for (int i = 0; i < points.size(); i++)
        {
            print_map(final_distances);
            pair<string, int> min_edge = find_minimum_edge(final_distances, mst);
            cout << min_edge.first << "--" << min_edge.second << endl;
            cout << "________________________________________________" << endl;

            mst[min_edge.first] = true;

            for (auto &C_nodes : ADJ_LIST[min_edge.first])
            {
                string C_node_name = C_nodes.first;
                int C_node_distance = C_nodes.second;

                if (mst[C_node_name] == false && final_distances[C_node_name] > C_node_distance)
                {
                    final_distances[C_node_name] = C_node_distance;
                }
            }
        }
        int total_cost = 0;
        for (const auto &entry : final_distances)
        {
            total_cost += entry.second;
        }
        return total_cost;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>> input_graph = {{3, 12}, {-2, 5}, {-4, 1}};
    //[[3,12],[-2,5],[-4,1]]
    // s1.make_adj_list(input_graph);
    // s1.print_adj_list();

    cout << s1.minCostConnectPoints(input_graph);

    // cout << endl;
    // vector<string> st(10,"");
    // for (int i = 0; i < input_graph.size(); i++)
    // {
    //     pair<int, int> p = make_pair(input_graph[i][0], input_graph[i][1]);
    //     st[i] = s1.to_key(p);
    // }

    // for (int i = 0; i < st.size(); i++)
    // {
    //     cout << st[i] << "__";
    //     pair<int, int> p = s1.to_pair(st[i]);
    //     cout << p.first << "--" << p.second;
    //     cout << endl;
    // }

    return 0;
}
