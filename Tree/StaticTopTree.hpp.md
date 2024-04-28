---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tree/StaticTopTree.hpp\"\ntemplate<class M>\nstruct StaticTopTree{\n\
    \    using point=M::point;\n    using path=M::path;\n    struct Node{\n      \
    \  bool is_path;\n        point point_val;\n        path path_val;\n        int32_t\
    \ pos;\n        int32_t left;\n        int32_t right;\n        int32_t parent;\n\
    \        Node(bool pat,int32_t po=-1,int32_t lf=-1,int32_t ri=-1){\n         \
    \   is_path=pat;\n            pos=po;\n            left=lf;\n            right=ri;\n\
    \            parent=-1;\n        }\n    };\n    size_t sz;\n    vector<vector<int32_t>>\
    \ tree;\n    vector<int32_t> node_pos;\n    vector<Node> nodes;\n    int32_t rt;\n\
    \    StaticTopTree(size_t size){\n        sz=size;\n        tree.resize(sz);\n\
    \        node_pos.resize(sz);\n    }\n    void add_edge(int32_t s,int32_t v){\n\
    \        tree[s].emplace_back(v);\n        tree[v].emplace_back(s);\n    }\n \
    \   int32_t _path_cluster(int32_t pos,vector<int32_t> &tree_sz){\n        if(tree[pos].empty()){\n\
    \            node_pos[pos]=nodes.size();\n            nodes.push_back(Node(1,pos));\n\
    \            _calc_val(nodes.size()-1);\n            return nodes.size()-1;\n\
    \        }\n        vector<int32_t> address;\n        vector<int32_t> sizes;\n\
    \        while(!tree[pos].empty()){\n            int32_t max_size=-1;\n      \
    \      int32_t next_pos=-1;\n            for(int i=0; i<tree[pos].size(); i++){\n\
    \                if(tree_sz[tree[pos][i]]>max_size){\n                    max_size=tree_sz[tree[pos][i]];\n\
    \                    next_pos=i;\n                }\n            }\n         \
    \   swap(tree[pos][next_pos],tree[pos].back());\n            next_pos=tree[pos].back();\n\
    \            tree[pos].pop_back();\n            tree_sz[pos]-=tree_sz[next_pos];\n\
    \            sizes.push_back(tree_sz[pos]);\n            address.push_back(_point_cluster(pos,tree_sz));\n\
    \            pos=next_pos;\n        }\n        address.push_back(_point_cluster(pos,tree_sz));\n\
    \        sizes.push_back(tree_sz[pos]);\n        return _merge(address,sizes,0,address.size(),1);\n\
    \    }\n    int32_t _point_cluster(int32_t pos,vector<int32_t> &tree_sz){\n  \
    \      if(tree[pos].empty()){\n            node_pos[pos]=nodes.size();\n     \
    \       nodes.push_back(Node(1,pos));\n            _calc_val(nodes.size()-1);\n\
    \            return nodes.size()-1;\n        }\n        vector<int32_t> address;\n\
    \        vector<int32_t> sizes;\n        for(int32_t i:tree[pos]){\n         \
    \   sizes.push_back(tree_sz[i]);\n            int32_t vert=_path_cluster(i,tree_sz);\n\
    \            nodes.push_back(Node(0,-1,vert));\n            nodes[vert].parent=nodes.size()-1;\n\
    \            address.push_back(nodes.size()-1);\n            _calc_val(nodes.size()-1);\n\
    \        }\n        int32_t vert=_merge(address,sizes,0,address.size(),0);\n \
    \       node_pos[pos]=nodes.size();\n        nodes.push_back(Node(1,pos,vert));\n\
    \        nodes[vert].parent=nodes.size()-1;\n        _calc_val(nodes.size()-1);\n\
    \        return nodes.size()-1;\n    }\n    int32_t _merge(vector<int32_t> &address,vector<int32_t>\
    \ &sizes,int32_t lf,int32_t ri,bool pat){\n        if(lf+1==ri)return address[lf];\n\
    \        int32_t add=0;\n        for(int32_t i=lf; i<ri; i++){\n            add+=sizes[i];\n\
    \        }\n        int32_t now=0;\n        int32_t bef=add+1;\n        for(int32_t\
    \ i=lf; i<ri; i++){\n            now+=sizes[i];\n            if(now>add-now){\n\
    \                if(now+now-add>bef)i--;\n                int32_t left=_merge(address,sizes,lf,i+1,pat);\n\
    \                int32_t right=_merge(address,sizes,i+1,ri,pat);\n           \
    \     nodes.push_back(Node(pat,-1,left,right));\n                nodes[left].parent=nodes.size()-1;\n\
    \                nodes[right].parent=nodes.size()-1;\n                _calc_val(nodes.size()-1);\n\
    \                return nodes.size()-1;\n            }\n            bef=add-now-now;\n\
    \        }\n        assert(false);\n    }\n    void _calc_val(int32_t pos){\n\
    \        if(nodes[pos].is_path){\n            if((nodes[pos].left==-1) && (nodes[pos].right==-1)){\n\
    \                nodes[pos].path_val=M::vertex(nodes[pos].pos);\n            }\n\
    \            else if((nodes[pos].left!=-1) && (nodes[pos].right!=-1)){\n     \
    \           nodes[pos].path_val=M::compress(nodes[nodes[pos].left].path_val,nodes[nodes[pos].right].path_val);\n\
    \            }\n            else{\n                nodes[pos].path_val=M::add_vertex(nodes[nodes[pos].left].point_val,nodes[pos].pos);\n\
    \            }\n        }\n        else{\n            if((nodes[pos].left!=-1)\
    \ && (nodes[pos].right!=-1)){\n                nodes[pos].point_val=M::rake(nodes[nodes[pos].left].point_val,nodes[nodes[pos].right].point_val);\n\
    \            }\n            else{\n                nodes[pos].point_val=M::add_edge(nodes[nodes[pos].left].path_val);\n\
    \            }\n        }\n    }\n    void build(int32_t root){\n        vector<int32_t>\
    \ vert(sz);\n        vector<int32_t> tree_sz(sz,-1);\n        vert[0]=root;\n\
    \        tree_sz[0]=0;\n        int32_t cnt=1;\n        for(int32_t i=0; i<sz;\
    \ i++){\n            for(int32_t j:tree[vert[i]]){\n                if(tree_sz[j]){\n\
    \                    tree_sz[j]=0;\n                    vert[cnt]=j;\n       \
    \             cnt++;\n                }\n            }\n        }\n        for(int32_t\
    \ i=sz-1; i>=0; i--){\n            int32_t parent=0;\n            for(int32_t\
    \ j:tree[vert[i]]){\n                if(tree_sz[j]==0){\n                    parent=-parent-1;\n\
    \                }\n                if(parent>=0)parent++;\n                tree_sz[vert[i]]+=tree_sz[j];\n\
    \            }\n            if(parent<0){\n                swap(tree[vert[i]][-parent-1],tree[vert[i]].back());\n\
    \                tree[vert[i]].pop_back();\n            }\n            tree_sz[vert[i]]++;\n\
    \        }\n        rt=_path_cluster(root,tree_sz);\n    }\n    path root_value(){\n\
    \        return nodes[rt].path_val;\n    }\n    void calc(int32_t pos){\n    \
    \    int32_t change=node_pos[pos];\n        while(nodes[change].parent!=-1){\n\
    \            _calc_val(change);\n            change=nodes[change].parent;\n  \
    \      }\n        _calc_val(change);\n    }\n    size_t size(){\n        return\
    \ sz;\n    }\n};\n"
  code: "#pragma once\ntemplate<class M>\nstruct StaticTopTree{\n    using point=M::point;\n\
    \    using path=M::path;\n    struct Node{\n        bool is_path;\n        point\
    \ point_val;\n        path path_val;\n        int32_t pos;\n        int32_t left;\n\
    \        int32_t right;\n        int32_t parent;\n        Node(bool pat,int32_t\
    \ po=-1,int32_t lf=-1,int32_t ri=-1){\n            is_path=pat;\n            pos=po;\n\
    \            left=lf;\n            right=ri;\n            parent=-1;\n       \
    \ }\n    };\n    size_t sz;\n    vector<vector<int32_t>> tree;\n    vector<int32_t>\
    \ node_pos;\n    vector<Node> nodes;\n    int32_t rt;\n    StaticTopTree(size_t\
    \ size){\n        sz=size;\n        tree.resize(sz);\n        node_pos.resize(sz);\n\
    \    }\n    void add_edge(int32_t s,int32_t v){\n        tree[s].emplace_back(v);\n\
    \        tree[v].emplace_back(s);\n    }\n    int32_t _path_cluster(int32_t pos,vector<int32_t>\
    \ &tree_sz){\n        if(tree[pos].empty()){\n            node_pos[pos]=nodes.size();\n\
    \            nodes.push_back(Node(1,pos));\n            _calc_val(nodes.size()-1);\n\
    \            return nodes.size()-1;\n        }\n        vector<int32_t> address;\n\
    \        vector<int32_t> sizes;\n        while(!tree[pos].empty()){\n        \
    \    int32_t max_size=-1;\n            int32_t next_pos=-1;\n            for(int\
    \ i=0; i<tree[pos].size(); i++){\n                if(tree_sz[tree[pos][i]]>max_size){\n\
    \                    max_size=tree_sz[tree[pos][i]];\n                    next_pos=i;\n\
    \                }\n            }\n            swap(tree[pos][next_pos],tree[pos].back());\n\
    \            next_pos=tree[pos].back();\n            tree[pos].pop_back();\n \
    \           tree_sz[pos]-=tree_sz[next_pos];\n            sizes.push_back(tree_sz[pos]);\n\
    \            address.push_back(_point_cluster(pos,tree_sz));\n            pos=next_pos;\n\
    \        }\n        address.push_back(_point_cluster(pos,tree_sz));\n        sizes.push_back(tree_sz[pos]);\n\
    \        return _merge(address,sizes,0,address.size(),1);\n    }\n    int32_t\
    \ _point_cluster(int32_t pos,vector<int32_t> &tree_sz){\n        if(tree[pos].empty()){\n\
    \            node_pos[pos]=nodes.size();\n            nodes.push_back(Node(1,pos));\n\
    \            _calc_val(nodes.size()-1);\n            return nodes.size()-1;\n\
    \        }\n        vector<int32_t> address;\n        vector<int32_t> sizes;\n\
    \        for(int32_t i:tree[pos]){\n            sizes.push_back(tree_sz[i]);\n\
    \            int32_t vert=_path_cluster(i,tree_sz);\n            nodes.push_back(Node(0,-1,vert));\n\
    \            nodes[vert].parent=nodes.size()-1;\n            address.push_back(nodes.size()-1);\n\
    \            _calc_val(nodes.size()-1);\n        }\n        int32_t vert=_merge(address,sizes,0,address.size(),0);\n\
    \        node_pos[pos]=nodes.size();\n        nodes.push_back(Node(1,pos,vert));\n\
    \        nodes[vert].parent=nodes.size()-1;\n        _calc_val(nodes.size()-1);\n\
    \        return nodes.size()-1;\n    }\n    int32_t _merge(vector<int32_t> &address,vector<int32_t>\
    \ &sizes,int32_t lf,int32_t ri,bool pat){\n        if(lf+1==ri)return address[lf];\n\
    \        int32_t add=0;\n        for(int32_t i=lf; i<ri; i++){\n            add+=sizes[i];\n\
    \        }\n        int32_t now=0;\n        int32_t bef=add+1;\n        for(int32_t\
    \ i=lf; i<ri; i++){\n            now+=sizes[i];\n            if(now>add-now){\n\
    \                if(now+now-add>bef)i--;\n                int32_t left=_merge(address,sizes,lf,i+1,pat);\n\
    \                int32_t right=_merge(address,sizes,i+1,ri,pat);\n           \
    \     nodes.push_back(Node(pat,-1,left,right));\n                nodes[left].parent=nodes.size()-1;\n\
    \                nodes[right].parent=nodes.size()-1;\n                _calc_val(nodes.size()-1);\n\
    \                return nodes.size()-1;\n            }\n            bef=add-now-now;\n\
    \        }\n        assert(false);\n    }\n    void _calc_val(int32_t pos){\n\
    \        if(nodes[pos].is_path){\n            if((nodes[pos].left==-1) && (nodes[pos].right==-1)){\n\
    \                nodes[pos].path_val=M::vertex(nodes[pos].pos);\n            }\n\
    \            else if((nodes[pos].left!=-1) && (nodes[pos].right!=-1)){\n     \
    \           nodes[pos].path_val=M::compress(nodes[nodes[pos].left].path_val,nodes[nodes[pos].right].path_val);\n\
    \            }\n            else{\n                nodes[pos].path_val=M::add_vertex(nodes[nodes[pos].left].point_val,nodes[pos].pos);\n\
    \            }\n        }\n        else{\n            if((nodes[pos].left!=-1)\
    \ && (nodes[pos].right!=-1)){\n                nodes[pos].point_val=M::rake(nodes[nodes[pos].left].point_val,nodes[nodes[pos].right].point_val);\n\
    \            }\n            else{\n                nodes[pos].point_val=M::add_edge(nodes[nodes[pos].left].path_val);\n\
    \            }\n        }\n    }\n    void build(int32_t root){\n        vector<int32_t>\
    \ vert(sz);\n        vector<int32_t> tree_sz(sz,-1);\n        vert[0]=root;\n\
    \        tree_sz[0]=0;\n        int32_t cnt=1;\n        for(int32_t i=0; i<sz;\
    \ i++){\n            for(int32_t j:tree[vert[i]]){\n                if(tree_sz[j]){\n\
    \                    tree_sz[j]=0;\n                    vert[cnt]=j;\n       \
    \             cnt++;\n                }\n            }\n        }\n        for(int32_t\
    \ i=sz-1; i>=0; i--){\n            int32_t parent=0;\n            for(int32_t\
    \ j:tree[vert[i]]){\n                if(tree_sz[j]==0){\n                    parent=-parent-1;\n\
    \                }\n                if(parent>=0)parent++;\n                tree_sz[vert[i]]+=tree_sz[j];\n\
    \            }\n            if(parent<0){\n                swap(tree[vert[i]][-parent-1],tree[vert[i]].back());\n\
    \                tree[vert[i]].pop_back();\n            }\n            tree_sz[vert[i]]++;\n\
    \        }\n        rt=_path_cluster(root,tree_sz);\n    }\n    path root_value(){\n\
    \        return nodes[rt].path_val;\n    }\n    void calc(int32_t pos){\n    \
    \    int32_t change=node_pos[pos];\n        while(nodes[change].parent!=-1){\n\
    \            _calc_val(change);\n            change=nodes[change].parent;\n  \
    \      }\n        _calc_val(change);\n    }\n    size_t size(){\n        return\
    \ sz;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Tree/StaticTopTree.hpp
  requiredBy: []
  timestamp: '2024-04-28 21:17:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Tree/StaticTopTree.hpp
layout: document
redirect_from:
- /library/Tree/StaticTopTree.hpp
- /library/Tree/StaticTopTree.hpp.html
title: Tree/StaticTopTree.hpp
---
