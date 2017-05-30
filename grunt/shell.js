module.exports =
{
    spellChecker:
    {
        command: 'cspell src/client/ts/*.ts'
    },
    saveWorkDir:
    {
        command: 'set lab5=%CD%'
    },
    buildServer:
    {
        command: ['cd /d %VS140COMNTOOLS%../ide/',
                'devenv "%lab5%/src/server/server.sln" /build Release'].join('&&')
    },
    startServer:
    {
        command: 'start server.exe',
        options:
        {
            async: true,
            execOptions:
            {
                cwd: '.build'
            }
        }
    },
    closeServer:
    {
        command: 'start taskkill /im server.exe'
    }
};
