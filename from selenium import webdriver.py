import requests

# Base URLs and endpoints for illustrative purposes
BASE_URL = "https://mepro.pearson.com/"
LOGIN_ENDPOINT = "/api/login"
PROGRESS_ENDPOINT = "/api/progress"
LEVELS_ENDPOINT = "/api/levels"

def login(email, password):
    """
    Logs in to the Pearson MePro platform.
    """
    payload = {"email": email, "password": password}
    response = requests.post(BASE_URL + LOGIN_ENDPOINT, json=payload)
    if response.status_code == 200:
        print("Login successful!")
        return response.json()["token"]  # Assume a token is returned
    else:
        print("Login failed. Please check your credentials.")
        return None

def get_progress(token):
    """
    Fetches user progress on the MePro platform.
    """
    headers = {"Authorization": f"Bearer {token}"}
    response = requests.get(BASE_URL + PROGRESS_ENDPOINT, headers=headers)
    if response.status_code == 200:
        progress = response.json()
        print("Your progress:")
        for level in progress["levels"]:
            print(f"Level {level['level']}: {level['status']}")
    else:
        print("Failed to fetch progress.")

def suggest_improvements(token):
    """
    Fetches level data and suggests areas to improve.
    """
    headers = {"Authorization": f"Bearer {token}"}
    response = requests.get(BASE_URL + LEVELS_ENDPOINT, headers=headers)
    if response.status_code == 200:
        levels = response.json()
        for level in levels:
            if level["status"] != "completed":
                print(f"Suggestions for Level {level['level']}:")
                print("- Focus on areas like grammar or reading comprehension.")
                print("- Complete all exercises before taking the final exam.")
    else:
        print("Failed to fetch levels.")

# Main function to guide the learner
def main():
    email = input("Enter your email: ")
    password = input("Enter your password: ")

    token = login(email, password)
    if not token:
        return

    get_progress(token)
    suggest_improvements(token)

if __name__ == "__main__":
    main()
