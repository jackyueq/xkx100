// Room: /d/chengdu/northchengmen.c
// Date: Feb.14 1998 by Java

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ������ţ��������Ϸ����š����š�����������֣���ǽ��
���ż��Źٸ���ʾ(gaoshi)��һ����ֱ����ʯ���������졣������
ȥ��һƬ�����͵���Ұ�������ҡҷ�ĸ��������񡣳��ű����йٱ���
ϸ�̲�����˵ȡ�
LONG
	);
	set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south"  : __DIR__"beijie",
		"north"  : __DIR__"fuheqiaon",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�ɶ��ᶽ\n�����\n";
}

