#include <iostream>
#include <vector>
#include <print>
#include <algorithm>
#include <fstream>
#include <string>

enum class ProcessState {
    Running = 1, 
    Waiting = 2,
    Stopped = 3
};

enum class Priority {
    Low = 1, 
    Medium = 2, 
    High = 3
};

class Process {
public:
    std::string name;
    int pid;

    ProcessState state;
    Priority priority;

    Process(std::string n, int p, ProcessState s, Priority pr) {
        name = n;
        pid = p;
        state = s;
        priority = pr;
    };
};
std::vector<Process> processed;
bool runtime = true;

namespace error {
    const std::string wrongNumber = "ERROR: Write only numbers!";
    const std::string duplicateName = "ERROR: This process name is duplicate!";
    const std::string duplicatePID = "ERROR: This PID is duplicate!";
    const std::string errorEnumWrite = "ERROR: Please write only numbers which are supported!";
}
namespace verify {
    bool existProcessName(std::string getPName) {
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].name == getPName)
            {
                return true;
            }
        }
        return false;
    }

    bool existPID(int getPID) {
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].pid == getPID)
            {
                return true;
            }
        }
        return false;
    }


}
namespace enumOperation {
    ProcessState setEnumFromIntState(int controler) {
        switch (controler)
        {
        case 1:
            return ProcessState::Running;

        case 2:
            return ProcessState::Waiting;

        case 3:
            return ProcessState::Stopped;
        }
    }

    Priority setEnumFromIntPriority(int control) {
        switch (control)
        {
        case 1:
            return Priority::Low;

        case 2:
            return Priority::Medium;

        case 3:
            return Priority::High;

        }
    }

    std::string getStringFromState(ProcessState stated) {
        switch (stated)
        {
        case ProcessState::Running:
            return "Running";

        case ProcessState::Waiting:
            return "Waiting";

        case ProcessState::Stopped:
            return "Stopped";
        }
    }

    std::string getStringFromPriority(Priority priorit) {
        switch (priorit)
        {
        case Priority::Low:
            return "Low";

        case Priority::Medium:
            return "Medium";

        case Priority::High:
            return "High";
        
        }
    }

}
namespace adder {
    int addState;
    int addPriority;

    std::string addName;
    int addPID;
    ProcessState newAddedState;
    Priority newAddedPriority;

    void saved() {
        processed.emplace_back(addName, addPID, newAddedState, newAddedPriority);
        std::println("Process added.");
    }

    void enumSet() {
        newAddedState = enumOperation::setEnumFromIntState(addState);
        newAddedPriority = enumOperation::setEnumFromIntPriority(addPriority);

        saved();
    }

    void verifyEnum() {
        if (addState <= 3 && addPriority <= 3 && addState != 0 && addPriority != 0)
        {
            enumSet();
        }
        else
        {
            std::cerr << error::errorEnumWrite;
        }
    }

    void verifyNameAndPID() {
        if (verify::existProcessName(addName))
        {
            std::cerr << error::duplicateName;
            return;
        }

        if (verify::existPID(addPID))
        {
            std::cerr << error::duplicatePID;
            return;
        }
        verifyEnum();
    }

    void choosePriority() {
        std::println("= Choose priority =");
        std::println("1) Low");
        std::println("2) Medium");
        std::println("3) High");
        std::print("Choose priority: ");
        std::cin >> addPriority;

        verifyNameAndPID();
    }

    void chooseState() {
        std::println("= Choose state =");
        std::println("1) Running");
        std::println("2) Waiting");
        std::println("3) Stopped");
        std::print("Choose state: ");
        std::cin >> addState;

        choosePriority();
    }

    void enter() {
        addState = 0;
        addPriority = 0;
        addName = "";
        addPID = 0;
        std::println("=== Add process ===");
        std::print("Process name: ");
        std::getline(std::cin >> std::ws, addName);
        std::print("PID: ");
        std::cin >> addPID;

        chooseState();
    }
}
namespace editor {
    std::string editName;

    void statee() {
        std::println("== Edit state ==");
        std::println("1) Running");
        std::println("2) Waiting");
        std::println("3) Stopped");
        std::print("Choose state: ");
        int choosers;
        std::cin >> choosers;

        if (choosers <= 3 && choosers != 0 )
        {
            for (size_t i = 0; i < processed.size(); i++)
            {
                if (processed[i].name == editName)
                {
                    processed[i].state = enumOperation::setEnumFromIntState(choosers);
                    std::println("State updated.");
                }
            }
        }
        else
        {
            std::cerr << error::errorEnumWrite;
        }
    }

    void priorit() {
        std::println("== Edit priority ==");
        std::println("1) Low");
        std::println("2) Medium");
        std::println("3) High");
        std::print("Choose priority: ");
        int choosers;
        std::cin >> choosers;

        if (choosers <= 3 && choosers != 0)
        {
            for (size_t i = 0; i < processed.size(); i++)
            {
                if (processed[i].name == editName)
                {
                    processed[i].priority = enumOperation::setEnumFromIntPriority(choosers);
                    std::println("Priority updated.");
                }
            }
        }
        else
        {
            std::cerr << error::errorEnumWrite;
        }
    }

    void lobby() {
        std::println("=== Edit process ===");
        std::print("Write name for edit: ");
        std::getline(std::cin >> std::ws, editName);

        if (!verify::existProcessName(editName))
        {
            std::cerr << "ERROR: Process with name " << editName << " not found!";
            return;
        }
        std::println("\n=== Edit process {} ===", editName);
        std::println("1) Edit state");
        std::println("2) Edit priority");
        std::print("3) Back\nChoose: ");
        int choose;
        std::cin >> choose;

        switch (choose)
        {
        case 1:
            statee();
            break;

        case 2:
            priorit();
            break;

        case 3:
            break;

        default:
            std::cerr << error::wrongNumber;
            lobby();
            break;
        }
    }
}
namespace removerer {
    std::string removeName;

    void sureRemove() {
        std::print("Are you sure for remove {}? Write y or n: ", removeName);
        std::string confirm;
        std::getline(std::cin >> std::ws, confirm);
        bool confirm_ = (confirm == "y" || confirm == "Y");
        if (!confirm_)
        {
            std::println("Remove canceled.");
            return;
        }
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].name == removeName)
            {
                processed.erase(processed.begin() + i);
                std::println("Process {} removed.", removeName);
            }
        }
    }

    void lobby() {
        std::println("=== Remove process ===");
        std::print("Write name process for remove: ");
        std::getline(std::cin >> std::ws, removeName);
        if (!verify::existProcessName(removeName))
        {
            std::cerr << "ERROR: This process name isn't exist!";
            return;
        }
        sureRemove();
    }
}
namespace filterrr {
    void onlyRun() {
        std::println("== Filter only running ==");
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].state == ProcessState::Running)
            {
                std::println("Process name: {}", processed[i].name);
                std::println("PID: {}", processed[i].pid);
                std::println("State: {}", enumOperation::getStringFromState(processed[i].state));
                std::println("Priority: {}", enumOperation::getStringFromPriority(processed[i].priority));
                std::println("----------------------");
            }
        }
    }

    void onlyWait() {
        std::println("== Filter only waiting ==");
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].state == ProcessState::Waiting)
            {
                std::println("Process name: {}", processed[i].name);
                std::println("PID: {}", processed[i].pid);
                std::println("State: {}", enumOperation::getStringFromState(processed[i].state));
                std::println("Priority: {}", enumOperation::getStringFromPriority(processed[i].priority));
                std::println("----------------------");
            }
        }
    }

    void onlyHighPriority() {
        std::println("== Filter only high priority ==");
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].priority == Priority::High)
            {
                std::println("Process name: {}", processed[i].name);
                std::println("PID: {}", processed[i].pid);
                std::println("State: {}", enumOperation::getStringFromState(processed[i].state));
                std::println("Priority: {}", enumOperation::getStringFromPriority(processed[i].priority));
                std::println("----------------------");
            }
        }
    }

    void onlyLowPriority() {
        std::println("== filter only low priority ==");
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].priority == Priority::Low)
            {
                std::println("Process name: {}", processed[i].name);
                std::println("PID: {}", processed[i].pid);
                std::println("State: {}", enumOperation::getStringFromState(processed[i].state));
                std::println("Priority: {}", enumOperation::getStringFromPriority(processed[i].priority));
                std::println("----------------------");
            }
        }
    }

    void lobby() {
        std::println("=== Filter ===");
        std::println("1) Only running");
        std::println("2) Only waiting");
        std::println("3) Only high priority");
        std::println("4) Only low priority");
        std::print("5) Back\nChoose: ");
        int chooserr;
        std::cin >> chooserr;

        switch (chooserr)
        {
        case 1:
            onlyRun();
            break;

        case 2:
            onlyWait();
            break;

        case 3:
            onlyHighPriority();
            break;

        case 4:
            onlyLowPriority();
            break;

        case 5:
            break;

        default:
            std::cerr << error::wrongNumber;
            lobby();
            break;
        }
    }
}
namespace sorter {
    void sortName() {
        std::sort(processed.begin(), processed.end(), [](const Process& a, const Process& b) {
            return a.name < b.name;
            });
    }

    void sortPID() {
        std::sort(processed.begin(), processed.end(), [](const Process& a, const Process& b) {
            return a.pid < b.pid;
            });
    }

    void sortPriority() {
        std::sort(processed.begin(), processed.end(), [](const Process& a, const Process& b) {
            return a.priority < b.priority;
            });
    }

    void lobby() {
        std::println("=== Sort ===");
        std::println("1) By name");
        std::println("2) By PID");
        std::println("3) By priority");
        std::print("4) Back\nChoose: ");
        int chooseL;
        std::cin >> chooseL;

        switch (chooseL)
        {
        case 1:
            sortName();
            std::println("Sorted.");
            break;

        case 2:
            sortPID();
            std::println("Sorted.");
            break;

        case 3:
            sortPriority();
            std::println("Sorted.");
            break;

        case 4:
            break;

        default:
            std::cerr << error::wrongNumber;
            lobby();
            break;
        }
    }
}
namespace statitics {
    int NumberOfProcess;
    
    int runProcess() {
        int counter = 0;
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].state == ProcessState::Running)
            {
                counter++;
            }
        }
        return counter;
    }

    int waitProcess() {
        int counter = 0;
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].state == ProcessState::Waiting)
            {
                counter++;
            }
        }
        return counter;
    }

    int stopProcess() {
        int counter = 0;
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].state == ProcessState::Stopped)
            {
                counter++;
            }
        }
        return counter;
    }

    int highPriorityProcess() {
        int counter = 0;
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].priority == Priority::High);
            {
                counter++;
            }
        }
        return counter;
    }

    void enterer() {
        std::println("=== Statistics ===");
        NumberOfProcess = processed.size();
        std::println("Total count of processes: {}", NumberOfProcess);
        std::println("Total count state of running: {}", runProcess());
        std::println("Total count state of waiting: {}", waitProcess());
        std::println("Total count state of stopped: {}", stopProcess());
        std::println("Total count process which have high priority: {}", highPriorityProcess());
    }
}
namespace processAction {
    bool ifRunnigProcess(std::string ifRun) {
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].state == ProcessState::Running && processed[i].name == ifRun)
            {
                return true;
            }
        }
        return false;
    }

    bool ifStoppedProcess(std::string ifStop) {
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].state == ProcessState::Stopped && processed[i].name == ifStop)
            {
                return true;
            }
        }
        return false;
    }

    void startProcess() {
        std::println("=== Start process ===");
        std::print("Start name: ");
        std::string startName;
        std::getline(std::cin >> std::ws, startName);
        if (!verify::existProcessName(startName))
        {
            std::cerr << "ERROR: Process " << startName << " isn't exist!";
            return;
        }

        if (ifRunnigProcess(startName))
        {
            std::cerr << "ERROR: This process is alredy running!";
            return;
        }
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].name == startName)
            {
                processed[i].state = ProcessState::Running;
                std::println("Process started.");
            }
        }
    }

    void stopProcess() {
        std::println("=== Stop process ===");
        std::print("Stop name: ");
        std::string stopName;
        std::getline(std::cin >> std::ws, stopName);
        if (!verify::existProcessName(stopName))
        {
            std::cerr << "ERROR: Process " << stopName << " isn't exist!";
            return;
        }

        if (ifStoppedProcess(stopName))
        {
            std::cerr << "ERROR: This process is alredy stopped!";
            return;
        }
        for (size_t i = 0; i < processed.size(); i++)
        {
            if (processed[i].name == stopName)
            {
                processed[i].state = ProcessState::Stopped;
                std::println("Process stopped.");
            }
        }
    }
}
namespace fileAction {
    const std::string fileName = "file.dat";

    void saveData() {
        std::println("Saving...");
        std::ofstream writer(fileName);
        if (!writer.is_open())
        {
            std::cerr << "ERROR: Can't open file " << fileName << "!";
            writer.close();
            return;
        }
        for (size_t i = 0; i < processed.size(); i++)
        {
            writer << processed[i].name << "\n";
            writer << processed[i].pid << "\n";
            writer << static_cast<int>(processed[i].state) << "\n";
            writer << static_cast<int>(processed[i].priority) << "\n";
        }
        writer.close();
        std::println("Save completed, terminating program...");
    }

    void laodData() {
        std::println("Loading...");
        std::ifstream loader(fileName);
        if (!loader.is_open())
        {
            std::cerr << "ERROR: Can't load file " << fileName << "!";
            loader.close();
            return;
        }

        std::string nameTemp;
        int PIDTemp;
        ProcessState stateTemp;
        Priority priorityTemp;

        int getterState;
        int getterPriority;

        while (std::getline(loader, nameTemp))
        {
            loader >> PIDTemp;
            loader >> getterState;
            loader >> getterPriority;
            loader.ignore();
            stateTemp = static_cast<ProcessState>(getterState);
            priorityTemp = static_cast<Priority>(getterPriority);
            processed.emplace_back(nameTemp, PIDTemp, stateTemp, priorityTemp);
        }
        loader.close();
        std::println("Loaded, starting menu...");
    }
}

void showProcesses() {
    std::println("=== Show processes ===");
    for (size_t i = 0; i < processed.size(); i++)
    {
        std::println("Name: {}", processed[i].name);
        std::println("PID: {}", processed[i].pid);
        std::println("State: {}", enumOperation::getStringFromState(processed[i].state));
        std::println("Priority: {}", enumOperation::getStringFromPriority(processed[i].priority));
        std::println("----------------------");
    }
    if (processed.size() == 0)
    {
        std::println("None process found.");
    }
}

int main()
{
    fileAction::laodData();
    while (runtime)
    {
        std::println("\n==== Process manager ====");
        std::println("1) Add process");
        std::println("2) Show processes");
        std::println("3) Edit process");
        std::println("4) Remove process");
        std::println("5) Filter");
        std::println("6) Sort");
        std::println("7) Statistics");
        std::println("8) Start process");
        std::println("9) Stop process");
        std::print("10) Terminate\nChoose: ");
        int choose;
        std::cin >> choose;

        switch (choose)
        {
        case 1:
            adder::enter();
            break;

        case 2:
            showProcesses();
            break;

        case 3:
            editor::lobby();
            break;

        case 4:
            removerer::lobby();
            break;

        case 5:
            filterrr::lobby();
            break;

        case 6:
            sorter::lobby();
            break;

        case 7:
            statitics::enterer();
            break;

        case 8:
            processAction::startProcess();
            break;

        case 9:
            processAction::stopProcess();
            break;

        case 10:
            runtime = false;
            fileAction::saveData();
            std::println("Program terminated.");
            return 0;

        default:
            std::cerr << error::wrongNumber;
            break;
        }
    }
}