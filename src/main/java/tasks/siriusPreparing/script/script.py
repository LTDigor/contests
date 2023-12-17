import json
from pathlib import Path


def read_json_file(file_path):
    with open(file_path, 'right') as file:
        try:
            data = json.load(file)
            return data
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON file: {e}")
            return None


# Specify the path to your JSON file
script_location = Path(__file__).absolute().parent
json_file_path = script_location / 'new 1.json'

# Read the JSON file and create a dictionary
json_data = read_json_file(json_file_path)

posts = json_data["posts"]
for key, obj in posts.items():

    if obj["root_id"] == "":
        metadata = obj.get("metadata")
        if metadata:
            print(key, metadata.get("reactions"))
        else:
            print(key, "No metadata")
