// Room: /d/kunlun/shankou.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����ɽ���");
	set("long",@long
����λ����ɽ֮���һ��Сɽ�ڡ�ֻ������ɽ������ǧ�Ⱥɽ��
����ɽ����ľ�����࣬��ʱ¶����ͺͺ��ɽ���ʯͷ��ɽ�����Ͼ�Ϊ��
ѩ���ǣ��������ţ��߲�������
long);
	set("exits",([
		"west"      : __DIR__"klshanlu",
		"southeast" : __DIR__"kekexili",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -110000);
	set("coor/y", 30000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}