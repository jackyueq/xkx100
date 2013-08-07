// Room: /d/hengshan/huixiantai.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "���Է�㳡");
	set("long", @LONG
�����Ǻ�ɽ������Է�嶥�Ĺ㳡�������︩�Ⱥɽ�������ú�
�Ժ�ɽ�ǻ��ı�����ɽ֮�ڣ�����Ҳ�����𽭺��ĺ�ɽ�ɵĸ����صء�
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"westdown"  : __DIR__"shandao2",
		"north"     : __DIR__"baiyunan",
	]));
	set("objects", ([
		CLASS_D("hengshan")+"/yi" : 1,
		CLASS_D("hengshan")+"/qing" : 1,
		CLASS_D("hengshan")+"/first" : 1,
	]));
	
	set("outdoors", "hengshan");
//	set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", 3200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

