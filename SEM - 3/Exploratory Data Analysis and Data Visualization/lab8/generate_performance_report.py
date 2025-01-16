import pandas as pd
import numpy as np
from scipy import stats

from sklearn.impute import SimpleImputer
from sklearn.preprocessing import OneHotEncoder
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

from sklearn.linear_model import LinearRegression, Ridge, Lasso
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score

file = open('lab8\\performance_report.txt', 'w')

for strategy in ['mean', 'most_frequent', 'median']:

    df = pd.read_csv('C:\Visual Studio Code\Weird Stuffs\lab8eda\Hitters.csv')
    df = df.drop('Unnamed: 0', axis=1)

    file.write('\n\n')
    file.write(f'NULL values filled by: {strategy}')
    file.write('\n\n')

    imputer = SimpleImputer(missing_values=np.nan, strategy=strategy)

    df['Salary'] = imputer.fit_transform(df['Salary'].to_numpy().reshape(-1, 1))

    encoder = OneHotEncoder(sparse_output=False)

    for i in ['League', 'Division', 'NewLeague']:

        temp = pd.DataFrame(

            data=encoder.fit_transform(df[i].to_numpy().reshape(-1, 1)),
            columns=encoder.get_feature_names_out([i])
        )

        df = pd.concat([df, temp], axis=1)
        df = df.drop(i, axis=1)

        df_iqr = df.copy(deep=True)

    for i in df.columns:

        Q1 = df[i].quantile(0.25)
        Q3 = df[i].quantile(0.75)
        IQR = Q3 - Q1

        lower_bound = Q1 - 1.5 * IQR
        upper_bound = Q3 + 1.5 * IQR

        df_iqr = df_iqr[(df_iqr[i] >= lower_bound) & (df_iqr[i] <= upper_bound)]

    df_zscore = df.copy(deep=True)

    for i in df.columns:

        df_zscore['z_score'] = np.abs(stats.zscore(df_zscore[i]))

        df_zscore = df_zscore[df_zscore['z_score'] < 3]

        df_zscore = df_zscore.drop('z_score', axis=1)

    types = {'No Outliers Removed': df, 'Outliers Removed based on IQR':df_iqr, 'Outliers Removed based on Z-Score': df_zscore}
    for type, df_type in types.items():

        file.write(f'\n\n{type}:\n\n')

        X = df_type.drop('Salary', axis=1)
        y = df_type['Salary']

        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, shuffle=True)

        scaler = StandardScaler()
        X_train_scaled = scaler.fit_transform(X_train)
        X_test_scaled = scaler.transform(X_test)

        ols_model = LinearRegression()
        ols_model.fit(X_train, y_train)
        ols_predictions = ols_model.predict(X_test)

        ridge_model = Ridge(alpha=1.0)
        ridge_model.fit(X_train_scaled, y_train)
        ridge_predictions = ridge_model.predict(X_test_scaled)

        lasso_model = Lasso(alpha=0.1, max_iter=10000)
        lasso_model.fit(X_train_scaled, y_train)
        lasso_predictions = lasso_model.predict(X_test_scaled)

        mae_ols = mean_absolute_error(y_test, ols_predictions)
        mse_ols = mean_squared_error(y_test, ols_predictions)
        rmse_ols = np.sqrt(mse_ols)
        r2_ols= r2_score(y_test, ols_predictions)

        mae_ridge = mean_absolute_error(y_test, ridge_predictions)
        mse_ridge = mean_squared_error(y_test, ridge_predictions)
        rmse_ridge = np.sqrt(mse_ridge)
        r2_ridge = r2_score(y_test, ridge_predictions)

        mae_lasso = mean_absolute_error(y_test, lasso_predictions)
        mse_lasso = mean_squared_error(y_test, lasso_predictions)
        rmse_lasso = np.sqrt(mse_lasso)
        r2_lasso = r2_score(y_test, lasso_predictions)

        file.write("OLS Model: ")
        file.write('\n')
        file.write(f"Mean Absolute Error (MAE): {mae_ols}")
        file.write('\n')
        file.write(f"Mean Squared Error (MSE): {mse_ols}")
        file.write('\n')
        file.write(f"Root Mean Squared Error (RMSE): {rmse_ols}")
        file.write('\n')
        file.write(f"R^2 Score: {r2_ols}x")
        file.write('\n')
        file.write("Ridge Model: ")
        file.write('\n')
        file.write(f"Mean Absolute Error (MAE): {mae_ridge}")
        file.write('\n')
        file.write(f"Mean Squared Error (MSE): {mse_ridge}")
        file.write('\n')
        file.write(f"Root Mean Squared Error (RMSE): {rmse_ridge}")
        file.write('\n')
        file.write(f"R^2 Score: {r2_ridge}x")
        file.write('\n')
        file.write("Lasso Model: ")
        file.write('\n')
        file.write(f"Mean Absolute Error (MAE): {mae_lasso}")
        file.write('\n')
        file.write(f"Mean Squared Error (MSE): {mse_lasso}")
        file.write('\n')
        file.write(f"Root Mean Squared Error (RMSE): {rmse_lasso}")
        file.write('\n')
        file.write(f"R^2 Score: {r2_lasso}x")

file.close()