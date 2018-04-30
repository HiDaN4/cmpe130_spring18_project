{
  "targets": [
    {
      "target_name": "interface",
      "sources": [ "interface.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
