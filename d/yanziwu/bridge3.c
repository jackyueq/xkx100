// Room: /d/yanziwu/bridge3.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ʮ������");
	set("long", @LONG
ʮ��������һ��ͨ���������о���ͤ��ʮ�����š��Ŷպ����˾�Ϊ
ʯ��������ȴ��Բľ�����š�͸����ָ���ľ��϶�����Կ�����������
��ˮ�����ĺɡ��������ŵ��ܡ�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"path16",
		"south"  : __DIR__"juanxin",
	]));
	set("coor/x", 1220);
	set("coor/y", -1210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}