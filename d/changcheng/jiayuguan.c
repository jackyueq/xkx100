// Room: /d/changcheng/jiayuguan.c
// Last Modified by Winder on Aug. 25 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�����ؼ�¥");
	set("long", WHT @LONG
��վ�ںųơ����µ�һ�۹ء��ļ����ؼ�¥�ϣ������������ѩ��
����ɽ���������������������ɽ��������ʮ��ص�һ��ƽ�����治��
���µ�һ�������ڸ��ɳĮ�ϵ������ɳ��������䶯���������֣���
�Ϻ�����
LONG
NOR );
	set("outdoors", "xiyu");
	set("exits", ([
		"down"      : "/d/xingxiu/jiayuguan",
		"northeast" : __DIR__"changcheng21",
	]));
	set("no_clean_up", 0);
	set("coor/x", -18000);
	set("coor/y", 400);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}