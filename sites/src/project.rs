use std::fs::{create_dir, File, self, DirEntry};
use std::io::{BufReader, BufWriter,prelude::*, Write, self};
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};

pub(crate) fn create_project(project_name: &str) -> io::Result<()> {
    let current_dir = Path::new("./sites/boj");
    let project_dir = current_dir.join(project_name);

    // 프로젝트 디렉토리 생성
    fs::create_dir(&project_dir)?;

    // C++ 파일 생성
    let template_path = current_dir.join("../templates/cpp.cpp");
    let cpp_file_path = project_dir.join(format!("{}.cpp", project_name));
    fs::copy(template_path, &cpp_file_path)?;

    // 테스트 폴더 생성
    let test_dir_path = project_dir.join("tests");
    fs::create_dir(&test_dir_path)?;

    // 1번 폴더 생성
    let test1_dir_path = test_dir_path.join("1번");
    fs::create_dir(&test1_dir_path)?;

    // input.txt, output.txt, expect.txt 생성
    let input_file_path = test1_dir_path.join("input.txt");
    let output_file_path = test1_dir_path.join("output.txt");
    let expect_file_path = test1_dir_path.join("expect.txt");
    
    // 입력 파일 생성
    let mut input_file = File::create(&input_file_path)?;
    write!(input_file, "input")?;

    // 출력 파일 생성
    let mut output_file = File::create(&output_file_path)?;
    write!(output_file, "output")?;

    // 예상 결과 파일 생성
    let mut expect_file = File::create(&expect_file_path)?;
    write!(expect_file, "expect")?;

    println!("Successfully created project: {}", project_name);

    Ok(())
}


pub(crate) fn build_and_test(name: &str) -> io::Result<(usize, usize)> {
  // 폴더를 찾습니다.
  let folder_path = format!("../sites/boj/{}", name);
  let mut test_folders = Vec::new();
  let mut cxx_file_path = None;
  for entry in fs::read_dir(&folder_path)? {
      let entry = entry?;
      let file_name = entry.file_name().into_string().unwrap();
      if file_name == format!("{}.cpp", name) {
          cxx_file_path = Some(entry.path());
      } else if file_name == "test" && entry.file_type()?.is_dir() {
          test_folders.push(entry.path());
      }
  }
  let cxx_file_path = match cxx_file_path {
      Some(path) => path,
      None => {
          return Err(io::Error::new(
              io::ErrorKind::NotFound,
              format!("No C++ file found for project '{}'", name),
          ));
      }
  };

  // C++ 파일을 빌드합니다.
  let status = Command::new("g++")
      .arg(&cxx_file_path)
      .arg("-o")
      .arg(&format!("{}/{}", folder_path, name))
      .status()?;
  if !status.success() {
      return Err(io::Error::new(
          io::ErrorKind::Other,
          format!("Failed to build C++ file for project '{}'", name),
      ));
  }


    // 테스트 폴더 내 모든 폴더들의 input.txt를 입력으로 실행하고 출력을 output.txt에 저장합니다.
    for test_folder in test_folders {
      for entry in fs::read_dir(&test_folder)? {
          let entry = entry?;
          if entry.file_name().into_string().unwrap() == "input.txt" {
              let input = fs::read_to_string(entry.path())?;
              let output = Command::new(&format!("{}/{}", folder_path, name))
                  .stdin(input.as_bytes())
                  .output()?;
              let output_path = entry.path().with_file_name("output.txt");
              let mut output_file = fs::File::create(&output_path)?;
              output_file.write_all(&output.stdout)?;
          }
      }
  }
  // 모든 테스트를 실행한다.
  let mut pass_count = 0;
  let mut fail_count = 0;
  let mut test_dirs = Vec::new();
  for entry in fs::read_dir(target_dir)? {
      if let Ok(entry) = entry {
          if entry.file_type()?.is_dir() && entry.file_name() != "tests" {
              test_dirs.push(entry);
          }
      }
  }

  for entry in test_dirs {
      let test_name = entry.file_name().to_string_lossy();
      let mut input_path = entry.path();
      input_path.push("input.txt");
      if !input_path.is_file() {
          eprintln!("skipping test {}: input.txt not found", test_name);
          continue;
      }
      let mut expect_path = entry.path();
      expect_path.push("expect.txt");
      if !expect_path.is_file() {
          eprintln!("skipping test {}: expect.txt not found", test_name);
          continue;
      }

      let mut output_path = entry.path();
      output_path.push("output.txt");

      let mut child = Command::new(format!("{}/{}", target_dir.clone().display(), name))
          .stdin(fs::File::open(input_path)?)
          .stdout(fs::File::create(&output_path)?)
          .spawn()?;
      let status = child.wait()?;
      if !status.success() {
          eprintln!(
              "test {} failed with exit code {}",
              test_name,
              status.code().unwrap()
          );
          fail_count += 1;
          continue;
      }

      let expect = fs::read_to_string(expect_path)?;
      let actual = fs::read_to_string(output_path)?;
      if expect != actual {
        eprintln!("test {} failed:
        expected: {}
        actual:   {}",
        test_name, expect, actual);
        fail_count += 1;
    } else {
        pass_count += 1;
    }
  }
  Ok((pass_count, fail_count))
}
