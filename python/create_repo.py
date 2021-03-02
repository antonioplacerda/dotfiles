import sys
import os
import subprocess
import requests
import json

def create_repo(repo_name):
    NEW_REPO_URL = "https://api.github.com/user/repos"
    with open('/Users/antonioplacerda/scripts/.secret') as secret:
        auth_json = json.load(secret)["github"]

    auth = (auth_json["user"], auth_json["token"])

    data = {
        "name": repo_name,
        "auto_init": True,
    }
    res = requests.post(NEW_REPO_URL, auth=auth, data=json.dumps(data))

    if res.status_code != 201:
        raise Exception(f"Could not create repo: {res.text}")

    return res.json()["html_url"]

if __name__ == "__main__":
    repo_name = sys.argv[1]

    url = create_repo(repo_name)

    projects_path = os.environ.get('PROJECTS')

    pipe = subprocess.Popen("git clone " + url, shell=True, cwd=projects_path)
    pipe.wait()

    print(projects_path + "/" + repo_name)
