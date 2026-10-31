#define _GLIBCXX_DEBUG // чтобы видеть все сбои работы с stl контейнерами
#define ll long long // сокращение long long

#include <bits/stdc++.h>
using namespace std;

struct event { // стурктура события
    ll t; // type - входит 1, выходит -1
    ll s; // statition - номер станции
    ll b; // кайф от стояния
    ll d; // diff - выгодга от сидения
};

bool operator<(const event& e1, const event& e2) { //комапаратор для сравнения событий по возрастанию
    if (e1.s != e2.s) return e1.s < e2.s;
    return e1.t < e2.t;
    // если разны номера станций, то выбираем ту, что меньше
    // если одинаковые выбираем что раньше 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); // ускорение cin cout

    ll n, m, p; // кол-во человек, кол-во мест, кол-во остановок
    cin >> n >> m >> p;

    vector<event> events; // порядок всех событий по порядку, сначала все зашли на станция по порядку, потом вышли
    events.reserve(2*n);
    // vector потому что могут повторяться события и их будет проще сортировать
    // 2*n событий потому что каждый пассажир сначала войдет, а потом выйдет
    for (int i = 0; i < n; ++i) { // от 1 до n вклчительно потому что номера станций с 1
        ll ai, bi, ci, di; // кайф от сидения, кайф от стояния, на какой стнации вошел, на какой вышел
        cin >> ai >> bi >> ci >>di;
        ll vigoda = max(0ll, ai-bi); // если выгода <0 то и сидеть не нужно, тогда выгоды нет
        events.push_back({1, ci, bi, vigoda}); // вошел
        events.push_back({-1, di, bi, vigoda}); // вышел
    }

    sort(events.begin(), events.end()); // сортируем события при помощи компаратора

    ll total_happiness = 0; // сумма удовольствий
    ll bons_sum = 0; // сколько на данном перегоне получится выиграть
    ll base_kaif = 0; // базовое удовольствие ехать в стоя, сумма всех кто едет
    ll last_station = 1;
    multiset<ll> sitting, standing; // мультимножество стояищий и сидящих.

    // идем по событиям
    for (size_t i = 0; i < events.size(); ) {
        ll cur_station = events[i].s; // текущая станция
        ll dist = cur_station - last_station; // сколько станций проехали

        if (dist > 0) { // если проекали сколько то станций
            total_happiness += (base_kaif + bons_sum) * dist; // к общему удовольствию прибавляется произведения проеханных станций на суммарное удовольствие с бонусами текущих пасссажиров
        }

        // идем по станциям до тех пор пока не дойдем до конца или пока станция не поменяется
        while (i < events.size() && events[i].s == cur_station) {
            const auto& e = events[i]; // сокрщение кода

            if (e.t == 1) { // если кто-то входит
                base_kaif += e.b; //общее базовое удовольствие полполняется
                if (e.d > 0) { // если выигрышь больше 0
                    sitting.insert(e.d); // добавляем его выигрыш в мультимножество сидящих
                    bons_sum += e.d; // также доабвляем в сумму выигрыша
                    if (sitting.size() > m) { // но если сидящих уже больше чем вообще возможно
                        ll smallest = *sitting.begin(); // находим того, у кого самый маленький вклад
                        bons_sum -= smallest; // исключаем из суммы выигрыша
                        sitting.erase(sitting.begin()); // уступает
                        standing.insert(smallest); // стоит
                    }
                }
            }
            else { //выходит
                base_kaif -= e.b; // удается из общего базвоого удовольствия
                if (e.d > 0) { // если был полезен
                    auto it = standing.find(e.d); // 
                    if (it != standing.end()) {
                        standing.erase(it);
                    }
                    else {
                        it = sitting.find(e.d);
                        if (it != sitting.end()) {
                            bons_sum -= e.d;
                            sitting.erase(it);
                        }
                        if (!standing.empty()) { // если можно сесть теперь тому кто стоял
                            ll biggest = *standing.rbegin(); // ищем самого желающего
                            bons_sum += biggest; // прибавляем его к выигрышу
                            sitting.insert(biggest); // делаем статус сидящего
                            standing.erase(prev(standing.end())); //удаляем статус стоящего
                        }
                    }
                }
            }
            i++; // рассматриваем нового человека
        }
        last_station = cur_station; // обновляем станцию
    }
    cout << total_happiness << '\n'; // ответ и \n чтобы быстрее вывести
}
