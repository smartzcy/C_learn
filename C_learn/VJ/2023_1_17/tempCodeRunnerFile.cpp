    cin >> n >> m >> x;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj1[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        d1[i] = inf;
        d2[i] = inf;
    }
    d1[x] = 0;
    d2[x] = 0;
    for (int i = 1; i <= n; i++) {
        int u1 = 0, u2 = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis1[j] && (u1 == 0 || d1[j] < d1[u1])) u1 = j;
            if (!vis2[j] && (u2 == 0 || d2[j] < d2[u2])) u2 = j;
        }
        vis1[u1] = 1;
        vis2[u2] = 1;
        for (auto [v, w] : adj[u1]) {
            d1[v] = min(d1[v], d1[u1] + w);
        }
        for (auto [v, w] : adj1[u2]) {
            d2[v] = min(d2[v], d2[u2] + w);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d1[i], d2[i]);
    }
    cout << ans << endl;