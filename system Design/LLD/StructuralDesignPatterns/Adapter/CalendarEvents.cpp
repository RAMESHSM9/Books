#include <bits/stdc++.h>
#include <memory>
using namespace std;

class CalendarEvent {
public:
  virtual string getTitle() = 0;
  virtual string getLocation() = 0;
  virtual string getStartTime() = 0;
  virtual string getEndTime() = 0;
};

//@ external APIs- added here for compilation
class GoogleCalendarEvent {
public:
  string getSummary() { return "[GoogleCalendar]: Summary"; }
  string getLocation() { return "[GoogleCalendar]: Location"; }
  string getStartTime() { return "[GoogleCalendar]: StartTime"; }
  string getEndTime() { return "[GoogleCalendar]: EndTime"; }
};
class GoogleCalendarAdapter : public CalendarEvent {
  // Has-A
  GoogleCalendarEvent googleCalendarEvent;

public:
  string getTitle() { return googleCalendarEvent.getSummary(); }

  string getLocation() { return googleCalendarEvent.getLocation(); }

  string getStartTime() { return googleCalendarEvent.getStartTime(); }

  string getEndTime() { return googleCalendarEvent.getEndTime(); }
};

class AppleCalendarEvent {
public:
  string getSummary() { return "[AppleCalendarEvent]: Summary"; }
  string getLocation() { return "[AppleCalendarEvent]: Location"; }
  string getStartTime() { return "[AppleCalendarEvent]: StartTime"; }
  string getEndTime() { return "[AppleCalendarEvent]: EndTime"; }
};
class AppleCalendarAdapter : public CalendarEvent {
  // Has-A
  AppleCalendarEvent appleCalendarEvent;

public:
  string getTitle() { return appleCalendarEvent.getSummary(); }

  string getLocation() { return appleCalendarEvent.getLocation(); }

  string getStartTime() { return appleCalendarEvent.getStartTime(); }

  string getEndTime() { return appleCalendarEvent.getEndTime(); }
};

class myCalendarApp {
  std::shared_ptr<CalendarEvent> ce;

public:
  myCalendarApp(const std::shared_ptr<CalendarEvent> &c) { this->ce = c; }

  string getTitle() { return ce->getTitle(); }

  string getLocation() { return ce->getLocation(); }

  string getStartTime() { return ce->getStartTime(); }

  string getEndTime() { return ce->getEndTime(); }
};

int main() {
  std::shared_ptr<CalendarEvent> ce = make_shared<AppleCalendarAdapter>();
  myCalendarApp calendarApp(ce);
  cout << calendarApp.getTitle() << " " << calendarApp.getLocation() << " "
       << calendarApp.getStartTime() << " " << calendarApp.getEndTime() << endl;
}