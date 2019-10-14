#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forn1(i, n) for (ll i = 1; i <= n; i++)
#define EPS 1e-9
#define pb push_back
#define sortx(x) sort(x.begin(), x.end())

int main()
{
	// ios::sync_with_stdio(0);

	vector<pair<ll, ll>> horarios;

	ll num_clientes;
	int hora, minuto, segundo;
	int hora_saida, minuto_saida, segundo_saida;
	ll min_cadeiras = 0, cadeira = 0;
	cout << "Informe o numero total de clientes: ";
	cin >> num_clientes;

	for (ll i = 0; i < num_clientes; i++)
	{
		cout << "Informe o horario de entrada do cliente " << i + 1 << " [HH:MM:SS]: ";
		scanf("%d:%d:%d", &hora, &minuto, &segundo);
		horarios.push_back(make_pair(hora * 3600 + minuto * 60 + segundo, 0));
		cout << "Informe o horario de saida do cliente " << i + 1 << " [HH:MM:SS]: ";
		scanf("%d:%d:%d", &hora_saida, &minuto_saida, &segundo_saida);
		horarios.push_back(make_pair(hora_saida * 3600 + minuto_saida * 60 + segundo_saida, 1));
	}
	sortx(horarios);

	for (ll i = 0; i < horarios.size(); i++)
	{
		if (horarios[i].second == 0)
		{
			cadeira++;
			if (min_cadeiras < cadeira)
			{
				min_cadeiras = cadeira;
			}
		}
		if (horarios[i].second == 1)
		{
			cadeira--;
		}
	}

	cout << "Serão necessarias ";
	cout << min_cadeiras;
	cout << " cadeiras para atender todos os clientes\n";
	return 0;
}
