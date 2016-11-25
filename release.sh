

#curl -i -H "Authorization: token bc63b440ca6e97c4198f7918c796a5a1692fe0f0" \
#    "https://api.github.com/repos/defold/defold-examples/releases"


curl -H "Authorization: token bc63b440ca6e97c4198f7918c796a5a1692fe0f0" \
     -H "Accept: application/vnd.github.manifold-preview" \
     -H "Content-Type: application/zip" \
     --data-binary @alien_world.zip \
     "https://uploads.github.com/repos/defold/defold-examples/releases/4685909/assets?name=testing.zip"