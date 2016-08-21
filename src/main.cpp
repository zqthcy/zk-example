#include <iostream>
#include <zookeeper/zookeeper.h>

#define ZK_SERVER "192.168.1.18:2181"
using namespace std;

void dummy( zhandle_t * zh, int type, int state, const char * path, void * context ) {
    cout << "In dummy watcher!\n";
    cout << "Receive event with type [" << type << "] state [" << state << "] path ["
    << path << "].\n";
}

int main(int argc, char* argv[]){
  cout << "hello world" << endl;
  zoo_set_debug_level(ZOO_LOG_LEVEL_DEBUG);
  zhandle_t* zh = zookeeper_init(
      ZK_SERVER, &dummy, 10000, 0, 0, 0);

  struct Stat stat;
//  int r = zoo_exists(zh, "/diego", 0, &stat );

  char buffer[512];
  std::string data = "my_data";
  int r = zoo_create(zh, "/diego", data.c_str(), data.size(), &ZOO_OPEN_ACL_UNSAFE, 
      0, buffer, sizeof( buffer ) - 1 );

  cout << "create done" << endl;

  int l = sizeof(buffer);
  r = zoo_get( zh, "/diego", 0, buffer, &l, &stat );

  cout << "get done:" << buffer << endl;

  return 1;
}
