const semesterSubjects = {
    1: [
      { name: "Engineering Mathematics – I", credit: 3 },
      { name: "Engineering Chemistry", credit: 3 },
      { name: "English", credit: 3 },
      { name: "Computer Programming Using C", credit: 3 },
      { name: "IT Essentials", credit: 3 },
      { name: "Communication skills Lab", credit: 1.5 },
      { name: "Computer Engineering Workshop Lab", credit: 1.5 },
      { name: "Computer Programming using C lab", credit: 1.5 },
    ],
    2: [
      { name: "Engineering Mathematics–II", credit: 3 },
      { name: "Engineering Physics", credit: 3 },
      { name: "Elements of Electronics Engineering", credit: 3 },
      { name: "Data Structures Using C", credit: 3 },
      { name: "Digital Logic Design", credit: 3 },
      { name: "Linux Administration Lab", credit: 1.5 },
      { name: "Engineering Physics Lab", credit: 1.5 },
      { name: "Data Structures Lab", credit: 1.5 },
    ],
    3: [
      { name: "Discrete Mathematical Structures", credit: 3 },
      { name: "Computer Organization and Architecture", credit: 3 },
      { name: "PSQT", credit: 3 },
      { name: "Operating Systems", credit: 3 },
      { name: "Object Oriented Programming Through Java", credit: 3 },
      { name: "Computer Organization & Architecture Lab", credit: 1.5 },
      { name: "Object Oriented Programming Through Java Lab", credit: 1.5 },
      { name: "Operating Systems Lab", credit: 1.5 },
      { name: "Intellectual Property Rights (Internal)", credit: 2 },
      { name: "Environmental Science", credit: 0 },
    ],
    4: [
      { name: "Microprocessors", credit: 3 },
      { name: "Design and Analysis of Algorithms", credit: 3 },
      { name: "Database Management System", credit: 3 },
      { name: "Formal Languages & Automata Theory", credit: 3 },
      { name: "Managerial Economics", credit: 3 },
      { name: "Algorithms Lab through C++", credit: 1.5 },
      { name: "Database Management Systems Lab", credit: 1.5 },
      { name: "Web Technologies", credit: 2 },
      { name: "Professional Ethics & Universal Human Values", credit: 0 },
    ],
    5: [
      { name: "Data Communications & Computer Networks", credit: 3 },
      { name: "Artificial Intelligence", credit: 3 },
      { name: "Compiler Design", credit: 3 },
      { name: "Professional Elective 1", credit: 3 },
      { name: "Open Elective 1", credit: 3 },
      { name: "Data Communications & Computer Networks Lab", credit: 1.5 },
      { name: "Python Programming Lab", credit: 1.5 },
      { name: "Soft Skills", credit: 2 },
      { name: "Internship 1", credit: 2 },
    ],
    6: [
      { name: "Object Oriented Software Engineering", credit: 3 },
      { name: "Machine Learning", credit: 3 },
      { name: "Cryptography & Network Security", credit: 3 },
      { name: "Professional Elective 2", credit: 3 },
      { name: "Open Elective 2", credit: 3 },
      { name: "Object oriented Software Engineering Lab", credit: 1.5 },
      { name: "Machine Learning Lab", credit: 1.5 },
      { name: "Cryptography & Network Security Lab", credit: 2 },
    ],
    7: [
      { name: "Professional Elective 3", credit: 3 },
      { name: "Professional Elective 4", credit: 3 },
      { name: "Professional Elective 5", credit: 3 },
      { name: "Open Elective 3", credit: 3 },
      { name: "Open Elective 4", credit: 3 },
      { name: "HSS Elective", credit: 3 },
      { name: "Design Thinking and product Innovation", credit: 2 },
      { name: "Internship 2", credit: 2 },
    ],
    8: [{ name: "Project Work", credit: 14 }],
  }
  
  let currentSemester = 1
  
  let semesters = {
    1: [],
    2: [],
    3: [],
    4: [],
    5: [],
    6: [],
    7: [],
    8: [],
  }
  
  function displaySemesterSubjects() {
    const gradeTable = document.getElementById("gradeTable")
    gradeTable.innerHTML = ""
  
    semesterSubjects[currentSemester].forEach((subject, index) => {
      const row = document.createElement("tr")
      row.innerHTML = `
              <td class="border border-gray-300 dark:border-gray-600 p-2 text-sm sm:text-base">${subject.name}</td>
              <td class="border border-gray-300 dark:border-gray-600 p-2 text-sm sm:text-base">${subject.credit}</td>
              <td class="border border-gray-300 dark:border-gray-600 p-2">
                  <input type="number" 
                      class="w-full grade-point bg-transparent text-sm sm:text-base" 
                      min="0" 
                      max="10" 
                      step="0.1" 
                      onkeypress="return (event.charCode >= 48 && event.charCode <= 57) || event.charCode === 46"
                      value="${semesters[currentSemester][index]?.gradePoint || ""}"
                      placeholder="0-10">
              </td>
              <td class="border border-gray-300 dark:border-gray-600 p-2 grade-letter text-sm sm:text-base"></td>
              <td class="border border-gray-300 dark:border-gray-600 p-2 score text-sm sm:text-base">0</td>
          `
      gradeTable.appendChild(row)
      addEventListeners(row)
    })
  
    calculateTotals()
  }
  
  function addEventListeners(row) {
    const gradePointInput = row.querySelector(".grade-point")
    gradePointInput.addEventListener("input", calculateScore)
  }
  
  function calculateScore(e) {
    const input = e.target
    const value = Number.parseFloat(input.value)
  
    // Enforce maximum value of 10
    if (value > 10) {
      input.value = 10
      showNotification("Maximum grade point is 10", "warning")
    }
  
    const row = input.closest("tr")
    const credit = Number.parseFloat(row.cells[1].textContent) || 0
    const gradePoint = Number.parseFloat(input.value) || 0
    const score = credit * gradePoint
    row.querySelector(".score").textContent = score.toFixed(2)
    updateGradeLetter(row, gradePoint)
    calculateTotals()
  }
  
  function updateGradeLetter(row, gradePoint) {
    const gradeLetter = row.querySelector(".grade-letter")
    if (gradePoint >= 9) gradeLetter.textContent = "A+"
    else if (gradePoint >= 8) gradeLetter.textContent = "A"
    else if (gradePoint >= 7) gradeLetter.textContent = "B"
    else if (gradePoint >= 6) gradeLetter.textContent = "C"
    else if (gradePoint >= 5) gradeLetter.textContent = "D"
    else gradeLetter.textContent = "F"
  }
  
  function calculateTotals() {
    let totalScore = 0
    let totalCredits = 0
  
    document.querySelectorAll("#gradeTable tr").forEach((row, index) => {
      const credit = semesterSubjects[currentSemester][index].credit
      const score = Number.parseFloat(row.querySelector(".score").textContent) || 0
      totalScore += score
      totalCredits += credit
    })
  
    document.getElementById("totalScore").textContent = totalScore.toFixed(2)
    document.getElementById("totalCredits").textContent = totalCredits.toFixed(2)
  
    const semesterGpa = totalCredits > 0 ? totalScore / totalCredits : 0
    document.getElementById("semesterGpa").textContent = semesterGpa.toFixed(2)
  
    calculateCumulativeGpa()
  }
  
  function calculateCumulativeGpa() {
    let totalScore = 0
    let totalCredits = 0
  
    Object.entries(semesters).forEach(([sem, subjects]) => {
      subjects.forEach((subject, index) => {
        if (semesterSubjects[sem] && semesterSubjects[sem][index]) {
          const credit = semesterSubjects[sem][index].credit
          totalScore += subject.gradePoint * credit
          totalCredits += credit
        }
      })
    })
  
    const currentSemesterScore = Number.parseFloat(document.getElementById("totalScore").textContent) || 0
    const currentSemesterCredits = Number.parseFloat(document.getElementById("totalCredits").textContent) || 0
  
    totalScore += currentSemesterScore
    totalCredits += currentSemesterCredits
  
    const cumulativeGpa = totalCredits > 0 ? totalScore / totalCredits : 0
    document.getElementById("cumulativeGpa").textContent = cumulativeGpa.toFixed(2)
  
    updateGpaMeter(cumulativeGpa)
  }
  
  function updateGpaMeter(gpa) {
    const gpaMeter = document.getElementById("gpaMeter")
    const percentage = (gpa / 10) * 100
    gpaMeter.style.width = `${percentage}%`
  
    // Update color based on GPA
    if (gpa >= 9) {
      gpaMeter.classList.remove("bg-yellow-500", "bg-red-500")
      gpaMeter.classList.add("bg-green-500")
    } else if (gpa >= 7) {
      gpaMeter.classList.remove("bg-green-500", "bg-red-500")
      gpaMeter.classList.add("bg-yellow-500")
    } else {
      gpaMeter.classList.remove("bg-green-500", "bg-yellow-500")
      gpaMeter.classList.add("bg-red-500")
    }
  }
  
  function saveSemesterData() {
    const semesterData = []
    document.querySelectorAll("#gradeTable tr").forEach((row, index) => {
      semesterData.push({
        gradePoint: Number.parseFloat(row.querySelector(".grade-point").value) || 0,
        score: Number.parseFloat(row.querySelector(".score").textContent) || 0,
      })
    })
    semesters[currentSemester] = semesterData
    localStorage.setItem("semesterData", JSON.stringify(semesters))
    showNotification("Data saved successfully!")
  }
  
  function loadSemesterData() {
    const savedData = localStorage.getItem("semesterData")
    if (savedData) {
      semesters = JSON.parse(savedData)
      displaySemesterSubjects()
      showNotification("Data loaded successfully!")
    } else {
      showNotification("No saved data found.")
    }
  }
  
  function showNotification(message, type = "success") {
    const notification = document.createElement("div")
    notification.textContent = message
    const bgColor = type === "warning" ? "bg-yellow-500" : "bg-green-500"
    notification.className = `fixed top-4 right-4 ${bgColor} text-white px-4 py-2 rounded shadow-lg transition-opacity duration-300`
    document.body.appendChild(notification)
  
    setTimeout(() => {
      notification.style.opacity = "0"
      setTimeout(() => {
        document.body.removeChild(notification)
      }, 300)
    }, 3000)
  }
  
  document.getElementById("semesterSelect").addEventListener("change", (e) => {
    currentSemester = Number.parseInt(e.target.value)
    displaySemesterSubjects()
  })
  
  document.getElementById("saveData").addEventListener("click", saveSemesterData)
  document.getElementById("loadData").addEventListener("click", loadSemesterData)
  
  // Theme toggle functionality
  const themeToggle = document.getElementById("themeToggle")
  const html = document.documentElement
  
  themeToggle.addEventListener("click", () => {
    html.classList.toggle("dark")
    localStorage.setItem("theme", html.classList.contains("dark") ? "dark" : "light")
  })
  
  // Check for saved theme preference or prefer-color-scheme
  const savedTheme = localStorage.getItem("theme")
  const prefersDark = window.matchMedia("(prefers-color-scheme: dark)").matches
  
  if (savedTheme === "dark" || (!savedTheme && prefersDark)) {
    html.classList.add("dark")
  }
  
  // Initialize the first semester
  displaySemesterSubjects()
  
  