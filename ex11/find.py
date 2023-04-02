import sys
import requests

URL = "https://pokeapi.co/api/v2/pokemon/{pokemon_name}"

if __name__ == "__main__":
    name = input("Enter the name of a Pokemon: ").lower()
    try:
        response = requests.get(URL.format(pokemon_name=name))
        if response.status_code != 200:
            raise Exception("Check the name again.")
        data = response.json()
        print("Name: {}".format(data["name"].title()))
        print("Abilities:")
        for ability in data["abilities"]:
            print("- {}".format(ability["ability"]["name"].title()))
    except requests.exceptions.RequestException as e:
        print("Error. Failed to request.")
    except Exception as e:
        print("Error.", e)