// Room: /d/henshan/zhurongdian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "ף�ڵ�");
	set("long", @LONG
ף�ڵ������ʥ�������ף�ڡ�����ʯ��ǽ�����߸���������
��հ�ѩ��ΡȻ�����ں�ɽ����������ʯ��Ͽ���:  "�����ճ�������
����" ��������"ʥ���ػ�"��鹶���������Ǻ�ɽ���������ڡ�
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southdown"  : __DIR__"wangritai",
	   "northdown"  : __DIR__"wangyuetai",
	   "westup"     : __DIR__"zhurongfeng",
	]));
	set("objects", ([
		CLASS_D("henshan")+"/moda":1,
		CLASS_D("henshan")+"/first":1,
	]));
	set("valid_startroom", 1);
	set("coor/x", -310);
	set("coor/y", -990);
	set("coor/z", 50);
	setup();
	"/clone/board/henshan_b"->foo();
	replace_program(ROOM);
}

