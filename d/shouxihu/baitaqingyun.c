// Room: /yangzhou/baitaqingyun.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","��������");
	set("long",@LONG
�������ƣ�λ�������ű������࣬�����������������Ǭ¡����ʹ
�γ����ڡ�����֪ͬ�⸨���Ⱥ�Ӫ�������������������������ҵ����
�飬ǰ�����ӡ���԰���涫����Ƕ���������ơ�ʯ��ú�ͥԺ��ֲ
��������������÷��ɽ�衢���˵��ļ���ľ����Ժ����ǧ�ͣ�����ͨ
����¥��
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northeast" : __DIR__"shuiyun",
		"southeast" : __DIR__"jicuixuan",
		"west"      : __DIR__"wangchunlou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}