// liufudayuan.c
// Date: Nov.1997 by Venus
// Last Modified by ahda on Sep.1 2001

#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
������Ժ�����ڼ��źܶ཭�����ͣ�ԭ�����������������ϴ�ֵ�
�����ӡ�����ү���ں�����Ե�ܺã�����������Ȼ���٣���Ժ���Ѱ���
�ܶ������ӣ������������������֡�
LONG);
	set("outdoors", "hengyang");
	set("exits", ([
	    "north"  : __DIR__"liufudating",
	    "out"    : __DIR__"liufugate",
	    "east"   : __DIR__"liangongfang",
	    "west"   : __DIR__"kefang",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
		"/d/huashan/npc/haoke" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
