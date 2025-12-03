#include <bits/stdc++.h>
using namespace std;

struct Edge {
    string to;
    double weight;
};

class Graph {
    map<string, list<Edge>> adj;

    void add_edge_one_way(const string& u, const string& v, double w) {
        auto& lst = adj[u];
        for (auto& e : lst) {
            if (e.to == v) {
                e.weight = w;
                return;
            }
        }
        lst.push_back(Edge{v, w});
    }

    void remove_edge_one_way(const string& u, const string& v) {
        auto it = adj.find(u);
        if (it == adj.end()) return;
        auto& lst = it->second;
        lst.remove_if([&](const Edge& e){ return e.to == v; });
    }

public:
    bool add_vertex(const string& id) {
        if (id.empty()) return false;
        if (!all_of(id.begin(), id.end(), ::isalpha)) return false;
        return adj.emplace(id, list<Edge>{}).second;
    }

    void remove_vertex(const string& id) {
        adj.erase(id);
        for (auto& [u, lst] : adj) {
            lst.remove_if([&](const Edge& e){ return e.to == id; });
        }
    }

    void add_edge(const string& u, const string& v, double w) {
        add_vertex(u);
        add_vertex(v);
        add_edge_one_way(u, v, w);
        add_edge_one_way(v, u, w);
    }

    void remove_edge(const string& u, const string& v) {
        remove_edge_one_way(u, v);
        remove_edge_one_way(v, u);
    }
    void change_weight(const string& u, const string& v, double new_w) {
        auto it = adj.find(u);
        if (it == adj.end()) return;
        auto& lst = it->second;
        bool found_uv = false;
        for (auto& e : lst) {
            if (e.to == v) {
                e.weight = new_w;
                found_uv = true;
                break;
            }
        }
        it = adj.find(v);
        if (it == adj.end()) return;
        auto& lst2 = it->second;
        for (auto& e : lst2) {
            if (e.to == u) {
                e.weight = new_w;
                break;
            }
        }
    }

    bool has_vertex(const string& id) const {
        return adj.find(id) != adj.end();
    }

    const map<string, list<Edge>>& adjacency() const {
        return adj;
    }

    const list<Edge>& neighbors(const string& v) const {
        auto it = adj.find(v);
        if (it == adj.end()) {
            static const list<Edge> empty;
            return empty;
        }
        return it->second;
    }

    bool empty() const {
        return adj.empty();
    }

    void print_edges() const {
        cout << "krawedzie (u - v : waga):\n";
        set<pair<string,string>> printed;
        for (const auto& [u, lst] : adj) {
            for (const auto& e : lst) {
                string a = min(u, e.to);
                string b = max(u, e.to);
                if (printed.insert({a, b}).second) {
                    cout << a << " - " << b << " : " << e.weight << "\n";
                }
            }
        }
    }
};

Graph prim_mst(const Graph& g) {
    Graph tree;
    if (g.empty()) return tree;

    const auto& adj = g.adjacency();

    using Item = tuple<double, string, string>; // (waga, z, do)

    struct Cmp {
        bool operator()(const Item& a, const Item& b) const {
            return get<0>(a) > get<0>(b); // min-kopiec
        }
    };

    priority_queue<Item, vector<Item>, Cmp> pq;
    set<string> in_mst;

    auto add_vertex_to_mst = [&](const string& v, const string& from, double w) {
        // jeśli from jest niepuste, to dodajemy krawędź from - v do drzewa
        if (!from.empty()) {
            tree.add_edge(from, v, w);
        } else {
            // początek nowego drzewa – ale wierzchołek i tak "pojawi się" przy dodaniu krawędzi
            tree.add_vertex(v);
        }

        in_mst.insert(v);

        // dodaj wszystkie krawędzie wychodzące z v
        for (const auto& e : g.neighbors(v)) {
            if (!in_mst.count(e.to)) {
                pq.emplace(e.weight, v, e.to);
            }
        }
    };

    // może być wiele spójnych składowych – przechodzimy po wszystkich wierzchołkach
    for (const auto& [start, _] : adj) {
        if (in_mst.count(start)) continue;

        // zaczynamy nowe drzewo w tym wierzchołku
        add_vertex_to_mst(start, "", 0.0);

        while (!pq.empty()) {
            auto [w, from, to] = pq.top();
            pq.pop();
            if (in_mst.count(to)) continue; // już w MST

            add_vertex_to_mst(to, from, w);
        }
    }

    return tree;
}

int main() {
    Graph g;

    // Przykładowy graf
    g.add_edge("A", "B", 4.0);
    g.add_edge("A", "C", 2.0);
    g.add_edge("B", "C", 5.0);
    g.add_edge("B", "D", 10.0);
    g.add_edge("C", "D", 3.0);
    g.add_edge("C", "E", 4.0);
    g.add_edge("D", "E", 11.0);
    g.add_edge("E", "F", -1.0); // przykład ujemnej wagi

    cout << "Graf wejsciowy:\n";
    g.print_edges();
    cout << "\n";

    Graph mst = prim_mst(g);

    cout << "MST (wynik algorytmu Prima):\n";
    mst.print_edges();

    return 0;
}
