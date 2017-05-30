module.exports = {
    script: {
        files: ['src/client/css/*.css', 'src/client/ts/*.ts'],
        tasks: 'client'
    },
    server: {
        files: ['src/server/**/*.cpp', 'src/server/**/*.c', 'src/server/**/*.h'],
        tasks: 'server'
    },
    html: {
        options: {
            livereload: true
        },
        files: 'src/client/index.html',
        tasks: 'copy:index'
    }
};