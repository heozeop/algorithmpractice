use std::{io::{self, Write}, time::Duration, thread::sleep};
use crossterm::{
    terminal::{enable_raw_mode, disable_raw_mode},
    event::{Event, KeyCode, KeyEvent, poll},
    execute, queue,
    style::{Color, Print, ResetColor, SetForegroundColor},
    terminal,
};

mod project;

fn main() -> io::Result<()> {
    // Raw mode로 전환
    enable_raw_mode()?;

    // Terminal 초기화
    let mut stdout = io::stdout();
    execute!(stdout, terminal::EnterAlternateScreen)?;

    // 명령어 리스트
    let commands = vec!["init", "run", "exit"];

    // 현재 선택된 명령어 인덱스
    let mut selected_command_index = 0;

    loop {
        // 화면 초기화
        execute!(
            stdout,
            terminal::Clear(terminal::ClearType::All),
            terminal::ScrollUp(999)
        )?;

        // 명령어 출력
        queue!(
            stdout,
            SetForegroundColor(Color::Yellow),
            Print("Select a command:\n"),
            ResetColor,
        )?;
        for (index, command) in commands.iter().enumerate() {
            if index == selected_command_index {
                queue!(
                    stdout,
                    SetForegroundColor(Color::Green),
                    Print("> "),
                    Print(command),
                    ResetColor,
                    Print("\n"),
                )?;
            } else {
                queue!(stdout, Print("  "), Print(command), Print("\n"))?;
            }
        }

        // 이벤트 처리
        if poll(Duration::from_millis(100))? {
            if let Event::Key(KeyEvent { code, .. }) = crossterm::event::read()? {
                match code {
                    KeyCode::Up => {
                        if selected_command_index > 0 {
                            selected_command_index -= 1;
                        }
                    }
                    KeyCode::Down => {
                        if selected_command_index < commands.len() - 1 {
                            selected_command_index += 1;
                        }
                    }
                    KeyCode::Enter => {
                        let command = commands[selected_command_index];
                        match command {
                            "init" => {
                                // 프로젝트 이름 입력
                                queue!(
                                    stdout,
                                    SetForegroundColor(Color::Yellow),
                                    Print("\nEnter a project name: "),
                                    ResetColor,
                                )?;
                                stdout.flush()?;
                                let mut project_name = String::new();
                                io::stdin().read_line(&mut project_name)?;
                                project_name = project_name.trim().to_string();
                                                            // 프로젝트 생성
                            match project::create_project(&project_name) {
                              Ok(()) => {
                                  queue!(
                                      stdout,
                                      SetForegroundColor(Color::Green),
                                      Print(format!(
                                          "\nProject \"{}\" created successfully!\n",
                                          project_name
                                      )),
                                      ResetColor,
                                  )?;
                              }
                              Err(err) => {
                                  queue!(
                                      stdout,
                                      SetForegroundColor(Color::Red),
                                      Print(format!(
                                          "\nFailed to create project \"{}\": {}\n",
                                          project_name, err
                                      )),
                                      ResetColor,
                                  )?;
                              }
                          }

                          // 잠시 대기
                          sleep(Duration::from_secs(1));
                      }
                      "run" => {
                        queue!(
                            stdout,
                            SetForegroundColor(Color::Yellow),
                            Print("\nEnter a project name: "),
                            ResetColor,
                        )?;
                        stdout.flush()?;
                        let mut project_name = String::new();
                        io::stdin().read_line(&mut project_name)?;
                        project_name = project_name.trim().to_string();
                          // 빌드 및 테스트 실행
                          match project::build_and_test(&project_name) {
                              Ok((pass,fail)) => {
                                  queue!(
                                      stdout,
                                      SetForegroundColor(Color::Green),
                                      Print(format!("\nBuild and test succeeded! success:{} fail:{}\n", pass,fail)),
                                      ResetColor,
                                  )?;
                              }
                              Err(err) => {
                                  queue!(
                                      stdout,
                                      SetForegroundColor(Color::Red),
                                      Print(format!(
                                          "\nBuild and test failed: {}\n",
                                          err
                                      )),
                                      ResetColor,
                                  )?;
                              }
                          }

                          // 잠시 대기
                          sleep(Duration::from_secs(1));
                      }
                      "exit" => {
                          // 프로그램 종료
                          break;
                      }
                      _ => {}
                  }
              }
              _ => {}
          }
      }
  }
}

// Raw mode 해제
disable_raw_mode()?;

// Terminal 초기화
execute!(stdout, terminal::LeaveAlternateScreen)?;

Ok(())
}