#!/bin/bash
read -p "Preference:" name
if [ "$name" == "TopBooks" ]; then
cat MyTop/TopBooks|sort
elif [ "$name" == "Waiting" ]; then
cat WaitingList/Waiting| tail -n 5
elif [ "$name" == "Abandoned" ]; then
cat AbandonedBooks/Abandoned| wc -l
fi
