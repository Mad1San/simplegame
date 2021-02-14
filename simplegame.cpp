#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <list>
#include <array>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player
{
public:
    int id, rank;
    string name;
    Player(int t_id, int t_rank, string t_name)
    {
        id = t_id;
        rank = t_rank;
        name = t_name;
    }
    Player() {
        id = 0;
        rank = 0;
        name = "name";
    }

    friend bool operator== (const Player& c1, const Player& c2) {
        return c1.id == c2.id;
    }

};


class Hero
{
public:
    int id, hp, damage;
    string name;
    Hero(int t_id, int t_hp, int t_damage, string t_name)
    {
        id = t_id;
        hp = t_hp;
        damage = t_damage;
        name = t_name;
    }
    Hero(){
        id = 0;
        hp = 0;
        damage = 0;
        name = "name";
    }
    
    friend bool operator== (const Hero& c1, const Hero& c2) {
        return c1.id == c2.id;
    }
    
};


class PlayerManager 
{
private:
    list<Player> m_playerList;

public:
    
    void CreatePlayer(int p_id,int p_rank, string p_name)
    {
        Player player = Player(p_id, p_rank, p_name);
        m_playerList.push_back(player);
    }

    Player GetPlayerByName(string p_name)
    {
        for (auto player : m_playerList)
        {
            if (p_name == player.name) return player;
        }
    }

    Player GetPlayerById(int p_id)
    {
        for(auto player: m_playerList)
        {
            if (p_id == player.id) return player;
        }
    }

    list<Player> GetPlayerList()
    {
        return m_playerList;
    }

    void DeletePlayer(int p_id)
    {
        for (auto player : m_playerList)
        {
            if (p_id == player.id) m_playerList.remove(player);
        }
    }
    
    void UpPlayerRank(int p_id)
    {
        for (auto player : m_playerList)
        {
            if (p_id == player.id)
            {
                m_playerList.remove(player);
                player.rank = player.rank + 25;
                m_playerList.push_back(player);
                break;
            }

        }
    }

    void DownPlayerRank(int p_id)
    {
        for (auto player : m_playerList)
        {
            if (p_id == player.id)
            {
                m_playerList.remove(player);
                player.rank = player.rank - 25;
                m_playerList.push_back(player);
                break;
            }

        }
    }
    void ShowPlayerInfo(Player player)
    {
        cout << player.id + 1 << "\t" << player.name << "\t" << player.rank << endl;
    }


};

class HeroManeger
{
private:
    list<Hero> m_heroList;
public:
    
    void CreateHero(int h_id, string h_name)
    {
        Hero hero = Hero(h_id, rand() % 1000, rand() % 305, h_name);
        m_heroList.push_back(hero);
    };
    

    Hero GetHeroByName(string h_name)
    {
        for (auto hero : m_heroList)
        {
            if (h_name == hero.name) return hero;
        }
    }

    Hero GetHeroById(int h_id)
    {
        for (auto hero : m_heroList)
        {
            if (h_id == hero.id) return hero;
        }
    }

    list<Hero> GetHeroList()
    {
        return m_heroList;
    }

    void DeleteHero(int h_id)
    {
        for (auto hero : m_heroList)
        {
            if (h_id == hero.id) m_heroList.remove(hero);
        }
    }


    void ShowHeroInfo(Hero hero)
    {
        cout << hero.id + 1 << "\t" << hero.name << "\t" << hero.hp << "\t" << hero.damage << endl;
    }

};

class Team 
{ 
public:
    array<tuple<Player,Hero>,5> team;
    string name;

    Team(string t_name, array<tuple<Player, Hero>, 5> t_team) {
        name = t_name;
        team = t_team;

    };
    Team() {
        name = "None";
    }
    

};

class TeamManager
{
public:
    Team GenereteNewTeam(list<Player> &t_playerList, list<Hero> &t_heroList)
    {
        array<tuple<Player, Hero>, 5> teamTuple;

        string name;
        cout << "say name: ";
        cin >> name;
        for (int i = 0; i < 5; i++)
        {
            Player playerTemp;
            Hero heroTemp;
            int index = rand() % t_playerList.size(), couter = 0;
            for(auto player :t_playerList)
            {
                if (index == couter)
                {
                    playerTemp = player;
                    break;
                }
                couter++;
            }
            couter = 0;
            index = rand() % t_heroList.size();
            for (auto hero : t_heroList)
            {
                if (index == couter)
                {
                    heroTemp = hero;
                    break;
                }
                couter++;
            }
           
            teamTuple[i] = tuple<Player, Hero>(playerTemp,heroTemp);
            t_heroList.remove(heroTemp);
            t_playerList.remove(playerTemp);

        }

        Team team = Team(name, teamTuple);
        return team;
    }

    void GetTeamInfo(Team &team)
    {
        cout << "Team name: " << team.name << endl;

        for (int i = 0; i < 5; i++)
            cout << "Player name:" << get<0>(team.team[i]).name << "\tRank: " << get<0>(team.team[i]).rank << "\tHero: " << get<1>(team.team[i]).name << "\tHP: " << get<1>(team.team[i]).hp << "\tDamage: " << get<1>(team.team[i]).damage << endl;
    }
    list<int> GetIdWinnerPlayer(Team& team)
    {
        list<int> playerId;
        for (int i = 0; i < 5; i++)
        {
            playerId.push_back(get<0>(team.team[i]).id);
        }
        return playerId;
    }
};

class Session
{
public:
    bool startTime = true;
    Team teamOne, teamTwo, winner , loser;

    Session (Team &team1,Team &team2)
    {
        teamOne = team1;
        teamTwo = team2;
    }
    Team CalculateWinner()
    {
        int teamOneHP = 0, teamTwoHP = 0, teamOneDm = 0, teamTwoDm = 0;
        for (int i = 0; i < 5; i++)
        {
            teamOneHP += get<1>(teamOne.team[i]).hp;
            teamTwoHP += get<1>(teamTwo.team[i]).hp;
            teamOneDm += get<1>(teamOne.team[i]).damage;
            teamTwoDm += get<1>(teamTwo.team[i]).damage;
        }
        cout << "Team "<< teamOne.name <<" skill\nHP: " << teamOneHP << "\tDamage: " << teamOneDm << endl;
        cout << "Team "<< teamTwo.name <<" skill\nHP: " << teamTwoHP << "\tDamage: " << teamTwoDm << endl;
        if ((teamOneHP - teamTwoDm) > (teamTwoHP - teamOneDm))
        {
            winner = teamOne;
            loser = teamTwo;
        }
        else
        {
            winner = teamTwo;
            loser = teamOne;
        }
        
        return winner; 
    }
    void UpTeamRank(PlayerManager &managerPlayer)  
    {
        TeamManager managerTeam;

        for (int i : managerTeam.GetIdWinnerPlayer(loser))
        {
            managerPlayer.DownPlayerRank(i);
        }
        for (int i : managerTeam.GetIdWinnerPlayer(winner))
        {
            managerPlayer.UpPlayerRank(i);
        }
    }

    Session(){};
};


class GameManager 
{
private:
    list<Session> gameSession;
public:
    GameManager(){};
    void PerformGameSession(list<Player> _pllst, list<Hero> _hrlst , PlayerManager &upplayer)
    {
        TeamManager team;
        Team teamOne = team.GenereteNewTeam(_pllst, _hrlst);
        team.GetTeamInfo(teamOne);
        Team teamTwo = team.GenereteNewTeam(_pllst, _hrlst);
        team.GetTeamInfo(teamTwo);
        Session session = Session(teamOne, teamTwo);
        Team winner = session.CalculateWinner();
        session.UpTeamRank(upplayer);
        cout << "Winner: " << winner.name  << endl;
        gameSession.push_back(session);

    }
    list<Session> GetSesion()
    {
        return gameSession;
    }
};


int main()
{
    srand(time(NULL));
    string arr_nameHero[10]{ "Noah", "Liam", "Mason", "Jacob", "William", "Ethan", "Michael", "Alex", "James", "Daniel" };
    string arr_namePlayer[10]{ "W1zarD", "AnGeL", "Haker", "DoNaT1k", "Stalin_USSR", "ShOoTeR", "FeNiKs", "3JIou_4uTeP", "cheJIoBeK", "cheByRaShKa" };
    HeroManeger h_man;
    PlayerManager p_man;
    for(int i = 0; i < 10; i++)
    {
        p_man.CreatePlayer(i , 0, arr_namePlayer[i]);
        h_man.CreateHero(i , arr_nameHero[i]);
    }
    GameManager game;
    while (true)
    {
        game.PerformGameSession(p_man.GetPlayerList(), h_man.GetHeroList(), p_man);
    }
}
