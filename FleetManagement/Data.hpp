#pragma once

namespace logActions {
	void exportLogs();

	void showLogs();
}

namespace fileDataAction {
	void loadData(std::vector<Car>& carList);

	void saveData(std::vector<Car>& carList);
}