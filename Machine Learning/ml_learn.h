#include<time.h>
#include<cmath>
#include<chrono>
#include <fstream>
using namespace chrono;

class DataFalcon
{
    string *column;
    string **object_data;
    long long **integer_data;
    double **floating_point_data;
    unsigned int sample_size,no_of_features;

    void read_line(string line)
    {
        string * word;
        int count=0,i,j ;
        for (int i=0;i<line.length();i++)
            if(line[i] == ',')
                count ++;
        count++;
        word = new string[count];
        no_of_features = count;

        j=0;
        for(i=0;i<count;i++)
        {
            for(;j<line.length();j++)
            {
                if(line[j]!= ',')
                    word[i] = word[i] + line[j];
                else 
                {
                    j++;    
                    break;
                }
            }
        }

        for(i=0;i<count;i++)
            cout << word[i] << "\t" ;
        cout << endl;
    }

    // Process word parameters: 1. takes string pointer 
    void process_words(string * word)
    {
        int i;
        for (i=0;i<no_of_features;i++)
        {
            if( word[i][0] == '"')
            {

            }
        }
        
    }

    public:
    void initilize(unsigned int Features,unsigned int sampleSize)
    {
        //cout << endl << ">>>>>Initilizing DataFalcon Object<<<<<  " ;
        sample_size = sampleSize;
        no_of_features = Features;
        floating_point_data = new double * [no_of_features];
        for(int i=0;i<no_of_features;i++)
            floating_point_data[i] = new double[sample_size];

        //cout << ":Completed!" << endl;
    }

    void read_csv(string file_name)
    {
        ifstream fp;
        string line;
        string **word;
        fp.open(file_name);
        int i=0;
        while(fp)
        {
            getline(fp, line);
            //cout << line << endl;
            read_line(line);
            
            int count=0,i,j ;
            for (int i=0;i<line.length();i++)
                if(line[i] == ',')
                    count ++;
            count++;
            word = new string[count];
            no_of_features = count;

            j=0;
            for(i=0;i<count;i++)
            {
                for(;j<line.length();j++)
                {
                    if(line[j]!= ',')
                        word[i] = word[i] + line[j];
                    else 
                    {
                        j++;    
                        break;
                    }
                }
            }

            for(i=0;i<count;i++)
                cout << word[i] << "\t" ;
            cout << endl;
            break;
        }

        fp.close();
    }


    double ** values()
    {
        return floating_point_data;
    }

    unsigned int sampleSize()
    {
        return sample_size;
    }

    unsigned int features()
    {
        return no_of_features;
    }

    void initilizeData(double ** ptr)
    {
        for (int i =0;i<no_of_features;i++)
            for(int j=0;j<sample_size;j++)
                floating_point_data[i][j] = ptr[i][j];
    }

    void initilizeRandomData(int random_state)
    {
        //cout << ">>>>>Initilizing with Data to DataFalcon Object<<<<<  ";
        time_t t;
        srand((unsigned) time(&t) - random_state);

        for( int i=0; i<no_of_features; i++)
            for(int j=0;j<sample_size;j++)
                floating_point_data[i][j] =(double)rand();
        
        //cout << ":Completed!" << endl;
    }

    void head()
    {
        for(int i=0;i<no_of_features;i++)
        {
            for(int j=0;j<sample_size && j<5 ;j++)
                cout << floating_point_data[i][j] << "\t";
            cout << endl;
        }
    }

 /*   ~DataFalcon()
    {
        for(int i=0;i<no_of_features;i++)
        {    
            delete [] X[i];
        }
        delete [] X;
    }*/

};


class NDimArray
{
    public:
        // >>>>>Find max in a array<<<<<
        double maxElem(double *x,int n)
        {
            double max = -2147483648.0;
            for(int i=0;i<n;i++)
                if(max<x[i])
                    max = x[i];
            return max;
        }

        // >>>>>Find min in a array<<<<<
        double minElem(double *x,int n)
        {
            double min = 2147483647.0;
            for(int i=0;i<n;i++)
                if(min>x[i])
                    min = x[i];
            return min;
        }

        // >>>>>Find average/mean of a array<<<<<
        double meanCal(double *x,int n)
        {
            double sum =0.0;
            for(int i=0;i<n;i++)
            sum +=x[i];
            return ((double)sum/n);
        }

        // Average of serise
        double average(double *x,int n)
        {
            int i;
            double sum = 0.0;
            for(i=0;i<n;i++)
            {
                sum += x[i];
            }
            return ((double)sum/n);
        }

        // >>>>>Min Max Scaler<<<<<
        void minMaxScaler(double ** x,int features,int n,double lower_bound,double upper_bound)
        {
            double min,max,dif,bound_dif;
            int i,j;
            bound_dif = upper_bound - lower_bound;
            for(i=0;i<features;i++)
            {
                min = minElem(x[i],n);
                max = maxElem(x[i],n);
                dif = max-min;
                for(j=0;j<n;j++)
                    x[i][j] = lower_bound+ ((x[i][j] - min) / dif * bound_dif);
            }
        }

        // >>>>>Standard Deviation<<<<<
        double standardDeviation(double *x,int n)
        {
            double mean,stdDiv=0;
            int i;
            mean = meanCal(x,n);
            for(i=0;i<n;i++)
                stdDiv += pow((x[i] - mean),2);
            stdDiv /=(double)n;
            return sqrt(stdDiv);

        }

        // >>>>>Normal Scaler<<<<<
        void standardScaler(double **x,int features,int n)
        {
            double mean, stdDiv;
            int i,j;
            for(i=0;i<features;i++)
            {
                mean = meanCal(x[i],n);
                stdDiv = standardDeviation(x[i],n);
                for(j=0;j<n;j++)
                    x[i][j] = (x[i][j] - mean)/stdDiv;
            }

        }

        DataFalcon nUnique(double * ptr,int size)
        {
            DataFalcon df;
            int unique,k,flag;
            double *p = new double[size];

            unique = k = 0;

            for (int i=0;i<size;i++)
            {
                flag = 0;
                for(int j=0;j<k;j++)
                {   
                    if(ptr[i]==p[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    unique ++;
                    p[k++] = ptr[i];
                }
            }

            df.initilize(1,unique);
            df.initilizeData(reshape(p,unique));
            df.head();

            return df;
        }

        double ** reshape(double * ptr,int size)
        {
            double ** pt = new double * [1];
            pt[0] = new double [size];
            for(int i =0;i<size;i++)
                pt[0][i] = ptr[i];

            return pt;
        }
};


class LinearRegression
{
    // Weights & Biases
    DataFalcon Weights_Biases;

    public:
        // >>>>>R2 score<<<<<
        double R2_score(DataFalcon Y_act,DataFalcon y_pred)
        {
            int i,j,k,sample_size;
            double sum_of_resedual, sum_of_avg_total,Y_avg,r2_score;
            NDimArray ndarray;
            double ** Y, ** y;

            Y = Y_act.values();
            y = y_pred.values();
            sample_size = Y_act.sampleSize();         
            sum_of_resedual = sum_of_avg_total = 0.0;
            Y_avg = ndarray.average(Y[0],sample_size);

            for(i=0;i<sample_size;i++)
            {
                sum_of_resedual += pow((Y[0][i]-y[0][i]),2);
                sum_of_avg_total += pow((Y[0][i]-Y_avg),2);
            }
            r2_score = 1 - (sum_of_resedual/sum_of_avg_total);
            return r2_score;
        }

        // >>>>>Train Test Split<<<<<
        void trainTestSplit(DataFalcon X,DataFalcon y,DataFalcon &X_train,DataFalcon &X_test,DataFalcon &y_train,DataFalcon &y_test, double split_ratio )
        {
            cout <<endl << ">>>>>Train Test Split<<<<< " ; 
            int i,j,k,index,flag,*test_ptr;
            unsigned int total_sample_size,train_sample_size,test_sample_size,features;
            double **X_act,**y_act,** X_Test,**X_Train,**y_Train, **y_Test;

            total_sample_size = X.sampleSize();
            test_sample_size = total_sample_size * split_ratio;
            train_sample_size = total_sample_size - test_sample_size;
            features = X.features();
            test_ptr = new int [test_sample_size];

            X_train.initilize(features,train_sample_size);
            X_test.initilize(features,test_sample_size);
            y_train.initilize(1,train_sample_size);
            y_test.initilize(1,test_sample_size);

            X_Train = X_train.values();
            X_Test = X_test.values();
            y_Train = y_train.values();
            y_Test = y_test.values();
            X_act = X.values();
            y_act = y.values();

            for(i=0;i<test_sample_size;i++)
                test_ptr[i] = -1;

            // Testing dataset creation
            i=0;
            do
            {
                index = rand() % total_sample_size;
                flag = 0;
                for(j=0;j<=i;j++)
                {
                    if(index == test_ptr[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag==0)
                {
                    test_ptr[i] = index;
                    for(j=0;j<features;j++)
                        X_Test[j][i] = X_act[j][index];
                    y_Test[0][i++] = y_act[0][index]; 
                }
                    
            } while (i<test_sample_size);

            // Training dataset creation
            k=0;
            for(i=0;i<total_sample_size;i++)
            {
                flag=0;
                for(j=0;j<test_sample_size;j++)
                {
                    if(i==test_ptr[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    for(j=0;j<features;j++)
                        X_Train[j][k] = X_act[j][i];
                    y_Train[0][k++] = y_act[0][i];
                }
            }
            cout << "Completed";

            
        }

        // >>>>>Stocastic Gradient Descent<<<<<
        void fit(DataFalcon X,DataFalcon y_target, double l_r, int epoch)
        {
            cout << endl << ">>>>>Stocastic Gradient Descent<<<<<";

            time_t start, end;
            start = clock();

            NDimArray ndarray;
            double ** weights_Biases,**X_act, **y_act;
            unsigned int sample_size, features;
            double Y_not,Y;
            int i,j,k, random;
            

            X_act = X.values();
            y_act = y_target.values();
            sample_size = X.sampleSize();
            features = X.features();
            Weights_Biases.initilize(1,features+1);
        
            // Initilize weights and biases
            Weights_Biases.initilizeRandomData(60);
            weights_Biases = Weights_Biases.values();
            for(i=0;i<=features;i++)
                weights_Biases[0][i] /= 10000.0f;

            // Epoch
            for(i=0; i<epoch; i++ )
            {
                // Initilize index
                j = rand()%sample_size;
                Y = 0;
                // Calculate y
                for(k=0;k<features;k++)
                    Y += weights_Biases[0][k]* X.values()[k][j];
                Y += weights_Biases[0][k];
                Y_not = Y - y_act[0][j];
                // Updating weights and biases;
                for(k=0;k<features;k++) 
                    weights_Biases[0][k] -= l_r * (2 * Y_not * X_act[k][j]);
                weights_Biases[0][k] -= l_r * 2 * Y_not;
            }
            end = clock();
            double duration = double(end-start)/double(CLOCKS_PER_SEC);
            cout << " Time taken: " << duration <<"s" << endl;
        }

        // >>>>>Minibatch Gradient Descent<<<<< 
        void fit(DataFalcon X, DataFalcon y, double l_r, int epoch, double batch)
        {
            cout << endl << ">>>>>Mini-batch Gradient Descent<<<<<";
            time_t start, end;
            // Initilize batch size
            start = clock();
            double **X_act,**y_act,**weights_biases,*Y, *dw,Y_not;
            int batch_size, *index,features,sample_size;
            int i, j, k, l;
            
            sample_size = X.sampleSize();
            batch_size = batch * X.sampleSize();
            features = X.features();
            X_act = X.values();
            y_act = y.values();
            dw = new double [features];
            Y = new double [batch_size];
            index = new int [batch_size];

            // Randowm Initilization of Weightes and Biases
            Weights_Biases.initilize(1,features+1);
            Weights_Biases.initilizeRandomData(32);
            weights_biases = Weights_Biases.values();
            for(i=0;i<=features;i++)
                weights_biases[0][i] /= 10000.0f;
                
            //Initilize weights and biases
            for( i=0; i<epoch; i++ )
            {
                //Initilize axulary variables
                Y_not = 0.0f;
                    
                // Starting epoch
                for(k=0;k<batch_size;k++)
                {
                    // Initilize index
                    j = (int)rand() % sample_size;
                    Y[k]= 0.0f;        // Initilize Y to zero
                    index[k] = j; 

                    // Calculate Y
                    for(l=0; l<features;l++)
                        Y[k] += weights_biases[0][l] * X_act[l][j];
                    Y[k] += weights_biases[0][l];

                    // Calculate deviation
                    Y_not += Y[k] - y_act[0][j];
                }

                // Taking avg of dw
                for(k=0;k<features;k++)
                {
                    dw[k] = 0.0f;
                    for(l=0;l<batch_size;l++)
                        dw[k] += (Y[l] - y_act[0][index[l]]) * X_act[k][index[l]];
                    dw[k] *= 2;
                    dw[k] /= batch_size;
                }                

                Y_not /= batch_size;   
                
                // Updating weights and biases
                for(k=0;k<features;k++)
                    weights_biases[0][k] -= l_r * dw[k] ;
                weights_biases[0][k] -= l_r * 2 * Y_not ;
            }
            free(dw);
            free(Y);
            free(index);

            end = clock();
            double duration = double(end-start)/double(CLOCKS_PER_SEC);
            cout << " Time taken: " << duration << "s" << endl;


        }

        // >>>>>Predict Function<<<<<
        void predict(DataFalcon X,DataFalcon * Y_preds)
        {
            double ** y_predicts,**X_val, **weights_Biases;
            int i,j,k,sample_size,features;

            Y_preds->initilize(1,X.sampleSize());
            sample_size = X.sampleSize();
            features = X.features();
            X_val = X.values();
            y_predicts = Y_preds->values();
            weights_Biases = Weights_Biases.values();

            for(i=0;i<sample_size;i++)
            {
                y_predicts[0][i] = 0;
                for(j=0;j<features;j++)
                    y_predicts[0][i] += weights_Biases[0][j] * X_val[j][i];
                y_predicts[0][i] +=  weights_Biases[0][j];
            }
        }

        // >>>>>Returning and print coefficient value<<<<<
        double * coeff()
        {
            double ** ptr = Weights_Biases.values();
            for(int i=0;i<(Weights_Biases.sampleSize()-1);i++)
            {
                cout << ptr[0][i] << " ";      
            }
            cout << endl;
            return ptr[0];
        }

        // >>>>>Returning and printing intercept value<<<<<
        double intercept()
        {
            double ** ptr = Weights_Biases.values();
            cout <<ptr[0][Weights_Biases.sampleSize()-1] << endl;
            return ptr[0][Weights_Biases.sampleSize()-1];
        }

};

class logisticRegression
{
    DataFalcon Weights_Biases;
    public:
        void fit(DataFalcon X,DataFalcon y_target, double l_r, int epoch)
        {
            cout << endl << ">>>>>Logistic Regression<<<<<";

            time_t start, end;
            start = clock();

            NDimArray ndarray;
            double ** weights_Biases,**X_act, **y_act;
            unsigned int sample_size, features;
            double Y_not,Y,exp_y;
            int i,j,k, random;
            

            X_act = X.values();
            y_act = y_target.values();
            sample_size = X.sampleSize();
            features = X.features();
            l_r *= 2;
            Weights_Biases.initilize(1,features+1);
        
            // Initilize weights and biases
            Weights_Biases.initilizeRandomData(60);
            weights_Biases = Weights_Biases.values();
            for(i=0;i<=features;i++)
                weights_Biases[0][i] /= 10000.0f;

            // Epoch
            for(i=0; i<epoch; i++ )
            {
                // Initilize index
                j = rand()%sample_size;
                Y = 0;
                // Calculate y
                for(k=0;k<features;k++)
                    Y += weights_Biases[0][k]* X.values()[k][j];
                Y += weights_Biases[0][k];
                exp_y = exp((-1) * Y);
                Y = 1/(1-exp_y);

                Y_not = Y - y_act[0][j];
                // Updating weights and biases;
                for(k=0;k<features;k++) 
                    weights_Biases[0][k] -= l_r * (Y_not * X_act[k][j]);
                weights_Biases[0][k] -= l_r * Y_not;
            }
            end = clock();
            double duration = double(end-start)/double(CLOCKS_PER_SEC);
            cout << " Time taken: " << duration <<"s" << endl;
        }

        DataFalcon predict(DataFalcon X)
        {
            int i,j, size,features;
            double y_exp;
            double ** y, **weight_biases,**x;
            DataFalcon Y_predict;

            Y_predict.initilize(1,X.sampleSize());
            x=X.values();
            y = Y_predict.values();
            weight_biases = Weights_Biases.values();
            size = X.sampleSize();
            features = X.features();

            for (i=0;i<size;i++)
            {
                y[0][i] = 0;
                for (j=0;j<features;j++)
                    y[0][i] += x[j][i] * weight_biases[0][j];
                y[0][i] += weight_biases[0][j];

                y_exp = exp((-1) * y[0][i]);
                y[0][i] = 1/(1-y_exp);
                
                y[0][i] = (y[0][i] >= 0.5) * 1;
                /*if(y[0][i]>=0.5)
                    y[0][i] = 1;
                else 
                    y[0][i] = 0;*/
            }

            return Y_predict;
        }

        double accuracy(DataFalcon y_test,DataFalcon y_predict)
        {
            double acc, **y_tst, **y_pred;
            int i,True,False,size;


            True = False = 0;
            size = y_test.sampleSize();
            y_tst = y_test.values();
            y_pred = y_predict.values();


            for(i=0;i<size;i++)
            {
                if(y_tst[0][i]==y_pred[0][i])
                    True ++;
            }
            acc = (double)True/size;
            return acc;
        }

        DataFalcon confusionMatrix(DataFalcon y_test,DataFalcon y_predict)
        {
            DataFalcon matrix,unique_count_matrix;
            NDimArray nd;
            double T_N, T_P, F_N, F_P;
            double **y_Test, **y_Predict, **matrix_ptr, **unique_matrix_ptr;
            int n;
            
            unique_count_matrix = nd.nUnique(y_test.values()[0],y_test.sampleSize());
            matrix.initilize(unique_count_matrix.sampleSize(),unique_count_matrix.sampleSize());
            n = y_test.sampleSize();
            y_Test = y_test.values();
            y_Predict = y_predict.values();
            matrix_ptr = matrix.values();
            unique_matrix_ptr = unique_count_matrix.values();

            for (int i =0;i<unique_count_matrix.sampleSize();i++)
                for (int j =0;j<unique_count_matrix.sampleSize();j++)
                    matrix_ptr[i][j] = 0;

            for(int i =0; i< n; i++)
            {
                if( y_Test[0][i] == y_Predict[0][i] )
                {
                    int j;
                    for(j=0; j< unique_count_matrix.sampleSize();j++)
                    {
                        if(y_Test[0][i]==unique_matrix_ptr[0][j])
                        break;
                    }
                    matrix_ptr[j][j] += 1;
                }
                else
                {
                    int j,k;
                    for(j=0; j< unique_count_matrix.sampleSize();j++)
                        if(y_Test[0][i]==unique_matrix_ptr[0][j])
                            break;
                    for( k =0; k< unique_count_matrix.sampleSize();k++)
                        if(y_Predict[0][i]==unique_matrix_ptr[0][k])
                            break;
                    matrix_ptr[j][k] += 1;
                }
            }
        return matrix;
        }
};

