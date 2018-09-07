# BGCPPChallenge
#I tryed to make the parsers by my own, and tryed to make the XML and JSON according to the knowledge i found


git clone <git repository URL>

cd <local repository folder>

docker run -d -it gcc /bin/bash
  
docker ps

#When doing the copy also do the copy of the xsd

docker cp app.cpp <container>:/app.cpp
  
docker cp template.xsd <container>:/template.xsd

# Inside Docker First install xerces using this command in docker

apt-get update

apt-get install libxerces-c3-dev
  
# Then compile
g++ app.cpp -o app -lxerces-c

#If compiling a error regarding not finding the path to xerces ("cannot find -lxerces") , just restart the docker, doing ctrl+p and then ctrl+q, and then execute again docker exec -it <container> /bin/bash

#And then just run with the path of the xsd, Use this in case the template is in the root of the Docker like the app
./app template.xsd

#The generated XML has the name generated_XML.xml
#The generated JSON has the name Exported_JSON.JSON

#Is possible to use another .xsd with this code, but they need to have the same types as the first ones, I put anothers for example
#Just change the name when called 
