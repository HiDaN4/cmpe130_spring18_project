{
  "targets": [
    {
      "target_name": "module",
      "sources": [ 
        "GraphManagerModule.cpp",
        "GraphManagerInterface.cpp"
        ],
        'link_settings': {
            'libraries': [
              '-lproject',
              '-std=c++11',
              '-mmacosx-version-min=10.13'
            ],
            'library_dirs': [
              '$(srcdir)/lib',
            ],
      },

      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "../c++/src",
        "../c++/include"
      ],
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-std=c++11',
          "-mmacosx-version-min=10.13"
        ],
        'MACOSX_DEPLOYMENT_TARGET': '10.13'
      }
    }
  ]
}
