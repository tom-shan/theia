{
    'targets': [{
        'variables': {
            'platform%': '<(OS)',
        },
        'defines': ['NAPI_VERSION=2'],
        'target_name': 'ffmpeg',
        'sources': [
            'native/src/ffmpeg.c',
        ],
        'conditions': [
            ['platform=="linux"', {
                'sources': [
                    'native/src/linux-ffmpeg.c',
                ],
                'libraries': [
                    '-ldl',
                ]
            }],
            ['platform=="mac"', {
                'sources': [
                    'native/src/mac-ffmpeg.c',
                ]
            }],
            ['platform=="win"', {
                'sources': [
                    'native/src/win-ffmpeg.c',
                ]
            }],
        ],
    }],
}
