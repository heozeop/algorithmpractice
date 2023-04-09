use std::process::Command;
use std::ffi::CString;
use std::fs;
use clap::{Arg, App, SubCommand};
use std::io::{self, Write};
use std::fs::File;

fn build_program(program_path: &str) {
    let build_command = Command::new("g++")
        .arg("-o")
        .arg(format!("./boj/{}/program.out", program_path).as_str())
        .arg(format!("./boj/{}/{}.cpp",program_path, program_path).as_str())
        .output()
        .expect("Failed to build program");

    if !build_command.status.success() {
      let mut errorMSG = format!("Failed to build program {}/{}.cpp", program_path, program_path);
      panic!("{}", errorMSG);
    }
}

fn run_program(program_path: &str, input_path: &str, output_path: &str) {
  let run_command = Command::new(format!("./boj/{}/program.out", program_path))
      .arg("<")
      .arg(input_path)
      .arg(">")
      .arg(output_path)
      .output()
      .expect("Failed to run program");

  if !run_command.status.success() {
      panic!("Failed to run program");
  }

  io::stdout().flush().unwrap();
}

fn validate_output(expected_path: &str, actual_path: &str) {
    let expected_output = fs::read_to_string(expected_path).unwrap();
    let actual_output = fs::read_to_string(actual_path).unwrap();
    assert_eq!(expected_output, actual_output);
}

fn run_tests(program_path: &str) {
  build_program(program_path);
  let files = fs::read_dir(format!("./boj/{}/test_cases", program_path)).unwrap().collect::<Vec<_>>();
  
  for n in 1..files.len() {
    let input_path = format!("./boj/{}/test_cases/{}/input.txt", program_path, n);
    let expected_path =format!("./boj/{}/test_cases/{}/output.txt", program_path, n);
    let return_path = format!("./boj/{}/test_cases/{}/return.txt", program_path, n);

    println!("{}\n{}\n{}", input_path, expected_path, return_path);
    run_program(&program_path, &input_path, &return_path);
    validate_output(&expected_path, &return_path);
  }
}

fn main() {
  let matcher = App::new("My Program")
  .subcommand(SubCommand::with_name("create")
      .about("create the C++ program")
      .arg(Arg::with_name("program")
          .required(true)
          .takes_value(true)
          .help("Path to the C++ program")))
  .subcommand(SubCommand::with_name("run")
      .arg(Arg::with_name("program")
          .required(true)
          .takes_value(true)
          .help("Path to the C++ program")));
  loop {
    print!("Enter command: ");
    io::stdout().flush().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    if input.trim() == "exit" {
        break;
    }

    input = format!("hello {}", input); // cli에서 command 바로 쓰고 싶어서 사용
    let matches = matcher.clone().get_matches_from(input.split_whitespace().collect::<Vec<&str>>());

    // execute C++ program here
    if let Some(matches) = matches.subcommand_matches("run") {
        let program_path = CString::new(matches.value_of("program").unwrap()).unwrap();

        let input_dir = program_path.to_str().unwrap().to_owned() + "/input";
        let output_dir = program_path.to_str().unwrap().to_owned() + "/output";
        let expected_dir = program_path.to_str().unwrap().to_owned() + "/expected";

        run_tests(program_path.to_str().unwrap());
    }

    if let Some(matches) = matches.subcommand_matches("create") {
      // Get the path to the C++ program from the command-line arguments
      let program_name = CString::new(matches.value_of("program").unwrap()).unwrap();
      let template_path = "./templates/cpp.cpp";
      let dir_path = format!("{}{}","./boj/",program_name.to_str().unwrap());
      fs::create_dir(dir_path.as_str()).expect(format!("Failed to create directory on {}", dir_path).as_str());

      let test_dir = dir_path.clone() + "/test_cases";
      fs::create_dir(test_dir.clone()).expect("Fail to create test directory");
      fs::create_dir(test_dir.clone() + "/1").expect("Fail to create first case");
      File::create(test_dir.clone() + "/1/input.txt").expect("Failed to create input file");
      File::create(test_dir.clone() + "/1/output.txt").expect("Failed to create output file");

      // file 복사
      let mut template_file = fs::read_to_string(template_path).unwrap();
      let file_name = format!("{}/{}{}", dir_path, program_name.to_str().unwrap(), ".cpp");
      let mut file = File::create(file_name).unwrap();

      file.write_all(template_file.as_bytes());
      println!("files related with {} created", program_name.to_str().unwrap());
      drop(file);
    }
  }
    
}