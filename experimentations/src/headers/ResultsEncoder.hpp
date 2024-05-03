#ifndef RESULTSENCODER_HPP
#define RESULTSENCODER_HPP

#include "Graph.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

class ResultsEncoder
{
public:
    ResultsEncoder() = default;

    void write(const string &path, const string &content)
    {
        ofstream file(path, ios::app);
        if (!file.is_open())
        {
            cerr << "Error: Unable to open/create file: " << path << endl;
            return;
        }

        file << content << endl;
        file.close();
    }

    void encodeResults(const string &path, const string &graphName, const string &function, const vector<chrono::duration<double>> &times, const long long int result){
        ofstream file(path, ios::app);
        if (!file.is_open())
        {
            cerr << "Error: Unable to open/create file: " << path << endl;
            return;
        }

        file << "Graph: " << graphName << " | Function: " << function << " | Result: " << result << endl;

        double min, max, avg;
        getMinMaxAvg(times, min, max, avg);
        file << "Min: " << min * 1000 << " ms"
             << " Max: " << max * 1000 << " ms"
             << " Avg: " << avg * 1000 << " ms" << endl;

        for (size_t i = 0; i < times.size(); ++i)
        {
            file << i + 1 << ". " << times[i].count() * 1000 << " ms" << endl;
        }

        file.close();
    }

    void encodeResultsAcceleration(const string &path, const string &graphName, const string &function, const vector<chrono::duration<double>> &timesA,
        const vector<chrono::duration<double>> &timesB,  const int resultA, const int resultB, const double expectedNumerator, const double expectedDenominator){
        ofstream file(path, ios::app);
        if (!file.is_open())
        {
            cerr << "Error: Unable to open/create file: " << path << endl;
            return;
        }

        file << "Graph: " << graphName << " | Function: " << function << " | ResultA: " << resultA << " | ResultB: " << resultB << endl;

        double minA, maxA, avgA, minB, maxB, avgB;
        getMinMaxAvg(timesA, minA, maxA, avgA);
        getMinMaxAvg(timesB, minB, maxB, avgB);
        file << "Expected speedup: " << expectedNumerator/expectedDenominator 
        <<"x ("<< expectedNumerator << "/" << expectedDenominator <<")"
        << " | Actual speedup: " << avgA/avgB << "x"<< endl;

        file << "Algo A : Min: " << minA * 1000 << " ms"
             << " Max: " << maxA * 1000 << " ms"
             << " Avg: " << avgA * 1000 << " ms" << endl;

        for (size_t i = 0; i < timesA.size(); ++i)
        {
            file << i + 1 << ". " << timesA[i].count() * 1000 << " ms" << endl;
        }
        file << "Algo B : Min: " << minB * 1000 << " ms"
             << " Max: " << maxB * 1000 << " ms"
             << " Avg: " << avgB * 1000 << " ms" << endl;

        for (size_t i = 0; i < timesB.size(); ++i)
        {
            file << i + 1 << ". " << timesB[i].count() * 1000 << " ms" << endl;
        }

        file.close();
    }

private:
    void getMinMaxAvg(const std::vector<std::chrono::duration<double>> &times, double &min, double &max, double &avg){
        if (times.empty())
        {
            min = max = avg = 0.0;
            return;
        }

        min = max = times[0].count();
        double sum = 0;

        for (const auto &time : times)
        {
            double t = time.count();
            if (t < min)
            {
                min = t;
            }
            if (t > max)
            {
                max = t;
            }
            sum += t;
        }

        avg = sum / times.size();
    }
};

#endif