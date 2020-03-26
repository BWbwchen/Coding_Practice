const path = require('path');
const webpack = require('webpack')

module.exports = {
    mode: 'development',
    entry: {main: './src/main.js'},
    output:{
        path: path.resolve(__dirname, 'dist'), 
        filename: '[name].bundle.js',
        chunkFilename: '[name].chunkhash.bundle.js'
    },
    module: {
        rules: [{
            test: /\.m?js$/,
            exclude: /(node_modules|bower_components)/,
            use: {
                loader: 'babel-loader',
                options: {presets: ['@babel/preset-env']}
            }
        }]
    }
    /*
    optimization: {
        splitChunks: {
            cacheGroups: {
                commons: {
                    chunks: 'initial',
                    minChunks: 1,
                    maxInitialRequests: 5,
                    minSize: 0
                },
                vendor: { 
                    test: 'p5',
                    chunks: 'initial',
                    name: 'vendor',
                    priority: 10, 
                    enforce: true
                }
            }
        }
    }
    */
};

