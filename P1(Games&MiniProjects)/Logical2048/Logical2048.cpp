#include <iostream>
using namespace std;

int m[1024][1024];
int M;

void FnL()
{
    bool check = false;
    while(!check){
        check = true;

        for(int i = 0; i < M; i++){
            for(int j = M - 1; j > 0; j--){
                if (m[i][j] != 0 && m[i][j-1] == 0){
                    m[i][j-1] = m[i][j];
                    m[i][j] = 0;
                    j = j + 2;
                }
            }
        }

        for(int i = 0; i < M; i++){
            int j = 0;
            while(m[i][j+1] != 0 && check == true){
                if(m[i][j+1] % m[i][j] == 0)
                    check = false;
                j++;
            }
        }

        if(!check)
            for(int i = 0; i < M; i++){
                int j = 0;
                while(m[i][j+1] != 0){
                    if(m[i][j+1] % m[i][j] == 0){
                        m[i][j+1] = m[i][j+1] - m[i][j];
                        m[i][j] = m[i][j] * 2;
                        if(m[i][j+1] == 0)
                            j++;
                    }
                    j++;
                }
            }

    }
}


void FnG()
{
    bool check = false;
    while(!check){
        check = true;

        for(int i = 0; i < M; i++){
            for(int j = M - 1; j > 0; j--){
                if (m[j][i] != 0 && m[j-1][i] == 0){
                    m[j-1][i] = m[j][i];
                    m[j][i] = 0;
                    j = j + 2;
                }
            }
        }

        for(int i = 0; i < M; i++){
            int j = 0;
            while(m[j+1][i] != 0 && check == true){
                if(m[j+1][i] % m[j][i] == 0)
                    check = false;
                j++;
            }
        }

        if(!check)
            for(int i = 0; i < M; i++){
                int j = 0;
                while(m[j+1][i] != 0){
                    if(m[j+1][i] % m[j][i] == 0){
                        m[j+1][i] = m[j+1][i] - m[j][i];
                        m[j][i] = m[j][i] * 2;
                        if(m[j+1][i] == 0)
                            j++;
                    }
                    j++;
                }
            }

    }
}


void FnP()
{
    bool check = false;
    while(!check){
        check = true;

        for(int i = 0; i < M; i++){

            for(int j = 0; j < M - 1; j++){
                if (m[i][j] != 0 && m[i][j+1] == 0){
                    m[i][j+1] = m[i][j];
                    m[i][j] = 0;
                    if(j != 0)
                        j = j - 2;
                }
            }
        }

        for(int i = 0; i < M; i++){
            int j = M - 1;
            while(m[i][j-1] != 0 && check == true){
                if(m[i][j-1] % m[i][j] == 0)
                    check = false;
                j--;
            }
        }

        if(!check)
            for(int i = 0; i < M; i++){
                int j = M - 1;
                while(m[i][j-1] != 0 && j > 0){
                    if(m[i][j-1] % m[i][j] == 0){
                        m[i][j-1] = m[i][j-1] - m[i][j];
                        m[i][j] = m[i][j] * 2;
                        if(m[i][j-1] == 0)
                            j--;
                    }
                    j--;
                }
            }

    }
}


void FnD()
{
    bool check = false;
    while(!check){
        check = true;
        //
        for(int i = 0; i < M; i++){

            for(int j = 0; j < M - 1; j++){
                if (m[j][i] != 0 && m[j+1][i] == 0){
                    m[j+1][i] = m[j][i];
                    m[j][i] = 0;
                    if(j != 0)
                        j = j - 2;
                }
            }
        }

        for(int i = 0; i < M; i++){
            int j = M - 1;
            while(m[j-1][i] != 0 && check == true){
                if(m[j-1][i] % m[j][i] == 0)
                    check = false;
                j--;
            }
        }

        if(!check)
            for(int i = 0; i < M; i++){
                int j = M - 1;
                while(m[j-1][i] != 0 && j > 0){
                    if(m[j-1][i] % m[j][i] == 0){
                        m[j-1][i] = m[j-1][i] - m[j][i];
                        m[j][i] = m[j][i] * 2;
                        if(m[j-1][i] == 0)
                            j--;
                    }
                    j--;
                }
            }

    }
}


void FnW()
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << m[i][j];
            if (j < M - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}


void FnN()
{
    int x, y, w;
    cin >> x >> y >> w;
    m[x][y] = w;
}


void FnS()
{
    long long sum = 0;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            sum = sum + m[i][j];
    cout << sum << endl;
}

void FnC()
{
    cin >> M;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            cin >> m[i][j];
}


int main()
{

    char a;
    cin >> M;
    while(cin >> a)
    {

        switch(a)
        {
            case 'W': FnW();

            break;
            case 'L': FnL(); break;
            case 'G': FnG(); break;
            case 'P': FnP(); break;
            case 'D': FnD(); break;
            case 'N': FnN(); break;
            case 'C': FnC(); break;
            case 'S': FnS(); break;
            case 'K': FnS(); break;

        }

    }
    return 0;
}

