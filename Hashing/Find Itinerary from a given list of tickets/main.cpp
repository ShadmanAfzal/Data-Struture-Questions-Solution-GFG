#include <bits/stdc++.h>
using namespace std;


void printRoute(map<string,string> route)
{
    map<string,string>::iterator it;
    map<string,string> revereseRoute;
    for(it = route.begin(); it!=route.end();it++)
    {
        revereseRoute[it->second] = it->first;
    }
    string startingPoint;
    for(it = route.begin(); it!=route.end(); it++)
    {
        if(revereseRoute.find(it->first)==revereseRoute.end())
        {
            startingPoint = it->first;
            break;
        }
    }
    it = route.find(startingPoint);
    while(it != route.end())
    {
        cout<<it->first<<" : "<<it->second<<endl;
        it = route.find(it->second);
    }
    cout<<startingPoint<<endl;
}

int main()
{
    map<string,string> route;
    route["Chennai"] = "Banglore"; 
    route["Mumbai"] = "Delhi"; 
    route["Goa"] = "Chennai"; 
    route["Delhi"] = "Goa";

    printRoute(route); 
}