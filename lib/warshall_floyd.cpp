#include <iostream>
#include <vector>
#include <algorithm>

constexpr long long INFL = (1LL << 60);

// ワーシャルフロイド法 (1.1 基本実装)
// 負閉路が存在する場合 true を返す
bool FloydWarshall(std::vector<std::vector<long long>>& distances)
{
	const size_t v = distances.size();

	for (size_t i = 0; i < v; ++i)
	{
		for (size_t from = 0; from < v; ++from)
		{
			for (size_t to = 0; to < v; ++to)
			{
				if ((distances[from][i] < INFL) && (distances[i][to] < INFL))
				{
					distances[from][to] = std::min(distances[from][to], (distances[from][i] + distances[i][to]));
				}
			}
		}
	}

	for (size_t i = 0; i < v; ++i)
	{
		// 負閉路が含まれている場合, distances[i][i] が負になるような i が存在する
		if (distances[i][i] < 0)
		{
			return true;
		}
	}

	return false;
}