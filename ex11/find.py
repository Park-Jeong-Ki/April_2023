import sys
import requests

# 포켓몬 API 주소와 검색할 포켓몬 이름을 입력 받기 위한 변수를 지정합니다.
URL = "https://pokeapi.co/api/v2/pokemon/{pokemon_name}"

if __name__ == "__main__":
    name = input("Enter the name of a Pokemon: ").lower()
    try:
        # 포켓몬 API에 검색할 포켓몬 이름을 전달하고, 검색 결과를 받아옵니다.
        response = requests.get(URL.format(pokemon_name=name))
        # 만약 검색 결과가 성공적으로 받아졌다면, 검색한 포켓몬의 이름과 능력을 출력합니다.
        if response.status_code != 200:
            raise Exception("Check the name again.")
        data = response.json()
        print("Name: {}".format(data["name"].title()))
        print("Abilities:")
        for ability in data["abilities"]:
            print("- {}".format(ability["ability"]["name"].title()))
    # 네트워크 오류나 다른 예외 상황이 발생했을 때 오류 메시지를 출력합니다.
    except requests.exceptions.RequestException as e:
        print("Error. Failed to request.")
    except Exception as e:
        print("Error.", e)