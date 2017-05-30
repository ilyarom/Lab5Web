module.exports =
{
    'client': ['clean:oldHashes', 'tslint', 'ts', 'copy:libs', 'copy:filesDirectory', 'copy:styles', 'systemjs', 'hashres', 'copy:index'],
    'server': ['shell:closeServer', 'shell:buildServer', 'copy:server', 'shell:startServer'],
    'default': ['clean', 'copy:server', 'shell:startServer', 'client', 'open', 'watch']
};