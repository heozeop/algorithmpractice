use std::process::Command;
use std::ffi::CString;
use std::process::Stdio;
use std::fs;
use clap::{Arg, App, SubCommand};
use std::io::{self, Write};
use std::fs::File;
use threadpool::ThreadPool;
use std::sync::{Arc, Barrier};
use std::sync::atomic::{AtomicUsize, Ordering};

fn build_program(program_path: &str, build_path: &str) {
    let build_command = Command::new("g++")
        .arg("-o")
        .arg(build_path)
        .arg(program_path)
        .output()
        .expect("Failed to build program");

    if !build_command.status.success() {
      panic!("Failed to build program {}/{}.cpp", program_path, program_path);
    }
}

fn run_program(build_path: &str, input_path: &str, output_path: &str) {
  let run_command = Command::new(build_path)
      .stdout(Stdio::piped())
      .arg("<")
      .arg(input_path)
      .output()
      .expect("Failed to run program");

  if !run_command.status.success() {
      panic!("Failed to run program");
  }

  let mut file = File::create(output_path).unwrap();
  file.write_all(String::from_utf8_lossy(&run_command.stdout).as_bytes());
  drop(file);
}

fn validate_output(expected_path: &str, actual_path: &str) {
    let expected_output = fs::read_to_string(expected_path).unwrap();
    let actual_output = fs::read_to_string(actual_path).unwrap();
    assert_eq!(expected_output, actual_output);
}

fn run_tests(program_path: &str) {
  let files = fs::read_dir(format!("./boj/{}/test_cases", program_path)).unwrap().collect::<Vec<_>>();

  let n_workers = 4;
  let n_jobs = 8;
  let pool = ThreadPool::new(n_workers);
  let an_atomic = Arc::new(AtomicUsize::new(0)); 

  let barrier = Arc::new(Barrier::new(n_jobs + 1));

  for n in 1..files.len() {
    let program_file_path = format!("./boj/{}/{}.cpp", program_path, program_path);
    let input_path = format!("{}/test_cases/{}/input.txt", program_path, n);
    let expected_path =format!("./boj/{}/test_cases/{}/output.txt", program_path, n);
    let return_path = format!("./boj/{}/test_cases/{}/return.txt", program_path, n);
    let build_path = format!("./boj/{}/test_cases/{}/program.out", program_path, n);

    let barrier = barrier.clone();
    let an_atomic = an_atomic.clone();
    pool.execute(move|| {
      // do the heavy work
      build_program(&program_file_path, &build_path);
      run_program(&build_path, &input_path, &return_path);
      validate_output(&expected_path, &return_path);

      an_atomic.fetch_add(1, Ordering::Relaxed);
      
      // then wait for the other threads
      barrier.wait();
    });
  }

  barrier.wait();
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