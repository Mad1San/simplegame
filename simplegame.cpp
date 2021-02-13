#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
public:
    int id, rank;
    string name;
    Player(int t_id, string t_name)
    {
        id = t_id;
        rank = rand() % 100;
        name = t_name;
    }
    Player()
    {
        id = 0;
        rank = 0;
        name = "name";
    }

};


class Hero
{
public:
    int id, hp, damage;
    string name;
    Hero(int t_id, string t_name)
    {
        id = t_id;
        hp = rand() % 1000;
        damage = rand() % 300;
        name = t_name;
    }
    Hero()
    {
        id = 0;
        hp = 0;
        damage = 0;
        name = "name";
    }
    
};


class PlayerManager 
{
public:
    string arr_name[10]{ "W1zarD", "AnGeL", "Haker", "DoNaT1k", "В_КеДАхХх", "ShOoTeR", "FeNiKs", "3JIou_4uTeP", "4eJIoBeK", "4eByRaShKa"};
    
    Player CreatePlayer(int a_id)
    {
        Player player = Player(a_id, arr_name[a_id]);
        return player;
    }

    void GetPlayerByName()
    {

    }

    void GetPlayerById()
    {

    }

    void DeletePlayer()
    {

    }

    void ShowPlayerInfo(Player player)
    {
        cout << player.id + 1 << "\t" << player.name << "\t" << player.rank << endl;
    }



};

class HeroManeger
{
public:
    string arr_name[10]{ "Noah", "Liam", "Mason", "Jacob", "William", "Ethan", "Michael", "Alex", "James", "Daniel" };
    
    Hero CreateHero(int a_id)
    {
        Hero hero = Hero(a_id, arr_name[a_id]);
        return hero;
    };
    

    void GetHeroByName()
    {

    }

    void GetHeroById()
    {

    }

    void DeleteHero()
    {

    }

    void ShowHeroInfo(Hero hero)
    {
        cout << hero.id + 1 << "\t" << hero.name << "\t" << hero.hp << "\t" << hero.damage << endl;
    }

};

class Team 
{ 
public:
    string name;
    vector<Player>p_list;
    vector<Hero>h_list;
    int i, i_t;
    Team(int t_call, string t_name) {
        name = t_name;
        PlayerManager player;
        HeroManeger hero;
        if (t_call == 1) {
            i = 0;
            i_t = 5;
        }
        else {
            i = 5;
            i_t = 10;
        }
        for (i ; i < i_t; i++)
        {
            h_list.push_back(hero.CreateHero(i));
            p_list.push_back(player.CreatePlayer(i));
        }
    
    };
    Team() {
        name = "None";
    }
    

};

class TeamManager
{
public:
    Team GenereteNewTeam(int call,string call_name)
    {
        Team team = Team(call,call_name);
        return team;
    }

    void GetTeamInfo(Team team)
    {
        cout << "Team name: " << team.name << endl;
        for (int i = 0; i < 5; i++)
            cout << "Player name:" << team.p_list[i].name << "\tRank: "<< team.p_list[i].rank <<"\tHero: "<< team.h_list[i].name<<"\tHP: "<< team.h_list[i].hp << "\tDamage: "<< team.h_list[i].damage <<endl;
    }

};

class Sesion
{
private:
    bool startTime;
    Team teamOne, teamTwo;
    string winner;
public:
    void CalculateWinner()
    {

    }
};

class GameManager
{
public:
    void PerformGameSesion()
    {


    }

};


int main()

{
    TeamManager teamone;
    TeamManager teamtwo;
    teamone.GetTeamInfo(teamone.GenereteNewTeam(1, "Hyper"));
    cout << endl;
    teamtwo.GetTeamInfo(teamtwo.GenereteNewTeam(2, "Loper"));

}
