var path = require('path');
var webpack = require('webpack');

module.exports = {
    context: path.resolve(__dirname, './src'),
    entry:{
      main: ['./main.js'],
      //module: ['./module-1.js']
    },
    output:{
      path: path.resolve(__dirname, 'dist'),
      filename: '[name].bundle.js'
    },
    module: {
      rules: [
          {
             test: /\.js$/,
             exclude: [/node_modules/],
             use: [
                 {
                     loader: 'babel-loader',
                     options: {
                         presets: [
                             [
                                 '@babel/preset-env', {
                                     modules: false
                                 }
                             ]
                         ]
                     }
                 }
             ]
          },
          {
            test: /\.css$/,
            use: ['style-loader','css-loader']
          }
      ]
    },
    optimization: {
        splitChunks: {
            cacheGroups: {
                vendor: {          
                    minChunks: 2,
                    name: 'vendor',
                    chunks: 'all'
                }
            }
        }
    }
};

