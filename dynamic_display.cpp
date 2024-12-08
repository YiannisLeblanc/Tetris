/*CONSOLE_CURSOR_INFO cursorInfo;
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(out, &cursorInfo);

	POINT x;
	char sprites[] = "-\\|/";
	const int size = strlen(sprites);
	const int T = 125;
	const int num = 25;
	CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(out, &ConsoleScreenBufferInfo);
	COORD cursorPosition = ConsoleScreenBufferInfo.dwCursorPosition;
	for (int j = 0;;j=(j+1)%size) {
		for (int i = 0; i < num; i++) {
			cout << sprites[(j+i)%(size)] << endl;
		}
		Sleep(T);
		SetConsoleCursorPosition(out, cursorPosition);
	}
	*/