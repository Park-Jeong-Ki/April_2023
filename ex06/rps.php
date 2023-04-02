<?php
    // install php https://stackoverflow.com/questions/69786222/zsh-command-not-found-php
    // PHP에서는 달러($) 기호를 사용하여 다음과 같이 변수를 선언합니다.
    // resource fopen ( string $filename , string $mode [, bool $use_include_path= false [, resource $context ]] )
    // 1,2 번쨰 인자 필수

    // PHP 함수 중 하나인 in_array 함수는 값이 배열 안에 존재하는지 확인해주는 함수입니다.

    // The fgets() function returns a line from an open file.
    // A single line read from the file on success, FALSE on EOF or error

    // trim 은 양쪽에 존재하는 공백 및 문자열을 제거하는 역활을 합니다.
    // The strtolower() function converts a string to lowercase.

    $stdin = fopen('php://stdin', 'r');

    echo "Choose rock, paper, or scissors: ";
    // remove whitespace and newlines
    $choice = strtolower(trim(fgets($stdin)));

    $choices = ["rock", "paper", "scissors"];
    $computer_choice = $choices[rand(0, 2)];

    if (!in_array($choice, $choices)) {
        echo "invalid input: $choice'.\n";
        exit;
    }

    $win_msg = "Congratulations! You won! The computer chose $computer_choice.\n";

    if ($choice == $computer_choice) {
        echo "It's a tie! You both chose $choice.\n";
    } else if ($choice == "rock" && $computer_choice == "scissors") {
        echo $win_msg;
    } else if ($choice == "paper" && $computer_choice == "rock") {
        echo $win_msg;
    } else if ($choice == "scissors" && $computer_choice == "paper") {
        echo $win_msg;
    } else {
        echo "Sorry, you lost. The computer chose $computer_choice.\n";
    }
?>