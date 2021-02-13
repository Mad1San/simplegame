#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

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
    Hero(int t_id, int t_hp, int t_damage, string t_name)
    {
        id = t_id;
        hp = t_hp;
        damage = t_damage;//rand() % 300;
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
        
        Hero hero = Hero(a_id, rand() % 1000, rand() % 305, arr_name[a_id]);
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
public:
    bool startTime = true;
    Team teamOne, teamTwo;
    string winner;
    int teamOneHP = 0, teamTwoHP = 0, teamOneDm = 0, teamTwoDm = 0, t_one_score = 0, t_two_score = 0;
    Sesion (Team team1,Team team2)
    {
        teamOne = team1;
        teamTwo = team2;
    }
    void CalculateWinner()
    {
        for (int i = 0; i < 5; i++)
        {
            teamOneHP += teamOne.h_list[i].hp;
            teamTwoHP += teamTwo.h_list[i].hp;
            teamOneDm += teamOne.h_list[i].damage;
            teamTwoDm += teamTwo.h_list[i].damage;
        }
        cout << "Team "<< teamOne.name <<" skill\nHP: " << teamOneHP << "\tDamage: " << teamOneDm << endl;
        cout << "Team "<< teamTwo.name <<" skill\nHP: " << teamTwoHP << "\tDamage: " << teamTwoDm << endl;
        if ((teamOneHP - teamTwoDm) > (teamTwoHP - teamOneDm))
        {
            winner = teamOne.name;
            t_one_score += 25;
            t_two_score -= 25;
        }
        else
        {
            winner = teamTwo.name;
            t_two_score += 25;
            t_one_score -= 25;
        }     
    }
    Sesion(){};
};

class Result
{
public:
    string team_one, team_second, winner;
    int o_score, s_score;
    Result(string t_team_one,string t_team_second,string t_winner,int t_o_score,int t_s_score)
    {
        team_one = t_team_one;
        team_second = t_team_second;
        winner = t_winner;
        o_score = t_o_score;
        s_score = t_s_score;
    };
    Result() {}
};

class GameManager : Sesion 
{
public:
    vector<Result> games;
    TeamManager teamone, teamtwo;
    Result res;
    char comm;
    string teamName;
    int sc = 0 , scc = 0;
    void PerformGameSesion()
    {
        cout << "Say your team name:";
        cin >> teamName;
        while (startTime)
        {
            Sesion ses = Sesion(teamone.GenereteNewTeam(1, teamName), teamtwo.GenereteNewTeam(2, "Loper"));
            teamone.GetTeamInfo(ses.teamOne);
            cout << endl;
            teamone.GetTeamInfo(ses.teamTwo);
            ses.CalculateWinner();
            cout << "Winer " << ses.winner << endl;
            res = Result(ses.teamOne.name, ses.teamTwo.name, ses.winner , ses.t_one_score, ses.t_two_score);
            games.push_back(res);
            cout << "\nSay 'q' to Quit\n";
            cin >> comm;
            if (comm == 'q') startTime = false;
            if (comm == 'r') {
                for (auto j : games) {
                    cout << "Team one: " << j.team_one << "\tTeam two: " << j.team_second << "\tWinner: " << j.winner << "\tScore: " << j.o_score << " " << j.s_score << endl;
                    if (j.team_second == ses.teamTwo.name) { sc += j.s_score;}
                    if (j.team_one == ses.teamOne.name) { scc += j.o_score; }
                }
            }
            cout << "Team " << ses.teamOne.name << " score: " << scc << "\nTeam " << ses.teamTwo.name << " score: " <<sc<<endl;;
        }
    }
    GameManager(){};
};


int main()

{
    srand(time(NULL));
    GameManager game;
    game.PerformGameSesion();
}
