#include <iostream>
#include <cmath>
using namespace std;
#include "ml_learn.h"

void reduce(double ** x,int features,int n,double factor)
{
    for(int i=0;i<features;i++)
        for(int j=0;j<n;j++)
            x[i][j] /= factor;
}
void calculateLinReg(double**x,double **w,double **y,int features,int n, int act_noise)
{
    int i,j;
    int *noise;
    noise = new int[features];
    for(i=0;i<features;i++)
        noise[i] = rand();

    for(i=0;i<n;i++)
    {
        for(j=0;j<features;j++)
            y[0][i] +=  w[0][j] * x[j][i];
        y[0][i] += w[0][j] ;
    }
}
void expand(double **ptr,double thrashold, int size)
{
    for(int i=0; i< size;i++)
    {
        if(ptr[0][i]>=thrashold)
            ptr[0][i] = 1;
        else
            ptr[0][i] = 0;
    }
}

int main()
{  
    int features,n,epoch;
    double **y_act,**x_act;
    DataFalcon X,y,X_train,X_test,y_train,y_test,weights_biases,Y_preds;
    NDimArray nd;
    LinearRegression linreg;
    logisticRegression logreg;

    cout << "How many features are there: ";
    cin>> features;
    cout << "Sample size: ";
    cin >> n;
    cout << "Enter Epoch: ";
    cin >>epoch;

    X.initilize(features,n);
    y.initilize(1,n);
    weights_biases.initilize(1,features+1);

    X.initilizeRandomData(42);
    weights_biases.initilizeRandomData(78);

    reduce(X.values(),features,n,10000);
    reduce(weights_biases.values(),1,features+1,10000);
    
    calculateLinReg(X.values(),weights_biases.values(),y.values(),features,n,1);

    nd.minMaxScaler(X.values(),X.features(),X.sampleSize(),0,1);
    nd.minMaxScaler(y.values(),1,y.sampleSize(),0,1);
    expand(y.values(),0.5,y.sampleSize());
    linreg.trainTestSplit(X,y,X_train,X_test,y_train,y_test,0.3);
    
 /*   linreg.fit(X_train,y_train,0.01,epoch,0.25);
    linreg.predict(X_test,&Y_preds);*/

    logreg.fit(X_train,y_train,0.5,epoch);
    DataFalcon y_preds = logreg.predict(X_test);
    cout << "Accuracy : " << logreg.accuracy(y_test,y_preds) << endl;
    DataFalcon confusion_matrix = logreg.confusionMatrix(y_test,y_preds);


    cout << endl ;

    for( int i=0;i<100 && i < y_test.sampleSize();i++)
        cout << y_test.values()[0][i] << " " << y_preds.values()[0][i]  << "\t";
    
    int con_size = confusion_matrix.sampleSize();

    for (int i = 0;i<con_size;i++)
    {
        cout << endl;
        for(int j=0;j<con_size;j++)
            cout << confusion_matrix.values()[i][j] << " ";
    }

/*    cout <<"R2 score is:" << linreg.R2_score(y_test,Y_preds);
    cout << endl;
    cout << "Co-efficients:" << linreg.coeff();5
    
    cout << "Intercept :" << linreg.intercept();*/


}
