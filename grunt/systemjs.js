module.exports = {
    options: {
        sfx: true,
        minify: true,
        baseURL: "",
        sourceMaps: false,
        configFile: 'systemConfig.js',
        build: {
            mangle: false
        }
    },
    ts: {
        src: 'index.js',
        dest: '.build/js/index.min.js'
    }
};