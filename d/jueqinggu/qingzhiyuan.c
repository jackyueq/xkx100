// Room: /d/jueqinggu/qingzhiyuan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��֥Ժ");
	set("long", @LONG
����һ�䲻���С�ݣ����ϣ���������ҩ�ޣ�����һ�ԴԵĹ�����
��Ǭ��ҩ�����ײ���������¯��ͭ���߰ߣ������Զ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"songtang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

